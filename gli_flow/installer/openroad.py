import json
import os
import shutil
import subprocess
import sys
import tempfile
import urllib.request
from pathlib import Path
from typing import Optional

from gli_flow.installer.system import check_command, run_sudo, run


OPENROAD_MIN_VERSION = "2.0"
OPENROAD_APT_PACKAGE = "openroad"

RELEASES_API = "https://api.github.com/repos/Precision-Innovations/OpenROAD/releases?per_page=10"

SUPPORTED_UBUNTU_VERSIONS = ["20.04", "22.04"]


def _fetch_deb_urls():
    try:
        req = urllib.request.Request(RELEASES_API, headers={"Accept": "application/json", "User-Agent": "gli-flow"})
        with urllib.request.urlopen(req, timeout=15) as resp:
            releases = json.loads(resp.read())

        deb_map = {}
        for rel in releases:
            for asset in rel.get("assets", []):
                name = asset["name"]
                if "ubuntu" in name and name.endswith(".deb"):
                    for uv in SUPPORTED_UBUNTU_VERSIONS:
                        if f"ubuntu-{uv}" in name or f"ubuntu{uv}" in name:
                            if uv not in deb_map:
                                deb_map[uv] = asset["browser_download_url"]
        return deb_map
    except Exception:
        return {}


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
    if _install_apt():
        return True

    deb_map = _fetch_deb_urls()

    ubuntu_ver = info.version
    if ubuntu_ver in deb_map:
        if _install_deb(deb_map[ubuntu_ver]):
            return True

    best = "22.04"
    if best in deb_map:
        print(f"  [INFO] No OpenROAD binary for Ubuntu {ubuntu_ver}, trying {best} .deb")
        if _install_deb(deb_map[best]):
            return True

    if deb_map:
        fallback_url = list(deb_map.values())[0]
        print(f"  [INFO] Trying closest available OpenROAD .deb")
        if _install_deb(fallback_url):
            return True

    return _install_from_source(info)


def _install_deb(url: str) -> bool:
    tmp = tempfile.mktemp(suffix=".deb")
    try:
        print(f"  [INFO] Downloading OpenROAD .deb ...")
        result = run(["wget", "-q", url, "-O", tmp])
        if result.returncode != 0:
            print(f"  [WARN] Download failed: {result.stderr.strip()}")
            return False

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


def _install_from_source(info) -> bool:
    print()
    print("  [INFO] Could not install OpenROAD automatically.")
    print("  [INFO] Install it manually:")
    print()
    print("    Option 1 — Binary download:")
    print("      https://vaultlink.precisioninno.com/")
    print()
    print("    Option 2 — Build from source:")
    print("      git clone --recursive https://github.com/The-OpenROAD-Project/OpenROAD.git")
    print("      cd OpenROAD && mkdir build && cd build")
    print("      cmake .. -DCMAKE_BUILD_TYPE=RELEASE")
    print("      make -j$(nproc) && sudo make install")
    print()
    print("    Option 3 — Docker:")
    print("      docker pull openroad/flow")
    print()
    return False


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
