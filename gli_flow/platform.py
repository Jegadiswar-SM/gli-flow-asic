import os
import platform
import shutil
import sys
from pathlib import Path


def get_platform():
    system = platform.system().lower()
    if system == "linux":
        return "linux"
    elif system == "darwin":
        return "macos"
    elif system == "windows":
        if "microsoft" in platform.uname().release.lower():
            return "wsl2"
        return "windows"
    return system


def get_default_pdk_root() -> str:
    return str(Path.home() / ".gli-flow" / "pdk")


def get_tool_path(name: str) -> str:
    path = shutil.which(name)
    if path:
        return path
    common_locations = {
        "openroad": [
            "/usr/local/bin/openroad",
            "/usr/bin/openroad",
            str(Path.home() / ".gli-flow" / "tools" / "OpenROAD" / "build" / "bin" / "openroad"),
        ],
        "yosys": [
            "/usr/local/bin/yosys",
            "/usr/bin/yosys",
            str(Path.home() / ".gli-flow" / "tools" / "yosys" / "yosys"),
        ],
        "klayout": [
            "/usr/local/bin/klayout",
            "/usr/bin/klayout",
            str(Path.home() / ".gli-flow" / "tools" / "klayout" / "bin" / "klayout"),
        ],
        "magic": [
            "/usr/local/bin/magic",
            "/usr/bin/magic",
        ],
    }
    for loc in common_locations.get(name, []):
        if Path(loc).exists():
            return loc
    return ""


def check_environment():
    result = {
        "platform": get_platform(),
        "python": sys.version,
        "pdk_root": os.environ.get("PDK_ROOT", get_default_pdk_root()),
        "orfs_root": os.environ.get("ORFS_ROOT", ""),
        "tools": {},
        "issues": [],
    }
    for tool in ("openroad", "yosys", "klayout", "magic", "netgen"):
        path = get_tool_path(tool)
        result["tools"][tool] = path
        if not path:
            result["issues"].append(f"{tool} not found in PATH")
    if not result["pdk_root"] or not Path(result["pdk_root"]).is_dir():
        result["issues"].append(f"PDK_ROOT directory not found: {result['pdk_root']}")
    return result


def to_native_path(path_str: str) -> str:
    path = Path(path_str)
    plat = get_platform()
    if plat == "wsl2" and path_str.startswith("/mnt/"):
        parts = path_str.split("/")
        drive = parts[2].upper()
        rest = "/".join(parts[3:])
        sep = "\\"
        backslash_path = rest.replace("/", sep)
        return drive + ":" + sep + backslash_path
    return str(path.resolve())
