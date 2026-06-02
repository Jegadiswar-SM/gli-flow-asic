import os
import subprocess
import sys
from pathlib import Path
from typing import Optional

from gli_flow.installer.system import check_command, run


SUPPORTED_PDKS = {"sky130", "gf180mcu"}
DEFAULT_PDK_ROOT = "/pdk"
DEFAULT_SKY130_COMMIT = "bdc9412b3e468c102d01b7cf6337be06ec6e9c9a"
DEFAULT_GF180_COMMIT = "4c3cb2e0a9e6c7f8d1a2b3c4d5e6f7a8b9c0d1e2"


def volare_installed() -> bool:
    return check_command("volare") is not None


def install_volare() -> bool:
    try:
        result = subprocess.run(
            ["pip3", "install", "volare"],
            check=True, capture_output=True, timeout=120,
        )
        return True
    except subprocess.CalledProcessError as e:
        err = e.stderr.decode() if e.stderr else str(e)
        print(f"  [WARN] volare install failed: {err[:150]}", file=sys.stderr)
        return False
    except FileNotFoundError:
        print("  [WARN] pip3 not found; cannot install volare", file=sys.stderr)
        return False


def pdk_is_installed(pdk: str, pdk_root: str = DEFAULT_PDK_ROOT) -> bool:
    candidates = [pdk]
    if pdk == "sky130":
        candidates += ["sky130A", "sky130B"]
    for cand in candidates:
        pdk_path = Path(pdk_root) / cand
        if pdk_path.exists() and any(pdk_path.iterdir()):
            return True
    return False


def install_sky130(pdk_root: str, commit: str = DEFAULT_SKY130_COMMIT) -> bool:
    env = os.environ.copy()
    env["PDK_ROOT"] = pdk_root
    try:
        subprocess.run(
            ["volare", "enable", "--pdk", "sky130", commit],
            check=True, capture_output=True, timeout=600,
            env=env,
        )
        return True
    except subprocess.CalledProcessError:
        print(f"  [WARN] volare enable failed for sky130 (commit={commit})", file=sys.stderr)
        try:
            result = subprocess.run(
                ["volare", "enable", "--pdk", "sky130"],
                check=True, capture_output=True, timeout=600,
                env=env,
            )
            return True
        except subprocess.CalledProcessError as e:
            err = e.stderr.decode() if e.stderr else str(e)
            print(f"  [WARN] volare enable failed (no commit): {err[:200]}", file=sys.stderr)
            return False


def install_gf180mcu(pdk_root: str, commit: str = DEFAULT_GF180_COMMIT) -> bool:
    env = os.environ.copy()
    env["PDK_ROOT"] = pdk_root
    try:
        subprocess.run(
            ["volare", "enable", "--pdk", "gf180mcu", commit],
            check=True, capture_output=True, timeout=600,
            env=env,
        )
        return True
    except subprocess.CalledProcessError:
        return False


def ensure_pdk_root(pdk_root: str) -> bool:
    path = Path(pdk_root)
    try:
        path.mkdir(parents=True, exist_ok=True)
        return True
    except PermissionError:
        try:
            subprocess.run(
                ["sudo", "mkdir", "-p", pdk_root],
                check=True, capture_output=True, timeout=30,
            )
            subprocess.run(
                ["sudo", "chmod", "a+rwx", pdk_root],
                check=True, capture_output=True, timeout=30,
            )
            return True
        except subprocess.CalledProcessError:
            return False


def install_pdk(pdk: str, pdk_root: str = DEFAULT_PDK_ROOT, force: bool = False) -> bool:
    if not force and pdk_is_installed(pdk, pdk_root):
        return True

    if not ensure_pdk_root(pdk_root):
        return False

    if not volare_installed():
        if not install_volare():
            return False

    if pdk == "sky130":
        return install_sky130(pdk_root)
    elif pdk == "gf180mcu":
        return install_gf180mcu(pdk_root)

    return False
