# GLI-FLOW

RTL-to-GDS execution orchestration and observability for OpenROAD / ORFS.

## What It Does

GLI-FLOW is an execution orchestration tool for the OpenROAD flow. It reads a design manifest, invokes Yosys + OpenROAD, collects timing/power/area metrics, computes QoR scores, detects regressions against previous runs, and persists results to an SQLite database. A FastAPI backend provides a dashboard to visualize runs, trends, and failures via the Failure Atlas.

## Installation

```bash
# Clone the repository
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow

# Install in editable mode
pip install -e .

# Verify installation
gli-flow doctor
```

## Quick Start

```bash
# Interactive setup wizard
gli-flow quickstart

# Run a design in mock mode
gli-flow run examples/counter --mock
```

## Key CLI Commands

| Command | Description |
|---------|-------------|
| `gli-flow run` | Run a design through the full RTL-to-GDS pipeline |
| `gli-flow dashboard` | Launch the dashboard |
| `gli-flow diagnose` | Diagnose a failed run by scanning stage logs |
| `gli-flow doctor` | Validate system and EDA toolchain |
| `gli-flow history` | Show execution history |
| `gli-flow status` | Show recent run status |

For a full list of commands, see `docs/reference/cli_reference.md`.

## Dashboard

The dashboard provides a visual interface to manage your designs, monitor runs, and analyze failures.

```bash
# Start API server
python -m uvicorn backend.server:app --port 8000

# Start dashboard dev server
cd dashboard && npm run dev
```

## Architecture

```
CLI -> FlowOrchestrator -> OpenRoadAdapter -> subprocess(make) -> ORFS
                                                         |
                                               Reports (GDS, DEF, .rpt)
                                                         |
                                               TelemetryParser -> SQLite
                                                         |
                                               FastAPI -> React Dashboard
```

## Supported PDKs

- `sky130` (sky130A, sky130hd)
- `gf180mcu` (defined, not verified)

## License

Apache 2.0
