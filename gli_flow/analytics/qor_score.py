WNS_PENALTY_FACTOR = 0.4
TNS_PENALTY_FACTOR = 0.01
UTILIZATION_THRESHOLD = 70.0
UTILIZATION_PENALTY_FACTOR = 0.01
RUNTIME_THRESHOLD_SEC = 15.0
RUNTIME_PENALTY_FACTOR = 0.01
TARGET_CLOCK_PERIOD_NS = 10.0


def _clamp(value, lo, hi):
    if value is None:
        return lo
    return max(lo, min(hi, value))


def _timing_score(wns_ns, tns_ns) -> float:
    if wns_ns is None or tns_ns is None:
        return 0.0
    if wns_ns < 0:
        return wns_ns / TARGET_CLOCK_PERIOD_NS
    return min(1.0, 0.5 + (wns_ns / TARGET_CLOCK_PERIOD_NS) * 0.5)


def calculate_qor_score(wns=None, tns=None, utilization=None, runtime=None, cell_count=None, hold_wns=None):
    score = 1.0

    timing_score = _timing_score(wns, tns)
    score -= (1.0 - timing_score) * 0.51

    area_score = 1.0
    if utilization is not None and utilization > UTILIZATION_THRESHOLD:
        area_penalty = (utilization - UTILIZATION_THRESHOLD) * UTILIZATION_PENALTY_FACTOR
        area_score = _clamp(1.0 - area_penalty, 0.0, 1.0)
        score -= area_penalty

    density_score = 1.0
    if cell_count is not None:
        density_ratio = cell_count / 25000.0
        if density_ratio > 1.0:
            density_penalty = (density_ratio - 1.0) * 0.5
            density_score = _clamp(1.0 - density_penalty, 0.0, 1.0)
            score -= density_score

    runtime_penalty = 0.0
    if runtime is not None and runtime > RUNTIME_THRESHOLD_SEC:
        runtime_penalty = (runtime - RUNTIME_THRESHOLD_SEC) * RUNTIME_PENALTY_FACTOR
        score -= runtime_penalty

    hold_violation_tapeout_blocking = False
    hold_violation_detail = None
    if hold_wns is not None and hold_wns < 0:
        score = 0.0
        hold_violation_tapeout_blocking = True
        hold_violation_detail = (
            f"Hold WNS: {hold_wns:.3f}ns — "
            f"TAPEOUT BLOCKING. Hold violations cause "
            f"flip-flops to capture wrong data. "
            f"Fix: increase hold margin with "
            f"set_fix_hold in SDC."
        )

    score = _clamp(score, 0.0, 1.0)

    return {
        "score": round(score, 2),
        "breakdown": {
            "timing": round(timing_score, 2),
            "area": round(area_score, 2),
            "density": round(density_score, 2),
        },
        "weights": {
            "timing": 0.50,
            "area": 0.30,
            "density": 0.20,
        },
        "hold_violation_tapeout_blocking": hold_violation_tapeout_blocking,
        "hold_violation_detail": hold_violation_detail,
    }
