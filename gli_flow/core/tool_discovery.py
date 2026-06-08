"""
Canonical EDA tool discovery — single source of truth.

Every caller must use this module for binary path and version resolution.
No duplicated discovery logic anywhere else.
"""

import os
import re
import shutil
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Callable, Optional

from gli_flow.core.subprocess_env import safe_env


@dataclass
class ToolBinary:
    path: str
    version: tuple[int, ...]
    version_str: str


KNOWN_BROKEN_VERSIONS: dict[str, list[tuple[int, ...]]] = {
    "magic": [(8, 3, 105)],
}

MAGIC_SEARCH_PATHS: list[str] = [
    "magic",
    str(Path.home() / ".local/bin/magic"),
    "/usr/local/bin/magic",
    "/usr/bin/magic",
    "/opt/OpenROAD/tools/install/magic/bin/magic",
    "/opt/pdk/share/magic/bin/magic",
]

MAGICDNUL_SEARCH_PATHS: list[str] = [
    "magicdnull",
    str(Path.home() / ".local/lib/magic/tcl/magicdnull"),
    "/usr/local/lib/magic/tcl/magicdnull",
    "/usr/lib/x86_64-linux-gnu/magic/tcl/magicdnull",
]

NETGEN_SEARCH_PATHS: list[str] = [
    "netgen-lvs",
    "netgen",
    "/usr/bin/netgen-lvs",
    "/usr/lib/netgen/bin/netgen",
    "/usr/bin/netgen",
    "/usr/local/bin/netgen",
    "/opt/OpenROAD/tools/install/netgen/bin/netgen",
    "/opt/pdk/share/netgen/bin/netgen",
]

NETGENEXEC_SEARCH_PATHS: list[str] = [
    "netgenexec",
    "/usr/lib/netgen/tcl/netgenexec",
    "/usr/local/lib/netgen/tcl/netgenexec",
]

KLAYOUT_SEARCH_PATHS: list[str] = [
    "klayout",
    "klayout_app",
    "/usr/local/bin/klayout",
    "/usr/bin/klayout",
]

OPENROAD_SEARCH_PATHS: list[str] = [
    "openroad",
    "/usr/local/bin/openroad",
    "/usr/bin/openroad",
    "/opt/OpenROAD/tools/install/OpenROAD/bin/openroad",
    "/opt/OpenROAD/build/bin/openroad",
]

YOSYS_SEARCH_PATHS: list[str] = [
    "yosys",
    "/usr/local/bin/yosys",
    "/usr/bin/yosys",
]

SV2V_SEARCH_PATHS: list[str] = [
    "sv2v",
    "/usr/local/bin/sv2v",
    "/usr/bin/sv2v",
]

STA_SEARCH_PATHS: list[str] = [
    "sta",
    "/usr/local/bin/sta",
    "/usr/bin/sta",
]


def _run_cmd(args: list[str], timeout: int = 10) -> tuple[int, str, str]:
    try:
        result = subprocess.run(args, capture_output=True, text=True, timeout=timeout, env=safe_env())
        return result.returncode, result.stdout, result.stderr
    except FileNotFoundError:
        return -1, "", ""
    except subprocess.TimeoutExpired:
        return -2, "", ""
    except OSError:
        return -3, "", ""


def _parse_semver(text: str) -> tuple[int, ...]:
    # Match version-like pattern: digits separated by dots, optionally followed by dash+digits
    m = re.search(r"(\d+(?:\.\d+)+(?:-\d+)?)", text)
    if m:
        version_str = m.group(1)
        # Split on dots and dashes
        parts = re.split(r"[.-]", version_str)
        return tuple(int(p) for p in parts[:4])
    # Fallback: grab first cluster of digits
    digits = re.findall(r"(\d+)", text)
    if digits:
        return (int(digits[0]),)
    return (0,)


def _version_from_path(candidate: str) -> Optional[tuple[int, ...]]:
    """Try to get version from a binary path by running --version."""
    rc, stdout, stderr = _run_cmd([candidate, "--version"])
    if rc == 0:
        ver = _parse_semver(stdout or stderr)
        if ver != (0,):
            return ver
    rc2, stdout2, stderr2 = _run_cmd([candidate, "-version"])
    if rc2 == 0:
        ver = _parse_semver(stdout2 or stderr2)
        if ver != (0,):
            return ver
    return None


def _version_from_str(text: str) -> tuple[int, ...]:
    return _parse_semver(text)


def _resolve_candidate(candidate: str) -> Optional[str]:
    """Resolve a candidate path to an actual executable path."""
    resolved = shutil.which(candidate)
    if resolved:
        return resolved
    path = Path(candidate)
    if path.is_file() and os.access(str(path), os.X_OK):
        return str(path.resolve())
    return None


def _find_candidate(candidates: list[str]) -> Optional[str]:
    """Find the first existing candidate."""
    seen: set[str] = set()
    for c in candidates:
        norm = os.path.normpath(c)
        if norm in seen:
            continue
        seen.add(norm)
        resolved = _resolve_candidate(c)
        if resolved:
            return resolved
    return None


def is_broken_version(tool: str, version: tuple[int, ...]) -> bool:
    broken = KNOWN_BROKEN_VERSIONS.get(tool, [])
    for bv in broken:
        if version[: len(bv)] == bv:
            return True
    return False


def find_binary(name: str) -> Optional[str]:
    """Generic binary finder for ad-hoc lookups."""
    return shutil.which(name)


def find_magic_binary() -> Optional[ToolBinary]:
    return _find_tool_with_version(MAGIC_SEARCH_PATHS)


def find_magicdnull_binary() -> Optional[ToolBinary]:
    return _find_tool_with_version(MAGICDNUL_SEARCH_PATHS)


def find_netgen_binary() -> Optional[ToolBinary]:
    return _find_tool_with_version(NETGEN_SEARCH_PATHS)


def find_netgenexec_binary() -> Optional[ToolBinary]:
    return _find_tool_with_version(NETGENEXEC_SEARCH_PATHS)


def find_klayout_binary() -> Optional[ToolBinary]:
    return _find_tool_with_version(KLAYOUT_SEARCH_PATHS)


def find_openroad_binary() -> Optional[ToolBinary]:
    return _find_tool_with_version(OPENROAD_SEARCH_PATHS)


def find_yosys_binary() -> Optional[ToolBinary]:
    return _find_tool_with_version(YOSYS_SEARCH_PATHS)


def find_sv2v_binary() -> Optional[ToolBinary]:
    return _find_tool_with_version(SV2V_SEARCH_PATHS)


def find_sta_binary() -> Optional[ToolBinary]:
    return _find_tool_with_version(STA_SEARCH_PATHS)


def _find_tool_with_version(candidates: list[str]) -> Optional[ToolBinary]:
    """Find best binary: prefer non-broken, prefer newer version.

    Strategy:
    1. Scan all candidates, collect those that exist.
    2. For each existing candidate, detect version.
    3. Filter out known-broken versions.
    4. Return the one with the highest version (most recent).
    5. If only a broken version exists, return it (user choice).
    """
    found: list[tuple[tuple[int, ...], str]] = []

    for c in candidates:
        resolved = _resolve_candidate(c)
        if not resolved:
            continue
        ver = _version_from_path(resolved)
        if ver is None:
            ver = (0,)
        found.append((ver, resolved))

    if not found:
        return None

    non_broken = [(v, p) for v, p in found if not is_broken_version("magic" if "magic" in p else "", v)]
    if non_broken:
        non_broken.sort(key=lambda x: x[0], reverse=True)
        version, path = non_broken[0]
    else:
        found.sort(key=lambda x: x[0], reverse=True)
        version, path = found[0]

    ver_str = ".".join(str(v) for v in version) if version else "unknown"
    return ToolBinary(path=path, version=version, version_str=ver_str)
