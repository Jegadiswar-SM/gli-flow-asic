# Getting Started with GLI-FLOW

Welcome to GLI-FLOW! This guide will help you set up your environment for RTL-to-GDS silicon design.

## Prerequisites
- Ubuntu 22.04 or compatible Linux distribution (WSL2 recommended for Windows).
- Python 3.9+ installed.
- Docker installed and configured.

## Installation

### 1. Clone the Repository
```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
```

### 2. Install Dependencies
```bash
pip install -e .
```

### 3. Verify Installation (Fix PATH issues)
If the `gli-flow` command is not found, you need to add the local binary directory to your PATH:

```bash
export PATH=$PATH:$HOME/.local/bin
```
To make this change permanent, add the above line to your `~/.bashrc` or `~/.zshrc`.

### 4. Run Diagnostics
After installation, verify your environment:
```bash
gli-flow doctor
```

### 5. First Run
```bash
gli-flow quickstart
```
