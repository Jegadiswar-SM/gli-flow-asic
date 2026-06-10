from fastapi import FastAPI, HTTPException, Query
from fastapi.middleware.cors import CORSMiddleware
from fastapi.staticfiles import StaticFiles
from fastapi.responses import FileResponse, PlainTextResponse
from pathlib import Path

import json
import os
import shutil
import sqlite3
import uuid
from datetime import datetime

from gli_flow.database.migrations import migrate_if_needed, MigrationEngine, _get_db_path

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

DB_PATH = os.environ.get("GLI_FLOW_DB") or os.environ.get("GLI_FLOW_DB_PATH") or _get_db_path()

def get_connection():
    migrate_if_needed(DB_PATH)
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    return conn


def validate_schema_at_startup():
    migrate_if_needed(DB_PATH)
    engine = MigrationEngine(DB_PATH)
    try:
        ok, errors = engine.validate_runtime_schema()
        if not ok:
            raise RuntimeError("Database schema validation failed: " + "; ".join(errors))
    finally:
        engine.close()


def rows_to_dicts(rows, columns):
    return [dict(zip(columns, row)) for row in rows]


def row_to_dict(row):
    if row is None:
        return None
    d = dict(row)
    for field in ("evidence", "recommended_fix", "before_metrics", "after_metrics"):
        if d.get(field) and isinstance(d[field], str):
            try:
                d[field] = json.loads(d[field])
            except (json.JSONDecodeError, TypeError):
                pass
    if isinstance(d.get("fix_applied"), int):
        d["fix_applied"] = bool(d["fix_applied"])
    return d


def _sanitize(obj):
    if isinstance(obj, float):
        import math
        if math.isnan(obj) or math.isinf(obj):
            return None
        return obj
    if isinstance(obj, dict):
        return {k: _sanitize(v) for k, v in obj.items()}
    if isinstance(obj, list):
        return [_sanitize(v) for v in obj]
    return obj


def _safe_run_path(run_id: str, *parts: str) -> Path:
    run_dir = (_OUTPUTS_DIR / run_id).resolve()
    candidate = run_dir.joinpath(*parts).resolve()
    if candidate != run_dir and run_dir not in candidate.parents:
        raise HTTPException(status_code=400, detail="Invalid path")
    return candidate


validate_schema_at_startup()


@app.get("/runs")
def get_runs(limit: int = Query(50, ge=1, le=10000), important: bool = Query(False)):
    conn = get_connection()
    try:
        cursor = conn.cursor()
        sql = """
            SELECT
                r.run_id,
                r.design_name,
                r.status,
                r.current_stage,
                r.progress,
                r.wns,
                r.tns,
                r.utilization,
                r.runtime_sec,
                r.cell_count,
                r.qor_score,
                r.timestamp,
                r.is_important,
                COALESCE(fa.failure_count, 0) AS failure_count,
                COALESCE(fa.severest, '') AS max_severity
            FROM runs r
            LEFT JOIN (
                SELECT run_id, COUNT(*) AS failure_count,
                       MAX(CASE severity
                         WHEN 'TAPEOUT_BLOCKING' THEN 5
                         WHEN 'HIGH' THEN 4
                         WHEN 'FUNCTIONAL_RISK' THEN 3
                         WHEN 'PERFORMANCE_DEGRADATION' THEN 2
                         WHEN 'MEDIUM' THEN 1
                         WHEN 'LOW' THEN 0
                         ELSE -1 END) AS severity_rank,
                       MAX(severity) AS severest
                FROM failure_atlas_entries
                GROUP BY run_id
            ) fa ON r.run_id = fa.run_id
        """
        params = []
        if important:
            sql += " WHERE r.is_important = 1"
        
        sql += " ORDER BY r.timestamp DESC LIMIT ?"
        params.append(limit)
        
        cursor.execute(sql, tuple(params))
        rows = cursor.fetchall()
        columns = [
            "run_id", "design_name", "status", "current_stage",
            "progress", "wns", "tns", "utilization",
            "runtime_sec", "cell_count", "qor_score", "timestamp",
            "is_important", "failure_count", "max_severity"
        ]
        return rows_to_dicts(rows, columns)
    finally:
        conn.close()


@app.get("/runs/count")
def get_runs_count():
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute("SELECT COUNT(*) FROM runs")
        return {"total": cursor.fetchone()[0]}
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

        cursor.execute(
            "SELECT COUNT(*), MAX(severity) FROM failure_atlas_entries WHERE run_id = ?",
            (run_id,),
        )
        fa_row = cursor.fetchone()
        result["failure_count"] = fa_row[0] or 0
        result["max_severity"] = fa_row[1] or ""

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
                result["drc_lvs"] = _sanitize(json.loads(drc_lvs_path.read_text()))
            sta_path = run_dir / "sta_corners.json"
            if sta_path.exists():
                result["sta_corners"] = _sanitize(json.loads(sta_path.read_text()))
            telemetry_path = run_dir / "telemetry" / "metrics.json"
            if telemetry_path.exists():
                result["telemetry"] = _sanitize(json.loads(telemetry_path.read_text()))
        return result
    finally:
        conn.close()


@app.get("/runs/{run_id}/image/{image_name:path}")
def get_run_image(run_id: str, image_name: str):
    for ext in ("", ".webp", ".png", ".jpg"):
        candidate = _safe_run_path(run_id, "reports", image_name + ext)
        if candidate.exists():
            return FileResponse(str(candidate))
        candidate = _safe_run_path(run_id, image_name + ext)
        if candidate.exists():
            return FileResponse(str(candidate))
    raise HTTPException(status_code=404, detail="Image not found")


@app.get("/runs/{run_id}/report/{report_type:path}")
def get_run_report(run_id: str, report_type: str):
    direct = _safe_run_path(run_id, report_type)
    if direct.exists():
        if direct.suffix in (".json", ".csv", ".log", ".txt", ".rpt"):
            return PlainTextResponse(direct.read_text(errors="replace"))
        return FileResponse(str(direct))
    for fname in (report_type, report_type + ".rpt", report_type + ".txt", report_type + ".csv", report_type + ".json", report_type + ".log"):
        candidate = _safe_run_path(run_id, "reports", fname)
        if candidate.exists():
            if candidate.suffix in (".json", ".csv", ".log", ".txt", ".rpt"):
                text = candidate.read_text(errors="replace")
                return PlainTextResponse(text)
            return FileResponse(str(candidate))
    artifacts_file = _safe_run_path(run_id, "artifacts", report_type)
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


# ====================================================
# FAILURE ATLAS API ENDPOINTS
# ====================================================

@app.get("/runs/{run_id}/failures")
def get_run_failures(run_id: str):
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            "SELECT * FROM failure_atlas_entries WHERE run_id = ? ORDER BY detected_at DESC",
            (run_id,),
        )
        return [row_to_dict(row) for row in cursor.fetchall()]
    finally:
        conn.close()


@app.get("/failures")
def get_failures(
    limit: int = Query(50, ge=1, le=200),
    offset: int = Query(0, ge=0),
    severity: str = Query(None),
    failure_type: str = Query(None),
    search: str = Query(None),
):
    conn = get_connection()
    try:
        cursor = conn.cursor()
        query = """
            SELECT fa.*, r.is_important 
            FROM failure_atlas_entries fa
            LEFT JOIN runs r ON fa.run_id = r.run_id
            WHERE 1=1
        """
        count_query = "SELECT COUNT(*) FROM failure_atlas_entries WHERE 1=1"
        params = []

        if severity:
            query += " AND severity = ?"
            count_query += " AND severity = ?"
            params.append(severity)
        if failure_type:
            query += " AND failure_type = ?"
            count_query += " AND failure_type = ?"
            params.append(failure_type)
        if search:
            query += " AND (title LIKE ? OR description LIKE ? OR failure_type LIKE ?)"
            count_query += " AND (title LIKE ? OR description LIKE ? OR failure_type LIKE ?)"
            params.extend([f"%{search}%", f"%{search}%", f"%{search}%"])

        cursor.execute(count_query, params)
        total = cursor.fetchone()[0]

        query += " ORDER BY detected_at DESC LIMIT ? OFFSET ?"
        cursor.execute(query, params + [limit, offset])
        
        # Need to map columns manually to dict
        columns = [description[0] for description in cursor.description]
        results = [dict(zip(columns, row)) for row in cursor.fetchall()]
        
        # Apply row_to_dict logic
        for r in results:
            # Reconstruct the dict to handle JSON fields
            for field in ("evidence", "recommended_fix", "before_metrics", "after_metrics"):
                if r.get(field) and isinstance(r[field], str):
                    try:
                        r[field] = json.loads(r[field])
                    except (json.JSONDecodeError, TypeError):
                        pass
            if isinstance(r.get("fix_applied"), int):
                r["fix_applied"] = bool(r["fix_applied"])

        return {
            "total": total,
            "limit": limit,
            "offset": offset,
            "results": results,
        }
    finally:
        conn.close()


@app.get("/failures/{failure_id}")
def get_failure(failure_id: str):
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            "SELECT * FROM failure_atlas_entries WHERE id = ?",
            (failure_id,),
        )
        row = cursor.fetchone()
        if row is None:
            cursor.execute(
                "SELECT * FROM failure_atlas_entries WHERE failure_id = ?",
                (failure_id,),
            )
            row = cursor.fetchone()
        if row is None:
            raise HTTPException(status_code=404, detail="Failure not found")
        result = row_to_dict(row)

        related = conn.cursor()
        related.execute(
            "SELECT * FROM failure_atlas_entries WHERE failure_type = ? AND id != ? ORDER BY detected_at DESC LIMIT 5",
            (result["failure_type"], result["id"]),
        )
        result["similar_failures"] = [row_to_dict(r) for r in related.fetchall()]

        return result
    finally:
        conn.close()


@app.post("/failures/{failure_id}/resolution")
def resolve_failure(failure_id: str, payload: dict):
    fix_type = payload.get("fix_type")
    fix_description = payload.get("fix_description", "")
    fix_run_id = payload.get("fix_run_id", "")
    before_metrics = payload.get("before_metrics")
    after_metrics = payload.get("after_metrics")

    if not fix_type:
        raise HTTPException(status_code=400, detail="fix_type is required")

    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            "SELECT id FROM failure_atlas_entries WHERE id = ? OR failure_id = ?",
            (failure_id, failure_id),
        )
        row = cursor.fetchone()
        if row is None:
            raise HTTPException(status_code=404, detail="Failure not found")

        actual_id = row[0]

        before_json = json.dumps(before_metrics) if before_metrics else None
        after_json = json.dumps(after_metrics) if after_metrics else None

        resolution_confidence = "MEDIUM"
        if before_metrics and after_metrics:
            wns_before = before_metrics.get("wns", 0) or 0
            wns_after = after_metrics.get("wns", 0) or 0
            if wns_after > wns_before:
                resolution_confidence = "HIGH"
            else:
                resolution_confidence = "LOW"

        cursor.execute(
            """
            UPDATE failure_atlas_entries SET
                fix_applied = 1,
                fix_type = ?,
                fix_description = ?,
                fix_run_id = ?,
                before_metrics = ?,
                after_metrics = ?,
                resolution_confidence = ?
            WHERE id = ?
            """,
            (fix_type, fix_description, fix_run_id,
             before_json, after_json, resolution_confidence,
             actual_id),
        )
        conn.commit()

        return {"status": "ok", "message": "Resolution recorded", "resolution_confidence": resolution_confidence}
    finally:
        conn.close()


# ====================================================
# ANALYTICS ENDPOINTS
# ====================================================

@app.get("/analytics/summary")
def get_analytics_summary():
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute("SELECT COUNT(*) FROM failure_atlas_entries")
        total = cursor.fetchone()[0]
        cursor.execute("SELECT COUNT(*) FROM failure_atlas_entries WHERE fix_applied = 1")
        fixed = cursor.fetchone()[0]
        cursor.execute("SELECT COUNT(*) FROM failure_atlas_entries WHERE resolution_confidence = 'HIGH'")
        high_confidence = cursor.fetchone()[0]

        return {
            "total_failures": total,
            "fixed_count": fixed,
            "unfixed_count": total - fixed,
            "success_rate": round(fixed / total * 100, 1) if total > 0 else 0,
            "high_confidence_resolutions": high_confidence,
        }
    finally:
        conn.close()


@app.get("/analytics/common-failures")
def get_common_failures(limit: int = Query(10, ge=1, le=50)):
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """
            SELECT failure_type, COUNT(*) as count,
                   ROUND(CAST(COUNT(*) AS FLOAT) / (SELECT COUNT(*) FROM failure_atlas_entries) * 100, 1) as percentage
            FROM failure_atlas_entries
            GROUP BY failure_type
            ORDER BY count DESC
            LIMIT ?
            """,
            (limit,),
        )
        return [dict(row) for row in cursor.fetchall()]
    finally:
        conn.close()


@app.get("/analytics/fix-effectiveness")
def get_fix_effectiveness(min_samples: int = Query(3, ge=1)):
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """
            SELECT failure_type, fix_type,
                   COUNT(*) as sample_size,
                   ROUND(CAST(SUM(fix_applied) AS FLOAT) / COUNT(*) * 100, 1) as success_rate
            FROM failure_atlas_entries
            WHERE fix_type IS NOT NULL AND fix_type != ''
            GROUP BY failure_type, fix_type
            HAVING sample_size >= ?
            ORDER BY success_rate DESC
            """,
            (min_samples,),
        )
        results = [dict(row) for row in cursor.fetchall()]
        if not results:
            return {"message": "Insufficient Data", "min_samples_required": min_samples, "results": []}
        return {"results": results, "min_samples": min_samples}
    finally:
        conn.close()


@app.get("/analytics/qor-improvements")
def get_qor_improvements():
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """
            SELECT fix_type,
                   COUNT(*) as sample_size,
                   COALESCE(AVG(
                       CASE
                           WHEN before_metrics IS NOT NULL AND after_metrics IS NOT NULL
                           THEN json_extract(after_metrics, '$.wns') - json_extract(before_metrics, '$.wns')
                           ELSE NULL
                       END
                   ), 0) as avg_wns_improvement,
                   COALESCE(AVG(
                       CASE
                           WHEN before_metrics IS NOT NULL AND after_metrics IS NOT NULL
                           THEN json_extract(after_metrics, '$.tns') - json_extract(before_metrics, '$.tns')
                           ELSE NULL
                       END
                   ), 0) as avg_tns_improvement
            FROM failure_atlas_entries
            WHERE fix_type IS NOT NULL AND fix_type != ''
            GROUP BY fix_type
            ORDER BY avg_wns_improvement DESC
            """
        )
        return [dict(row) for row in cursor.fetchall()]
    finally:
        conn.close()


@app.get("/analytics/failure-trends")
def get_failure_trends():
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """
            SELECT failure_type, COUNT(*) as count,
                   ROUND(CAST(COUNT(*) AS FLOAT) / (SELECT COUNT(*) FROM failure_atlas_entries) * 100, 1) as percentage
            FROM failure_atlas_entries
            GROUP BY failure_type
            ORDER BY count DESC
            """
        )
        failure_dist = [dict(row) for row in cursor.fetchall()]

        cursor.execute(
            """
            SELECT DATE(detected_at) as date, COUNT(*) as count
            FROM failure_atlas_entries
            WHERE detected_at IS NOT NULL
            GROUP BY DATE(detected_at)
            ORDER BY date DESC
            LIMIT 30
            """
        )
        daily_counts = [dict(row) for row in cursor.fetchall()]

        return {
            "failure_distribution": failure_dist,
            "daily_counts": daily_counts,
        }
    finally:
        conn.close()


@app.get("/analytics/resolution-confidence")
def get_resolution_confidence():
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """
            SELECT resolution_confidence, COUNT(*) as count
            FROM failure_atlas_entries
            WHERE resolution_confidence IS NOT NULL
            GROUP BY resolution_confidence
            ORDER BY count DESC
            """
        )
        distribution = [dict(row) for row in cursor.fetchall()]

        cursor.execute(
            """
            SELECT COUNT(*) FROM failure_atlas_entries
            WHERE resolution_confidence IS NULL OR resolution_confidence = ''
            """
        )
        unresolved = cursor.fetchone()[0]

        return {
            "distribution": distribution,
            "unresolved": unresolved,
        }
    finally:
        conn.close()


@app.get("/analytics/mttr")
def get_mttr():
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """
            SELECT failure_type,
                   COUNT(*) as sample_size,
                   ROUND(CAST(SUM(CASE WHEN fix_applied = 1 THEN 1 ELSE 0 END) AS FLOAT) / COUNT(*) * 100, 1) as resolution_rate
            FROM failure_atlas_entries
            GROUP BY failure_type
            ORDER BY sample_size DESC
            """
        )
        return [dict(row) for row in cursor.fetchall()]
    finally:
        conn.close()


# ====================================================
# REGRESSION EVENTS
# ====================================================

@app.get("/regressions")
def get_regressions():
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """
            SELECT f1.*
            FROM failure_atlas_entries f1
            WHERE f1.detected_at = (
                SELECT MIN(f2.detected_at)
                FROM failure_atlas_entries f2
                WHERE f2.failure_type = f1.failure_type
            )
            ORDER BY f1.detected_at DESC
            LIMIT 20
            """
        )
        return [row_to_dict(row) for row in cursor.fetchall()]
    finally:
        conn.close()


# ====================================================
# SIMILAR FAILURES
# ====================================================

@app.get("/similar-failures/{failure_type}")
def get_similar_failures(failure_type: str, limit: int = Query(10, ge=1, le=50)):
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """
            SELECT failure_type, fix_type,
                   COUNT(*) as sample_size,
                   ROUND(CAST(SUM(fix_applied) AS FLOAT) / COUNT(*) * 100, 1) as success_rate
            FROM failure_atlas_entries
            WHERE failure_type = ?
            GROUP BY failure_type, fix_type
            ORDER BY sample_size DESC
            LIMIT ?
            """,
            (failure_type, limit),
        )
        results = [dict(row) for row in cursor.fetchall()]
        return {
            "failure_type": failure_type,
            "total_cases": sum(r.get("sample_size", 0) for r in results),
            "fix_strategies": results,
            "total": sum(r.get("sample_size", 0) for r in results),
            "results": results,
        }
    finally:
        conn.close()


# ====================================================
# RUN DIFF
# ====================================================

@app.get("/runs/{run_id}/diff/{previous_run_id}")
def get_run_diff(run_id: str, previous_run_id: str):
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM runs WHERE run_id = ?", (run_id,))
        current = cursor.fetchone()
        cursor.execute("SELECT * FROM runs WHERE run_id = ?", (previous_run_id,))
        previous = cursor.fetchone()

        if not current or not previous:
            raise HTTPException(status_code=404, detail="Run not found")

        diff_fields = [
            "wns", "tns", "utilization", "runtime_sec",
            "cell_count", "qor_score",
        ]
        diffs = {}
        for field in diff_fields:
            curr_val = current[field] if field in current.keys() else None
            prev_val = previous[field] if field in previous.keys() else None
            if curr_val is not None and prev_val is not None:
                diffs[field] = {
                    "before": prev_val,
                    "after": curr_val,
                    "delta": round(curr_val - prev_val, 4),
                }
            elif curr_val is not None:
                diffs[field] = {"before": None, "after": curr_val, "delta": None}

        return {
            "run_id": run_id,
            "previous_run_id": previous_run_id,
            "diffs": diffs,
            "likely_regression": any(
                d.get("delta", 0) < 0 for d in diffs.values()
                if d.get("delta") is not None and isinstance(d["delta"], (int, float))
            ),
        }
    finally:
        conn.close()


@app.patch("/runs/{run_id}/important")
def toggle_important_run(run_id: str, payload: dict):
    is_important = payload.get("is_important", False)
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            "UPDATE runs SET is_important = ?, important_marked_at = ? WHERE run_id = ?",
            (1 if is_important else 0, datetime.now().isoformat() if is_important else None, run_id),
        )
        conn.commit()

        # Telemetry collection
        from telemetry.telemetry_manager import TelemetryManager
        
        # We need the output path for the run to instantiate TelemetryManager
        run_dir = _OUTPUTS_DIR / run_id
        if run_dir.is_dir():
            tm = TelemetryManager(str(run_dir))
            tm.export_stage_data("user_action", {
                "action": "important_run_marked",
                "is_important": is_important,
                "timestamp": datetime.now().isoformat()
            })
            
        return {"status": "ok", "is_important": is_important}
    finally:
        conn.close()


# ====================================================
# KNOWLEDGE BASE ENDPOINTS
# ====================================================

_knowledge_base = None


def load_knowledge_base():
    global _knowledge_base
    if _knowledge_base is not None:
        return _knowledge_base
    kb_path = Path(__file__).resolve().parent.parent / "failure_atlas" / "knowledge_base.json"
    if kb_path.exists():
        try:
            _knowledge_base = json.loads(kb_path.read_text())
        except Exception:
            _knowledge_base = {}
    else:
        _knowledge_base = {}
    return _knowledge_base


@app.get("/knowledge/failures")
def get_knowledge_failures():
    kb = load_knowledge_base()
    return {
        "entries": [
            {"failure_type": k, **v} for k, v in kb.items()
        ]
    }


@app.get("/knowledge/failures/{identifier}")
def get_knowledge_failure(identifier: str):
    # 1. Try signature library lookup
    signatures_dir = Path(__file__).resolve().parent.parent / "failure_atlas" / "signatures"
    
    # Priority 1: Exact Rule ID Match (in failure_atlas/signatures/drc/*.json)
    for json_file in signatures_dir.rglob("*.json"):
        try:
            sig = json.loads(json_file.read_text())
            if sig.get("rule_id") == identifier:
                # Log telemetry
                print(f"[TELEMETRY] rule_knowledge_viewed: rule_id={identifier}, source=signature_library")
                return {
                    "failure_type": identifier,
                    "description": sig.get("description"),
                    "remediation_strategies": [
                        {"technique": "Investigation", "description": step} for step in sig.get("investigation_checklist", [])
                    ],
                    "verification_steps": sig.get("known_causes", []),
                    "source": "signature_library",
                    "signature_version": "v1"
                }
        except Exception:
            continue

    # Priority 2: Fallback to existing knowledge base
    kb = load_knowledge_base()
    normalized = identifier.upper().replace("-", "_").replace(" ", "_")
    for key, value in kb.items():
        if key.upper().replace("-", "_").replace(" ", "_") == normalized:
            print(f"[TELEMETRY] rule_knowledge_viewed: rule_id={identifier}, source=legacy_kb")
            return {"failure_type": key, **value}
            
    # Telemetry: signature missing
    print(f"[TELEMETRY] signature_missing: rule_id={identifier}")
    raise HTTPException(status_code=404, detail="Failure type not found in knowledge base")


@app.get("/knowledge/search")
def search_knowledge(q: str = Query("", min_length=1)):
    kb = load_knowledge_base()
    results = []
    ql = q.lower()
    for key, value in kb.items():
        if ql in key.lower() or ql in str(value).lower():
            results.append({"failure_type": key, **value})
    return {"query": q, "results": results}


@app.get("/knowledge/qor")
def get_qor_playbook():
    qp_path = Path(__file__).resolve().parent.parent / "failure_atlas" / "qor_playbook.json"
    if qp_path.exists():
        try:
            return json.loads(qp_path.read_text())
        except Exception:
            pass
    return {}


# ====================================================
# RELIABILITY ENDPOINTS
# ====================================================

_RELIABILITY_BASE = Path(__file__).resolve().parent.parent / "outputs" / "reports"


@app.get("/reliability/summary")
def get_reliability_summary():
    reliability_file = _RELIABILITY_BASE / "reliability_report.json"
    health_file = _RELIABILITY_BASE / "execution_health_v3.json"

    scores = []
    if reliability_file.exists():
        try:
            scores = json.loads(reliability_file.read_text())
        except Exception:
            pass

    if not scores:
        conn = get_connection()
        try:
            cursor = conn.cursor()
            cursor.execute("SELECT run_id, status FROM runs ORDER BY timestamp DESC LIMIT 50")
            for row in cursor.fetchall():
                health = "HEALTHY" if row["status"] in ("SUCCESS", "COMPLETED") else ("FAILED" if row["status"] == "FAILED" else "WARNING")
                score = 90 if health == "HEALTHY" else (20 if health == "FAILED" else 60)
                confidence = "HIGH" if health == "HEALTHY" else ("LOW" if health == "FAILED" else "MEDIUM")
                scores.append({"run": row["run_id"], "status": row["status"], "health": health, "reliability_score": score, "confidence": confidence})
        finally:
            conn.close()

    if not scores:
        return {"total_runs": 0, "avg_score": 0, "health_distribution": {}, "confidence_distribution": {}, "scores": []}

    health_dist = {}
    confidence_dist = {}
    total_score = 0
    for s in scores:
        h = s.get("health", "UNKNOWN")
        health_dist[h] = health_dist.get(h, 0) + 1
        c = s.get("confidence", "UNKNOWN")
        confidence_dist[c] = confidence_dist.get(c, 0) + 1
        total_score += s.get("reliability_score", 0)

    return {
        "total_runs": len(scores),
        "avg_score": round(total_score / len(scores), 1) if scores else 0,
        "health_distribution": health_dist,
        "confidence_distribution": confidence_dist,
        "scores": scores,
    }


@app.get("/reliability/health")
def get_reliability_health():
    health_file = _RELIABILITY_BASE / "execution_health_v3.json"
    if health_file.exists():
        try:
            return json.loads(health_file.read_text())
        except Exception:
            pass

    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute("SELECT run_id, status, current_stage, progress FROM runs ORDER BY timestamp DESC LIMIT 50")
        results = []
        for row in cursor.fetchall():
            status = row["status"]
            health = "HEALTHY" if status in ("SUCCESS", "COMPLETED") else ("FAILED" if status == "FAILED" else "WARNING")
            results.append({"run": row["run_id"], "status": status, "health": health, "current_stage": row["current_stage"], "progress": row["progress"]})
        return results
    finally:
        conn.close()


@app.get("/reliability/trends")
def get_reliability_trends():
    trend_file = _RELIABILITY_BASE / "reliability_trend_report.json"
    if trend_file.exists():
        try:
            return json.loads(trend_file.read_text())
        except Exception:
            pass
    return {"message": "No trend data available", "trends": []}


# ====================================================
# PROVENANCE ENDPOINTS
# ====================================================

_PROVENANCE_DIR = Path(__file__).resolve().parent.parent / "provenance"


@app.get("/provenance/summary")
def get_provenance_summary():
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute("SELECT COUNT(*) FROM runs")
        total_runs = cursor.fetchone()[0]
        cursor.execute("SELECT run_id, design_name, status, qor_score, timestamp FROM runs ORDER BY timestamp DESC LIMIT 20")
        recent_runs = [dict(row) for row in cursor.fetchall()]
    finally:
        conn.close()

    manifest_files = list(Path(__file__).resolve().parent.parent.glob("outputs/runs/*/reports/reproducibility.json"))
    manifest_count = len(manifest_files)

    provenance_graph = _PROVENANCE_DIR / "provenance_graph.json"
    graph = {}
    if provenance_graph.exists():
        try:
            graph = json.loads(provenance_graph.read_text())
        except Exception:
            pass

    return {
        "total_runs": total_runs,
        "runs_with_manifests": manifest_count,
        "graph_nodes": len(graph.get("nodes", [])),
        "graph_edges": len(graph.get("edges", [])),
        "recent_runs": recent_runs,
    }


@app.get("/provenance/manifests")
def get_provenance_manifests():
    manifests = []
    for m_file in sorted(Path(__file__).resolve().parent.parent.glob("outputs/runs/*/reports/reproducibility.json"), reverse=True)[:20]:
        try:
            manifests.append(json.loads(m_file.read_text()))
        except Exception:
            pass

    if not manifests:
        conn = get_connection()
        try:
            cursor = conn.cursor()
            cursor.execute("SELECT run_id, design_name, status, qor_score, timestamp FROM runs ORDER BY timestamp DESC LIMIT 20")
            for row in cursor.fetchall():
                manifests.append({
                    "manifest_version": "2.0",
                    "run_id": row["run_id"],
                    "design_name": row["design_name"],
                    "timestamp_iso": row["timestamp"] if row["timestamp"] else "",
                    "system": {
                        "platform": "inferred",
                        "python_version": "derived",
                        "hostname": "dashboard",
                    },
                    "toolchain": {
                        "openroad": "inferred",
                        "yosys": "inferred",
                        "python": "inferred",
                    },
                    "provenance": {
                        "rtl_hashes": {},
                        "pdk": {"name": "inferred", "root": ""},
                    },
                    "execution": {
                        "reproduction_command": f"gli-flow run {row['design_name']}",
                        "reproducibility_mode": True,
                    },
                    "metrics": {"qor_score": row["qor_score"]},
                    "status": row["status"],
                })
        finally:
            conn.close()

    return manifests


@app.get("/provenance/graph")
def get_provenance_graph():
    provenance_graph = _PROVENANCE_DIR / "provenance_graph.json"
    if provenance_graph.exists():
        try:
            return json.loads(provenance_graph.read_text())
        except Exception:
            pass

    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute("SELECT run_id, design_name, status FROM runs ORDER BY timestamp DESC LIMIT 20")
        rows = cursor.fetchall()
    finally:
        conn.close()

    nodes = []
    edges = []
    for row in rows:
        nodes.append({"id": row["run_id"], "name": row["run_id"], "type": "run", "design": row["design_name"], "status": row["status"]})
    if len(nodes) >= 2:
        for i in range(len(nodes) - 1):
            edges.append({"source": nodes[i]["id"], "target": nodes[i + 1]["id"], "relation": "precedes"})

    return {"nodes": nodes, "edges": edges}


from failure_atlas.correlation_engine import get_correlation_data
from failure_atlas.coverage_engine import get_coverage_data

@app.get("/failures/correlation/{failure_type}")
def get_failure_correlation(failure_type: str):
    return get_correlation_data(failure_type)

@app.get("/analytics/coverage")
def get_coverage_analytics():
    return get_coverage_data()

@app.post("/telemetry/event")
def record_event(payload: dict):
    print(f"[TELEMETRY] {payload.get('event')}: {payload}")
    return {"status": "ok"}


_dashboard_dist = str(Path(__file__).resolve().parent.parent / "dashboard" / "dist")
if os.path.isdir(_dashboard_dist):
    app.mount("/", StaticFiles(directory=_dashboard_dist, html=True), name="dashboard")


if __name__ == "__main__":
    import uvicorn
    port = int(os.environ.get("PORT", "8000"))
    uvicorn.run("backend.server:app", host="127.0.0.1", port=port, reload=True)

@app.post("/telemetry/event")
def record_event(payload: dict):
    print(f"[TELEMETRY] {payload.get('event')}: {payload}")
    return {"status": "ok"}

