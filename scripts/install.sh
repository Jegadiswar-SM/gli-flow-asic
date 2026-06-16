#!/usr/bin/env bash
set -euo pipefail

# GLI-FLOW One-Command Install
# Supports: Ubuntu (22.04+), Debian (12+), WSL2
#
# Usage from a cloned repo:
#   bash scripts/install.sh
#
# Or from scratch:
#   git clone https://github.com/green-lantern-industries/gli-flow.git
#   cd gli-flow
#   bash scripts/install.sh

GLI_FLOW_VERSION="v1.0.0"
MIN_PYTHON="3.9"
MIN_DISK_GB=10
MIN_RAM_MB=2048

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
NC='\033[0m'

pass() { echo -e "  ${GREEN}✓${NC} $1"; }
warn() { echo -e "  ${YELLOW}⚠${NC} $1"; }
fail() { echo -e "  ${RED}✗${NC} $1"; }
info() { echo -e "  ${CYAN}→${NC} $1"; }

echo ""
echo "╔══════════════════════════════════════════╗"
echo "║     GLI-FLOW Installer ${GLI_FLOW_VERSION}      ║"
echo "║  RTL-to-GDS Silicon Pipeline             ║"
echo "╚══════════════════════════════════════════╝"
echo ""

# ---- Determine script directory (where this script lives) ----
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

# ---- OS Detection ----
info "Detecting operating system..."

OS=""
OS_LIKE=""
WSL=false

if [ -f /etc/os-release ]; then
    . /etc/os-release
    OS="$ID"
    OS_LIKE="${ID_LIKE:-}"
fi

if uname -r | grep -qi microsoft; then
    WSL=true
    pass "WSL2 detected"
fi

case "$OS" in
    ubuntu)
        pass "Ubuntu $VERSION_ID detected"
        MAJOR=$(echo "$VERSION_ID" | cut -d. -f1)
        if [ "$MAJOR" -lt 22 ]; then
            fail "Ubuntu 22.04+ required (found $VERSION_ID)"
            exit 1
        fi
        ;;
    debian)
        pass "Debian $VERSION_ID detected"
        MAJOR=$(echo "$VERSION_ID" | cut -d. -f1)
        if [ "$MAJOR" -lt 12 ]; then
            fail "Debian 12+ required (found $VERSION_ID)"
            exit 1
        fi
        ;;
    *)
        if echo "$OS_LIKE" | grep -qiE "debian|ubuntu"; then
            warn "Untested OS ($OS), but Debian-like. Proceeding with caution."
        else
            fail "Unsupported OS: $OS"
            echo "  Supported: Ubuntu 22.04+, Debian 12+, WSL2"
            echo "  Install via Docker: docker run ghcr.io/green-lantern-industries/gli-flow"
            exit 1
        fi
        ;;
esac

# ---- Prerequisites ----
info "Checking prerequisites..."

PYTHON_CMD=""
for cmd in python3 python; do
    if command -v "$cmd" &>/dev/null; then
        PYTHON_CMD="$cmd"
        break
    fi
done

if [ -z "$PYTHON_CMD" ]; then
    fail "Python not found. Install Python $MIN_PYTHON+ first."
    exit 1
fi

PYTHON_VERSION=$($PYTHON_CMD --version 2>&1 | grep -oP '\d+\.\d+')
if [ -z "$PYTHON_VERSION" ]; then
    fail "Could not determine Python version."
    exit 1
fi

MAJOR_PY=$(echo "$PYTHON_VERSION" | cut -d. -f1)
MINOR_PY=$(echo "$PYTHON_VERSION" | cut -d. -f2)
REQUIRED_MAJOR=$(echo "$MIN_PYTHON" | cut -d. -f1)
REQUIRED_MINOR=$(echo "$MIN_PYTHON" | cut -d. -f2)

if [ "$MAJOR_PY" -lt "$REQUIRED_MAJOR" ] || ([ "$MAJOR_PY" -eq "$REQUIRED_MAJOR" ] && [ "$MINOR_PY" -lt "$REQUIRED_MINOR" ]); then
    fail "Python $MIN_PYTHON+ required (found $PYTHON_VERSION)"
    exit 1
fi
pass "Python $PYTHON_VERSION"

# ---- Disk Space ----
AVAIL_KB=$(df /tmp 2>/dev/null | awk 'NR==2 {print $4}' || echo 0)
AVAIL_GB=$((AVAIL_KB / 1024 / 1024))
if [ "$AVAIL_GB" -lt "$MIN_DISK_GB" ]; then
    fail "Insufficient disk space: ${AVAIL_GB}GB (need ${MIN_DISK_GB}GB)"
    exit 1
fi
pass "Disk space: ${AVAIL_GB}GB"

# ---- RAM ----
TOTAL_RAM_MB=$(awk '/MemTotal/ {printf "%d", $2/1024}' /proc/meminfo 2>/dev/null || echo 0)
if [ "$TOTAL_RAM_MB" -lt "$MIN_RAM_MB" ]; then
    fail "Insufficient RAM: ${TOTAL_RAM_MB}MB (need ${MIN_RAM_MB}MB)"
    exit 1
fi
pass "RAM: ${TOTAL_RAM_MB}MB"

# ---- Docker (optional) ----
if command -v docker &>/dev/null; then
    pass "Docker found"
else
    warn "Docker not found (optional — needed for containerized runs)"
fi

# ---- Validate we are in the repo ----
if [ ! -f "$REPO_DIR/setup.py" ]; then
    fail "Cannot find gli-flow source. Run this script from within the cloned repository."
    echo "  git clone https://github.com/green-lantern-industries/gli-flow.git"
    echo "  cd gli-flow"
    echo "  bash scripts/install.sh"
    exit 1
fi
pass "GLI-FLOW source found at $REPO_DIR"

# ---- Check for root/sudo ----
if [ "$EUID" -eq 0 ]; then
    warn "Running as root! This may cause permission issues. If you are a normal user, run this script without sudo."
fi

# ---- Install System Dependencies ----
info "Installing system dependencies..."

if command -v apt-get &>/dev/null; then
    if [ "$EUID" -ne 0 ]; then
        warn "Installing system dependencies requires sudo. Please enter password if prompted."
    fi
    sudo apt-get update -qq
    sudo apt-get install -y -qq \
        git curl wget cmake build-essential \
        python3-pip python3-venv \
        tclsh tk libffi-dev libssl-dev \
        lz4 zlib1g-dev \
        >/dev/null 2>&1 || {
        fail "System dependency installation failed."
        echo "  Try: sudo apt-get install git curl cmake build-essential python3-pip python3-venv tclsh"
        exit 1
    }
    pass "System dependencies installed"
else
    warn "apt-get not found; skipping system deps. Install git, cmake, python3-pip manually."
fi

# ---- Install GLI-FLOW ----
info "Installing gli-flow..."

PIP_CMD="pip3"
if ! command -v pip3 &>/dev/null; then
    PIP_CMD="pip"
fi

# Create a virtual environment if not already in one
if [ -z "${VIRTUAL_ENV:-}" ]; then
    VENV_DIR="$HOME/.gli-flow/venv"
    if [ ! -d "$VENV_DIR" ]; then
        info "Creating virtual environment at $VENV_DIR"
        $PYTHON_CMD -m venv "$VENV_DIR"
    fi
    # shellcheck disable=SC1091
    source "$VENV_DIR/bin/activate"
    PIP_CMD="$VENV_DIR/bin/pip"
    pass "Virtual environment ready"
fi

info "Installing gli-flow from source..."
$PIP_CMD install --quiet --upgrade pip setuptools wheel >/dev/null 2>&1

if $PIP_CMD install --quiet -e "$REPO_DIR" >/dev/null 2>&1; then
    pass "gli-flow installed successfully"
else
    fail "gli-flow installation failed."
    echo "  Try: cd $REPO_DIR && pip install -e ."
    exit 1
fi

# ---- Verify CLI works ----
info "Verifying gli-flow CLI..."
if command -v gli-flow &>/dev/null; then
    GLI_VERSION=$(gli-flow --help 2>&1 | head -1)
    pass "CLI ready: gli-flow"
else
    warn "gli-flow command not found in PATH."
    if [ -n "${VIRTUAL_ENV:-}" ]; then
        echo "  Run: source $VENV_DIR/bin/activate"
        echo "  Or add to your shell config: export PATH=\"$VENV_DIR/bin:\$PATH\""
    fi
    VENV_BIN="$VENV_DIR/bin"
    if [ -f "$VENV_BIN/gli-flow" ]; then
        warn "Found at $VENV_BIN/gli-flow — add to PATH:"
        echo "  export PATH=\"$VENV_BIN:\$PATH\""
    fi
fi

# ---- Run Doctor ----
info "Running environment validation..."
if command -v gli-flow &>/dev/null; then
    gli-flow doctor 2>&1 || {
        warn "Doctor found issues — run 'gli-flow doctor' to see details."
    }
    pass "Environment validated"
fi

# ---- Success ----
echo ""
echo "╔══════════════════════════════════════════╗"
echo "║  Installation Complete!                  ║"
echo "╠══════════════════════════════════════════╣"
echo "║  Next steps:                             ║"
echo "║                                          ║"
echo "║  gli-flow doctor                         ║"
echo "║  gli-flow quickstart                     ║"
echo "║  gli-flow run examples/counter --mock    ║"
echo "║                                          ║"
echo "║  To start the dashboard:                 ║"
echo "║  gli-flow dashboard                      ║"
echo "║                                          ║"
echo "║  Docs: https://opencode.ai/gli-flow      ║"
echo "╚══════════════════════════════════════════╝"
echo ""
