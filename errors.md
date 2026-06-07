bolter@Jegadiswar-PC:~/gli-flow$ gli-flow run examples/uart

  GLI-FLOW   Execution Intelligence Infrastructure
RTL-to-GDS Silicon Pipeline

╭──────────────────────────────────────╮╭──────────────────────────────────────╮╭──────────────────────────────────────╮
│ Run ID                               ││ Design                               ││ Output                               │
│ run_1780772445_28d16659_uart         ││ uart                                 ││ /home/bolter/gli-flow/outputs/runs/r │
│                                      ││                                      ││ un_1780772445_28d16659_uart          │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
│                                      ││                                      ││                                      │
╰──────────────────────────────────────╯╰──────────────────────────────────────╯╰──────────────────────────────────────╯

Run ID: run_1780772445_28d16659_uart
Design: uart
PDK: sky130
PDK Root: /home/bolter/.gli-flow/pdk
Corners: ['typical']
Threads: 4
Run Dir: /home/bolter/gli-flow/outputs/runs/run_1780772445_28d16659_uart

  [INITIALIZING      ] 3%
  [HIERARCHICAL_PARTITIONING] 6%
  [BLOCK_SYNTHESIS   ] 10%
  [SYNTHESIS         ] 13%
  Config: /home/bolter/gli-flow/outputs/runs/run_1780772445_28d16659_uart/config.json
  [PACKAGING         ] 17%
  [SKIP] PACKAGING: ORFS exited with code 2
  [CLOCK_GATING      ] 20%
  [SCAN_INSERTION    ] 24%
  [FORMAL_VERIFICATION] 27%
  [FLOORPLANNING     ] 31%
  [TOP_FLOORPLANNING ] 34%
  [PLACEMENT         ] 37%
  [CTS               ] 41%
  [ROUTING           ] 44%
  [PRO               ] 48%
  [ANTENNA_CHECK     ] 51%
  [SKIP] ANTENNA_CHECK: Antenna check command failed with exit code 1
  [FILL              ] 55%
  [DECAP             ] 58%
  [POWER             ] 62%
  [EM_CHECK          ] 65%
  [DENSITY_CHECK     ] 68%
Density check (density) failed: Density check (density) failed with exit code 1
Post-fill density check failed: Post-fill density check failed with exit code 1
  [YIELD             ] 72%
  [ATPG              ] 75%
  [D2D_INTERFACE_CHECK] 79%
  [QOR_EXTRACTION    ] 82%
  [DRC               ] 86%
  [SKIP] DRC: GDS not found at /home/bolter/gli-flow/outputs/runs/run_1780772445_28d16659_uart/artifacts/6_final.gds
  [LVS               ] 89%
GDS file not found — LVS skipped
  [TIMING_ANALYSIS   ] 93%
Timing signoff failed: OpenROAD STA exited with code 1. Timing signoff failed.
  [SKIP] TIMING_ANALYSIS: SETUP TIMING VIOLATED: WNS=0.000ns, TNS=0.000ns. Design cannot be taped out with setup violations.
  [SI_ANALYSIS       ] 96%
  [SIGN_OFF          ] 100%
  [FAILURE ATLAS] Recorded pipeline failure for run run_1780772445_28d16659_uart

[ERROR] Signoff gate failed: Synthesis did not complete cleanly; Final GDS file not found or empty; Final DEF file not found or empty; Final netlist not found or empty; Setup timing violated (WNS < 0); Hold timing violated (WHS < 0); Magic DRC: violations found or report missing; KLayout DRC: violations found or report missing; Antenna violations found or report missing; LVS failed or report missing

  [ERROR] Signoff gate failed: Synthesis did not complete cleanly; Final GDS file not found or empty; Final DEF file not found or empty; Final netlist not found or empty; Setup timing violated (WNS < 0); Hold timing violated (WHS < 0); Magic DRC: violations found or report missing; KLayout DRC: violations found or report missing; Antenna violations found or report missing; LVS failed or report missing

  Run complete (FAILED): /home/bolter/gli-flow/outputs/runs/run_1780772445_28d16659_uart
ERROR: Execution failed for examples/uart
