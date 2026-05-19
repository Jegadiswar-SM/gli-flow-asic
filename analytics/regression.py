import sqlite3


def detect_regression():

    regressions = []

    try:

        connection = sqlite3.connect(
            "gli_flow.db"
        )

        cursor = connection.cursor()

        cursor.execute(
            """
            SELECT
                qor_score,
                wns
            FROM runs
            ORDER BY timestamp DESC
            LIMIT 2
            """
        )

        rows = cursor.fetchall()

        connection.close()

        if len(rows) < 2:

            return {
                "alerts": [],
                "regression_count": 0
            }

        latest = rows[0]
        previous = rows[1]

        latest_qor = latest[0]
        previous_qor = previous[0]

        latest_wns = latest[1]
        previous_wns = previous[1]

        if latest_qor < previous_qor:
            regressions.append(
                "QoR regression detected"
            )

        if latest_wns < previous_wns:
            regressions.append(
                "Timing regression detected"
            )

    except Exception:

        return {
            "alerts": [],
            "regression_count": 0
        }

    return {
        "alerts": regressions,
        "regression_count": len(regressions)
    }
