WNS_PENALTY_FACTOR = 0.4
TNS_PENALTY_FACTOR = 0.01
UTILIZATION_THRESHOLD = 70.0
UTILIZATION_PENALTY_FACTOR = 0.01
RUNTIME_THRESHOLD_SEC = 15.0
RUNTIME_PENALTY_FACTOR = 0.01


def _clamp(value, lo, hi):
    if value is None:
        return lo
    return max(lo, min(hi, value))


def calculate_qor_score(wns=None, tns=None, utilization=None, runtime=None, cell_count=None):
    score = 1.0

    timing_score = 1.0
    if wns is not None and wns < 0:
        penalty = abs(wns) * WNS_PENALTY_FACTOR
        timing_score = _clamp(1.0 - penalty, 0.0, 1.0)
        score -= penalty

    tns_penalty = 0.0
    if tns is not None and tns < 0:
        tns_penalty = abs(tns) * TNS_PENALTY_FACTOR
        timing_score = _clamp(timing_score - tns_penalty, 0.0, 1.0)
        score -= tns_penalty

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
    }
