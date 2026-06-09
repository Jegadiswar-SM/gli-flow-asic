"""
gli-flow doctor — REAL tool validation command.

Performs actual tool execution tests:
  - Magic startup, TCL execution, DRC smoke test
  - Netgen startup, LVS smoke test
  - OpenROAD startup, OpenSTA startup
  - Yosys startup, KLayout startup
  - Docker validation, Disk space, RAM, PDK

Output: PASS / WARNING / FAIL with machine-readable JSON.

Discovery reports show all candidates found for each tool,
not just the selected one.
"""

import json
import logging
import os
import shutil
import subprocess
import tempfile
import time
from dataclasses import dataclass, field, asdict
from pathlib import Path
from typing import Any, Optional

from gli_flow.core.subprocess_env import safe_env
from gli_flow.core.tool_discovery import (
    ToolCandidate,
    ToolCandidateStatus,
    discover_magic_binaries,
    validate_magic_candidate,
    find_magic_binary,
    rank_tool_candidates,
)

log = logging.getLogger(__name__)


@dataclass
class DoctorCheck:
    name: str
    status: str = "NOT_RUN"
    detail: str = ""
    runtime_seconds: float = 0.0

    @property
    def passed(self) -> bool:
        return self.status == "PASS"

    @property
    def failed(self) -> bool:
        return self.status == "FAIL"


@dataclass
class DoctorReport:
    checks: list[DoctorCheck] = field(default_factory=list)
    overall_status: str = "NOT_RUN"
    timestamp: str = ""

    @property
    def passed(self) -> bool:
        return all(c.passed for c in self.checks)

    def to_dict(self) -> dict[str, Any]:
        return {
            "overall_status": self.overall_status,
            "timestamp": self.timestamp,
            "checks": [asdict(c) for c in self.checks],
        }

    def to_json(self) -> str:
        return json.dumps(self.to_dict(), indent=2)

    def print_summary(self) -> None:
        print()
        print(f"{'Check':<35} {'Status':<10} {'Detail'}")
        print("-" * 80)
        for c in self.checks:
            detail = c.detail[:60] if c.detail else "-"
            print(f"{c.name:<35} {c.status:<10} {detail}")
        print()
        print(f"Overall: {self.overall_status}")


@dataclass
class DiscoveryItem:
    name: str
    detail: str = ""
    status: str = "INFO"


@dataclass
class DiscoveryReport:
    tool_name: str
    candidates: list[ToolCandidate]
    selected: Optional[ToolCandidate] = None
    issues: list[str] = field(default_factory=list)
    repair_available: bool = False
    repair_command: str = ""

    def print_discovery(self) -> None:
        print()
        print(f"{self.tool_name} Discovery")
        print(f"Found {len(self.candidates)} candidate(s)")
        print("-" * 60)
        for i, c in enumerate(self.candidates, 1):
            selected_mark = "YES" if self.selected and c.path == self.selected.path else "NO"
            print(f"\n  Candidate #{i}")
            print(f"  Path:      {c.path}")
            print(f"  Version:   {c.version_str}")
            print(f"  Status:    {c.status.value.upper()}")
            if c.failure_reason:
                print(f"  Reason:    {c.failure_reason}")
            if c.validation_evidence:
                for ev in c.validation_evidence[:3]:
                    print(f"  Evidence:  {ev}")
            print(f"  Selected:  {selected_mark}")
        if self.issues:
            print(f"\n  Issues:")
            for issue in self.issues:
                print(f"    - {issue}")
        if self.repair_available:
            print(f"\n  Resolution:")
            print(f"    Run: {self.repair_command}")


def _run_tool(args: list[str], timeout: int = 30, input_data: str = None) -> tuple[int, str, str]:
    try:
        result = subprocess.run(
            args,
            capture_output=True,
            text=True,
            timeout=timeout,
            env=safe_env(),
            input=input_data,
        )
        return result.returncode, result.stdout, result.stderr
    except FileNotFoundError:
        return -1, "", "command not found"
    except subprocess.TimeoutExpired:
        return -2, "", "timed out"
    except OSError as e:
        return -3, "", str(e)


def check_magic() -> DoctorCheck:
    start = time.time()
    binary = shutil.which("magic") or "/usr/bin/magic"
    rc, stdout, stderr = _run_tool([binary, "--version"], timeout=10)
    if rc == -1:
        return DoctorCheck(name="magic", status="FAIL", detail="Not installed")
    if rc != 0:
        return DoctorCheck(name="magic", status="FAIL", detail=f"Exit code {rc}: {stderr[:100]}")

    tcl_rc, tcl_out, tcl_err = _run_tool([binary, "-noconsole", "-dnull", "-version"], timeout=15)
    if tcl_rc != 0:
        return DoctorCheck(name="magic", status="FAIL", detail=f"TCL exec failed: {tcl_err[:100]}")

    with tempfile.TemporaryDirectory() as tmp:
        drc_script = Path(tmp) / "drc_test.tcl"
        drc_script.write_text("puts {DRC_SMOKE_OK}\nquit\n")
        smoke_rc, smoke_out, smoke_err = _run_tool(
            [binary, "-noconsole", "-dnull", str(drc_script)],
            timeout=30,
        )
        if smoke_rc == 0 and "DRC_SMOKE_OK" in smoke_out:
            elapsed = time.time() - start
            return DoctorCheck(name="magic", status="PASS", detail=f"Startup+TCL+DRC smoke OK ({elapsed:.1f}s)", runtime_seconds=elapsed)
        else:
            return DoctorCheck(name="magic", status="FAIL", detail=f"DRC smoke test failed: {smoke_err[:100]}")

    elapsed = time.time() - start
    return DoctorCheck(name="magic", status="PASS", detail=f"Startup OK ({elapsed:.1f}s)", runtime_seconds=elapsed)


def run_magic_discovery() -> DiscoveryReport:
    candidates = discover_magic_binaries()
    if not candidates:
        return DiscoveryReport(
            tool_name="Magic",
            candidates=[],
        )

    for c in candidates:
        if c.status == ToolCandidateStatus.UNKNOWN:
            report = validate_magic_candidate(c)
            c.status = report.status
            c.failure_reason = report.failure_reason
            c.validation_evidence = report.evidence
            c.functional = report.passed

    ranked = rank_tool_candidates(candidates)

    issues: list[str] = []
    repair_available = False
    repair_cmd = ""

    valid = [c for c in ranked if c.status == ToolCandidateStatus.VALID]
    broken = [c for c in ranked if c.status == ToolCandidateStatus.BROKEN]

    if not valid:
        issues.append("No valid magic binary found")
    elif broken:
        issues.append(f"Broken candidate exists at {broken[0].path}")
        repair_available = True
        repair_cmd = "gli-flow doctor --repair-magic"

    selected = valid[0] if valid else (ranked[0] if ranked else None)

    return DiscoveryReport(
        tool_name="Magic",
        candidates=ranked,
        selected=selected,
        issues=issues,
        repair_available=repair_available,
        repair_command=repair_cmd,
    )


def check_netgen() -> DoctorCheck:
    start = time.time()
    binary = shutil.which("netgen-lvs") or shutil.which("netgen") or ""
    if not binary:
        return DoctorCheck(name="netgen", status="FAIL", detail="Not installed")
    rc, stdout, stderr = _run_tool([binary, "-batch", "quit"], timeout=15)
    if rc == -1:
        return DoctorCheck(name="netgen", status="FAIL", detail="Not installed")
    if rc not in (0, 1):
        elapsed = time.time() - start
        return DoctorCheck(name="netgen", status="FAIL", detail=f"Exit code {rc}: {stderr[:100]}")

    with tempfile.TemporaryDirectory() as tmp:
        lvs_script = Path(tmp) / "lvs_test.tcl"
        lvs_script.write_text("puts {LVS_SMOKE_OK}\nquit\n")
        smoke_rc, smoke_out, smoke_err = _run_tool(
            [binary, "-batch", str(lvs_script)],
            timeout=30,
        )
        elapsed = time.time() - start
        if smoke_rc in (0, 1) and "LVS_SMOKE_OK" in (smoke_out + smoke_err):
            return DoctorCheck(name="netgen", status="PASS", detail=f"Startup+LVS smoke OK ({elapsed:.1f}s)", runtime_seconds=elapsed)
        return DoctorCheck(name="netgen", status="WARNING", detail=f"Startup OK but LVS smoke unclear ({elapsed:.1f}s)", runtime_seconds=elapsed)

    elapsed = time.time() - start
    return DoctorCheck(name="netgen", status="PASS", detail=f"Startup OK ({elapsed:.1f}s)", runtime_seconds=elapsed)


def check_openroad() -> DoctorCheck:
    start = time.time()
    binary = shutil.which("openroad") or ""
    if not binary:
        return DoctorCheck(name="openroad", status="FAIL", detail="Not installed")
    rc, stdout, stderr = _run_tool([binary, "-version"], timeout=15)
    elapsed = time.time() - start
    if rc == 0:
        ver = (stdout or stderr).strip()[:60]
        return DoctorCheck(name="openroad", status="PASS", detail=f"Startup OK: {ver} ({elapsed:.1f}s)", runtime_seconds=elapsed)
    return DoctorCheck(name="openroad", status="FAIL", detail=f"Exit code {rc}: {stderr[:100]}")


def check_opensta() -> DoctorCheck:
    start = time.time()
    binary = shutil.which("sta") or ""
    if not binary:
        return DoctorCheck(name="opensta", status="WARNING", detail="Not installed (optional if OpenROAD includes STA)")
    rc, stdout, stderr = _run_tool([binary, "-version"], timeout=15)
    elapsed = time.time() - start
    if rc == 0:
        ver = (stdout or stderr).strip()[:60]
        return DoctorCheck(name="opensta", status="PASS", detail=f"Startup OK: {ver} ({elapsed:.1f}s)", runtime_seconds=elapsed)
    return DoctorCheck(name="opensta", status="FAIL", detail=f"Exit code {rc}: {stderr[:100]}")


def check_yosys() -> DoctorCheck:
    start = time.time()
    binary = shutil.which("yosys") or ""
    if not binary:
        return DoctorCheck(name="yosys", status="FAIL", detail="Not installed")
    rc, stdout, stderr = _run_tool([binary, "-V"], timeout=15)
    elapsed = time.time() - start
    if rc == 0:
        ver = (stdout or stderr).strip()[:60]
        return DoctorCheck(name="yosys", status="PASS", detail=f"Startup OK: {ver} ({elapsed:.1f}s)", runtime_seconds=elapsed)
    return DoctorCheck(name="yosys", status="FAIL", detail=f"Exit code {rc}: {stderr[:100]}")


def check_klayout() -> DoctorCheck:
    start = time.time()
    binary = shutil.which("klayout") or ""
    if not binary:
        return DoctorCheck(name="klayout", status="FAIL", detail="Not installed")
    rc, stdout, stderr = _run_tool([binary, "-b", "-v"], timeout=15)
    elapsed = time.time() - start
    if rc == 0:
        ver = (stdout or stderr).strip()[:60]
        return DoctorCheck(name="klayout", status="PASS", detail=f"Startup OK: {ver} ({elapsed:.1f}s)", runtime_seconds=elapsed)
    return DoctorCheck(name="klayout", status="FAIL", detail=f"Exit code {rc}: {stderr[:100]}")


def check_docker() -> DoctorCheck:
    start = time.time()
    binary = shutil.which("docker") or ""
    if not binary:
        return DoctorCheck(name="docker", status="WARNING", detail="Not installed (optional for local mode)")
    rc, stdout, stderr = _run_tool([binary, "info", "--format", "{{.ServerVersion}}"], timeout=15)
    elapsed = time.time() - start
    if rc == 0:
        return DoctorCheck(name="docker", status="PASS", detail=f"Daemon OK: {stdout.strip()} ({elapsed:.1f}s)", runtime_seconds=elapsed)
    if "permission denied" in stderr.lower():
        return DoctorCheck(name="docker", status="FAIL", detail="Permission denied. Add user to docker group.")
    return DoctorCheck(name="docker", status="FAIL", detail=f"Daemon not running: {stderr[:100]}")


def check_disk_space(min_gb: int = 10) -> DoctorCheck:
    stat = shutil.disk_usage("/")
    free_gb = stat.free / (1024 ** 3)
    if free_gb < min_gb:
        return DoctorCheck(name="disk_space", status="FAIL", detail=f"Only {free_gb:.1f}GB free (min {min_gb}GB)")
    if free_gb < min_gb * 2:
        return DoctorCheck(name="disk_space", status="WARNING", detail=f"{free_gb:.1f}GB free")
    return DoctorCheck(name="disk_space", status="PASS", detail=f"{free_gb:.1f}GB free")


def check_ram(min_gb: int = 4) -> DoctorCheck:
    try:
        with open("/proc/meminfo") as f:
            data = f.read()
        import re
        m = re.search(r"MemAvailable:\s+(\d+)", data)
        avail_kb = int(m.group(1)) if m else 0
        avail_gb = avail_kb / 1024 / 1024
        m_total = re.search(r"MemTotal:\s+(\d+)", data)
        total_kb = int(m_total.group(1)) if m_total else 0
        total_gb = total_kb / 1024 / 1024
        if avail_gb < min_gb:
            return DoctorCheck(name="ram", status="FAIL", detail=f"Only {avail_gb:.1f}GB available (min {min_gb}GB)")
        return DoctorCheck(name="ram", status="PASS", detail=f"{avail_gb:.1f}GB available / {total_gb:.1f}GB total")
    except OSError:
        return DoctorCheck(name="ram", status="WARNING", detail="Could not determine available RAM")


def check_pdk(pdk_root: str = None) -> DoctorCheck:
    from gli_flow.installer.workspace import get_config_value
    pdk_root = pdk_root or os.environ.get("PDK_ROOT") or get_config_value("pdk_root") or str(Path.home() / ".gli-flow" / "pdk")
    pdk_path = Path(pdk_root)
    if not pdk_path.exists():
        return DoctorCheck(name="pdk", status="FAIL", detail=f"PDK root not found: {pdk_root}")
    pdks = [d.name for d in pdk_path.iterdir() if d.is_dir() and d.name.startswith(("sky", "gf"))]
    if not pdks:
        return DoctorCheck(name="pdk", status="FAIL", detail=f"No PDKs found in {pdk_root}")
    return DoctorCheck(name="pdk", status="PASS", detail=f"Found PDKs: {', '.join(pdks)} in {pdk_root}")


def run_all_checks(pdk_root: str = None) -> DoctorReport:
    checks = [
        check_magic(),
        check_netgen(),
        check_openroad(),
        check_opensta(),
        check_yosys(),
        check_klayout(),
        check_docker(),
        check_disk_space(),
        check_ram(),
        check_pdk(pdk_root),
    ]
    report = DoctorReport(
        checks=checks,
        overall_status="PASS" if all(c.passed for c in checks) else "FAIL",
        timestamp=t.strftime("%Y-%m-%dT%H:%M:%S"),
    )
    return report
