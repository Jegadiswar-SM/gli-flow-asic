import os
import shutil
import subprocess
from pathlib import Path
from typing import Optional

from gli_flow.installer.system import check_command


ORFS_REPO = "https://github.com/The-OpenROAD-Project/OpenROAD-flow-scripts.git"
ORFS_PINNED_COMMIT = "7b05472e7168e8193587244a9c28ab8adaae1047"


def _git_env() -> dict[str, str]:
    env = os.environ.copy()
    env["GIT_TERMINAL_PROMPT"] = "0"
    env["GIT_ASKPASS"] = "echo"
    return env


def default_orfs_root() -> str:
    return os.path.join(os.path.expanduser("~"), ".gli-flow", "orfs")


def is_installed(orfs_root: str = None) -> bool:
    root = Path(orfs_root or default_orfs_root())
    return (root / "flow" / "Makefile").exists()


def install(orfs_root: str = None, force: bool = False) -> bool:
    root = Path(orfs_root or default_orfs_root())

    if not force and is_installed(str(root)):
        return True

    if not check_command("git"):
        return False

    env = _git_env()

    if (root / ".git").exists():
        if is_installed(str(root)):
            try:
                subprocess.run(
                    ["git", "-C", str(root), "pull", "--ff-only"],
                    check=True, capture_output=True, timeout=120, env=env,
                )
                return True
            except (subprocess.CalledProcessError, subprocess.TimeoutExpired):
                pass

    shutil.rmtree(str(root), ignore_errors=True)
    root.mkdir(parents=True, exist_ok=True)

    try:
        subprocess.run(
            ["git", "clone", "--depth", "1", ORFS_REPO, str(root)],
            check=True, capture_output=True, timeout=600, env=env,
        )

        subprocess.run(
            ["git", "-C", str(root), "checkout", ORFS_PINNED_COMMIT],
            check=True, capture_output=True, timeout=30, env=env,
        )

        return is_installed(str(root))

    except subprocess.CalledProcessError as e:
        stderr = (e.stderr or "").strip()[:200]
        print(f"  [WARN] ORFS clone failed: {stderr}")
        return False
    except subprocess.TimeoutExpired:
        print("  [WARN] ORFS clone timed out (repo is large, retry with --force)")
        return False


def installed_version(orfs_root: str = None) -> Optional[str]:
    root = Path(orfs_root or default_orfs_root())
    head = root / ".git" / "HEAD"
    if head.exists():
        try:
            return head.read_text().strip()
        except OSError:
            pass
    return None
