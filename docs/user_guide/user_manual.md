# GLI-FLOW User Manual

This manual provides instructions for using GLI-FLOW to orchestrate RTL-to-GDS pipelines and analyze results.

## 1. Installation

See [Installation Guide](docs/setup/installation.md) for detailed steps.

## 2. First Run

To start a new design or run an example:

```bash
# Interactive wizard to setup a new design
gli-flow quickstart

# Run a design in mock mode (no EDA tools needed)
gli-flow run examples/counter --mock
```

## 3. Dashboard

The dashboard provides a visual interface for managing designs and analyzing results.

```bash
# Launch the dashboard
gli-flow dashboard
```

## 4. Failure Atlas

Failure Atlas tracks failures across runs.

```bash
# Diagnose a failed run
gli-flow diagnose <run_id>
```

## 5. Telemetry & Support Bundles

```bash
# Show telemetry payload
gli-flow show-telemetry <run_id>

# Generate support bundle for troubleshooting
gli-flow support-bundle
```

## 6. Troubleshooting

Run the doctor command to validate your environment:
```bash
gli-flow doctor
```
