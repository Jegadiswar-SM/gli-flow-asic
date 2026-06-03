bolter@Jegadiswar-PC:~/gli-flow$ gli-flow install

  GLI-FLOW   Execution Intelligence Infrastructure
RTL-to-GDS Silicon Pipeline

Platform: ubuntu 26.04
PDK: sky130
ORFS: /home/bolter/.gli-flow/orfs

[sudo: authenticate] Password:
Hit:1 https://deb.nodesource.com/node_22.x nodistro InRelease
Hit:2 http://security.ubuntu.com/ubuntu resolute-security InRelease
Hit:3 http://archive.ubuntu.com/ubuntu resolute InRelease
Hit:4 http://archive.ubuntu.com/ubuntu resolute-updates InRelease
Hit:5 https://ppa.launchpadcontent.net/deadsnakes/ppa/ubuntu resolute InRelease
Hit:6 http://archive.ubuntu.com/ubuntu resolute-backports InRelease
Reading package lists... Done
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
git is already the newest version (1:2.53.0-1ubuntu1).
curl is already the newest version (8.18.0-1ubuntu2.1).
wget is already the newest version (1.25.0-2ubuntu4).
ca-certificates is already the newest version (20260223).
build-essential is already the newest version (12.12ubuntu2).
cmake is already the newest version (4.2.3-2ubuntu2).
python3 is already the newest version (3.14.3-0ubuntu2).
python3-pip is already the newest version (25.1.1+dfsg-1ubuntu2).
python3-venv is already the newest version (3.14.3-0ubuntu2).
pipx is already the newest version (1.8.0-1).
tcl is already the newest version (8.6.16build1).
tcl-dev is already the newest version (8.6.16build1).
tk-dev is already the newest version (8.6.16build1).
libffi-dev is already the newest version (3.5.2-4).
libssl-dev is already the newest version (3.5.5-1ubuntu3).
libgomp1 is already the newest version (16-20260322-1ubuntu1).
libtcl8.6 is already the newest version (8.6.17+dfsg-1build1).
tcl-tclreadline is already the newest version (2.4.1-2build1).
netgen-lvs is already the newest version (1.5.133-1.2).
cargo is already the newest version (1.93.1ubuntu1).
magic is already the newest version (8.3.105+ds.1-1.1).
Solving dependencies... Done
0 upgraded, 0 newly installed, 0 to remove and 2 not upgraded.
  PASS  system-deps
  PASS  workspace: /home/bolter/.gli-flow/orfs
  PASS  gli-flow
  SKIP  yosys
  SKIP  klayout
  SKIP  openroad
  SKIP  sv2v
  SKIP  magic
  SKIP  netgen
  SKIP  orfs
  SKIP  pdk:sky130
  ACTION REQUIRED  WSL2: Running inside WSL2


Installation Summary
============================================================

PASS:
  - git  (git version 2.53.0)
  - cmake  (cmake version 4.2.3)
  - python3  (Python 3.14.4)
  - yosys  (Yosys 0.52 (git sha1 fee39a3284c90249e1d9684cf6944ffbbcbb8f90))
  - klayout  (KLayout 0.30.0)
  - magic  (8.3.105)
  - sv2v  (sv2v v0.0.13)
  - orfs  (/home/bolter/.gli-flow/orfs)
  - pdk:sky130  (installed)
  - python3  (3.14.4)
  - gli-flow  (v1.0.0)

FAIL (version mismatch):
  - openroad has None, need 2.0
  - netgen has None, need 1.5

ACTION REQUIRED:
  - WSL2: Running inside WSL2
Ensure Docker Desktop is running for ORFS.
  Verify with: docker ps
  Set GLI_FLOW_USE_DOCKER=1 if needed.
  File permissions: avoid /mnt/c/ paths; use ~/gli-flow instead.

Overall Status: NOT READY

  [FAIL] openroad: Version None does not meet minimum 2.0
  [FAIL] netgen: Version None does not meet minimum 1.5
bolter@Jegadiswar-PC:~/gli-flow$ gli-flow install

  GLI-FLOW   Execution Intelligence Infrastructure
RTL-to-GDS Silicon Pipeline

Platform: ubuntu 26.04
PDK: sky130
ORFS: /home/bolter/.gli-flow/orfs

Hit:1 https://deb.nodesource.com/node_22.x nodistro InRelease
Hit:2 http://security.ubuntu.com/ubuntu resolute-security InRelease
Hit:3 http://archive.ubuntu.com/ubuntu resolute InRelease
Hit:4 https://ppa.launchpadcontent.net/deadsnakes/ppa/ubuntu resolute InRelease
Hit:5 http://archive.ubuntu.com/ubuntu resolute-updates InRelease
Hit:6 http://archive.ubuntu.com/ubuntu resolute-backports InRelease
Reading package lists... Done
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
git is already the newest version (1:2.53.0-1ubuntu1).
curl is already the newest version (8.18.0-1ubuntu2.1).
wget is already the newest version (1.25.0-2ubuntu4).
ca-certificates is already the newest version (20260223).
build-essential is already the newest version (12.12ubuntu2).
cmake is already the newest version (4.2.3-2ubuntu2).
python3 is already the newest version (3.14.3-0ubuntu2).
python3-pip is already the newest version (25.1.1+dfsg-1ubuntu2).
python3-venv is already the newest version (3.14.3-0ubuntu2).
pipx is already the newest version (1.8.0-1).
tcl is already the newest version (8.6.16build1).
tcl-dev is already the newest version (8.6.16build1).
tk-dev is already the newest version (8.6.16build1).
libffi-dev is already the newest version (3.5.2-4).
libssl-dev is already the newest version (3.5.5-1ubuntu3).
libgomp1 is already the newest version (16-20260322-1ubuntu1).
libtcl8.6 is already the newest version (8.6.17+dfsg-1build1).
tcl-tclreadline is already the newest version (2.4.1-2build1).
netgen-lvs is already the newest version (1.5.133-1.2).
cargo is already the newest version (1.93.1ubuntu1).
magic is already the newest version (8.3.105+ds.1-1.1).
Solving dependencies... Done
0 upgraded, 0 newly installed, 0 to remove and 2 not upgraded.
  PASS  system-deps
  PASS  workspace: /home/bolter/.gli-flow/orfs
  PASS  gli-flow
  SKIP  yosys
  SKIP  klayout
  SKIP  openroad
  SKIP  sv2v
  SKIP  magic
  SKIP  netgen
  SKIP  orfs
  SKIP  pdk:sky130
  ACTION REQUIRED  WSL2: Running inside WSL2


Installation Summary
============================================================

PASS:
  - git  (git version 2.53.0)
  - cmake  (cmake version 4.2.3)
  - python3  (Python 3.14.4)
  - yosys  (Yosys 0.52 (git sha1 fee39a3284c90249e1d9684cf6944ffbbcbb8f90))
  - klayout  (KLayout 0.30.0)
  - magic  (8.3.105)
  - netgen  (1.5.133-1.2)
  - sv2v  (sv2v v0.0.13)
  - orfs  (/home/bolter/.gli-flow/orfs)
  - pdk:sky130  (installed)
  - python3  (3.14.4)
  - gli-flow  (v1.0.0)

FAIL (version mismatch):
  - openroad has None, need 2.0

ACTION REQUIRED:
  - WSL2: Running inside WSL2
Ensure Docker Desktop is running for ORFS.
  Verify with: docker ps
  Set GLI_FLOW_USE_DOCKER=1 if needed.
  File permissions: avoid /mnt/c/ paths; use ~/gli-flow instead.

Overall Status: NOT READY

  [FAIL] openroad: Version None does not meet minimum 2.0
