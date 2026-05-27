import os
import platform
import subprocess
import shutil
from dataclasses import dataclass, field
from typing import Optional


SUPPORTED_PLATFORMS = {
    "ubuntu": {"22.04", "24.04"},
    "debian": {"11", "12"},
    "darwin": set(),
}


@dataclass
class SystemInfo:
    distro: str
    version: str
    arch: str
    is_macos: bool = False
    is_linux: bool = True
    package_manager: str = "apt"
    has_sudo: bool = False
    errors: list[str] = field(default_factory=list)


def detect_platform() -> SystemInfo:
    arch_map = {"x86_64": "amd64", "aarch64": "arm64", "arm64": "arm64"}
    raw_arch = platform.machine()
    arch = arch_map.get(raw_arch, raw_arch)
    system = platform.system()

    if system == "Darwin":
        return SystemInfo(
            distro="macos",
            version=platform.mac_ver()[0] or "unknown",
            arch=arch,
            is_macos=True,
            is_linux=False,
            package_manager="brew",
            has_sudo=False,
        )

    info = SystemInfo(distro="unknown", version="", arch=arch)

    try:
        import distro
        info.distro = distro.id().lower()
        info.version = distro.version() or ""
    except (ImportError, Exception):
        try:
            with open("/etc/os-release") as f:
                for line in f:
                    if line.startswith("ID="):
                        info.distro = line.split("=", 1)[1].strip().strip('"')
                    elif line.startswith("VERSION_ID="):
                        info.version = line.split("=", 1)[1].strip().strip('"')
        except FileNotFoundError:
            info.errors.append("Cannot detect Linux distribution")

    try:
        result = subprocess.run(
            ["sudo", "-n", "true"], capture_output=True, timeout=5
        )
        info.has_sudo = result.returncode == 0
    except (subprocess.SubprocessError, FileNotFoundError):
        info.has_sudo = os.geteuid() == 0

    return info


def check_command(name: str) -> Optional[str]:
    return shutil.which(name)


def check_tool_version(name: str, min_version: Optional[str] = None) -> Optional[str]:
    path = check_command(name)
    if not path:
        return None
    try:
        result = subprocess.run(
            [name, "--version"], capture_output=True, text=True, timeout=10
        )
        return result.stdout.strip() or result.stderr.strip()
    except (subprocess.SubprocessError, FileNotFoundError):
        return None


def run_sudo(cmd: list[str], description: str = "") -> bool:
    if os.geteuid() == 0:
        full_cmd = cmd
    else:
        full_cmd = ["sudo"] + cmd
    try:
        subprocess.run(full_cmd, check=True, timeout=300)
        return True
    except subprocess.CalledProcessError:
        return False


def run(cmd: list[str], timeout: int = 300) -> subprocess.CompletedProcess:
    return subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)


def check_python_version() -> tuple[bool, str]:
    v = platform.python_version_tuple()
    major, minor = int(v[0]), int(v[1])
    ok = major >= 3 and minor >= 9
    return ok, f"{major}.{minor}.{v[2]}"


APT_DEPS = [
    "git",
    "curl",
    "wget",
    "ca-certificates",
    "build-essential",
    "cmake",
    "python3",
    "python3-pip",
    "python3-venv",
    "tcl",
    "tcl-dev",
    "tk-dev",
    "libffi-dev",
    "libssl-dev",
    "libgomp1",
    "libtcl8.6",
]

BREW_DEPS = [
    "git",
    "cmake",
    "python@3.11",
    "tcl-tk",
    "libffi",
    "openssl",
]
