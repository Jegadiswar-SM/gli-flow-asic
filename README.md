# GLI-FLOW

Turn Verilog into a chip layout — one command.

GLI-FLOW orchestrates the open-source ASIC toolchain (Yosys, OpenROAD, Magic, Netgen, KLayout)
to take your RTL design from Verilog through synthesis, placement, routing, DRC, LVS,
and static timing analysis — all the way to final GDSII.

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
python3 -m venv venv
source venv/bin/activate
pip install -e .
gli-flow doctor
gli-flow run examples/counter --mock
```

**Prerequisites:** Python 3.9+, Linux (Ubuntu 22.04+ / Debian 12+ / WSL2), 8GB+ RAM, 10GB+ disk.  
EDA tools are optional — mock mode runs without them.

## Features

- **One-command ASIC flow** — `gli-flow run <design>` runs the full RTL-to-GDS pipeline
- **Mock mode** — run without any EDA tools. Validates your design config in seconds
- **Dashboard** — visual web interface for run history, timing, area, DRC/LVS, telemetry
- **Telemetry** — opt-in, privacy-safe. Default: local-only. No data leaves your machine without consent
- **Failure detection** — automatic root-cause analysis from run logs
- **Smoke test** — one command validates your entire installation
- **Support bundle** — one command generates a diagnostic archive for issue reports

## Quick Start (with mock mode, no tools needed)

```bash
python3 -m venv venv              # Create a virtual environment (required on modern systems)
source venv/bin/activate           # Activate it
pip install -e .                   # Install GLI-FLOW
gli-flow smoke-test                # Verify installation
gli-flow run examples/counter --mock   # Run first design
gli-flow dashboard                 # Open the web dashboard
```

See [Getting Started](docs/user_guide/getting_started.md) for the full 8-step guide.

## Installation

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
python3 -m venv venv
source venv/bin/activate
pip install -e .
```

If `gli-flow` is not found after install: run `source venv/bin/activate` to activate your virtual environment.

After install, run `gli-flow smoke-test` to verify everything works correctly.

## Documentation

| Document | Purpose |
|----------|---------|
| [Getting Started](docs/user_guide/getting_started.md) | 8-step onboarding — clone to dashboard |
| [User Manual](docs/user_guide/user_manual.md) | Complete reference for all features |
| [CLI Reference](docs/reference/cli_reference.md) | Every command, flag, and argument |
| [Dashboard Guide](docs/user_guide/dashboard.md) | Dashboard pages and features |
| [Troubleshooting](docs/reference/troubleshooting.md) | Common issues and solutions |
| [Telemetry & Privacy](docs/privacy/telemetry_and_privacy.md) | Data handling and consent |
| [Known Limitations](docs/user_guide/KNOWN_LIMITATIONS.md) | What v1.0 does not do |

## Community & Support

- **Issues**: https://github.com/green-lantern-industries/gli-flow/issues
- **Support bundles**: `gli-flow support-bundle`, attach the `.zip` to your issue

## License

Apache 2.0 — see [LICENSE](LICENSE).
