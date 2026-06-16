# Installation Guide

This guide describes how to install GLI-FLOW on supported Linux distributions (Ubuntu 22.04+, Debian 12+) and WSL2.

## Prerequisites

- Python 3.9+
- 8GB RAM minimum (16GB+ recommended)
- 10GB free disk space
- `git`, `cmake`, `build-essential`

## Automated Installation

The simplest way to install GLI-FLOW is using the provided installation script:

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
bash scripts/install.sh
```

This script will:
1. Detect your OS.
2. Install necessary system dependencies (if on Debian/Ubuntu).
3. Create a virtual environment at `$HOME/.gli-flow/venv`.
4. Install GLI-FLOW in editable mode.
5. Verify the installation with `gli-flow doctor`.

## Manual Installation

If you prefer to install manually:

```bash
# Clone the repository
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow

# Create and activate a virtual environment
python3 -m venv venv
source venv/bin/activate

# Install requirements and GLI-FLOW
pip install --upgrade pip setuptools wheel
pip install -e .

# Run diagnostics to ensure toolchain is configured correctly
gli-flow doctor
```

## Post-Installation

After installation, verify that the `gli-flow` command is in your PATH. If it is not found:

1. **If using a virtual environment**, ensure it is activated: `source venv/bin/activate`.
2. **If installed globally**, ensure your local binary directory is in your PATH:
   ```bash
   export PATH="$HOME/.local/bin:$PATH"
   ```
   Add this line to your `~/.bashrc` or `~/.zshrc` to make it permanent.
