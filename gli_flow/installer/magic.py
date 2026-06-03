import os
import re
import shutil
import subprocess
import tempfile
from pathlib import Path

from gli_flow.core.subprocess_env import safe_env
from gli_flow.installer.system import check_command, run_sudo, run, apt_package_exists, detect_tool


MAGIC_MIN_VERSION = "8.3.411"
MAGIC_APT_PACKAGE = "magic"
MAGIC_REPO = "https://github.com/RTimothyEdwards/magic.git"


def is_installed() -> bool:
    return check_command("magic") is not None


def _parse_version(version_str: str) -> tuple[int, ...]:
    match = re.search(r'(\d+\.\d+(?:\.\d+)?)', version_str)
    if match:
        parts = match.group(1).split('.')
        return tuple(int(p) for p in parts)
    return (0,)


def installed_version() -> str:
    try:
        result = run(["magic", "-noconsole", "-dnull", "-version"])
        return result.stdout.strip() or result.stderr.strip()
    except Exception:
        return ""


def install_linux(info) -> tuple[bool, str]:
    detection = detect_tool("magic", ["magic", "-noconsole", "-dnull", "-version"])
    if detection.exists and detection.version:
        return (True, f"already installed ({detection.version})")

    if apt_package_exists(MAGIC_APT_PACKAGE):
        if run_sudo(["apt-get", "install", "-y", MAGIC_APT_PACKAGE]):
            ver = installed_version()
            cur_ver = _parse_version(ver)
            min_ver = _parse_version(MAGIC_MIN_VERSION)
            if cur_ver >= min_ver:
                return (True, f"installed via apt ({ver})")
            print(f"  [WARN] Magic {ver} may be too old for sky130 PDK (need >= {MAGIC_MIN_VERSION})")
            print("  [INFO] Building a newer version from source ...")
            if _build_from_source():
                return (True, "built from source")
            print("  [INFO] To build manually:")
            print(f"    sudo apt-get install -y libx11-dev")
            print(f"    git clone {MAGIC_REPO}")
            print(f"    cd magic && ./configure && make -j$(nproc) && sudo make install")
            print()
            return (True, "installed via apt (older version)")
        return (False, "apt install failed")

    print(f"  [INFO] Building Magic VLSI from source ...")
    ok = _build_from_source()
    if ok:
        return (True, "built from source")
    return (False, "magic build from source failed")


def _build_from_source() -> bool:
    build = Path(tempfile.mkdtemp(prefix="magic-build-"))
    src = build / "magic"
    try:
        subprocess.run(
            ["git", "clone", "--depth", "1", MAGIC_REPO, str(src)],
            check=True, capture_output=True, timeout=120, env=safe_env(),
        )

        log = subprocess.run(
            ["./configure", "--prefix=/usr/local"],
            capture_output=True, timeout=120, cwd=str(src), env=safe_env(),
        )
        if log.returncode != 0:
            print(f"  [WARN] magic configure failed: {log.stderr.decode()[:300]}")
            return False

        log = subprocess.run(
            ["make", f"-j{os.cpu_count() or 1}"],
            capture_output=True, timeout=600, cwd=str(src), env=safe_env(),
        )
        if log.returncode != 0:
            print(f"  [WARN] magic make failed: {log.stderr.decode()[:300]}")
            return False

        log = subprocess.run(
            ["sudo", "make", "install"],
            capture_output=True, timeout=120, cwd=str(src), env=safe_env(),
        )
        if log.returncode != 0:
            print(f"  [WARN] magic make install failed: {log.stderr.decode()[:300]}")
            return False

        if check_command("magic"):
            ver = installed_version()
            cur_ver = _parse_version(ver)
            min_ver = _parse_version(MAGIC_MIN_VERSION)
            print(f"  [INFO] Installed Magic {ver}")
            if cur_ver < min_ver:
                print(f"  [WARN] Built Magic {ver} still below recommended {MAGIC_MIN_VERSION}")
            return True

        print("  [WARN] magic built but not found on PATH")
        print("  [INFO] Ensure /usr/local/bin is in your PATH")
        return False
    except Exception as e:
        print(f"  [WARN] magic build failed: {e}")
        return False
    finally:
        shutil.rmtree(str(build), ignore_errors=True)


def install_darwin() -> tuple[bool, str]:
    try:
        subprocess.run(
            ["brew", "install", "magic-vlsi"],
            check=True, capture_output=True, timeout=600, env=safe_env(),
        )
        return (True, "installed via brew")
    except (subprocess.CalledProcessError, FileNotFoundError):
        print("  [INFO] Building Magic from source on macOS ...")
        ok = _build_from_source()
        if ok:
            return (True, "built from source on macOS")
        return (False, "magic installation failed on macOS")


def install(info) -> tuple[bool, str]:
    if info.is_macos:
        return install_darwin()
    return install_linux(info)
