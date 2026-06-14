# PicoRV32 — GLI-FLOW Reference Design

## Description

PicoRV32 is a size-optimized RISC-V RV32I CPU core by Claire Xenia Wolf (YosysHQ).
This project processes PicoRV32 through the full GLI-FLOW ASIC toolchain:
Yosys → OpenROAD → Magic → Netgen → KLayout.

- **RTL:** `rtl/picorv32.v` — 3049 lines, 8 modules
- **Top module:** `picorv32`
- **PDK:** SkyWater 130nm (sky130A)
- **Clock:** 50 MHz (20 ns period)
- **Configuration:** RV32I (no multiply, no divide, no compressed, no IRQ)

## How to Run

```bash
# Production run (with EDA tools)
gli-flow run examples/picorv32

# Mock run (for CI/testing)
gli-flow run examples/picorv32 --mock
```

## Expected Outputs

After a successful run:
- `artifacts/6_final.gds` — Final GDSII layout
- `artifacts/6_final.def` — Final DEF
- `artifacts/6_final.v` — Final netlist
- `reports/` — Timing, area, power reports
- `logs/` — All tool logs
- `drc_lvs_summary.json` — DRC/LVS results

## Design Files

```
examples/picorv32/
├── rtl/
│   └── picorv32.v          # RTL source (single file)
├── constraints/
│   └── picorv32.sdc        # Timing constraints
├── docs/                   # Design-specific docs
├── gli_manifest.yaml       # GLI-FLOW configuration
└── README.md               # This file
```

## Parameters

PicoRV32 configured as RV32I:
- Counters enabled
- No compressed ISA
- No multiply/divide
- No interrupt controller
- Native memory interface
