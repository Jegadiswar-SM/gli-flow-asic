from typing import List, Optional, Dict, Any
from failure_atlas.schema import FailureAtlasEntry
from failure_atlas.taxonomy import FailureDomain, FailureCategory, FailureSeverity

def detect_failures(
    run_id: str,
    metrics: Dict[str, Any],
    stage: str = "UNKNOWN",
    design_name: str = "",
    pdk_name: str = "",
) -> List[FailureAtlasEntry]:
    """
    Rule-based failure detection. Returns list of FailureAtlasEntry.
    Returns empty list if no failures detected.
    metrics dict uses the same keys as telemetry/parser.py output.
    """
    entries = []

    def make_entry(domain, category, signature, severity, evidence=None, origin=None):
        return FailureAtlasEntry(
            run_id=run_id,
            detection_stage=stage,
            origin_stage=origin,
            level1_domain=domain,
            level2_category=category,
            level3_signature=signature,
            severity=severity,
            pdk_name=pdk_name,
            design_name=design_name,
            pre_failure_metrics={k: metrics.get(k) for k in [
                "setup_wns_ns", "setup_tns_ns", "hold_whs_ns", "hold_ths_ns",
                "utilization", "cell_count",
                "drc_total_violations", "drc_is_clean",
            ] if metrics.get(k) is not None},
            evidence=evidence or {},
        )

    wns = metrics.get("setup_wns_ns")
    if wns is not None and wns < 0:
        entries.append(make_entry(
            FailureDomain.TIMING, FailureCategory.SETUP_VIOLATION,
            f"Setup timing violated: WNS={wns:.3f}ns at stage {stage}",
            FailureSeverity.TAPEOUT_BLOCKING if wns < -0.5 else FailureSeverity.PERFORMANCE_DEGRADATION,
            evidence={"setup_wns_ns": wns, "setup_tns_ns": metrics.get("setup_tns_ns")},
        ))

    hold_wns = metrics.get("hold_whs_ns")
    if hold_wns is not None and hold_wns < 0:
        entries.append(make_entry(
            FailureDomain.TIMING, FailureCategory.HOLD_VIOLATION,
            f"Hold timing violated: WHS={hold_wns:.3f}ns",
            FailureSeverity.TAPEOUT_BLOCKING,
            evidence={"hold_whs_ns": hold_wns},
        ))

    overflow_h = metrics.get("overflow_h", 0) or 0
    overflow_v = metrics.get("overflow_v", 0) or 0
    if overflow_h > 0.05 or overflow_v > 0.05:
        entries.append(make_entry(
            FailureDomain.CONGESTION, FailureCategory.GLOBAL_OVERFLOW,
            f"Global routing overflow: H={overflow_h:.3f} V={overflow_v:.3f}",
            FailureSeverity.TAPEOUT_BLOCKING if max(overflow_h, overflow_v) > 0.1 else FailureSeverity.FUNCTIONAL_RISK,
            evidence={"overflow_h": overflow_h, "overflow_v": overflow_v},
        ))

    drc_total = metrics.get("drc_total_violations", 0) or 0
    drc_is_clean = metrics.get("drc_is_clean", True)
    lvs_result = metrics.get("lvs_result", "")
    if drc_total > 0 or not drc_is_clean:
        drc_by_cat = metrics.get("drc_by_category", {}) or {}
        cat_map = {
            "SHORT": FailureCategory.DRC_SPACING,
            "SPACING": FailureCategory.DRC_SPACING,
            "WIDTH": FailureCategory.DRC_WIDTH,
            "ENCLOSURE": FailureCategory.DRC_ENCLOSURE,
            "ANTENNA": FailureCategory.DRC_ANTENNA,
            "DENSITY": FailureCategory.DRC_DENSITY,
        }
        categories = []
        for rule_name in drc_by_cat:
            mapped = cat_map.get(rule_name.upper(), FailureCategory.DRC_SPACING)
            if mapped not in categories:
                categories.append(mapped)
        primary_cat = categories[0] if categories else FailureCategory.DRC_SPACING
        entries.append(make_entry(
            FailureDomain.DRC, primary_cat,
            f"DRC failed: {drc_total} violations, categories: {categories}",
            FailureSeverity.TAPEOUT_BLOCKING,
            evidence={"drc_total": drc_total, "by_category": drc_by_cat, "level2_categories": categories},
            origin="ROUTING",
        ))

    lvs_result = metrics.get("lvs_result")
    if lvs_result and lvs_result.upper() == "FAIL":
        unmatched_nets = metrics.get("lvs_unmatched_nets", 0) or 0
        short_count = metrics.get("lvs_short_count", 0) or 0
        if short_count > 0:
            cat = FailureCategory.LVS_SHORT
        elif unmatched_nets > 0:
            cat = FailureCategory.LVS_OPEN_NET
        else:
            cat = FailureCategory.LVS_DEVICE_MISMATCH
        entries.append(make_entry(
            FailureDomain.LVS, cat,
            f"LVS failed: unmatched_nets={unmatched_nets}, shorts={short_count}",
            FailureSeverity.TAPEOUT_BLOCKING,
            evidence={"lvs_unmatched_nets": unmatched_nets, "lvs_short_count": short_count},
        ))

    has_sram = metrics.get("has_sram_macros", False)
    if has_sram and drc_total > 0 and metrics.get("drc_by_category", {}).get("SPACING", 0) > 0:
        entries.append(make_entry(
            FailureDomain.MACRO_INTEGRATION, FailureCategory.SRAM_PIN_BLOCKED,
            "SRAM macro spacing violation - possible pin access or halo issue",
            FailureSeverity.TAPEOUT_BLOCKING,
        ))

    return entries
