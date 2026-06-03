import os
import shutil
import subprocess
import tempfile
from pathlib import Path

from gli_flow.core.subprocess_env import safe_env
from gli_flow.installer.system import check_command, run_sudo, run, apt_package_exists, detect_tool


NETGEN_MIN_VERSION = "1.5"
NETGEN_APT_PACKAGE = "netgen-lvs"
NETGEN_REPO = "https://github.com/RTimothyEdwards/netgen.git"


def is_installed() -> bool:
    return check_command("netgen") is not None


def installed_version() -> str:
    try:
        result = run(["netgen", "-version"])
        return result.stdout.strip() or result.stderr.strip()
    except Exception:
        return ""


def _has_netgenexec() -> bool:
    return check_command("netgenexec") is not None


def install_linux(info) -> tuple[bool, str]:
    detection = detect_tool("netgen", ["netgen", "-version"])
    if detection.exists and detection.version:
        return (True, f"already installed ({detection.version})")

    if apt_package_exists(NETGEN_APT_PACKAGE):
        if run_sudo(["apt-get", "install", "-y", NETGEN_APT_PACKAGE]):
            if _has_netgenexec():
                return (True, "installed via apt")
        print("  [WARN] apt netgen-lvs not available or not the VLSI LVS tool. Building from source ...")
    else:
        print("  [INFO] Building netgen-lvs from source ...")

    ok = _build_from_source()
    if ok:
        return (True, "built from source")
    return (False, "netgen installation failed")


def _build_from_source() -> bool:
    build = Path(tempfile.mkdtemp(prefix="netgen-build-"))
    src = build / "netgen"
    try:
        subprocess.run(
            ["git", "clone", "--depth", "1", NETGEN_REPO, str(src)],
            check=True, capture_output=True, timeout=120, env=safe_env(),
        )

        log = subprocess.run(
            ["./configure", "--prefix=/usr/local"],
            capture_output=True, timeout=120, cwd=str(src), env=safe_env(),
        )
        if log.returncode != 0:
            print(f"  [WARN] netgen configure failed: {log.stderr.decode()[:300]}")
            return False

        log = subprocess.run(
            ["make", f"-j{os.cpu_count() or 1}"],
            capture_output=True, timeout=600, cwd=str(src), env=safe_env(),
        )
        if log.returncode != 0:
            print(f"  [WARN] netgen make failed: {log.stderr.decode()[:300]}")
            return False

        log = subprocess.run(
            ["sudo", "make", "install"],
            capture_output=True, timeout=120, cwd=str(src), env=safe_env(),
        )
        if log.returncode != 0:
            print(f"  [WARN] netgen make install failed: {log.stderr.decode()[:300]}")
            return False

        if _has_netgenexec():
            return True

        for p in ["/usr/local/bin/netgenexec", "/usr/local/bin/netgen"]:
            if os.path.exists(p):
                return True
        print("  [WARN] netgen-lvs built but netgenexec not found on PATH")
        print("  [INFO] Ensure /usr/local/bin is in your PATH")
        return False
    except Exception as e:
        print(f"  [WARN] netgen-lvs build failed: {e}")
        return False
    finally:
        shutil.rmtree(str(build), ignore_errors=True)


def install_darwin() -> tuple[bool, str]:
    try:
        subprocess.run(
            ["brew", "install", "netgen-lvs"],
            check=True, capture_output=True, timeout=600, env=safe_env(),
        )
        return (True, "installed via brew")
    except (subprocess.CalledProcessError, FileNotFoundError):
        print("  [INFO] Building netgen-lvs from source on macOS ...")
        ok = _build_from_source()
        if ok:
            return (True, "built from source on macOS")
        return (False, "netgen installation failed on macOS")


def install(info) -> tuple[bool, str]:
    if info.is_macos:
        return install_darwin()
    return install_linux(info)
