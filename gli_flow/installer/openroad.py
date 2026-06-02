import json
import os
import shutil
import subprocess
import sys
import tempfile
import urllib.request
from pathlib import Path
from typing import Optional

from gli_flow.installer.system import check_command, run_sudo, run, detect_tool, get_openroad_recommendation


OPENROAD_MIN_VERSION = "2.0"
RELEASES_API = "https://api.github.com/repos/Precision-Innovations/OpenROAD/releases?per_page=10"
SUPPORTED_UBUNTU_VERSIONS = ["20.04", "22.04", "24.04"]


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


def install_linux(info) -> tuple[bool, str]:
    detection = detect_tool("openroad", ["openroad", "-version"])
    if detection.exists and detection.version:
        return (True, f"already installed ({detection.version})")

    ok, msg = _install_via_apt()
    if ok:
        return (True, msg)

    ok, msg = _install_via_deb(info)
    if ok:
        return (True, msg)

    return (False, get_openroad_recommendation())


def _install_via_apt() -> tuple[bool, str]:
    if not shutil.which("apt-get"):
        return (False, "apt-get not available")
    ok = run_sudo(["apt-get", "install", "-y", "openroad"], "Installing OpenROAD via apt")
    if ok:
        detection = detect_tool("openroad", ["openroad", "-version"])
        if detection.exists:
            return (True, f"installed via apt ({detection.version})")
    return (False, "apt package 'openroad' not found in repository")


def _install_via_deb(info) -> tuple[bool, str]:
    deb_map = _fetch_deb_urls()
    if not deb_map:
        return (False, "no OpenROAD .deb releases found on GitHub")
    ubuntu_ver = info.version
    candidates = []
    if ubuntu_ver in deb_map:
        candidates.append(ubuntu_ver)
    for preferred in ["24.04", "22.04", "20.04"]:
        if preferred in deb_map and preferred not in candidates:
            candidates.append(preferred)
    for uv in candidates:
        url = deb_map[uv]
        if _install_deb(url):
            detection = detect_tool("openroad", ["openroad", "-version"])
            if detection.exists:
                return (True, f"installed via .deb ({detection.version})")
        return (False, f".deb for Ubuntu {uv} installed but openroad not found")
    return (False, "no compatible .deb found for this system")


def _download_deb(url: str, dest: str) -> bool:
    if shutil.which("wget"):
        try:
            result = run(["wget", "-q", url, "-O", dest])
            if result.returncode == 0:
                return True
        except FileNotFoundError:
            pass
    if shutil.which("curl"):
        try:
            result = run(["curl", "-fsSL", "-o", dest, url])
            return result.returncode == 0
        except FileNotFoundError:
            pass
    return False


def _install_deb(url: str) -> bool:
    tmp = tempfile.mktemp(suffix=".deb")
    try:
        print("  [INFO] Downloading OpenROAD .deb ...")
        if not _download_deb(url, tmp):
            print("  [WARN] Download failed")
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


def install_darwin() -> bool:
    try:
        subprocess.run(
            ["brew", "install", "openroad"],
            check=True, capture_output=True, timeout=600,
        )
        return True
    except (subprocess.CalledProcessError, FileNotFoundError):
        return False


def install(info) -> tuple[bool, str]:
    if info.is_macos:
        ok = install_darwin()
        return (ok, "installed via brew" if ok else "brew install failed")
    return install_linux(info)