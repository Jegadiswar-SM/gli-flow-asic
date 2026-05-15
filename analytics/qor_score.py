def compute_qor_score(
    wns,
    tns,
    utilization,
    runtime_sec
):

    score = 100

    # WNS penalty
    if wns < 0:
        score -= abs(wns) * 120

    # TNS penalty
    if tns < 0:
        score -= abs(tns) * 2

    # Utilization penalty
    if utilization > 70:
        score -= (
            utilization - 70
        ) * 1.5

    # Runtime penalty
    if runtime_sec > 300:
        score -= (
            runtime_sec - 300
        ) * 0.05

    if score < 0:
        score = 0

    return round(score / 100, 2)
