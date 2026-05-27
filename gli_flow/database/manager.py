import sqlite3


def get_runs(db_path, limit=20):
    connection = sqlite3.connect(db_path)

    try:
        cursor = connection.cursor()
        cursor.execute(
            """
            SELECT
                run_id,
                design_name,
                status,
                current_stage,
                progress,
                wns,
                tns,
                utilization,
                runtime_sec,
                cell_count,
                qor_score,
                timestamp
            FROM runs
            ORDER BY timestamp DESC
            LIMIT ?
            """,
            (limit,)
        )

        rows = cursor.fetchall()
    finally:
        connection.close()

    results = []

    for row in rows:
        results.append({
            "run_id": row[0],
            "design_name": row[1],
            "status": row[2],
            "current_stage": row[3],
            "progress": row[4],
            "wns": row[5],
            "tns": row[6],
            "utilization": row[7],
            "runtime_sec": row[8],
            "cell_count": row[9],
            "qor_score": row[10],
            "timestamp": row[11]
        })

    return results
