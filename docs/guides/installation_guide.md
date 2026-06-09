# Installation Guide

This guide covers the various ways to install GLI-FLOW.

## Prerequisites

- **Python 3.9+** — Required for running GLI-FLOW and its Python tooling.
- **git** — Needed for version control and fetching PDK components.
- **cmake** — Required for building certain PDK and simulation dependencies.

Optional but recommended:
- **Docker** — For containerized deployment (see Option B).
- **curl** — For the curl install script (see Option C).

## Option A: pip install

```bash
pip install gli-flow
```

To install a specific version:

```bash
pip install gli-flow==1.2.0
```

To upgrade an existing installation:

```bash
pip install --upgrade gli-flow
```

## Option B: Docker

Pull the pre-built image from GitHub Container Registry:

```bash
docker pull ghcr.io/gli-flow/gli-flow:latest
```

Run an interactive container:

```bash
docker run -it --rm -v "$(pwd):/workspace" ghcr.io/gli-flow/gli-flow:latest
```

To build the image locally:

```bash
git clone https://github.com/gli-flow/gli-flow.git
cd gli-flow
docker build -t gli-flow:local .
```

## Option C: curl install script

```bash
curl -fsSL https://raw.githubusercontent.com/gli-flow/gli-flow/main/install.sh | bash
```

To install to a specific directory:

```bash
curl -fsSL https://raw.githubusercontent.com/gli-flow/gli-flow/main/install.sh | bash -s -- --prefix ~/.local
```

## Verifying Installation

Run the `doctor` command to verify that GLI-FLOW is installed correctly and all dependencies are available:

```bash
gli-flow doctor
```

This command checks:
- Python version compatibility
- Required toolchain availability (yosys, openroad, magic, netgen, klayout, etc.)
- PDK presence and configuration
- Environment variable setup

### Multi-Candidate Discovery

The doctor uses multi-candidate tool discovery, meaning it finds ALL copies of each tool on the system and selects the best one based on functional validation, not PATH order.

If a broken local binary shadows a valid system binary, the doctor reports it:

```bash
# Show discovery report with all candidates
gli-flow doctor

# Repair broken magic binary shadowing system install
gli-flow doctor --repair-magic
```

### Understanding Tool Selection

During installation, `gli-flow install` validates each tool and reports any PATH shadowing detected:

```
magic  PASS  8.3.359 at /usr/bin/magic
  ⚠ PATH shadowing detected: broken at /home/user/.local/bin/magic,
    valid at /usr/bin/magic. Run: gli-flow doctor --repair-magic
```

## Troubleshooting Common Install Issues

| Issue | Likely Cause | Solution |
|---|---|---|
| `command not found: gli-flow` | pip bin directory not in PATH | Add `$(python3 -m site --user-base)/bin` to your `PATH` |
| `Error: Python 3.9+ required` | Outdated Python | Run `python3 --version` and upgrade via `pyenv` or your package manager |
| `cmake: command not found` | cmake not installed | Run `apt install cmake` (Linux) or `brew install cmake` (macOS) |
| Docker permission denied | User not in docker group | Run `sudo usermod -aG docker $USER` and log out and back in |
| `pip install gli-flow` fails on Windows | Missing build tools | Install Microsoft C++ Build Tools or use WSL / Docker |
| `gli-flow doctor` reports missing PDK | PDK not configured | Run `gli-flow pdk setup` or set `PDK_ROOT` environment variable |
