# GLI-FLOW

Open-source RTL-to-GDS digital design flow — one command from Verilog to GDSII.

GLI-FLOW orchestrates Yosys, OpenROAD, Magic, Netgen, and KLayout through synthesis,
floorplanning, placement, CTS, routing, DRC/LVS, STA, and GDS export. Mock mode
validates your design config in seconds without any EDA tools installed.

## Why GLI-FLOW?

- **One command.** `gli-flow run <design>` runs the complete flow end-to-end.
- **Mock mode.** Develop and validate manifests without the EDA toolchain.
- **Built-in diagnostics.** Automated failure detection, root-cause analysis, and support bundles.
- **Dashboard.** Web UI for run history, timing/area/power, DRC/LVS, and telemetry.
- **Privacy-first.** Default local-only telemetry. RTL, GDS, and netlists are never collected.

## Quick Install

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
python3 -m venv venv
source venv/bin/activate
pip install -e .
```

Python 3.9+. Linux (Ubuntu 22.04+ / Debian 12+ / WSL2). EDA tools are optional.

## Smoke Test

```bash
gli-flow smoke-test
```

Output shows mock-mode readiness, available EDA tools, and optional dependencies.
All mock-mode checks must pass; missing real-flow tools show as warnings, not errors.

## First Run (Mock Mode)

```bash
gli-flow run examples/counter --mock
```

```
  Metric        Value
─────────────────────
  QoR Score     0.6
  WNS           0.05
  TNS           0.0
  Utilization   65.0%
  Cell Count    100
  Runtime       42.0s

✓ Implementation: SUCCESS
✓ Signoff: PASS
```

## Dashboard

```bash
gli-flow dashboard
```

Opens at `http://127.0.0.1:5173`. Use `--backend-only` for API at `http://127.0.0.1:8000`.

## Features

- Full RTL-to-GDS pipeline — synthesis, placement, routing, DRC, LVS, STA
- Mock mode — validate config without tools
- Web dashboard — run history, metrics, telemetry
- Automated failure detection with fix recommendations
- AI-assisted investigation (experimental)
- CI mode with JUnit/Markdown output
- Batch runs, remote SSH execution, cloud storage
- Support bundles for issue reports

## Documentation

| Link | Contents |
|------|----------|
| [Getting Started](docs/user_guide/getting_started.md) | Clone to dashboard in 5 minutes |
| [User Manual](docs/user_guide/user_manual.md) | Install, run, diagnose, telemetry |
| [Dashboard Guide](docs/user_guide/dashboard.md) | Dashboard pages reference |
| [CLI Reference](docs/reference/cli_reference.md) | Every command and flag |
| [Troubleshooting](docs/reference/troubleshooting.md) | Common issues |
| [Telemetry & Privacy](docs/privacy/telemetry_and_privacy.md) | Data handling and consent |

## Current Beta Scope

**Included:**
- Open-source ASIC implementation flow (Yosys + OpenROAD + Magic + KLayout)
- Mock mode for config validation
- Execution observability and Failure Atlas
- Opt-in telemetry collection (RTL/IP never collected)
- Web dashboard

**Not included:**
- Commercial EDA tools (Synopsys, Cadence, Siemens)
- Tapeout certification
- Enterprise collaboration features
- Multi-user cloud platform
- Production signoff guarantees

GLI-FLOW is v1.1.0-beta. Report issues at https://github.com/green-lantern-industries/gli-flow/issues.

## License

Apache 2.0 — see [LICENSE](LICENSE).
