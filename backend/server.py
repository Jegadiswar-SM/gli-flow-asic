import sqlite3
from analytics.trend_analyzer import analyze_trends
from fastapi import FastAPI

from analytics.regression import detect_regression

from fastapi.middleware.cors import CORSMiddleware

from metrics.qor_api import (
    get_all_runs,
    get_latest_run,
    get_live_runs,
    get_wns_trend
)

app = FastAPI()

app.add_middleware(

    CORSMiddleware,

    allow_origins=["*"],

    allow_credentials=True,

    allow_methods=["*"],

    allow_headers=["*"],
)

@app.get("/runs")
def runs():

    return get_all_runs()


@app.get("/runs/latest")
def latest_run():

    return get_latest_run()


@app.get("/runs/live")
def live_runs():

    return get_live_runs()


@app.get("/metrics/wns")
def wns():

    return get_wns_trend()

@app.get("/regressions")
def regressions():

    return detect_regression()

@app.get("/runs/live")
def get_live_runs():

    connection = sqlite3.connect(
        "gli_flow.db"
    )

    cursor = connection.cursor()

    cursor.execute("""
    SELECT
        run_id,
        current_stage,
        status
    FROM runs
    WHERE status = 'RUNNING'
    """)

    rows = cursor.fetchall()

    connection.close()

    return [

        {
            "run_id": r[0],
            "current_stage": r[1],
            "status": r[2]
        }

        for r in rows
    ]
@app.get("/trends")
def trends():

    return analyze_trends()
@app.get("/live_runs")
def live_runs():

    import sqlite3

    connection = sqlite3.connect(
        "gli_flow.db"
    )

    cursor = connection.cursor()

    cursor.execute("""
        SELECT
            run_id,
            status,
            current_stage,
            qor_score,
            wns,
            runtime_sec
        FROM runs
        WHERE status='RUNNING'
        ORDER BY timestamp DESC
    """)

    rows = cursor.fetchall()

    connection.close()

    results = []

    for row in rows:

        results.append({
            "run_id": row[0],
            "status": row[1],
            "current_stage": row[2],
            "qor_score": row[3],
            "wns": row[4],
            "runtime_sec": row[5]
        })

    return results
