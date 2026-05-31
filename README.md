# GLI-FLOW

RTL-to-GDS execution orchestration and observability for OpenROAD / ORFS.

## What It Does

`gli-flow run <design_dir>` reads a manifest, invokes Yosys + OpenROAD via the ORFS
Makefile, collects timing/power/area metrics from the tool output, computes a QoR
score, detects regressions against previous runs, and persists everything to SQLite.
A FastAPI backend serves dashboards, run details, images, and reports. DRC/LVS
verification, multi-corner STA, and Failure Atlas pattern matching are wired in.

## Quick Start

```bash
# One-command interactive setup
gli-flow quickstart

# Or manually
export PDK_ROOT=/pdk
export ORFS_ROOT=/path/to/orfs/flow
gli-flow run examples/counter --mock
```

## Commands

| Command | Description |
|---------|-------------|
| `gli-flow quickstart` | Interactive wizard — creates manifest + skeleton RTL |
| `gli-flow init <name>` | Creates a design manifest for an existing RTL project |
| `gli-flow run <dir>` | Run a design through the full RTL-to-GDS pipeline |
| `gli-flow run <dir> --mock` | Run using a mock adapter (no real EDA tools needed) |
| `gli-flow history` | Show execution history |
| `gli-flow status` | Show recent run status |
| `gli-flow report <design>` | Show QoR report from ORFS output files |
| `gli-flow batch <dir1> <dir2> ...` | Run multiple designs in parallel |
| `gli-flow install` | Install EDA toolchain (Yosys, OpenROAD, KLayout, PDK) |
| `gli-flow ci <dir>` | Run a design in CI mode with JUnit/Markdown output |

## Manifest Format

Create a `gli_manifest.yaml` in your design directory:

```yaml
design_name: my_chip
rtl_files:
  - rtl/my_chip.sv
top_module: my_chip
backend: openroad
pdk: sky130
pdk_variant: sky130A
clock_port: clk
clock_period_ns: 10.0
threads: 4
corners:
  - name: typical
    type: typical
    process: typical
    voltage: 1.80
    temperature: 25
```

Generate one with: `gli-flow init my_design`

## Outputs

After a run, results are in `outputs/runs/<run_id>/`:

| Path | Contents |
|------|----------|
| `reports/` | Timing reports, metrics CSV, DRC/LVS results, finish report, images |
| `artifacts/` | GDS, DEF, synthesized Verilog, artifact manifest |
| `telemetry/` | Per-stage telemetry and metrics JSON |
| `logs/` | OpenROAD execution log |
| `config.json` | Full design configuration |
| `reproducibility.json` | SHA256 hashes, tool versions, system fingerprint |
| `drc_lvs_summary.json` | DRC and LVS verification results |
| `sta_corners.json` | Multi-corner STA results |

## Architecture

```
CLI -> FlowOrchestrator -> OpenRoadAdapter -> subprocess(make) -> ORFS
                                                         |
                                               Reports (GDS, DEF, .rpt)
                                                         |
                                               TelemetryParser -> metrics.csv
                                                         |
                                               QoR scoring -> SQLite -> FastAPI -> React Dashboard
```

## Dashboard

Start the backend and frontend:

```bash
# Terminal 1: Start API server
python -m uvicorn backend.server:app --reload --port 8000

# Terminal 2: Start dashboard dev server
cd dashboard && npm run dev
```

The dashboard polls the API every 2 seconds and shows:
- 5 metric cards (total runs, success rate, avg QoR, regressions, unique designs)
- QoR trend chart with 0.70 threshold line
- QoR score breakdown (timing, utilization, cell count, runtime)
- Execution health gauge
- Recent runs table (click a run for detail view with 8 tabs)
- Top releases (from `/releases` API)
- Pipeline capability indicators (from `/health` API)

## System Requirements

- Linux, macOS, or WSL2
- Python >= 3.9
- OpenROAD-flow-scripts (ORFS) installed locally
- PDK pointing to a sky130 or gf180mcu PDK
- 8 GB RAM minimum (16+ recommended for non-trivial designs)

## Supported PDKs

| PDK | Variant | Status |
|-----|---------|--------|
| sky130 | sky130A (sky130hd) | Tested (4x4 systolic, UART, counter, GCD) |
| gf180mcu | — | Defined but not verified |

## Known Limitations

- **DRC/LVS**: Requires Magic >= 8.3.411 for sky130A techfile. Magic 8.3.105 is too old.
  Also requires VLSI netgen (not the FEM mesh generator package).
  DRC/LVS stages gracefully skip when tools are missing.
- **Failure Atlas**: Signature detection requires tool logs in expected format.
  All consumers now use safe `.get()` key access.
- **Multi-corner STA**: Only typical corner tested; slow/fast corners require
  additional PDK liberty files.
- **Dashboard**: Serves static build from `dashboard/dist/` — rebuild after changes.
- **Only sky130hd tested**: GF180MCU defined but not verified.
- **No OpenRAM integration**: `adapters/openram/injector.py` is a stub.
- **Platform paths**: `platform.py` provides path helpers for Linux/macOS/WSL2.

## Testing

```bash
# Run all tests
pytest tests/ -v

# Run with coverage
pytest tests/ --cov=gli_flow --cov-report=term-missing
```

## License

Apache 2.0
