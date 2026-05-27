import subprocess

from gli_flow.installer.system import check_command, run_sudo, run


KLAYOUT_MIN_VERSION = "0.28"
KLAYOUT_APT_PACKAGE = "klayout"
KLAYOUT_BREW_PACKAGE = "klayout"


def is_installed() -> bool:
    return check_command("klayout") is not None


def installed_version() -> str:
    try:
        result = run(["klayout", "-b", "-v"])
        return result.stdout.strip() or result.stderr.strip()
    except Exception:
        return ""


def install_linux() -> bool:
    return run_sudo(["apt-get", "install", "-y", KLAYOUT_APT_PACKAGE])


def install_darwin() -> bool:
    try:
        subprocess.run(
            ["brew", "install", KLAYOUT_BREW_PACKAGE],
            check=True, capture_output=True, timeout=600,
        )
        return True
    except (subprocess.CalledProcessError, FileNotFoundError):
        return False


def install(info) -> bool:
    if info.is_macos:
        return install_darwin()
    return install_linux()
