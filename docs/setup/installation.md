# Installation Guide

## Supported Environments

- Ubuntu 22.04+
- Debian 12+
- WSL2 (Ubuntu)

## Prerequisites

- Python 3.9+
- git
- cmake

## Install from Source (Recommended)

```bash
# Clone and install
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
pip install -e .

# Verify
gli-flow doctor
```

## Docker

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
docker build -t gli-flow:local .
docker run -it --rm -v "$(pwd):/workspace" gli-flow:local
```

## Post-Installation

After installation, verify with:

```bash
gli-flow doctor
```

Run a mock design to test:

```bash
gli-flow run examples/counter --mock
```

## Next Steps

See:
- `docs/setup/quickstart.md` — Getting started guide
- `docs/USER_MANUAL.md` — Full command reference and pipeline stages
- `docs/guides/troubleshooting_guide.md` — Common issues
