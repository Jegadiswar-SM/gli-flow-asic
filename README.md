# GLI-FLOW

RTL-to-GDS execution orchestration and observability for OpenROAD / ORFS.

## What It Does

`gli-flow run <design_dir>` reads a manifest, invokes Yosys + OpenROAD via the ORFS Makefile, collects timing/power/area metrics from the tool output, computes a QoR score, detects regressions against previous runs, and persists everything to SQLite.

## Status

- **~70% complete toward production MVP**
- Core pipeline (run → GDS → metrics → DB) works end-to-end for `sky130hd` on the 4×4 systolic array (98 MHz, 360K µm² die, 61.6 mW total power)
- DRC/LVS not yet wired — most critical remaining gap for tapeout
- 22 automated tests across 6 test modules all passing
- CI pipeline runs lint + pytest + import validation on every push

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
export ORFS_ROOT=/path/to/orfs/flow
gli-flow run examples/counter
```

This produces GDS, DEF, timing/power reports, telemetry JSON, artifact manifest, and reproducibility manifest in `outputs/runs/<run_id>/`.

## Project Structure

| Directory | Purpose |
|---|---|
| `gli_flow/` | Core package — orchestrator, backends, CLI, analytics, database, runtime, PDK, installer, scheduler |
| `examples/` | Example designs: systolic_array_4x4, UART loopback, counter, GCD |
| `backend/` | FastAPI server (serves run data to dashboard) |
| `dashboard/` | React + Vite frontend (polling, 2s interval) |
| `failure_atlas/` | Failure signatures JSON with detection engine (4 of 5 consumers need key fix) |
| `analytics/` | Standalone analysis scripts |
| `tests/` | 22 pytest tests covering orchestrator, QoR, failure detection, provenance, regression, telemetry |
| `configs/` | Default policies, runtime config, and toolchain definitions |
| `environment/` | Tool validation, environment fingerprinting, consistency checks |
| `intelligence/` | Adaptive orchestration, anomaly detection, learning engine, recommendations |

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

- RTL-to-GDS via OpenROAD (sky130hd, tested with 4×4 systolic array and 8-bit counter)
- Real metric extraction from OpenROAD reports (WNS, TNS, Fmax, power, violations, area, utilization, cell count)
- QoR scoring from extracted metrics with per-aspect breakdown (timing, area, density)
- SQLite database for historical run storage and trend analysis
- CLI: `run`, `history`, `status`, `report`, `install`, `batch` commands
- `gli-flow report <design>` — reads ORFS output files directly and displays metrics in a rich terminal table
- Reproducibility manifest with SHA256 hashes, tool versions, system fingerprint
- Artifact collection (GDS, DEF, logs, reports) with manifest
- Backend API (FastAPI, 3 endpoints, no mocked data)
- Dashboard with 6 real-data panels + 3 hardcoded placeholders
- Regression detection (QoR, WNS, utilization vs baseline, threshold-based)
- Dual backend: OpenRoadAdapter (working) and LibreLaneAdapter
- PVT corner management with Sky130 and GF180MCU PDK definitions
- Full installer: Yosys, OpenROAD, KLayout, ORFS, PDK via volare
- Threaded batch job queue with resource-aware local worker
- Failure Atlas with 20 signatures and detection engine (partial — detect_failures.py fixed)
- 22 passing tests covering the entire core pipeline
- GitHub Actions CI: lint + pytest + import chain validation
- 4 example designs: systolic array, UART loopback, counter, GCD
- Environment validation, fingerprinting, and remediation engine
- Execution contracts, governance policies, and release validation
- Dashboard health backend aggregating execution/reliability/regression state
- Snapshot, replay, and reproduction index for archived runs

## Known Limitations

- **DRC/LVS not wired** — Magic and Netgen are not integrated; critical for tapeout
- **Failure Atlas consumers incomplete** — `signature_engine.py`, `recommend_fixes.py`, `index_failures.py`, `analyze_failure_trends.py` still access wrong keys
- **ORFS path configurable** via `ORFS_ROOT` env var or `orfs_root` in `~/.gli-flow/config.json`
- **Only sky130hd tested** — GF180MCU PDK defined but not verified
- **Dashboard panels partially hardcoded** — 6 of 9 panels show real data, 3 are static UI
- **Duplicate code** — top-level `analytics/`, `telemetry/`, `regression/`, `provenance/` directories mirror code in `gli_flow/`
- **No multi-corner signoff** — only typical library available, multi-corner STA would fail
- **Placeholder flow script** — `scripts/run_flow.sh` uses `sleep 1` per stage (not real tools)
- **OpenRAM not integrated** — `adapters/openram/injector.py` returns `not_implemented`

## License

Apache 2.0
