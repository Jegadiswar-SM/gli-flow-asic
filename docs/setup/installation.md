# Installation Guide

Install GLI-FLOW on supported Linux distributions (Ubuntu 22.04+, Debian 12+) and WSL2.

## Prerequisites

- Python 3.9+
- 8GB RAM minimum (16GB+ recommended)
- 10GB free disk space
- `git`, `cmake`, `build-essential`

## Quick Install (pip)

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
pip install -e .
gli-flow doctor
```

## Automated Install (script)

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
bash scripts/install.sh
```

The script validates Python, Docker, Git, LibreLane, and repository structure.

## CLI Install (recommended)

```bash
# Install gli-flow and toolchain dependencies
gli-flow install

# Install with specific PDK
gli-flow install --pdk sky130

# Dry run to preview changes
gli-flow install --dry-run

# Skip ORFS installation if already present
gli-flow install --skip-orfs

# Custom PDK root
gli-flow install --pdk-root /opt/pdk
```

The installer:
1. Installs system dependencies
2. Installs OpenROAD-flow-scripts
3. Installs the selected PDK (default: sky130)
4. Configures environment
5. Reports install status to `~/.gli-flow/install_report.json`

## Manual Installation

```bash
# Clone the repository
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow

# Create and activate a virtual environment
python3 -m venv venv
source venv/bin/activate

# Install
pip install --upgrade pip setuptools wheel
pip install -e .

# Run diagnostics
gli-flow doctor
```

## Post-Installation

If `gli-flow` is not found:

1. Ensure virtual environment is activated: `source venv/bin/activate`
2. Or add local binary directory to PATH:
   ```bash
   export PATH="$HOME/.local/bin:$PATH"
   ```
   Add to `~/.bashrc` or `~/.zshrc` to make it permanent.

## First-Time Setup

```bash
# Interactive setup (recommended)
gli-flow setup

# Non-interactive setup
gli-flow setup --pdk-root /opt/pdk --workspace ~/designs --telemetry on
```

## Verification

```bash
gli-flow doctor          # Validate environment
gli-flow db migrate      # Ensure database is up to date
gli-flow run examples/counter --mock  # Test run in mock mode
```

## Dashboard

```bash
gli-flow dashboard
# Opens at http://127.0.0.1:8000
```
