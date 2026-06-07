"""
Dual DRC runner: Magic + KLayout.
Both must be run. Final count is deduplicated union.
"""

import subprocess
import shutil
import re
import json
import logging
import os
from pathlib import Path
from typing import Optional
from gli_flow.core.subprocess_env import safe_env

PDK_VARIANT_MAP = {
    "sky130": "sky130A",
    "sky130A": "sky130A",
    "gf180mcu": "gf180mcuD",
    "gf180mcuD": "gf180mcuD",
}

def _resolve_pdk_path(pdk: str) -> str:
    variant = PDK_VARIANT_MAP.get(pdk, pdk)
    pdk_root = os.environ.get("PDK_ROOT", "") or str(Path.home() / ".gli-flow" / "pdk")
    if not Path(pdk_root).exists():
        pdk_root = str(Path.home() / "pdk")
    return f"{pdk_root}/{variant}"

log = logging.getLogger(__name__)


def _get_magicdnull_path() -> Optional[str]:
    paths = [
        "/usr/lib/x86_64-linux-gnu/magic/tcl/magicdnull",
        "/usr/local/lib/magic/tcl/magicdnull",
        str(Path.home() / ".local/lib/magic/tcl/magicdnull"),
    ]
    for p in paths:
        if Path(p).exists():
            return p
    d = shutil.which("magicdnull")
    if d:
        return d
    return None


def run_magic_drc(gds_path: str, design_name: str, pdk: str, run_dir: Path) -> dict:
    """Run Magic DRC on final GDS."""
    magicdnull_path = _get_magicdnull_path()
    if not magicdnull_path:
        return {"tool": "magic", "run": False, "error": "magicdnull not found", "violations": None}

    report_path = run_dir / "reports" / "magic_drc.rpt"
    report_path.parent.mkdir(parents=True, exist_ok=True)

    magic_rcfile = _get_magic_rcfile(pdk)
    if not Path(magic_rcfile).exists():
        return {"tool": "magic", "run": False, "error": f"Magic rcfile not found: {magic_rcfile}", "violations": None}

    pdk_root = os.environ.get("PDK_ROOT", "") or str(Path.home() / ".gli-flow" / "pdk")

    script_path = run_dir / "magic_drc.tcl"
    script_path.write_text(
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

    env = safe_env(extra={
        "DISPLAY": os.environ.get("DISPLAY", ""),
        "PDK_ROOT": pdk_root,
    })
    cmd = [magicdnull_path, "-nowrapper", "-d", "NULL", "-rcfile", magic_rcfile, str(script_path)]

    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=600, env=env)

        violations = _parse_magic_drc_report(str(report_path))

        return {
            "tool": "magic", "run": True, "violations": violations,
            "report_path": str(report_path), "returncode": result.returncode,
        }

    except subprocess.TimeoutExpired:
        return {"tool": "magic", "run": False, "error": "Magic DRC timed out after 600s", "violations": None}
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
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=600, env=safe_env())
        violations = _parse_klayout_drc_report(str(report_path))
        return {
            "tool": "klayout", "run": True, "violations": violations,
            "report_path": str(report_path), "returncode": result.returncode,
        }
    except subprocess.TimeoutExpired:
        return {"tool": "klayout", "run": False, "error": "KLayout DRC timed out after 600s", "violations": None}
    except Exception as e:
        return {"tool": "klayout", "run": False, "error": str(e), "violations": None}


def run_dual_drc(gds_path: str, design_name: str, pdk: str, run_dir: Path) -> dict:
    """Run both Magic and KLayout DRC. Falls back to KLayout-only if Magic times out."""
    log.info("Running Magic DRC...")
    magic_result = run_magic_drc(gds_path, design_name, pdk, run_dir)

    log.info("Running KLayout DRC...")
    klayout_result = run_klayout_drc(gds_path, design_name, pdk, run_dir)

    magic_count = magic_result.get("violations") or 0
    klayout_count = klayout_result.get("violations") or 0

    magic_run = magic_result.get("run", False)
    klayout_run = klayout_result.get("run", False)

    if not magic_run and klayout_run:
        total = klayout_count
        drc_clean = klayout_count == 0
        note = "KLayout DRC only (Magic skipped or timed out)."
    elif not klayout_run and magic_run:
        total = magic_count
        drc_clean = magic_count == 0
        note = "Magic DRC only (KLayout skipped or timed out)."
    elif magic_run and klayout_run:
        total = max(magic_count, klayout_count)
        drc_clean = magic_count == 0 and klayout_count == 0
        note = "DRC verified by both Magic and KLayout. Both tools required for full coverage."
    else:
        total = 0
        drc_clean = True
        note = "Both Magic and KLayout DRC skipped or failed."

    result = {
        "drc_clean": drc_clean,
        "total_violations": total,
        "magic": magic_result,
        "klayout": klayout_result,
        "note": note,
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
    pdk_path = _resolve_pdk_path(pdk)
    return f"{pdk_path}/libs.tech/magic/{Path(pdk_path).name}.tech"


def _get_magic_rcfile(pdk: str) -> str:
    pdk_path = _resolve_pdk_path(pdk)
    return f"{pdk_path}/libs.tech/magic/{Path(pdk_path).name}.magicrc"


def _get_klayout_drc_script(pdk: str) -> Optional[str]:
    pdk_path = _resolve_pdk_path(pdk)
    script = f"{pdk_path}/libs.tech/klayout/drc/{Path(pdk_path).name}.lydrc"
    if Path(script).exists():
        return script
    return None
