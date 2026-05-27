import subprocess

from gli_flow.installer.system import check_command, run_sudo, run


YOSYS_MIN_VERSION = "0.33"
YOSYS_APT_PACKAGE = "yosys"
YOSYS_BREW_PACKAGE = "yosys"


def is_installed() -> bool:
    return check_command("yosys") is not None


def installed_version() -> str:
    try:
        result = run(["yosys", "-V"])
        return result.stdout.strip() or result.stderr.strip()
    except Exception:
        return ""


def install_linux() -> bool:
    return run_sudo(["apt-get", "install", "-y", YOSYS_APT_PACKAGE])


def install_darwin() -> bool:
    try:
        subprocess.run(
            ["brew", "install", YOSYS_BREW_PACKAGE],
            check=True, capture_output=True, timeout=600,
        )
        return True
    except (subprocess.CalledProcessError, FileNotFoundError):
        return False


def install(info) -> bool:
    if info.is_macos:
        return install_darwin()
    return install_linux()
