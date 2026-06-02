// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsoc_top__Syms.h"


VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__prim_cipher_pkg__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__prim_ram_1p_pkg__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__ibex_pkg__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("prim_mubi_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsoc_top___024root__trace_init_sub__TOP__prim_mubi_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_cipher_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsoc_top___024root__trace_init_sub__TOP__prim_cipher_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_secded_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsoc_top___024root__trace_init_sub__TOP__prim_secded_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_ram_1p_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsoc_top___024root__trace_init_sub__TOP__prim_ram_1p_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("ibex_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vsoc_top___024root__trace_init_sub__TOP__ibex_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1097,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("soc_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1097,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1098,0,"instr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1099,0,"dma_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1100,0,"mac_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1101,0,"mac_fsm_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+756,0,"instr_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_gnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+986,0,"instr_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+757,0,"cpu_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+987,0,"cpu_gnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+988,0,"cpu_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,0,"cpu_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+759,0,"cpu_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+760,0,"cpu_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+761,0,"cpu_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1093,0,"cpu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+708,0,"mac_m_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+751,0,"mac_m_gnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"mac_m_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+709,0,"mac_m_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"mac_m_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"mac_m_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1102,0,"mac_m_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+710,0,"dma_m_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+989,0,"dma_m_gnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+711,0,"dma_m_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+712,0,"dma_m_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+713,0,"dma_m_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+714,0,"dma_m_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1102,0,"dma_m_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+715,0,"apb_paddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+716,0,"apb_pwdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+717,0,"apb_bus_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+718,0,"cpu_rdata_apb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+719,0,"apb_psel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+720,0,"apb_penable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+721,0,"apb_pwrite",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+722,0,"apb_pready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+752,0,"cpu_gnt_apb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+723,0,"cpu_rvalid_apb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+724,0,"s_psel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1103,0,"s0_prdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+725,0,"s1_prdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+726,0,"d_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+727,0,"d_dst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+728,0,"d_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+1144,0,"d_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1104,0,"cpu_rdata_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+122,0,"cpu_rvalid_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1105,0,"rst_sync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1106,0,"rst_n_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+762,0,"sel_periph",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+763,0,"sel_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"dma_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_bridge", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+764,0,"obi_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+752,0,"obi_gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+760,0,"obi_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+758,0,"obi_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+761,0,"obi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+723,0,"obi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+718,0,"obi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+715,0,"paddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+719,0,"psel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+720,0,"penable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+721,0,"pwrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+716,0,"pwdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+717,0,"prdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+722,0,"pready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+729,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_bus", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+715,0,"m_paddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+719,0,"m_psel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+720,0,"m_penable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+721,0,"m_pwrite",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+716,0,"m_pwdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+717,0,"m_prdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+722,0,"m_pready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+724,0,"s_psel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1103,0,"s0_prdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"s0_pready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+725,0,"s1_prdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"s1_pready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"s2_prdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"s2_pready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"s3_prdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"s3_pready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"s4_prdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"s4_pready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"s5_prdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"s5_pready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"PMPEnable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1148,0,"PMPGranularity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1149,0,"PMPNumRegions",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1148,0,"MHPMCounterNum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1150,0,"MHPMCounterWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("PMPRstCfg", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+1151,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[8]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[9]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[10]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[11]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[12]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[13]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[14]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[15]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->pushPrefix("PMPRstAddr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declQuad(c+1152+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1184,0,"PMPRstMsecCfg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1147,0,"RV32E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1185,0,"RV32M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1186,0,"RV32B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1187,0,"RV32ZC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1188,0,"RegFile",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+1147,0,"BranchTargetALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"WritebackStage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ICache",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ICacheECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"BranchPredictor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"DbgTriggerEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1189,0,"DbgHwBreakNum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"SecureIbex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1189,0,"LockstepOffset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"MemECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1190,0,"MemDataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ICacheScramble",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1191,0,"ICacheScrNumPrinceRoundsHalf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ICacheTweakInfection",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1192,0,"RndCnstLfsrSeed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1193,0,"RndCnstLfsrPerm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 159,0);
    tracep->declBus(c+1198,0,"DmBaseAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1199,0,"DmAddrMask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1200,0,"DmHaltAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1201,0,"DmExceptionAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declArray(c+1202,0,"RndCnstIbexKey",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declQuad(c+1206,0,"RndCnstIbexNonce",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1146,0,"CsrMvendorId",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"CsrMimpId",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"test_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1209,0,"ram_cfg_icache_tag_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+1210,0,"ram_cfg_rsp_icache_tag_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1209,0,"ram_cfg_icache_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+1210,0,"ram_cfg_rsp_icache_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1146,0,"hart_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"boot_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+756,0,"instr_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1098,0,"instr_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+986,0,"instr_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1211,0,"instr_rdata_intg_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1208,0,"instr_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+757,0,"data_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+987,0,"data_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+988,0,"data_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,0,"data_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+759,0,"data_be_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+760,0,"data_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+761,0,"data_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1211,0,"data_wdata_intg_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1093,0,"data_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1211,0,"data_rdata_intg_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1208,0,"data_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_software_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_timer_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_external_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1212,0,"irq_fast_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+1208,0,"irq_nm_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"scramble_key_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1213,0,"scramble_key_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declQuad(c+1217,0,"scramble_nonce_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+1208,0,"scramble_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"debug_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+632,0,"crash_dump_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 159,0);
    tracep->declBit(c+990,0,"double_fault_seen_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1219,0,"fetch_enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1208,0,"alert_minor_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"alert_major_internal_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"alert_major_bus_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"core_sleep_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"scan_rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1220,0,"lockstep_cmp_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1208,0,"data_req_shadow_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"data_we_shadow_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1221,0,"data_be_shadow_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1146,0,"data_addr_shadow_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"data_wdata_shadow_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1211,0,"data_wdata_intg_shadow_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1208,0,"instr_req_shadow_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"instr_addr_shadow_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1147,0,"Lockstep",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ResetAll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"DummyInstructions",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"RegFileECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"RegFileLockstepECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1190,0,"RegFileDataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1222,0,"RegFileDataEccWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1190,0,"BusSizeECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1223,0,"LineSizeECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1224,0,"TagSizeECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1148,0,"NumAddrScrRounds",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1108,0,"core_busy_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+125,0,"core_busy_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+126,0,"clock_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_pending",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+656,0,"rf_raddr_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+657,0,"rf_raddr_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+658,0,"rf_waddr_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+976,0,"rf_we_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1094,0,"rf_wdata_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+765,0,"rf_rdata_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,0,"rf_rdata_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+761,0,"data_wdata_core",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1093,0,"data_rdata_core",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+986,0,"instr_rdata_core",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1210,0,"ic_tag_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1208,0,"ic_tag_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1225,0,"ic_tag_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1226,0,"ic_tag_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->pushPrefix("ic_tag_rdata", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 21,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1210,0,"ic_data_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1208,0,"ic_data_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1225,0,"ic_data_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+1217,0,"ic_data_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("ic_data_rdata", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+3+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+1208,0,"ic_scr_key_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"core_alert_major_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"core_alert_major_bus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"core_alert_minor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"lockstep_alert_major_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"lockstep_alert_major_bus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"lockstep_alert_minor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1213,0,"scramble_key_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declQuad(c+1217,0,"scramble_nonce_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+1145,0,"scramble_key_valid_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"scramble_key_valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"scramble_req_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"scramble_req_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1219,0,"fetch_enable_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1210,0,"icache_tag_alert",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1210,0,"icache_data_alert",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1208,0,"icache_alert_major_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("core_clock_gate_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"NoFpgaGate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1227,0,"FpgaBufGlobal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1096,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"test_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1107,0,"clk_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1109,0,"en_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("g_clock_en_non_secure", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+127,0,"unused_core_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_no_lockstep", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1145,0,"unused_scan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_non_mem_rdata_ecc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1208,0,"unused_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_norams", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1208,0,"unused_ram_cfg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"unused_ram_inputs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_noscramble", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1208,0,"unused_scramble_inputs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_regfile_ff", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("register_file_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"RV32E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1190,0,"DataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"DummyInstructions",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1146,0,"WordZeroVal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"test_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+656,0,"raddr_a_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+765,0,"rdata_a_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+657,0,"raddr_b_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+766,0,"rdata_b_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+658,0,"waddr_a_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1094,0,"wdata_a_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+976,0,"we_a_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1228,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1190,0,"NUM_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("rf_reg", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+405+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+991,0,"we_a_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+992,0,"unused_strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"unused_test_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("g_normal_r0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1208,0,"unused_dummy_instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[10]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+437,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[11]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+438,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[12]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+439,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[13]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+440,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[14]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+441,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[15]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+442,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[16]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+443,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[17]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+444,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[18]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+445,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[19]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+446,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+447,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[20]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+448,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[21]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+449,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[22]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+450,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[23]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+451,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[24]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+452,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[25]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+453,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[26]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+454,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[27]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+455,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[28]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+456,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[29]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+457,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+458,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[30]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+459,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[31]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+460,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+461,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[4]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+462,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[5]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+463,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[6]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+464,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[7]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+465,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[8]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+466,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_rf_flops[9]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+467,0,"rf_reg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("we_a_decoder", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_fetch_enable_buf", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1229,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1219,0,"in_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1219,0,"out_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1221,0,"inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_ibex_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"PMPEnable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1148,0,"PMPGranularity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1149,0,"PMPNumRegions",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("PMPRstCfg", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+1151,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[8]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[9]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[10]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[11]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[12]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[13]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[14]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[15]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->pushPrefix("PMPRstAddr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declQuad(c+1230+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1184,0,"PMPRstMsecCfg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1148,0,"MHPMCounterNum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1150,0,"MHPMCounterWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"RV32E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1185,0,"RV32M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1186,0,"RV32B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1187,0,"RV32ZC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+1147,0,"BranchTargetALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"WritebackStage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ICache",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ICacheECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ICacheTweakInfection",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1190,0,"BusSizeECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1224,0,"TagSizeECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1223,0,"LineSizeECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"BranchPredictor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"DbgTriggerEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1189,0,"DbgHwBreakNum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ResetAll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1192,0,"RndCnstLfsrSeed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1193,0,"RndCnstLfsrPerm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 159,0);
    tracep->declBit(c+1147,0,"SecureIbex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"DummyInstructions",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"RegFileECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1190,0,"RegFileDataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"MemECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1190,0,"MemDataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1198,0,"DmBaseAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1199,0,"DmAddrMask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1200,0,"DmHaltAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1201,0,"DmExceptionAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1146,0,"CsrMvendorId",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"CsrMimpId",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"hart_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"boot_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+756,0,"instr_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1098,0,"instr_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+986,0,"instr_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"instr_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+757,0,"data_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+987,0,"data_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+988,0,"data_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,0,"data_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+759,0,"data_be_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+760,0,"data_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+761,0,"data_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1093,0,"data_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"data_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+656,0,"rf_raddr_a_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+657,0,"rf_raddr_b_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+658,0,"rf_waddr_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+976,0,"rf_we_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1094,0,"rf_wdata_wb_ecc_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+765,0,"rf_rdata_a_ecc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,0,"rf_rdata_b_ecc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1210,0,"ic_tag_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1208,0,"ic_tag_write_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1225,0,"ic_tag_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1226,0,"ic_tag_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->pushPrefix("ic_tag_rdata_i", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 21,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1210,0,"ic_data_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1208,0,"ic_data_write_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1225,0,"ic_data_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+1217,0,"ic_data_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("ic_data_rdata_i", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+3+i*2,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+1145,0,"ic_scr_key_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"ic_scr_key_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_software_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_timer_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_external_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1212,0,"irq_fast_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+1208,0,"irq_nm_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_pending_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"debug_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+632,0,"crash_dump_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 159,0);
    tracep->declBit(c+990,0,"double_fault_seen_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1219,0,"fetch_enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1208,0,"alert_minor_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"alert_major_internal_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"alert_major_bus_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1108,0,"core_busy_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1262,0,"PMPNumChan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"DataIndTiming",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"PCIncrCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ShadowCSR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+693,0,"instr_valid_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+468,0,"instr_new_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+659,0,"instr_rdata_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+659,0,"instr_rdata_alu_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+660,0,"instr_rdata_c_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+661,0,"instr_is_compressed_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+662,0,"instr_gets_expanded_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+663,0,"instr_expanded_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+1110,0,"instr_perf_count_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"instr_bp_taken_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+664,0,"instr_fetch_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+665,0,"instr_fetch_err_plus2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+666,0,"illegal_c_insn_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+667,0,"pc_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+668,0,"pc_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"pc_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("imd_val_d_ex", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+767+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("imd_val_q_ex", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+469+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+771,0,"imd_val_we_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+473,0,"data_ind_timing",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+474,0,"dummy_instr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+475,0,"dummy_instr_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1208,0,"dummy_instr_seed_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"dummy_instr_seed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1111,0,"icache_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+772,0,"icache_inval",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"icache_ecc_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"pc_mismatch_alert",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"csr_shadow_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+694,0,"instr_first_cycle_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+993,0,"instr_valid_clear",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"pc_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"nt_branch_mispredict",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"nt_branch_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+774,0,"pc_mux_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+695,0,"exc_pc_mux_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+775,0,"exc_cause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1208,0,"instr_intg_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+994,0,"lsu_load_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+994,0,"lsu_load_err_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+995,0,"lsu_store_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+995,0,"lsu_store_err_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"lsu_load_resp_intg_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"lsu_store_resp_intg_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1112,0,"expecting_load_resp_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1113,0,"expecting_store_resp_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+476,0,"lsu_addr_incr_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+477,0,"lsu_addr_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+776,0,"branch_target_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+777,0,"branch_decision",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+696,0,"ctrl_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+639,0,"if_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+478,0,"lsu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+656,0,"rf_raddr_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+765,0,"rf_rdata_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+657,0,"rf_raddr_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+766,0,"rf_rdata_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1114,0,"rf_ren_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1115,0,"rf_ren_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+658,0,"rf_waddr_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1094,0,"rf_wdata_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"rf_wdata_fwd_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1095,0,"rf_wdata_lsu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+976,0,"rf_we_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+996,0,"rf_we_lsu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"rf_ecc_err_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+658,0,"rf_waddr_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+778,0,"rf_wdata_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+779,0,"rf_we_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"rf_rd_a_wb_match",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"rf_rd_b_wb_match",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+780,0,"alu_operator_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+781,0,"alu_operand_a_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+782,0,"alu_operand_b_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"bt_a_operand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"bt_b_operand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+776,0,"alu_adder_result_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+783,0,"result_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+784,0,"mult_en_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+785,0,"div_en_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+786,0,"mult_sel_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,0,"div_sel_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+788,0,"multdiv_operator_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+789,0,"multdiv_signed_mode_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+765,0,"multdiv_operand_a_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,0,"multdiv_operand_b_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"multdiv_ready_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+790,0,"csr_access",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+791,0,"csr_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+997,0,"csr_op_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+669,0,"csr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+792,0,"csr_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+781,0,"csr_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+793,0,"illegal_csr_insn_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,0,"lsu_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+794,0,"lsu_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+795,0,"lsu_sign_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+796,0,"lsu_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+996,0,"lsu_rdata_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+766,0,"lsu_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1116,0,"lsu_req_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+998,0,"id_in_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+797,0,"ex_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+999,0,"lsu_resp_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1000,0,"lsu_resp_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+697,0,"instr_req_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+697,0,"instr_req_gated",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"instr_exec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1001,0,"en_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1263,0,"instr_type_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1145,0,"ready_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"rf_write_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"outstanding_load_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"outstanding_store_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+479,0,"nmi_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1264,0,"irqs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBit(c+480,0,"csr_mstatus_mie",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+481,0,"csr_mepc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+482,0,"csr_depc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("csr_pmp_addr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+7+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("csr_pmp_cfg", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+15,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+16,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+17,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+18,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->declBus(c+1184,0,"csr_pmp_mseccfg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("pmp_req_err", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+19+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+757,0,"data_req_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+698,0,"csr_save_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+798,0,"csr_save_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"csr_save_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+799,0,"csr_restore_mret_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+800,0,"csr_restore_dret_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+801,0,"csr_save_cause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+802,0,"csr_mtvec_init",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+483,0,"csr_mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+803,0,"csr_mtval",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+484,0,"csr_mstatus_tw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+485,0,"priv_mode_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+486,0,"priv_mode_lsu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+487,0,"debug_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+699,0,"debug_mode_entering",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+488,0,"debug_cause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+700,0,"debug_csr_save",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+489,0,"debug_single_step",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+490,0,"debug_ebreakm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+491,0,"debug_ebreaku",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"trigger_match",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1001,0,"instr_id_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"instr_done_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1002,0,"perf_instr_ret_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1117,0,"perf_instr_ret_compressed_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"perf_instr_ret_wb_spec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"perf_instr_ret_compressed_wb_spec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1118,0,"perf_iside_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+977,0,"perf_dside_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+978,0,"perf_mul_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+979,0,"perf_div_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+804,0,"perf_jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+805,0,"perf_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+806,0,"perf_tbranch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+807,0,"perf_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+808,0,"perf_store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+809,0,"illegal_insn_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+809,0,"unused_illegal_insn_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+492,0,"crash_dump_mtval",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+468,0,"unused_instr_new_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1001,0,"unused_instr_id_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"unused_instr_done_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+670,0,"unused_instr_expanded_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+671,0,"unused_instr_gets_expanded_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("cs_registers_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"DbgTriggerEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1189,0,"DbgHwBreakNum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"DataIndTiming",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"DummyInstructions",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ShadowCSR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ICache",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1148,0,"MHPMCounterNum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1150,0,"MHPMCounterWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"PMPEnable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1148,0,"PMPGranularity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1149,0,"PMPNumRegions",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("PMPRstCfg", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+1151,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[8]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[9]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[10]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[11]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[12]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[13]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[14]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[15]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->pushPrefix("PMPRstAddr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declQuad(c+1265+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1184,0,"PMPRstMsecCfg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1147,0,"RV32E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1185,0,"RV32M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1186,0,"RV32B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1146,0,"CsrMvendorId",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"CsrMimpId",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"hart_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+485,0,"priv_mode_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+486,0,"priv_mode_lsu_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+484,0,"csr_mstatus_tw_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+483,0,"csr_mtvec_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+802,0,"csr_mtvec_init_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"boot_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+790,0,"csr_access_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+669,0,"csr_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+781,0,"csr_wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+791,0,"csr_op_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+997,0,"csr_op_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+792,0,"csr_rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"irq_software_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_timer_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_external_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1212,0,"irq_fast_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+479,0,"nmi_mode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_pending_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1264,0,"irqs_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBit(c+480,0,"csr_mstatus_mie_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+481,0,"csr_mepc_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+492,0,"csr_mtval_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("csr_pmp_cfg_o", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+15,0,"[0]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+16,0,"[1]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+17,0,"[2]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+18,0,"[3]",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->pushPrefix("csr_pmp_addr_o", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+7+i*2,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1184,0,"csr_pmp_mseccfg_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+487,0,"debug_mode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+699,0,"debug_mode_entering_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+488,0,"debug_cause_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+700,0,"debug_csr_save_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+482,0,"csr_depc_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+489,0,"debug_single_step_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+490,0,"debug_ebreakm_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+491,0,"debug_ebreaku_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"trigger_match_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+667,0,"pc_if_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+668,0,"pc_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"pc_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+473,0,"data_ind_timing_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+474,0,"dummy_instr_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+475,0,"dummy_instr_mask_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1208,0,"dummy_instr_seed_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"dummy_instr_seed_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1111,0,"icache_enable_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"csr_shadow_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"ic_scr_key_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+698,0,"csr_save_if_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+798,0,"csr_save_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"csr_save_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+799,0,"csr_restore_mret_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+800,0,"csr_restore_dret_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+801,0,"csr_save_cause_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+775,0,"csr_mcause_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+803,0,"csr_mtval_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+793,0,"illegal_csr_insn_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+990,0,"double_fault_seen_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1002,0,"instr_ret_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1117,0,"instr_ret_compressed_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"instr_ret_spec_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"instr_ret_compressed_spec_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1118,0,"iside_wait_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+804,0,"jump_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+805,0,"branch_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+806,0,"branch_taken_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+807,0,"mem_load_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+808,0,"mem_store_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+977,0,"dside_wait_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+978,0,"mul_wait_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+979,0,"div_wait_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1148,0,"RV32BExtra",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1189,0,"RV32MEnabled",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1190,0,"PMPAddrWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1297,0,"MISA_VALUE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+810,0,"exception_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+485,0,"priv_lvl_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+811,0,"priv_lvl_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+493,0,"mstatus_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1003,0,"mstatus_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+1208,0,"mstatus_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1004,0,"mstatus_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+494,0,"mie_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBus(c+812,0,"mie_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBit(c+1005,0,"mie_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+495,0,"mscratch_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1006,0,"mscratch_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+481,0,"mepc_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+813,0,"mepc_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1007,0,"mepc_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+496,0,"mcause_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1008,0,"mcause_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1009,0,"mcause_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+492,0,"mtval_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+814,0,"mtval_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1010,0,"mtval_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+483,0,"mtvec_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+815,0,"mtvec_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"mtvec_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1011,0,"mtvec_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1298,0,"mip",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBus(c+497,0,"dcsr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1012,0,"dcsr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1013,0,"dcsr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+482,0,"depc_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+816,0,"depc_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1014,0,"depc_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+498,0,"dscratch0_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+499,0,"dscratch1_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1015,0,"dscratch0_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1016,0,"dscratch1_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+500,0,"mstack_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+501,0,"mstack_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+817,0,"mstack_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+502,0,"mstack_epc_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+481,0,"mstack_epc_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+503,0,"mstack_cause_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+496,0,"mstack_cause_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->pushPrefix("pmp_addr_rdata", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+22+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("pmp_cfg_rdata", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+38+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+1208,0,"pmp_csr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1299,0,"pmp_mseccfg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+504,0,"mcountinhibit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1119,0,"mcountinhibit_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+505,0,"mcountinhibit_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1017,0,"mcountinhibit_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("mhpmcounter", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declQuad(c+506+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1018,0,"mhpmcounter_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1019,0,"mhpmcounterh_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1020,0,"mhpmcounter_incr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("mhpmevent", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+54+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+657,0,"mhpmcounter_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1021,0,"unused_mhpmcounter_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1022,0,"unused_mhpmcounterh_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1023,0,"unused_mhpmcounter_incr_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+570,0,"minstret_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+572,0,"minstret_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1146,0,"tselect_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"tmatch_control_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"tmatch_value_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+574,0,"cpuctrlsts_part_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1024,0,"cpuctrlsts_part_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+818,0,"cpuctrlsts_part_wdata_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+819,0,"cpuctrlsts_part_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1025,0,"cpuctrlsts_part_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"cpuctrlsts_part_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"cpuctrlsts_ic_scr_key_valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"cpuctrlsts_ic_scr_key_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+820,0,"csr_wdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+792,0,"csr_rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1026,0,"csr_we_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+821,0,"csr_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+672,0,"dbg_csr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+673,0,"illegal_csr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+637,0,"illegal_csr_priv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+638,0,"illegal_csr_dbg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1120,0,"illegal_csr_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1225,0,"unused_boot_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+674,0,"unused_csr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+669,0,"csr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+1300,0,"MSTATUS_RST_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1301,0,"DCSR_RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1302,0,"MSTACK_RESET_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("g_mcountinhibit_reduced", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1027,0,"unused_mhphcounter_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBus(c+1028,0,"unused_mhphcounterh_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBus(c+1029,0,"unused_mhphcounter_incr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1303,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[10]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1304,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[11]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1305,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[12]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1306,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[13]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1307,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[14]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1308,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[15]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1309,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[16]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1310,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[17]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1311,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[18]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1312,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[19]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1313,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1229,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[20]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1314,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[21]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1315,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[22]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1316,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[23]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1317,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[24]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1318,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[25]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1319,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[26]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1320,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[27]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1321,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[28]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1322,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1323,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1324,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[4]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1325,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[5]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1326,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[6]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1327,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[7]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1328,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("gen_unimp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("gen_no_compressed_instr_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1208,0,"unused_instr_ret_compressed_spec_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[8]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1329,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_cntrs[9]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1330,0,"Cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_mhpmcounter_incr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_mhpmevent", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1331,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_no_dit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+822,0,"unused_dit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_no_dummy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+823,0,"unused_dummy_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+824,0,"unused_dummy_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_no_icache", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+825,0,"unused_icen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"unused_ic_scr_key_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mcycle_counter_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1332,0,"CounterWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ProvideValUpd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+651,0,"counter_inc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1030,0,"counterh_we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1031,0,"counter_we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+820,0,"counter_val_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+575,0,"counter_val_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+1217,0,"counter_val_upd_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+575,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+577,0,"counter_upd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+1032,0,"counter_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+1034,0,"we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+1035,0,"counter_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1333,0,"UseDsp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declQuad(c+575,0,"counter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->pushPrefix("minstret_counter_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1332,0,"CounterWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1227,0,"ProvideValUpd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+652,0,"counter_inc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1037,0,"counterh_we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1038,0,"counter_we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+820,0,"counter_val_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+572,0,"counter_val_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+570,0,"counter_val_upd_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+572,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+570,0,"counter_upd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+1039,0,"counter_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+1041,0,"we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+1042,0,"counter_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1333,0,"UseDsp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declQuad(c+572,0,"counter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_cpuctrlsts_part_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1334,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1335,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 7,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1024,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1025,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+574,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+574,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_dcsr_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1336,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1012,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1013,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+497,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+497,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_depc_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1337,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+816,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1014,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+482,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+482,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_dscratch0_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1337,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+820,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1015,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+498,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+498,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_dscratch1_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1337,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+820,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1016,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+499,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+499,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mcause_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1338,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1339,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 6,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1008,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1009,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+496,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+496,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mepc_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1337,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+813,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1007,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+481,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+481,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mie_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1340,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1341,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 17,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+812,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBit(c+1005,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+494,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+494,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mscratch_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1337,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+820,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1006,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+495,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+495,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mstack_cause_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1338,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1339,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 6,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+496,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+817,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+503,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+503,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mstack_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1262,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1342,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 2,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+501,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+817,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+500,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+500,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mstack_epc_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1337,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+481,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+817,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+502,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+502,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mstatus_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1343,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1344,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 5,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1003,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+1004,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+493,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+493,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mtval_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1337,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+814,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1010,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+492,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+492,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mtvec_csr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ShadowCopy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1345,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+815,0,"wr_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1011,0,"wr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+483,0,"rd_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"rd_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+483,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("ex_block_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1185,0,"RV32M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1186,0,"RV32B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+1147,0,"BranchTargetALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+780,0,"alu_operator_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+781,0,"alu_operand_a_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+782,0,"alu_operand_b_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+694,0,"alu_instr_first_cycle_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"bt_a_operand_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"bt_b_operand_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+788,0,"multdiv_operator_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+784,0,"mult_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+785,0,"div_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+786,0,"mult_sel_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,0,"div_sel_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+789,0,"multdiv_signed_mode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+765,0,"multdiv_operand_a_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,0,"multdiv_operand_b_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"multdiv_ready_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+473,0,"data_ind_timing_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+771,0,"imd_val_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("imd_val_d_o", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+767+i*2,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("imd_val_q_i", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+469+i*2,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+776,0,"alu_adder_result_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+783,0,"result_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+776,0,"branch_target_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+777,0,"branch_decision_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+797,0,"ex_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+826,0,"alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+640,0,"multdiv_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+827,0,"multdiv_alu_operand_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+579,0,"multdiv_alu_operand_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+829,0,"alu_adder_result_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBit(c+777,0,"alu_cmp_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+831,0,"alu_is_equal_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+641,0,"multdiv_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+832,0,"multdiv_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("alu_imd_val_q", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+581+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("alu_imd_val_d", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+86+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1210,0,"alu_imd_val_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("multdiv_imd_val_d", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+833+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+837,0,"multdiv_imd_val_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("alu_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1186,0,"RV32B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+780,0,"operator_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+781,0,"operand_a_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+782,0,"operand_b_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+694,0,"instr_first_cycle_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+579,0,"multdiv_operand_a_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+827,0,"multdiv_operand_b_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+832,0,"multdiv_sel_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("imd_val_q_i", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+581+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("imd_val_d_o", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+86+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1210,0,"imd_val_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+776,0,"adder_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+829,0,"adder_result_ext_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBus(c+826,0,"result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+777,0,"comparison_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+831,0,"is_equal_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+838,0,"operand_a_rev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+839,0,"operand_b_neg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+841,0,"adder_op_a_shift1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+842,0,"adder_op_a_shift2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+843,0,"adder_op_a_shift3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+844,0,"adder_op_b_negate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+642,0,"adder_in_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+845,0,"adder_in_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+776,0,"adder_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+831,0,"is_equal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+847,0,"is_greater_equal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+848,0,"cmp_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+777,0,"cmp_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+849,0,"shift_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"shift_ones",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+850,0,"shift_arith",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"shift_funnel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"shift_sbmode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1121,0,"shift_amt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+851,0,"shift_amt_compl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+852,0,"shift_operand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+853,0,"shift_result_ext_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+855,0,"shift_result_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+857,0,"unused_shift_result_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+858,0,"shift_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+859,0,"shift_result_rev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"bfp_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+860,0,"bfp_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+861,0,"bfp_off",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1146,0,"bfp_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"bfp_mask_rev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"bfp_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+862,0,"bwlogic_or",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+863,0,"bwlogic_and",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+782,0,"bwlogic_operand_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+864,0,"bwlogic_or_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+865,0,"bwlogic_and_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+866,0,"bwlogic_xor_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+867,0,"bwlogic_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"bwlogic_op_b_negate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1346,0,"bitcnt_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1146,0,"minmax_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"pack_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"sext_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"singlebit_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"rev_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"shuffle_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"xperm_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"butterfly_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"invbutterfly_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"clmul_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"multicycle_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+868,0,"unused_shift_amt_compl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("g_no_alu_rvb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unused_imd_val_q", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+583+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1146,0,"unused_butterfly_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"unused_invbutterfly_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1190,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("g_no_branch_target_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1146,0,"unused_bt_a_operand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"unused_bt_b_operand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_multdiv_fast", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("multdiv_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1185,0,"RV32M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+784,0,"mult_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+785,0,"div_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+786,0,"mult_sel_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,0,"div_sel_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+788,0,"operator_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+789,0,"signed_mode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+765,0,"op_a_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,0,"op_b_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+829,0,"alu_adder_ext_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBus(c+776,0,"alu_adder_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+831,0,"equal_to_zero_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+473,0,"data_ind_timing_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+579,0,"alu_operand_a_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+827,0,"alu_operand_b_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->pushPrefix("imd_val_q_i", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+469+i*2,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("imd_val_d_o", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+833+i*2,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+837,0,"imd_val_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1145,0,"multdiv_ready_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+640,0,"multdiv_result_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+641,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+869,0,"mac_res_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 34,0);
    tracep->declQuad(c+869,0,"mac_res_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 34,0);
    tracep->declQuad(c+871,0,"accum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBit(c+873,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+874,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+875,0,"mult_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+876,0,"signed_mult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+877,0,"mac_res_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+879,0,"op_remainder_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+881,0,"mac_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBit(c+883,0,"div_sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+884,0,"div_sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+885,0,"is_greater_equal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+644,0,"div_change_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+883,0,"rem_change_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+585,0,"one_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+586,0,"op_denominator_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+587,0,"op_numerator_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+588,0,"op_quotient_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+886,0,"op_denominator_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+887,0,"op_numerator_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+888,0,"op_quotient_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+889,0,"next_remainder",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+890,0,"next_quotient",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+776,0,"res_adder_h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+589,0,"div_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+590,0,"div_counter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+892,0,"div_counter_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+893,0,"multdiv_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+894,0,"mult_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+591,0,"div_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+895,0,"div_by_zero_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+592,0,"div_by_zero_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+896,0,"mult_en_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+897,0,"div_en_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+593,0,"sva_mul_fsm_idle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+594,0,"md_state_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+898,0,"md_state_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+786,0,"unused_mult_sel_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+595,0,"unused_imd_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+899,0,"unused_mac_res_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+900,0,"unused_alu_adder_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+593,0,"unused_sva_mul_fsm_idle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_mult_fast", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+901,0,"mult_op_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+902,0,"mult_op_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+596,0,"mult_state_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+903,0,"mult_state_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("g_instr_req_gated_non_secure", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1145,0,"unused_fetch_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("g_no_check_mem_response", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1112,0,"unused_expecting_load_resp_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1113,0,"unused_expecting_store_resp_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("g_no_pmp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+486,0,"unused_priv_lvl_ls",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("unused_csr_pmp_addr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+88+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unused_csr_pmp_cfg", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+96,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+97,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+98,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+99,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->declBus(c+1184,0,"unused_csr_pmp_mseccfg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_no_regfile_ecc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1114,0,"unused_rf_ren_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1115,0,"unused_rf_ren_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"unused_rf_rd_a_wb_match",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"unused_rf_rd_b_wb_match",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("id_stage_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"RV32E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1185,0,"RV32M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1186,0,"RV32B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+1147,0,"DataIndTiming",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"BranchTargetALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"WritebackStage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"BranchPredictor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"MemECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+696,0,"ctrl_busy_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+809,0,"illegal_insn_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+693,0,"instr_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+659,0,"instr_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+659,0,"instr_rdata_alu_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+660,0,"instr_rdata_c_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+661,0,"instr_is_compressed_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"instr_bp_taken_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+697,0,"instr_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+694,0,"instr_first_cycle_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+993,0,"instr_valid_clear_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+998,0,"id_in_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"instr_exec_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+772,0,"icache_inval_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+777,0,"branch_decision_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"pc_set_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+774,0,"pc_mux_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1208,0,"nt_branch_mispredict_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"nt_branch_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+695,0,"exc_pc_mux_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+775,0,"exc_cause_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+666,0,"illegal_c_insn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+664,0,"instr_fetch_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+665,0,"instr_fetch_err_plus2_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+668,0,"pc_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+797,0,"ex_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+999,0,"lsu_resp_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+780,0,"alu_operator_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+781,0,"alu_operand_a_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+782,0,"alu_operand_b_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+771,0,"imd_val_we_ex_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("imd_val_d_ex_i", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+767+i*2,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("imd_val_q_ex_o", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+469+i*2,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1146,0,"bt_a_operand_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"bt_b_operand_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+784,0,"mult_en_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+785,0,"div_en_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+786,0,"mult_sel_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,0,"div_sel_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+788,0,"multdiv_operator_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+789,0,"multdiv_signed_mode_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+765,0,"multdiv_operand_a_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,0,"multdiv_operand_b_ex_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"multdiv_ready_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+790,0,"csr_access_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+791,0,"csr_op_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+669,0,"csr_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+997,0,"csr_op_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+698,0,"csr_save_if_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+798,0,"csr_save_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"csr_save_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+799,0,"csr_restore_mret_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+800,0,"csr_restore_dret_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+801,0,"csr_save_cause_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+803,0,"csr_mtval_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+485,0,"priv_mode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+484,0,"csr_mstatus_tw_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+793,0,"illegal_csr_insn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+473,0,"data_ind_timing_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+796,0,"lsu_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,0,"lsu_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+794,0,"lsu_type_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+795,0,"lsu_sign_ext_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+766,0,"lsu_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1116,0,"lsu_req_done_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+476,0,"lsu_addr_incr_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+477,0,"lsu_addr_last_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+480,0,"csr_mstatus_mie_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_pending_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1264,0,"irqs_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBit(c+1208,0,"irq_nm_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+479,0,"nmi_mode_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+994,0,"lsu_load_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"lsu_load_resp_intg_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+995,0,"lsu_store_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"lsu_store_resp_intg_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1112,0,"expecting_load_resp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1113,0,"expecting_store_resp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+487,0,"debug_mode_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+699,0,"debug_mode_entering_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+488,0,"debug_cause_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+700,0,"debug_csr_save_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"debug_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+489,0,"debug_single_step_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+490,0,"debug_ebreakm_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+491,0,"debug_ebreaku_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"trigger_match_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+783,0,"result_ex_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+792,0,"csr_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+656,0,"rf_raddr_a_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+765,0,"rf_rdata_a_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+657,0,"rf_raddr_b_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+766,0,"rf_rdata_b_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1114,0,"rf_ren_a_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1115,0,"rf_ren_b_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+658,0,"rf_waddr_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+778,0,"rf_wdata_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+779,0,"rf_we_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"rf_rd_a_wb_match_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"rf_rd_b_wb_match_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+658,0,"rf_waddr_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1146,0,"rf_wdata_fwd_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"rf_write_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1001,0,"en_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1263,0,"instr_type_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1110,0,"instr_perf_count_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"ready_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"outstanding_load_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"outstanding_store_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+804,0,"perf_jump_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+805,0,"perf_branch_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+806,0,"perf_tbranch_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+977,0,"perf_dside_wait_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+978,0,"perf_mul_wait_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+979,0,"perf_div_wait_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1001,0,"instr_id_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+904,0,"illegal_insn_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+645,0,"illegal_dret_insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+646,0,"illegal_umode_insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+905,0,"ebrk_insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+906,0,"mret_insn_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+907,0,"dret_insn_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+908,0,"ecall_insn_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+909,0,"wfi_insn_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"wb_exception",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+910,0,"id_exception",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+911,0,"branch_in_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+597,0,"branch_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+598,0,"branch_set_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+912,0,"branch_set_raw_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+599,0,"branch_jump_set_done_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1122,0,"branch_jump_set_done_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"branch_not_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+913,0,"jump_in_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+914,0,"jump_set_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+915,0,"jump_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+916,0,"jump_set_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+694,0,"instr_first_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+917,0,"instr_executing_spec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+917,0,"instr_executing",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1001,0,"instr_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+701,0,"controller_run",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"stall_ld_hz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1123,0,"stall_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1044,0,"stall_multdiv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1045,0,"stall_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1046,0,"stall_jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1047,0,"stall_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"stall_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+918,0,"flush_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1048,0,"multicycle_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"mem_resp_intg_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+675,0,"imm_i_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+676,0,"imm_s_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+677,0,"imm_b_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+678,0,"imm_u_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+679,0,"imm_j_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+680,0,"zimm_rs1_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1124,0,"imm_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+919,0,"imm_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+920,0,"rf_wdata_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+921,0,"rf_we_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+922,0,"rf_we_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1114,0,"rf_ren_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1115,0,"rf_ren_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+923,0,"rf_ren_a_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+924,0,"rf_ren_b_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+765,0,"rf_rdata_a_fwd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,0,"rf_rdata_b_fwd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+780,0,"alu_operator",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+925,0,"alu_op_a_mux_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+926,0,"alu_op_a_mux_sel_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+647,0,"alu_op_b_mux_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+927,0,"alu_op_b_mux_sel_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"alu_multicycle_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"stall_alu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("imd_val_q", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+600+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1347,0,"bt_a_mux_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1348,0,"bt_b_mux_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+928,0,"imm_a_mux_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+929,0,"imm_b_mux_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+930,0,"imm_b_mux_sel_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+784,0,"mult_en_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+931,0,"mult_en_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+785,0,"div_en_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+932,0,"div_en_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+933,0,"multdiv_en_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+788,0,"multdiv_operator",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+789,0,"multdiv_signed_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+758,0,"lsu_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+794,0,"lsu_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+795,0,"lsu_sign_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+796,0,"lsu_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+934,0,"lsu_req_dec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+694,0,"data_req_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+681,0,"no_flush_csr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1125,0,"csr_pipe_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+781,0,"alu_operand_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+782,0,"alu_operand_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+604,0,"id_fsm_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1049,0,"id_fsm_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("controller_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"WritebackStage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"BranchPredictor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"MemECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+696,0,"ctrl_busy_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+809,0,"illegal_insn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+908,0,"ecall_insn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+906,0,"mret_insn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+907,0,"dret_insn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+909,0,"wfi_insn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+905,0,"ebrk_insn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1125,0,"csr_pipe_flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+693,0,"instr_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+659,0,"instr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+660,0,"instr_compressed_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+661,0,"instr_is_compressed_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"instr_bp_taken_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+664,0,"instr_fetch_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+665,0,"instr_fetch_err_plus2_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+668,0,"pc_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+993,0,"instr_valid_clear_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+998,0,"id_in_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+701,0,"controller_run_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"instr_exec_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+697,0,"instr_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"pc_set_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+774,0,"pc_mux_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1208,0,"nt_branch_mispredict_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+695,0,"exc_pc_mux_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+775,0,"exc_cause_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+477,0,"lsu_addr_last_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+994,0,"load_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+995,0,"store_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"mem_resp_intg_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"wb_exception_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+910,0,"id_exception_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+597,0,"branch_set_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"branch_not_set_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+915,0,"jump_set_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+480,0,"csr_mstatus_mie_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_pending_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1264,0,"irqs_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBit(c+1208,0,"irq_nm_ext_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+479,0,"nmi_mode_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"debug_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+488,0,"debug_cause_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+700,0,"debug_csr_save_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+487,0,"debug_mode_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+699,0,"debug_mode_entering_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+489,0,"debug_single_step_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+490,0,"debug_ebreakm_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+491,0,"debug_ebreaku_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"trigger_match_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+698,0,"csr_save_if_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+798,0,"csr_save_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"csr_save_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+799,0,"csr_restore_mret_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+800,0,"csr_restore_dret_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+801,0,"csr_save_cause_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+803,0,"csr_mtval_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+485,0,"priv_mode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1047,0,"stall_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"stall_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+918,0,"flush_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"ready_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+804,0,"perf_jump_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+806,0,"perf_tbranch_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+702,0,"ctrl_fsm_cs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1050,0,"ctrl_fsm_ns",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+479,0,"nmi_mode_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+935,0,"nmi_mode_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+487,0,"debug_mode_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+936,0,"debug_mode_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1126,0,"debug_cause_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+488,0,"debug_cause_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+605,0,"load_err_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+994,0,"load_err_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+606,0,"store_err_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+995,0,"store_err_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+607,0,"exc_req_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+910,0,"exc_req_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+608,0,"illegal_insn_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+937,0,"illegal_insn_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+938,0,"instr_fetch_err_prio",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+939,0,"illegal_insn_prio",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+940,0,"ecall_insn_prio",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+941,0,"ebrk_insn_prio",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+942,0,"store_err_prio",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+943,0,"load_err_prio",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1047,0,"stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1051,0,"halt_if",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1052,0,"retain_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+918,0,"flush_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1000,0,"exc_req_lsu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1053,0,"special_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+980,0,"special_req_pc_change",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1127,0,"special_req_flush_only",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+703,0,"do_single_step_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+609,0,"do_single_step_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+704,0,"enter_debug_mode_prio_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+610,0,"enter_debug_mode_prio_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+704,0,"enter_debug_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+611,0,"ebreak_into_debug",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+612,0,"irq_enabled",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"handle_irq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+693,0,"id_wb_pending",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_nm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"irq_nm_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"irq_nm_int_mtval",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1349,0,"irq_nm_int_cause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1221,0,"mfip_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1208,0,"unused_irq_timer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+944,0,"ecall_insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+945,0,"mret_insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+946,0,"dret_insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+947,0,"wfi_insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+948,0,"ebrk_insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1128,0,"csr_pipe_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+949,0,"instr_fetch_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("g_no_intg_irq_int", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1208,0,"unused_mem_resp_intg_err_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_mfip_id", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1350,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("decoder_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"RV32E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1185,0,"RV32M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1186,0,"RV32B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+1147,0,"BranchTargetALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+904,0,"illegal_insn_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+905,0,"ebrk_insn_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+906,0,"mret_insn_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+907,0,"dret_insn_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+908,0,"ecall_insn_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+909,0,"wfi_insn_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+914,0,"jump_set_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"branch_taken_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+772,0,"icache_inval_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+694,0,"instr_first_cycle_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+659,0,"instr_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+659,0,"instr_rdata_alu_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+666,0,"illegal_c_insn_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+928,0,"imm_a_mux_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+930,0,"imm_b_mux_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1347,0,"bt_a_mux_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1348,0,"bt_b_mux_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+675,0,"imm_i_type_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+676,0,"imm_s_type_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+677,0,"imm_b_type_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+678,0,"imm_u_type_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+679,0,"imm_j_type_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+680,0,"zimm_rs1_type_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+920,0,"rf_wdata_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+921,0,"rf_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+656,0,"rf_raddr_a_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+657,0,"rf_raddr_b_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+658,0,"rf_waddr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+923,0,"rf_ren_a_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+924,0,"rf_ren_b_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+780,0,"alu_operator_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+926,0,"alu_op_a_mux_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+927,0,"alu_op_b_mux_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"alu_multicycle_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+931,0,"mult_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+932,0,"div_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+786,0,"mult_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+787,0,"div_sel_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+788,0,"multdiv_operator_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+789,0,"multdiv_signed_mode_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+790,0,"csr_access_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+791,0,"csr_op_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+669,0,"csr_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+934,0,"data_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,0,"data_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+794,0,"data_type_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+795,0,"data_sign_extension_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+913,0,"jump_in_dec_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+911,0,"branch_in_dec_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+904,0,"illegal_insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"illegal_reg_rv32e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+950,0,"csr_illegal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+921,0,"rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+659,0,"instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+659,0,"instr_alu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+682,0,"unused_instr_alu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+656,0,"instr_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+657,0,"instr_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+683,0,"instr_rs3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+658,0,"instr_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1208,0,"use_rs3_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"use_rs3_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+951,0,"csr_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+952,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+953,0,"opcode_alu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->pushPrefix("gen_no_rs3_flop", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1107,0,"unused_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"unused_rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("g_branch_set_flop", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+598,0,"branch_set_raw_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("g_nobtalu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1347,0,"unused_a_mux_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1348,0,"unused_b_mux_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_no_stall_mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1116,0,"unused_data_req_done_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+658,0,"unused_rf_waddr_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1208,0,"unused_rf_write_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"unused_outstanding_load_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"unused_outstanding_store_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"unused_wb_exception",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"unused_rf_wdata_fwd_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+910,0,"unused_id_exception",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("if_stage_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1200,0,"DmHaltAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1201,0,"DmExceptionAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"DummyInstructions",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ICache",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1187,0,"RV32ZC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ICacheECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ICacheTweakInfection",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1190,0,"BusSizeECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1224,0,"TagSizeECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1223,0,"LineSizeECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"PCIncrCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"ResetAll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1192,0,"RndCnstLfsrSeed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1193,0,"RndCnstLfsrPerm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 159,0);
    tracep->declBit(c+1147,0,"BranchPredictor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"MemECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1190,0,"MemDataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"boot_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+697,0,"req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1098,0,"instr_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+756,0,"instr_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+986,0,"instr_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"instr_bus_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"instr_intg_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1210,0,"ic_tag_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1208,0,"ic_tag_write_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1225,0,"ic_tag_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1226,0,"ic_tag_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->pushPrefix("ic_tag_rdata_i", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 21,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1210,0,"ic_data_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1208,0,"ic_data_write_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1225,0,"ic_data_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+1217,0,"ic_data_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("ic_data_rdata_i", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+3+i*2,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+1145,0,"ic_scr_key_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"ic_scr_key_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+693,0,"instr_valid_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+468,0,"instr_new_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+659,0,"instr_rdata_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+659,0,"instr_rdata_alu_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+660,0,"instr_rdata_c_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+661,0,"instr_is_compressed_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+662,0,"instr_gets_expanded_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+663,0,"instr_expanded_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+1208,0,"instr_bp_taken_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+664,0,"instr_fetch_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+665,0,"instr_fetch_err_plus2_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+666,0,"illegal_c_insn_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+667,0,"pc_if_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+668,0,"pc_id_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"pmp_err_if_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"pmp_err_if_plus2_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+993,0,"instr_valid_clear_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"pc_set_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+774,0,"pc_mux_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1208,0,"nt_branch_mispredict_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"nt_branch_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+695,0,"exc_pc_mux_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+775,0,"exc_cause",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+474,0,"dummy_instr_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+475,0,"dummy_instr_mask_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1208,0,"dummy_instr_seed_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"dummy_instr_seed_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1111,0,"icache_enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+772,0,"icache_inval_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"icache_ecc_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+776,0,"branch_target_ex_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+481,0,"csr_mepc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+482,0,"csr_depc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+483,0,"csr_mtvec_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+802,0,"csr_mtvec_init_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+998,0,"id_in_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"pc_mismatch_alert_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+639,0,"if_busy_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1129,0,"instr_valid_id_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+693,0,"instr_valid_id_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1054,0,"instr_new_id_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+468,0,"instr_new_id_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"instr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"instr_intg_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+639,0,"prefetch_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"branch_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+648,0,"fetch_addr_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+649,0,"unused_fetch_addr_n0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"prefetch_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+954,0,"prefetch_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1055,0,"fetch_valid_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1055,0,"fetch_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1056,0,"fetch_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1057,0,"fetch_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+667,0,"fetch_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1058,0,"fetch_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1130,0,"fetch_err_plus2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1059,0,"instr_decompressed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1060,0,"illegal_c_insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1061,0,"instr_is_compressed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1062,0,"instr_gets_expanded",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1055,0,"if_instr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1057,0,"if_instr_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+667,0,"if_instr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1058,0,"if_instr_bus_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"if_instr_pmp_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1058,0,"if_instr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1130,0,"if_instr_err_plus2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+955,0,"exc_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1054,0,"if_id_pipe_reg_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"stall_dummy_instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1059,0,"instr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1061,0,"instr_is_compressed_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1062,0,"instr_gets_expanded_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1060,0,"illegal_c_instr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1058,0,"instr_err_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"predict_branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"predict_branch_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+956,0,"irq_vec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+774,0,"pc_mux_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1225,0,"unused_boot_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+613,0,"unused_csr_mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+957,0,"unused_exc_cause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("compressed_decoder_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1187,0,"RV32ZC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ResetAll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1063,0,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1064,0,"id_in_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1057,0,"instr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1059,0,"instr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1061,0,"is_compressed_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1062,0,"gets_expanded_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1060,0,"illegal_instr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1065,0,"cm_rlist_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+684,0,"cm_rlist_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1066,0,"cm_sp_offset_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+685,0,"cm_sp_offset_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1067,0,"cm_state_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+614,0,"cm_state_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1068,0,"gets_expanded",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_no_dummy_instr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+474,0,"unused_dummy_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+475,0,"unused_dummy_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1208,0,"unused_dummy_seed_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"unused_dummy_seed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_prefetch_buffer", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1111,0,"unused_icen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+772,0,"unused_icinv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"unused_scr_key_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("unused_tag_ram_input", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+101+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 21,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unused_data_ram_input", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+103+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("prefetch_buffer_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"ResetAll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+697,0,"req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"branch_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+954,0,"addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1056,0,"ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1055,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1057,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+667,0,"addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1058,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1130,0,"err_plus2_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1098,0,"instr_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+986,0,"instr_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"instr_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+639,0,"busy_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1191,0,"NUM_REQS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+958,0,"valid_new_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"valid_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"valid_req_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+615,0,"valid_req_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+959,0,"discard_req_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+616,0,"discard_req_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+960,0,"rdata_outstanding_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+961,0,"rdata_outstanding_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+617,0,"rdata_outstanding_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+962,0,"branch_discard_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+963,0,"branch_discard_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+618,0,"branch_discard_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+619,0,"rdata_outstanding_rev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+964,0,"stored_addr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+686,0,"stored_addr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+965,0,"stored_addr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1131,0,"fetch_addr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+687,0,"fetch_addr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+966,0,"fetch_addr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+964,0,"instr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1098,0,"instr_addr_w_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+967,0,"fifo_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+954,0,"fifo_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1132,0,"fifo_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"fifo_clear",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+705,0,"fifo_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("fifo_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1191,0,"NUM_REQS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1147,0,"ResetAll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+773,0,"clear_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+705,0,"busy_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+967,0,"in_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+954,0,"in_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+986,0,"in_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"in_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1055,0,"out_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1056,0,"out_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+667,0,"out_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1057,0,"out_rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1058,0,"out_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1130,0,"out_err_plus2_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1262,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declArray(c+1069,0,"rdata_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 95,0);
    tracep->declArray(c+688,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 95,0);
    tracep->declBus(c+968,0,"err_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+691,0,"err_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+981,0,"valid_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+706,0,"valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+707,0,"lowest_free_entry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+969,0,"valid_pushed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1072,0,"valid_popped",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1073,0,"entry_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1074,0,"pop_fifo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1075,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1133,0,"rdata_unaligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+970,0,"err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1134,0,"err_unaligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1135,0,"err_plus2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+971,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1136,0,"valid_unaligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1076,0,"aligned_is_compressed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1077,0,"unaligned_is_compressed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1078,0,"addr_incr_two",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1137,0,"instr_addr_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,1);
    tracep->declBus(c+1138,0,"instr_addr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,1);
    tracep->declBus(c+692,0,"instr_addr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,1);
    tracep->declBit(c+982,0,"instr_addr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+972,0,"unused_addr_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("load_store_unit_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"MemECC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+1190,0,"MemDataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+757,0,"data_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+987,0,"data_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+988,0,"data_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"data_bus_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"data_pmp_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+760,0,"data_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+758,0,"data_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+759,0,"data_be_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+761,0,"data_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1093,0,"data_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+758,0,"lsu_we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+794,0,"lsu_type_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+766,0,"lsu_wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+795,0,"lsu_sign_ext_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1095,0,"lsu_rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+996,0,"lsu_rdata_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+796,0,"lsu_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+776,0,"adder_result_ex_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+476,0,"addr_incr_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+477,0,"addr_last_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1116,0,"lsu_req_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+999,0,"lsu_resp_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+994,0,"load_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"load_resp_intg_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+995,0,"store_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"store_resp_intg_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+478,0,"busy_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+807,0,"perf_load_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+808,0,"perf_store_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+776,0,"data_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+760,0,"data_addr_w_aligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+477,0,"addr_last_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+650,0,"addr_last_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1079,0,"addr_update",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1080,0,"ctrl_update",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1081,0,"rdata_update",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+620,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,8);
    tracep->declBus(c+621,0,"rdata_offset_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+622,0,"data_type_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+623,0,"data_sign_ext_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+624,0,"data_we_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+973,0,"data_offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+759,0,"data_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+761,0,"data_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1095,0,"data_rdata_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1139,0,"rdata_w_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1140,0,"rdata_h_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1141,0,"rdata_b_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+974,0,"split_misaligned_access",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+625,0,"handle_misaligned_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1082,0,"handle_misaligned_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+626,0,"pmp_err_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1083,0,"pmp_err_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+627,0,"lsu_err_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1084,0,"lsu_err_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"data_intg_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+628,0,"data_or_pmp_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+629,0,"ls_fsm_cs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1085,0,"ls_fsm_ns",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+653,0,"fcov_mis_2_en_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+630,0,"fcov_mis_2_en_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+654,0,"fcov_mis_rvalid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1086,0,"fcov_mis_rvalid_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+655,0,"fcov_mis_bus_err_1_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+631,0,"fcov_mis_bus_err_1_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("wb_stage_i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1147,0,"ResetAll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"WritebackStage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1147,0,"DummyInstructions",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+1107,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1001,0,"en_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1263,0,"instr_type_wb_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+668,0,"pc_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+661,0,"instr_is_compressed_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1110,0,"instr_perf_count_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1145,0,"ready_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"rf_write_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"outstanding_load_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"outstanding_store_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"pc_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1002,0,"perf_instr_ret_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1117,0,"perf_instr_ret_compressed_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"perf_instr_ret_wb_spec_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"perf_instr_ret_compressed_wb_spec_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+658,0,"rf_waddr_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+778,0,"rf_wdata_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+779,0,"rf_we_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_id_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1095,0,"rf_wdata_lsu_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+996,0,"rf_we_lsu_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1146,0,"rf_wdata_fwd_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+658,0,"rf_waddr_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1094,0,"rf_wdata_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+976,0,"rf_we_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"dummy_instr_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+999,0,"lsu_resp_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1000,0,"lsu_resp_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"instr_done_wb_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("rf_wdata_wb_mux", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1142+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+983,0,"rf_wdata_wb_mux_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("g_bypass_wb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1107,0,"unused_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"unused_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1263,0,"unused_instr_type_wb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+668,0,"unused_pc_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1208,0,"unused_dummy_instr_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_dma_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+726,0,"src_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+727,0,"dst_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+728,0,"length_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+1144,0,"start_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1099,0,"busy_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+730,0,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+731,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+710,0,"req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+989,0,"gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+713,0,"addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+712,0,"we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+714,0,"wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+711,0,"rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1102,0,"rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+732,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+733,0,"curr_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+734,0,"curr_dst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+735,0,"data_buffer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+736,0,"bytes_left",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_dma_regs", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+715,0,"paddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+737,0,"psel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+720,0,"penable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+721,0,"pwrite",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+716,0,"pwdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1103,0,"prdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"pready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+726,0,"src_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+727,0,"dst_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+728,0,"length_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+123,0,"start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"abort_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1099,0,"busy_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1208,0,"done_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1351,0,"err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"irq_ack_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1225,0,"ADDR_SRC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1352,0,"ADDR_DST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1353,0,"ADDR_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1354,0,"ADDR_CTRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1355,0,"ADDR_STAT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1356,0,"ADDR_IRQ_ACK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mac", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+715,0,"paddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+738,0,"psel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+720,0,"penable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+721,0,"pwrite",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+716,0,"pwdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+725,0,"prdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"pready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1100,0,"done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1101,0,"fsm_state_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+708,0,"m_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+751,0,"m_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"m_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+709,0,"m_we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+121,0,"m_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+119,0,"m_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1102,0,"m_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"result_hold_o_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"result_hold_o_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+132,0,"result_hold_o_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+133,0,"result_hold_o_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+134,0,"start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+135,0,"reg_m",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+136,0,"reg_k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"reg_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+138,0,"wgt_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"act_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"res_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("wgt_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+141,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+142,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+143,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+144,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+145,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+146,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+147,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+148,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+149,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+150,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+151,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+152,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+153,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+154,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+155,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+156,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("weight_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+157,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+158,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+159,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+160,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+161,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+162,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+163,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+164,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+165,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+166,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+167,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+168,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+169,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+170,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+171,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+172,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("act_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+173+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("res_buf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+1357+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("row_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+178+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("col_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+107+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("col_out", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+739+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1221,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1361,0,"WGT_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1362,0,"WGT_PRESENT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1363,0,"ACT_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1364,0,"FEED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1365,0,"DRAIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1366,0,"RES_STORE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1367,0,"ROW_NEXT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1368,0,"DONE_ST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+182,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+183,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+184,0,"wgt_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+185,0,"res_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+186,0,"row_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+187,0,"feed_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+188,0,"drain_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+189,0,"wgt_done_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"res_done_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("result_hold", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+191+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+708,0,"m_req_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"m_addr_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+709,0,"m_we_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+121,0,"m_wdata_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_array", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+195,0,"row_in_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+196,0,"row_in_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+197,0,"row_in_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+198,0,"row_in_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+199,0,"w_in_0_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+200,0,"w_in_0_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+201,0,"w_in_0_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+202,0,"w_in_0_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+203,0,"w_in_1_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+204,0,"w_in_1_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+205,0,"w_in_1_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+206,0,"w_in_1_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+207,0,"w_in_2_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+208,0,"w_in_2_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+209,0,"w_in_2_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+210,0,"w_in_2_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+211,0,"w_in_3_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+212,0,"w_in_3_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+213,0,"w_in_3_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+214,0,"w_in_3_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+111,0,"col_in_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"col_in_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"col_in_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"col_in_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+743,0,"col_out_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+744,0,"col_out_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+745,0,"col_out_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+746,0,"col_out_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("row_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+215+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("weight_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+219,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+220,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+221,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+222,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+223,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+224,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+225,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+226,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+227,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+228,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+229,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+230,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+231,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+232,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+233,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+234,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("col_in", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+115+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("col_out", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+747+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("h_wire", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+235,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+236,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+237,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+238,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+239,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+240,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+241,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+242,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+243,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+244,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+245,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+246,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+247,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+248,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+249,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+250,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+251,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+252,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+253,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+254,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("v_wire", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+255,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+256,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+257,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+258,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+259,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+260,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+261,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+262,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+263,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+264,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+265,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+266,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+267,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+270,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[4]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+271,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+272,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_rows[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("gen_cols[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1369,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1369,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+275,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+276,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+277,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+278,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+279,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+280,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+281,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+282,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1369,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1370,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+283,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+284,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+285,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+286,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+287,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+288,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+289,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+290,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1369,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1371,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+291,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+292,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+293,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+294,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+295,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+296,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+297,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+298,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1369,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1372,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+299,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+300,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+301,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+302,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+303,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+304,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+305,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+306,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_rows[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("gen_cols[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1370,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1369,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+308,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+309,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+310,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+311,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+312,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+313,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+314,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1370,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1370,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+315,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+316,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+317,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+318,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+319,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+320,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+321,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+322,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1370,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1371,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+323,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+324,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+325,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+326,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+327,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+328,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+329,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+330,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1370,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1372,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+331,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+332,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+333,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+334,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+335,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+336,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+337,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+338,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_rows[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("gen_cols[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1371,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1369,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+339,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+340,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+341,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+342,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+343,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+344,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+345,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+346,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1371,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1370,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+347,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+348,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+349,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+350,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+351,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+352,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+353,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+354,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1371,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1371,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+355,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+356,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+357,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+358,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+359,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+360,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+361,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+362,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1371,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1372,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+363,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+364,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+365,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+366,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+367,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+368,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+369,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+370,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_rows[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("gen_cols[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1372,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1369,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+371,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+372,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+373,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+374,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+375,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+376,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+377,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+378,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1372,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1370,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+379,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+380,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+381,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+382,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+383,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+384,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+385,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+386,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1372,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1371,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+387,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+388,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+389,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+390,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+391,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+392,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+393,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+394,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_cols[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("inst_pe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1372,0,"ROW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1372,0,"COL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"load_wgt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+395,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+396,0,"w_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+397,0,"acc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+398,0,"a_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+399,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+400,0,"a_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+401,0,"w_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+402,0,"mul_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_regs", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+715,0,"paddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+738,0,"psel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+720,0,"penable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+721,0,"pwrite",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+716,0,"pwdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+725,0,"prdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1145,0,"pready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1101,0,"fsm_state_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1100,0,"done_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+135,0,"reg_m_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+136,0,"reg_k_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"reg_n_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+138,0,"wgt_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"act_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"res_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"result_hold_i_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"result_hold_i_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+132,0,"result_hold_i_2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+133,0,"result_hold_i_3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+403,0,"sticky_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+404,0,"pe_addr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1106,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1098,0,"instr_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+986,0,"instr_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+756,0,"instr_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+756,0,"instr_gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+975,0,"cpu_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+760,0,"cpu_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+758,0,"cpu_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+759,0,"cpu_be",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+761,0,"cpu_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1104,0,"cpu_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+122,0,"cpu_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+708,0,"mac_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"mac_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+709,0,"mac_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+121,0,"mac_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1102,0,"mac_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+751,0,"mac_gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"mac_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+710,0,"dma_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+713,0,"dma_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+712,0,"dma_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+714,0,"dma_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1102,0,"dma_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+989,0,"dma_gnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+711,0,"dma_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+753,0,"arb_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1087,0,"arb_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+754,0,"arb_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1088,0,"arb_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1089,0,"arb_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1104,0,"arb_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+984,0,"sel_rom",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1090,0,"sel_ram",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1102,0,"ram_dout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_ram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1373,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1374,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1091,0,"sram_cen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+755,0,"sram_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1092,0,"sram_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+1088,0,"sram_wmask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1089,0,"sram_din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1102,0,"sram_dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_rom", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1096,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+985,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+986,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__prim_cipher_pkg__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_sub__TOP__prim_cipher_pkg__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declQuad(c+1375,0,"PRINCE_SBOX4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+1377,0,"PRINCE_SBOX4_INV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+1379,0,"PRINCE_SHIFT_ROWS64",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+1381,0,"PRINCE_SHIFT_ROWS64_INV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+1383,0,"PRINCE_ROUND_CONST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 767,0);
    tracep->declQuad(c+1407,0,"PRINCE_ALPHA_CONST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1409,0,"PRINCE_SHIFT_ROWS_CONST0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1410,0,"PRINCE_SHIFT_ROWS_CONST1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1411,0,"PRINCE_SHIFT_ROWS_CONST2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1412,0,"PRINCE_SHIFT_ROWS_CONST3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+1413,0,"PRESENT_SBOX4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+1415,0,"PRESENT_SBOX4_INV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+1417,0,"PRESENT_PERM32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 159,0);
    tracep->declArray(c+1422,0,"PRESENT_PERM32_INV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 159,0);
    tracep->declArray(c+1427,0,"PRESENT_PERM64",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 383,0);
    tracep->declArray(c+1439,0,"PRESENT_PERM64_INV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 383,0);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_sub__TOP__prim_secded_pkg__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1346,0,"Secded2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1226,0,"Secded2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+1346,0,"Secded2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1451,0,"Secded2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+1211,0,"Secded3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1452,0,"Secded3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+1211,0,"Secded6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1217,0,"Secded6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1225,0,"Secded7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1454,0,"Secded7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+1346,0,"SecdedHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1226,0,"SecdedHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+1211,0,"SecdedHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1452,0,"SecdedHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+1225,0,"SecdedHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1454,0,"SecdedHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+1225,0,"SecdedHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1457,0,"SecdedHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
    tracep->declBus(c+1460,0,"SecdedInv2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1461,0,"SecdedInv2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+1460,0,"SecdedInv2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1462,0,"SecdedInv2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+1463,0,"SecdedInv3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1464,0,"SecdedInv3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+1463,0,"SecdedInv6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1466,0,"SecdedInv6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1468,0,"SecdedInv7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1469,0,"SecdedInv7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+1460,0,"SecdedInvHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1461,0,"SecdedInvHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+1463,0,"SecdedInvHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1464,0,"SecdedInvHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+1468,0,"SecdedInvHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1469,0,"SecdedInvHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+1468,0,"SecdedInvHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1472,0,"SecdedInvHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_sub__TOP__prim_mubi_pkg__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1229,0,"MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1326,0,"MuBi8Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1330,0,"MuBi12Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1307,0,"MuBi16Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1311,0,"MuBi20Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1315,0,"MuBi24Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1319,0,"MuBi28Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1475,0,"MuBi32Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__prim_ram_1p_pkg__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_sub__TOP__prim_ram_1p_pkg__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1476,0,"RAM_1P_CFG_DEFAULT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__ibex_pkg__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_sub__TOP__ibex_pkg__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1477,0,"ExcCauseIrqSoftwareM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1478,0,"ExcCauseIrqTimerM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1479,0,"ExcCauseIrqExternalM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1480,0,"ExcCauseIrqNm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1481,0,"ExcCauseInsnAddrMisa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1482,0,"ExcCauseInstrAccessFault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1483,0,"ExcCauseIllegalInsn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1484,0,"ExcCauseBreakpoint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1485,0,"ExcCauseLoadAccessFault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1486,0,"ExcCauseStoreAccessFault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1487,0,"ExcCauseEcallUMode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1488,0,"ExcCauseEcallMMode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1190,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1190,0,"BUS_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1149,0,"BUS_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1191,0,"BUS_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1489,0,"IC_SIZE_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1191,0,"IC_NUM_WAYS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1223,0,"IC_LINE_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1334,0,"IC_LINE_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1262,0,"IC_LINE_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1490,0,"IC_NUM_LINES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1191,0,"IC_LINE_BEATS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1189,0,"IC_LINE_BEATS_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1334,0,"IC_INDEX_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1491,0,"IC_INDEX_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1224,0,"IC_TAG_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1191,0,"IC_OUTPUT_BEATS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1338,0,"IC_DATA_ECC_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1343,0,"IC_TAG_ECC_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1492,0,"SCRAMBLE_KEY_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1223,0,"SCRAMBLE_NONCE_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1493,0,"PMP_MAX_REGIONS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1334,0,"PMP_CFG_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1494,0,"PMP_ADDR_MSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1191,0,"PMP_ADDR_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1148,0,"PMP_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1189,0,"PMP_I2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1191,0,"PMP_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1495,0,"CSR_OFF_PMP_CFG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+1496,0,"CSR_OFF_PMP_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+1262,0,"CSR_MSTATUS_MIE_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1338,0,"CSR_MSTATUS_MPIE_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1497,0,"CSR_MSTATUS_MPP_BIT_LOW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1498,0,"CSR_MSTATUS_MPP_BIT_HIGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1499,0,"CSR_MSTATUS_MPRV_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1500,0,"CSR_MSTATUS_TW_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1501,0,"CSR_MISA_MXL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1262,0,"CSR_MSIX_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1338,0,"CSR_MTIX_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1497,0,"CSR_MEIX_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1493,0,"CSR_MFIX_BIT_LOW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1502,0,"CSR_MFIX_BIT_HIGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1148,0,"CSR_MSECCFG_MML_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1189,0,"CSR_MSECCFG_MMWP_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1191,0,"CSR_MSECCFG_RLB_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1503,0,"CSR_MARCHID_VALUE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1146,0,"CSR_MCONFIGPTR_VALUE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1475,0,"LfsrWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1192,0,"RndCnstLfsrSeedDefault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1193,0,"RndCnstLfsrPermDefault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 159,0);
    tracep->declArray(c+1202,0,"RndCnstIbexKeyDefault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declQuad(c+1206,0,"RndCnstIbexNonceDefault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1229,0,"IbexMuBiWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1504,0,"IbexMuBiOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1220,0,"IbexMuBiOff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("PmpCfgRst", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+1151,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[2]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[3]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[4]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[5]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[6]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[7]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[8]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[9]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[10]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[11]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[12]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[13]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[14]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1151,0,"[15]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->pushPrefix("PmpAddrRst", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declQuad(c+1505+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, true,(i+0), 33,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1184,0,"PmpMseccfgRst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_top(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_top\n"); );
    // Body
    Vsoc_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsoc_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsoc_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsoc_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsoc_top___024root__trace_register(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vsoc_top___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vsoc_top___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vsoc_top___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vsoc_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_const_0\n"); );
    // Init
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsoc_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<24>/*767:0*/ Vsoc_top__ConstPool__CONST_h08bc5fc5_0;
extern const VlWide<12>/*383:0*/ Vsoc_top__ConstPool__CONST_h24667f93_0;
extern const VlWide<12>/*383:0*/ Vsoc_top__ConstPool__CONST_h98189d5c_0;

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<5>/*159:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<5>/*159:0*/ __Vtemp_4;
    VlWide<5>/*159:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_9;
    // Body
    bufp->fullBit(oldp+1144,(vlSelf->soc_top__DOT__d_start));
    bufp->fullBit(oldp+1145,(1U));
    bufp->fullIData(oldp+1146,(0U),32);
    bufp->fullBit(oldp+1147,(0U));
    bufp->fullIData(oldp+1148,(0U),32);
    bufp->fullIData(oldp+1149,(4U),32);
    bufp->fullIData(oldp+1150,(0x28U),32);
    bufp->fullCData(oldp+1151,(0U),6);
    bufp->fullQData(oldp+1152,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[0]),34);
    bufp->fullQData(oldp+1154,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[1]),34);
    bufp->fullQData(oldp+1156,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[2]),34);
    bufp->fullQData(oldp+1158,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[3]),34);
    bufp->fullQData(oldp+1160,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[4]),34);
    bufp->fullQData(oldp+1162,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[5]),34);
    bufp->fullQData(oldp+1164,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[6]),34);
    bufp->fullQData(oldp+1166,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[7]),34);
    bufp->fullQData(oldp+1168,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[8]),34);
    bufp->fullQData(oldp+1170,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[9]),34);
    bufp->fullQData(oldp+1172,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[10]),34);
    bufp->fullQData(oldp+1174,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[11]),34);
    bufp->fullQData(oldp+1176,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[12]),34);
    bufp->fullQData(oldp+1178,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[13]),34);
    bufp->fullQData(oldp+1180,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[14]),34);
    bufp->fullQData(oldp+1182,(vlSelf->soc_top__DOT__u_core__DOT__PMPRstAddr[15]),34);
    bufp->fullCData(oldp+1184,(0U),3);
    bufp->fullIData(oldp+1185,(2U),32);
    bufp->fullIData(oldp+1186,(0U),32);
    bufp->fullIData(oldp+1187,(3U),32);
    bufp->fullIData(oldp+1188,(0U),32);
    bufp->fullIData(oldp+1189,(1U),32);
    bufp->fullIData(oldp+1190,(0x20U),32);
    bufp->fullIData(oldp+1191,(2U),32);
    bufp->fullIData(oldp+1192,(0xac533bf4U),32);
    __Vtemp_1[0U] = 0x78a8daedU;
    __Vtemp_1[1U] = 0xc04fa438U;
    __Vtemp_1[2U] = 0x2e958152U;
    __Vtemp_1[3U] = 0x467fd1b1U;
    __Vtemp_1[4U] = 0x1e35ecbaU;
    bufp->fullWData(oldp+1193,(__Vtemp_1),160);
    bufp->fullIData(oldp+1198,(0x1a110000U),32);
    bufp->fullIData(oldp+1199,(0xfffU),32);
    bufp->fullIData(oldp+1200,(0x1a110800U),32);
    bufp->fullIData(oldp+1201,(0x1a110808U),32);
    __Vtemp_2[0U] = 0xcc113298U;
    __Vtemp_2[1U] = 0x12286bb3U;
    __Vtemp_2[2U] = 0xe3040d5eU;
    __Vtemp_2[3U] = 0x14e8cecaU;
    bufp->fullWData(oldp+1202,(__Vtemp_2),128);
    bufp->fullQData(oldp+1206,(0xf79780bc735f3843ULL),64);
    bufp->fullBit(oldp+1208,(0U));
    bufp->fullSData(oldp+1209,(0U),12);
    bufp->fullCData(oldp+1210,(0U),2);
    bufp->fullCData(oldp+1211,(0U),7);
    bufp->fullSData(oldp+1212,(0U),15);
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    __Vtemp_3[3U] = 0U;
    bufp->fullWData(oldp+1213,(__Vtemp_3),128);
    bufp->fullQData(oldp+1217,(0ULL),64);
    bufp->fullCData(oldp+1219,(0xfU),4);
    bufp->fullCData(oldp+1220,(0xaU),4);
    bufp->fullCData(oldp+1221,(0U),4);
    bufp->fullIData(oldp+1222,(0x27U),32);
    bufp->fullIData(oldp+1223,(0x40U),32);
    bufp->fullIData(oldp+1224,(0x16U),32);
    bufp->fullCData(oldp+1225,(0U),8);
    bufp->fullIData(oldp+1226,(0U),22);
    bufp->fullBit(oldp+1227,(1U));
    bufp->fullIData(oldp+1228,(5U),32);
    bufp->fullIData(oldp+1229,(4U),32);
    bufp->fullQData(oldp+1230,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[0]),34);
    bufp->fullQData(oldp+1232,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[1]),34);
    bufp->fullQData(oldp+1234,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[2]),34);
    bufp->fullQData(oldp+1236,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[3]),34);
    bufp->fullQData(oldp+1238,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[4]),34);
    bufp->fullQData(oldp+1240,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[5]),34);
    bufp->fullQData(oldp+1242,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[6]),34);
    bufp->fullQData(oldp+1244,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[7]),34);
    bufp->fullQData(oldp+1246,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[8]),34);
    bufp->fullQData(oldp+1248,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[9]),34);
    bufp->fullQData(oldp+1250,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[10]),34);
    bufp->fullQData(oldp+1252,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[11]),34);
    bufp->fullQData(oldp+1254,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[12]),34);
    bufp->fullQData(oldp+1256,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[13]),34);
    bufp->fullQData(oldp+1258,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[14]),34);
    bufp->fullQData(oldp+1260,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr[15]),34);
    bufp->fullIData(oldp+1262,(3U),32);
    bufp->fullCData(oldp+1263,(2U),2);
    bufp->fullIData(oldp+1264,(0U),18);
    bufp->fullQData(oldp+1265,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[0]),34);
    bufp->fullQData(oldp+1267,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[1]),34);
    bufp->fullQData(oldp+1269,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[2]),34);
    bufp->fullQData(oldp+1271,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[3]),34);
    bufp->fullQData(oldp+1273,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[4]),34);
    bufp->fullQData(oldp+1275,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[5]),34);
    bufp->fullQData(oldp+1277,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[6]),34);
    bufp->fullQData(oldp+1279,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[7]),34);
    bufp->fullQData(oldp+1281,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[8]),34);
    bufp->fullQData(oldp+1283,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[9]),34);
    bufp->fullQData(oldp+1285,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[10]),34);
    bufp->fullQData(oldp+1287,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[11]),34);
    bufp->fullQData(oldp+1289,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[12]),34);
    bufp->fullQData(oldp+1291,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[13]),34);
    bufp->fullQData(oldp+1293,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[14]),34);
    bufp->fullQData(oldp+1295,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr[15]),34);
    bufp->fullIData(oldp+1297,(0x40101104U),32);
    bufp->fullIData(oldp+1298,(0U),18);
    bufp->fullCData(oldp+1299,(0U),3);
    bufp->fullCData(oldp+1300,(0x10U),6);
    bufp->fullIData(oldp+1301,(0x40000003U),32);
    bufp->fullCData(oldp+1302,(4U),3);
    bufp->fullIData(oldp+1303,(3U),32);
    bufp->fullIData(oldp+1304,(0xdU),32);
    bufp->fullIData(oldp+1305,(0xeU),32);
    bufp->fullIData(oldp+1306,(0xfU),32);
    bufp->fullIData(oldp+1307,(0x10U),32);
    bufp->fullIData(oldp+1308,(0x11U),32);
    bufp->fullIData(oldp+1309,(0x12U),32);
    bufp->fullIData(oldp+1310,(0x13U),32);
    bufp->fullIData(oldp+1311,(0x14U),32);
    bufp->fullIData(oldp+1312,(0x15U),32);
    bufp->fullIData(oldp+1313,(0x16U),32);
    bufp->fullIData(oldp+1314,(0x17U),32);
    bufp->fullIData(oldp+1315,(0x18U),32);
    bufp->fullIData(oldp+1316,(0x19U),32);
    bufp->fullIData(oldp+1317,(0x1aU),32);
    bufp->fullIData(oldp+1318,(0x1bU),32);
    bufp->fullIData(oldp+1319,(0x1cU),32);
    bufp->fullIData(oldp+1320,(0x1dU),32);
    bufp->fullIData(oldp+1321,(0x1eU),32);
    bufp->fullIData(oldp+1322,(0x1fU),32);
    bufp->fullIData(oldp+1323,(5U),32);
    bufp->fullIData(oldp+1324,(6U),32);
    bufp->fullIData(oldp+1325,(7U),32);
    bufp->fullIData(oldp+1326,(8U),32);
    bufp->fullIData(oldp+1327,(9U),32);
    bufp->fullIData(oldp+1328,(0xaU),32);
    bufp->fullIData(oldp+1329,(0xbU),32);
    bufp->fullIData(oldp+1330,(0xcU),32);
    bufp->fullIData(oldp+1331,(0x20U),32);
    bufp->fullIData(oldp+1332,(0x40U),32);
    bufp->fullIData(oldp+1333,(0x6e6fU),32);
    bufp->fullIData(oldp+1334,(8U),32);
    bufp->fullCData(oldp+1335,(0U),8);
    bufp->fullIData(oldp+1336,(0x40000003U),32);
    bufp->fullIData(oldp+1337,(0U),32);
    bufp->fullIData(oldp+1338,(7U),32);
    bufp->fullCData(oldp+1339,(0U),7);
    bufp->fullIData(oldp+1340,(0x12U),32);
    bufp->fullIData(oldp+1341,(0U),18);
    bufp->fullCData(oldp+1342,(4U),3);
    bufp->fullIData(oldp+1343,(6U),32);
    bufp->fullCData(oldp+1344,(0x10U),6);
    bufp->fullIData(oldp+1345,(1U),32);
    bufp->fullCData(oldp+1346,(0U),6);
    bufp->fullCData(oldp+1347,(2U),2);
    bufp->fullCData(oldp+1348,(0U),3);
    bufp->fullCData(oldp+1349,(0U),5);
    bufp->fullIData(oldp+1350,(0xffffffffU),32);
    bufp->fullBit(oldp+1351,(vlSelf->soc_top__DOT__u_dma_regs__DOT__err_i));
    bufp->fullCData(oldp+1352,(4U),8);
    bufp->fullCData(oldp+1353,(8U),8);
    bufp->fullCData(oldp+1354,(0xcU),8);
    bufp->fullCData(oldp+1355,(0x10U),8);
    bufp->fullCData(oldp+1356,(0x14U),8);
    bufp->fullIData(oldp+1357,(vlSelf->soc_top__DOT__u_mac__DOT__res_buf[0]),32);
    bufp->fullIData(oldp+1358,(vlSelf->soc_top__DOT__u_mac__DOT__res_buf[1]),32);
    bufp->fullIData(oldp+1359,(vlSelf->soc_top__DOT__u_mac__DOT__res_buf[2]),32);
    bufp->fullIData(oldp+1360,(vlSelf->soc_top__DOT__u_mac__DOT__res_buf[3]),32);
    bufp->fullCData(oldp+1361,(1U),4);
    bufp->fullCData(oldp+1362,(2U),4);
    bufp->fullCData(oldp+1363,(3U),4);
    bufp->fullCData(oldp+1364,(4U),4);
    bufp->fullCData(oldp+1365,(5U),4);
    bufp->fullCData(oldp+1366,(6U),4);
    bufp->fullCData(oldp+1367,(7U),4);
    bufp->fullCData(oldp+1368,(8U),4);
    bufp->fullIData(oldp+1369,(0U),32);
    bufp->fullIData(oldp+1370,(1U),32);
    bufp->fullIData(oldp+1371,(2U),32);
    bufp->fullIData(oldp+1372,(3U),32);
    bufp->fullIData(oldp+1373,(0xbU),32);
    bufp->fullIData(oldp+1374,(0x800U),32);
    bufp->fullQData(oldp+1375,(0x4d5e087619ca23fbULL),64);
    bufp->fullQData(oldp+1377,(0x1ce5046a98df237bULL),64);
    bufp->fullQData(oldp+1379,(0xfa50b61c72d83e94ULL),64);
    bufp->fullQData(oldp+1381,(0xf258be147ad0369cULL),64);
    bufp->fullWData(oldp+1383,(Vsoc_top__ConstPool__CONST_h08bc5fc5_0),768);
    bufp->fullQData(oldp+1407,(0xc0ac29b7c97c50ddULL),64);
    bufp->fullSData(oldp+1409,(0x7bdeU),16);
    bufp->fullSData(oldp+1410,(0xbde7U),16);
    bufp->fullSData(oldp+1411,(0xde7bU),16);
    bufp->fullSData(oldp+1412,(0xe7bdU),16);
    bufp->fullQData(oldp+1413,(0x21748fe3da09b65cULL),64);
    bufp->fullQData(oldp+1415,(0xa970364bd21c8fe5ULL),64);
    __Vtemp_4[0U] = 0x521c4100U;
    __Vtemp_4[1U] = 0x3d4942ccU;
    __Vtemp_4[2U] = 0x5184dcd6U;
    __Vtemp_4[3U] = 0xc6ed5a5eU;
    __Vtemp_4[4U] = 0xfdde7f59U;
    bufp->fullWData(oldp+1417,(__Vtemp_4),160);
    __Vtemp_5[0U] = 0x29062080U;
    __Vtemp_5[1U] = 0x16a4a1e6U;
    __Vtemp_5[2U] = 0x28c2ee6bU;
    __Vtemp_5[3U] = 0xe3f6ad27U;
    __Vtemp_5[4U] = 0xfeef37acU;
    bufp->fullWData(oldp+1422,(__Vtemp_5),160);
    bufp->fullWData(oldp+1427,(Vsoc_top__ConstPool__CONST_h24667f93_0),384);
    bufp->fullWData(oldp+1439,(Vsoc_top__ConstPool__CONST_h98189d5c_0),384);
    bufp->fullIData(oldp+1451,(0U),28);
    bufp->fullQData(oldp+1452,(0ULL),39);
    __Vtemp_6[0U] = 0U;
    __Vtemp_6[1U] = 0U;
    __Vtemp_6[2U] = 0U;
    bufp->fullWData(oldp+1454,(__Vtemp_6),72);
    __Vtemp_7[0U] = 0U;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    bufp->fullWData(oldp+1457,(__Vtemp_7),76);
    bufp->fullCData(oldp+1460,(0x2aU),6);
    bufp->fullIData(oldp+1461,(0x2a0000U),22);
    bufp->fullIData(oldp+1462,(0xa800000U),28);
    bufp->fullCData(oldp+1463,(0x2aU),7);
    bufp->fullQData(oldp+1464,(0x2a00000000ULL),39);
    bufp->fullQData(oldp+1466,(0x5400000000000000ULL),64);
    bufp->fullCData(oldp+1468,(0xaaU),8);
    __Vtemp_8[0U] = 0U;
    __Vtemp_8[1U] = 0U;
    __Vtemp_8[2U] = 0xaaU;
    bufp->fullWData(oldp+1469,(__Vtemp_8),72);
    __Vtemp_9[0U] = 0U;
    __Vtemp_9[1U] = 0U;
    __Vtemp_9[2U] = 0xaa0U;
    bufp->fullWData(oldp+1472,(__Vtemp_9),76);
    bufp->fullIData(oldp+1475,(0x20U),32);
    bufp->fullSData(oldp+1476,(0U),12);
    bufp->fullCData(oldp+1477,(0x23U),7);
    bufp->fullCData(oldp+1478,(0x27U),7);
    bufp->fullCData(oldp+1479,(0x2bU),7);
    bufp->fullCData(oldp+1480,(0x3fU),7);
    bufp->fullCData(oldp+1481,(0U),7);
    bufp->fullCData(oldp+1482,(1U),7);
    bufp->fullCData(oldp+1483,(2U),7);
    bufp->fullCData(oldp+1484,(3U),7);
    bufp->fullCData(oldp+1485,(5U),7);
    bufp->fullCData(oldp+1486,(7U),7);
    bufp->fullCData(oldp+1487,(8U),7);
    bufp->fullCData(oldp+1488,(0xbU),7);
    bufp->fullIData(oldp+1489,(0x1000U),32);
    bufp->fullIData(oldp+1490,(0x100U),32);
    bufp->fullIData(oldp+1491,(0xaU),32);
    bufp->fullIData(oldp+1492,(0x80U),32);
    bufp->fullIData(oldp+1493,(0x10U),32);
    bufp->fullIData(oldp+1494,(0x21U),32);
    bufp->fullSData(oldp+1495,(0x3a0U),12);
    bufp->fullSData(oldp+1496,(0x3b0U),12);
    bufp->fullIData(oldp+1497,(0xbU),32);
    bufp->fullIData(oldp+1498,(0xcU),32);
    bufp->fullIData(oldp+1499,(0x11U),32);
    bufp->fullIData(oldp+1500,(0x15U),32);
    bufp->fullCData(oldp+1501,(1U),2);
    bufp->fullIData(oldp+1502,(0x1eU),32);
    bufp->fullIData(oldp+1503,(0x16U),32);
    bufp->fullCData(oldp+1504,(5U),4);
    bufp->fullQData(oldp+1505,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[0]),34);
    bufp->fullQData(oldp+1507,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[1]),34);
    bufp->fullQData(oldp+1509,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[2]),34);
    bufp->fullQData(oldp+1511,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[3]),34);
    bufp->fullQData(oldp+1513,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[4]),34);
    bufp->fullQData(oldp+1515,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[5]),34);
    bufp->fullQData(oldp+1517,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[6]),34);
    bufp->fullQData(oldp+1519,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[7]),34);
    bufp->fullQData(oldp+1521,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[8]),34);
    bufp->fullQData(oldp+1523,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[9]),34);
    bufp->fullQData(oldp+1525,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[10]),34);
    bufp->fullQData(oldp+1527,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[11]),34);
    bufp->fullQData(oldp+1529,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[12]),34);
    bufp->fullQData(oldp+1531,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[13]),34);
    bufp->fullQData(oldp+1533,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[14]),34);
    bufp->fullQData(oldp+1535,(vlSymsp->TOP__ibex_pkg.__PVT__PmpAddrRst[15]),34);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_full_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsoc_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_full_0\n"); );
    // Init
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsoc_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_full_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<5>/*159:0*/ __Vtemp_3;
    // Body
    bufp->fullIData(oldp+1,(vlSelf->soc_top__DOT__u_core__DOT__ic_tag_rdata[0]),22);
    bufp->fullIData(oldp+2,(vlSelf->soc_top__DOT__u_core__DOT__ic_tag_rdata[1]),22);
    bufp->fullQData(oldp+3,(vlSelf->soc_top__DOT__u_core__DOT__ic_data_rdata[0]),64);
    bufp->fullQData(oldp+5,(vlSelf->soc_top__DOT__u_core__DOT__ic_data_rdata[1]),64);
    bufp->fullQData(oldp+7,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[0]),34);
    bufp->fullQData(oldp+9,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[1]),34);
    bufp->fullQData(oldp+11,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[2]),34);
    bufp->fullQData(oldp+13,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[3]),34);
    bufp->fullCData(oldp+15,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
                             [0U]),6);
    bufp->fullCData(oldp+16,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
                             [1U]),6);
    bufp->fullCData(oldp+17,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
                             [2U]),6);
    bufp->fullCData(oldp+18,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
                             [3U]),6);
    bufp->fullBit(oldp+19,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pmp_req_err[0]));
    bufp->fullBit(oldp+20,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pmp_req_err[1]));
    bufp->fullBit(oldp+21,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pmp_req_err[2]));
    bufp->fullIData(oldp+22,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[0]),32);
    bufp->fullIData(oldp+23,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[1]),32);
    bufp->fullIData(oldp+24,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[2]),32);
    bufp->fullIData(oldp+25,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[3]),32);
    bufp->fullIData(oldp+26,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[4]),32);
    bufp->fullIData(oldp+27,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[5]),32);
    bufp->fullIData(oldp+28,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[6]),32);
    bufp->fullIData(oldp+29,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[7]),32);
    bufp->fullIData(oldp+30,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[8]),32);
    bufp->fullIData(oldp+31,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[9]),32);
    bufp->fullIData(oldp+32,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[10]),32);
    bufp->fullIData(oldp+33,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[11]),32);
    bufp->fullIData(oldp+34,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[12]),32);
    bufp->fullIData(oldp+35,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[13]),32);
    bufp->fullIData(oldp+36,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[14]),32);
    bufp->fullIData(oldp+37,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[15]),32);
    bufp->fullCData(oldp+38,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[0]),8);
    bufp->fullCData(oldp+39,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[1]),8);
    bufp->fullCData(oldp+40,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[2]),8);
    bufp->fullCData(oldp+41,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[3]),8);
    bufp->fullCData(oldp+42,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[4]),8);
    bufp->fullCData(oldp+43,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[5]),8);
    bufp->fullCData(oldp+44,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[6]),8);
    bufp->fullCData(oldp+45,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[7]),8);
    bufp->fullCData(oldp+46,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[8]),8);
    bufp->fullCData(oldp+47,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[9]),8);
    bufp->fullCData(oldp+48,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[10]),8);
    bufp->fullCData(oldp+49,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[11]),8);
    bufp->fullCData(oldp+50,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[12]),8);
    bufp->fullCData(oldp+51,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[13]),8);
    bufp->fullCData(oldp+52,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[14]),8);
    bufp->fullCData(oldp+53,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[15]),8);
    bufp->fullIData(oldp+54,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0]),32);
    bufp->fullIData(oldp+55,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[1]),32);
    bufp->fullIData(oldp+56,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[2]),32);
    bufp->fullIData(oldp+57,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[3]),32);
    bufp->fullIData(oldp+58,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[4]),32);
    bufp->fullIData(oldp+59,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[5]),32);
    bufp->fullIData(oldp+60,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[6]),32);
    bufp->fullIData(oldp+61,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[7]),32);
    bufp->fullIData(oldp+62,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[8]),32);
    bufp->fullIData(oldp+63,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[9]),32);
    bufp->fullIData(oldp+64,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[10]),32);
    bufp->fullIData(oldp+65,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[11]),32);
    bufp->fullIData(oldp+66,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[12]),32);
    bufp->fullIData(oldp+67,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[13]),32);
    bufp->fullIData(oldp+68,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[14]),32);
    bufp->fullIData(oldp+69,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[15]),32);
    bufp->fullIData(oldp+70,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[16]),32);
    bufp->fullIData(oldp+71,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[17]),32);
    bufp->fullIData(oldp+72,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[18]),32);
    bufp->fullIData(oldp+73,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[19]),32);
    bufp->fullIData(oldp+74,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[20]),32);
    bufp->fullIData(oldp+75,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[21]),32);
    bufp->fullIData(oldp+76,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[22]),32);
    bufp->fullIData(oldp+77,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[23]),32);
    bufp->fullIData(oldp+78,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[24]),32);
    bufp->fullIData(oldp+79,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[25]),32);
    bufp->fullIData(oldp+80,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[26]),32);
    bufp->fullIData(oldp+81,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[27]),32);
    bufp->fullIData(oldp+82,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[28]),32);
    bufp->fullIData(oldp+83,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[29]),32);
    bufp->fullIData(oldp+84,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[30]),32);
    bufp->fullIData(oldp+85,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[31]),32);
    bufp->fullIData(oldp+86,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_d[0]),32);
    bufp->fullIData(oldp+87,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_d[1]),32);
    bufp->fullQData(oldp+88,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[0]),34);
    bufp->fullQData(oldp+90,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[1]),34);
    bufp->fullQData(oldp+92,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[2]),34);
    bufp->fullQData(oldp+94,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[3]),34);
    bufp->fullCData(oldp+96,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg
                             [0U]),6);
    bufp->fullCData(oldp+97,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg
                             [1U]),6);
    bufp->fullCData(oldp+98,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg
                             [2U]),6);
    bufp->fullCData(oldp+99,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg
                             [3U]),6);
    bufp->fullBit(oldp+100,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_alu));
    bufp->fullIData(oldp+101,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_tag_ram_input[0]),22);
    bufp->fullIData(oldp+102,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_tag_ram_input[1]),22);
    bufp->fullQData(oldp+103,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_data_ram_input[0]),64);
    bufp->fullQData(oldp+105,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_data_ram_input[1]),64);
    bufp->fullIData(oldp+107,(vlSelf->soc_top__DOT__u_mac__DOT__col_in[0]),32);
    bufp->fullIData(oldp+108,(vlSelf->soc_top__DOT__u_mac__DOT__col_in[1]),32);
    bufp->fullIData(oldp+109,(vlSelf->soc_top__DOT__u_mac__DOT__col_in[2]),32);
    bufp->fullIData(oldp+110,(vlSelf->soc_top__DOT__u_mac__DOT__col_in[3]),32);
    bufp->fullIData(oldp+111,(vlSelf->soc_top__DOT__u_mac__DOT__col_in
                              [0U]),32);
    bufp->fullIData(oldp+112,(vlSelf->soc_top__DOT__u_mac__DOT__col_in
                              [1U]),32);
    bufp->fullIData(oldp+113,(vlSelf->soc_top__DOT__u_mac__DOT__col_in
                              [2U]),32);
    bufp->fullIData(oldp+114,(vlSelf->soc_top__DOT__u_mac__DOT__col_in
                              [3U]),32);
    bufp->fullIData(oldp+115,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[0]),32);
    bufp->fullIData(oldp+116,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[1]),32);
    bufp->fullIData(oldp+117,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[2]),32);
    bufp->fullIData(oldp+118,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[3]),32);
    bufp->fullBit(oldp+119,(vlSelf->soc_top__DOT__mac_m_rvalid));
    bufp->fullIData(oldp+120,(vlSelf->soc_top__DOT__u_mac__DOT__m_addr_c),32);
    bufp->fullIData(oldp+121,(vlSelf->soc_top__DOT__u_mac__DOT__m_wdata_c),32);
    bufp->fullBit(oldp+122,(vlSelf->soc_top__DOT__cpu_rvalid_mem));
    bufp->fullBit(oldp+123,(vlSelf->soc_top__DOT__dma_start));
    bufp->fullBit(oldp+124,((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__core_busy_q)))));
    bufp->fullCData(oldp+125,(vlSelf->soc_top__DOT__u_core__DOT__core_busy_q),4);
    bufp->fullBit(oldp+126,((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__core_busy_q))));
    bufp->fullBit(oldp+127,((1U & VL_REDXOR_32((7U 
                                                & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__core_busy_q) 
                                                   >> 1U))))));
    bufp->fullBit(oldp+128,(vlSelf->soc_top__DOT__u_dma_regs__DOT__abort_o));
    bufp->fullBit(oldp+129,(vlSelf->soc_top__DOT__u_dma_regs__DOT__irq_ack_o));
    bufp->fullIData(oldp+130,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                              [0U]),32);
    bufp->fullIData(oldp+131,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                              [1U]),32);
    bufp->fullIData(oldp+132,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                              [2U]),32);
    bufp->fullIData(oldp+133,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                              [3U]),32);
    bufp->fullBit(oldp+134,(vlSelf->soc_top__DOT__u_mac__DOT__start));
    bufp->fullCData(oldp+135,(vlSelf->soc_top__DOT__u_mac__DOT__reg_m),8);
    bufp->fullCData(oldp+136,(vlSelf->soc_top__DOT__u_mac__DOT__reg_k),8);
    bufp->fullCData(oldp+137,(vlSelf->soc_top__DOT__u_mac__DOT__reg_n),8);
    bufp->fullIData(oldp+138,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_addr),32);
    bufp->fullIData(oldp+139,(vlSelf->soc_top__DOT__u_mac__DOT__act_addr),32);
    bufp->fullIData(oldp+140,(vlSelf->soc_top__DOT__u_mac__DOT__res_addr),32);
    bufp->fullCData(oldp+141,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [0U][0U]),8);
    bufp->fullCData(oldp+142,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [0U][1U]),8);
    bufp->fullCData(oldp+143,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [0U][2U]),8);
    bufp->fullCData(oldp+144,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [0U][3U]),8);
    bufp->fullCData(oldp+145,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [1U][0U]),8);
    bufp->fullCData(oldp+146,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [1U][1U]),8);
    bufp->fullCData(oldp+147,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [1U][2U]),8);
    bufp->fullCData(oldp+148,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [1U][3U]),8);
    bufp->fullCData(oldp+149,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [2U][0U]),8);
    bufp->fullCData(oldp+150,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [2U][1U]),8);
    bufp->fullCData(oldp+151,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [2U][2U]),8);
    bufp->fullCData(oldp+152,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [2U][3U]),8);
    bufp->fullCData(oldp+153,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [3U][0U]),8);
    bufp->fullCData(oldp+154,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [3U][1U]),8);
    bufp->fullCData(oldp+155,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [3U][2U]),8);
    bufp->fullCData(oldp+156,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                              [3U][3U]),8);
    bufp->fullCData(oldp+157,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [0U][0U]),8);
    bufp->fullCData(oldp+158,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [0U][1U]),8);
    bufp->fullCData(oldp+159,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [0U][2U]),8);
    bufp->fullCData(oldp+160,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [0U][3U]),8);
    bufp->fullCData(oldp+161,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [1U][0U]),8);
    bufp->fullCData(oldp+162,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [1U][1U]),8);
    bufp->fullCData(oldp+163,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [1U][2U]),8);
    bufp->fullCData(oldp+164,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [1U][3U]),8);
    bufp->fullCData(oldp+165,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [2U][0U]),8);
    bufp->fullCData(oldp+166,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [2U][1U]),8);
    bufp->fullCData(oldp+167,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [2U][2U]),8);
    bufp->fullCData(oldp+168,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [2U][3U]),8);
    bufp->fullCData(oldp+169,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [3U][0U]),8);
    bufp->fullCData(oldp+170,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [3U][1U]),8);
    bufp->fullCData(oldp+171,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [3U][2U]),8);
    bufp->fullCData(oldp+172,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [3U][3U]),8);
    bufp->fullCData(oldp+173,(vlSelf->soc_top__DOT__u_mac__DOT__act_buf[0]),8);
    bufp->fullCData(oldp+174,(vlSelf->soc_top__DOT__u_mac__DOT__act_buf[1]),8);
    bufp->fullCData(oldp+175,(vlSelf->soc_top__DOT__u_mac__DOT__act_buf[2]),8);
    bufp->fullCData(oldp+176,(vlSelf->soc_top__DOT__u_mac__DOT__act_buf[3]),8);
    bufp->fullBit(oldp+177,(vlSelf->soc_top__DOT__u_mac__DOT__load_wgt));
    bufp->fullCData(oldp+178,(vlSelf->soc_top__DOT__u_mac__DOT__row_in[0]),8);
    bufp->fullCData(oldp+179,(vlSelf->soc_top__DOT__u_mac__DOT__row_in[1]),8);
    bufp->fullCData(oldp+180,(vlSelf->soc_top__DOT__u_mac__DOT__row_in[2]),8);
    bufp->fullCData(oldp+181,(vlSelf->soc_top__DOT__u_mac__DOT__row_in[3]),8);
    bufp->fullCData(oldp+182,(vlSelf->soc_top__DOT__u_mac__DOT__state),4);
    bufp->fullCData(oldp+183,(vlSelf->soc_top__DOT__u_mac__DOT__next_state),4);
    bufp->fullCData(oldp+184,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_cnt),2);
    bufp->fullCData(oldp+185,(vlSelf->soc_top__DOT__u_mac__DOT__res_cnt),2);
    bufp->fullCData(oldp+186,(vlSelf->soc_top__DOT__u_mac__DOT__row_cnt),8);
    bufp->fullCData(oldp+187,(vlSelf->soc_top__DOT__u_mac__DOT__feed_cnt),4);
    bufp->fullCData(oldp+188,(vlSelf->soc_top__DOT__u_mac__DOT__drain_cnt),4);
    bufp->fullBit(oldp+189,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_done_r));
    bufp->fullBit(oldp+190,(vlSelf->soc_top__DOT__u_mac__DOT__res_done_r));
    bufp->fullIData(oldp+191,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold[0]),32);
    bufp->fullIData(oldp+192,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold[1]),32);
    bufp->fullIData(oldp+193,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold[2]),32);
    bufp->fullIData(oldp+194,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold[3]),32);
    bufp->fullCData(oldp+195,(vlSelf->soc_top__DOT__u_mac__DOT__row_in
                              [0U]),8);
    bufp->fullCData(oldp+196,(vlSelf->soc_top__DOT__u_mac__DOT__row_in
                              [1U]),8);
    bufp->fullCData(oldp+197,(vlSelf->soc_top__DOT__u_mac__DOT__row_in
                              [2U]),8);
    bufp->fullCData(oldp+198,(vlSelf->soc_top__DOT__u_mac__DOT__row_in
                              [3U]),8);
    bufp->fullCData(oldp+199,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [0U][0U]),8);
    bufp->fullCData(oldp+200,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [0U][1U]),8);
    bufp->fullCData(oldp+201,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [0U][2U]),8);
    bufp->fullCData(oldp+202,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [0U][3U]),8);
    bufp->fullCData(oldp+203,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [1U][0U]),8);
    bufp->fullCData(oldp+204,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [1U][1U]),8);
    bufp->fullCData(oldp+205,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [1U][2U]),8);
    bufp->fullCData(oldp+206,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [1U][3U]),8);
    bufp->fullCData(oldp+207,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [2U][0U]),8);
    bufp->fullCData(oldp+208,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [2U][1U]),8);
    bufp->fullCData(oldp+209,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [2U][2U]),8);
    bufp->fullCData(oldp+210,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [2U][3U]),8);
    bufp->fullCData(oldp+211,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [3U][0U]),8);
    bufp->fullCData(oldp+212,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [3U][1U]),8);
    bufp->fullCData(oldp+213,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [3U][2U]),8);
    bufp->fullCData(oldp+214,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                              [3U][3U]),8);
    bufp->fullCData(oldp+215,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[0]),8);
    bufp->fullCData(oldp+216,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[1]),8);
    bufp->fullCData(oldp+217,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[2]),8);
    bufp->fullCData(oldp+218,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[3]),8);
    bufp->fullCData(oldp+219,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [0U][0U]),8);
    bufp->fullCData(oldp+220,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [0U][1U]),8);
    bufp->fullCData(oldp+221,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [0U][2U]),8);
    bufp->fullCData(oldp+222,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [0U][3U]),8);
    bufp->fullCData(oldp+223,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [1U][0U]),8);
    bufp->fullCData(oldp+224,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [1U][1U]),8);
    bufp->fullCData(oldp+225,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [1U][2U]),8);
    bufp->fullCData(oldp+226,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [1U][3U]),8);
    bufp->fullCData(oldp+227,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [2U][0U]),8);
    bufp->fullCData(oldp+228,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [2U][1U]),8);
    bufp->fullCData(oldp+229,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [2U][2U]),8);
    bufp->fullCData(oldp+230,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [2U][3U]),8);
    bufp->fullCData(oldp+231,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [3U][0U]),8);
    bufp->fullCData(oldp+232,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [3U][1U]),8);
    bufp->fullCData(oldp+233,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [3U][2U]),8);
    bufp->fullCData(oldp+234,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [3U][3U]),8);
    bufp->fullCData(oldp+235,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [0U][0U]),8);
    bufp->fullCData(oldp+236,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [0U][1U]),8);
    bufp->fullCData(oldp+237,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [0U][2U]),8);
    bufp->fullCData(oldp+238,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [0U][3U]),8);
    bufp->fullCData(oldp+239,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [0U][4U]),8);
    bufp->fullCData(oldp+240,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [1U][0U]),8);
    bufp->fullCData(oldp+241,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [1U][1U]),8);
    bufp->fullCData(oldp+242,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [1U][2U]),8);
    bufp->fullCData(oldp+243,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [1U][3U]),8);
    bufp->fullCData(oldp+244,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [1U][4U]),8);
    bufp->fullCData(oldp+245,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [2U][0U]),8);
    bufp->fullCData(oldp+246,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [2U][1U]),8);
    bufp->fullCData(oldp+247,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [2U][2U]),8);
    bufp->fullCData(oldp+248,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [2U][3U]),8);
    bufp->fullCData(oldp+249,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [2U][4U]),8);
    bufp->fullCData(oldp+250,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [3U][0U]),8);
    bufp->fullCData(oldp+251,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [3U][1U]),8);
    bufp->fullCData(oldp+252,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [3U][2U]),8);
    bufp->fullCData(oldp+253,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [3U][3U]),8);
    bufp->fullCData(oldp+254,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [3U][4U]),8);
    bufp->fullIData(oldp+255,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [0U][0U]),32);
    bufp->fullIData(oldp+256,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [0U][1U]),32);
    bufp->fullIData(oldp+257,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [0U][2U]),32);
    bufp->fullIData(oldp+258,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [0U][3U]),32);
    bufp->fullIData(oldp+259,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [1U][0U]),32);
    bufp->fullIData(oldp+260,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [1U][1U]),32);
    bufp->fullIData(oldp+261,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [1U][2U]),32);
    bufp->fullIData(oldp+262,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [1U][3U]),32);
    bufp->fullIData(oldp+263,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [2U][0U]),32);
    bufp->fullIData(oldp+264,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [2U][1U]),32);
    bufp->fullIData(oldp+265,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [2U][2U]),32);
    bufp->fullIData(oldp+266,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [2U][3U]),32);
    bufp->fullIData(oldp+267,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [3U][0U]),32);
    bufp->fullIData(oldp+268,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [3U][1U]),32);
    bufp->fullIData(oldp+269,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [3U][2U]),32);
    bufp->fullIData(oldp+270,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [3U][3U]),32);
    bufp->fullIData(oldp+271,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [4U][0U]),32);
    bufp->fullIData(oldp+272,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [4U][1U]),32);
    bufp->fullIData(oldp+273,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [4U][2U]),32);
    bufp->fullIData(oldp+274,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [4U][3U]),32);
    bufp->fullCData(oldp+275,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [0U][0U]),8);
    bufp->fullCData(oldp+276,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [0U][0U]),8);
    bufp->fullIData(oldp+277,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [0U][0U]),32);
    bufp->fullCData(oldp+278,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+279,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+280,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+281,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+282,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+283,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [0U][1U]),8);
    bufp->fullCData(oldp+284,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [0U][1U]),8);
    bufp->fullIData(oldp+285,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [0U][1U]),32);
    bufp->fullCData(oldp+286,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+287,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+288,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+289,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+290,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+291,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [0U][2U]),8);
    bufp->fullCData(oldp+292,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [0U][2U]),8);
    bufp->fullIData(oldp+293,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [0U][2U]),32);
    bufp->fullCData(oldp+294,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+295,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+296,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+297,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+298,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+299,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [0U][3U]),8);
    bufp->fullCData(oldp+300,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [0U][3U]),8);
    bufp->fullIData(oldp+301,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [0U][3U]),32);
    bufp->fullCData(oldp+302,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+303,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+304,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+305,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+306,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+307,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [1U][0U]),8);
    bufp->fullCData(oldp+308,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [1U][0U]),8);
    bufp->fullIData(oldp+309,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [1U][0U]),32);
    bufp->fullCData(oldp+310,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+311,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+312,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+313,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+314,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+315,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [1U][1U]),8);
    bufp->fullCData(oldp+316,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [1U][1U]),8);
    bufp->fullIData(oldp+317,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [1U][1U]),32);
    bufp->fullCData(oldp+318,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+319,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+320,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+321,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+322,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+323,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [1U][2U]),8);
    bufp->fullCData(oldp+324,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [1U][2U]),8);
    bufp->fullIData(oldp+325,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [1U][2U]),32);
    bufp->fullCData(oldp+326,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+327,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+328,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+329,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+330,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+331,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [1U][3U]),8);
    bufp->fullCData(oldp+332,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [1U][3U]),8);
    bufp->fullIData(oldp+333,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [1U][3U]),32);
    bufp->fullCData(oldp+334,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+335,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+336,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+337,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+338,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+339,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [2U][0U]),8);
    bufp->fullCData(oldp+340,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [2U][0U]),8);
    bufp->fullIData(oldp+341,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [2U][0U]),32);
    bufp->fullCData(oldp+342,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+343,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+344,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+345,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+346,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+347,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [2U][1U]),8);
    bufp->fullCData(oldp+348,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [2U][1U]),8);
    bufp->fullIData(oldp+349,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [2U][1U]),32);
    bufp->fullCData(oldp+350,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+351,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+352,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+353,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+354,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+355,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [2U][2U]),8);
    bufp->fullCData(oldp+356,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [2U][2U]),8);
    bufp->fullIData(oldp+357,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [2U][2U]),32);
    bufp->fullCData(oldp+358,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+359,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+360,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+361,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+362,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+363,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [2U][3U]),8);
    bufp->fullCData(oldp+364,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [2U][3U]),8);
    bufp->fullIData(oldp+365,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [2U][3U]),32);
    bufp->fullCData(oldp+366,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+367,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+368,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+369,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+370,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+371,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [3U][0U]),8);
    bufp->fullCData(oldp+372,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [3U][0U]),8);
    bufp->fullIData(oldp+373,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [3U][0U]),32);
    bufp->fullCData(oldp+374,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+375,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+376,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+377,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+378,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+379,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [3U][1U]),8);
    bufp->fullCData(oldp+380,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [3U][1U]),8);
    bufp->fullIData(oldp+381,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [3U][1U]),32);
    bufp->fullCData(oldp+382,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+383,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+384,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+385,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+386,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+387,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [3U][2U]),8);
    bufp->fullCData(oldp+388,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [3U][2U]),8);
    bufp->fullIData(oldp+389,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [3U][2U]),32);
    bufp->fullCData(oldp+390,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+391,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+392,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+393,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+394,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullCData(oldp+395,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                              [3U][3U]),8);
    bufp->fullCData(oldp+396,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                              [3U][3U]),8);
    bufp->fullIData(oldp+397,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                              [3U][3U]),32);
    bufp->fullCData(oldp+398,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out),8);
    bufp->fullIData(oldp+399,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out),32);
    bufp->fullCData(oldp+400,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg),8);
    bufp->fullCData(oldp+401,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg),8);
    bufp->fullSData(oldp+402,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg),16);
    bufp->fullBit(oldp+403,(vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__sticky_done));
    bufp->fullCData(oldp+404,(vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__pe_addr_reg),4);
    bufp->fullIData(oldp+405,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0]),32);
    bufp->fullIData(oldp+406,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[1]),32);
    bufp->fullIData(oldp+407,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[2]),32);
    bufp->fullIData(oldp+408,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[3]),32);
    bufp->fullIData(oldp+409,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[4]),32);
    bufp->fullIData(oldp+410,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[5]),32);
    bufp->fullIData(oldp+411,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[6]),32);
    bufp->fullIData(oldp+412,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[7]),32);
    bufp->fullIData(oldp+413,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[8]),32);
    bufp->fullIData(oldp+414,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[9]),32);
    bufp->fullIData(oldp+415,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[10]),32);
    bufp->fullIData(oldp+416,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[11]),32);
    bufp->fullIData(oldp+417,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[12]),32);
    bufp->fullIData(oldp+418,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[13]),32);
    bufp->fullIData(oldp+419,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[14]),32);
    bufp->fullIData(oldp+420,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[15]),32);
    bufp->fullIData(oldp+421,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[16]),32);
    bufp->fullIData(oldp+422,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[17]),32);
    bufp->fullIData(oldp+423,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[18]),32);
    bufp->fullIData(oldp+424,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[19]),32);
    bufp->fullIData(oldp+425,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[20]),32);
    bufp->fullIData(oldp+426,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[21]),32);
    bufp->fullIData(oldp+427,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[22]),32);
    bufp->fullIData(oldp+428,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[23]),32);
    bufp->fullIData(oldp+429,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[24]),32);
    bufp->fullIData(oldp+430,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[25]),32);
    bufp->fullIData(oldp+431,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[26]),32);
    bufp->fullIData(oldp+432,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[27]),32);
    bufp->fullIData(oldp+433,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[28]),32);
    bufp->fullIData(oldp+434,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[29]),32);
    bufp->fullIData(oldp+435,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[30]),32);
    bufp->fullIData(oldp+436,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[31]),32);
    bufp->fullIData(oldp+437,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__10__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+438,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__11__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+439,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__12__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+440,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__13__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+441,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__14__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+442,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__15__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+443,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__16__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+444,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__17__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+445,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__18__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+446,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__19__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+447,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__1__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+448,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__20__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+449,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__21__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+450,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__22__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+451,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__23__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+452,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__24__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+453,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__25__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+454,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__26__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+455,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__27__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+456,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__28__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+457,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__29__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+458,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__2__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+459,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__30__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+460,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__31__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+461,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__3__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+462,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__4__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+463,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__5__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+464,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__6__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+465,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__7__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+466,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__8__KET____DOT__rf_reg_q),32);
    bufp->fullIData(oldp+467,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__9__KET____DOT__rf_reg_q),32);
    bufp->fullBit(oldp+468,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_new_id_q));
    bufp->fullQData(oldp+469,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex[0]),34);
    bufp->fullQData(oldp+471,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex[1]),34);
    bufp->fullBit(oldp+473,((1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+474,((1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                   >> 2U))));
    bufp->fullCData(oldp+475,((7U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                     >> 3U))),3);
    bufp->fullBit(oldp+476,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req));
    bufp->fullIData(oldp+477,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q),32);
    bufp->fullBit(oldp+478,((0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))));
    bufp->fullBit(oldp+479,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q));
    bufp->fullBit(oldp+480,((1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                   >> 5U))));
    bufp->fullIData(oldp+481,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mepc_csr__DOT__rdata_q),32);
    bufp->fullIData(oldp+482,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_depc_csr__DOT__rdata_q),32);
    bufp->fullIData(oldp+483,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtvec_csr__DOT__rdata_q),32);
    bufp->fullBit(oldp+484,((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q))));
    bufp->fullCData(oldp+485,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q),2);
    bufp->fullCData(oldp+486,((3U & ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q))
                                      ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                         >> 2U) : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q)))),2);
    bufp->fullBit(oldp+487,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q));
    bufp->fullCData(oldp+488,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_cause_q),3);
    bufp->fullBit(oldp+489,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                                   >> 2U))));
    bufp->fullBit(oldp+490,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                                   >> 0xfU))));
    bufp->fullBit(oldp+491,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                                   >> 0xcU))));
    bufp->fullIData(oldp+492,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtval_csr__DOT__rdata_q),32);
    bufp->fullCData(oldp+493,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q),6);
    bufp->fullIData(oldp+494,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mie_csr__DOT__rdata_q),18);
    bufp->fullIData(oldp+495,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mscratch_csr__DOT__rdata_q),32);
    bufp->fullCData(oldp+496,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mcause_csr__DOT__rdata_q),7);
    bufp->fullIData(oldp+497,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q),32);
    bufp->fullIData(oldp+498,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dscratch0_csr__DOT__rdata_q),32);
    bufp->fullIData(oldp+499,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dscratch1_csr__DOT__rdata_q),32);
    bufp->fullCData(oldp+500,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_csr__DOT__rdata_q),3);
    bufp->fullCData(oldp+501,((7U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                     >> 2U))),3);
    bufp->fullIData(oldp+502,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_epc_csr__DOT__rdata_q),32);
    bufp->fullCData(oldp+503,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_cause_csr__DOT__rdata_q),7);
    bufp->fullIData(oldp+504,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q),32);
    bufp->fullCData(oldp+505,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q),3);
    bufp->fullQData(oldp+506,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0]),64);
    bufp->fullQData(oldp+508,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[1]),64);
    bufp->fullQData(oldp+510,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[2]),64);
    bufp->fullQData(oldp+512,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[3]),64);
    bufp->fullQData(oldp+514,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[4]),64);
    bufp->fullQData(oldp+516,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[5]),64);
    bufp->fullQData(oldp+518,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[6]),64);
    bufp->fullQData(oldp+520,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[7]),64);
    bufp->fullQData(oldp+522,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[8]),64);
    bufp->fullQData(oldp+524,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[9]),64);
    bufp->fullQData(oldp+526,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[10]),64);
    bufp->fullQData(oldp+528,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[11]),64);
    bufp->fullQData(oldp+530,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[12]),64);
    bufp->fullQData(oldp+532,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[13]),64);
    bufp->fullQData(oldp+534,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[14]),64);
    bufp->fullQData(oldp+536,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[15]),64);
    bufp->fullQData(oldp+538,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[16]),64);
    bufp->fullQData(oldp+540,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[17]),64);
    bufp->fullQData(oldp+542,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[18]),64);
    bufp->fullQData(oldp+544,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[19]),64);
    bufp->fullQData(oldp+546,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[20]),64);
    bufp->fullQData(oldp+548,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[21]),64);
    bufp->fullQData(oldp+550,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[22]),64);
    bufp->fullQData(oldp+552,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[23]),64);
    bufp->fullQData(oldp+554,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[24]),64);
    bufp->fullQData(oldp+556,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[25]),64);
    bufp->fullQData(oldp+558,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[26]),64);
    bufp->fullQData(oldp+560,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[27]),64);
    bufp->fullQData(oldp+562,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[28]),64);
    bufp->fullQData(oldp+564,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[29]),64);
    bufp->fullQData(oldp+566,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[30]),64);
    bufp->fullQData(oldp+568,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[31]),64);
    bufp->fullQData(oldp+570,((1ULL + vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_q)),64);
    bufp->fullQData(oldp+572,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_q),64);
    bufp->fullCData(oldp+574,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q),8);
    bufp->fullQData(oldp+575,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_q),64);
    bufp->fullQData(oldp+577,((1ULL + vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_q)),64);
    bufp->fullQData(oldp+579,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a),33);
    bufp->fullIData(oldp+581,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_q[0]),32);
    bufp->fullIData(oldp+582,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_q[1]),32);
    bufp->fullIData(oldp+583,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__g_no_alu_rvb__DOT__unused_imd_val_q[0]),32);
    bufp->fullIData(oldp+584,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__g_no_alu_rvb__DOT__unused_imd_val_q[1]),32);
    bufp->fullIData(oldp+585,(((IData)(1U) << (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q))),32);
    bufp->fullIData(oldp+586,((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                      [1U])),32);
    bufp->fullIData(oldp+587,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q),32);
    bufp->fullIData(oldp+588,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q),32);
    bufp->fullBit(oldp+589,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid));
    bufp->fullCData(oldp+590,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q),5);
    bufp->fullBit(oldp+591,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold));
    bufp->fullBit(oldp+592,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q));
    bufp->fullBit(oldp+593,((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q))));
    bufp->fullCData(oldp+594,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q),3);
    bufp->fullCData(oldp+595,((3U & (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                             [1U] >> 0x20U)))),2);
    bufp->fullCData(oldp+596,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q),2);
    bufp->fullBit(oldp+597,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set));
    bufp->fullBit(oldp+598,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__g_branch_set_flop__DOT__branch_set_raw_q));
    bufp->fullBit(oldp+599,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_q));
    bufp->fullQData(oldp+600,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imd_val_q[0]),34);
    bufp->fullQData(oldp+602,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imd_val_q[1]),34);
    bufp->fullBit(oldp+604,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q));
    bufp->fullBit(oldp+605,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q));
    bufp->fullBit(oldp+606,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q));
    bufp->fullBit(oldp+607,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q));
    bufp->fullBit(oldp+608,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_q));
    bufp->fullBit(oldp+609,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_q));
    bufp->fullBit(oldp+610,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_q));
    bufp->fullBit(oldp+611,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug));
    bufp->fullBit(oldp+612,((IData)((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                      >> 5U) | (0U 
                                                == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q))))));
    bufp->fullCData(oldp+613,((0xffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtvec_csr__DOT__rdata_q)),8);
    bufp->fullCData(oldp+614,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q),3);
    bufp->fullBit(oldp+615,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q));
    bufp->fullBit(oldp+616,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_q));
    bufp->fullCData(oldp+617,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q),2);
    bufp->fullCData(oldp+618,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q),2);
    bufp->fullCData(oldp+619,(((2U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                      << 1U)) | (1U 
                                                 & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                    >> 1U)))),2);
    bufp->fullIData(oldp+620,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q),24);
    bufp->fullCData(oldp+621,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q),2);
    bufp->fullCData(oldp+622,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q),2);
    bufp->fullBit(oldp+623,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q));
    bufp->fullBit(oldp+624,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q));
    bufp->fullBit(oldp+625,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q));
    bufp->fullBit(oldp+626,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q));
    bufp->fullBit(oldp+627,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q));
    bufp->fullBit(oldp+628,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err));
    bufp->fullCData(oldp+629,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs),3);
    bufp->fullBit(oldp+630,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_2_en_q));
    bufp->fullBit(oldp+631,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_bus_err_1_q));
    __Vtemp_3[0U] = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtval_csr__DOT__rdata_q;
    __Vtemp_3[1U] = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mepc_csr__DOT__rdata_q;
    __Vtemp_3[2U] = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
    __Vtemp_3[3U] = (IData)((((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_id)) 
                              << 0x20U) | (QData)((IData)(
                                                          (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                                           << 1U)))));
    __Vtemp_3[4U] = (IData)(((((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_id)) 
                               << 0x20U) | (QData)((IData)(
                                                           (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                                            << 1U)))) 
                             >> 0x20U));
    bufp->fullWData(oldp+632,(__Vtemp_3),160);
    bufp->fullBit(oldp+637,(((3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                    >> 0x1cU)) > (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q))));
    bufp->fullBit(oldp+638,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dbg_csr))));
    bufp->fullBit(oldp+639,(((0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                             | (IData)(vlSelf->soc_top__DOT__instr_req))));
    bufp->fullIData(oldp+640,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex)
                                ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                          [0U]) : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d))),32);
    bufp->fullBit(oldp+641,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid) 
                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid))));
    bufp->fullQData(oldp+642,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a
                                : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1)
                                    ? (1ULL | ((QData)((IData)(
                                                               (0x7fffffffU 
                                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a))) 
                                               << 2U))
                                    : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2)
                                        ? (1ULL | ((QData)((IData)(
                                                                   (0x3fffffffU 
                                                                    & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a))) 
                                                   << 3U))
                                        : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3)
                                            ? (1ULL 
                                               | ((QData)((IData)(
                                                                  (0x1fffffffU 
                                                                   & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a))) 
                                                  << 4U))
                                            : (1ULL 
                                               | ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a)) 
                                                  << 1U))))))),33);
    bufp->fullBit(oldp+644,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q)) 
                             & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a) 
                                ^ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b)))));
    bufp->fullBit(oldp+645,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__dret_insn_dec))));
    bufp->fullBit(oldp+646,(((3U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q)) 
                             & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mret_insn_dec) 
                                | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                   & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__wfi_insn_dec))))));
    bufp->fullBit(oldp+647,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec) 
                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req))));
    bufp->fullIData(oldp+648,(((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                ? ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                    ? 0x80U : ((1U 
                                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                                ? 0x80U
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_depc_csr__DOT__rdata_q))
                                : ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                    ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                        ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mepc_csr__DOT__rdata_q
                                        : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__exc_pc)
                                    : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                        ? (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                   >> 1U))
                                        : 0x80U)))),32);
    bufp->fullBit(oldp+649,((1U & ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                    ? ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                        ? 0x80U : (
                                                   (1U 
                                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                                    ? 0x80U
                                                    : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_depc_csr__DOT__rdata_q))
                                    : ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                        ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mepc_csr__DOT__rdata_q
                                            : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__exc_pc)
                                        : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                            ? (IData)(
                                                      (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                       >> 1U))
                                            : 0x80U))))));
    bufp->fullIData(oldp+650,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req)
                                ? ((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                            >> 3U)) 
                                   << 2U) : (IData)(
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                     >> 1U)))),32);
    bufp->fullBit(oldp+651,((1U & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q)) 
                                   & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr))));
    bufp->fullBit(oldp+652,((1U & ((~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q) 
                                       >> 2U)) & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr 
                                                  >> 2U)))));
    bufp->fullBit(oldp+653,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_rvalid_2)) 
                             & ((((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)) 
                                  | (4U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) 
                                 & (IData)(vlSelf->soc_top__DOT__cpu_rvalid)) 
                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_2_en_q)))));
    bufp->fullBit(oldp+654,((((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)) 
                              | (4U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) 
                             & (IData)(vlSelf->soc_top__DOT__cpu_rvalid))));
    bufp->fullBit(oldp+655,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_rvalid_2)) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_bus_err_1_q))));
    bufp->fullCData(oldp+656,((0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+657,((0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+658,((0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                        >> 7U))),5);
    bufp->fullIData(oldp+659,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id),32);
    bufp->fullSData(oldp+660,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_c_id),16);
    bufp->fullBit(oldp+661,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_is_compressed_id));
    bufp->fullCData(oldp+662,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_gets_expanded_id),2);
    bufp->fullSData(oldp+663,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_expanded_id),16);
    bufp->fullBit(oldp+664,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err));
    bufp->fullBit(oldp+665,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err_plus2));
    bufp->fullBit(oldp+666,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_c_insn_id));
    bufp->fullIData(oldp+667,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                               << 1U)),32);
    bufp->fullIData(oldp+668,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_id),32);
    bufp->fullSData(oldp+669,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                               >> 0x14U)),12);
    bufp->fullBit(oldp+670,((1U & VL_REDXOR_16(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_expanded_id))));
    bufp->fullBit(oldp+671,((1U & VL_REDXOR_2(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_gets_expanded_id))));
    bufp->fullBit(oldp+672,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dbg_csr));
    bufp->fullBit(oldp+673,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr));
    bufp->fullCData(oldp+674,((7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0x19U))),3);
    bufp->fullIData(oldp+675,((((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                            >> 0x14U))),32);
    bufp->fullIData(oldp+676,((((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0xfe0U 
                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 7U))))),32);
    bufp->fullIData(oldp+677,((((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                            >> 0x1fU))) 
                                << 0xdU) | ((0x1000U 
                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                >> 0x13U)) 
                                            | ((0x800U 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   << 4U)) 
                                               | ((0x7e0U 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                      >> 0x14U)) 
                                                  | (0x1eU 
                                                     & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                        >> 7U))))))),32);
    bufp->fullIData(oldp+678,((0xfffff000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)),32);
    bufp->fullIData(oldp+679,((((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                            >> 0x1fU))) 
                                << 0x14U) | ((0xff000U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id) 
                                             | ((0x800U 
                                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 9U)) 
                                                | (0x7feU 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                      >> 0x14U)))))),32);
    bufp->fullIData(oldp+680,((0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                        >> 0xfU))),32);
    bufp->fullBit(oldp+681,(((0x340U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                         >> 0x14U)) 
                             | (0x341U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                           >> 0x14U)))));
    bufp->fullSData(oldp+682,(((0x3e0U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0xaU)) 
                               | (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                           >> 7U)))),10);
    bufp->fullCData(oldp+683,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                               >> 0x1bU)),5);
    bufp->fullCData(oldp+684,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q),5);
    bufp->fullCData(oldp+685,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_q),5);
    bufp->fullIData(oldp+686,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_q),32);
    bufp->fullIData(oldp+687,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q),32);
    bufp->fullWData(oldp+688,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q),96);
    bufp->fullCData(oldp+691,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q),3);
    bufp->fullIData(oldp+692,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q),31);
    bufp->fullBit(oldp+693,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q));
    bufp->fullBit(oldp+694,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id));
    bufp->fullCData(oldp+695,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_pc_mux_id),2);
    bufp->fullBit(oldp+696,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ctrl_busy));
    bufp->fullBit(oldp+697,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_req_int));
    bufp->fullBit(oldp+698,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_if));
    bufp->fullBit(oldp+699,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_mode_entering));
    bufp->fullBit(oldp+700,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save));
    bufp->fullBit(oldp+701,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_run));
    bufp->fullCData(oldp+702,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs),4);
    bufp->fullBit(oldp+703,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_d));
    bufp->fullBit(oldp+704,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_d));
    bufp->fullCData(oldp+705,((3U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                     >> 1U))),2);
    bufp->fullCData(oldp+706,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q),3);
    bufp->fullCData(oldp+707,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h88c42b44__0) 
                                << 2U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h077f4b9b__0) 
                                           << 1U) | 
                                          (1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)))))),3);
    bufp->fullBit(oldp+708,(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c));
    bufp->fullBit(oldp+709,(vlSelf->soc_top__DOT__u_mac__DOT__m_we_c));
    bufp->fullBit(oldp+710,(vlSelf->soc_top__DOT__dma_m_req));
    bufp->fullBit(oldp+711,(vlSelf->soc_top__DOT__dma_m_rvalid));
    bufp->fullBit(oldp+712,(vlSelf->soc_top__DOT__dma_m_we));
    bufp->fullIData(oldp+713,(vlSelf->soc_top__DOT__dma_m_addr),32);
    bufp->fullIData(oldp+714,(vlSelf->soc_top__DOT__dma_m_wdata),32);
    bufp->fullIData(oldp+715,(vlSelf->soc_top__DOT__apb_paddr),32);
    bufp->fullIData(oldp+716,(vlSelf->soc_top__DOT__apb_pwdata),32);
    bufp->fullIData(oldp+717,(vlSelf->soc_top__DOT__apb_bus_data),32);
    bufp->fullIData(oldp+718,(vlSelf->soc_top__DOT__cpu_rdata_apb),32);
    bufp->fullBit(oldp+719,(vlSelf->soc_top__DOT__apb_psel));
    bufp->fullBit(oldp+720,(vlSelf->soc_top__DOT__apb_penable));
    bufp->fullBit(oldp+721,(vlSelf->soc_top__DOT__apb_pwrite));
    bufp->fullBit(oldp+722,(vlSelf->soc_top__DOT__apb_pready));
    bufp->fullBit(oldp+723,(vlSelf->soc_top__DOT__cpu_rvalid_apb));
    bufp->fullCData(oldp+724,(vlSelf->soc_top__DOT__s_psel),6);
    bufp->fullIData(oldp+725,(vlSelf->soc_top__DOT__s1_prdata),32);
    bufp->fullIData(oldp+726,(vlSelf->soc_top__DOT__d_src),32);
    bufp->fullIData(oldp+727,(vlSelf->soc_top__DOT__d_dst),32);
    bufp->fullSData(oldp+728,(vlSelf->soc_top__DOT__d_len),16);
    bufp->fullCData(oldp+729,(vlSelf->soc_top__DOT__u_bridge__DOT__state),2);
    bufp->fullBit(oldp+730,(vlSelf->soc_top__DOT__u_dma_core__DOT__done_o));
    bufp->fullBit(oldp+731,(vlSelf->soc_top__DOT__u_dma_core__DOT__err_o));
    bufp->fullCData(oldp+732,(vlSelf->soc_top__DOT__u_dma_core__DOT__state),3);
    bufp->fullIData(oldp+733,(vlSelf->soc_top__DOT__u_dma_core__DOT__curr_src),32);
    bufp->fullIData(oldp+734,(vlSelf->soc_top__DOT__u_dma_core__DOT__curr_dst),32);
    bufp->fullIData(oldp+735,(vlSelf->soc_top__DOT__u_dma_core__DOT__data_buffer),32);
    bufp->fullSData(oldp+736,(vlSelf->soc_top__DOT__u_dma_core__DOT__bytes_left),16);
    bufp->fullBit(oldp+737,((1U & (IData)(vlSelf->soc_top__DOT__s_psel))));
    bufp->fullBit(oldp+738,((1U & ((IData)(vlSelf->soc_top__DOT__s_psel) 
                                   >> 1U))));
    bufp->fullIData(oldp+739,(vlSelf->soc_top__DOT__u_mac__DOT__col_out[0]),32);
    bufp->fullIData(oldp+740,(vlSelf->soc_top__DOT__u_mac__DOT__col_out[1]),32);
    bufp->fullIData(oldp+741,(vlSelf->soc_top__DOT__u_mac__DOT__col_out[2]),32);
    bufp->fullIData(oldp+742,(vlSelf->soc_top__DOT__u_mac__DOT__col_out[3]),32);
    bufp->fullIData(oldp+743,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
                              [0U]),32);
    bufp->fullIData(oldp+744,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
                              [1U]),32);
    bufp->fullIData(oldp+745,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
                              [2U]),32);
    bufp->fullIData(oldp+746,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
                              [3U]),32);
    bufp->fullIData(oldp+747,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[0]),32);
    bufp->fullIData(oldp+748,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[1]),32);
    bufp->fullIData(oldp+749,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[2]),32);
    bufp->fullIData(oldp+750,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[3]),32);
    bufp->fullBit(oldp+751,(((~ (IData)(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req)) 
                             & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c))));
    bufp->fullBit(oldp+752,(((0U == (IData)(vlSelf->soc_top__DOT__u_bridge__DOT__state)) 
                             & (IData)(vlSelf->soc_top__DOT____Vcellinp__u_bridge__obi_req))));
    bufp->fullBit(oldp+753,(((IData)(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req) 
                             || ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c) 
                                 || (IData)(vlSelf->soc_top__DOT__dma_m_req)))));
    bufp->fullBit(oldp+754,(((IData)(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req)
                              ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we)
                              : ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c)
                                  ? (IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_we_c)
                                  : ((IData)(vlSelf->soc_top__DOT__dma_m_req) 
                                     && (IData)(vlSelf->soc_top__DOT__dma_m_we))))));
    bufp->fullBit(oldp+755,((1U & (~ ((IData)(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req)
                                       ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we)
                                       : ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c)
                                           ? (IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_we_c)
                                           : ((IData)(vlSelf->soc_top__DOT__dma_m_req) 
                                              && (IData)(vlSelf->soc_top__DOT__dma_m_we))))))));
    bufp->fullBit(oldp+756,(vlSelf->soc_top__DOT__instr_req));
    bufp->fullBit(oldp+757,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out));
    bufp->fullBit(oldp+758,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we));
    bufp->fullCData(oldp+759,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be),4);
    bufp->fullIData(oldp+760,(((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                        >> 3U)) << 2U)),32);
    bufp->fullIData(oldp+761,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_wdata),32);
    bufp->fullBit(oldp+762,((0x400U == (0xfffU & (IData)(
                                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                          >> 0x15U))))));
    bufp->fullBit(oldp+763,((0x400U != (0xfffU & (IData)(
                                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                          >> 0x15U))))));
    bufp->fullBit(oldp+764,(vlSelf->soc_top__DOT____Vcellinp__u_bridge__obi_req));
    bufp->fullIData(oldp+765,(vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a),32);
    bufp->fullIData(oldp+766,(vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b),32);
    bufp->fullQData(oldp+767,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_d_ex[0]),34);
    bufp->fullQData(oldp+769,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_d_ex[1]),34);
    bufp->fullCData(oldp+771,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_we_ex),2);
    bufp->fullBit(oldp+772,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__icache_inval));
    bufp->fullBit(oldp+773,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set));
    bufp->fullCData(oldp+774,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id),3);
    bufp->fullCData(oldp+775,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause),7);
    bufp->fullIData(oldp+776,((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                       >> 1U))),32);
    bufp->fullBit(oldp+777,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result));
    bufp->fullIData(oldp+778,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_wdata_id),32);
    bufp->fullBit(oldp+779,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id));
    bufp->fullCData(oldp+780,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator),7);
    bufp->fullIData(oldp+781,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a),32);
    bufp->fullIData(oldp+782,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex),32);
    bufp->fullIData(oldp+783,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__result_ex),32);
    bufp->fullBit(oldp+784,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec))));
    bufp->fullBit(oldp+785,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec))));
    bufp->fullBit(oldp+786,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__mult_sel_ex));
    bufp->fullBit(oldp+787,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex));
    bufp->fullCData(oldp+788,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator),2);
    bufp->fullCData(oldp+789,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode),2);
    bufp->fullBit(oldp+790,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_access));
    bufp->fullCData(oldp+791,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op),2);
    bufp->fullIData(oldp+792,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int),32);
    bufp->fullBit(oldp+793,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_csr_insn_id));
    bufp->fullCData(oldp+794,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type),2);
    bufp->fullBit(oldp+795,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_sign_ext));
    bufp->fullBit(oldp+796,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req));
    bufp->fullBit(oldp+797,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_valid));
    bufp->fullBit(oldp+798,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id));
    bufp->fullBit(oldp+799,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id));
    bufp->fullBit(oldp+800,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id));
    bufp->fullBit(oldp+801,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause));
    bufp->fullBit(oldp+802,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtvec_init));
    bufp->fullIData(oldp+803,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval),32);
    bufp->fullBit(oldp+804,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_jump));
    bufp->fullBit(oldp+805,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_branch));
    bufp->fullBit(oldp+806,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_tbranch));
    bufp->fullBit(oldp+807,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_load));
    bufp->fullBit(oldp+808,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_store));
    bufp->fullBit(oldp+809,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_insn_id));
    bufp->fullIData(oldp+810,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__exception_pc),32);
    bufp->fullCData(oldp+811,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_d),2);
    bufp->fullIData(oldp+812,(((0x20000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                            << 0xeU)) 
                               | ((0x10000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                               << 9U)) 
                                  | ((0x8000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                                 << 4U)) 
                                     | (0x7fffU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                                   >> 0x10U)))))),18);
    bufp->fullIData(oldp+813,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_d),32);
    bufp->fullIData(oldp+814,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_d),32);
    bufp->fullIData(oldp+815,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtvec_init)
                                ? 1U : (1U | (0xffffff00U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)))),32);
    bufp->fullIData(oldp+816,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_d),32);
    bufp->fullBit(oldp+817,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstack_en));
    bufp->fullCData(oldp+818,((0xffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)),8);
    bufp->fullCData(oldp+819,((0xc0U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)),8);
    bufp->fullIData(oldp+820,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int),32);
    bufp->fullBit(oldp+821,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr));
    bufp->fullBit(oldp+822,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                   >> 1U))));
    bufp->fullBit(oldp+823,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                   >> 2U))));
    bufp->fullCData(oldp+824,((7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                     >> 3U))),3);
    bufp->fullBit(oldp+825,((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)));
    bufp->fullIData(oldp+826,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result),32);
    bufp->fullQData(oldp+827,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b),33);
    bufp->fullQData(oldp+829,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext),34);
    bufp->fullBit(oldp+831,((0U == (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                            >> 1U)))));
    bufp->fullBit(oldp+832,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel));
    bufp->fullQData(oldp+833,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_imd_val_d[0]),34);
    bufp->fullQData(oldp+835,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_imd_val_d[1]),34);
    bufp->fullCData(oldp+837,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal) 
                                << 1U) | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal) 
                                          | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal)))),2);
    bufp->fullIData(oldp+838,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev),32);
    bufp->fullQData(oldp+839,((0x1ffffffffULL & (~ 
                                                 ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                                  << 1U)))),33);
    bufp->fullBit(oldp+841,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1));
    bufp->fullBit(oldp+842,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2));
    bufp->fullBit(oldp+843,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3));
    bufp->fullBit(oldp+844,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate));
    bufp->fullQData(oldp+845,((0x1ffffffffULL & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                                  ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b
                                                  : 
                                                 ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate)
                                                   ? 
                                                  (~ 
                                                   ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                                    << 1U))
                                                   : 
                                                  ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                                   << 1U))))),33);
    bufp->fullBit(oldp+847,((1U & (((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                     ^ vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex) 
                                    >> 0x1fU) ? ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                  >> 0x1fU) 
                                                 ^ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed))
                                    : (~ (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                  >> 0x20U)))))));
    bufp->fullBit(oldp+848,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed));
    bufp->fullBit(oldp+849,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left));
    bufp->fullBit(oldp+850,((8U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))));
    bufp->fullCData(oldp+851,((0x3fU & ((IData)(0x20U) 
                                        - (0x1fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)))),6);
    bufp->fullIData(oldp+852,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand),32);
    bufp->fullQData(oldp+853,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed),33);
    bufp->fullQData(oldp+855,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext),33);
    bufp->fullBit(oldp+857,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__unused_shift_result_ext));
    bufp->fullIData(oldp+858,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result),32);
    bufp->fullIData(oldp+859,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev),32);
    bufp->fullCData(oldp+860,(((0x10U & ((~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0xfU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex 
                                                         >> 0x18U))))) 
                                         << 4U)) | 
                               (0xfU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex 
                                        >> 0x18U)))),5);
    bufp->fullCData(oldp+861,((0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex 
                                        >> 0x10U))),5);
    bufp->fullBit(oldp+862,(((3U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)) 
                             | (6U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)))));
    bufp->fullBit(oldp+863,(((4U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)) 
                             | (7U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)))));
    bufp->fullIData(oldp+864,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                               | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)),32);
    bufp->fullIData(oldp+865,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                               & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)),32);
    bufp->fullIData(oldp+866,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                               ^ vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)),32);
    bufp->fullIData(oldp+867,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result),32);
    bufp->fullBit(oldp+868,((1U & (((IData)(0x20U) 
                                    - (0x1fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                   >> 5U))));
    bufp->fullQData(oldp+869,((0x7ffffffffULL & (VL_MULS_QQQ(35, 
                                                             (0x7ffffffffULL 
                                                              & VL_EXTENDS_QI(35,17, 
                                                                              (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a) 
                                                                                << 0x10U) 
                                                                               | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_a)))), 
                                                             (0x7ffffffffULL 
                                                              & VL_EXTENDS_QI(35,17, 
                                                                              (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b) 
                                                                                << 0x10U) 
                                                                               | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b))))) 
                                                 + 
                                                 VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum)))),35);
    bufp->fullQData(oldp+871,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum),34);
    bufp->fullBit(oldp+873,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a));
    bufp->fullBit(oldp+874,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b));
    bufp->fullBit(oldp+875,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid));
    bufp->fullBit(oldp+876,((0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode))));
    bufp->fullQData(oldp+877,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d),34);
    bufp->fullQData(oldp+879,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d),34);
    bufp->fullQData(oldp+881,((0x3ffffffffULL & ((0x7ffffffffULL 
                                                  & VL_MULS_QQQ(35, 
                                                                (0x7ffffffffULL 
                                                                 & VL_EXTENDS_QI(35,17, 
                                                                                (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a) 
                                                                                << 0x10U) 
                                                                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_a)))), 
                                                                (0x7ffffffffULL 
                                                                 & VL_EXTENDS_QI(35,17, 
                                                                                (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b) 
                                                                                << 0x10U) 
                                                                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b)))))) 
                                                 + 
                                                 (0x7ffffffffULL 
                                                  & VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum))))),34);
    bufp->fullBit(oldp+883,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a));
    bufp->fullBit(oldp+884,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b));
    bufp->fullBit(oldp+885,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal));
    bufp->fullIData(oldp+886,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d),32);
    bufp->fullIData(oldp+887,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d),32);
    bufp->fullIData(oldp+888,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d),32);
    bufp->fullIData(oldp+889,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder),32);
    bufp->fullQData(oldp+890,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient),33);
    bufp->fullCData(oldp+892,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d),5);
    bufp->fullBit(oldp+893,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal) 
                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal))));
    bufp->fullBit(oldp+894,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold));
    bufp->fullBit(oldp+895,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d));
    bufp->fullBit(oldp+896,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal));
    bufp->fullBit(oldp+897,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal));
    bufp->fullCData(oldp+898,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d),3);
    bufp->fullBit(oldp+899,((1U & (IData)((1ULL & (
                                                   (VL_MULS_QQQ(35, 
                                                                (0x7ffffffffULL 
                                                                 & VL_EXTENDS_QI(35,17, 
                                                                                (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a) 
                                                                                << 0x10U) 
                                                                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_a)))), 
                                                                (0x7ffffffffULL 
                                                                 & VL_EXTENDS_QI(35,17, 
                                                                                (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b) 
                                                                                << 0x10U) 
                                                                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b))))) 
                                                    + 
                                                    VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum)) 
                                                   >> 0x22U))))));
    bufp->fullCData(oldp+900,(((2U & ((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                               >> 0x21U)) 
                                      << 1U)) | (1U 
                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext)))),2);
    bufp->fullSData(oldp+901,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_a),16);
    bufp->fullSData(oldp+902,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b),16);
    bufp->fullCData(oldp+903,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_d),2);
    bufp->fullBit(oldp+904,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn));
    bufp->fullBit(oldp+905,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ebrk_insn));
    bufp->fullBit(oldp+906,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mret_insn_dec));
    bufp->fullBit(oldp+907,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__dret_insn_dec));
    bufp->fullBit(oldp+908,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ecall_insn_dec));
    bufp->fullBit(oldp+909,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__wfi_insn_dec));
    bufp->fullBit(oldp+910,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_d));
    bufp->fullBit(oldp+911,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec));
    bufp->fullBit(oldp+912,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set_raw_d));
    bufp->fullBit(oldp+913,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec));
    bufp->fullBit(oldp+914,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_dec));
    bufp->fullBit(oldp+915,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set));
    bufp->fullBit(oldp+916,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw));
    bufp->fullBit(oldp+917,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec));
    bufp->fullBit(oldp+918,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id));
    bufp->fullIData(oldp+919,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b),32);
    bufp->fullBit(oldp+920,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_wdata_sel));
    bufp->fullBit(oldp+921,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we));
    bufp->fullBit(oldp+922,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_we_raw));
    bufp->fullBit(oldp+923,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec));
    bufp->fullBit(oldp+924,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_b_dec));
    bufp->fullCData(oldp+925,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel),2);
    bufp->fullCData(oldp+926,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec),2);
    bufp->fullBit(oldp+927,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec));
    bufp->fullBit(oldp+928,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_a_mux_sel));
    bufp->fullCData(oldp+929,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel),3);
    bufp->fullCData(oldp+930,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec),3);
    bufp->fullBit(oldp+931,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec));
    bufp->fullBit(oldp+932,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec));
    bufp->fullBit(oldp+933,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec));
    bufp->fullBit(oldp+934,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec));
    bufp->fullBit(oldp+935,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_d));
    bufp->fullBit(oldp+936,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_d));
    bufp->fullBit(oldp+937,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_d));
    bufp->fullBit(oldp+938,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err_prio));
    bufp->fullBit(oldp+939,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_prio));
    bufp->fullBit(oldp+940,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio));
    bufp->fullBit(oldp+941,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio));
    bufp->fullBit(oldp+942,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_prio));
    bufp->fullBit(oldp+943,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_prio));
    bufp->fullBit(oldp+944,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn));
    bufp->fullBit(oldp+945,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn));
    bufp->fullBit(oldp+946,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn));
    bufp->fullBit(oldp+947,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__wfi_insn));
    bufp->fullBit(oldp+948,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn));
    bufp->fullBit(oldp+949,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err));
    bufp->fullBit(oldp+950,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_illegal));
    bufp->fullCData(oldp+951,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op),2);
    bufp->fullCData(oldp+952,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode),7);
    bufp->fullCData(oldp+953,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu),7);
    bufp->fullIData(oldp+954,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr),32);
    bufp->fullIData(oldp+955,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__exc_pc),32);
    bufp->fullCData(oldp+956,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__irq_vec),5);
    bufp->fullBit(oldp+957,((IData)((0U != (0x60U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause))))));
    bufp->fullBit(oldp+958,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req));
    bufp->fullBit(oldp+959,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d));
    bufp->fullCData(oldp+960,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n),2);
    bufp->fullCData(oldp+961,((3U & ((IData)(vlSelf->soc_top__DOT__instr_req)
                                      ? VL_SHIFTR_III(2,2,32, (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n), 1U)
                                      : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n)))),2);
    bufp->fullCData(oldp+962,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n),2);
    bufp->fullCData(oldp+963,((3U & ((IData)(vlSelf->soc_top__DOT__instr_req)
                                      ? VL_SHIFTR_III(2,2,32, (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n), 1U)
                                      : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n)))),2);
    bufp->fullIData(oldp+964,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d),32);
    bufp->fullBit(oldp+965,(((~ (IData)(vlSelf->soc_top__DOT__instr_req)) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfdd8329f__0))));
    bufp->fullBit(oldp+966,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set) 
                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfdd8329f__0))));
    bufp->fullBit(oldp+967,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid));
    bufp->fullCData(oldp+968,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_d),3);
    bufp->fullCData(oldp+969,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46fac9ec__0) 
                                << 2U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf22c316__0) 
                                           << 1U) | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h91d85a72__0)))),3);
    bufp->fullBit(oldp+970,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err));
    bufp->fullBit(oldp+971,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
    bufp->fullBit(oldp+972,((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr)));
    bufp->fullCData(oldp+973,((3U & (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                             >> 1U)))),2);
    bufp->fullBit(oldp+974,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access));
    bufp->fullBit(oldp+975,(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req));
    bufp->fullBit(oldp+976,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id))));
    bufp->fullBit(oldp+977,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
                             & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec)))));
    bufp->fullBit(oldp+978,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv))));
    bufp->fullBit(oldp+979,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv))));
    bufp->fullBit(oldp+980,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn) 
                             | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn) 
                                | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_d) 
                                   | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_err))))));
    bufp->fullCData(oldp+981,(((((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)) 
                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d1f386f__0)) 
                                << 2U) | ((((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)) 
                                            & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h2b0e8186__0)) 
                                           << 1U) | 
                                          ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)) 
                                           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hc11c213a__0))))),3);
    bufp->fullBit(oldp+982,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set) 
                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659e18c__0))));
    bufp->fullCData(oldp+983,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                << 1U) | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id))),2);
    bufp->fullBit(oldp+984,(((IData)(vlSelf->soc_top__DOT__instr_req) 
                             | (0U == (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                       >> 0xcU)))));
    bufp->fullSData(oldp+985,((0x3ffU & ((IData)(vlSelf->soc_top__DOT__instr_req)
                                          ? (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d 
                                             >> 2U)
                                          : (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                             >> 2U)))),10);
    bufp->fullIData(oldp+986,(vlSelf->soc_top__DOT__instr_rdata),32);
    bufp->fullBit(oldp+987,(vlSelf->soc_top__DOT__cpu_gnt));
    bufp->fullBit(oldp+988,(vlSelf->soc_top__DOT__cpu_rvalid));
    bufp->fullBit(oldp+989,(vlSelf->soc_top__DOT__dma_m_gnt));
    bufp->fullBit(oldp+990,(vlSelf->soc_top__DOT__u_core__DOT__double_fault_seen_o));
    bufp->fullIData(oldp+991,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec),32);
    bufp->fullBit(oldp+992,((1U & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)));
    bufp->fullBit(oldp+993,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_valid_clear));
    bufp->fullBit(oldp+994,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_load_err));
    bufp->fullBit(oldp+995,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_store_err));
    bufp->fullBit(oldp+996,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu));
    bufp->fullBit(oldp+997,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en));
    bufp->fullBit(oldp+998,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready));
    bufp->fullBit(oldp+999,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid));
    bufp->fullBit(oldp+1000,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_err));
    bufp->fullBit(oldp+1001,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__en_wb));
    bufp->fullBit(oldp+1002,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_instr_ret_wb));
    bufp->fullCData(oldp+1003,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d),6);
    bufp->fullBit(oldp+1004,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_en));
    bufp->fullBit(oldp+1005,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mie_en));
    bufp->fullBit(oldp+1006,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mscratch_en));
    bufp->fullBit(oldp+1007,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_en));
    bufp->fullCData(oldp+1008,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_d),7);
    bufp->fullBit(oldp+1009,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_en));
    bufp->fullBit(oldp+1010,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_en));
    bufp->fullBit(oldp+1011,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtvec_en));
    bufp->fullIData(oldp+1012,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d),32);
    bufp->fullBit(oldp+1013,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_en));
    bufp->fullBit(oldp+1014,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_en));
    bufp->fullBit(oldp+1015,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dscratch0_en));
    bufp->fullBit(oldp+1016,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dscratch1_en));
    bufp->fullBit(oldp+1017,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_we));
    bufp->fullIData(oldp+1018,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we),32);
    bufp->fullIData(oldp+1019,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we),32);
    bufp->fullIData(oldp+1020,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr),32);
    bufp->fullBit(oldp+1021,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                    >> 1U))));
    bufp->fullBit(oldp+1022,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                    >> 1U))));
    bufp->fullBit(oldp+1023,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr 
                                    >> 1U))));
    bufp->fullCData(oldp+1024,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d),8);
    bufp->fullBit(oldp+1025,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_we));
    bufp->fullBit(oldp+1026,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int));
    bufp->fullIData(oldp+1027,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                >> 3U)),29);
    bufp->fullIData(oldp+1028,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                >> 3U)),29);
    bufp->fullIData(oldp+1029,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr 
                                >> 3U)),29);
    bufp->fullBit(oldp+1030,((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we)));
    bufp->fullBit(oldp+1031,((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we)));
    bufp->fullQData(oldp+1032,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_load),64);
    bufp->fullBit(oldp+1034,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__we));
    bufp->fullQData(oldp+1035,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_d),64);
    bufp->fullBit(oldp+1037,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                    >> 2U))));
    bufp->fullBit(oldp+1038,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                    >> 2U))));
    bufp->fullQData(oldp+1039,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_load),64);
    bufp->fullBit(oldp+1041,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__we));
    bufp->fullQData(oldp+1042,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_d),64);
    bufp->fullBit(oldp+1044,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv));
    bufp->fullBit(oldp+1045,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_branch));
    bufp->fullBit(oldp+1046,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_jump));
    bufp->fullBit(oldp+1047,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_id));
    bufp->fullBit(oldp+1048,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multicycle_done));
    bufp->fullBit(oldp+1049,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_d));
    bufp->fullCData(oldp+1050,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns),4);
    bufp->fullBit(oldp+1051,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__halt_if));
    bufp->fullBit(oldp+1052,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__retain_id));
    bufp->fullBit(oldp+1053,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__special_req));
    bufp->fullBit(oldp+1054,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_new_id_d));
    bufp->fullBit(oldp+1055,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_valid_raw));
    bufp->fullBit(oldp+1056,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready) 
                              & (1U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_gets_expanded)))));
    bufp->fullIData(oldp+1057,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata),32);
    bufp->fullBit(oldp+1058,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_err));
    bufp->fullIData(oldp+1059,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed),32);
    bufp->fullBit(oldp+1060,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn));
    bufp->fullBit(oldp+1061,((3U != (3U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))));
    bufp->fullCData(oldp+1062,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_gets_expanded),2);
    bufp->fullBit(oldp+1063,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i));
    bufp->fullBit(oldp+1064,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i));
    bufp->fullCData(oldp+1065,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d),5);
    bufp->fullCData(oldp+1066,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d),5);
    bufp->fullCData(oldp+1067,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d),3);
    bufp->fullCData(oldp+1068,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded),2);
    bufp->fullWData(oldp+1069,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d),96);
    bufp->fullCData(oldp+1072,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d1f386f__0) 
                                 << 2U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h2b0e8186__0) 
                                            << 1U) 
                                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hc11c213a__0)))),3);
    bufp->fullCData(oldp+1073,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en),3);
    bufp->fullBit(oldp+1074,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo));
    bufp->fullIData(oldp+1075,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata),32);
    bufp->fullBit(oldp+1076,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed));
    bufp->fullBit(oldp+1077,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed));
    bufp->fullBit(oldp+1078,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two));
    bufp->fullBit(oldp+1079,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update));
    bufp->fullBit(oldp+1080,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update));
    bufp->fullBit(oldp+1081,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update));
    bufp->fullBit(oldp+1082,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d));
    bufp->fullBit(oldp+1083,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d));
    bufp->fullBit(oldp+1084,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d));
    bufp->fullCData(oldp+1085,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns),3);
    bufp->fullBit(oldp+1086,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_rvalid_2));
    bufp->fullIData(oldp+1087,(vlSelf->soc_top__DOT__u_mem__DOT__arb_addr),32);
    bufp->fullCData(oldp+1088,(vlSelf->soc_top__DOT__u_mem__DOT__arb_be),4);
    bufp->fullIData(oldp+1089,(vlSelf->soc_top__DOT__u_mem__DOT__arb_wdata),32);
    bufp->fullBit(oldp+1090,((0x100U == (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                         >> 0x14U))));
    bufp->fullBit(oldp+1091,(vlSelf->soc_top__DOT__u_mem__DOT____Vcellinp__u_ram__sram_cen));
    bufp->fullSData(oldp+1092,((0x7ffU & (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                          >> 2U))),11);
    bufp->fullIData(oldp+1093,(vlSelf->soc_top__DOT__cpu_rdata),32);
    bufp->fullIData(oldp+1094,(vlSelf->soc_top__DOT__u_core__DOT__rf_wdata_wb),32);
    bufp->fullIData(oldp+1095,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext),32);
    bufp->fullBit(oldp+1096,(vlSelf->clk));
    bufp->fullBit(oldp+1097,(vlSelf->rst_n));
    bufp->fullIData(oldp+1098,(vlSelf->soc_top__DOT__instr_addr),32);
    bufp->fullBit(oldp+1099,(vlSelf->soc_top__DOT__dma_busy));
    bufp->fullBit(oldp+1100,(vlSelf->soc_top__DOT__mac_done));
    bufp->fullCData(oldp+1101,(vlSelf->soc_top__DOT__mac_fsm_state),3);
    bufp->fullIData(oldp+1102,(vlSelf->soc_top__DOT__u_mem__DOT__ram_dout),32);
    bufp->fullIData(oldp+1103,(((0U == (0xffU & vlSelf->soc_top__DOT__apb_paddr))
                                 ? vlSelf->soc_top__DOT__d_src
                                 : ((4U == (0xffU & vlSelf->soc_top__DOT__apb_paddr))
                                     ? vlSelf->soc_top__DOT__d_dst
                                     : ((8U == (0xffU 
                                                & vlSelf->soc_top__DOT__apb_paddr))
                                         ? (IData)(vlSelf->soc_top__DOT__d_len)
                                         : ((0x10U 
                                             == (0xffU 
                                                 & vlSelf->soc_top__DOT__apb_paddr))
                                             ? (((IData)(vlSelf->soc_top__DOT__u_dma_regs__DOT__err_i) 
                                                 << 2U) 
                                                | (IData)(vlSelf->soc_top__DOT__dma_busy))
                                             : 0U))))),32);
    bufp->fullIData(oldp+1104,((((IData)(vlSelf->soc_top__DOT__instr_req) 
                                 | (0U == (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                           >> 0xcU)))
                                 ? vlSelf->soc_top__DOT__instr_rdata
                                 : vlSelf->soc_top__DOT__u_mem__DOT__ram_dout)),32);
    bufp->fullCData(oldp+1105,(vlSelf->soc_top__DOT__rst_sync),2);
    bufp->fullBit(oldp+1106,(vlSelf->soc_top__DOT__rst_n_int));
    bufp->fullBit(oldp+1107,(vlSelf->soc_top__DOT__u_core__DOT__clk));
    bufp->fullCData(oldp+1108,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ctrl_busy) 
                                 | (((0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                                     | (IData)(vlSelf->soc_top__DOT__instr_req)) 
                                    | (0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))))
                                 ? 5U : 0xaU)),4);
    bufp->fullBit(oldp+1109,(vlSelf->soc_top__DOT__u_core__DOT__core_clock_gate_i__DOT__en_latch));
    bufp->fullBit(oldp+1110,((1U & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ebrk_insn)) 
                                    & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ecall_insn_dec)) 
                                       & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn)) 
                                          & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_csr_insn_id)) 
                                             & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err)))))))));
    bufp->fullBit(oldp+1111,((1U & ((~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_mode_entering) 
                                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q))) 
                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q)))));
    bufp->fullBit(oldp+1112,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we)) 
                              & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q) 
                                 & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id)) 
                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec))))));
    bufp->fullBit(oldp+1113,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q) 
                               & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id)) 
                                  & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec))) 
                              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we))));
    bufp->fullBit(oldp+1114,((((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_insn_id)) 
                               & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err)) 
                                  & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q))) 
                              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec))));
    bufp->fullBit(oldp+1115,((((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_insn_id)) 
                               & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err)) 
                                  & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q))) 
                              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_b_dec))));
    bufp->fullBit(oldp+1116,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req) 
                               | (0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) 
                              & (0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns)))));
    bufp->fullBit(oldp+1117,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_instr_ret_wb) 
                              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_is_compressed_id))));
    bufp->fullBit(oldp+1118,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)) 
                              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready))));
    bufp->fullCData(oldp+1119,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_we)
                                 ? (5U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)
                                 : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q))),3);
    bufp->fullBit(oldp+1120,(((3U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1eU)) & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr))));
    bufp->fullCData(oldp+1121,((0x1fU & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id)
                                          ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex
                                          : (- vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)))),6);
    bufp->fullBit(oldp+1122,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_valid_clear)) 
                              & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__g_branch_set_flop__DOT__branch_set_raw_q) 
                                 | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_q) 
                                    | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw))))));
    bufp->fullBit(oldp+1123,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q) 
                              & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec) 
                                 & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)) 
                                    | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id))))));
    bufp->fullIData(oldp+1124,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_a_mux_sel)
                                 ? 0U : (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0xfU)))),32);
    bufp->fullBit(oldp+1125,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en) 
                              & ((~ ((0x340U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                 >> 0x14U)) 
                                     | (0x341U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U)))) 
                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr)))));
    bufp->fullCData(oldp+1126,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio) 
                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug))
                                 ? 1U : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_d)
                                          ? 4U : 0U))),3);
    bufp->fullBit(oldp+1127,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__wfi_insn) 
                              | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en) 
                                  & ((~ ((0x340U == 
                                          (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                           >> 0x14U)) 
                                         | (0x341U 
                                            == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                >> 0x14U)))) 
                                     & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr))) 
                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)))));
    bufp->fullBit(oldp+1128,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en) 
                               & ((~ ((0x340U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x14U)) 
                                      | (0x341U == 
                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x14U)))) 
                                  & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr))) 
                              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q))));
    bufp->fullBit(oldp+1129,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_new_id_d) 
                              | ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_valid_clear)) 
                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)))));
    bufp->fullBit(oldp+1130,(((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q) 
                              && (IData)((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                           >> 1U) & 
                                          (2U == (3U 
                                                  & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q))))))));
    bufp->fullIData(oldp+1131,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)
                                  ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr
                                  : (0xfffffffcU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q)) 
                                + ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfdd8329f__0) 
                                   << 2U))),32);
    bufp->fullBit(oldp+1132,((1U & (~ (IData)((3U == 
                                               (3U 
                                                & (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                                    >> 1U) 
                                                   | ((2U 
                                                       & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                            >> 1U)))))))))));
    bufp->fullIData(oldp+1133,(((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                 ? ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[1U] 
                                     << 0x10U) | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                                  >> 0x10U))
                                 : ((vlSelf->soc_top__DOT__instr_rdata 
                                     << 0x10U) | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                                  >> 0x10U)))),32);
    bufp->fullBit(oldp+1134,((1U & ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                     ? (((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed)) 
                                         & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q) 
                                            >> 1U)) 
                                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q))
                                     : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err)))));
    bufp->fullBit(oldp+1135,((IData)((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                       >> 1U) & (2U 
                                                 == 
                                                 (3U 
                                                  & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)))))));
    bufp->fullBit(oldp+1136,((1U & (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                     >> 1U) | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                               & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid))))));
    bufp->fullIData(oldp+1137,((0x7fffffffU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                               + ((2U 
                                                   & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)) 
                                                      << 1U)) 
                                                  | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two))))),31);
    bufp->fullIData(oldp+1138,((0x7fffffffU & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)
                                                ? (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr 
                                                   >> 1U)
                                                : (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                                   + 
                                                   ((2U 
                                                     & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)) 
                                                        << 1U)) 
                                                    | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)))))),31);
    bufp->fullIData(oldp+1139,(((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                 ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                     ? ((vlSelf->soc_top__DOT__cpu_rdata 
                                         << 8U) | (0xffU 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                                      >> 0x10U)))
                                     : ((vlSelf->soc_top__DOT__cpu_rdata 
                                         << 0x10U) 
                                        | (0xffffU 
                                           & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                              >> 8U))))
                                 : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                     ? ((vlSelf->soc_top__DOT__cpu_rdata 
                                         << 0x18U) 
                                        | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q)
                                     : vlSelf->soc_top__DOT__cpu_rdata))),32);
    bufp->fullIData(oldp+1140,(((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                 ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                     ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->soc_top__DOT__cpu_rdata 
                                                            >> 7U)))) 
                                             << 0x10U) 
                                            | ((0xff00U 
                                                & (vlSelf->soc_top__DOT__cpu_rdata 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                                     >> 0x10U))))
                                         : ((0xff00U 
                                             & (vlSelf->soc_top__DOT__cpu_rdata 
                                                << 8U)) 
                                            | (0xffU 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                                  >> 0x10U))))
                                     : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                         ? (((- (IData)(
                                                        (vlSelf->soc_top__DOT__cpu_rdata 
                                                         >> 0x1fU))) 
                                             << 0x10U) 
                                            | (vlSelf->soc_top__DOT__cpu_rdata 
                                               >> 0x10U))
                                         : (vlSelf->soc_top__DOT__cpu_rdata 
                                            >> 0x10U)))
                                 : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                     ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->soc_top__DOT__cpu_rdata 
                                                            >> 0x17U)))) 
                                             << 0x10U) 
                                            | (0xffffU 
                                               & (vlSelf->soc_top__DOT__cpu_rdata 
                                                  >> 8U)))
                                         : (0xffffU 
                                            & (vlSelf->soc_top__DOT__cpu_rdata 
                                               >> 8U)))
                                     : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->soc_top__DOT__cpu_rdata 
                                                            >> 0xfU)))) 
                                             << 0x10U) 
                                            | (0xffffU 
                                               & vlSelf->soc_top__DOT__cpu_rdata))
                                         : (0xffffU 
                                            & vlSelf->soc_top__DOT__cpu_rdata))))),32);
    bufp->fullIData(oldp+1141,(((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                 ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                     ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                         ? (((- (IData)(
                                                        (vlSelf->soc_top__DOT__cpu_rdata 
                                                         >> 0x1fU))) 
                                             << 8U) 
                                            | (vlSelf->soc_top__DOT__cpu_rdata 
                                               >> 0x18U))
                                         : (vlSelf->soc_top__DOT__cpu_rdata 
                                            >> 0x18U))
                                     : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->soc_top__DOT__cpu_rdata 
                                                            >> 0x17U)))) 
                                             << 8U) 
                                            | (0xffU 
                                               & (vlSelf->soc_top__DOT__cpu_rdata 
                                                  >> 0x10U)))
                                         : (0xffU & 
                                            (vlSelf->soc_top__DOT__cpu_rdata 
                                             >> 0x10U))))
                                 : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                     ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->soc_top__DOT__cpu_rdata 
                                                            >> 0xfU)))) 
                                             << 8U) 
                                            | (0xffU 
                                               & (vlSelf->soc_top__DOT__cpu_rdata 
                                                  >> 8U)))
                                         : (0xffU & 
                                            (vlSelf->soc_top__DOT__cpu_rdata 
                                             >> 8U)))
                                     : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->soc_top__DOT__cpu_rdata 
                                                            >> 7U)))) 
                                             << 8U) 
                                            | (0xffU 
                                               & vlSelf->soc_top__DOT__cpu_rdata))
                                         : (0xffU & vlSelf->soc_top__DOT__cpu_rdata))))),32);
    bufp->fullIData(oldp+1142,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__wb_stage_i__DOT__rf_wdata_wb_mux[0]),32);
    bufp->fullIData(oldp+1143,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__wb_stage_i__DOT__rf_wdata_wb_mux[1]),32);
}
