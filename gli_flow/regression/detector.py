QOR_DROP_THRESHOLD = 0.05
WNS_DEGRADE_THRESHOLD = 0.1
UTILIZATION_INCREASE_THRESHOLD = 5.0


def detect_regression(current_metrics, baseline_metrics=None):
    alerts = []

    if baseline_metrics is None:
        return {"regression_detected": False, "alerts": [], "baseline": None}

    current_qor = current_metrics.get("qor_score", 0)
    baseline_qor = baseline_metrics.get("qor_score", 0)

    if baseline_qor > 0:
        drop = baseline_qor - current_qor
        if drop > QOR_DROP_THRESHOLD:
            pct = (drop / baseline_qor) * 100
            alerts.append(
                f"QoR regression: {baseline_qor:.2f} -> {current_qor:.2f} "
                f"({pct:.1f}% drop)"
            )

    current_wns = current_metrics.get("wns")
    baseline_wns = baseline_metrics.get("wns")
    if current_wns is not None and baseline_wns is not None:
        wns_degradation = current_wns - baseline_wns
        if wns_degradation < -WNS_DEGRADE_THRESHOLD:
            alerts.append(
                f"WNS degraded: {baseline_wns:.3f} -> {current_wns:.3f} "
                f"(worsened by {abs(wns_degradation):.3f})"
            )

    current_util = current_metrics.get("utilization")
    baseline_util = baseline_metrics.get("utilization")
    if current_util is not None and baseline_util is not None:
        util_increase = current_util - baseline_util
        if util_increase > UTILIZATION_INCREASE_THRESHOLD:
            alerts.append(
                f"Utilization increased: {baseline_util:.1f}% -> {current_util:.1f}% "
                f"(+{util_increase:.1f}%)"
            )

    return {
        "regression_detected": len(alerts) > 0,
        "alerts": alerts,
        "baseline_qor": baseline_qor,
        "current_qor": current_qor,
    }
