def calculate_qor_score(
    wns,
    tns
):

    score = 1.0

    score += (wns * 2)

    score += (tns / 100)

    if score < 0:
        score = 0

    if score > 1:
        score = 1

    return round(score, 2)
