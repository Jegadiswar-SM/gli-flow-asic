# GLI-FLOW

RTL-to-GDS execution orchestration and observability for OpenROAD / ORFS.

## What It Does

GLI-FLOW orchestrates RTL-to-GDS pipelines via OpenROAD, collects timing/power/area metrics, computes QoR scores, detects regressions, identifies failures via the Failure Atlas, and provides AI-assisted investigation. A FastAPI backend powers a React dashboard for visualizing runs, trends, failures, and telemetry.

## Installation

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
pip install -e .
gli-flow doctor
```

See [Installation Guide](docs/setup/installation.md) for detailed steps.

## Quick Start

```bash
gli-flow quickstart
gli-flow run examples/counter --mock
```

## Key CLI Commands

| Command | Description |
|---------|-------------|
| `gli-flow run` | Run a design through the RTL-to-GDS pipeline |
| `gli-flow doctor` | Validate environment and EDA toolchain |
| `gli-flow diagnose` | Diagnose a failed run |
| `gli-flow dashboard` | Launch the dashboard |
| `gli-flow investigate` | LLM-powered failure investigation |
| `gli-flow support-bundle` | Generate debug archive |
| `gli-flow telemetry` | Telemetry operations |

See [CLI Reference](docs/reference/cli_reference.md) for the full command list.

## Dashboard

```bash
gli-flow dashboard     # Starts backend + frontend
gli-flow dashboard --backend-only  # Backend only
```

The dashboard includes 24 pages: Run Matrix, Failure Atlas, QoR Analytics, AI Investigation, Telemetry Transparency Center, Resolution Intelligence, Engineering Dashboard, Beta Dashboard, and more.

See [Dashboard Guide](docs/user_guide/dashboard_guide.md).

## Key Features

- **Flow Orchestration** — RTL-to-GDS via Yosys + OpenROAD, mock mode for testing
- **Failure Atlas** — Track, classify, and resolve design failures
- **AI Investigation** — LLM-powered root cause analysis (BharatCode API)
- **Resolution Intelligence** — Learn fix patterns from historical runs
- **Telemetry** — Consent-based telemetry with LOCAL/FULL/ATLAS/DISABLED modes
- **Community Intelligence** — Escalate unknown failures and discover knowledge gaps
- **Support Bundles** — One-command debug archive generation
- **Dashboard** — Real-time run monitoring, analytics, and management

## Architecture

```
CLI → FlowOrchestrator → OpenRoadAdapter → subprocess(make) → ORFS
                                                      ↓
                                            Reports, GDS, DEF
                                                      ↓
                                            TelemetryParser → SQLite
                                                      ↓
                                            FastAPI → React Dashboard
                                            (Failure Atlas, AI, Analytics,
                                             Resolution Intelligence, Telemetry)
```

## Supported PDKs

- `sky130` (sky130A, sky130hd)
- `gf180mcu` (defined, not verified)

## Repository Structure

```
├── gli_flow/              # Core Python package
├── backend/               # FastAPI server
├── dashboard/             # React dashboard
├── configs/               # Configuration files
├── outputs/               # Generated data (telemetry, execution_history, etc.)
├── scripts/               # Installation and utility scripts
├── docs/                  # Documentation
├── examples/              # Design examples
└── tests/                 # Test suite
```

## License

Apache 2.0
