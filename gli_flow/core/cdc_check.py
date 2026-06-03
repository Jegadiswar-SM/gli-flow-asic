"""
CDC (Clock Domain Crossing) detection.
GLI-FLOW v1.0 does NOT perform CDC analysis.
This module detects multi-clock designs and displays mandatory disclaimers.
"""

import re
from pathlib import Path
from typing import List


def count_clock_domains(rtl_files: List[str], sdc_file: str = None) -> dict:
    """Count clock domains in design."""
    clocks = set()

    if sdc_file and Path(sdc_file).exists():
        try:
            sdc_content = Path(sdc_file).read_text()
            clock_matches = re.findall(
                r"create_clock[^\n]+\[get_ports\s+([^\]]+)\]", sdc_content
            )
            clocks.update(clock_matches)

            gen_clocks = re.findall(
                r"create_generated_clock[^\n]+-name\s+(\S+)", sdc_content
            )
            clocks.update(gen_clocks)
        except Exception:
            pass

    for rtl_file in rtl_files:
        try:
            content = Path(rtl_file).read_text(errors='ignore')
            edges = re.findall(r"(?:posedge|negedge)\s+(\w+)", content)
            for sig in edges:
                if any(kw in sig.lower() for kw in ['clk', 'clock', 'clk_', '_clk', 'ck', 'osc']):
                    clocks.add(sig)
        except Exception:
            pass

    return {
        "clock_count": len(clocks),
        "clock_names": list(clocks),
        "multi_clock": len(clocks) > 1,
    }


CDC_DISCLAIMER = """
┌─────────────────────────────────────────────────────┐
│ ⚠  CDC ANALYSIS NOT PERFORMED                      │
│                                                     │
│ {n} clock domain(s) detected in this design.        │
│                                                     │
│ GLI-FLOW v1.0 does NOT perform clock domain         │
│ crossing (CDC) analysis. CDC violations are a       │
│ leading cause of functional failures in silicon.    │
│                                                     │
│ REQUIRED before tapeout:                            │
│   Use a dedicated CDC tool (Synopsys SpyGlass,      │
│   Mentor Questa CDC, or open-source sv-cdc)         │
│   to verify all clock domain crossings.             │
│                                                     │
│ LVS CLEAN and DRC CLEAN do NOT indicate CDC safety. │
└─────────────────────────────────────────────────────┘
"""
