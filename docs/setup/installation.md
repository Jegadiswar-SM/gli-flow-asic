# GLI-FLOW Installation Guide

## Supported Environments

Currently validated environments:

- Ubuntu 22.04
- WSL2 Ubuntu

---

# Prerequisites

## Required Tools

| Tool | Minimum Version |
|---|---|
| Python | 3.10 |
| Docker | 24.0 |
| Git | 2.30 |

---

# Optional Tools

## LibreLane

LibreLane is required for:
- OpenROAD execution
- ASIC flow orchestration
- physical design execution

Current installation is manual.

---

# Repository Setup

Clone repository:

```bash
git clone <repository-url>
cd gli-flow
```

---

# Python Environment

Create virtual environment:

```bash
python3 -m venv venv
source venv/bin/activate
```

---

# Install Dependencies

```bash
pip install -r requirements.txt
```

---

# Docker Validation

Verify Docker:

```bash
docker --version
docker ps
```

For WSL:
- Docker Desktop required
- WSL integration must be enabled

---

# Environment Validation

Run:

```bash
./install/install.sh
```

Or:

```bash
python3 environment/validation/validate_environment.py
```

---

# Reproducibility Validation

Generate environment fingerprint:

```bash
python3 environment/validation/environment_fingerprint.py
```

---

# Expected MVP Capabilities

Current MVP supports:
- execution orchestration
- telemetry collection
- QoR analytics
- provenance generation
- regression detection
- packaging foundations

---

# Current Limitations

Current limitations include:
- Linux/WSL focused workflows
- manual LibreLane installation
- early-stage MVP infrastructure
- no Windows-native execution support

---

# Troubleshooting

See:

- docs/troubleshooting/
- docs/failure_atlas/

for remediation guidance and known issues.
