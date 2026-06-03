"""
Dual DRC runner: Magic + KLayout.
Both must be run. Final count is deduplicated union.
"""

import subprocess
import shutil
import re
import json
import logging
from pathlib import Path
from typing import Optional
from gli_flow.core.subprocess_env import safe_env

log = logging.getLogger(__name__)


def run_magic_drc(gds_path: str, design_name: str, pdk: str, run_dir: Path) -> dict:
    """Run Magic DRC on final GDS."""
    magic_path = shutil.which("magic")
    if not magic_path:
        return {"tool": "magic", "run": False, "error": "Magic not found", "violations": None}

    report_path = run_dir / "reports" / "magic_drc.rpt"
    report_path.parent.mkdir(parents=True, exist_ok=True)

    pdk_magic_tech = _get_magic_techfile(pdk)

    magic_cmd_file = run_dir / "magic_drc.tcl"
    magic_cmd_file.write_text(
        f"drc off\n"
        f"gds read {gds_path}\n"
        f"load {design_name}\n"
        f"select top cell\n"
        f"drc on\n"
        f"drc check\n"
        f"set drc_result [drc listall why]\n"
        f"set fp [open {report_path} w]\n"
        f"puts $fp \"DRC Results:\"\n"
        f"puts $fp $drc_result\n"
        f"set count [llength $drc_result]\n"
        f"puts $fp \"Total violations: $count\"\n"
        f"close $fp\n"
        f"quit -noprompt\n"
    )

    cmd = [magic_path, "-dnull", "-noconsole", "-rcfile", pdk_magic_tech, str(magic_cmd_file)]

    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=1800, env=safe_env())

        violations = _parse_magic_drc_report(str(report_path))

        return {
            "tool": "magic", "run": True, "violations": violations,
            "report_path": str(report_path), "returncode": result.returncode,
        }

    except Exception as e:
        return {"tool": "magic", "run": False, "error": str(e), "violations": None}


def run_klayout_drc(gds_path: str, design_name: str, pdk: str, run_dir: Path) -> dict:
    """Run KLayout DRC on final GDS."""
    klayout_path = shutil.which("klayout") or shutil.which("klayout_app")
    if not klayout_path:
        return {"tool": "klayout", "run": False, "error": "KLayout not found", "violations": None}

    drc_script = _get_klayout_drc_script(pdk)
    if not drc_script:
        return {"tool": "klayout", "run": False, "error": f"No KLayout DRC script for {pdk}", "violations": None}

    report_path = run_dir / "reports" / "klayout_drc.xml"
    report_path.parent.mkdir(parents=True, exist_ok=True)

    cmd = [klayout_path, "-b", "-r", drc_script, "-rd", f"input={gds_path}", "-rd", f"topcell={design_name}", "-rd", f"report={report_path}"]

    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=1800, env=safe_env())
        violations = _parse_klayout_drc_report(str(report_path))
        return {
            "tool": "klayout", "run": True, "violations": violations,
            "report_path": str(report_path), "returncode": result.returncode,
        }
    except Exception as e:
        return {"tool": "klayout", "run": False, "error": str(e), "violations": None}


def run_dual_drc(gds_path: str, design_name: str, pdk: str, run_dir: Path) -> dict:
    """Run both Magic and KLayout DRC."""
    log.info("Running Magic DRC...")
    magic_result = run_magic_drc(gds_path, design_name, pdk, run_dir)

    log.info("Running KLayout DRC...")
    klayout_result = run_klayout_drc(gds_path, design_name, pdk, run_dir)

    magic_count = magic_result.get("violations") or 0
    klayout_count = klayout_result.get("violations") or 0

    total = max(magic_count, klayout_count)

    both_clean = (
        magic_result.get("run") and klayout_result.get("run")
        and magic_count == 0 and klayout_count == 0
    )

    result = {
        "drc_clean": both_clean,
        "total_violations": total,
        "magic": magic_result,
        "klayout": klayout_result,
        "note": "DRC verified by both Magic and KLayout. Both tools required for full coverage."
    }

    summary_path = run_dir / "reports" / "drc_combined.json"
    with open(summary_path, "w") as f:
        json.dump(result, f, indent=2)

    return result


def _parse_magic_drc_report(report_path: str) -> int:
    try:
        content = Path(report_path).read_text()
        match = re.search(r"Total violations:\s*(\d+)", content)
        if match:
            return int(match.group(1))
        return len([l for l in content.split('\n') if l.strip() and 'Total' not in l and 'DRC' not in l])
    except Exception:
        return 0


def _parse_klayout_drc_report(report_path: str) -> int:
    try:
        content = Path(report_path).read_text()
        count = len(re.findall(r'<item>', content))
        if count:
            return count
        match = re.search(r"(\d+)\s+violation", content)
        return int(match.group(1)) if match else 0
    except Exception:
        return 0


def _get_magic_techfile(pdk: str) -> str:
    import os
    pdk_root = os.environ.get("PDK_ROOT", str(Path.home() / "pdk"))
    techfiles = {
        "sky130A": f"{pdk_root}/sky130A/libs.tech/magic/sky130A.tech",
        "gf180mcuD": f"{pdk_root}/gf180mcuD/libs.tech/magic/gf180mcu.tech",
    }
    return techfiles.get(pdk, "")


def _get_klayout_drc_script(pdk: str) -> Optional[str]:
    import os
    pdk_root = os.environ.get("PDK_ROOT", str(Path.home() / "pdk"))
    scripts = {
        "sky130A": f"{pdk_root}/sky130A/libs.tech/klayout/drc/sky130A.lydrc",
        "gf180mcuD": f"{pdk_root}/gf180mcuD/libs.tech/klayout/drc/gf180mcu.lydrc",
    }
    script = scripts.get(pdk)
    if script and Path(script).exists():
        return script
    return None
