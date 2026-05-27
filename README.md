# GLI-FLOW

RTL-to-GDS execution orchestration and observability for OpenROAD / ORFS.

## What It Does

`gli-flow run <design_dir>` reads a manifest, invokes Yosys + OpenROAD via the ORFS Makefile, collects timing/power/area metrics from the tool output, computes a QoR score, detects regressions against previous runs, and persists everything to SQLite.

## Status

- **65% complete toward production MVP**
- Core pipeline (run → GDS → metrics → DB) works end-to-end for `sky130hd`
- 7 of 9 pipeline stages are scaffolding (log progress only)
- Dashboard: 6 of 11 panels show real data; 5 are hardcoded UI placeholders
- Failure Atlas: JSON entries exist, but zero consuming functions work (schema mismatch)
- No automated tests

## Requirements

- Linux or WSL2
- Python ≥ 3.9
- OpenROAD-flow-scripts (ORFS) installed locally
- PDK_ROOT pointing to a sky130 PDK (volare-managed)
- OpenROAD binary, Yosys, KLayout in PATH

## Quick Start

```bash
git clone <repo>
cd gli-flow
pip install -e .

export PDK_ROOT=/path/to/pdk
gli-flow run examples/counter
```

This produces GDS, DEF, timing/power reports, telemetry JSON, artifact manifest, and reproducibility manifest in `outputs/runs/<run_id>/`.

## Project Structure

| Directory | Purpose |
|---|---|
| `gli_flow/` | Core package — orchestrator, backends, CLI, analytics, database, runtime |
| `examples/` | Example designs with `gli_manifest.yaml` |
| `backend/` | FastAPI server (serves run data to dashboard) |
| `dashboard/` | React + Vite frontend (polling, 2s interval) |
| `telemetry/` | Report parsers (CSV, .rpt, metrics.rpt) |
| `provenance/` | Reproducibility manifest with SHA256 hashing |
| `regression/` | Baseline comparison against historical runs |
| `failure_atlas/` | Failure signatures JSON (integration not yet functional) |
| `analytics/` | Standalone analysis scripts (some duplicate `gli_flow/analytics/`) |

## Architecture

```
CLI → FlowOrchestrator → OpenRoadAdapter → subprocess(make) → ORFS
                                                        ↓
                                              Reports (GDS, DEF, .rpt)
                                                        ↓
                                              TelemetryParser → metrics.csv
                                                        ↓
                                              QoR scoring → SQLite → FastAPI → React
```

## Working Features

- RTL-to-GDS via OpenROAD (sky130hd, tested with 8-bit counter)
- Real metric extraction from OpenROAD reports (WNS, TNS, fmax, power, violations, area, utilization, cell count)
- QoR scoring from extracted metrics
- SQLite database for historical run storage
- CLI: `run`, `history`, `status` commands
- Reproducibility manifest with SHA256 hashes, tool versions, system fingerprint
- Artifact collection (GDS, DEF, logs, reports) with manifest
- Backend API (FastAPI, 3 endpoints, no mocked data)
- Dashboard with 6 real-data panels + 5 hardcoded placeholders
- Regression detection (3 metrics vs baseline, threshold-based)
- Dual backend: OpenRoadAdapter (working) and LibreLaneAdapter (real subprocess, target may not be installed)

## Known Limitations

- **ORFS path hardcoded** in `openroad_adapter.py` — must edit for other machines
- **Failure Atlas consumers broken** — all 10+ consumers have wrong key names
- **No tests** — zero test files
- **Duplicate code** — top-level `analytics/`, `telemetry/`, `regression/` directories duplicate code in `gli_flow/`
- **Silent parse failures** — report parser silently returns `None` on format changes
- **QoR score of 1.0 when no data** — no metrics → perfect score (design choice, not a bug)
- **Database schema mismatch** — `backend/server.py` vs `gli_flow/database/sqlite.py` use different defaults
- **Dashboard error state invisible** — API failure not shown to user
- **`toolchain` column not persisted** — field exists in model, missing from DB insert
- **Only sky130hd tested** — no other PDKs verified
- **No CI/CD**, no containerized deployment

## License

Apache 2.0
