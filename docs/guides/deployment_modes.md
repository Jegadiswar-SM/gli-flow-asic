# Deployment Modes

GLI-FLOW supports several deployment modes for different environments.

## Local Developer (Native Install)

Best for individual developers running flows on their workstation.

**Requirements:**
- Python 3.9+
- Linux or macOS (Windows users should use WSL)
- 16 GB RAM recommended
- PDK installed locally

**Validated example:**

```bash
# Install
pip install gli-flow

# Set up PDK
gli-flow pdk setup

# Run a flow
gli-flow run --design my_chip
```

## WSL (Windows)

Recommended for Windows users who need native Linux toolchain performance.

**Requirements:**
- Windows 10 21H2+ or Windows 11
- WSL 2 with Ubuntu 22.04 LTS
- 8 GB RAM allocated to WSL (16 GB+ recommended for larger designs)
- Docker Desktop with WSL 2 backend (optional)

**Validated example:**

```powershell
# In PowerShell (admin)
wsl --install -d Ubuntu-22.04

# In WSL terminal
sudo apt update && sudo apt install python3 python3-pip git cmake
pip install gli-flow
gli-flow pdk setup
gli-flow run --design my_chip
```

**WSL configuration (.wslconfig):**
```ini
[wsl2]
memory=16GB
processors=4
localhostForwarding=true
```

## Docker (Production + Dev)

Best for reproducible builds, CI/CD, and production deployment.

**Requirements:**
- Docker 23.0+ or Podman 4.0+
- 8 GB disk space for the image
- 16 GB RAM for running flows

**Validated example (production):**

```bash
docker pull ghcr.io/gli-flow/gli-flow:latest

docker run --rm \
  -v "$(pwd)/designs:/workspace/designs" \
  -v "$(pwd)/output:/workspace/output" \
  -e PDK_ROOT=/pdk \
  ghcr.io/gli-flow/gli-flow:latest \
  gli-flow run --design designs/my_chip
```

**Validated example (development):**

```bash
git clone https://github.com/gli-flow/gli-flow.git
cd gli-flow

docker build -t gli-flow:dev .

docker run -it --rm \
  -v "$(pwd):/workspace" \
  -v "$(pwd)/dev_pdk:/pdk" \
  gli-flow:dev \
  bash
```

## CI/CD (GitHub Actions)

Automated deployment for continuous integration and regression testing.

**Requirements:**
- GitHub repository with Actions enabled
- Self-hosted runner with 16 GB+ RAM (recommended) or GitHub-hosted runner (smaller designs only)
- Docker support on the runner

**Validated example (`.github/workflows/gli-flow.yml`):**

```yaml
name: GLI-FLOW CI

on:
  push:
    branches: [main]
  pull_request:
    branches: [main]

jobs:
  flow:
    runs-on: ubuntu-22.04
    container:
      image: ghcr.io/gli-flow/gli-flow:latest

    steps:
      - uses: actions/checkout@v4

      - name: Run GLI-FLOW
        run: |
          gli-flow run --design designs/${{ matrix.design }}

      - name: Upload artifacts
        uses: actions/upload-artifact@v4
        with:
          name: flow-results
          path: output/

    strategy:
      matrix:
        design: [counter, adder, my_chip]
```

**Self-hosted runner setup:**

```bash
# On the runner machine
pip install gli-flow
gli-flow pdk setup

# Register the runner with GitHub
gh runner register --url https://github.com/myorg/myrepo
```
