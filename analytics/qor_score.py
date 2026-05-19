def calculate_qor_score(
    wns,
    tns,
    utilization,
    runtime
):

    score = 100

    if wns < 0:
        score -= abs(wns) * 120

    if tns < 0:
        score -= abs(tns) * 0.7

    if utilization > 75:
        score -= (utilization - 75) * 1.5

    if runtime > 20:
        score -= (runtime - 20) * 0.5

    if score < 0:
        score = 0

    if score > 100:
        score = 100

    return round(score / 100, 2)
