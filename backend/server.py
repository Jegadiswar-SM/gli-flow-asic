from fastapi import FastAPI, HTTPException
from fastapi.middleware.cors import CORSMiddleware
from fastapi.staticfiles import StaticFiles
from fastapi.responses import FileResponse, PlainTextResponse
from pathlib import Path

import json
import os
import shutil
import sqlite3

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
    timestamp TEXT DEFAULT (datetime('now')),
    run_dir TEXT DEFAULT NULL,
    regression INTEGER DEFAULT 0,
    drc_violations INTEGER DEFAULT NULL,
    lvs_result TEXT DEFAULT NULL
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



_OUTPUTS_DIR = Path(__file__).resolve().parent.parent / "outputs" / "runs"


@app.get("/runs/{run_id}")
def get_run(run_id: str):
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """
            SELECT
                run_id, design_name, status, current_stage, progress,
                wns, tns, utilization, runtime_sec, cell_count,
                qor_score, timestamp
            FROM runs
            WHERE run_id = ?
            """,
            (run_id,),
        )
        row = cursor.fetchone()
        if row is None:
            raise HTTPException(status_code=404, detail="Run not found")
        columns = [
            "run_id", "design_name", "status", "current_stage",
            "progress", "wns", "tns", "utilization",
            "runtime_sec", "cell_count", "qor_score", "timestamp",
        ]
        result = dict(zip(columns, row))

        run_dir = _OUTPUTS_DIR / run_id
        if run_dir.is_dir():
            result["run_dir"] = str(run_dir)
            artifacts = []
            for f in sorted(run_dir.rglob("*")):
                if f.is_file() and f.suffix in (".json", ".csv", ".rpt", ".txt", ".log", ".gds", ".def", ".v", ".webp", ".png", ".jpg"):
                    rel = f.relative_to(run_dir)
                    artifacts.append(str(rel))
            result["artifacts"] = artifacts
            drc_lvs_path = run_dir / "drc_lvs_summary.json"
            if drc_lvs_path.exists():
                result["drc_lvs"] = json.loads(drc_lvs_path.read_text())
            sta_path = run_dir / "sta_corners.json"
            if sta_path.exists():
                result["sta_corners"] = json.loads(sta_path.read_text())
            telemetry_path = run_dir / "telemetry" / "metrics.json"
            if telemetry_path.exists():
                result["telemetry"] = json.loads(telemetry_path.read_text())
        return result
    finally:
        conn.close()


@app.get("/runs/{run_id}/image/{image_name:path}")
def get_run_image(run_id: str, image_name: str):
    run_dir = _OUTPUTS_DIR / run_id
    for ext in ("", ".webp", ".png", ".jpg"):
        candidate = run_dir / "reports" / (image_name + ext)
        if candidate.exists():
            return FileResponse(str(candidate))
    raise HTTPException(status_code=404, detail="Image not found")


@app.get("/runs/{run_id}/report/{report_type:path}")
def get_run_report(run_id: str, report_type: str):
    run_dir = _OUTPUTS_DIR / run_id
    for fname in (report_type, report_type + ".rpt", report_type + ".txt", report_type + ".csv", report_type + ".json", report_type + ".log"):
        candidate = run_dir / "reports" / fname
        if candidate.exists():
            if candidate.suffix in (".json", ".csv", ".log", ".txt", ".rpt"):
                text = candidate.read_text(errors="replace")
                return PlainTextResponse(text)
            return FileResponse(str(candidate))
    artifacts_file = run_dir / "artifacts" / report_type
    if artifacts_file.exists():
        return FileResponse(str(artifacts_file))
    raise HTTPException(status_code=404, detail="Report not found")


@app.get("/releases")
def get_releases():
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """
            SELECT run_id, design_name, qor_score, status, timestamp
            FROM runs
            WHERE qor_score IS NOT NULL
            ORDER BY qor_score DESC
            LIMIT 10
            """
        )
        rows = cursor.fetchall()
        columns = ["run_id", "design_name", "qor_score", "status", "timestamp"]
        return rows_to_dicts(rows, columns)
    finally:
        conn.close()


@app.get("/health")
def get_health():
    tools = {}
    for name in ("openroad", "yosys", "klayout", "magic", "netgen"):
        tools[name] = shutil.which(name) is not None
    return {
        "status": "ok",
        "database": os.path.isfile(DB_PATH),
        "tools": tools,
    }


_dashboard_dist = str(Path(__file__).resolve().parent.parent / "dashboard" / "dist")
if os.path.isdir(_dashboard_dist):
    app.mount("/", StaticFiles(directory=_dashboard_dist, html=True), name="dashboard")


if __name__ == "__main__":
    import uvicorn
    port = int(os.environ.get("PORT", "8000"))
    uvicorn.run("backend.server:app", host="127.0.0.1", port=port, reload=True)
