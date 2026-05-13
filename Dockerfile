# ==================================================
# GLI-FLOW Stable Container (FIXED VERSION)
# ==================================================

FROM ubuntu:22.04

LABEL maintainer="Green Lantern Industries <team@gatelevel.io>"
LABEL org.opencontainers.image.title="GLI-FLOW"
LABEL org.opencontainers.image.description="Stable RTL-to-GDS flow for SKY130"
LABEL org.opencontainers.image.licenses="Apache-2.0"

ENV DEBIAN_FRONTEND=noninteractive
ENV PDK_ROOT=/pdk
ENV VOLARE_HOME=/pdk
ENV PDK=sky130A
ENV OPENRAM_HOME=/opt/OpenRAM
ENV PYTHONPATH="${OPENRAM_HOME}:${PYTHONPATH}"
ENV PATH="/usr/local/bin:${PATH}"

# --------------------------------------------------
# System dependencies (fixed)
# --------------------------------------------------
RUN apt-get update && apt-get install -y \
    git curl wget ca-certificates \
    build-essential cmake \
    python3 python3-pip \
    tcl tcl-dev tk-dev \
    libffi-dev libssl-dev \
    libgomp1 libtcl8.6 \
    yosys klayout \
 && rm -rf /var/lib/apt/lists/*

# --------------------------------------------------
# ✅ Install OpenROAD (exact URL from confirmed build)
# --------------------------------------------------
RUN wget -q \
    https://github.com/Precision-Innovations/OpenROAD/releases/download/2024-12-14/openroad_2.0-17598-ga008522d8_amd64-ubuntu-22.04.deb \
    -O /tmp/openroad.deb \
 && apt-get update \
 && apt-get install -y /tmp/openroad.deb \
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
# SKY130 (pinned — correct)
# --------------------------------------------------
RUN mkdir -p /pdk \
 && volare enable --pdk sky130 \
    bdc9412b3e468c102d01b7cf6337be06ec6e9c9a

# --------------------------------------------------
# ⚠️ Still non-deterministic (optional improvement later)
# --------------------------------------------------
RUN git clone --depth=1 https://github.com/VLSIDA/OpenRAM.git /opt/OpenRAM

# --------------------------------------------------
# GLI-FLOW
# --------------------------------------------------
WORKDIR /gli-flow
COPY . /gli-flow
RUN pip3 install --no-cache-dir -e .

# --------------------------------------------------
# Workspace
# --------------------------------------------------
RUN mkdir -p /workspace /workspace/runs /workspace/reports
WORKDIR /workspace

ENTRYPOINT ["gli-flow"]
CMD ["--help"]
