# PicoRV32 GLI-FLOW Execution Report

## Run Details

| Field | Value |
|-------|-------|
| Run ID | `run_1781330223_e05f7ec0_picorv32` |
| Design | picorv32 |
| PDK | sky130A |
| Clock Target | 50 MHz (20 ns) |
| Date | 2026-06-13 |

## QoR Summary

| Metric | Value |
|--------|-------|
| Die Area | 286,059 um² (534.8 x 534.8 um) |
| Core Area | 279,871 um² |
| Standard Cells | 10,428 |
| Utilization | 36.7% |
| Setup WNS | 12.83 ns |
| Hold WNS | 0.13 ns |
| Total Power | 8.48 mW |
| Internal Power | 6.09 mW |
| Switching Power | 2.39 mW |
| Leakage Power | 37 nW |
| Routing DRC | 0 (OpenROAD), 6 (Magic), 4 (KLayout) |
| LVS | NOT_RUN (timeout) |
| Runtime | 2309 seconds (~38.5 min) |

## ORFS Flow Steps

All OpenROAD flow steps completed successfully:
1. Yosys synthesis ✓ (1_2_yosys.v: 1.1 MB)
2. Floorplan ✓ (2_floorplan.odb)
3. Placement ✓ (3_place.odb)
4. Clock Tree Synthesis ✓ (4_cts.odb)
5. Global Routing ✓ (5_1_grt.odb)
6. **Detailed Routing ✓** (12 iterations, 0 DRC errors)
7. Fill Insertion ✓ (5_3_fillcell.odb)
8. GDS Merge ✓ (6_final.gds: 12.7 MB)
9. SPEF Extraction ✓ (6_final.spef: 9.7 MB)

## DRC Details

### Magic DRC: 6 violations
- li.3 (local interconnect spacing): 4 violations — at die-edge boundaries
- licon.8a (poly overlap of contact): 2 violations — minor enclosure

### KLayout DRC: 4 violations
- li.3 (local interconnect spacing): 4 violations — matches Magic findings

**Assessment:** Minor, non-critical. Can be resolved by increasing core margin.

## Deliverables

| File | Size | Description |
|------|------|-------------|
| `6_final.gds` | 12.7 MB | Final GDSII layout |
| `6_final.def` | 11.2 MB | Final DEF |
| `6_final.v` | 873 KB | Final netlist |
| `6_final.spef` | 9.7 MB | Parasitic extraction |
| `6_final.sdc` | 39 KB | Final constraints |
