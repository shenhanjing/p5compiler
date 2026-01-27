#!/usr/bin/env python3
import argparse
import os
import re
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import List, Optional, Sequence


@dataclass(frozen=True)
class PrecompileResult:
    merged_file: Path
    preprocessed_files: List[Path]


def _find_files(src_dir: Path, *, suffix: str) -> List[Path]:
    files_out: List[Path] = []
    for root, _, files in os.walk(src_dir):
        for f in files:
            if f.endswith(suffix):
                files_out.append(Path(root) / f)
    files_out.sort()
    return files_out


def _flatten_relpath(rel_path: Path) -> str:
    # Mirror p4c's approach: flatten path separators to '_' and append ".p4i".
    return str(rel_path).replace(os.sep, "_") + ".p4i"


def _build_preprocessor_base_cmd(
    preprocessor: str,
    include_paths: Sequence[str],
    defines: Sequence[str],
    extra_preprocessor_args: Sequence[str],
) -> List[str]:
    # Mirrors the flags in p4c/tools/driver/p4c_src/main.py for the P5 directory case.
    cmd: List[str] = [preprocessor, "-E"]
    cmd.extend([
        # "-C", 
        "-undef", 
        "-nostdinc", 
        "-x", 
        "assembler-with-cpp"
        ])

    for inc in include_paths:
        cmd.extend(["-I", inc])
    for d in defines:
        cmd.append(f"-D{d}")
    cmd.extend(list(extra_preprocessor_args))
    return cmd


def _run_preprocessor(cmd: Sequence[str]) -> str:
    # Use a list invocation (no shell) so paths don't need manual quoting.
    proc = subprocess.run(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        encoding="utf-8",
        errors="replace",
    )
    if proc.returncode != 0:
        sys.stderr.write(proc.stderr)
        raise RuntimeError(f"preprocessor failed with exit code {proc.returncode}")
    return proc.stdout


def _default_p5c_path() -> Path:
    # This file lives at: <repo>/p5compiler/precompiler/p5_precompile.py
    # p5c lives at:       <repo>/p5compiler/build_p5c/p5c
    return Path(__file__).resolve().parent.parent / "build_p5c" / "p5c"


def _run_p5c(*, p5c_path: Path, input_p5: Path, out_dir: Path) -> None:
    if not p5c_path.exists():
        raise FileNotFoundError(
            f"p5c not found at: {p5c_path}\n"
            f"Build it first (see /root/p5compiler/README.md), or pass --p5c <path>."
        )

    cmd = [str(p5c_path), str(input_p5), "-o", str(out_dir)]
    proc = subprocess.run(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        encoding="utf-8",
        errors="replace",
    )
    if proc.returncode != 0:
        if proc.stdout:
            sys.stdout.write(proc.stdout)
        if proc.stderr:
            sys.stderr.write(proc.stderr)
        raise RuntimeError(f"p5c failed with exit code {proc.returncode}")


_LINE_MARKER_RE = re.compile(r'^#\s+\d+\s+"([^"]+)"(?:\s+\d+.*)?$')


def _strip_expanded_includes(preprocessed_text: str, *, main_file: Path) -> str:
    """Keep only lines that originate from main_file, drop expanded include content.

    We rely on the preprocessor's line markers (`# <n> "file" ...`) to track the
    current origin file. When the origin file is not main_file, we discard those
    non-marker lines.
    """
    # Compare against both the user-specified path and its resolved form,
    # since preprocessors may emit either in line markers.
    main_strs = {str(main_file), str(main_file.resolve())}

    out_lines: List[str] = []
    current_file: Optional[str] = None

    for line in preprocessed_text.splitlines(keepends=True):
        m = _LINE_MARKER_RE.match(line.rstrip("\n"))
        if m:
            current_file = m.group(1)
            # Keep only the line markers that point back to the main file
            # (useful for debugging/line mapping), but always update state.
            if current_file in main_strs:
                out_lines.append(line)
            continue

        if current_file in main_strs:
            out_lines.append(line)

    return "".join(out_lines)


def precompile_p5_directory(
    src_dir: str,
    output_dir: str,
    *,
    output_file: Optional[str] = None,
    preprocessor: str = "cc",
    include_paths: Sequence[str] = (),
    defines: Sequence[str] = (),
    extra_preprocessor_args: Sequence[str] = (),
    keep_tmp: bool = False,
) -> PrecompileResult:
    src = Path(src_dir)
    out_dir = Path(output_dir)

    if not src.exists() or not src.is_dir():
        raise ValueError(f"src_dir must be an existing directory: {src}")

    out_dir.mkdir(parents=True, exist_ok=True)

    dir_name = src.resolve().name
    merged = Path(output_file) if output_file else (out_dir / f"{dir_name}_merged.p5")

    p5_files = _find_files(src, suffix=".p5")
    h_files = _find_files(src, suffix=".h")
    if not p5_files and not h_files:
        raise ValueError(f"no .p5 or .h files found under: {src}")

    base_cmd = _build_preprocessor_base_cmd(
        preprocessor=preprocessor,
        include_paths=list(include_paths),
        defines=defines,
        extra_preprocessor_args=extra_preprocessor_args,
    )

    preprocessed: List[Path] = []

    def preprocess_and_filter_to_file(src_f: Path, *, rel_prefix: str) -> Path:
        rel = src_f.relative_to(src)
        out_name = f"{rel_prefix}{_flatten_relpath(rel)}"
        out_f = out_dir / out_name

        # cc -E ... <in>  (stdout captured)
        cmd = list(base_cmd) + [str(src_f)]
        raw = _run_preprocessor(cmd)
        filtered = _strip_expanded_includes(raw, main_file=src_f)
        out_f.write_text(filtered, encoding="utf-8", errors="replace")
        preprocessed.append(out_f)
        return out_f

    # Phase 1: preprocess all .h files, strip expanded include content, merge together.
    h_outputs: List[Path] = []
    for h_f in h_files:
        h_outputs.append(preprocess_and_filter_to_file(h_f, rel_prefix="h_"))

    # Phase 2: preprocess all .p5 files, strip expanded include content, merge together.
    p5_outputs: List[Path] = []
    for p5_f in p5_files:
        p5_outputs.append(preprocess_and_filter_to_file(p5_f, rel_prefix="p5_"))

    merged.parent.mkdir(parents=True, exist_ok=True)
    with merged.open("w", encoding="utf-8") as out_fp:
        # Put merged .h content first, then merged .p5 content.
        for p4i_f in h_outputs:
            out_fp.write(f"// File: {p4i_f}\n")
            out_fp.write(p4i_f.read_text(encoding="utf-8", errors="replace"))
            out_fp.write("\n")

        for p4i_f in p5_outputs:
            out_fp.write(f"// File: {p4i_f}\n")
            out_fp.write(p4i_f.read_text(encoding="utf-8", errors="replace"))
            out_fp.write("\n")

    if not keep_tmp:
        for p4i_f in preprocessed:
            try:
                p4i_f.unlink(missing_ok=True)
            except Exception:
                # Best-effort cleanup; keep merged output regardless.
                pass

    return PrecompileResult(merged_file=merged, preprocessed_files=preprocessed)


def _parse_args(argv: Optional[Sequence[str]] = None) -> argparse.Namespace:
    ap = argparse.ArgumentParser(
        description="Precompile a P5 directory: preprocess files and merge into one output"
    )
    ap.add_argument("src_dir", help="Directory to scan recursively for .p5 files")
    ap.add_argument(
        "-o",
        "--output-dir",
        dest="output_dir",
        default=".",
        help="Directory to write outputs (default: current directory)",
    )
    ap.add_argument(
        "--output-file",
        dest="output_file",
        default=None,
        help="Path to merged output file (default: <output-dir>/<dir>_merged.p5)",
    )
    ap.add_argument(
        "--preprocessor",
        default="cc",
        help="Preprocessor executable to run (default: cc)",
    )
    ap.add_argument(
        "-I",
        dest="include_paths",
        action="append",
        default=[],
        help="Add an include search path (repeatable)",
    )
    ap.add_argument(
        "-D",
        dest="defines",
        action="append",
        default=[],
        help="Define a macro NAME[=VALUE] (repeatable)",
    )
    ap.add_argument(
        "-Xpreprocessor",
        dest="extra_preprocessor_args",
        action="append",
        default=[],
        help="Pass an extra argument to the preprocessor (repeatable)",
    )
    ap.add_argument(
        "--run-p5c",
        action="store_true",
        default=False,
        help="After merging, run p5compiler/build_p5c/p5c on the merged .p5 and write outputs into the merged file's directory",
    )
    ap.add_argument(
        "--p5c",
        dest="p5c_path",
        default=None,
        help="Path to p5c executable (default: ../../build_p5c/p5c relative to this script)",
    )
    ap.add_argument(
        "--keep-tmp",
        action="store_true",
        default=False,
        help="Keep per-file preprocessed .p4i outputs (default: delete them after merge)",
    )
    return ap.parse_args(argv)


def main(argv: Optional[Sequence[str]] = None) -> int:
    ns = _parse_args(argv)
    try:
        res = precompile_p5_directory(
            ns.src_dir,
            ns.output_dir,
            output_file=ns.output_file,
            preprocessor=ns.preprocessor,
            include_paths=ns.include_paths,
            defines=ns.defines,
            extra_preprocessor_args=ns.extra_preprocessor_args,
            keep_tmp=ns.keep_tmp,
        )

        if ns.run_p5c:
            p5c_path = Path(ns.p5c_path) if ns.p5c_path else _default_p5c_path()
            _run_p5c(p5c_path=p5c_path, input_p5=res.merged_file, out_dir=res.merged_file.parent)
    except Exception as e:
        sys.stderr.write(f"ERROR: {e}\n")
        return 1

    sys.stdout.write(str(res.merged_file) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

