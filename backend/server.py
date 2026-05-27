from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware

import os
import sys
import sqlite3
from pathlib import Path

app = FastAPI()

allowed_origins = os.environ.get(
    "CORS_ORIGINS",
    "http://localhost:5173,http://127.0.0.1:5173"
).split(",")

app.add_middleware(
    CORSMiddleware,
    allow_origins=allowed_origins,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

_default_db = str(Path(__file__).resolve().parent.parent / "gli_flow.db")
DB_PATH = os.environ.get("GLI_FLOW_DB_PATH", _default_db)

SCHEMA_SQL = """
CREATE TABLE IF NOT EXISTS runs (
    run_id TEXT PRIMARY KEY,
    design_name TEXT NOT NULL,
    status TEXT DEFAULT 'PENDING',
    current_stage TEXT DEFAULT 'INITIALIZING',
    progress INTEGER DEFAULT 0,
    wns REAL DEFAULT 0.0,
    tns REAL DEFAULT 0.0,
    utilization REAL DEFAULT 0.0,
    runtime_sec REAL DEFAULT 0.0,
    cell_count INTEGER DEFAULT 0,
    qor_score REAL DEFAULT 0.0,
    timestamp TEXT DEFAULT (datetime('now'))
)
"""


def get_connection():
    conn = sqlite3.connect(DB_PATH)
    conn.execute(SCHEMA_SQL)
    conn.commit()
    return conn


def rows_to_dicts(rows, columns):
    return [dict(zip(columns, row)) for row in rows]


@app.get("/runs")
def get_runs():
    conn = get_connection()
    try:
        cursor = conn.cursor()
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
        columns = [
            "run_id", "design_name", "status", "current_stage",
            "progress", "wns", "tns", "utilization",
            "runtime_sec", "cell_count", "qor_score", "timestamp"
        ]
        return rows_to_dicts(rows, columns)
    finally:
        conn.close()


@app.get("/live_runs")
def get_live_runs():
    conn = get_connection()
    try:
        cursor = conn.cursor()
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
        columns = ["run_id", "status", "current_stage", "progress"]
        return rows_to_dicts(rows, columns)
    finally:
        conn.close()


@app.get("/trends")
def get_trends():
    conn = get_connection()
    try:
        cursor = conn.cursor()
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
    finally:
        conn.close()

    if len(rows) == 0:
        return {
            "trend": "NO_DATA",
            "avg_qor": 0,
            "avg_runtime": 0,
            "regressions": 0
        }

    qor_values = [row[0] for row in rows if row[0] is not None]
    runtime_values = [row[1] for row in rows if row[1] is not None]

    avg_qor = round(
        sum(qor_values) / len(qor_values), 2
    ) if qor_values else 0

    avg_runtime = round(
        sum(runtime_values) / len(runtime_values), 2
    ) if runtime_values else 0

    regressions = len(
        [v for v in qor_values if v < 0.7]
    )

    if len(qor_values) >= 2:
        if qor_values[0] > qor_values[-1]:
            trend = "IMPROVING"
        elif qor_values[0] < qor_values[-1]:
            trend = "DEGRADING"
        else:
            trend = "STABLE"
    else:
        trend = "NO_DATA"

    return {
        "trend": trend,
        "avg_qor": avg_qor,
        "avg_runtime": avg_runtime,
        "regressions": regressions
    }


if __name__ == "__main__":
    import uvicorn
    port = int(os.environ.get("PORT", "8000"))
    uvicorn.run("backend.server:app", host="127.0.0.1", port=port, reload=True)
