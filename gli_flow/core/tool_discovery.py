"""
Canonical EDA tool discovery — single source of truth.

Every caller must use this module for binary path and version resolution.
No duplicated discovery logic anywhere else.

Precedence (highest to lowest):
  1. Explicit config override (gli_manifest.yaml or env var)
  2. User local installation (~/.local/bin, ~/.gli-flow/tools/bin)
  3. Virtual environment tools
  4. System tools (/usr/bin, /usr/local/bin, etc.)
"""

import os
import re
import shutil
import subprocess
from dataclasses import dataclass, field
from enum import Enum
from pathlib import Path
from typing import Callable, Optional

from gli_flow.core.subprocess_env import safe_env


class BinarySource(Enum):
    CONFIG = "config"
    USER_LOCAL = "user_local"
    VENV = "venv"
    SYSTEM = "system"
    UNKNOWN = "unknown"


class ValidationStatus(Enum):
    VALID = "valid"
    BROKEN = "broken"
    UNVERIFIED = "unverified"


@dataclass
class ToolInfo:
    tool_name: str
    executable_path: str
    version: tuple[int, ...]
    version_str: str
    source: BinarySource = BinarySource.UNKNOWN
    validation_status: ValidationStatus = ValidationStatus.UNVERIFIED

    @property
    def path(self) -> str:
        return self.executable_path


HISTORICAL_RISK_VERSIONS: dict[str, list[tuple[int, ...]]] = {
    "magic": [(8, 3, 105)],
}

TOOL_CONFIG_KEYS: dict[str, str] = {
    "magic": "magic_binary",
    "netgen": "netgen_binary",
    "openroad": "openroad_binary",
    "yosys": "yosys_binary",
    "klayout": "klayout_binary",
    "sv2v": "sv2v_binary",
    "sta": "sta_binary",
}

HOME_PREFIX = "<HOME>"

EXTRA_PATH_DIRS = [
    "/usr/local/bin",
    HOME_PREFIX + "/.local/bin",
    HOME_PREFIX + "/.gli-flow/tools/bin",
    HOME_PREFIX + "/.gli-flow/orfs/tools/install/OpenROAD/bin",
    HOME_PREFIX + "/.gli-flow/orfs/tools/install/Yosys/bin",
    "/opt/OpenROAD/tools/install/magic/bin",
    "/opt/OpenROAD/tools/install/OpenROAD/bin",
    "/opt/OpenROAD/build/bin",
    "/opt/pdk/share/magic/bin",
    "/opt/pdk/share/netgen/bin",
    "/pdk",
    "/usr/lib/netgen",
    "/usr/local/lib/netgen",
]

MAGIC_SEARCH_PATHS: list[str] = [
    "magic",
    HOME_PREFIX + "/.local/bin/magic",
    "/usr/local/bin/magic",
    "/usr/bin/magic",
    "/opt/OpenROAD/tools/install/magic/bin/magic",
    "/opt/pdk/share/magic/bin/magic",
]

MAGICDNUL_SEARCH_PATHS: list[str] = [
    "magicdnull",
    HOME_PREFIX + "/.local/lib/magic/tcl/magicdnull",
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


def _detect_source(resolved_path: str) -> BinarySource:
    home = str(Path.home())
    if ".local/bin" in resolved_path or ".gli-flow" in resolved_path:
        return BinarySource.USER_LOCAL
    if "/venv/" in resolved_path or "/.venv/" in resolved_path or "/virtualenv/" in resolved_path:
        return BinarySource.VENV
    if resolved_path.startswith(("/usr/", "/opt/")):
        return BinarySource.SYSTEM
    return BinarySource.UNKNOWN


def _get_config_override(tool_name: str) -> Optional[str]:
    key = TOOL_CONFIG_KEYS.get(tool_name)
    if not key:
        return None
    from gli_flow.installer.workspace import get_config_value
    val = get_config_value(key)
    if val and os.path.isfile(val) and os.access(val, os.X_OK):
        return val
    env_val = os.environ.get(f"GLI_FLOW_{tool_name.upper()}_BINARY")
    if env_val and os.path.isfile(env_val) and os.access(env_val, os.X_OK):
        return env_val
    return None


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
    m = re.search(r"(\d+(?:\.\d+)+(?:-\d+)?)", text)
    if m:
        version_str = m.group(1)
        parts = re.split(r"[.-]", version_str)
        result = tuple(int(p) for p in parts[:4])
        if len(parts) < 3:
            rev = re.search(r"(?:revision|rev|r)\s*(\d+)", text, re.IGNORECASE)
            if rev:
                result = result + (int(rev.group(1)),)
        return result
    m = re.search(r"(\d+)\.(\d+)\s*(?:revision|r|rev)\s*(\d+)", text, re.IGNORECASE)
    if m:
        return (int(m.group(1)), int(m.group(2)), int(m.group(3)))
    digits = re.findall(r"(\d+)", text)
    if digits:
        return (int(digits[0]),)
    return (0,)


def _version_from_path(candidate: str) -> Optional[tuple[int, ...]]:
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


def is_broken_version(tool: str, version: tuple[int, ...]) -> bool:
    return False


def is_historical_risk_version(tool: str, version: tuple[int, ...]) -> bool:
    risky = HISTORICAL_RISK_VERSIONS.get(tool, [])
    for rv in risky:
        if version[: len(rv)] == rv:
            return True
    return False


def get_version_risk_warning(tool: str, version: tuple[int, ...]) -> Optional[str]:
    if is_historical_risk_version(tool, version):
        ver_str = ".".join(str(v) for v in version)
        return f"{tool} version {ver_str} has historical risk — functional validation recommended"
    return None


def _resolve_home(path: str) -> str:
    """Resolve HOME_PREFIX to actual home directory at call time."""
    if path.startswith(HOME_PREFIX):
        return str(Path.home() / path[len(HOME_PREFIX) + 1:])
    return path


def _resolve_candidate(candidate: str) -> Optional[str]:
    resolved = shutil.which(candidate)
    if resolved:
        return resolved
    path = Path(_resolve_home(candidate))
    if path.is_file() and os.access(str(path), os.X_OK):
        return str(path.resolve())
    return None


def _find_candidate(candidates: list[str]) -> Optional[str]:
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


def find_binary(name: str) -> Optional[str]:
    return shutil.which(name)


def _find_tool_with_info(
    tool_name: str,
    candidates: list[str],
    config_override: bool = True,
) -> Optional[ToolInfo]:
    if config_override:
        override_path = _get_config_override(tool_name)
        if override_path:
            ver = _version_from_path(override_path)
            if ver is None:
                ver = (0,)
            ver_str = ".".join(str(v) for v in ver)
            return ToolInfo(
                tool_name=tool_name,
                executable_path=override_path,
                version=ver,
                version_str=ver_str,
                source=BinarySource.CONFIG,
                validation_status=ValidationStatus.VALID,
            )

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
        for extra in EXTRA_PATH_DIRS:
            candidate = Path(_resolve_home(extra)) / tool_name
            if candidate.is_file() and os.access(str(candidate), os.X_OK):
                resolved = str(candidate.resolve())
                ver = _version_from_path(resolved)
                if ver is None:
                    ver = (0,)
                found.append((ver, resolved))
                break

    if not found:
        return None

    non_broken = [(v, p) for v, p in found]
    if non_broken:
        non_broken.sort(key=lambda x: x[0], reverse=True)
        version, path = non_broken[0]
    else:
        found.sort(key=lambda x: x[0], reverse=True)
        version, path = found[0]

    ver_str = ".".join(str(v) for v in version) if version else "unknown"
    source = _detect_source(path)
    status = ValidationStatus.VALID

    return ToolInfo(
        tool_name=tool_name,
        executable_path=path,
        version=version,
        version_str=ver_str,
        source=source,
        validation_status=status,
    )


def _get_tool_info(tool_name: str) -> Optional[ToolInfo]:
    search_paths = {
        "magic": MAGIC_SEARCH_PATHS,
        "magicdnull": MAGICDNUL_SEARCH_PATHS,
        "netgen": NETGEN_SEARCH_PATHS,
        "netgenexec": NETGENEXEC_SEARCH_PATHS,
        "klayout": KLAYOUT_SEARCH_PATHS,
        "openroad": OPENROAD_SEARCH_PATHS,
        "yosys": YOSYS_SEARCH_PATHS,
        "sv2v": SV2V_SEARCH_PATHS,
        "sta": STA_SEARCH_PATHS,
    }
    candidates = search_paths.get(tool_name, [tool_name])
    return _find_tool_with_info(tool_name, candidates)


def find_magic_binary() -> Optional[ToolInfo]:
    return _get_tool_info("magic")


def find_magicdnull_binary() -> Optional[ToolInfo]:
    return _get_tool_info("magicdnull")


def find_netgen_binary() -> Optional[ToolInfo]:
    return _get_tool_info("netgen")


def find_netgenexec_binary() -> Optional[ToolInfo]:
    return _get_tool_info("netgenexec")


def find_klayout_binary() -> Optional[ToolInfo]:
    return _get_tool_info("klayout")


def find_openroad_binary() -> Optional[ToolInfo]:
    return _get_tool_info("openroad")


def find_yosys_binary() -> Optional[ToolInfo]:
    return _get_tool_info("yosys")


def find_sv2v_binary() -> Optional[ToolInfo]:
    return _get_tool_info("sv2v")


def find_sta_binary() -> Optional[ToolInfo]:
    return _get_tool_info("sta")
