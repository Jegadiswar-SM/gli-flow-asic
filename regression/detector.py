def detect_regression(current_qor):

    regression_count = 0
    alerts = []

    if current_qor < 0.75:
        regression_count += 1
        alerts.append("QoR regression detected")

    return {
        "regression_count": regression_count,
        "alerts": alerts
    }
