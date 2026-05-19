def calculate_qor_score(
    wns,
    tns,
    utilization,
    runtime,
):

    score = 1.0

    # -----------------------------------------
    # WNS PENALTY
    # -----------------------------------------

    if wns < 0:
        score -= abs(wns) * 0.4

    # -----------------------------------------
    # TNS PENALTY
    # -----------------------------------------

    if tns < 0:
        score -= abs(tns) * 0.01

    # -----------------------------------------
    # UTILIZATION PENALTY
    # -----------------------------------------

    if utilization > 70:
        score -= (utilization - 70) * 0.01

    # -----------------------------------------
    # RUNTIME PENALTY
    # -----------------------------------------

    if runtime > 15:
        score -= (runtime - 15) * 0.01

    # -----------------------------------------
    # CLAMP
    # -----------------------------------------

    if score < 0:
        score = 0

    if score > 1:
        score = 1

    return round(score, 2)
