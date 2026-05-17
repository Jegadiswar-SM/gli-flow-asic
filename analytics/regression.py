import sqlite3


def detect_regression():

    connection = sqlite3.connect(
        "gli_flow.db"
    )

    cursor = connection.cursor()

    cursor.execute(
        """
        SELECT
            run_id,
            wns,
            utilization,
            runtime_sec,
            qor_score
        FROM runs
        ORDER BY timestamp DESC
        LIMIT 2
        """
    )

    rows = cursor.fetchall()

    connection.close()

    if len(rows) < 2:

        return {
            "status": "NOT_ENOUGH_DATA",
            "regressions": [],
            "regression_count": 0
        }

    latest = rows[0]
    previous = rows[1]

    regressions = []

    latest_wns = latest[1]
    previous_wns = previous[1]

    latest_util = latest[2]
    previous_util = previous[2]

    latest_runtime = latest[3]
    previous_runtime = previous[3]

    latest_qor = latest[4]
    previous_qor = previous[4]

    if latest_wns < previous_wns:

        regressions.append(
            "WNS regression detected"
        )

    if latest_util > previous_util + 5:

        regressions.append(
            "Utilization regression detected"
        )

    if latest_runtime > previous_runtime + 5:

        regressions.append(
            "Runtime regression detected"
        )

    if latest_qor < previous_qor:

        regressions.append(
            "QoR regression detected"
        )

    return {
        "status": "ANALYZED",
        "latest_run": latest[0],
        "previous_run": previous[0],
        "regressions": regressions,
        "regression_count": len(regressions)
    }
