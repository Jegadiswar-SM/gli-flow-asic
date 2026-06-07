TARGET_CLOCK_PERIOD_NS = 10.0
MAX_UTILIZATION_PCT = 100.0
UTIL_OVERHEAD = 0.30
REF_CELL_COUNT = 25000.0
RUNTIME_THRESHOLD_SEC = 15.0
RUNTIME_PENALTY_FACTOR = 0.01
TIMING_WEIGHT = 0.50
AREA_WEIGHT = 0.30
DENSITY_WEIGHT = 0.20


def _clamp(value, lo, hi):
    if value is None:
        return lo
    return max(lo, min(hi, value))


def _timing_score(wns_ns, tns_ns) -> float:
    if wns_ns is None or tns_ns is None:
        return 0.0
    tns_ratio = max(0, -tns_ns) / TARGET_CLOCK_PERIOD_NS
    return 1.0 / (1.0 + tns_ratio)


def _area_score(utilization) -> float:
    if utilization is None:
        return 0.0
    util_ratio = utilization / MAX_UTILIZATION_PCT
    return _clamp(1.0 - util_ratio ** 2, 0.0, 1.0)


def _density_score(cell_count) -> float:
    if cell_count is None:
        return 0.0
    density_ratio = cell_count / REF_CELL_COUNT
    effective = max(0.0, density_ratio - UTIL_OVERHEAD)
    return _clamp(1.0 - effective ** 2, 0.0, 1.0)


def calculate_qor_score(wns=None, tns=None, utilization=None, runtime=None, cell_count=None, hold_wns=None):
    timing_score = _timing_score(wns, tns)
    area_score = _area_score(utilization)
    density_score = _density_score(cell_count)

    score = (
        TIMING_WEIGHT * timing_score +
        AREA_WEIGHT * area_score +
        DENSITY_WEIGHT * density_score
    )

    if runtime is not None and runtime > RUNTIME_THRESHOLD_SEC:
        score -= (runtime - RUNTIME_THRESHOLD_SEC) * RUNTIME_PENALTY_FACTOR

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
            "timing": TIMING_WEIGHT,
            "area": AREA_WEIGHT,
            "density": DENSITY_WEIGHT,
        },
        "hold_violation_tapeout_blocking": hold_violation_tapeout_blocking,
        "hold_violation_detail": hold_violation_detail,
    }
