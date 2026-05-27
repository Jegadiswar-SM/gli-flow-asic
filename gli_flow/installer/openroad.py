import os
import shutil
import subprocess
import tempfile
from pathlib import Path
from typing import Optional

from gli_flow.installer.system import check_command, run_sudo, run


OPENROAD_MIN_VERSION = "2.0"
OPENROAD_APT_PACKAGE = "openroad"

OPENROAD_DEB_URLS = {
    "22.04": "https://github.com/Precision-Innovations/OpenROAD/releases/download/2024-12-14/openroad_2.0-17598-ga008522d8_amd64-ubuntu-22.04.deb",
    "24.04": "https://github.com/Precision-Innovations/OpenROAD/releases/download/2024-12-14/openroad_2.0-17606-g3c8ed3657_amd64-ubuntu-24.04.deb",
}


def is_installed() -> Optional[str]:
    return check_command("openroad")


def installed_version() -> Optional[str]:
    path = is_installed()
    if not path:
        return None
    try:
        result = run(["openroad", "-version"])
        return result.stdout.strip() or result.stderr.strip()
    except Exception:
        return None


def install_linux(info) -> bool:
    deb_url = OPENROAD_DEB_URLS.get(info.version)
    if deb_url:
        return _install_deb(deb_url)
    return _install_apt()


def _install_deb(url: str) -> bool:
    tmp = tempfile.mktemp(suffix=".deb")
    try:
        run(["wget", "-q", url, "-O", tmp])

        _remove_conflicting_packages()

        ok = run_sudo(
            ["dpkg", "--force-overwrite", "-i", tmp],
            "Installing OpenROAD .deb",
        )
        run_sudo(["apt-get", "install", "-y", "-f"], "Fixing dependencies")

        if not ok:
            ok = run_sudo(
                ["dpkg", "--force-overwrite", "-i", tmp],
                "Retrying OpenROAD install",
            )
            run_sudo(["apt-get", "install", "-y", "-f"], "Fixing dependencies")

        return ok
    finally:
        if os.path.exists(tmp):
            os.remove(tmp)


def _remove_conflicting_packages():
    conflicts = ["opensta"]
    for pkg in conflicts:
        run_sudo(
            ["dpkg", "--remove", "--force-depends", pkg],
            f"Removing conflicting package {pkg}",
        )


def _install_apt() -> bool:
    return run_sudo(
        ["apt-get", "install", "-y", OPENROAD_APT_PACKAGE],
        "Installing OpenROAD via apt",
    )


def install_darwin() -> bool:
    try:
        subprocess.run(
            ["brew", "install", "openroad"],
            check=True, capture_output=True, timeout=600,
        )
        return True
    except (subprocess.CalledProcessError, FileNotFoundError):
        return False


def install(info) -> bool:
    if info.is_macos:
        return install_darwin()
    return install_linux(info)
