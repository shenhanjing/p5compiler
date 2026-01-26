#!/usr/bin/env python3
import argparse
import os
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, List, Optional, Sequence, Tuple


@dataclass(frozen=True)
class PrecompileResult:
    merged_file: Path
    preprocessed_files: List[Path]


def _find_p5_files(src_dir: Path) -> List[Path]:
    p5_files: List[Path] = []
    for root, _, files in os.walk(src_dir):
        for f in files:
            if f.endswith(".p5"):
                p5_files.append(Path(root) / f)
    p5_files.sort()
    return p5_files


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
    cmd.extend(["-C", "-undef", "-nostdinc", "-x", "assembler-with-cpp"])

    for inc in include_paths:
        cmd.extend(["-I", inc])
    for d in defines:
        cmd.append(f"-D{d}")
    cmd.extend(list(extra_preprocessor_args))
    return cmd


def _run_preprocessor(cmd: Sequence[str]) -> None:
    # Use a list invocation (no shell) so paths don't need manual quoting.
    proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    if proc.returncode != 0:
        sys.stderr.write(proc.stderr)
        raise RuntimeError(f"preprocessor failed with exit code {proc.returncode}")


def precompile_p5_directory(
    src_dir: str,
    output_dir: str,
    *,
    output_file: Optional[str] = None,
    preprocessor: str = "cc",
    p4_include: str = "14",
    use_env_includes: bool = True,
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
    merged = Path(output_file) if output_file else (out_dir / f"{dir_name}_merged.p4i")

    p5_files = _find_p5_files(src)
    if not p5_files:
        raise ValueError(f"no .p5 files found under: {src}")

    env_include_paths: List[str] = []
    if use_env_includes:
        if p4_include == "16":
            p = os.environ.get("P4C_16_INCLUDE_PATH")
            if p:
                env_include_paths.append(p)
        else:
            p = os.environ.get("P4C_14_INCLUDE_PATH")
            if p:
                env_include_paths.append(p)

    base_cmd = _build_preprocessor_base_cmd(
        preprocessor=preprocessor,
        include_paths=list(env_include_paths) + list(include_paths),
        defines=defines,
        extra_preprocessor_args=extra_preprocessor_args,
    )

    preprocessed: List[Path] = []
    for p5_f in p5_files:
        rel = p5_f.relative_to(src)
        out_name = _flatten_relpath(rel)
        out_f = out_dir / out_name

        # cc -E ... -o <out> <in>
        cmd = list(base_cmd) + ["-o", str(out_f), str(p5_f)]
        _run_preprocessor(cmd)
        preprocessed.append(out_f)

    merged.parent.mkdir(parents=True, exist_ok=True)
    with merged.open("w", encoding="utf-8") as out_fp:
        for p4i_f in preprocessed:
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
        description="Precompile a P5 directory: preprocess all .p5 files and merge into one .p4i"
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
        help="Path to merged output file (default: <output-dir>/<dir>_merged.p4i)",
    )
    ap.add_argument(
        "--preprocessor",
        default="cc",
        help="Preprocessor executable to run (default: cc)",
    )
    ap.add_argument(
        "--p4-include",
        choices=["14", "16"],
        default="14",
        help="Which P4 include env to use: P4C_14_INCLUDE_PATH or P4C_16_INCLUDE_PATH (default: 14)",
    )
    ap.add_argument(
        "--no-env-includes",
        action="store_true",
        default=False,
        help="Do not auto-add P4C_14_INCLUDE_PATH / P4C_16_INCLUDE_PATH to -I",
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
            p4_include=ns.p4_include,
            use_env_includes=(not ns.no_env_includes),
            include_paths=ns.include_paths,
            defines=ns.defines,
            extra_preprocessor_args=ns.extra_preprocessor_args,
            keep_tmp=ns.keep_tmp,
        )
    except Exception as e:
        sys.stderr.write(f"ERROR: {e}\n")
        return 1

    sys.stdout.write(str(res.merged_file) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

