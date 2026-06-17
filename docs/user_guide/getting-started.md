# Getting Started with GLI-FLOW

Welcome to GLI-FLOW! This guide will help you set up and run your first design.

## Prerequisites

- Ubuntu 22.04+ or compatible Linux distribution
- Python 3.9+
- 8GB+ RAM, 10GB+ free disk

## Installation

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
pip install -e .
gli-flow doctor
```

If `gli-flow` is not found:
```bash
export PATH=$PATH:$HOME/.local/bin
```

## First Run (Mock Mode)

Mock mode runs the full pipeline without requiring EDA tools:

```bash
# Run the counter example in mock mode
gli-flow run examples/counter --mock
```

## Quickstart Wizard

```bash
# Interactive wizard to create a new design
gli-flow quickstart
```

## View Results

```bash
# Check run history
gli-flow history

# Launch dashboard
gli-flow dashboard
```

## What's Next?

- Read the [User Manual](user_manual.md) for detailed usage
- Explore the [Dashboard Guide](dashboard_guide.md) for dashboard features
- See the [CLI Reference](../reference/cli_reference.md) for all commands
- Review [Telemetry & Privacy](../privacy/telemetry_and_privacy.md) for data handling
