# Installation Guide

This guide covers the supported ways to install GLI-FLOW.

## Prerequisites

- **Python 3.9+** — Required for running GLI-FLOW and its Python tooling.
- **git** — Needed for cloning the repository.
- **cmake** — Required for building certain PDK and simulation dependencies.

Optional but recommended:
- **Docker** — For containerized deployment (see Option B).

## Option A: Install from Source (Recommended)

**This is the only supported installation method.**

```bash
# 1. Clone the repository
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow

# 2. (Recommended) Create a virtual environment
python3 -m venv venv
source venv/bin/activate

# 3. Install gli-flow
pip install -e .

# 4. Verify installation
gli-flow doctor

# 5. Run a mock design
gli-flow run examples/counter --mock
```

> **After install, if `gli-flow` is not found:**
> - If using a venv: run `source venv/bin/activate` (or wherever your venv is)
> - If installed user-wide: add `export PATH="$HOME/.local/bin:$PATH"` to your `~/.bashrc`
> - Run `which gli-flow` to confirm

### Environment validation script

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
bash scripts/validate.sh
```

This script:
- Detects your OS (Ubuntu 22.04+, Debian 12+, WSL2)
- Checks Python version, disk space, and RAM
- Validates repository structure
- Checks for required EDA tools (yosys, openroad, etc.)
- Runs `gli-flow doctor` to verify environment readiness

## Option B: Docker

Build the Docker image locally:

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
docker build -t gli-flow:local .

# Run an interactive container
docker run -it --rm -v "$(pwd):/workspace" gli-flow:local
```

## Verifying Installation

Run `gli-flow doctor` to verify everything is installed correctly:

```bash
gli-flow doctor
```

This command checks:
- Python version compatibility
- Required toolchain availability (yosys, openroad, magic, netgen, klayout)
- PDK presence and configuration
- Environment variable setup

### Multi-Candidate Discovery

The doctor uses multi-candidate tool discovery — it finds ALL copies of each tool on the system and selects the best one based on functional validation, not PATH order.

```bash
# Show discovery report with all candidates
gli-flow doctor

# Repair broken magic binary shadowing system install
gli-flow doctor --repair-magic
```

## Troubleshooting Common Install Issues

| Issue | Likely Cause | Solution |
|---|---|---|
| `command not found: gli-flow` | pip bin directory not in PATH | Activate your venv or add `export PATH="$HOME/.local/bin:$PATH"` to `~/.bashrc` |
| `Error: Python 3.9+ required` | Outdated Python | Run `python3 --version` and upgrade via `pyenv` or your package manager |
| `gli-flow doctor` reports missing tools | EDA tools not installed | Install Yosys, OpenROAD, etc. or use `--mock` mode for testing |
| Docker permission denied | User not in docker group | Run `sudo usermod -aG docker $USER` and log out and back in |
