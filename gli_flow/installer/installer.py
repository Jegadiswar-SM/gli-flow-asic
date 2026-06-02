import os
import subprocess
import sys
import platform
from pathlib import Path
from typing import Optional

from gli_flow.installer.system import (
    detect_platform,
    check_python_version,
    check_command,
    APT_DEPS,
    BREW_DEPS,
    run_sudo,
)
from gli_flow.installer import openroad, yosys, klayout, pdk, orfs, workspace
from gli_flow.installer.validation import (
    InstallReport,
    ValidationResult,
    TOOLCHAIN,
    run_pdk_validation,
)
from gli_flow.version import VERSION


SUPPORTED_PDKS = {"sky130", "gf180mcu"}


class Installer:
    def __init__(
        self,
        pdk_name: str = "sky130",
        pdk_root: str = None,
        orfs_root: str = None,
        force: bool = False,
        dry_run: bool = False,
        skip_system: bool = False,
        skip_pdk: bool = False,
        skip_orfs: bool = False,
        prefix: Optional[str] = None,
    ):
        self.pdk_name = pdk_name
        self.pdk_root = pdk_root or os.environ.get("PDK_ROOT", str(Path.home() / ".gli-flow" / "pdk"))
        self._orfs_root = orfs_root
        self.force = force
        self.dry_run = dry_run
        self.skip_system = skip_system
        self.skip_pdk = skip_pdk
        self.skip_orfs = skip_orfs
        self.prefix = prefix or "/usr/local"
        self.report = InstallReport()
        self.info = detect_platform()

    @property
    def orfs_root(self):
        if self._orfs_root:
            return self._orfs_root
        config = workspace.load_config()
        return config.get("orfs_root", orfs.default_orfs_root())

    def run(self) -> InstallReport:
        self._check_prerequisites()
        self._install_system_deps()
        self._install_toolchain()
        self._install_orfs()
        if not self.skip_pdk:
            self._install_pdk()
        self._setup_workspace()
        self._install_gli_flow()
        self._validate()
        return self.report

    def _check_prerequisites(self) -> None:
        if self.info.errors:
            for err in self.info.errors:
                self.report.failed.append(f"Platform detection: {err}")

    def _install_system_deps(self) -> None:
        if self.skip_system:
            self.report.skipped.append("system-deps")
            return

        if self.info.is_linux and self.info.package_manager == "apt":
            self._install_apt_deps()
        elif self.info.is_macos:
            self._install_brew_deps()
        else:
            self.report.skipped.append(
                f"system-deps (unsupported: {self.info.distro})"
            )

    def _install_apt_deps(self) -> None:
        if self.dry_run:
            self.report.completed.append(
                f"system-deps: apt-get install {' '.join(APT_DEPS)}"
            )
            return

        ok = run_sudo(["apt-get", "update"], "Updating package lists")
        if not ok:
            self.report.failed.append("apt-get update failed")
            return

        ok = run_sudo(
            ["apt-get", "install", "-y"] + APT_DEPS,
            "Installing system dependencies",
        )
        if ok:
            self.report.completed.append("system-deps")
        else:
            self.report.failed.append("system-deps")

    def _install_brew_deps(self) -> None:
        if self.dry_run:
            self.report.completed.append(
                f"system-deps: brew install {' '.join(BREW_DEPS)}"
            )
            return

        try:
            subprocess.run(
                ["brew", "install"] + BREW_DEPS,
                check=True, capture_output=True, timeout=600,
            )
            self.report.completed.append("system-deps")
        except Exception:
            self.report.failed.append("system-deps (brew install failed)")

    def _install_toolchain(self) -> None:
        self._install_component("yosys", yosys)
        self._install_component("klayout", klayout)
        self._install_component("openroad", openroad)

    def _install_component(self, name: str, module) -> None:
        if not self.force and module.is_installed():
            self.report.skipped.append(name)
            return

        if self.dry_run:
            self.report.completed.append(f"{name} (would install)")
            return

        ok = module.install(self.info)
        if ok:
            self.report.completed.append(name)
        else:
            self.report.failed.append(name)

    def _install_orfs(self) -> None:
        if self.skip_orfs:
            self.report.skipped.append("orfs")
            return

        orfs_root = self.orfs_root

        if not self.force and orfs.is_installed(orfs_root):
            self.report.skipped.append("orfs")
            return

        if self.dry_run:
            self.report.completed.append(
                f"orfs: git clone {orfs.ORFS_REPO} -> {orfs_root}"
            )
            return

        if not check_command("git"):
            self.report.failed.append("orfs (git not found)")
            return

        ok = orfs.install(orfs_root, self.force)
        if ok:
            self.report.completed.append("orfs")
        else:
            self.report.failed.append("orfs (clone failed)")

    def _install_pdk(self) -> None:
        if self.pdk_name not in SUPPORTED_PDKS:
            self.report.failed.append(
                f"pdk:{self.pdk_name} (unsupported; choose from {SUPPORTED_PDKS})"
            )
            return

        if not self.force and pdk.pdk_is_installed(self.pdk_name, self.pdk_root):
            self.report.skipped.append(f"pdk:{self.pdk_name}")
            return

        if self.dry_run:
            self.report.completed.append(f"pdk:{self.pdk_name} (would install)")
            return

        ok = pdk.install_pdk(self.pdk_name, self.pdk_root, self.force)
        if ok:
            self.report.completed.append(f"pdk:{self.pdk_name}")
        else:
            self.report.failed.append(f"pdk:{self.pdk_name}")

    def _setup_workspace(self) -> None:
        if self.dry_run:
            self.report.completed.append(
                "workspace: ~/.gli-flow/ {orfs, pdk, designs, runs, config.json}"
            )
            return

        config = workspace.write_default_config(
            orfs_root=self.orfs_root,
            pdk_root=self.pdk_root,
        )
        self.report.completed.append(
            f"workspace: {config.get('orfs_root', '?')}"
        )

    def _install_gli_flow(self) -> None:
        if self.dry_run:
            self.report.completed.append("gli-flow (pip install)")
            return

        try:
            result = subprocess.run(
                [sys.executable, "-m", "pip", "install", "-e", "."],
                check=True, capture_output=True, timeout=120,
                cwd=Path(__file__).resolve().parent.parent.parent,
            )
            self.report.completed.append("gli-flow")
        except subprocess.CalledProcessError as e:
            err = e.stderr.decode() if e.stderr else str(e)
            self.report.failed.append(f"gli-flow (pip install failed: {err[:200]})")

    def _validate(self) -> None:
        for tool in TOOLCHAIN:
            self.report.add_validation(tool)

        orfs_root = self.orfs_root
        orfs_ok = orfs.is_installed(orfs_root)
        self.report.validations.append(ValidationResult(
            tool="orfs",
            installed=orfs_ok,
            version=orfs_root,
            ok=orfs_ok,
        ))

        pdk_result = run_pdk_validation(self.pdk_name, self.pdk_root)
        self.report.validations.append(pdk_result)

        python_ok, python_ver = check_python_version()
        self.report.validations.append(ValidationResult(
            tool="python3",
            installed=python_ok,
            version=python_ver,
            ok=python_ok,
        ))

        gli_installed = check_command("gli-flow") is not None
        if not gli_installed:
            try:
                import gli_flow
                gli_installed = True
            except ImportError:
                pass
        self.report.validations.append(ValidationResult(
            tool="gli-flow",
            installed=gli_installed,
            version=VERSION,
            ok=gli_installed,
        ))
