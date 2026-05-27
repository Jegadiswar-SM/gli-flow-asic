import shutil
import subprocess
from dataclasses import dataclass, field
from typing import Optional

from gli_flow.installer.system import check_command, check_tool_version


@dataclass
class ValidationResult:
    tool: str
    installed: bool
    version: Optional[str] = None
    path: Optional[str] = None
    ok: bool = False
    error: Optional[str] = None


@dataclass
class InstallReport:
    completed: list[str] = field(default_factory=list)
    skipped: list[str] = field(default_factory=list)
    failed: list[str] = field(default_factory=list)
    validations: list[ValidationResult] = field(default_factory=list)

    @property
    def success(self) -> bool:
        return len(self.failed) == 0

    def add_validation(self, tool: str) -> None:
        path = check_command(tool)
        raw = check_tool_version(tool)
        version = raw.split("\n")[0].strip() if raw else None
        installed = path is not None
        self.validations.append(ValidationResult(
            tool=tool,
            installed=installed,
            version=version,
            path=path,
            ok=installed,
        ))


TOOLCHAIN = [
    "git",
    "cmake",
    "yosys",
    "openroad",
    "klayout",
]

PDK_TOOLS = [
    "volare",
]


def run_pdk_validation(pdk: str, pdk_root: str = "/pdk") -> ValidationResult:
    import os
    from pathlib import Path
    # Volare installs as sky130A (not sky130); check common variants
    candidates = [pdk]
    if pdk == "sky130":
        candidates += ["sky130A", "sky130B"]
    pdk_dir = None
    installed = False
    for cand in candidates:
        d = Path(pdk_root) / cand
        if d.exists() and any(d.iterdir()):
            pdk_dir = d
            installed = True
            break
    if pdk_dir is None:
        pdk_dir = Path(pdk_root) / pdk
    return ValidationResult(
        tool=f"pdk:{pdk}",
        installed=installed,
        path=str(pdk_dir),
        ok=installed,
    )


def run_flow_validation(design_dir: Optional[str] = None) -> ValidationResult:
    if not design_dir:
        return ValidationResult(
            tool="flow",
            installed=False,
            error="No design provided",
        )
    manifest = Path(design_dir) / "gli_manifest.yaml"
    ok = manifest.exists()
    return ValidationResult(
        tool="flow",
        installed=ok,
        path=str(manifest) if ok else None,
        error=None if ok else "No gli_manifest.yaml found",
        ok=ok,
    )
