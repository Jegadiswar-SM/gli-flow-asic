# Important Runs Feature: Architecture Audit

## Executive Summary

The "Important Run" feature aims to collect high-fidelity human-preference signals for training future Execution Intelligence, Failure Atlas, and QoR models. It must integrate seamlessly into the existing GLI-FLOW architecture without introducing separate bookmarking databases, local storage, or disconnected telemetry.

## Existing Architecture Analysis

### Run Metadata Storage
- **Primary Database**: `gli_flow.db` (SQLite).
- **Key Table**: `runs` (stores `run_id`, `design_name`, `status`, `current_stage`, `progress`, `wns`, `tns`, `utilization`, `runtime_sec`, `cell_count`, `qor_score`, `timestamp`).
- **Access**: Managed via `backend/server.py` using `sqlite3` and `FastAPI`.

### User Preference Mechanisms
- **Current State**: Limited. The `failure_atlas_entries` table tracks `fix_applied`, `fix_type`, `resolution_confidence`, which acts as a proxy for successful resolution signals.
- **Bookmark/Preference System**: None exists for general runs.

### Telemetry Collection Paths
- **Mechanism**: Run-specific telemetry is collected as JSON files within `{run_dir}/telemetry/`.
- **Infrastructure**: Managed by `telemetry/telemetry_manager.py`.

## Important Runs Feature Proposal

To fulfill the requirements, we propose the following changes:

### Phase 2: Database Support
Extend the `runs` table to include:
- `is_important` (BOOLEAN, default: FALSE)
- `important_marked_at` (TIMESTAMP, NULL)
- `important_source` (TEXT, NULL) - To track the origin of the signal if not a direct user click (e.g., automated heuristics).

### Phase 3 & 4: Dashboard & UI
- **Backend API**: Add `PATCH /runs/{run_id}/important` endpoint to toggle the `is_important` flag and record telemetry.
- **Frontend**: Add a "star" toggle in `RunsPage.jsx` and `RunDetail.jsx`. Implement a new view "Important Runs" in the sidebar by filtering existing `/runs` results with a query parameter `important=true`.

### Phase 5 & 6: Telemetry Integration
- **Event Capture**: When the "star" is toggled, record an `important_run_marked` event in the existing telemetry infrastructure.
- **Metadata**: Capture `important_run_version`, `selection_context`, `run_rank_signal` as part of the telemetry payload.

### Phase 8 & 9: Analytics Foundation
- **Failure Atlas**: Update failure incident views to check `is_important` status of associated runs from the `runs` table.
- **Aggregation**: Database-level indexing on `is_important` to facilitate future analytical queries (e.g., correlation between QoR metrics and "important" status).
