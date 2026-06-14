from fastapi import FastAPI, HTTPException, Query
from fastapi.middleware.cors import CORSMiddleware
from fastapi.staticfiles import StaticFiles
from fastapi.responses import FileResponse, PlainTextResponse, JSONResponse
from pathlib import Path

import dataclasses
import json
import math
import mimetypes
import os
import shutil
import sqlite3
import uuid
from datetime import datetime

from gli_flow.database.migrations import migrate_if_needed, MigrationEngine, _get_db_path
from gli_flow.database.sqlite import DatabaseManager

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
                r.hold_wns,
                r.hold_tns,
                r.utilization,
                r.runtime_sec,
                r.cell_count,
                r.qor_score,
                r.timestamp,
                r.is_important,
                r.tapeout_ready,
                r.implementation_status,
                r.signoff_status,
                r.implementation_score,
                r.signoff_score,
                r.root_cause_summary,
                r.drc_violations,
                r.drc_is_clean,
                r.lvs_is_clean,
                COALESCE(fa.failure_count, 0) AS failure_count,
                COALESCE(fa.severest, '') AS max_severity
            FROM runs r
            LEFT JOIN (
                SELECT run_id, COUNT(*) AS failure_count,
                 MAX(CASE severity
                          WHEN 'TAPEOUT_BLOCKING' THEN 5
                          WHEN 'HIGH' THEN 4
                          WHEN 'UNDER_REVIEW' THEN 3
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
            "progress", "wns", "tns", "hold_wns", "hold_tns",
            "utilization", "runtime_sec", "cell_count", "qor_score",
            "timestamp", "is_important", "tapeout_ready",
            "implementation_status", "signoff_status",
            "implementation_score", "signoff_score", "root_cause_summary",
            "drc_violations", "drc_is_clean", "lvs_is_clean",
            "failure_count", "max_severity",
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
                wns, tns, hold_wns, hold_tns, utilization, runtime_sec,
                cell_count, qor_score, timestamp, drc_violations,
                drc_magic_violations, drc_klayout_violations, drc_is_clean,
                lvs_result, lvs_is_clean, signoff_setup_pass, signoff_hold_pass,
                signoff_gate_json, tapeout_ready, implementation_status,
                signoff_status, implementation_score, signoff_score,
                root_cause_summary
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
            "progress", "wns", "tns", "hold_wns", "hold_tns",
            "utilization", "runtime_sec", "cell_count", "qor_score",
            "timestamp", "drc_violations", "drc_magic_violations",
            "drc_klayout_violations", "drc_is_clean", "lvs_result",
            "lvs_is_clean", "signoff_setup_pass", "signoff_hold_pass",
            "signoff_gate_json", "tapeout_ready", "implementation_status",
            "signoff_status", "implementation_score", "signoff_score",
            "root_cause_summary",
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
            drc_combined_path = run_dir / "reports" / "drc_combined.json"
            if drc_combined_path.exists():
                try:
                    result["drc_combined"] = _sanitize(json.loads(drc_combined_path.read_text()))
                except Exception:
                    pass
            drc_agreement_path = run_dir / "telemetry" / "drc_agreement.json"
            if drc_agreement_path.exists():
                try:
                    result["drc_analysis"] = _sanitize(json.loads(drc_agreement_path.read_text()))
                except Exception:
                    pass
            sta_path = run_dir / "sta_corners.json"
            if sta_path.exists():
                result["sta_corners"] = _sanitize(json.loads(sta_path.read_text()))
            telemetry_path = run_dir / "telemetry" / "metrics.json"
            if telemetry_path.exists():
                result["telemetry"] = _sanitize(json.loads(telemetry_path.read_text()))
        return result
    finally:
        conn.close()


@app.get("/runs/{run_id}/drc")
def get_run_drc(run_id: str):
    run_dir = _OUTPUTS_DIR / run_id
    if not run_dir.is_dir():
        raise HTTPException(status_code=404, detail="Run directory not found")
    drc_combined_path = run_dir / "reports" / "drc_combined.json"
    if not drc_combined_path.exists():
        return {"run_id": run_id, "drc_result": None, "analysis": None}
    try:
        drc_combined = json.loads(drc_combined_path.read_text())
        analysis = None
        drc_agreement_path = run_dir / "telemetry" / "drc_agreement.json"
        if drc_agreement_path.exists():
            analysis = json.loads(drc_agreement_path.read_text())
        return {"run_id": run_id, "drc_result": _sanitize(drc_combined), "analysis": _sanitize(analysis)}
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"DRC analysis error: {e}")


@app.get("/runs/{run_id}/image/{image_name:path}")
def get_run_image(run_id: str, image_name: str):
    for ext in ("", ".webp", ".png", ".jpg", ".webp.png", ".svg"):
        candidate = _safe_run_path(run_id, "reports", image_name + ext)
        if candidate.exists():
            mime = _image_mime_type(candidate)
            return FileResponse(str(candidate), media_type=mime)
        candidate = _safe_run_path(run_id, image_name + ext)
        if candidate.exists():
            mime = _image_mime_type(candidate)
            return FileResponse(str(candidate), media_type=mime)
    raise HTTPException(status_code=404, detail="Image not found")


def _image_mime_type(path: Path) -> str:
    ext = path.suffix.lower()
    if ext == ".webp":
        return "image/webp"
    if ext == ".png":
        return "image/png"
    if ext == ".jpg" or ext == ".jpeg":
        return "image/jpeg"
    if ext == ".svg":
        return "image/svg+xml"
    return "image/webp"


_EMPTY_REPORT_FALLBACKS = {
    "antenna": "0 antenna violations",
    "atpg": "ATPG tool not available — 0 patterns generated",
    "drc": "0 DRC violations",
    "violation": "0 violations",
}

def _report_text(text: str, report_type: str) -> str:
    stripped = text.strip()
    if stripped:
        return text
    report_lower = report_type.lower()
    for keyword, msg in _EMPTY_REPORT_FALLBACKS.items():
        if keyword in report_lower:
            return msg + "\n"
    return "No data\n"

@app.get("/runs/{run_id}/report/{report_type:path}")
def get_run_report(run_id: str, report_type: str):
    direct = _safe_run_path(run_id, report_type)
    if direct.exists():
        if direct.suffix in (".json", ".csv", ".log", ".txt", ".rpt"):
            text = _report_text(direct.read_text(errors="replace"), report_type)
            return PlainTextResponse(text)
        return FileResponse(str(direct))
    for fname in (report_type, report_type + ".rpt", report_type + ".txt", report_type + ".csv", report_type + ".json", report_type + ".log"):
        candidate = _safe_run_path(run_id, "reports", fname)
        if candidate.exists():
            if candidate.suffix in (".json", ".csv", ".log", ".txt", ".rpt"):
                text = _report_text(candidate.read_text(errors="replace"), report_type)
                return PlainTextResponse(text)
            return FileResponse(str(candidate))
    artifacts_file = _safe_run_path(run_id, "artifacts", report_type)
    if artifacts_file.exists():
        return FileResponse(str(artifacts_file))
    raise HTTPException(status_code=404, detail="Report not found")


# ── Artifact Viewer Endpoints ───────────────────────────────────────────────

TEXT_EXTENSIONS = {".txt", ".log", ".rpt", ".csv", ".json", ".yaml", ".yml",
                   ".md", ".v", ".sv", ".vhdl", ".tcl", ".py", ".cfg", ".conf",
                   ".sdc", ".sdf", ".spef", ".lib", ".lef", ".def"}
IMAGE_EXTENSIONS = {".png", ".jpg", ".jpeg", ".webp", ".svg"}
PDF_EXTENSIONS = {".pdf"}
HTML_EXTENSIONS = {".html", ".htm"}

ARTIFACT_CATEGORIES = {
    "reports": {".rpt", ".txt", ".csv", ".md"},
    "logs": {".log"},
    "images": IMAGE_EXTENSIONS,
    "pdfs": PDF_EXTENSIONS,
    "html": HTML_EXTENSIONS,
    "json": {".json"},
    "yaml": {".yaml", ".yml"},
    "config": {".cfg", ".conf", ".tcl", ".sdc"},
    "code": {".v", ".sv", ".vhdl", ".py"},
    "layout": {".gds", ".def", ".lef", ".lib", ".sdf", ".spef", ".spi"},
}


def _artifact_mime_type(path: Path) -> str:
    ext = path.suffix.lower()
    if ext in IMAGE_EXTENSIONS:
        return _image_mime_type(path)
    if ext == ".pdf":
        return "application/pdf"
    if ext in (".html", ".htm"):
        return "text/html"
    if ext == ".json":
        return "application/json"
    if ext == ".csv":
        return "text/csv"
    if ext == ".yaml" or ext == ".yml":
        return "text/yaml"
    if ext == ".svg":
        return "image/svg+xml"
    if ext in (".gds",):
        return "application/octet-stream"
    if ext in (".def", ".lef", ".lib", ".sdc", ".sdf", ".spef", ".spi"):
        return "text/plain"
    mt = mimetypes.guess_type(str(path))[0]
    return mt or "application/octet-stream"


def _categorize_artifact(ext: str) -> str:
    for cat, exts in ARTIFACT_CATEGORIES.items():
        if ext in exts:
            return cat
    return "other"


@app.get("/runs/{run_id}/artifacts")
def list_artifacts(run_id: str):
    # Try primary run directory path
    run_dir = _OUTPUTS_DIR / run_id

    # Fallback: check database for the run's run_dir if it differs
    if not run_dir.is_dir():
        try:
            conn = get_connection()
            cursor = conn.cursor()
            cursor.execute("SELECT run_dir FROM runs WHERE run_id = ?", (run_id,))
            row = cursor.fetchone()
            conn.close()
            if row and row[0]:
                alt = Path(row[0])
                if alt.is_dir():
                    run_dir = alt
        except Exception:
            pass

    artifacts = []
    if not run_dir.is_dir():
        return artifacts

    for f in sorted(run_dir.rglob("*")):
        if not f.is_file() or f.name.startswith("."):
            continue
        rel = str(f.relative_to(run_dir))
        ext = f.suffix.lower()
        stat = f.stat()
        artifacts.append({
            "path": rel,
            "name": f.name,
            "size_bytes": stat.st_size,
            "size_mb": round(stat.st_size / (1024 * 1024), 3),
            "modified": datetime.fromtimestamp(stat.st_mtime).isoformat(),
            "extension": ext,
            "category": _categorize_artifact(ext),
            "is_text": ext in TEXT_EXTENSIONS,
            "is_image": ext in IMAGE_EXTENSIONS,
            "is_pdf": ext in PDF_EXTENSIONS,
            "is_html": ext in HTML_EXTENSIONS,
        })
    return artifacts


@app.get("/runs/{run_id}/artifact")
def get_artifact_file(run_id: str, path: str = Query(...)):
    safe = _safe_run_path(run_id, path)
    if not safe.is_file():
        raise HTTPException(status_code=404, detail="Artifact not found")
    mime = _artifact_mime_type(safe)
    return FileResponse(str(safe), media_type=mime, filename=safe.name)


@app.get("/runs/{run_id}/artifact/preview")
def get_artifact_preview(
    run_id: str,
    path: str = Query(...),
    max_preview_mb: float = Query(5.0, ge=0.1, le=100),
    lines: int = Query(0, ge=0, le=100000),
):
    safe = _safe_run_path(run_id, path)
    if not safe.is_file():
        raise HTTPException(status_code=404, detail="Artifact not found")
    ext = safe.suffix.lower()
    if ext not in TEXT_EXTENSIONS:
        raise HTTPException(status_code=400,
                            detail=f"Preview not supported for {ext} files. Use /artifact endpoint for raw file.")
    stat = safe.stat()
    size_mb = stat.st_size / (1024 * 1024)
    truncated = False
    content = safe.read_text(errors="replace")
    if size_mb > max_preview_mb:
        max_chars = int(max_preview_mb * 1024 * 1024)
        content = content[:max_chars]
        truncated = True
    if lines > 0:
        content_lines = content.splitlines(keepends=True)
        content = "".join(content_lines[:lines])
        if len(content_lines) > lines:
            truncated = True
    return {
        "content": content,
        "size_bytes": stat.st_size,
        "size_mb": round(size_mb, 3),
        "truncated": truncated,
        "line_count": content.count("\n") + 1 if content else 0,
    }


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
def get_knowledge_failure(identifier: str, citation: str = Query(None)):
    # Priority 1: Signature library lookup (exact rule_id match)
    signatures_dir = Path(__file__).resolve().parent.parent / "failure_atlas" / "signatures"
    for json_file in signatures_dir.rglob("*.json"):
        try:
            sig = json.loads(json_file.read_text())
            if sig.get("rule_id") == identifier:
                print(f"[TELEMETRY] rule_knowledge_viewed: rule_id={identifier}, source=signature_library")
                return {
                    "failure_type": identifier,
                    "description": sig.get("description"),
                    "remediation_strategies": [
                        {"technique": "Investigation", "description": step} for step in sig.get("investigation_checklist", [])
                    ],
                    "verification_steps": sig.get("known_causes", []),
                    "source": "signature_library",
                    "version": "v1",
                }
        except Exception:
            continue

    # Priority 2: Legacy knowledge base lookup by identifier
    kb = load_knowledge_base()
    normalized = identifier.upper().replace("-", "_").replace(" ", "_")
    for key, value in kb.items():
        if key.upper().replace("-", "_").replace(" ", "_") == normalized:
            print(f"[TELEMETRY] rule_knowledge_viewed: rule_id={identifier}, source=legacy_kb")
            return {"failure_type": key, **value, "source": "legacy_kb", "version": "v1"}

    # Priority 3: Citation-based lookup (evidence.citation fallback)
    if citation:
        normalized_citation = citation.upper().replace("-", "_").replace(" ", "_")
        for key, value in kb.items():
            if key.upper().replace("-", "_").replace(" ", "_") == normalized_citation:
                print(f"[TELEMETRY] rule_knowledge_viewed: rule_id={identifier}, citation={citation}, source=legacy_kb_citation")
                return {"failure_type": key, **value, "source": "legacy_kb", "version": "v1"}

        # Also try matching citation against each entry's "citation" field
        for key, value in kb.items():
            entry_citation = str(value.get("citation", "")).upper().replace("-", "_").replace(" ", "_")
            if entry_citation == normalized_citation:
                print(f"[TELEMETRY] rule_knowledge_viewed: rule_id={identifier}, citation={citation}, source=legacy_kb_field")
                return {"failure_type": key, **value, "source": "legacy_kb", "version": "v1"}

    # Telemetry: signature missing
    print(f"[TELEMETRY] failure_atlas_knowledge_lookup_failed: rule_id={identifier}, citation={citation}")
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
from failure_atlas.repository import FailureAtlasRepository
from failure_atlas.ai_assistant import (
    should_use_ai, build_context, AIResponse, validate_response,
    FeedbackStore, ResolutionCapture,
)


@app.get("/failures/{failure_id}/run")
def get_failure_run_id(failure_id: str):
    """Resolve a failure ID to its associated run_id.
    Bridge for Failure Atlas → InvestigationLayer integration.
    """
    repo = FailureAtlasRepository()
    try:
        entry = repo.get_failure_by_id(failure_id) if failure_id else None
        if entry and entry.get("run_id"):
            return {"run_id": entry["run_id"]}

        entries = repo.search_entries(limit=1, offset=0)
        if entries and entries[0].get("run_id"):
            return {"run_id": entries[0]["run_id"], "note": "fallback to most recent occurrence"}

        return {"run_id": None, "detail": "No associated run found for this failure"}
    finally:
        repo.close()


@app.get("/failure-atlas")
def get_failure_atlas_incidents(
    limit: int = Query(100, ge=1, le=1000),
    offset: int = Query(0, ge=0),
    severity: str = Query(None),
    failure_type: str = Query(None),
):
    repo = FailureAtlasRepository()
    try:
        entries = repo.search_entries(
            severity=severity,
            failure_type=failure_type,
            limit=limit,
            offset=offset,
        )
        total = repo.count_entries(failure_type=failure_type)
        return {"total": total, "limit": limit, "offset": offset, "results": entries}
    finally:
        repo.close()

@app.get("/failures/correlation/{failure_type}")
def get_failure_correlation(failure_type: str):
    return get_correlation_data(failure_type)

@app.get("/analytics/coverage")
def get_coverage_analytics():
    return get_coverage_data()

@app.post("/telemetry/event")
def record_event(payload: dict):
    """Persist telemetry events to community_telemetry.

    Validates payload, classifies event, records to database.
    Never stores RTL, netlists, GDS, DEF, LEF, or source code.
    """
    import logging
    log = logging.getLogger(__name__)

    event = payload.get("event", "")
    if not event:
        raise HTTPException(status_code=400, detail="event field is required")

    allowed_events = {
        "escalation_created", "escalation_sent", "escalation_resolved",
        "knowledge_created", "signature_created",
        "unknown_failure_detected", "ai_investigation_run",
        "failure_atlas_miss", "dashboard_view",
    }
    if event not in allowed_events:
        log.warning(f"Ignoring unrecognized telemetry event: {event}")
        return {"status": "ok", "warning": "unrecognized event type"}

    details = payload.get("details", {}) or {}
    safe_keys = {"signature", "error_class", "confidence", "severity",
                  "stage", "tool", "failure_type", "frequency",
                  "ai_helpfulness", "resolution_outcome"}
    sanitized = {k: v for k, v in details.items() if k in safe_keys}

    from failure_atlas.community_intelligence import EscalationTelemetry
    telemetry = EscalationTelemetry()
    try:
        telemetry.record(
            event=event,
            escalation_id=payload.get("escalation_id", ""),
            failure_type=payload.get("failure_type", ""),
            tool=payload.get("tool", ""),
            atlas_id=payload.get("atlas_id", ""),
            details=sanitized,
        )
        log.info(f"Telemetry recorded: event={event}")
    except Exception as e:
        log.error(f"Telemetry ingestion failed: {e}")
        raise HTTPException(status_code=500, detail=f"Telemetry ingestion failed: {e}")

    return {"status": "ok"}


# ====================================================
# AI INVESTIGATION ASSISTANT ENDPOINTS
# ====================================================

@app.get("/ai/trigger")
def get_ai_trigger(
    failure_type: str = Query(""),
    signature: str = Query(""),
    severity: str = Query("MEDIUM"),
    confidence: float = Query(0.0),
    run_id: str = Query(""),
):
    trigger = should_use_ai(
        failure_type=failure_type,
        signature=signature,
        severity=severity,
        confidence=confidence,
        run_id=run_id or None,
    )
    return dataclasses.asdict(trigger)


@app.post("/ai/investigate")
def ai_investigate(payload: dict):
    """Generate AI investigation guidance for a failure.

    The endpoint:
    1. Checks trigger conditions
    2. Builds context package
    3. Returns heuristic fallback guidance
    (Future: plug in LLM provider)
    """
    failure_type = payload.get("failure_type", "UNKNOWN")
    signature = payload.get("signature", "")
    severity = payload.get("severity", "MEDIUM")
    confidence = payload.get("confidence", 0.0)
    tool = payload.get("tool", "")
    stage = payload.get("stage", "")
    error_text = payload.get("error_text", "")
    log_snippet = payload.get("log_snippet", "")
    metrics = payload.get("metrics", {})
    design_metadata = payload.get("design_metadata", {})
    run_metadata = payload.get("run_metadata", {})
    known_evidence = payload.get("known_evidence", {})

    trigger = should_use_ai(
        failure_type=failure_type,
        signature=signature,
        severity=severity,
        confidence=confidence,
    )

    if trigger.use_ai:
        _capture_unknown_failure(
            tool=tool,
            failure_type=failure_type,
            signature=signature,
            severity=severity,
            confidence=confidence,
            stage=stage,
            source="ai_investigate",
        )

    context = build_context(
        tool=tool,
        stage=stage,
        error_text=error_text,
        log_snippet=log_snippet,
        failure_type=failure_type,
        metrics=metrics,
        design_metadata=design_metadata,
        run_metadata=run_metadata,
        known_evidence=known_evidence,
    )

    response = AIResponse.heuristic_fallback(context.to_dict())
    errors = validate_response(response.to_dict())

    return {
        "trigger": dataclasses.asdict(trigger),
        "context": context.to_dict(),
        "response": response.to_dict(),
        "validation_errors": errors,
    }


@app.get("/ai/investigate/failure")
def ai_investigate_failure(
    failure_id: str = Query(""),
    run_id: str = Query(""),
):
    """Investigate a specific failure from the database."""
    repo = FailureAtlasRepository()
    try:
        entry = repo.get_failure_by_id(failure_id) if failure_id else None
        if not entry and run_id:
            entries = repo.get_failures_for_run(run_id)
            if entries:
                entry = entries[0]

        if not entry:
            raise HTTPException(status_code=404, detail="Failure not found")

        ev = {}
        if isinstance(entry.get("evidence"), str):
            try:
                ev = json.loads(entry["evidence"])
            except (json.JSONDecodeError, TypeError):
                pass
        elif isinstance(entry.get("evidence"), dict):
            ev = entry["evidence"]

        failure_type = entry.get("failure_type", "UNKNOWN")
        signature = entry.get("signature", "")
        severity = entry.get("severity", "MEDIUM")
        confidence = entry.get("confidence", 0.0)

        trigger = should_use_ai(
            failure_type=failure_type,
            signature=signature,
            severity=severity,
            confidence=confidence,
            run_id=run_id or entry.get("run_id"),
            repo=repo,
        )

        if trigger.use_ai:
            _capture_unknown_failure(
                tool=ev.get("tool", entry.get("tool_name", "")),
                failure_type=failure_type,
                signature=signature,
                severity=severity,
                confidence=confidence,
                stage=ev.get("stage", entry.get("tool_stage", "")),
                source="ai_investigate_failure",
                run_id=run_id or entry.get("run_id"),
            )

        context = build_context(
            tool=ev.get("tool", entry.get("tool_name", "")),
            stage=ev.get("stage", entry.get("tool_stage", "")),
            error_text=entry.get("description", ""),
            failure_type=failure_type,
            metrics=ev.get("metrics", {}),
            known_evidence=ev,
        )

        response = AIResponse.heuristic_fallback(context.to_dict())
        errors = validate_response(response.to_dict())

        return {
            "failure": entry,
            "trigger": dataclasses.asdict(trigger),
            "context": context.to_dict(),
            "response": response.to_dict(),
            "validation_errors": errors,
        }
    finally:
        repo.close()


@app.post("/ai/feedback")
def record_ai_feedback(payload: dict):
    """Record user feedback on AI investigation guidance."""
    investigation_id = payload.get("investigation_id", "")
    feedback_type = payload.get("feedback_type", "")
    resolved = payload.get("resolved", False)
    comment = payload.get("comment", "")
    run_id = payload.get("run_id", "")
    failure_type = payload.get("failure_type", "")

    if not investigation_id or not feedback_type:
        raise HTTPException(status_code=400, detail="investigation_id and feedback_type are required")

    allowed = {"helpful", "not_helpful", "resolved", "did_not_resolve"}
    if feedback_type not in allowed:
        raise HTTPException(status_code=400, detail=f"feedback_type must be one of {allowed}")

    store = FeedbackStore()
    try:
        entry_id = store.record_feedback(
            investigation_id=investigation_id,
            feedback_type=feedback_type,
            resolved=resolved,
            comment=comment,
            run_id=run_id,
            failure_type=failure_type,
        )
        return {"status": "ok", "feedback_id": entry_id}
    finally:
        pass


@app.get("/ai/feedback/{investigation_id}")
def get_ai_feedback(investigation_id: str):
    store = FeedbackStore()
    try:
        return store.get_feedback_for_investigation(investigation_id)
    finally:
        pass


@app.get("/ai/feedback-summary")
def get_ai_feedback_summary(failure_type: str = Query("")):
    store = FeedbackStore()
    try:
        return store.get_feedback_summary(failure_type=failure_type or None)
    finally:
        pass


@app.post("/ai/resolution")
def record_ai_resolution(payload: dict):
    """Capture a resolution that was guided by the AI assistant."""
    investigation_id = payload.get("investigation_id", "")
    failure_type = payload.get("failure_type", "")
    tool = payload.get("tool", "")
    fix_description = payload.get("fix_description", "")
    resolution_outcome = payload.get("resolution_outcome", "")
    stage = payload.get("stage", "")
    design_name = payload.get("design_name", "")
    pdk = payload.get("pdk", "")
    metrics_before = payload.get("metrics_before", {})
    metrics_after = payload.get("metrics_after", {})

    if not investigation_id or not failure_type or not fix_description:
        raise HTTPException(status_code=400, detail="investigation_id, failure_type, and fix_description are required")

    capture = ResolutionCapture()
    try:
        entry_id = capture.record_resolution(
            investigation_id=investigation_id,
            failure_type=failure_type,
            tool=tool,
            fix_description=fix_description,
            resolution_outcome=resolution_outcome,
            stage=stage,
            design_name=design_name,
            pdk=pdk,
            metrics_before=metrics_before,
            metrics_after=metrics_after,
        )
        return {"status": "ok", "capture_id": entry_id}
    finally:
        pass


@app.get("/ai/resolutions")
def get_ai_resolutions(failure_type: str = Query(""), limit: int = Query(20, ge=1, le=100)):
    capture = ResolutionCapture()
    try:
        return {
            "results": capture.get_captured_resolutions(
                failure_type=failure_type or None,
                limit=limit,
            ),
            "total": capture.get_resolution_count(),
        }
    finally:
        pass


# ── Pipeline Helpers ──

def _capture_unknown_failure(
    tool: str,
    failure_type: str,
    signature: str = "",
    severity: str = "MEDIUM",
    confidence: float = 0.0,
    stage: str = "",
    source: str = "unknown",
    run_id: str = "",
):
    """Auto-capture an unknown failure into dataset + telemetry.

    Called when the Failure Atlas cannot classify a failure
    (use_ai=True from should_use_ai). Does NOT store RTL, GDS,
    netlists, DEF, LEF, or source code — only signatures/metadata.
    """
    import logging
    _log = logging.getLogger(__name__)

    from failure_atlas.community_intelligence import (
        EscalationTelemetry,
        UnknownFailureDataset,
    )

    try:
        dataset = UnknownFailureDataset()
        dataset.record_unknown_failure(
            tool=tool,
            failure_type=failure_type,
            signature=signature,
        )
    except Exception as e:
        _log.warning(f"Unknown failure dataset capture failed: {e}")

    try:
        telemetry = EscalationTelemetry()
        telemetry.record(
            event="failure_atlas_miss",
            failure_type=failure_type,
            tool=tool,
            details={
                "signature": signature,
                "severity": severity,
                "confidence": confidence,
                "stage": stage,
                "source": source,
                "error_class": failure_type,
            },
        )
        _log.info(
            f"Unknown failure captured: tool={tool} "
            f"failure_type={failure_type} source={source}"
        )
    except Exception as e:
        _log.warning(f"Telemetry record failed for unknown failure: {e}")


# ── Community Intelligence API ─────────────────────────────────────────────

@app.post("/community/escalate")
def create_community_escalation(payload: dict):
    """Create and submit a community escalation."""
    from failure_atlas.community_intelligence import EscalationManager, FailurePackageBuilder

    failure_type = payload.get("failure_type", "UNKNOWN")
    tool = payload.get("tool", "")
    stage = payload.get("stage", "")
    run_id = payload.get("run_id", "")
    user_notes = payload.get("notes", "")
    consent_given = payload.get("consent", False)
    error_text = payload.get("error_text", "")

    if not consent_given:
        raise HTTPException(status_code=400, detail="Consent is required to escalate")

    builder = FailurePackageBuilder(
        failure_type=failure_type,
        tool=tool,
        stage=stage,
        error_text=error_text,
    )
    pkg = builder.build()

    mgr = EscalationManager()
    try:
        escalation_id = mgr.create_escalation(
            run_id=run_id,
            failure_type=failure_type,
            tool=tool,
            stage=stage,
            user_notes=user_notes,
            consent_given=consent_given,
        )

        # Phase 3: Record telemetry event for escalation
        from failure_atlas.community_intelligence import EscalationTelemetry, UnknownFailureDataset
        import logging
        _log = logging.getLogger(__name__)
        try:
            telemetry = EscalationTelemetry()
            telemetry.record(
                event="escalation_created",
                escalation_id=escalation_id,
                failure_type=failure_type,
                tool=tool,
                details={"stage": stage, "consent_given": consent_given},
            )
        except Exception as e:
            _log.warning(f"Failed to record escalation telemetry: {e}")

        # Phase 2: Record in unknown failure dataset
        try:
            dataset = UnknownFailureDataset()
            dataset.record_unknown_failure(
                tool=tool,
                failure_type=failure_type,
                consent_given=consent_given,
                escalation_id=escalation_id,
            )
        except Exception as e:
            _log.warning(f"Failed to record unknown failure: {e}")

        return {
            "id": escalation_id,
            "status": "created",
            "failure_type": failure_type,
            "tool": tool,
            "stage": stage,
            "consent_given": consent_given,
            "created_at": datetime.now().isoformat(),
        }
    finally:
        mgr.close()


@app.get("/community/escalations")
def get_community_escalations(
    status: str = Query(""),
    limit: int = Query(50, ge=1, le=200),
):
    """List community escalations."""
    from failure_atlas.community_intelligence import EscalationManager
    mgr = EscalationManager()
    try:
        records = mgr.list_escalations(status=status or None, limit=limit)
        return {"results": records, "total": len(records)}
    finally:
        mgr.close()


@app.get("/community/escalation/{escalation_id}")
def get_community_escalation(escalation_id: str):
    """Get a specific escalation."""
    from failure_atlas.community_intelligence import EscalationManager
    mgr = EscalationManager()
    try:
        record = mgr.get_escalation(escalation_id)
        if not record:
            raise HTTPException(status_code=404, detail="Escalation not found")
        return record.to_dict() if hasattr(record, "to_dict") else {
            "id": record.id,
            "failure_type": record.failure_type,
            "tool": record.tool,
            "stage": record.stage,
            "status": record.status,
            "consent_given": record.consent_given,
            "user_notes": record.user_notes,
            "engineer_response": record.engineer_response,
            "bharatcode_submission_id": record.bharatcode_submission_id,
            "created_at": record.created_at,
            "sent_at": record.sent_at,
            "resolved_at": record.resolved_at,
        }
    finally:
        mgr.close()


@app.post("/community/escalation/{escalation_id}/response")
def record_community_response(escalation_id: str, payload: dict):
    """Record an engineer response for an escalation."""
    from failure_atlas.community_intelligence import EscalationManager
    mgr = EscalationManager()
    try:
        success = mgr.record_engineer_response(
            escalation_id=escalation_id,
            response_data=payload.get("response", {}),
        )
        if not success:
            raise HTTPException(status_code=404, detail="Escalation not found")
        return {"status": "ok", "escalation_id": escalation_id}
    finally:
        mgr.close()


@app.get("/community/stats")
def get_community_stats():
    """Get community intelligence statistics."""
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute("SELECT COUNT(*) FROM community_escalations")
        total = cursor.fetchone()[0]

        cursor.execute("SELECT COUNT(*) FROM community_escalations WHERE status='open'")
        open_count = cursor.fetchone()[0]

        cursor.execute("SELECT COUNT(*) FROM community_escalations WHERE engineer_response != '{}' AND engineer_response != ''")
        responded = cursor.fetchone()[0]

        cursor.execute("SELECT COUNT(*) FROM community_telemetry")
        telemetry_count = cursor.fetchone()[0]

        cursor.execute("SELECT COUNT(*) FROM community_unknown_dataset")
        dataset_count = cursor.fetchone()[0]

        cursor.execute("SELECT failure_type, frequency FROM community_unknown_dataset ORDER BY frequency DESC LIMIT 5")
        top_unknowns = [{"failure_type": r[0], "frequency": r[1]} for r in cursor.fetchall()]

        return {
            "total_escalations": total,
            "open_escalations": open_count,
            "responded_escalations": responded,
            "telemetry_events": telemetry_count,
            "dataset_entries": dataset_count,
            "top_unknown_failures": top_unknowns,
        }
    finally:
        conn.close()


@app.get("/community/dataset")
def get_community_dataset(
    limit: int = Query(50, ge=1, le=200),
    min_frequency: int = Query(1, ge=1),
):
    """Get unknown failure dataset entries."""
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            "SELECT tool, failure_type, signature, frequency, ai_helpfulness, resolution_outcome, last_seen "
            "FROM community_unknown_dataset WHERE frequency >= ? ORDER BY frequency DESC LIMIT ?",
            (min_frequency, limit),
        )
        rows = cursor.fetchall()
        results = [
            {
                "tool": r[0],
                "failure_type": r[1],
                "signature": r[2],
                "frequency": r[3],
                "ai_helpfulness": r[4],
                "resolution_outcome": r[5],
                "last_seen": r[6],
            }
            for r in rows
        ]
        return {"results": results, "total": len(results)}
    finally:
        conn.close()


@app.get("/community/knowledge-gaps")
def get_community_knowledge_gaps(limit: int = Query(20, ge=1, le=100)):
    """Identify knowledge gaps: high-frequency failures with no resolved outcome."""
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute("""
            SELECT tool, failure_type, signature, frequency, ai_helpfulness
            FROM community_unknown_dataset
            WHERE resolution_outcome = '' OR resolution_outcome IS NULL
            ORDER BY frequency DESC
            LIMIT ?
        """, (limit,))
        rows = cursor.fetchall()
        results = [
            {
                "tool": r[0],
                "failure_type": r[1],
                "signature": r[2],
                "frequency": r[3],
                "ai_helpfulness": r[4],
            }
            for r in rows
        ]
        return {"gaps": results, "total": len(results)}
    finally:
        conn.close()


@app.get("/runs/{run_id}/investigation")
def get_run_investigation(run_id: str):
    """Get the investigation result for a run, including history and failed attempts."""
    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute(
            """SELECT llm_investigation_available, llm_investigation_status,
               llm_investigation_summary, llm_investigation_timestamp,
               llm_investigation_failed_attempts
               FROM runs WHERE run_id = ?""",
            (run_id,),
        )
        row = cursor.fetchone()
        if row is None:
            raise HTTPException(status_code=404, detail="Run not found")

        result = {
            "available": bool(row[0]),
            "status": row[1],
            "summary": row[2],
            "timestamp": row[3],
        }

        try:
            if row[4]:
                failed = json.loads(row[4])
                result["failed_attempts"] = failed.get("attempts", [])
            else:
                result["failed_attempts"] = []
        except (json.JSONDecodeError, TypeError):
            result["failed_attempts"] = []

        run_dir = _OUTPUTS_DIR / run_id
        investigation_path = run_dir / "investigation.json"
        if investigation_path.exists():
            try:
                raw = json.loads(investigation_path.read_text())
                result["investigation"] = raw.get("investigation", raw)
                result["file_status"] = raw.get("status")
            except (json.JSONDecodeError, OSError):
                pass

        from gli_flow.investigation.investigator import InvestigationLayer
        layer = InvestigationLayer(run_dir=str(run_dir), run_id=run_id)
        result["history"] = layer.get_investigation_history()
        result["has_backup"] = layer._backup_path().exists()
        return result
    finally:
        conn.close()


@app.post("/runs/{run_id}/investigation")
def trigger_run_investigation(run_id: str):
    """Trigger an LLM investigation for a run.

    Builds compact context, calls BharatCode, validates output,
    saves investigation.json, and updates the database.

    Hardened: preserves existing successful investigations on failure,
    maintains history, creates backups, validates API key before attempting.
    """
    from gli_flow.investigation import InvestigationLayer

    conn = get_connection()
    try:
        cursor = conn.cursor()
        cursor.execute("SELECT run_dir FROM runs WHERE run_id = ?", (run_id,))
        row = cursor.fetchone()
        if row is None:
            raise HTTPException(status_code=404, detail="Run not found")
        run_dir = row[0]
        if not run_dir or not Path(run_dir).exists():
            run_dir = str(_OUTPUTS_DIR / run_id)
        if not Path(run_dir).exists():
            raise HTTPException(status_code=400, detail="Run directory not found")
    finally:
        conn.close()

    layer = InvestigationLayer(run_dir=run_dir, run_id=run_id)

    preflight_error = layer.preflight_check()
    if preflight_error:
        raise HTTPException(status_code=400, detail=preflight_error)

    if not layer.is_available():
        raise HTTPException(status_code=503, detail="Investigation unavailable: BHARATCODE_API_KEY not set or feature disabled")

    result = layer.investigate()
    saved_path = layer.save_investigation(result)

    summary = ""
    if result.payload and result.payload.get("summary"):
        summary = result.payload["summary"]

    failed_attempts_json = None
    if not result.is_success():
        failed_attempts = layer.get_failed_attempts()
        failed_attempts_json = json.dumps({"attempts": failed_attempts})

    db = DatabaseManager()
    try:
        db.update_run_investigation(
            run_id=run_id,
            available=result.is_success(),
            status=result.status,
            summary=summary,
            timestamp=datetime.now().isoformat(),
            failed_attempts=failed_attempts_json,
        )
    finally:
        db.close()

    return {
        "status": result.status,
        "provider": result.provider,
        "model": result.model,
        "latency_sec": result.latency_sec,
        "error": result.error,
        "investigation": result.payload,
        "preserved_existing": not result.is_success() and layer.has_successful_investigation(),
    }


_dashboard_dist = str(Path(__file__).resolve().parent.parent / "dashboard" / "dist")
if os.path.isdir(_dashboard_dist):
    app.mount("/", StaticFiles(directory=_dashboard_dist, html=True), name="dashboard")


if __name__ == "__main__":
    import uvicorn
    port = int(os.environ.get("PORT", "8000"))
    uvicorn.run("backend.server:app", host="127.0.0.1", port=port, reload=True)

