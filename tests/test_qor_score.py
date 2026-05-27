from gli_flow.analytics.qor_score import calculate_qor_score


def test_qor_perfect():
    result = calculate_qor_score(wns=0.0, tns=0.0, utilization=50, runtime=5, cell_count=1000)
    assert result["score"] == 1.0
    assert result["breakdown"]["timing"] == 1.0
    assert result["breakdown"]["area"] == 1.0


def test_qor_wns_penalty():
    result = calculate_qor_score(wns=-0.5, tns=0.0, utilization=50, runtime=5)
    assert 0.0 < result["score"] < 1.0
    assert result["breakdown"]["timing"] < 1.0


def test_qor_max_penalty():
    result = calculate_qor_score(wns=-5.0, tns=-100, utilization=95, runtime=9999, cell_count=100000)
    assert result["score"] == 0.0


def test_qor_all_none():
    result = calculate_qor_score()
    assert result["score"] == 1.0
    assert result["breakdown"]["timing"] == 1.0


def test_qor_density_penalty():
    result = calculate_qor_score(cell_count=50000)
    assert result["breakdown"]["density"] < 1.0
