from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware

import sqlite3

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

DB_PATH = "gli_flow.db"


def get_connection():
    return sqlite3.connect(DB_PATH)


@app.get("/runs")
def get_runs():

    connection = get_connection()

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
        LIMIT 20
        """
    )

    rows = cursor.fetchall()

    connection.close()

    runs = []

    for row in rows:

        runs.append({
            "run_id": row[0],
            "design_name": row[1],
            "status": row[2],
            "current_stage": row[3],
            "progress": row[4],
            "wns": row[5] if row[5] else 0,
            "tns": row[6] if row[6] else 0,
            "utilization": row[7] if row[7] else 0,
            "runtime_sec": row[8] if row[8] else 0,
            "cell_count": row[9] if row[9] else 0,
            "qor_score": row[10] if row[10] else 0,
            "timestamp": row[11]
        })

    return runs


@app.get("/live_runs")
def get_live_runs():

    connection = get_connection()

    cursor = connection.cursor()

    cursor.execute(
        """
        SELECT
            run_id,
            status,
            current_stage,
            progress
        FROM runs
        WHERE status='RUNNING'
        ORDER BY timestamp DESC
        """
    )

    rows = cursor.fetchall()

    connection.close()

    live_runs = []

    for row in rows:

        live_runs.append({
            "run_id": row[0],
            "status": row[1],
            "current_stage": row[2],
            "progress": row[3]
        })

    return live_runs


@app.get("/trends")
def get_trends():

    connection = get_connection()

    cursor = connection.cursor()

    cursor.execute(
        """
        SELECT
            qor_score,
            runtime_sec
        FROM runs
        WHERE qor_score IS NOT NULL
        ORDER BY timestamp DESC
        LIMIT 20
        """
    )

    rows = cursor.fetchall()

    connection.close()

    if len(rows) == 0:

        return {
            "trend": "NO_DATA",
            "avg_qor": 0,
            "avg_runtime": 0,
            "regressions": 0
        }

    avg_qor = round(
        sum(row[0] for row in rows if row[0]) / len(rows),
        2
    )

    avg_runtime = round(
        sum(row[1] for row in rows if row[1]) / len(rows),
        2
    )

    regressions = len(
        [row for row in rows if row[0] and row[0] < 0.7]
    )

    trend = "IMPROVING"

    return {
        "trend": trend,
        "avg_qor": avg_qor,
        "avg_runtime": avg_runtime,
        "regressions": regressions
    }
