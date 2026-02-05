#!/usr/bin/env python3
import argparse
import os
import re
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional, Sequence, Tuple


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


_BAT_SET_RE = re.compile(r"^\s*set\s+([A-Za-z_][A-Za-z0-9_]*)=(.*)$", re.IGNORECASE)
_BAT_VAR_REF_RE = re.compile(r"%([A-Za-z_][A-Za-z0-9_]*)%")


def _bat_expand_vars(value: str, vars_map: Dict[str, str], *, max_passes: int = 20) -> str:
    """Expand %VAR% references using vars_map (Windows .bat style)."""
    out = value
    for _ in range(max_passes):
        changed = False

        def repl(m: re.Match[str]) -> str:
            nonlocal changed
            k = m.group(1)
            if k in vars_map:
                changed = True
                return vars_map[k]
            return m.group(0)

        new_out = _BAT_VAR_REF_RE.sub(repl, out)
        out = new_out
        if not changed:
            break
    return out


def _parse_makefile_bat(makefile_path: Path) -> Tuple[List[str], List[Path]]:
    """Parse a Windows .bat 'makefile' and return (include_dirs, ordered_p5_files).

    Expected patterns:
    - set INCLUDES=-I... -I...
    - set SRC_FILES= ^  (followed by path lines ending with ^, terminated by blank line)
    """
    text = makefile_path.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()

    vars_map: Dict[str, str] = {}
    includes_raw: Optional[str] = None
    src_files_lines: List[str] = []
    in_src_files = False

    for line in lines:
        # Stop SRC_FILES block on first blank line.
        if in_src_files and line.strip() == "":
            in_src_files = False
            continue

        m = _BAT_SET_RE.match(line)
        if m and not in_src_files:
            name = m.group(1)
            value = m.group(2).strip()

            # Special-case SRC_FILES: it typically starts with just '^' then continues.
            if name.upper() == "SRC_FILES":
                in_src_files = True
                if value:
                    src_files_lines.append(value)
                continue

            vars_map[name] = value
            if name.upper() == "INCLUDES":
                includes_raw = value
            continue

        if in_src_files:
            src_files_lines.append(line.strip())

    if includes_raw is None:
        raise ValueError(f"makefile missing INCLUDES: {makefile_path}")
    if not src_files_lines:
        raise ValueError(f"makefile missing SRC_FILES: {makefile_path}")

    # Expand vars in INCLUDES and parse -I entries.
    includes_expanded = _bat_expand_vars(includes_raw, vars_map)
    include_dirs: List[str] = []
    for tok in includes_expanded.split():
        if tok.startswith("-I") and len(tok) > 2:
            include_dirs.append(tok[2:])

    # Parse ordered SRC_FILES (keep original order).
    ordered_p5: List[Path] = []
    for raw_line in src_files_lines:
        if not raw_line:
            continue
        # Remove caret continuation markers.
        s = raw_line.rstrip()
        if s.endswith("^"):
            s = s[:-1].rstrip()
        if not s:
            continue
        s = _bat_expand_vars(s, vars_map)
        # Support multiple paths per line (rare).
        for tok in s.split():
            if tok.endswith("^"):
                tok = tok[:-1]
            tok = tok.strip()
            if not tok:
                continue
            # Normalize slashes for Path() on Linux.
            tok_norm = tok.replace("\\", "/")
            p = (makefile_path.parent / tok_norm).resolve()
            ordered_p5.append(p)

    if not ordered_p5:
        raise ValueError(f"SRC_FILES expanded to empty list: {makefile_path}")

    # Normalize include dirs to absolute paths.
    include_dirs_abs: List[str] = []
    for inc in include_dirs:
        inc_norm = inc.replace("\\", "/")
        include_dirs_abs.append(str((makefile_path.parent / inc_norm).resolve()))

    return include_dirs_abs, ordered_p5


def _common_base_dir(paths: Sequence[Path]) -> Path:
    if not paths:
        raise ValueError("paths must be non-empty")
    common = os.path.commonpath([str(p) for p in paths])
    return Path(common)


def _precompile_files(
    *,
    p5_files: Sequence[Path],
    h_files: Sequence[Path],
    base_root: Path,
    output_dir: Path,
    output_file: Optional[str],
    preprocessor: str,
    include_paths: Sequence[str],
    defines: Sequence[str],
    extra_preprocessor_args: Sequence[str],
    keep_tmp: bool,
    merged_name_hint: str,
) -> PrecompileResult:
    out_dir = output_dir
    out_dir.mkdir(parents=True, exist_ok=True)

    merged = Path(output_file) if output_file else (out_dir / f"{merged_name_hint}_merged.p5")

    base_cmd = _build_preprocessor_base_cmd(
        preprocessor=preprocessor,
        include_paths=list(include_paths),
        defines=defines,
        extra_preprocessor_args=extra_preprocessor_args,
    )

    preprocessed: List[Path] = []

    def preprocess_and_filter_to_file(src_f: Path, *, rel_prefix: str) -> Path:
        try:
            rel = src_f.resolve().relative_to(base_root.resolve())
        except Exception:
            rel = Path(src_f.name)
        out_name = f"{rel_prefix}{_flatten_relpath(rel)}"
        out_f = out_dir / out_name

        cmd = list(base_cmd) + [str(src_f)]
        raw = _run_preprocessor(cmd)
        filtered = _strip_expanded_includes(raw, main_file=src_f)
        out_f.write_text(filtered, encoding="utf-8", errors="replace")
        preprocessed.append(out_f)
        return out_f

    h_outputs: List[Path] = []
    for h_f in h_files:
        h_outputs.append(preprocess_and_filter_to_file(h_f, rel_prefix="h_"))

    p5_outputs: List[Path] = []
    for p5_f in p5_files:
        p5_outputs.append(preprocess_and_filter_to_file(p5_f, rel_prefix="p5_"))

    merged.parent.mkdir(parents=True, exist_ok=True)
    with merged.open("w", encoding="utf-8") as out_fp:
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
                pass

    return PrecompileResult(merged_file=merged, preprocessed_files=preprocessed)


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

    if not src.exists() or not src.is_dir():
        raise ValueError(f"src_dir must be an existing directory: {src}")

    p5_files = _find_files(src, suffix=".p5")
    h_files = _find_files(src, suffix=".h")
    if not p5_files and not h_files:
        raise ValueError(f"no .p5 or .h files found under: {src}")
    all_for_base: List[Path] = []
    all_for_base.extend([p.resolve() for p in p5_files])
    all_for_base.extend([p.resolve() for p in h_files])
    base_root = _common_base_dir(all_for_base)

    return _precompile_files(
        p5_files=p5_files,
        h_files=h_files,
        base_root=base_root,
        output_dir=Path(output_dir),
        output_file=output_file,
        preprocessor=preprocessor,
        include_paths=include_paths,
        defines=defines,
        extra_preprocessor_args=extra_preprocessor_args,
        keep_tmp=keep_tmp,
        merged_name_hint=src.resolve().name,
    )


def precompile_p5_makefile_bat(
    makefile_path: str,
    output_dir: str,
    *,
    output_file: Optional[str] = None,
    preprocessor: str = "cc",
    include_paths: Sequence[str] = (),
    defines: Sequence[str] = (),
    extra_preprocessor_args: Sequence[str] = (),
    keep_tmp: bool = False,
) -> PrecompileResult:
    mk = Path(makefile_path)
    if not mk.exists() or not mk.is_file():
        raise ValueError(f"makefile_path must be an existing file: {mk}")

    mk_includes, ordered_p5 = _parse_makefile_bat(mk)
    # Merge include paths: makefile-provided first, then CLI -I (caller additions).
    all_includes = list(mk_includes) + list(include_paths)

    # Collect headers from include roots.
    h_files: List[Path] = []
    for inc in mk_includes:
        inc_p = Path(inc)
        if inc_p.exists() and inc_p.is_dir():
            h_files.extend(_find_files(inc_p, suffix=".h"))
    # De-dup while keeping deterministic order.
    seen_h: set[str] = set()
    h_unique: List[Path] = []
    for p in h_files:
        s = str(p.resolve())
        if s not in seen_h:
            seen_h.add(s)
            h_unique.append(p)

    # Ensure src files exist; keep order exactly as in makefile.
    missing = [str(p) for p in ordered_p5 if not p.exists()]
    if missing:
        raise FileNotFoundError("Missing SRC_FILES entries:\n" + "\n".join(missing))

    all_for_base: List[Path] = []
    all_for_base.extend([p.resolve() for p in ordered_p5])
    all_for_base.extend([p.resolve() for p in h_unique])
    base_root = _common_base_dir(all_for_base) if all_for_base else mk.parent.resolve()

    merged_name_hint = mk.parent.resolve().name
    return _precompile_files(
        p5_files=ordered_p5,
        h_files=h_unique,
        base_root=base_root,
        output_dir=Path(output_dir),
        output_file=output_file,
        preprocessor=preprocessor,
        include_paths=all_includes,
        defines=defines,
        extra_preprocessor_args=extra_preprocessor_args,
        keep_tmp=keep_tmp,
        merged_name_hint=merged_name_hint,
    )


def _parse_args(argv: Optional[Sequence[str]] = None) -> argparse.Namespace:
    ap = argparse.ArgumentParser(
        description="Precompile a P5 directory: preprocess files and merge into one output"
    )
    ap.add_argument(
        "input",
        help="Either a directory to scan, or a Windows makefile.bat path (parsed for INCLUDES/SRC_FILES)",
    )
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
        inp = Path(ns.input)
        if inp.exists() and inp.is_file():
            res = precompile_p5_makefile_bat(
                str(inp),
                ns.output_dir,
                output_file=ns.output_file,
                preprocessor=ns.preprocessor,
                include_paths=ns.include_paths,
                defines=ns.defines,
                extra_preprocessor_args=ns.extra_preprocessor_args,
                keep_tmp=ns.keep_tmp,
            )
        else:
            res = precompile_p5_directory(
                ns.input,
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

