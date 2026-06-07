import os
import re
import shutil
import subprocess
from dataclasses import dataclass, field
from pathlib import Path
from typing import Optional

from gli_flow.core.subprocess_env import safe_env
from gli_flow.installer.system import check_command


@dataclass
class ValidationResult:
    tool: str
    installed: bool
    version: Optional[str] = None
    path: Optional[str] = None
    ok: bool = False
    error: Optional[str] = None
    remediation: Optional[str] = None


@dataclass
class InstallReport:
    completed: list[str] = field(default_factory=list)
    skipped: list[str] = field(default_factory=list)
    failed: list[str] = field(default_factory=list)
    action_required: list[tuple[str, str, str]] = field(default_factory=list)
    validations: list[ValidationResult] = field(default_factory=list)

    @property
    def success(self) -> bool:
        if self.failed:
            return False
        if self.validations:
            return all(v.ok for v in self.validations)
        return True

    @property
    def install_steps(self):
        return []

    @property
    def validation_items(self):
        return self.validations

    def add_validation(self, tool: str) -> None:
        path = check_command(tool)
        version = check_tool_version_with_flag(tool)
        installed = path is not None
        version_ok = meets_min_version(tool, version) if installed else False
        self.validations.append(ValidationResult(
            tool=tool,
            installed=installed,
            version=version,
            path=path,
            ok=installed and version_ok,
            error=f"Version {version} does not meet minimum {TOOL_MIN_VERSIONS.get(tool, 'any')}" if installed and not version_ok else None,
        ))

    def _render_table(self, rows: list[tuple[str, str, str]]) -> str:
        if not rows:
            return "  (none)"
        name_w = max(len(r[0]) for r in rows) + 2
        status_w = 10
        lines = []
        for name, status, detail in rows:
            lines.append(f"  {name:<{name_w}} {status:<{status_w}} {detail}")
        return "\n".join(lines)

    def summary_text(self) -> str:
        lines = []
        lines.append("")
        lines.append("Installation Summary")
        lines.append("=" * 60)
        lines.append("")

        passes = [v for v in self.validations if v.ok]
        fails = [v for v in self.validations if not v.ok and v.installed is False]
        version_fails = [v for v in self.validations if v.installed and not v.ok]

        if passes:
            lines.append("PASS:")
            for v in passes:
                lines.append(f"  - {v.tool}  ({v.version or 'installed'})")
            lines.append("")

        if fails:
            lines.append("FAIL (not installed):")
            for v in fails:
                lines.append(f"  - {v.tool}")
                if v.remediation:
                    lines.append(f"      {v.remediation}")
            lines.append("")

        if version_fails:
            lines.append("FAIL (version mismatch):")
            for v in version_fails:
                lines.append(f"  - {v.tool} has {v.version}, need {TOOL_MIN_VERSIONS.get(v.tool, '?')}")
                if v.remediation:
                    lines.append(f"      {v.remediation}")
            lines.append("")

        if self.action_required:
            lines.append("ACTION REQUIRED:")
            for tool, reason, remediation in self.action_required:
                lines.append(f"  - {tool}: {reason}")
                if remediation:
                    lines.append(f"{remediation}")
            lines.append("")

        if self.failed:
            lines.append("INSTALL FAILURES:")
            for f in self.failed:
                lines.append(f"  - {f}")
            lines.append("")

        if passes and not fails and not version_fails and not self.action_required and not self.failed:
            lines.append("  All tools installed and validated.")
            lines.append("")

        overall = "READY" if self.success else "NOT READY"
        lines.append(f"Overall Status: {overall}")
        lines.append("")
        return "\n".join(lines)


TOOLCHAIN = [
    "git",
    "cmake",
    "python3",
    "yosys",
    "openroad",
    "klayout",
    "magic",
    "netgen",
    "sv2v",
]

PDK_TOOLS = [
    "volare",
]

TOOL_MIN_VERSIONS = {
    "python3": "3.9.0",
    "yosys": "0.27",
    "openroad": "2.0",
    "klayout": "0.28",
    "magic": "8.3",
    "netgen": "1.5",
    "sv2v": "0.0",
    "git": "2.0",
    "cmake": "3.10",
}

TOOL_VERSION_FLAGS = {
    "magic": ["magic", "--version"],
    "netgen": ["netgen", "-version"],
    "sv2v": ["sv2v", "--version"],
    "yosys": ["yosys", "-V"],
    "openroad": ["openroad", "-version"],
    "klayout": ["klayout", "-b", "-v"],
    "git": ["git", "--version"],
    "cmake": ["cmake", "--version"],
    "python3": ["python3", "--version"],
}

TOOL_DISPLAY_NAMES = {
    "yosys": "Yosys",
    "openroad": "OpenROAD",
    "klayout": "KLayout",
    "magic": "Magic",
    "netgen": "Netgen",
    "sv2v": "sv2v",
    "git": "Git",
    "cmake": "CMake",
    "python3": "Python3",
}

TOOL_REMEDIATIONS = {
    "yosys": (
        "Install OSS CAD Suite:\n"
        "  wget https://github.com/YosysHQ/oss-cad-suite-build/releases/latest/download/oss-cad-suite-linux-x86_64.tgz\n"
        "  tar -xzf oss-cad-suite-linux-x86_64.tgz\n"
        "  export PATH=\"$PWD/oss-cad-suite/bin:$PATH\"\n"
        "  echo 'export PATH=\"$PWD/oss-cad-suite/bin:$PATH\"' >> ~/.bashrc\n"
        "Reference: https://github.com/YosysHQ/oss-cad-suite-build"
    ),
    "openroad": (
        "Install OpenROAD manually:\n"
        "  Option 1 — Binary download:\n"
        "    https://github.com/The-OpenROAD-Project/OpenROAD/releases\n"
        "  Option 2 — Build from source:\n"
        "    git clone --recursive https://github.com/The-OpenROAD-Project/OpenROAD.git\n"
        "    cd OpenROAD && mkdir build && cd build\n"
        "    cmake .. -DCMAKE_BUILD_TYPE=RELEASE\n"
        "    make -j$(nproc) && sudo make install"
    ),
    "klayout": (
        "Enable universe repository:\n"
        "  sudo add-apt-repository universe\n"
        "  sudo apt-get update\n"
        "  sudo apt-get install klayout\n"
        "Or download from: https://www.klayout.de/build.html"
    ),
    "sv2v": (
        "Install via cargo:\n"
        "  curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh\n"
        "  source $HOME/.cargo/env\n"
        "  cargo install sv2v"
    ),
    "magic": (
        "sudo apt-get install magic"
    ),
    "netgen": (
        "sudo apt-get install netgen-lvs"
    ),
}


def check_tool_version_with_flag(tool: str) -> Optional[str]:
    path = check_command(tool)
    if not path:
        return None
    flags = TOOL_VERSION_FLAGS.get(tool, [tool, "--version"])
    try:
        result = subprocess.run(
            flags,
            capture_output=True, text=True, timeout=10, env=safe_env(),
        )
        ver = (result.stdout or result.stderr or "").strip()
        if not ver:
            return None
        return ver.split("\n")[0]
    except Exception:
        return None


def parse_version(ver_str: str):
    digits = re.findall(r"(\d+\.\d+(?:\.\d+)?)", ver_str)
    if digits:
        parts = digits[0].split(".")
        return tuple(int(p) for p in parts)
    return (0,)


def meets_min_version(tool: str, installed_ver: Optional[str]) -> bool:
    if not installed_ver:
        return False
    min_ver = TOOL_MIN_VERSIONS.get(tool)
    if not min_ver:
        return True
    try:
        installed = parse_version(installed_ver)
        required = parse_version(min_ver)
        return installed >= required
    except Exception:
        return False


def run_pdk_validation(pdk: str, pdk_root: str = "") -> ValidationResult:
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


def doctor_report(validations: list[ValidationResult]) -> str:
    lines = []
    lines.append("")
    lines.append(f"{'Tool':<20} {'Status':<12} {'Version'}")
    lines.append("-" * 60)
    for v in validations:
        status = "PASS" if v.ok else "FAIL"
        version = v.version or "-"
        display = TOOL_DISPLAY_NAMES.get(v.tool, v.tool)
        lines.append(f"{display:<20} {status:<12} {version}")
    lines.append("")
    all_ok = all(v.ok for v in validations)
    lines.append(f"Overall Status: {'READY' if all_ok else 'NOT READY'}")
    lines.append("")
    if not all_ok:
        lines.append("Missing or outdated tools:")
        for v in validations:
            if not v.ok:
                lines.append(f"  - {v.tool}: {v.error or 'not installed'}")
                remed = TOOL_REMEDIATIONS.get(v.tool)
                if remed:
                    lines.append(f"    {remed.split(chr(10))[0]}")
        lines.append("")
    return "\n".join(lines)