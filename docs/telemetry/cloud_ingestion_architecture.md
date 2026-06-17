# Cloud Ingestion Platform — Architecture

## Overview

Privacy-safe ingestion pipeline for telemetry and Failure Atlas data.
Routes: `EDA Flow → Client Library → HTTPS → Ingestion Server → PostgreSQL`.

## Components

### Client Side (`gli_flow/telemetry/`)

| Module | File | Role |
|---|---|---|
| `TelemetryUploader` | `uploader.py` | Exports, sanitizes, uploads via httpx; falls back to queue |
| `UploadQueue` | `upload_queue.py` | SQLite-backed persistent queue (`~/.gli-flow/upload_queue.db`) |
| `RetryEngine` | `retry_engine.py` | Exponential backoff: 30s×2^n, 1h cap, ±25% jitter, max 10 retries |
| `FailureAtlasUploader` | `failure_atlas_uploader.py` | Sanitizes FA entries, uploads or queues |
| `PrivacyValidator` | `export.py` | Field-level substring matching; blocks RTL, netlists, paths, instances |

### Server Side (`cloud_ingestion/`)

| Module | File | Role |
|---|---|---|
| `CloudIngestionConfig` | `config.py` | YAML + env var config (`GLI_SERVER_URL`, `GLI_API_KEY`, `GLI_DATABASE_URL`) |
| `IngestionDatabase` | `database.py` | SQLite/PostgreSQL — telemetry_events, failure_atlas_events, upload_audit, consent_records |
| `CloudIngestionServer` | `server.py` | FastAPI app: `POST /api/v1/telemetry`, `GET /api/v1/health`, `GET /api/v1/stats` |

## Data Flow

```
Run Complete
    │
    ▼
TelemetryUploader.upload_run_telemetry(run_id)
    │
    ├── TelemetryExporter.export_to_json()  → query DB
    ├── PrivacyValidator.sanitize_dict()    → strip sensitive fields
    │
    ├── httpx POST /api/v1/telemetry        → direct upload
    │     ├── Success → audit log
    │     └── Failure → UploadQueue.enqueue()
    │
    └── UploadQueue persists to SQLite
          └── RetryEngine.process_queue()   → exponential backoff
```

## Endpoints

| Method | Path | Auth | Description |
|---|---|---|---|
| POST | `/api/v1/telemetry` | X-API-Key | Ingest telemetry events + FA entries |
| GET | `/api/v1/health` | None | Health check |
| GET | `/api/v1/stats` | X-API-Key | Ingestion statistics |

## Privacy Hardening

- **Substring matching**: `"rtl_source"` matches `"rtl"`, `"source_code"` matches `"source"`
- **Extension blocking**: `.v`, `.sv`, `.vh`, `.gds`, `.def`, `.lef`, `.bit`, `.bin`
- **Path redaction**: `/path/to/file` → `[PATH REDACTED]`
- **Instance redaction**: `U1/and2_1` → `[INSTANCE REDACTED]`

## Retry Policy

| Retry | Delay (approx) |
|---|---|
| 0 | 30s ±25% |
| 1 | 60s ±25% |
| 2 | 120s ±25% |
| 3 | 240s ±25% |
| 4 | 480s ±25% |
| 5 | 960s ±25% |
| 6 | 1920s ±25% |
| 7+ | 3600s (capped) |

Max retries: 10. After exhaustion, item stays in queue with `max retries exceeded`.

## Configuration

```yaml
# configs/cloud_ingestion.yaml
server:
  host: "0.0.0.0"
  port: 8100
database:
  url: "sqlite:///tmp/cloud_ingestion_dev.db"   # or postgresql://user:pass@host/db
auth:
  api_key: "${GLI_API_KEY:-dev-key-change-in-production}"
```

Env overrides: `GLI_SERVER_URL`, `GLI_API_KEY`, `GLI_DATABASE_URL`.

## Deployment

```bash
# Start server (dev)
python -m cloud_ingestion.server

# Start server (prod with uvicorn)
uvicorn cloud_ingestion.server:create_app --host 0.0.0.0 --port 8100 --workers 4

# Run validation
python scripts/validate_cloud_ingestion.py

# Run scale test
python scripts/scale_test_cloud_ingestion.py
```
