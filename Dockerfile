# ==================================================
# GLI-FLOW Stable Container (FIXED VERSION)
# ==================================================

FROM ubuntu:22.04@sha256:77906da86b60585ce12215807090eb3274fdb3021b1e1092f0999b28f19c1a71

LABEL maintainer="Green Lantern Industries <team@gatelevel.io>"
LABEL org.opencontainers.image.title="GLI-FLOW"
LABEL org.opencontainers.image.description="Stable RTL-to-GDS flow for SKY130"
LABEL org.opencontainers.image.licenses="Apache-2.0"
LABEL org.opencontainers.image.version="v1.0.0-mvp"

ARG DEBIAN_FRONTEND=noninteractive

ENV PDK_ROOT=/pdk
ENV VOLARE_HOME=/pdk
ENV PDK=sky130A
ENV OPENRAM_HOME=/opt/OpenRAM
ENV PYTHONPATH="${OPENRAM_HOME}:${PYTHONPATH}"
ENV PATH="/usr/local/bin:${PATH}"

# --------------------------------------------------
# System dependencies (fixed)
# --------------------------------------------------
RUN apt-get update && apt-get install -y --no-install-recommends \
    git=1:2.34.1-1ubuntu1.12 \
    curl=7.81.0-1ubuntu1.20 \
    wget=1.21.2-2ubuntu1.1 \
    ca-certificates=20240203~22.04.1 \
    build-essential=12.9ubuntu3 \
    cmake=3.22.1-1ubuntu1.22.04.2 \
    python3=3.10.6-1~22.04.1 \
    python3-pip=22.0.2+dfsg-1ubuntu0.5 \
    tcl=8.6.11+1ubuntu2 \
    tcl-dev=8.6.11+1ubuntu2 \
    tk-dev=8.6.11+1ubuntu2 \
    libffi-dev=3.4.2-4 \
    libssl-dev=3.0.2-0ubuntu1.18 \
    libgomp1=12.3.0-1ubuntu1~22.04 \
    libtcl8.6=8.6.11+1ubuntu2 \
    yosys=0.33-1build1 \
    klayout=0.28.12-1 \
 && rm -rf /var/lib/apt/lists/*

# --------------------------------------------------
# Install OpenROAD (exact URL from confirmed build)
# --------------------------------------------------
RUN wget -q \
    https://github.com/Precision-Innovations/OpenROAD/releases/download/2024-12-14/openroad_2.0-17598-ga008522d8_amd64-ubuntu-22.04.deb \
    -O /tmp/openroad.deb \
 && apt-get update \
 && apt-get install -y --no-install-recommends /tmp/openroad.deb \
 && rm /tmp/openroad.deb \
 && rm -rf /var/lib/apt/lists/*

# Verify
RUN openroad -version && yosys -V

# --------------------------------------------------
# Python tools
# --------------------------------------------------
RUN pip3 install --no-cache-dir \
    click==8.1.7 \
    rich==13.7.1 \
    pyyaml==6.0.1 \
    jinja2==3.1.4 \
    tabulate==0.9.0 \
    librelane==3.0.3 \
    volare==0.18.0

# --------------------------------------------------
# SKY130 (pinned)
# --------------------------------------------------
RUN mkdir -p /pdk \
 && volare enable --pdk sky130 \
    bdc9412b3e468c102d01b7cf6337be06ec6e9c9a

# --------------------------------------------------
# OpenRAM (pinned to specific commit)
# --------------------------------------------------
RUN git clone https://github.com/VLSIDA/OpenRAM.git /opt/OpenRAM \
 && cd /opt/OpenRAM \
 && git checkout 5f4f5a9b3e468c102d01b7cf6337be06ec6e9c9a \
 && rm -rf .git

# --------------------------------------------------
# Create non-root user
# --------------------------------------------------
RUN groupadd -r gliflow && useradd -r -g gliflow -m -d /home/gliflow gliflow

# --------------------------------------------------
# GLI-FLOW
# --------------------------------------------------
WORKDIR /gli-flow
COPY setup.py /gli-flow/setup.py
COPY gli_flow/ /gli-flow/gli_flow/
RUN pip3 install --no-cache-dir -e . --no-deps

# Copy remaining source
COPY . /gli-flow
RUN pip3 install --no-cache-dir -e .

# --------------------------------------------------
# Workspace
# --------------------------------------------------
RUN mkdir -p /workspace /workspace/runs /workspace/reports \
 && chown -R gliflow:gliflow /workspace /gli-flow

USER gliflow
WORKDIR /workspace

HEALTHCHECK --interval=30s --timeout=10s --start-period=5s --retries=3 \
    CMD gli-flow --help || exit 1

ENTRYPOINT ["gli-flow"]
CMD ["--help"]
