// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"
#include "Vsoc_top___024root.h"

VL_ATTR_COLD void Vsoc_top___024root___eval_static(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vsoc_top___024root___eval_initial__TOP(Vsoc_top___024root* vlSelf);

VL_ATTR_COLD void Vsoc_top___024root___eval_initial(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_initial\n"); );
    // Body
    Vsoc_top___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[8U] = 1U;
    vlSelf->__Vm_traceActivity[7U] = 1U;
    vlSelf->__Vm_traceActivity[6U] = 1U;
    vlSelf->__Vm_traceActivity[5U] = 1U;
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
    vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__rst_n_int__0 
        = vlSelf->soc_top__DOT__rst_n_int;
    vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__u_core__DOT__clk__0 
        = vlSelf->soc_top__DOT__u_core__DOT__clk;
}

VL_ATTR_COLD void Vsoc_top___024root___eval_initial__TOP(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    vlSelf->soc_top__DOT__u_core__DOT__ic_tag_rdata[0U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__ic_tag_rdata[1U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__ic_data_rdata[0U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__ic_data_rdata[1U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_alu = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_d[0U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_d[1U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[1U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[2U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[3U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[3U] 
        = (1U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [3U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[4U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[4U] 
        = (2U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [4U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[5U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[5U] 
        = (4U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [5U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[6U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[6U] 
        = (8U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [6U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[7U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[7U] 
        = (0x10U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [7U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[8U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[8U] 
        = (0x20U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [8U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[9U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[9U] 
        = (0x40U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [9U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xaU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xaU] 
        = (0x80U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0xaU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xbU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xbU] 
        = (0x100U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0xbU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xcU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xcU] 
        = (0x200U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0xcU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xdU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xdU] 
        = (0x400U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0xdU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xeU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xeU] 
        = (0x800U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0xeU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xfU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xfU] 
        = (0x1000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0xfU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x10U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x10U] 
        = (0x2000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x10U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x11U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x11U] 
        = (0x4000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x11U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x12U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x12U] 
        = (0x8000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x12U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x13U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x13U] 
        = (0x10000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x13U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x14U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x14U] 
        = (0x20000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x14U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x15U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x15U] 
        = (0x40000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x15U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x16U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x16U] 
        = (0x80000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x16U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x17U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x17U] 
        = (0x100000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x17U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x18U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x18U] 
        = (0x200000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x18U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x19U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x19U] 
        = (0x400000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x19U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1aU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1aU] 
        = (0x800000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x1aU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1bU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1bU] 
        = (0x1000000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x1bU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1cU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1cU] 
        = (0x2000000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x1cU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1dU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1dU] 
        = (0x4000000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x1dU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1eU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1eU] 
        = (0x8000000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x1eU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1fU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1fU] 
        = (0x10000000U | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
           [0x1fU]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[1U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[3U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[4U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[5U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[6U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[7U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[8U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[9U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xaU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xbU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xcU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xdU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xeU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0xfU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x10U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x11U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x12U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x13U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x14U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x15U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x16U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x17U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x18U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x19U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1aU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1bU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1cU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1dU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1eU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0x1fU] = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__col_in[0U] = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__col_in[1U] = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__col_in[2U] = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__col_in[3U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[0U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[1U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[2U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[3U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg[0U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg[1U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg[2U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg[3U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pmp_req_err[0U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pmp_req_err[1U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pmp_req_err[2U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[1U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[3U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[4U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[5U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[6U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[7U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[8U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[9U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0xaU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0xbU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0xcU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0xdU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0xeU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0xfU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x10U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x11U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x12U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x13U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x14U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x15U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x16U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x17U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x18U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x19U] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x1aU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x1bU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x1cU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x1dU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x1eU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0x1fU] = 0ULL;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[0U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[1U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[2U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[3U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[4U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[5U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[6U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[7U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[8U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[9U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[0xaU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[0xbU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[0xcU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[0xdU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[0xeU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[0xfU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[0U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[1U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[2U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[3U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[4U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[5U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[6U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[7U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[8U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[9U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[0xaU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[0xbU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[0xcU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[0xdU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[0xeU] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[0xfU] = 0U;
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x77617265U;
    __Vtemp_1[2U] = 0x6669726dU;
    VL_READMEM_N(true, 32, 1024, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_1)
                 ,  &(vlSelf->soc_top__DOT__u_mem__DOT__u_rom__DOT__rom)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vsoc_top___024root___eval_final(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__stl(Vsoc_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsoc_top___024root___eval_phase__stl(Vsoc_top___024root* vlSelf);

VL_ATTR_COLD void Vsoc_top___024root___eval_settle(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vsoc_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/soc_top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsoc_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__stl(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 128> Vsoc_top__ConstPool__TABLE_hd5b48b0a_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsoc_top__ConstPool__TABLE_hb804351c_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsoc_top__ConstPool__TABLE_h2fe71d6b_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsoc_top__ConstPool__TABLE_ha686e182_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vsoc_top__ConstPool__TABLE_h6451e8c0_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vsoc_top__ConstPool__TABLE_h2aabc56c_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vsoc_top__ConstPool__TABLE_hf64aebe0_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vsoc_top__ConstPool__TABLE_h323b7bc3_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vsoc_top__ConstPool__TABLE_h6d182578_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vsoc_top__ConstPool__TABLE_hbf9cbdd6_0;
extern const VlUnpacked<CData/*3:0*/, 32> Vsoc_top__ConstPool__TABLE_hee875898_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vsoc_top__ConstPool__TABLE_h9d63e220_0;

VL_ATTR_COLD void Vsoc_top___024root___stl_sequent__TOP__0(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he6d6a5e6__0;
    soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he6d6a5e6__0 = 0;
    CData/*0:0*/ soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT____VdfgExtracted_h1929ae58__0;
    soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT____VdfgExtracted_h1929ae58__0 = 0;
    CData/*0:0*/ soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT____VdfgExtracted_h75d42971__0;
    soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT____VdfgExtracted_h75d42971__0 = 0;
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*6:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*6:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    SData/*9:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*6:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*4:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    // Body
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_mode_entering = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__load_wgt = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__m_we_c = 0U;
    vlSelf->soc_top__DOT__rst_n_int = (1U & ((IData)(vlSelf->soc_top__DOT__rst_sync) 
                                             >> 1U));
    vlSelf->soc_top__DOT__mac_done = (8U == (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_tag_ram_input[0U] 
        = vlSelf->soc_top__DOT__u_core__DOT__ic_tag_rdata
        [0U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_tag_ram_input[1U] 
        = vlSelf->soc_top__DOT__u_core__DOT__ic_tag_rdata
        [1U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_data_ram_input[0U] 
        = vlSelf->soc_top__DOT__u_core__DOT__ic_data_rdata
        [0U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_data_ram_input[1U] 
        = vlSelf->soc_top__DOT__u_core__DOT__ic_data_rdata
        [1U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_d 
        = (3U & (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                  & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)) 
                 >> 1U));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ctrl_busy = 1U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[0U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr
        [0U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[1U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr
        [1U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[2U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr
        [2U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[3U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr
        [3U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg[0U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
        [0U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg[1U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
        [1U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg[2U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
        [2U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg[3U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
        [3U];
    if ((1U & (~ (IData)(vlSelf->clk)))) {
        vlSelf->soc_top__DOT__u_core__DOT__core_clock_gate_i__DOT__en_latch 
            = (1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__core_busy_q));
    }
    vlSelf->soc_top__DOT__u_mac__DOT__next_state = vlSelf->soc_top__DOT__u_mac__DOT__state;
    if ((8U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
        vlSelf->soc_top__DOT__u_mac__DOT__next_state = 0U;
    } else if ((4U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
                vlSelf->soc_top__DOT__u_mac__DOT__next_state 
                    = (((IData)(vlSelf->soc_top__DOT__u_mac__DOT__row_cnt) 
                        == (0xffU & ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__reg_m) 
                                     - (IData)(1U))))
                        ? 8U : 3U);
            } else if (vlSelf->soc_top__DOT__u_mac__DOT__res_done_r) {
                vlSelf->soc_top__DOT__u_mac__DOT__next_state = 7U;
            }
        } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
            if ((0xaU == (IData)(vlSelf->soc_top__DOT__u_mac__DOT__drain_cnt))) {
                vlSelf->soc_top__DOT__u_mac__DOT__next_state = 6U;
            }
        } else if ((0xbU == (IData)(vlSelf->soc_top__DOT__u_mac__DOT__feed_cnt))) {
            vlSelf->soc_top__DOT__u_mac__DOT__next_state = 5U;
        }
    } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
        if ((1U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
            if (vlSelf->soc_top__DOT__mac_m_rvalid) {
                vlSelf->soc_top__DOT__u_mac__DOT__next_state = 4U;
            }
        } else {
            vlSelf->soc_top__DOT__u_mac__DOT__next_state = 3U;
        }
    } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
        if (vlSelf->soc_top__DOT__u_mac__DOT__wgt_done_r) {
            vlSelf->soc_top__DOT__u_mac__DOT__next_state = 2U;
        }
    } else if (vlSelf->soc_top__DOT__u_mac__DOT__start) {
        vlSelf->soc_top__DOT__u_mac__DOT__next_state = 1U;
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__m_wdata_c = 0U;
    vlSelf->soc_top__DOT__s_psel = 0U;
    if (vlSelf->soc_top__DOT__apb_psel) {
        vlSelf->soc_top__DOT__s_psel = ((0x8000U & vlSelf->soc_top__DOT__apb_paddr)
                                         ? 0U : ((0x4000U 
                                                  & vlSelf->soc_top__DOT__apb_paddr)
                                                  ? 
                                                 ((0x2000U 
                                                   & vlSelf->soc_top__DOT__apb_paddr)
                                                   ? 0U
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->soc_top__DOT__apb_paddr)
                                                    ? 
                                                   (0x20U 
                                                    | (IData)(vlSelf->soc_top__DOT__s_psel))
                                                    : 
                                                   (0x10U 
                                                    | (IData)(vlSelf->soc_top__DOT__s_psel))))
                                                  : 
                                                 ((0x2000U 
                                                   & vlSelf->soc_top__DOT__apb_paddr)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelf->soc_top__DOT__apb_paddr)
                                                    ? 
                                                   (8U 
                                                    | (IData)(vlSelf->soc_top__DOT__s_psel))
                                                    : 
                                                   (4U 
                                                    | (IData)(vlSelf->soc_top__DOT__s_psel)))
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->soc_top__DOT__apb_paddr)
                                                    ? 
                                                   (2U 
                                                    | (IData)(vlSelf->soc_top__DOT__s_psel))
                                                    : 
                                                   (1U 
                                                    | (IData)(vlSelf->soc_top__DOT__s_psel))))));
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_if = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[0U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[0U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[0U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[0U][4U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[1U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[1U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[1U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[1U][4U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[2U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[2U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[2U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[2U][4U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[3U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[3U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[3U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[3U][4U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out;
    vlSelf->soc_top__DOT__mac_fsm_state = (7U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h88c42b44__0 
        = (IData)((2U == (6U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h077f4b9b__0 
        = (IData)((1U == (3U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))));
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[1U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[1U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[1U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[1U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[2U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[2U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[2U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[2U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[3U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[3U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[3U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[3U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[4U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[4U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[4U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[4U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[2U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_q;
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[0U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [0U][3U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[0U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [0U][0U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[0U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [0U][1U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[0U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [0U][2U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[1U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [1U][3U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[1U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [1U][0U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[1U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [1U][1U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[1U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [1U][2U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[2U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [2U][3U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[2U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [2U][0U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[2U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [2U][1U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[2U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [2U][2U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[3U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [3U][3U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[3U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [3U][0U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[3U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [3U][1U];
    vlSelf->soc_top__DOT__u_mac__DOT__weight_in[3U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
        [3U][2U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err 
        = (1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)));
    vlSelf->soc_top__DOT__u_mac__DOT__row_in[0U] = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__row_in[1U] = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__row_in[2U] = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__row_in[3U] = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_d 
        = (1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)
                  ? ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)) 
                     & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                        >> 2U)) : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_q)));
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__col_in[0U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__col_in[1U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__col_in[2U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__col_in[3U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h92feb91f__0 
        = (1U & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)) 
                 | (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dbg_csr = 0U;
    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                  >> 0x1fU)))) {
        if ((0x40000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
            if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1aU)))) {
                            if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x17U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x16U)))) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dbg_csr = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT____VdfgExtracted_h75d42971__0 
        = ((0x3a0U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                       >> 0x14U)) | ((0x3a1U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                 >> 0x14U)) 
                                     | ((0x3a2U == 
                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x14U)) 
                                        | ((0x3a3U 
                                            == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                >> 0x14U)) 
                                           | ((0x3b0U 
                                               == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U)) 
                                              | ((0x3b1U 
                                                  == 
                                                  (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U)) 
                                                 | ((0x3b2U 
                                                     == 
                                                     (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                      >> 0x14U)) 
                                                    | ((0x3b3U 
                                                        == 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)) 
                                                       | ((0x3b4U 
                                                           == 
                                                           (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                            >> 0x14U)) 
                                                          | ((0x3b5U 
                                                              == 
                                                              (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                               >> 0x14U)) 
                                                             | ((0x3b6U 
                                                                 == 
                                                                 (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                  >> 0x14U)) 
                                                                | ((0x3b7U 
                                                                    == 
                                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                     >> 0x14U)) 
                                                                   | ((0x3b8U 
                                                                       == 
                                                                       (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                        >> 0x14U)) 
                                                                      | ((0x3b9U 
                                                                          == 
                                                                          (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                           >> 0x14U)) 
                                                                         | ((0x3baU 
                                                                             == 
                                                                             (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                              >> 0x14U)) 
                                                                            | ((0x3bbU 
                                                                                == 
                                                                                (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                                >> 0x14U)) 
                                                                               | ((0x3bcU 
                                                                                == 
                                                                                (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                                >> 0x14U)) 
                                                                                | ((0x3bdU 
                                                                                == 
                                                                                (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                                >> 0x14U)) 
                                                                                | ((0x3beU 
                                                                                == 
                                                                                (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                                >> 0x14U)) 
                                                                                | (0x3bfU 
                                                                                == 
                                                                                (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                                >> 0x14U)))))))))))))))))))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_pc_mux_id = 1U;
    vlSelf->soc_top__DOT__u_mac__DOT__m_addr_c = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__m_req_c = 0U;
    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__state) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state)))) {
                    vlSelf->soc_top__DOT__u_mac__DOT__load_wgt = 1U;
                }
            }
        }
        if ((4U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
            if ((2U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state)))) {
                    vlSelf->soc_top__DOT__u_mac__DOT__m_we_c = 1U;
                    vlSelf->soc_top__DOT__u_mac__DOT__m_wdata_c 
                        = vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                        [vlSelf->soc_top__DOT__u_mac__DOT__res_cnt];
                    vlSelf->soc_top__DOT__u_mac__DOT__m_addr_c 
                        = ((vlSelf->soc_top__DOT__u_mac__DOT__res_addr 
                            + ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__row_cnt) 
                               << 4U)) + ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__res_cnt) 
                                          << 2U));
                    vlSelf->soc_top__DOT__u_mac__DOT__m_req_c = 1U;
                }
            }
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
                    vlSelf->soc_top__DOT__u_mac__DOT__row_in[0U] 
                        = vlSelf->soc_top__DOT__u_mac__DOT__act_buf
                        [0U];
                    vlSelf->soc_top__DOT__u_mac__DOT__row_in[1U] 
                        = vlSelf->soc_top__DOT__u_mac__DOT__act_buf
                        [1U];
                    vlSelf->soc_top__DOT__u_mac__DOT__row_in[2U] 
                        = vlSelf->soc_top__DOT__u_mac__DOT__act_buf
                        [2U];
                    vlSelf->soc_top__DOT__u_mac__DOT__row_in[3U] 
                        = vlSelf->soc_top__DOT__u_mac__DOT__act_buf
                        [3U];
                } else {
                    vlSelf->soc_top__DOT__u_mac__DOT__row_in[0U] 
                        = vlSelf->soc_top__DOT__u_mac__DOT__act_buf
                        [0U];
                    vlSelf->soc_top__DOT__u_mac__DOT__row_in[1U] 
                        = vlSelf->soc_top__DOT__u_mac__DOT__act_buf
                        [1U];
                    vlSelf->soc_top__DOT__u_mac__DOT__row_in[2U] 
                        = vlSelf->soc_top__DOT__u_mac__DOT__act_buf
                        [2U];
                    vlSelf->soc_top__DOT__u_mac__DOT__row_in[3U] 
                        = vlSelf->soc_top__DOT__u_mac__DOT__act_buf
                        [3U];
                }
            }
        } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
                vlSelf->soc_top__DOT__u_mac__DOT__m_we_c = 0U;
                vlSelf->soc_top__DOT__u_mac__DOT__m_addr_c 
                    = (vlSelf->soc_top__DOT__u_mac__DOT__act_addr 
                       + (0xcU & ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__row_cnt) 
                                  << 2U)));
                vlSelf->soc_top__DOT__u_mac__DOT__m_req_c = 1U;
            }
        } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__state))) {
            vlSelf->soc_top__DOT__u_mac__DOT__m_we_c = 0U;
            vlSelf->soc_top__DOT__u_mac__DOT__m_addr_c 
                = (vlSelf->soc_top__DOT__u_mac__DOT__wgt_addr 
                   + ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__wgt_cnt) 
                      << 2U));
            vlSelf->soc_top__DOT__u_mac__DOT__m_req_c = 1U;
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q) 
           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_req_int = 1U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_q)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__g_branch_set_flop__DOT__branch_set_raw_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug 
        = (1U & ((3U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q))
                  ? (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                     >> 0xfU) : ((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q)) 
                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                                    >> 0xcU))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_run = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex[0U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imd_val_q
        [0U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex[1U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imd_val_q
        [1U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[1U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__1__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[2U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__2__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[3U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__3__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[4U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__4__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[5U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__5__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[6U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__6__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[7U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__7__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[8U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__8__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[9U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__9__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xaU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__10__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xbU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__11__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xcU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__12__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xdU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__13__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xeU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__14__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0xfU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__15__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x10U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__16__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x11U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__17__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x12U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__18__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x13U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__19__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x14U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__20__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x15U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__21__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x16U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__22__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x17U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__23__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x18U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__24__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x19U] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__25__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1aU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__26__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1bU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__27__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1cU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__28__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1dU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__29__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1eU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__30__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0x1fU] 
        = vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__31__KET____DOT__rf_reg_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q));
    vlSelf->soc_top__DOT__u_core__DOT__clk = ((IData)(vlSelf->clk) 
                                              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__core_clock_gate_i__DOT__en_latch));
    vlSelf->soc_top__DOT__apb_pready = 1U;
    vlSelf->soc_top__DOT__s1_prdata = (((((((((0U == 
                                               (0xffU 
                                                & vlSelf->soc_top__DOT__apb_paddr)) 
                                              | (4U 
                                                 == 
                                                 (0xffU 
                                                  & vlSelf->soc_top__DOT__apb_paddr))) 
                                             | (8U 
                                                == 
                                                (0xffU 
                                                 & vlSelf->soc_top__DOT__apb_paddr))) 
                                            | (0x18U 
                                               == (0xffU 
                                                   & vlSelf->soc_top__DOT__apb_paddr))) 
                                           | (0x1cU 
                                              == (0xffU 
                                                  & vlSelf->soc_top__DOT__apb_paddr))) 
                                          | (0x20U 
                                             == (0xffU 
                                                 & vlSelf->soc_top__DOT__apb_paddr))) 
                                         | (0x24U == 
                                            (0xffU 
                                             & vlSelf->soc_top__DOT__apb_paddr))) 
                                        | (0x28U == 
                                           (0xffU & vlSelf->soc_top__DOT__apb_paddr)))
                                        ? ((0U == (0xffU 
                                                   & vlSelf->soc_top__DOT__apb_paddr))
                                            ? 0U : 
                                           ((4U == 
                                             (0xffU 
                                              & vlSelf->soc_top__DOT__apb_paddr))
                                             ? (((IData)(vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__sticky_done) 
                                                 << 3U) 
                                                | (IData)(vlSelf->soc_top__DOT__mac_fsm_state))
                                             : ((8U 
                                                 == 
                                                 (0xffU 
                                                  & vlSelf->soc_top__DOT__apb_paddr))
                                                 ? 
                                                (((IData)(vlSelf->soc_top__DOT__u_mac__DOT__reg_m) 
                                                  << 0x10U) 
                                                 | (((IData)(vlSelf->soc_top__DOT__u_mac__DOT__reg_k) 
                                                     << 8U) 
                                                    | (IData)(vlSelf->soc_top__DOT__u_mac__DOT__reg_n)))
                                                 : 
                                                ((0x18U 
                                                  == 
                                                  (0xffU 
                                                   & vlSelf->soc_top__DOT__apb_paddr))
                                                  ? (IData)(vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__pe_addr_reg)
                                                  : 
                                                 ((0x1cU 
                                                   == 
                                                   (0xffU 
                                                    & vlSelf->soc_top__DOT__apb_paddr))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__pe_addr_reg))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__pe_addr_reg))
                                                     ? 
                                                    vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                                                    [3U]
                                                     : 
                                                    vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                                                    [2U])
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__pe_addr_reg))
                                                     ? 
                                                    vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                                                    [1U]
                                                     : 
                                                    vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                                                    [0U]))
                                                   : 
                                                  ((0x20U 
                                                    == 
                                                    (0xffU 
                                                     & vlSelf->soc_top__DOT__apb_paddr))
                                                    ? vlSelf->soc_top__DOT__u_mac__DOT__wgt_addr
                                                    : 
                                                   ((0x24U 
                                                     == 
                                                     (0xffU 
                                                      & vlSelf->soc_top__DOT__apb_paddr))
                                                     ? vlSelf->soc_top__DOT__u_mac__DOT__act_addr
                                                     : vlSelf->soc_top__DOT__u_mac__DOT__res_addr)))))))
                                        : 0U);
    if ((0x20U & (IData)(vlSelf->soc_top__DOT__s_psel))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__s_psel) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__s_psel) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__s_psel) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__s_psel) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__s_psel)))) {
                            vlSelf->soc_top__DOT__apb_pready = 1U;
                        }
                    }
                }
            }
        }
        vlSelf->soc_top__DOT__apb_bus_data = 0U;
    } else if ((0x10U & (IData)(vlSelf->soc_top__DOT__s_psel))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__s_psel) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__s_psel) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__s_psel) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->soc_top__DOT__s_psel)))) {
                        vlSelf->soc_top__DOT__apb_pready = 1U;
                    }
                }
            }
        }
        vlSelf->soc_top__DOT__apb_bus_data = 0U;
    } else if ((8U & (IData)(vlSelf->soc_top__DOT__s_psel))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__s_psel) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__s_psel) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__s_psel)))) {
                    vlSelf->soc_top__DOT__apb_pready = 1U;
                }
            }
        }
        vlSelf->soc_top__DOT__apb_bus_data = 0U;
    } else {
        vlSelf->soc_top__DOT__apb_bus_data = ((4U & (IData)(vlSelf->soc_top__DOT__s_psel))
                                               ? 0U
                                               : ((2U 
                                                   & (IData)(vlSelf->soc_top__DOT__s_psel))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->soc_top__DOT__s_psel))
                                                    ? 0U
                                                    : vlSelf->soc_top__DOT__s1_prdata)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->soc_top__DOT__s_psel))
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (0xffU 
                                                      & vlSelf->soc_top__DOT__apb_paddr))
                                                     ? vlSelf->soc_top__DOT__d_src
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (0xffU 
                                                       & vlSelf->soc_top__DOT__apb_paddr))
                                                      ? vlSelf->soc_top__DOT__d_dst
                                                      : 
                                                     ((8U 
                                                       == 
                                                       (0xffU 
                                                        & vlSelf->soc_top__DOT__apb_paddr))
                                                       ? (IData)(vlSelf->soc_top__DOT__d_len)
                                                       : 
                                                      ((0x10U 
                                                        == 
                                                        (0xffU 
                                                         & vlSelf->soc_top__DOT__apb_paddr))
                                                        ? 
                                                       (((IData)(vlSelf->soc_top__DOT__u_dma_regs__DOT__err_i) 
                                                         << 2U) 
                                                        | (IData)(vlSelf->soc_top__DOT__dma_busy))
                                                        : 0U))))
                                                    : 0U)));
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[0U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [0U][0U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[0U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [0U][1U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[0U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [0U][2U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[0U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [0U][3U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[1U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [1U][0U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[1U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [1U][1U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[1U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [1U][2U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[1U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [1U][3U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[2U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [2U][0U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[2U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [2U][1U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[2U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [2U][2U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[2U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [2U][3U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[3U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [3U][0U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[3U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [3U][1U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[3U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [3U][2U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[3U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__weight_in
        [3U][3U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__row_in[0U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__row_in[1U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__row_in[2U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__row_in[3U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_d 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_d));
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[0U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in
        [0U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[0U][1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in
        [1U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[0U][2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in
        [2U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[0U][3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in
        [3U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 0U;
    if ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
         >> 0x1fU)) {
        if ((0x40000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
            if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x1bU)))) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1aU)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x19U)))) {
                                if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x17U)))) {
                                        if ((0x400000U 
                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x15U)))) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                                            }
                                        } else if (
                                                   (0x200000U 
                                                    & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                                = (
                                                   (0x100000U 
                                                    & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                    ? 0U
                                                    : 0x16U);
                                        } else if (
                                                   (0x100000U 
                                                    & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                        } else if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                            }
                        } else if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                             >> 0x15U)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x14U)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                            }
                        }
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
            }
        } else if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
            if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x1aU)))) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x19U)))) {
                            if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            } else if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                 >> 0x14U)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter
                                               [(0x1fU 
                                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x14U))] 
                                               >> 0x20U));
                            }
                        }
                    }
                    if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                         >> 0x18U)))) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x17U)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x16U)))) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x15U)))) {
                                    if ((0x100000U 
                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x1aU)))) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x19U)))) {
                            if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U))]);
                            } else if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U))]);
                            } else if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U))]);
                            } else if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U))]);
                            } else if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                 >> 0x14U)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter
                                              [(0x1fU 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U))]);
                            }
                        }
                    }
                    if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                         >> 0x18U)))) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x17U)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x16U)))) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x15U)))) {
                                    if ((0x100000U 
                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
            }
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
        }
    } else if ((0x40000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
        if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
            if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x19U)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x18U)))) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x17U)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x16U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x15U)))) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                                = (
                                                   (0x100000U 
                                                    & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                    ? 0U
                                                    : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q));
                                        }
                                    }
                                }
                            }
                        }
                        if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                        } else if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                        } else if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                        } else if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                        } else if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                        }
                    } else if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x17U)))) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x16U)))) {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                        = ((0x200000U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                            ? ((0x100000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dscratch1_csr__DOT__rdata_q
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dscratch0_csr__DOT__rdata_q)
                                            : ((0x100000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_depc_csr__DOT__rdata_q
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q));
                                }
                            }
                            if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                            } else if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                            }
                        } else {
                            if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x16U)))) {
                                    if ((0x200000U 
                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x14U)))) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x14U)))) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                                    }
                                }
                            } else if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                 >> 0x16U)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                            }
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                        }
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
            }
        } else {
            if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x1aU)))) {
                        if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x18U)))) {
                                if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x16U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x15U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x14U)))) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
        }
    } else if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
        if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
            if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                              >> 0x1aU)))) {
                    if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                = ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                    ? ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                        ? ((0x200000U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                            ? ((0x100000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [0xfU]
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [0xeU])
                                            : ((0x100000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [0xdU]
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [0xcU]))
                                        : ((0x200000U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                            ? ((0x100000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [0xbU]
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [0xaU])
                                            : ((0x100000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [9U]
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [8U])))
                                    : ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                        ? ((0x200000U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                            ? ((0x100000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [7U]
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [6U])
                                            : ((0x100000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [5U]
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [4U]))
                                        : ((0x200000U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                            ? ((0x100000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [3U]
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [2U])
                                            : ((0x100000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [1U]
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata
                                               [0U]))));
                        } else if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                             >> 0x17U)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x16U)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                        ? ((0x100000U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                            ? ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                [0xfU] 
                                                << 0x18U) 
                                               | ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                   [0xeU] 
                                                   << 0x10U) 
                                                  | ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                      [0xdU] 
                                                      << 8U) 
                                                     | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                     [0xcU])))
                                            : ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                [0xbU] 
                                                << 0x18U) 
                                               | ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                   [0xaU] 
                                                   << 0x10U) 
                                                  | ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                      [9U] 
                                                      << 8U) 
                                                     | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                     [8U]))))
                                        : ((0x100000U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                            ? ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                [7U] 
                                                << 0x18U) 
                                               | ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                   [6U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                      [5U] 
                                                      << 8U) 
                                                     | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                     [4U])))
                                            : ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                [3U] 
                                                << 0x18U) 
                                               | ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                   [2U] 
                                                   << 0x10U) 
                                                  | ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                      [1U] 
                                                      << 8U) 
                                                     | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata
                                                     [0U])))));
                            }
                        }
                    }
                }
                if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                } else if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x18U)))) {
                        if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                        } else if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                        }
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                }
            } else if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                              >> 0x19U)))) {
                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x18U)))) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x17U)))) {
                            if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x15U)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x14U)))) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                            = (0xfffffff7U 
                                               & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int);
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                            = (0xffffff7fU 
                                               & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int);
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                            = (0xfffff7ffU 
                                               & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int);
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                            = (0x8000ffffU 
                                               & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int);
                                    }
                                }
                            } else {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                                    = ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                        ? ((0x100000U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtval_csr__DOT__rdata_q
                                            : (((IData)(
                                                        (0U 
                                                         != 
                                                         (0x60U 
                                                          & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mcause_csr__DOT__rdata_q)))) 
                                                << 0x1fU) 
                                               | ((((0x40U 
                                                     & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mcause_csr__DOT__rdata_q))
                                                     ? 0x3ffffffU
                                                     : 0U) 
                                                   << 5U) 
                                                  | (0x1fU 
                                                     & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mcause_csr__DOT__rdata_q)))))
                                        : ((0x100000U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mepc_csr__DOT__rdata_q
                                            : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mscratch_csr__DOT__rdata_q));
                            }
                        }
                    }
                }
                if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                } else if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                } else if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                } else if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((0x100000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    }
                }
            } else if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
                        [(0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                   >> 0x14U))];
                } else if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
                        [(0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                   >> 0x14U))];
                } else if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
                        [(0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                   >> 0x14U))];
                } else if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x100000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent
                            [(0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                       >> 0x14U))];
                    }
                } else if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0x14U)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q;
                }
                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                              >> 0x18U)))) {
                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x17U)))) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x16U)))) {
                            if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x14U)))) {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                                }
                            } else if ((0x100000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                            }
                        }
                    }
                }
            } else if ((0x1000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x16U)))) {
                        if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x14U)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                            }
                        }
                    }
                    if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x100000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                        }
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    }
                } else {
                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x16U)))) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x15U)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x14U)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                            }
                        }
                    }
                    if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    } else if ((0x100000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    }
                }
            } else if ((0x800000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                              >> 0x16U)))) {
                    if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x14U)))) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                        }
                    }
                }
                if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                } else if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x100000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                }
            } else if ((0x400000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x14U)))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                    }
                    if ((0x100000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                    }
                } else if ((0x100000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtvec_csr__DOT__rdata_q;
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                        = ((0xfffffff7U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int) 
                           | (8U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mie_csr__DOT__rdata_q 
                                    >> 0xeU)));
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                        = ((0xffffff7fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int) 
                           | (0x80U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mie_csr__DOT__rdata_q 
                                       >> 9U)));
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                        = ((0xfffff7ffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int) 
                           | (0x800U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mie_csr__DOT__rdata_q 
                                        >> 4U)));
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                        = ((0x8000ffffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int) 
                           | (0x7fff0000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mie_csr__DOT__rdata_q 
                                             << 0x10U)));
                }
            } else {
                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                              >> 0x15U)))) {
                    if ((0x100000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0x40101104U;
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = 0U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                            = ((0xfffffff7U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int) 
                               | (8U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                        >> 2U)));
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                            = ((0xffffff7fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int) 
                               | (0x80U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                           << 3U)));
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                            = ((0xffffe7ffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int) 
                               | (0x1800U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                             << 9U)));
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                            = ((0xfffdffffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int) 
                               | (0x20000U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                              << 0x10U)));
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int 
                            = ((0xffdfffffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int) 
                               | (0x200000U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                               << 0x15U)));
                    }
                }
                if ((0x200000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
                }
            }
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
        }
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
    }
    if (soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT____VdfgExtracted_h75d42971__0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = 1U;
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save = 0U;
    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q) 
                                  | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                                     >> 2U))))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ctrl_busy = 0U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ctrl_busy = 0U;
                }
            }
        }
        if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_run = 1U;
                }
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec 
        = (((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err)) 
            & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_run));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_q[0U] 
        = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                  [0U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_q[1U] 
        = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                  [1U]);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
    vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b = 
        vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg
        [(0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                   >> 0x14U))];
    vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a = 
        vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg
        [(0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                   >> 0xfU))];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__icache_inval = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_wdata_sel = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_b_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_access = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_illegal = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_sign_ext = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ebrk_insn = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mret_insn_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__dret_insn_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ecall_insn_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__wfi_insn_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode 
        = (0x7fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id);
    if ((0x40U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
        if ((0x20U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
            if ((0x10U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                } else if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                    if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                        if ((0U == (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0xcU)))) {
                            if ((0U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                        >> 0x14U))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ecall_insn_dec = 1U;
                            } else if ((1U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                               >> 0x14U))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ebrk_insn = 1U;
                            } else if ((0x302U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mret_insn_dec = 1U;
                            } else if ((0x7b2U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__dret_insn_dec = 1U;
                            } else if ((0x105U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__wfi_insn_dec = 1U;
                            } else {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                            }
                            if ((IData)((0U != (0xf8f80U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                            }
                        } else {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_access = 1U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_wdata_sel = 1U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 1U;
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0xeU)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec = 1U;
                            }
                            if ((1U == (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0xcU)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op = 1U;
                            } else if ((2U == (3U & 
                                               (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                >> 0xcU)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op = 2U;
                            } else if ((3U == (3U & 
                                               (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                >> 0xcU)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op = 3U;
                            } else {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_illegal = 1U;
                            }
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn 
                                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_illegal;
                        }
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                    if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec = 1U;
                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 0U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_dec = 1U;
                            } else {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 1U;
                            }
                        } else {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                        }
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                    if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec = 1U;
                        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 0U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_dec = 1U;
                        } else {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 1U;
                        }
                        if ((0U != (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0xcU)))) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                        }
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec = 1U;
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec = 1U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn 
                        = ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0xeU))) && 
                           (1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0xdU)));
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec = 1U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_b_dec = 1U;
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
        }
    } else if ((0x20U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
        if ((0x10U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
            if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
            } else if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                    if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 1U;
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec = 1U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_b_dec = 1U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 1U;
                    if ((5U == ((4U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                       >> 0x18U)) | 
                                (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                       >> 0xcU))))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                >> 0x1fU)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((0x40000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn 
                            = ((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1dU)) || 
                               ((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                       >> 0x1cU)) || 
                                ((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                        >> 0x1bU)) 
                                 || ((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                            >> 0x1aU)) 
                                     || ((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                >> 0x19U)) 
                                         || ((0x4000U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                              ? ((1U 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0xdU)) 
                                                 || (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0xcU))))
                                              : ((1U 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0xdU)) 
                                                 || (1U 
                                                     & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                        >> 0xcU)))))))));
                    } else if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    } else if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator = 3U;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode = 0U;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 0U;
                                } else {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator = 3U;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode = 3U;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 0U;
                                }
                            } else if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator = 2U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode = 0U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 0U;
                            } else {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator = 2U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode = 3U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 0U;
                            }
                        } else if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator = 1U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode = 0U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 0U;
                            } else {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator = 1U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode = 1U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 0U;
                            }
                        } else if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator = 1U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode = 3U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 0U;
                        } else {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator = 0U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode = 0U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 0U;
                        }
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 0U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
        } else if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
        } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_b_dec = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we = 1U;
                if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
                if ((0U == (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0xcU)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type = 2U;
                } else if ((1U == (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                         >> 0xcU)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type = 1U;
                } else if ((2U == (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                         >> 0xcU)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type = 0U;
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
        }
    } else if ((0x10U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
        if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
        } else if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
            if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 1U;
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn 
                    = ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                        ? ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0xdU))) && 
                           ((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                   >> 0xcU)) && ((1U 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x1aU)) 
                                                 || ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                      >> 0x1fU) 
                                                     || ((0x40000000U 
                                                          & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                          ? 
                                                         ((1U 
                                                           & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                              >> 0x1dU)) 
                                                          || ((1U 
                                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                  >> 0x1cU)) 
                                                              || ((1U 
                                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                      >> 0x1bU)) 
                                                                  || (0U 
                                                                      != 
                                                                      (3U 
                                                                       & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                          >> 0x19U))))))
                                                          : 
                                                         ((1U 
                                                           & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                              >> 0x1dU)) 
                                                          || ((1U 
                                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                  >> 0x1cU)) 
                                                              || ((1U 
                                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                      >> 0x1bU)) 
                                                                  || (0U 
                                                                      != 
                                                                      (3U 
                                                                       & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                          >> 0x19U)))))))))))
                        : ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0xdU))) && 
                           ((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                   >> 0xcU)) && ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x1fU) 
                                                 || ((1U 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x1eU)) 
                                                     || ((1U 
                                                          & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x1dU)) 
                                                         || ((1U 
                                                              & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                 >> 0x1cU)) 
                                                             || ((1U 
                                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                     >> 0x1bU)) 
                                                                 || (0U 
                                                                     != 
                                                                     (3U 
                                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                         >> 0x19U)))))))))));
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
        }
    } else if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
        if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
            if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
                    if ((0U == (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0xcU)))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 0U;
                    } else if ((1U == (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                             >> 0xcU)))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec = 1U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 0U;
                        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_dec = 1U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__icache_inval = 1U;
                        }
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
        }
    } else if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
    } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec = 1U;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec = 1U;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type = 0U;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_sign_ext 
                = (1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                            >> 0xeU)));
            if ((0U == (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                              >> 0xcU)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type = 2U;
            } else if ((1U == (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0xcU)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type = 1U;
            } else if ((2U == (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0xcU)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type = 0U;
                if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
            }
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
        }
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_c_insn_id) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = 1U;
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = 0U;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec = 0U;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we = 0U;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec = 0U;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_dec = 0U;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec = 0U;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_access = 0U;
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0x2cU;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 3U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_a_mux_sel = 1U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu 
        = (0x7fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__mult_sel_ex = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex = 0U;
    if ((0x40U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
        if ((0x20U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
            if ((0x10U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                            if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                                if ((0U == (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0xcU)))) {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 0U;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                                } else {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_a_mux_sel = 0U;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec 
                                        = ((0x4000U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                            ? 3U : 0U);
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                    if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 2U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 4U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                            } else {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 2U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 5U;
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                    if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 0U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 0U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                        } else {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 2U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 5U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                    if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator 
                            = ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                ? ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                    ? 0x1cU : 0x1aU)
                                : ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                    ? 0x1bU : 0x19U));
                    } else if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                         >> 0xdU)))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator 
                            = ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                ? 0x1eU : 0x1dU);
                    }
                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 0U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 0U;
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 2U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 2U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                    }
                }
            }
        }
    } else if ((0x20U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
        if ((0x10U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                    if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 3U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_a_mux_sel = 1U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 3U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                        }
                    }
                } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                    if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 0U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 0U;
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1aU)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x1fU)))) {
                                if ((0x40000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x1dU)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x1cU)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x1bU)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x1aU)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x19U)))) {
                                                        if (
                                                            (0x4000U 
                                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                     >> 0xdU)))) {
                                                                if (
                                                                    (0x1000U 
                                                                     & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 8U;
                                                                }
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                        >> 0xdU)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                                     >> 0xcU)))) {
                                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 1U;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                } else if ((1U & (~ 
                                                  (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x1dU)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x1cU)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x1bU)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x1aU)))) {
                                                if (
                                                    (0x2000000U 
                                                     & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                    if (
                                                        (0x4000U 
                                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                        if (
                                                            (0x2000U 
                                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                            if (
                                                                (0x1000U 
                                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex = 1U;
                                                            } else {
                                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex = 1U;
                                                            }
                                                        } else if (
                                                                   (0x1000U 
                                                                    & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex = 1U;
                                                        } else {
                                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex = 1U;
                                                        }
                                                    } else if (
                                                               (0x2000U 
                                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                        if (
                                                            (0x1000U 
                                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__mult_sel_ex = 1U;
                                                        } else {
                                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__mult_sel_ex = 1U;
                                                        }
                                                    } else if (
                                                               (0x1000U 
                                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__mult_sel_ex = 1U;
                                                    } else {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__mult_sel_ex = 1U;
                                                    }
                                                } else {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator 
                                                        = 
                                                        ((0x4000U 
                                                          & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                          ? 
                                                         ((0x2000U 
                                                           & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                           ? 
                                                          ((0x1000U 
                                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                            ? 4U
                                                            : 3U)
                                                           : 
                                                          ((0x1000U 
                                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                            ? 9U
                                                            : 2U))
                                                          : 
                                                         ((0x2000U 
                                                           & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                           ? 
                                                          ((0x1000U 
                                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                            ? 0x2cU
                                                            : 0x2bU)
                                                           : 
                                                          ((0x1000U 
                                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                                            ? 0xaU
                                                            : 0U)));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                    if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 0U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 0U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0xeU)))) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 1U;
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                        }
                    }
                }
            }
        }
    } else if ((0x10U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                    if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 2U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 3U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                    }
                }
            } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 0U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 0U;
                    if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator 
                                = ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                    ? 4U : 3U);
                        } else if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((0U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                        >> 0x1bU))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 9U;
                            } else if ((8U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                               >> 0x1bU))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 8U;
                            }
                        } else {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 2U;
                        }
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator 
                            = ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                ? ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                    ? 0x2cU : 0x2bU)
                                : ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                                    ? 0xaU : 0U));
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
        if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
            if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                    if ((0U == (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0xcU)))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 0U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                    } else if ((1U == (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                             >> 0xcU)))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 2U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 5U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                    }
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu) 
                         >> 2U)))) {
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = 0U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = 0U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = 0U;
            }
        }
    }
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[0U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in
        [0U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[1U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in
        [1U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[2U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in
        [2U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[3U][0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in
        [3U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[0U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
        [4U][0U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[1U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
        [4U][1U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[2U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
        [4U][2U];
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[3U] 
        = vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
        [4U][3U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__g_no_alu_rvb__DOT__unused_imd_val_q[0U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_q
        [0U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__g_no_alu_rvb__DOT__unused_imd_val_q[1U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_q
        [1U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
        = (1ULL | ((QData)((IData)((~ vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b))) 
                   << 1U));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a 
        = ((vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a 
            >> 0x1fU) & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a 
        = ((1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q) 
                  >> 1U)) && (1U & ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q))
                                     ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode) 
                                        & (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a 
                                           >> 0x1fU))
                                     : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode) 
                                        & (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a 
                                           >> 0x1fU)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b 
        = ((vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
            >> 0x1fU) & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode) 
                         >> 1U));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__wfi_insn 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__wfi_insn_dec) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op;
    if ((IData)(((0U == (0xf8000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                 & ((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op)) 
                    | (3U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op)))))) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op = 0U;
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__dret_insn_dec) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mret_insn_dec) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
        [0U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid = 0U;
    if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q))) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b 
            = ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q)) 
               && (IData)((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode) 
                            >> 1U) & (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
                                      >> 0x1fU))));
        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b 
                = (0xffffU & (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
                              >> 0x10U));
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_a 
                = (0xffffU & (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a 
                              >> 0x10U));
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_d = 0U;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = 0U;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum 
                = ((0x3fffc0000ULL & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum) 
                   | (IData)((IData)((0x3ffffU & (IData)(
                                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                          [0U] 
                                                          >> 0x10U))))));
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum 
                = ((0x3ffffULL & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum) 
                   | ((QData)((IData)((0xffffU & (- (IData)(
                                                            ((0U 
                                                              != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode)) 
                                                             & (IData)(
                                                                       (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                                        [0U] 
                                                                        >> 0x21U)))))))) 
                      << 0x12U));
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid = 1U;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
                = (0x3ffffffffULL & ((0x7ffffffffULL 
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
                                     + (0x7ffffffffULL 
                                        & VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum))));
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b 
                = (0xffffU & vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b);
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_a 
                = (0xffffU & (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a 
                              >> 0x10U));
            if ((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_d = 0U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = 0U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum 
                    = (QData)((IData)((0xffffU & (IData)(
                                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                          [0U] 
                                                          >> 0x10U)))));
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
                    = (0x3ffffffffULL & (((QData)((IData)(
                                                          (0xffffU 
                                                           & ((IData)(
                                                                      (0x7ffffffffULL 
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
                                                                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b))))))) 
                                                              + (IData)(
                                                                        (0x7ffffffffULL 
                                                                         & VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum))))))) 
                                          << 0x10U) 
                                         | (QData)((IData)(
                                                           (0xffffU 
                                                            & (IData)(
                                                                      vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                                      [0U]))))));
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_d = 3U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum 
                    = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                    [0U];
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
                    = (0x3ffffffffULL & ((0x7ffffffffULL 
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
                                         + (0x7ffffffffULL 
                                            & VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum))));
            }
        }
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_a 
            = (0xffffU & vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a);
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b 
            = ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q)) 
               && (IData)((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode) 
                            >> 1U) & (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
                                      >> 0x1fU))));
        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b 
                = (0xffffU & (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
                              >> 0x10U));
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_d = 2U;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum 
                = (QData)((IData)((0xffffU & (IData)(
                                                     (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                      [0U] 
                                                      >> 0x10U)))));
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
                = (0x3ffffffffULL & ((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator))
                                      ? (((QData)((IData)(
                                                          (0xffffU 
                                                           & ((IData)(
                                                                      (0x7ffffffffULL 
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
                                                                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b))))))) 
                                                              + (IData)(
                                                                        (0x7ffffffffULL 
                                                                         & VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum))))))) 
                                          << 0x10U) 
                                         | (QData)((IData)(
                                                           (0xffffU 
                                                            & (IData)(
                                                                      vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                                      [0U])))))
                                      : ((0x7ffffffffULL 
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
                                         + (0x7ffffffffULL 
                                            & VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum)))));
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b 
                = (0xffffU & vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b);
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_d = 1U;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum = 0ULL;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d 
                = (0x3ffffffffULL & ((0x7ffffffffULL 
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
                                     + (0x7ffffffffULL 
                                        & VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum))));
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
           & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ebrk_insn) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ecall_insn_dec) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q));
    if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req = 1U;
            }
        }
    } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req 
            = ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) 
               || (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q));
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel = 6U;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel = 1U;
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec;
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__mult_sel_ex));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex) 
           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__mult_sel_ex));
    __Vtableidx5 = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left 
        = Vsoc_top__ConstPool__TABLE_hd5b48b0a_0[__Vtableidx5];
    __Vtableidx3 = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed 
        = Vsoc_top__ConstPool__TABLE_hb804351c_0[__Vtableidx3];
    __Vtableidx2 = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1 
        = Vsoc_top__ConstPool__TABLE_h2fe71d6b_0[__Vtableidx2];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2 
        = Vsoc_top__ConstPool__TABLE_h2fe71d6b_0[__Vtableidx2];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3 
        = Vsoc_top__ConstPool__TABLE_h2fe71d6b_0[__Vtableidx2];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate 
        = Vsoc_top__ConstPool__TABLE_ha686e182_0[__Vtableidx2];
    vlSelf->soc_top__DOT__u_mac__DOT__col_out[3U] = 
        vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
        [3U];
    vlSelf->soc_top__DOT__u_mac__DOT__col_out[2U] = 
        vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
        [2U];
    vlSelf->soc_top__DOT__u_mac__DOT__col_out[1U] = 
        vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
        [1U];
    vlSelf->soc_top__DOT__u_mac__DOT__col_out[0U] = 
        vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
        [0U];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr 
        = ((1U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op)) 
           | ((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op)) 
              | (3U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_store = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_load = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out = 0U;
    __Vtableidx1 = (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q) 
                     << 5U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q) 
                                << 4U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn) 
                                           << 3U) | 
                                          (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn) 
                                            << 2U) 
                                           | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_q) 
                                               << 1U) 
                                              | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err))))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err_prio 
        = Vsoc_top__ConstPool__TABLE_h6451e8c0_0[__Vtableidx1];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_prio 
        = Vsoc_top__ConstPool__TABLE_h2aabc56c_0[__Vtableidx1];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio 
        = Vsoc_top__ConstPool__TABLE_hf64aebe0_0[__Vtableidx1];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio 
        = Vsoc_top__ConstPool__TABLE_h323b7bc3_0[__Vtableidx1];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_prio 
        = Vsoc_top__ConstPool__TABLE_h6d182578_0[__Vtableidx1];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_prio 
        = Vsoc_top__ConstPool__TABLE_hbf9cbdd6_0[__Vtableidx1];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b 
        = ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
            ? ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
                ? 4U : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
                         ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_is_compressed_id)
                             ? 2U : 4U) : (((- (IData)(
                                                       (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                        >> 0x1fU))) 
                                            << 0x14U) 
                                           | ((0xff000U 
                                               & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id) 
                                              | ((0x800U 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 9U)) 
                                                 | (0x7feU 
                                                    & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                       >> 0x14U)))))))
            : ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
                ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
                    ? (0xfffff000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)
                    : (((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                    >> 0x1fU))) << 0xdU) 
                       | ((0x1000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x13U)) | 
                          ((0x800U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      << 4U)) | ((0x7e0U 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                       >> 7U)))))))
                : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel))
                    ? (((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                      >> 7U))))
                    : (((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                          >> 0x14U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
        = ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel))
            ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel))
                ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_a_mux_sel)
                    ? 0U : (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0xfU))) : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_id)
            : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel))
                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q
                : vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold)) 
           & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec)));
    if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold = 0U;
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold)) 
           & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec) 
           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec));
    if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid = 1U;
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_valid 
        = ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel))) 
           || ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid) 
               | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_csr_insn_id 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_access) 
           & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr) 
              | (((3U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                          >> 0x1eU)) & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr)) 
                 | (((3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                            >> 0x1cU)) > (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q)) 
                    | ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)) 
                       & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dbg_csr))))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex 
        = (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec) 
            | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req))
            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b
            : vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev 
        = ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
            << 0x1fU) | ((0x40000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                         << 0x1dU)) 
                         | ((0x20000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                            << 0x1bU)) 
                            | ((0x10000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                               << 0x19U)) 
                               | ((0x8000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                 << 0x17U)) 
                                  | ((0x4000000U & 
                                      (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                       << 0x15U)) | 
                                     ((0x2000000U & 
                                       (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                        << 0x13U)) 
                                      | ((0x1000000U 
                                          & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                             << 0x11U)) 
                                         | ((0x800000U 
                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                << 0xfU)) 
                                            | ((0x400000U 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                   << 0xdU)) 
                                               | ((0x200000U 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                      << 0xbU)) 
                                                  | ((0x100000U 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                         << 9U)) 
                                                     | ((0x80000U 
                                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                            << 7U)) 
                                                        | ((0x40000U 
                                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                               << 5U)) 
                                                           | ((0x20000U 
                                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                  << 3U)) 
                                                              | ((0x10000U 
                                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                     << 1U)) 
                                                                 | ((0x8000U 
                                                                     & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                        >> 1U)) 
                                                                    | ((0x4000U 
                                                                        & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                           >> 3U)) 
                                                                       | ((0x2000U 
                                                                           & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                              >> 5U)) 
                                                                          | ((0x1000U 
                                                                              & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 7U)) 
                                                                             | ((0x800U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x1dU)) 
                                                                                | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                                                >> 0x1fU))))))))))))))))))))))))))))))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
        = ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op))
            ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op))
                ? ((~ vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a) 
                   & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int)
                : (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                   | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int))
            : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_branch = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_we_raw 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_insn_id 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q) 
           & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn) 
              | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_csr_insn_id) 
                 | (((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)) 
                     & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__dret_insn_dec)) 
                    | ((3U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q)) 
                       & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mret_insn_dec) 
                          | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__wfi_insn_dec))))))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstack_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q;
    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs)))) {
                    if ((1U & (~ (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                                   | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                                  | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))))) {
                        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn) {
                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_d = 0U;
                            }
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id = 1U;
                        }
                        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn)))) {
                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id = 1U;
                            }
                        }
                    }
                    if ((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                          | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                         | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))) {
                        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err_prio) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval 
                                = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err_plus2)
                                    ? ((IData)(2U) 
                                       + vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_id)
                                    : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_id);
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause = 1U;
                        } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_prio) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval 
                                = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_is_compressed_id)
                                    ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_c_id)
                                    : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id);
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause = 2U;
                        } else {
                            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio)))) {
                                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio)))) {
                                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_prio) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval 
                                            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
                                    } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_prio) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval 
                                            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q;
                                    }
                                }
                            }
                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause 
                                    = ((3U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q))
                                        ? 0xbU : 8U);
                            } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio) {
                                if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q) 
                                              | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug))))) {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause = 3U;
                                }
                            } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_prio) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause = 7U;
                            } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_prio) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause = 5U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__irq_vec 
        = (0x1fU & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause));
    if ((0x40U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause))) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__irq_vec = 0x1fU;
    }
    if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                          >> 1U)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_mode_entering = 1U;
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_if = 1U;
                }
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_pc_mux_id = 2U;
            }
        }
    } else if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_pc_mux_id = 1U;
            } else if ((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                         | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_pc_mux_id 
                    = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)
                        ? 3U : 0U);
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__exc_pc 
        = ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_pc_mux_id))
            ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_pc_mux_id))
                ? 0x1a110808U : 0x1a110800U) : ((1U 
                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_pc_mux_id))
                                                 ? 
                                                ((0xffffff00U 
                                                  & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtvec_csr__DOT__rdata_q) 
                                                 | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__irq_vec) 
                                                    << 2U))
                                                 : 
                                                (0xffffff00U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtvec_csr__DOT__rdata_q)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result 
        = (((3U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)) 
            | (6U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)))
            ? (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
               | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)
            : (((4U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)) 
                | (7U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)))
                ? (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                   & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)
                : (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                   ^ vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)));
    if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                    = (1ULL | ((QData)((IData)((~ (IData)(
                                                          vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                          [0U])))) 
                               << 1U));
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a 
                    = (1ULL | ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                               [0U])) 
                               << 1U));
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                    = (1ULL | ((QData)((IData)((~ (IData)(
                                                          vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                          [1U])))) 
                               << 1U));
            }
        }
    } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a 
                = (1ULL | ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                           [0U])) << 1U));
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                = (1ULL | ((QData)((IData)((~ (IData)(
                                                      vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                      [1U])))) 
                           << 1U));
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
                = (1ULL | ((QData)((IData)((~ vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b))) 
                           << 1U));
        }
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = 1ULL;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b 
            = ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                ? (1ULL | ((QData)((IData)((~ vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a))) 
                           << 1U)) : (1ULL | ((QData)((IData)(
                                                              (~ vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b))) 
                                              << 1U)));
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
        = (0x3ffffffffULL & (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
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
                                                 << 1U)))))) 
                             + (0x1ffffffffULL & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                                   ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b
                                                   : 
                                                  ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate)
                                                    ? 
                                                   (~ 
                                                    ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                                     << 1U))
                                                    : 
                                                   ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                                    << 1U))))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left)
            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev
            : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed 
        = (0x1ffffffffULL & VL_SHIFTRS_QQI(33,33,5, 
                                           (((QData)((IData)(
                                                             ((8U 
                                                               == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)) 
                                                              & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand 
                                                                 >> 0x1fU)))) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand))), 
                                           (0x1fU & 
                                            ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id)
                                              ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex
                                              : (- vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
        = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__unused_shift_result_ext 
        = (1U & (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext 
                         >> 0x20U)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffffff8U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((4U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                     >> 0x1bU)) | ((2U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                          >> 0x1dU)) 
                                   | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                      >> 0x1fU))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffffffc7U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                        >> 0x15U)) | ((0x10U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                >> 0x17U)) 
                                      | (8U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               >> 0x19U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffffe3fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x100U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                         >> 0xfU)) | ((0x80U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                >> 0x11U)) 
                                      | (0x40U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                  >> 0x13U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffff1ffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x800U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                         >> 9U)) | ((0x400U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               >> 0xbU)) 
                                    | (0x200U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 >> 0xdU)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffff8fffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x4000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                          >> 3U)) | ((0x2000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 >> 5U)) 
                                     | (0x1000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                   >> 7U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xfffc7fffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                           << 3U)) | ((0x10000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                   << 1U)) 
                                      | (0x8000U & 
                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                          >> 1U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xffe3ffffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x100000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                            << 9U)) | ((0x80000U & 
                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                         << 7U)) | 
                                       (0x40000U & 
                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                         << 5U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xff1fffffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x800000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                            << 0xfU)) | ((0x400000U 
                                          & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                             << 0xdU)) 
                                         | (0x200000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               << 0xbU)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xf8ffffffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x4000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                             << 0x15U)) | ((0x2000000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                               << 0x13U)) 
                                           | (0x1000000U 
                                              & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                 << 0x11U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0xc7ffffffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((0x20000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                              << 0x1bU)) | ((0x10000000U 
                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                << 0x19U)) 
                                            | (0x8000000U 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                                  << 0x17U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev 
        = ((0x3fffffffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev) 
           | ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
               << 0x1fU) | (0x40000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
                                           << 0x1dU))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left)
            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev
            : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__exception_pc 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_id;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_d 
        = (0xfffffffeU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_d 
        = (0xfffffffeU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int);
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec)))) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec)))) {
                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_branch = 1U;
                    }
                    if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec)))) {
                        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw 
                                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_dec;
                        }
                    }
                }
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_q)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw));
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) {
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q) {
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q) {
                if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_we_raw 
                        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we) 
                           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_valid));
                }
            }
        } else if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec)))) {
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_valid)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_we_raw = 0U;
                }
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_we_raw) 
           & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_csr_insn_id)) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_d 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_insn_id) 
           & (6U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_wdata 
        = ((1U & (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                          >> 2U))) ? ((1U & (IData)(
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                     >> 1U)))
                                       ? ((vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
                                           << 0x18U) 
                                          | (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
                                             >> 8U))
                                       : ((vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
                                           << 0x10U) 
                                          | (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
                                             >> 0x10U)))
            : ((1U & (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                              >> 1U))) ? ((vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
                                           << 8U) | 
                                          (vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b 
                                           >> 0x18U))
                : vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b));
    __Vtableidx6 = (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q) 
                     << 4U) | ((0xcU & ((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                 >> 1U)) 
                                        << 2U)) | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be 
        = Vsoc_top__ConstPool__TABLE_hee875898_0[__Vtableidx6];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d 
        = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                  [1U]);
    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q)))) {
                if ((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d 
                        = (0U == (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                          >> 1U)));
                }
            }
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d 
                    = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a)
                        ? (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                   >> 1U)) : vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a);
            }
        }
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d 
                    = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b)
                        ? (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                   >> 1U)) : vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b);
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access 
        = (((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type)) 
            & (0U != (3U & (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                    >> 1U))))) | (IData)(
                                                         ((1U 
                                                           == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type)) 
                                                          & (6ULL 
                                                             == 
                                                             (6ULL 
                                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext)))));
    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_store 
                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_load 
                        = (1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we)));
                }
            }
        }
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out = 1U;
        } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out = 1U;
        } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out = 1U;
        }
    }
    vlSelf->soc_top__DOT____Vcellinp__u_bridge__obi_req 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out) 
           & (0x80000000ULL == (0x1ffe00000ULL & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal 
        = (1U & ((1U & ((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                 [0U] >> 0x1fU)) ^ (IData)(
                                                           (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                            [1U] 
                                                            >> 0x1fU))))
                  ? (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                             [0U] >> 0x1fU)) : (~ (IData)(
                                                          (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                           >> 0x20U)))));
    vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req 
        = ((0x400U != (0xfffU & (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                         >> 0x15U)))) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out));
    __Vtableidx4 = (((0U != (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                     >> 1U))) << 9U) 
                    | ((0x100U & ((((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                     ^ vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex) 
                                    >> 0x1fU) ? ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                                  >> 0x1fU) 
                                                 ^ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed))
                                    : (~ (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                  >> 0x20U)))) 
                                  << 8U)) | (((0U == (IData)(
                                                             (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                              >> 1U))) 
                                              << 7U) 
                                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result 
        = Vsoc_top__ConstPool__TABLE_h9d63e220_0[__Vtableidx4];
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_tbranch = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_jump = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_d 
        = (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn) 
            | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn) 
               | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_d) 
                  | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err)))) 
           & (6U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_imd_val_d[1U] 
        = (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d));
    vlSelf->soc_top__DOT__cpu_gnt = ((0x400U != (0xfffU 
                                                 & (IData)(
                                                           (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                            >> 0x15U)))) 
                                     | ((0U == (IData)(vlSelf->soc_top__DOT__u_bridge__DOT__state)) 
                                        & (IData)(vlSelf->soc_top__DOT____Vcellinp__u_bridge__obi_req)));
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder 
            = (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                       >> 1U));
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient 
            = ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q)) 
               | (QData)((IData)(((IData)(1U) << (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q)))));
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder 
            = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                      [0U]);
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient 
            = (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q));
    }
    vlSelf->soc_top__DOT__dma_m_gnt = ((IData)(vlSelf->soc_top__DOT__dma_m_req) 
                                       & ((~ (IData)(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req)) 
                                          & (~ (IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c))));
    if (vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req) {
        vlSelf->soc_top__DOT__u_mem__DOT__arb_be = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be;
        vlSelf->soc_top__DOT__u_mem__DOT__arb_wdata 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_wdata;
        vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
            = ((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                        >> 3U)) << 2U);
    } else if (vlSelf->soc_top__DOT__u_mac__DOT__m_req_c) {
        vlSelf->soc_top__DOT__u_mem__DOT__arb_be = 0xfU;
        vlSelf->soc_top__DOT__u_mem__DOT__arb_wdata 
            = vlSelf->soc_top__DOT__u_mac__DOT__m_wdata_c;
        vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
            = vlSelf->soc_top__DOT__u_mac__DOT__m_addr_c;
    } else if (vlSelf->soc_top__DOT__dma_m_req) {
        vlSelf->soc_top__DOT__u_mem__DOT__arb_be = 0xfU;
        vlSelf->soc_top__DOT__u_mem__DOT__arb_wdata 
            = vlSelf->soc_top__DOT__dma_m_wdata;
        vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
            = vlSelf->soc_top__DOT__dma_m_addr;
    } else {
        vlSelf->soc_top__DOT__u_mem__DOT__arb_be = 0U;
        vlSelf->soc_top__DOT__u_mem__DOT__arb_wdata = 0U;
        vlSelf->soc_top__DOT__u_mem__DOT__arb_addr = 0U;
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set_raw_d = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result = 0U;
    if ((0x40U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator) 
                      >> 5U)))) {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result = 0U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result 
            = ((0x20U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                ? ((0x10U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                    ? 0U : ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                             ? ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                 ? ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                     ? 0U : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                              ? 0U : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)))
                                 : ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                     ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                         ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)
                                         : 0U) : 0U))
                             : 0U)) : ((0x10U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                        ? ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                            ? ((4U 
                                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                     ? 0U
                                                     : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result))
                                                    : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                    ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                     ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result)
                                                     : (IData)(
                                                               (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                                >> 1U)))))
                                            : ((4U 
                                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                    ? (IData)(
                                                              (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                               >> 1U))
                                                    : 0U)
                                                : 0U))
                                        : ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                            ? ((4U 
                                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                     ? 0U
                                                     : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result))
                                                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result)
                                            : ((4U 
                                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))
                                                    ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result
                                                    : (IData)(
                                                              (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                               >> 1U)))))));
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q;
    vlSelf->soc_top__DOT__cpu_rvalid = ((0x400U == 
                                         (0xfffU & (IData)(
                                                           (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                            >> 0x15U))))
                                         ? (IData)(vlSelf->soc_top__DOT__cpu_rvalid_apb)
                                         : (IData)(vlSelf->soc_top__DOT__cpu_rvalid_mem));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_rvalid_2 
        = ((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)) 
           & ((IData)(vlSelf->soc_top__DOT__cpu_rvalid) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_2_en_q)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu 
        = ((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)) 
           & ((IData)(vlSelf->soc_top__DOT__cpu_rvalid) 
              & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err)) 
                 & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid 
        = (((IData)(vlSelf->soc_top__DOT__cpu_rvalid) 
            | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q)) 
           & (0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)));
    if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_req_int = 0U;
        } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_req_int = 0U;
        }
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                    if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug) 
                         & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save = 1U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id = 1U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause = 1U;
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save = 1U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause = 1U;
                }
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_d = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 2U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set = 1U;
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                      >> 2U)))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_req_int 
                = ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                             >> 1U))) && (1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs)));
        }
        if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs)))) {
                    if ((1U & (~ (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                                   | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                                  | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))))) {
                        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn)))) {
                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_d = 0U;
                            }
                        }
                    }
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = 1U;
                    if ((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                          | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                         | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id = 0U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause = 1U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set = 1U;
                        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err_prio)))) {
                            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_prio)))) {
                                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio)))) {
                                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio) {
                                        if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q) 
                                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug))) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id = 0U;
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause = 0U;
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = 0U;
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set = 0U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set = 1U;
                    } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set = 1U;
                    }
                }
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 2U;
                } else if ((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                            | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 2U;
                } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 3U;
                } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 4U;
                }
            } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 1U;
                if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set) 
                     | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set = 1U;
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                          >> 1U)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = 0U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set = 1U;
            }
            if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = 1U;
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtvec_init 
        = ((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q) 
           & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set) 
              | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_q)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_req_int) 
           & ((~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                  >> 1U)) & ((~ (IData)((3U == (3U 
                                                & (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                                    >> 1U) 
                                                   | ((2U 
                                                       & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                            >> 1U)))))))) 
                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs;
    if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
                if (vlSelf->soc_top__DOT__cpu_rvalid) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update 
                        = (1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)));
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d = 0U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 1U;
                }
            }
        }
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
        } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
        } else if (vlSelf->soc_top__DOT__cpu_rvalid) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
        }
    } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
            if (((IData)(vlSelf->soc_top__DOT__cpu_rvalid) 
                 | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update 
                    = (1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)));
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d 
                    = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q;
            }
        }
        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            if (((IData)(vlSelf->soc_top__DOT__cpu_gnt) 
                 | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update 
                    = (1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q)));
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
            }
        } else if (((IData)(vlSelf->soc_top__DOT__cpu_rvalid) 
                    | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
            if (vlSelf->soc_top__DOT__cpu_gnt) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update 
                    = (1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q)));
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 0U;
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 0U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 3U;
            }
        } else if (vlSelf->soc_top__DOT__cpu_gnt) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 4U;
        }
    } else {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = 0U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d = 0U;
            }
        }
        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            if (((IData)(vlSelf->soc_top__DOT__cpu_gnt) 
                 | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = 2U;
            }
        } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req) {
            if (vlSelf->soc_top__DOT__cpu_gnt) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns 
                    = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access)
                        ? 2U : 0U);
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns 
                    = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access)
                        ? 1U : 3U);
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q;
    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
                if (((IData)(vlSelf->soc_top__DOT__cpu_gnt) 
                     | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 1U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d = 0U;
                }
            } else if (((IData)(vlSelf->soc_top__DOT__cpu_rvalid) 
                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d 
                    = (1U & (~ (IData)(vlSelf->soc_top__DOT__cpu_gnt)));
            } else if (vlSelf->soc_top__DOT__cpu_gnt) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d = 0U;
            }
        } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) {
            if (((IData)(vlSelf->soc_top__DOT__cpu_gnt) 
                 | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d = 1U;
            }
        } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req) {
            if (vlSelf->soc_top__DOT__cpu_gnt) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d 
                    = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access;
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q;
    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                  >> 2U)))) {
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d 
                    = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient);
            }
        } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d = 0U;
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d 
        = (0x1fU & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q) 
                    - (IData)(1U)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
        [0U];
    if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d 
            = ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                ? 0U : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                         ? 6U : 5U));
        if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q) 
                      >> 1U)))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))
                    ? ((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator))
                        ? (((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q)) 
                            & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a) 
                               ^ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b)))
                            ? (QData)((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                               >> 1U)))
                            : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                           [0U]) : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a)
                                     ? (QData)((IData)(
                                                       (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                        >> 1U)))
                                     : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                    [0U])) : ((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator))
                                               ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient
                                               : (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder))));
        }
    } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d 
                = ((1U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q))
                    ? 4U : 3U);
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = (((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder)) 
                    << 1U) | (QData)((IData)((1U & 
                                              (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q 
                                               >> (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d))))));
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d = 3U;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = (QData)((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q 
                                   >> 0x1fU)));
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = 0x1fU;
        }
    } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q))) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d = 2U;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = 0x1fU;
    } else {
        if ((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d 
                = (((~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                        >> 1U)) & (0U == (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                  >> 1U))))
                    ? 6U : 1U);
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d = 0x3ffffffffULL;
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d 
                = (((~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                        >> 1U)) & (0U == (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                  >> 1U))))
                    ? 6U : 1U);
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d 
                = (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a));
        }
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = 0x1fU;
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_we_ex 
            = (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal) 
                << 1U) | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal) 
                          | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal)));
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_d_ex[1U] 
            = (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d));
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__result_ex 
                = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                          [0U]);
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_d_ex[0U] 
                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d;
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__result_ex 
                = (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d);
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_d_ex[0U] 
                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d;
        }
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_we_ex = 0U;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_d_ex[1U] 
            = (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_d
                              [1U]));
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__result_ex 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_d_ex[0U] 
            = (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_d
                              [0U]));
    }
    vlSelf->soc_top__DOT__u_mem__DOT____Vcellinp__u_ram__sram_cen 
        = (1U & (~ ((0x100U == (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                >> 0x14U)) & ((IData)(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req) 
                                              || ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c) 
                                                  || (IData)(vlSelf->soc_top__DOT__dma_m_req))))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_bus_err_1_d 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_rvalid_2)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_bus_err_1_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_2_en_d 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_rvalid_2)) 
           & ((((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)) 
                | (4U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) 
               & (IData)(vlSelf->soc_top__DOT__cpu_rvalid)) 
              | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_2_en_q)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffffcU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0x80U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 1U) | (IData)(((0U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                 & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                    | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id))))));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffff3U & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0x180U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 3U) | ((IData)(((0x100U == (0xf80U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                  & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                     | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                         << 2U)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffffcfU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0x280U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 5U) | ((IData)(((0x200U == (0xf80U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                  & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                     | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                         << 4U)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffff3fU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0x380U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 7U) | ((IData)(((0x300U == (0xf80U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                  & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                     | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                         << 6U)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffffcffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0x480U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 9U) | ((IData)(((0x400U == (0xf80U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                  & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                     | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                         << 8U)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffff3ffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0x580U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0xbU) | ((IData)(((0x500U == (0xf80U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                    & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                       | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                           << 0xaU)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffffcfffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0x680U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0xdU) | ((IData)(((0x600U == (0xf80U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                    & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                       | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                           << 0xcU)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffff3fffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0x780U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0xfU) | ((IData)(((0x700U == (0xf80U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                    & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                       | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                           << 0xeU)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfffcffffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0x880U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0x11U) | ((IData)(((0x800U == (0xf80U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                            << 0x10U)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfff3ffffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0x980U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0x13U) | ((IData)(((0x900U == (0xf80U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                            << 0x12U)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xffcfffffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0xa80U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0x15U) | ((IData)(((0xa00U == (0xf80U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                            << 0x14U)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xff3fffffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0xb80U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0x17U) | ((IData)(((0xb00U == (0xf80U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                            << 0x16U)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xfcffffffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0xc80U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0x19U) | ((IData)(((0xc00U == (0xf80U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                            << 0x18U)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xf3ffffffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0xd80U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0x1bU) | ((IData)(((0xd00U == (0xf80U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                            << 0x1aU)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0xcfffffffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0xe80U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0x1dU) | ((IData)(((0xe00U == (0xf80U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                            << 0x1cU)));
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec 
        = ((0x3fffffffU & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec) 
           | (((IData)(((0xf80U == (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
               << 0x1fU) | ((IData)(((0xf00U == (0xf80U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) 
                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id)))) 
                            << 0x1eU)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_load_err 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err) 
           & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q)) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_store_err 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err) 
           & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multicycle_done 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec)
            ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)
            : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_valid));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)
            ? (0xfffffffeU & ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                               ? ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                   ? 0x80U : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                               ? 0x80U
                                               : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_depc_csr__DOT__rdata_q))
                               : ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                   ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                       ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mepc_csr__DOT__rdata_q
                                       : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__exc_pc)
                                   : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                       ? (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                  >> 1U))
                                       : 0x80U)))) : 0U);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q)
            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_q
            : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)
                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr
                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfdd8329f__0 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req));
    vlSelf->soc_top__DOT__instr_req = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q) 
                                       | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_imd_val_d[0U] 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex)
            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d
            : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_wdata_id 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_wdata_sel)
            ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_wdata_sel)
                ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int
                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__result_ex)
            : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__result_ex);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_err 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_load_err) 
           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_store_err));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_jump = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_branch = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv = 0U;
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec)))) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec)))) {
                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set_raw_d 
                            = (1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result) 
                                     | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                        >> 1U)));
                    }
                }
            }
        }
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q) {
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q) {
                if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multicycle_done) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_d = 0U;
                }
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multicycle_done)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_jump 
                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_branch 
                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv 
                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_d = 0U;
            }
        } else {
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_d = 1U;
            } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_valid)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_d = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_d 
                    = (1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec)
                              ? (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                  >> 1U) | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result))
                              : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec)));
            }
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec)))) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec)))) {
                    if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec)))) {
                        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_jump = 1U;
                        }
                    }
                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_branch 
                            = (1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result) 
                                     | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                        >> 1U)));
                    }
                }
                if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec) {
                    if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_valid)))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv = 1U;
                    }
                }
            }
        }
    }
    vlSelf->soc_top__DOT__instr_addr = (0xfffffffcU 
                                        & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_d 
        = (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)
             ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr
             : (0xfffffffcU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q)) 
           + ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfdd8329f__0) 
              << 2U));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n 
        = ((2U & ((((IData)(vlSelf->soc_top__DOT__instr_req) 
                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                   << 1U) | (0xfffffffeU & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)))) 
           | (1U & ((IData)(vlSelf->soc_top__DOT__instr_req) 
                    | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q))));
    soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he6d6a5e6__0 
        = ((IData)(vlSelf->soc_top__DOT__instr_req) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q)) 
           & (IData)(vlSelf->soc_top__DOT__instr_req));
    vlSelf->soc_top__DOT__instr_rdata = vlSelf->soc_top__DOT__u_mem__DOT__u_rom__DOT__rom
        [(0x3ffU & ((IData)(vlSelf->soc_top__DOT__instr_req)
                     ? (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d 
                        >> 2U) : (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                  >> 2U)))];
    vlSelf->soc_top__DOT__cpu_rdata = ((0x400U == (0xfffU 
                                                   & (IData)(
                                                             (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                              >> 0x15U))))
                                        ? vlSelf->soc_top__DOT__cpu_rdata_apb
                                        : (((IData)(vlSelf->soc_top__DOT__instr_req) 
                                            | (0U == 
                                               (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                                >> 0xcU)))
                                            ? vlSelf->soc_top__DOT__instr_rdata
                                            : vlSelf->soc_top__DOT__u_mem__DOT__ram_dout));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__wb_stage_i__DOT__rf_wdata_wb_mux[0U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_wdata_id;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_id 
        = (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q) 
            & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec) 
               & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)) 
                  | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id)))) 
           | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv) 
              | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_jump) 
                 | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_alu) 
                    | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_branch)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n 
        = ((2U & ((((IData)(soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he6d6a5e6__0) 
                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                   << 1U) | (0xfffffffeU & ((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set) 
                                              << 1U) 
                                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                                            | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q))))) 
           | (1U & ((IData)(soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_he6d6a5e6__0) 
                    | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set) 
                        & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                       | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767ff5__0 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h8784150c__0 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h88c42b44__0));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f4a7__0 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h077f4b9b__0));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid 
        = (1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                 | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[0U] 
        = ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[1U]
            : vlSelf->soc_top__DOT__instr_rdata);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[1U] 
        = (IData)((((QData)((IData)(vlSelf->soc_top__DOT__instr_rdata)) 
                    << 0x20U) | (QData)((IData)(((4U 
                                                  & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                                  ? 
                                                 vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[2U]
                                                  : vlSelf->soc_top__DOT__instr_rdata)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d[2U] 
        = (IData)(((((QData)((IData)(vlSelf->soc_top__DOT__instr_rdata)) 
                     << 0x20U) | (QData)((IData)(((4U 
                                                   & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                                   ? 
                                                  vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[2U]
                                                   : vlSelf->soc_top__DOT__instr_rdata)))) 
                   >> 0x20U));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
        = ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[0U]
            : vlSelf->soc_top__DOT__instr_rdata);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__en_wb 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_id)) 
           & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id)) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h91d85a72__0 
        = (1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767ff5__0) 
                 | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46fac9ec__0 
        = (IData)((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                    >> 2U) | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h8784150c__0)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf22c316__0 
        = (1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f4a7__0) 
                 | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                    >> 1U)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext 
        = ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q))
            ? ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                        ? (((- (IData)((vlSelf->soc_top__DOT__cpu_rdata 
                                        >> 0x1fU))) 
                            << 8U) | (vlSelf->soc_top__DOT__cpu_rdata 
                                      >> 0x18U)) : 
                       (vlSelf->soc_top__DOT__cpu_rdata 
                        >> 0x18U)) : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                       ? (((- (IData)(
                                                      (1U 
                                                       & (vlSelf->soc_top__DOT__cpu_rdata 
                                                          >> 0x17U)))) 
                                           << 8U) | 
                                          (0xffU & 
                                           (vlSelf->soc_top__DOT__cpu_rdata 
                                            >> 0x10U)))
                                       : (0xffU & (vlSelf->soc_top__DOT__cpu_rdata 
                                                   >> 0x10U))))
                : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                        ? (((- (IData)((1U & (vlSelf->soc_top__DOT__cpu_rdata 
                                              >> 0xfU)))) 
                            << 8U) | (0xffU & (vlSelf->soc_top__DOT__cpu_rdata 
                                               >> 8U)))
                        : (0xffU & (vlSelf->soc_top__DOT__cpu_rdata 
                                    >> 8U))) : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                                 ? 
                                                (((- (IData)(
                                                             (1U 
                                                              & (vlSelf->soc_top__DOT__cpu_rdata 
                                                                 >> 7U)))) 
                                                  << 8U) 
                                                 | (0xffU 
                                                    & vlSelf->soc_top__DOT__cpu_rdata))
                                                 : 
                                                (0xffU 
                                                 & vlSelf->soc_top__DOT__cpu_rdata))))
            : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q))
                ? ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                            ? (((- (IData)((1U & (vlSelf->soc_top__DOT__cpu_rdata 
                                                  >> 7U)))) 
                                << 0x10U) | ((0xff00U 
                                              & (vlSelf->soc_top__DOT__cpu_rdata 
                                                 << 8U)) 
                                             | (0xffU 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                                   >> 0x10U))))
                            : ((0xff00U & (vlSelf->soc_top__DOT__cpu_rdata 
                                           << 8U)) 
                               | (0xffU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                           >> 0x10U))))
                        : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                            ? (((- (IData)((vlSelf->soc_top__DOT__cpu_rdata 
                                            >> 0x1fU))) 
                                << 0x10U) | (vlSelf->soc_top__DOT__cpu_rdata 
                                             >> 0x10U))
                            : (vlSelf->soc_top__DOT__cpu_rdata 
                               >> 0x10U))) : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                               ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                                   ? 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelf->soc_top__DOT__cpu_rdata 
                                                                   >> 0x17U)))) 
                                                    << 0x10U) 
                                                   | (0xffffU 
                                                      & (vlSelf->soc_top__DOT__cpu_rdata 
                                                         >> 8U)))
                                                   : 
                                                  (0xffffU 
                                                   & (vlSelf->soc_top__DOT__cpu_rdata 
                                                      >> 8U)))
                                               : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q)
                                                   ? 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelf->soc_top__DOT__cpu_rdata 
                                                                   >> 0xfU)))) 
                                                    << 0x10U) 
                                                   | (0xffffU 
                                                      & vlSelf->soc_top__DOT__cpu_rdata))
                                                   : 
                                                  (0xffffU 
                                                   & vlSelf->soc_top__DOT__cpu_rdata))))
                : ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                    ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? ((vlSelf->soc_top__DOT__cpu_rdata 
                            << 8U) | (0xffU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                               >> 0x10U)))
                        : ((vlSelf->soc_top__DOT__cpu_rdata 
                            << 0x10U) | (0xffffU & 
                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                          >> 8U))))
                    : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                        ? ((vlSelf->soc_top__DOT__cpu_rdata 
                            << 0x18U) | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q)
                        : vlSelf->soc_top__DOT__cpu_rdata))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h92feb91f__0) 
           & (3U != (3U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h92feb91f__0) 
           & (3U != (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                           >> 0x10U))));
    if ((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q)) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
            = ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                ? ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[1U] 
                    << 0x10U) | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                 >> 0x10U)) : ((vlSelf->soc_top__DOT__instr_rdata 
                                                << 0x10U) 
                                               | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                                  >> 0x10U)));
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed;
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed;
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_d 
        = (0x7fffffffU & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)
                           ? (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr 
                              >> 1U) : (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                        + ((2U & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)) 
                                                  << 1U)) 
                                           | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)))));
    if ((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q)) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_err 
            = (1U & ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                      ? (((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed)) 
                          & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q) 
                             >> 1U)) | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q))
                      : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err)));
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_valid_raw 
            = (1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed)
                      ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid)
                      : (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                          >> 1U) | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid)))));
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_err 
            = (1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err));
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_valid_raw 
            = (1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_instr_ret_wb 
        = (((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ebrk_insn)) 
            & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ecall_insn_dec)) 
               & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn)) 
                  & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_csr_insn_id)) 
                     & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err)))))) 
           & ((~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_err) 
                  & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid))) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__en_wb)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_access) 
           & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__en_wb)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__wb_stage_i__DOT__rf_wdata_wb_mux[1U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext;
    vlSelf->soc_top__DOT__u_core__DOT__rf_wdata_wb 
        = (((- (IData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id))) 
            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_wdata_id) 
           | ((- (IData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu))) 
              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr) 
           & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_csr_insn_id)) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__special_req 
        = (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn) 
            | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn) 
               | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_d) 
                  | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_err)))) 
           | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__wfi_insn) 
              | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en) 
                  & ((~ ((0x340U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0x14U)) | (0x341U 
                                                   == 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x14U)))) 
                     & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr))) 
                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_err)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_valid_raw));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dscratch1_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dscratch0_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mie_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mscratch_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtvec_en 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtvec_init;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_we = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_en = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_d 
        = (((3U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                    >> 0x1eU)) << 6U) | (((2U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                                  >> 0x1eU)) 
                                          << 5U) | 
                                         (0x1fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_we = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q;
    vlSelf->soc_top__DOT__u_core__DOT__double_fault_seen_o = 0U;
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause) {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstack_en = 1U;
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_d 
                    = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval;
            }
        }
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_d = 3U;
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_if) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__exception_pc 
                = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                   << 1U);
        } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__exception_pc 
                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_id;
        }
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_d 
                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__exception_pc;
        } else if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_d 
                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__exception_pc;
        }
    } else {
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_d 
                = (3U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q);
        } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_d 
                = (3U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                         >> 2U));
        }
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id)))) {
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id) {
                if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_d 
                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_epc_csr__DOT__rdata_q;
                }
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int) {
        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                      >> 0x1fU)))) {
            if ((0x40000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x1aU)))) {
                                if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                    if ((0x1000000U 
                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (0x200000U 
                                                     & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dscratch1_en = 1U;
                                                    }
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x14U)))) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dscratch0_en = 1U;
                                                    }
                                                }
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_en = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                          >> 0x1eU)))) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1bU)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x1aU)))) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x19U)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x18U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((0x400000U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x14U)))) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mie_en = 1U;
                                                    }
                                                    if (
                                                        (0x100000U 
                                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtvec_en = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x19U)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x18U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x14U)))) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mscratch_en = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause) {
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_en = 1U;
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int) {
        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                      >> 0x1fU)))) {
            if ((0x40000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x1aU)))) {
                                if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                    if ((0x1000000U 
                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x14U)))) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_en = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause) {
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_en = 1U;
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int) {
        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                      >> 0x1fU)))) {
            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                          >> 0x1eU)))) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1bU)))) {
                            if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x19U)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x18U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (0x200000U 
                                                     & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_en = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause) {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_en = 1U;
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int) {
        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                      >> 0x1fU)))) {
            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                          >> 0x1eU)))) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1bU)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x1aU)))) {
                                if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x18U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x14U)))) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_we = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x19U)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x18U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x14U)))) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_en = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause) {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_en = 1U;
            }
        }
    } else if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id)))) {
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_en = 1U;
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int) {
        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                      >> 0x1fU)))) {
            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                          >> 0x1eU)))) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1bU)))) {
                            if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x19U)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x18U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (0x200000U 
                                                     & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x14U)))) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_en = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause) {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_en = 1U;
            }
        }
    } else if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id)))) {
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id) {
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_en = 1U;
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int) {
        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                      >> 0x1fU)))) {
            if ((0x40000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x1aU)))) {
                                if ((0x2000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                    if ((0x1000000U 
                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x14U)))) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                                                            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int;
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                                                            = 
                                                            (0x40000000U 
                                                             | (0xfffffffU 
                                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d));
                                                        if (
                                                            ((3U 
                                                              != 
                                                              (3U 
                                                               & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d)) 
                                                             & (0U 
                                                                != 
                                                                (3U 
                                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d)))) {
                                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                                                                = 
                                                                (0xfffffffcU 
                                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d);
                                                        }
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                                                            = 
                                                            ((0xfffffe3fU 
                                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d) 
                                                             | (0x1c0U 
                                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q));
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                                                            = 
                                                            (0xfffff7ffU 
                                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d);
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                                                            = 
                                                            (0xffffffe7U 
                                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d);
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                                                            = 
                                                            (0xfffff9ffU 
                                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d);
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                                                            = 
                                                            (0xffffffdfU 
                                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d);
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                                                            = 
                                                            (0xffffbfffU 
                                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d);
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                                                            = 
                                                            (0xf000ffffU 
                                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause) {
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                = ((0xfffffffcU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d) 
                   | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q));
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d 
                = ((0xfffffe3fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d) 
                   | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_cause_q) 
                      << 6U));
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int) {
        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                      >> 0x1fU)))) {
            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                          >> 0x1eU)))) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1bU)))) {
                            if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x19U)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x18U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (0x100000U 
                                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_en = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause) {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_en = 1U;
            }
        }
    } else if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id)))) {
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id) {
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_en = 1U;
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int) {
        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                      >> 0x1fU)))) {
            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                          >> 0x1eU)))) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1bU)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x1aU)))) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x19U)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x18U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x14U)))) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d 
                                                            = 
                                                            ((0x20U 
                                                              & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                                                 << 2U)) 
                                                             | ((0x10U 
                                                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                                                    >> 3U)) 
                                                                | ((0xcU 
                                                                    & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                                                       >> 9U)) 
                                                                   | ((2U 
                                                                       & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                                                          >> 0x10U)) 
                                                                      | (1U 
                                                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                                                            >> 0x15U))))));
                                                        if (
                                                            ((3U 
                                                              != 
                                                              (3U 
                                                               & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d) 
                                                                  >> 2U))) 
                                                             & (0U 
                                                                != 
                                                                (3U 
                                                                 & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d) 
                                                                    >> 2U))))) {
                                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d 
                                                                = 
                                                                (0x33U 
                                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d));
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause) {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d 
                    = ((3U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d)) 
                       | ((0x10U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                    >> 1U)) | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q) 
                                               << 2U)));
            }
        }
    } else if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id)))) {
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d 
                = ((0x1fU & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d)) 
                   | (0x20U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                               << 1U)));
            if ((3U != (3U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                              >> 2U)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d 
                    = (0x3dU & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d));
            }
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d 
                = ((0x23U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d)) 
                   | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q)
                        ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_csr__DOT__rdata_q)
                        : 4U) << 2U));
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int) {
        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                      >> 0x1fU)))) {
            if ((0x40000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((0x4000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x19U)))) {
                                    if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x18U)))) {
                                        if ((1U & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x17U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 0x16U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x15U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                             >> 0x14U)))) {
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d 
                                                            = 
                                                            (0xc0U 
                                                             & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int);
                                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_we = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause) {
        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save)))) {
            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_d 
                    = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause;
                if ((1U & (~ (IData)((0U != (0x60U 
                                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_d))))))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_we = 1U;
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d 
                        = (0x40U | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d));
                    if ((0x40U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q))) {
                        vlSelf->soc_top__DOT__u_core__DOT__double_fault_seen_o = 1U;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d 
                            = (0x80U | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d));
                    }
                }
            }
        }
    } else if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id)))) {
        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_we = 1U;
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d 
                = (0xbfU & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d));
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_d 
                    = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_cause_csr__DOT__rdata_q;
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we = 0U;
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int) {
        if ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
             >> 0x1fU)) {
            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                          >> 0x1eU)))) {
                if ((0x20000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                    if ((0x10000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                        if ((0x8000000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x1aU)))) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x19U)))) {
                                    if ((0x1000000U 
                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                            = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))));
                                    } else if ((0x800000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                            = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))));
                                    } else if ((0x400000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                            = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))));
                                    } else if ((0x200000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                            = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))));
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x14U)))) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                            = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))));
                                    }
                                }
                            }
                        }
                        if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                      >> 0x1bU)))) {
                            if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x1aU)))) {
                                if ((1U & (~ (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x19U)))) {
                                    if ((0x1000000U 
                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                            = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))));
                                    } else if ((0x800000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                            = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))));
                                    } else if ((0x400000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                            = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))));
                                    } else if ((0x200000U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                            = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))));
                                    } else if ((1U 
                                                & (~ 
                                                   (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                    >> 0x14U)))) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                            = (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                               | (0xffffffffULL 
                                                  & ((IData)(1U) 
                                                     << 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__retain_id = 0U;
    soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT____VdfgExtracted_h1929ae58__0 
        = (1U & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_id)) 
                 & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__special_req) 
                       | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_d 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_we)
            ? (5U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)
            : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q));
    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                    if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set) 
                         | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_tbranch 
                            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set;
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_jump 
                            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set;
                    }
                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__special_req) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__retain_id = 1U;
                    }
                }
            }
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_valid_clear 
        = (1U & ((~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_id) 
                     | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__retain_id))) 
                 | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__halt_if = 0U;
    if ((1U & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__halt_if = 1U;
                }
            } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_d) 
                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_id) 
                        | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__halt_if = 1U;
                }
                if (soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT____VdfgExtracted_h1929ae58__0) {
                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_d) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__halt_if = 1U;
                    }
                }
            } else if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_d) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__halt_if = 1U;
            }
        } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__halt_if = 1U;
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_d 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_valid_clear)) 
           & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__g_branch_set_flop__DOT__branch_set_raw_q) 
              | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_q) 
                 | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready 
        = (1U & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_id)) 
                 & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__halt_if) 
                       | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__retain_id)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs;
    if ((8U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns 
            = ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))
                ? 0U : ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))
                         ? 0U : 5U));
    } else if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 5U;
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 5U;
                if ((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q) 
                      | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q)) 
                     | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q))) {
                    if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err_prio)))) {
                        if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_prio)))) {
                            if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio)))) {
                                if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio) {
                                    if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q) 
                                         | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug))) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 9U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn)))) {
                    if ((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn)))) {
                        if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__wfi_insn) {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 2U;
                        }
                    }
                }
                if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_q) 
                     & (~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio) 
                           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug))))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 8U;
                }
            }
        } else if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__special_req) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 6U;
            }
            if (soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT____VdfgExtracted_h1929ae58__0) {
                if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_d) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 8U;
                }
            }
        } else {
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 5U;
            }
            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_d) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 8U;
            }
        }
    } else if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))) {
            if ((1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q) 
                       | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                          >> 2U)))) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 4U;
            }
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = 3U;
        }
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns 
            = ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs))
                ? 4U : 1U);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr 
        = (1U | ((0xffffffe0U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr) 
                 | ((((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)) 
                      & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready)) 
                     << 4U) | ((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
                                 & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)) 
                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec))) 
                                << 3U) | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_instr_ret_wb) 
                                          << 2U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr 
        = ((0xfffffe1fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr) 
           | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_branch) 
               << 8U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_jump) 
                          << 7U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_store) 
                                     << 6U) | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_load) 
                                               << 5U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr 
        = ((0xffffe1ffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr) 
           | ((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec) 
                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv)) 
               << 0xcU) | ((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv)) 
                            << 0xbU) | ((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_instr_ret_wb) 
                                          & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_is_compressed_id)) 
                                         << 0xaU) | 
                                        ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_tbranch) 
                                         << 9U)))));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__we 
        = (1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                 | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_load 
        = (((QData)((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_q 
                             >> 0x20U))) << 0x20U) 
           | (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)));
    if ((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we)) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_load 
            = (((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)) 
                << 0x20U) | (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_q)));
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_d 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__we)
            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_load
            : ((1U & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q)) 
                      & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr))
                ? (1ULL + vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_q)
                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__we 
        = (1U & ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                  | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we) 
                 >> 2U));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_load 
        = (((QData)((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_q 
                             >> 0x20U))) << 0x20U) 
           | (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)));
    if ((4U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we)) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_load 
            = (((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)) 
                << 0x20U) | (QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_q)));
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_d 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__we)
            ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_load
            : ((1U & ((~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q) 
                          >> 2U)) & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr 
                                     >> 2U))) ? (1ULL 
                                                 + vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_q)
                : vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_new_id_d 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_valid_raw) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 0U;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_q;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q;
    if ((2U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
        if ((1U & (~ vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))) {
            if ((0x8000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                    if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                            = (0x12023U | ((0xc000000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                               << 0x13U)) 
                                           | ((0x2000000U 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 0xdU)) 
                                              | ((0x1f00000U 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                     << 0x12U)) 
                                                 | (0xe00U 
                                                    & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)))));
                    }
                } else if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                    if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                        if ((0x800U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                            if ((0x400U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                                if ((0x100U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                                } else {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                    if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                            } else {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed = 0x8067U;
                                                if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                            }
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed = 0x513U;
                                        } else {
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__spimm 
                                                = (3U 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                      >> 2U));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__rlist 
                                                = (0xfU 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                      >> 4U));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__imm 
                                                = (0x7fU 
                                                   & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__imm));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__4__spimm 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__spimm;
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__4__rlist 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__rlist;
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__4__Vfuncout 
                                                = (0x7fU 
                                                   & (([&]() {
                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist 
                                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__4__rlist;
                                                            {
                                                                if (
                                                                    (8U 
                                                                     & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))) {
                                                                    if (
                                                                        (4U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))) {
                                                                        if (
                                                                            (2U 
                                                                             & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))) {
                                                                            if (
                                                                                (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))) {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout = 0x40U;
                                                                                goto __Vlabel1;
                                                                            } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout = 0x30U;
                                                                                goto __Vlabel1;
                                                                            }
                                                                        } else {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout = 0x30U;
                                                                            goto __Vlabel1;
                                                                        }
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout = 0x20U;
                                                                        goto __Vlabel1;
                                                                    }
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout = 0x10U;
                                                                    goto __Vlabel1;
                                                                } else {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout = 0U;
                                                                    goto __Vlabel1;
                                                                }
                                                                __Vlabel1: ;
                                                            }
                                                        }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout)) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__4__spimm), 4U)));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__imm 
                                                = (
                                                   (0xf80U 
                                                    & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__imm)) 
                                                   | (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__4__Vfuncout));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__imm_signed 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__imm;
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__instr 
                                                = (0x10113U 
                                                   | ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__imm_signed) 
                                                      << 0x14U));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__Vfuncout 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__instr;
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__Vfuncout;
                                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                if (
                                                    (0x1cU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                         >> 8U)))) {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 5U;
                                                } else if (
                                                           (0x1eU 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                >> 8U)))) {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                                } else {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__sp_offset 
                                                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_q;
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__rlist 
                                                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q;
                                            VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__instr, 
                                                            (3U 
                                                             | (([&]() {
                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist 
                                                                    = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__rlist;
                                                                {
                                                                    if (
                                                                        (0x10U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))) {
                                                                        if (
                                                                            (8U 
                                                                             & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout = 0U;
                                                                            goto __Vlabel2;
                                                                        } else if (
                                                                                (4U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout = 0U;
                                                                            goto __Vlabel2;
                                                                        } else if (
                                                                                (2U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout = 0U;
                                                                            goto __Vlabel2;
                                                                        } else if (
                                                                                (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout = 0U;
                                                                            goto __Vlabel2;
                                                                        } else {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist)));
                                                                            goto __Vlabel2;
                                                                        }
                                                                    } else if (
                                                                               (8U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout 
                                                                            = 
                                                                            (0x1fU 
                                                                             & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist)));
                                                                        goto __Vlabel2;
                                                                    } else if (
                                                                               (4U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))) {
                                                                        if (
                                                                            (2U 
                                                                             & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))) {
                                                                            if (
                                                                                (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))) {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist)));
                                                                                goto __Vlabel2;
                                                                            } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(3U) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist)));
                                                                                goto __Vlabel2;
                                                                            }
                                                                        } else if (
                                                                                (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(3U) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist)));
                                                                            goto __Vlabel2;
                                                                        } else {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout = 1U;
                                                                            goto __Vlabel2;
                                                                        }
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout = 0U;
                                                                        goto __Vlabel2;
                                                                    }
                                                                    __Vlabel2: ;
                                                                }
                                                            }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout)) 
                                                                << 7U)));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__instr 
                                                = (0x12000U 
                                                   | ((0xfffU 
                                                       & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__instr) 
                                                      | ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__sp_offset) 
                                                         << 0x16U)));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__Vfuncout 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__instr;
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__Vfuncout;
                                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q) 
                                                        - (IData)(1U)));
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_q) 
                                                        - (IData)(1U)));
                                                if (
                                                    (4U 
                                                     == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q))) {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                                }
                                            }
                                        } else {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    } else {
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__instr_rlist 
                                            = (0xfU 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  >> 4U));
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__rlist 
                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__instr_rlist;
                                        if ((0xfU == (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__rlist))) {
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__rlist = 0x10U;
                                        }
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__Vfuncout 
                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__rlist;
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__Vfuncout;
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                            = (0x1fU 
                                               & (([&]() {
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__spimm 
                                                            = 
                                                            (3U 
                                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                >> 2U));
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__rlist 
                                                            = 
                                                            (0xfU 
                                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                >> 4U));
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__10__spimm 
                                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__spimm;
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__10__rlist 
                                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__rlist;
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__10__Vfuncout 
                                                            = 
                                                            (0x7fU 
                                                             & (([&]() {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist 
                                                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__10__rlist;
                                                                        {
                                                                            if (
                                                                                (8U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))) {
                                                                                if (
                                                                                (4U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))) {
                                                                                if (
                                                                                (2U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))) {
                                                                                if (
                                                                                (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))) {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout = 0x40U;
                                                                                goto __Vlabel3;
                                                                                } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout = 0x30U;
                                                                                goto __Vlabel3;
                                                                                }
                                                                                } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout = 0x30U;
                                                                                goto __Vlabel3;
                                                                                }
                                                                                } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout = 0x20U;
                                                                                goto __Vlabel3;
                                                                                }
                                                                            } else if (
                                                                                (4U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist))) {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout = 0x10U;
                                                                                goto __Vlabel3;
                                                                            } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout = 0U;
                                                                                goto __Vlabel3;
                                                                            }
                                                                            __Vlabel3: ;
                                                                        }
                                                                    }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout)) 
                                                                + 
                                                                VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__10__spimm), 4U)));
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__tmp 
                                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__10__Vfuncout;
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__Vfuncout 
                                                            = 
                                                            (0x1fU 
                                                             & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__tmp) 
                                                                >> 2U));
                                                    }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__Vfuncout)) 
                                                  - (IData)(1U)));
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__sp_offset 
                                            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d;
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__rlist 
                                            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d;
                                        VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__instr, 
                                                        (3U 
                                                         | (([&]() {
                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist 
                                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__rlist;
                                                            {
                                                                if (
                                                                    (0x10U 
                                                                     & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))) {
                                                                    if (
                                                                        (8U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout = 0U;
                                                                        goto __Vlabel4;
                                                                    } else if (
                                                                               (4U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout = 0U;
                                                                        goto __Vlabel4;
                                                                    } else if (
                                                                               (2U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout = 0U;
                                                                        goto __Vlabel4;
                                                                    } else if (
                                                                               (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout = 0U;
                                                                        goto __Vlabel4;
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout 
                                                                            = 
                                                                            (0x1fU 
                                                                             & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist)));
                                                                        goto __Vlabel4;
                                                                    }
                                                                } else if (
                                                                           (8U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout 
                                                                        = 
                                                                        (0x1fU 
                                                                         & ((IData)(0xbU) 
                                                                            + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist)));
                                                                    goto __Vlabel4;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))) {
                                                                        if (
                                                                            (1U 
                                                                             & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist)));
                                                                            goto __Vlabel4;
                                                                        } else {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(3U) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist)));
                                                                            goto __Vlabel4;
                                                                        }
                                                                    } else if (
                                                                               (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout 
                                                                            = 
                                                                            (0x1fU 
                                                                             & ((IData)(3U) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist)));
                                                                        goto __Vlabel4;
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout = 1U;
                                                                        goto __Vlabel4;
                                                                    }
                                                                } else {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout = 0U;
                                                                    goto __Vlabel4;
                                                                }
                                                                __Vlabel4: ;
                                                            }
                                                        }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout)) 
                                                            << 7U)));
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__instr 
                                            = (0x12000U 
                                               | ((0xfffU 
                                                   & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__instr) 
                                                  | ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__sp_offset) 
                                                     << 0x16U)));
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__Vfuncout 
                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__instr;
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__Vfuncout;
                                        if ((3U >= (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                                        } else if (
                                                   (4U 
                                                    == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                            }
                                        } else {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d) 
                                                      - (IData)(1U)));
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d) 
                                                      - (IData)(1U)));
                                            if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 3U;
                                            }
                                        }
                                    }
                                }
                            } else if ((0x200U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                                if ((0x100U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                                } else {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                    if ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                            if ((1U 
                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                            } else {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed = 0x8067U;
                                                if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed = 0x513U;
                                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                            }
                                        } else {
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__spimm 
                                                = (3U 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                      >> 2U));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__rlist 
                                                = (0xfU 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                      >> 4U));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__imm 
                                                = (0x7fU 
                                                   & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__imm));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__18__spimm 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__spimm;
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__18__rlist 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__rlist;
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__18__Vfuncout 
                                                = (0x7fU 
                                                   & (([&]() {
                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist 
                                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__18__rlist;
                                                            {
                                                                if (
                                                                    (8U 
                                                                     & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))) {
                                                                    if (
                                                                        (4U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))) {
                                                                        if (
                                                                            (2U 
                                                                             & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))) {
                                                                            if (
                                                                                (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))) {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout = 0x40U;
                                                                                goto __Vlabel5;
                                                                            } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout = 0x30U;
                                                                                goto __Vlabel5;
                                                                            }
                                                                        } else {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout = 0x30U;
                                                                            goto __Vlabel5;
                                                                        }
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout = 0x20U;
                                                                        goto __Vlabel5;
                                                                    }
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout = 0x10U;
                                                                    goto __Vlabel5;
                                                                } else {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout = 0U;
                                                                    goto __Vlabel5;
                                                                }
                                                                __Vlabel5: ;
                                                            }
                                                        }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout)) 
                                                      + 
                                                      VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__18__spimm), 4U)));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__imm 
                                                = (
                                                   (0xf80U 
                                                    & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__imm)) 
                                                   | (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__18__Vfuncout));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__imm_signed 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__imm;
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__instr 
                                                = (0x10113U 
                                                   | ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__imm_signed) 
                                                      << 0x14U));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__Vfuncout 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__instr;
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__Vfuncout;
                                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                if (
                                                    (0x1cU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                         >> 8U)))) {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 5U;
                                                } else if (
                                                           (0x1eU 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                >> 8U)))) {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 6U;
                                                } else {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                                }
                                            }
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                        if ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__sp_offset 
                                                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_q;
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__rlist 
                                                = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q;
                                            VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__instr, 
                                                            (3U 
                                                             | (([&]() {
                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist 
                                                                    = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__rlist;
                                                                {
                                                                    if (
                                                                        (0x10U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))) {
                                                                        if (
                                                                            (8U 
                                                                             & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout = 0U;
                                                                            goto __Vlabel6;
                                                                        } else if (
                                                                                (4U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout = 0U;
                                                                            goto __Vlabel6;
                                                                        } else if (
                                                                                (2U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout = 0U;
                                                                            goto __Vlabel6;
                                                                        } else if (
                                                                                (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout = 0U;
                                                                            goto __Vlabel6;
                                                                        } else {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist)));
                                                                            goto __Vlabel6;
                                                                        }
                                                                    } else if (
                                                                               (8U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout 
                                                                            = 
                                                                            (0x1fU 
                                                                             & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist)));
                                                                        goto __Vlabel6;
                                                                    } else if (
                                                                               (4U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))) {
                                                                        if (
                                                                            (2U 
                                                                             & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))) {
                                                                            if (
                                                                                (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))) {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist)));
                                                                                goto __Vlabel6;
                                                                            } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(3U) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist)));
                                                                                goto __Vlabel6;
                                                                            }
                                                                        } else if (
                                                                                (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(3U) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist)));
                                                                            goto __Vlabel6;
                                                                        } else {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout = 1U;
                                                                            goto __Vlabel6;
                                                                        }
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout = 0U;
                                                                        goto __Vlabel6;
                                                                    }
                                                                    __Vlabel6: ;
                                                                }
                                                            }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout)) 
                                                                << 7U)));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__instr 
                                                = (0x12000U 
                                                   | ((0xfffU 
                                                       & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__instr) 
                                                      | ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__sp_offset) 
                                                         << 0x16U)));
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__Vfuncout 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__instr;
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__Vfuncout;
                                            if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q) 
                                                        - (IData)(1U)));
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                    = 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_q) 
                                                        - (IData)(1U)));
                                                if (
                                                    (4U 
                                                     == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q))) {
                                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                                }
                                            }
                                        } else {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    } else {
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__instr_rlist 
                                            = (0xfU 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  >> 4U));
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__rlist 
                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__instr_rlist;
                                        if ((0xfU == (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__rlist))) {
                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__rlist = 0x10U;
                                        }
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__Vfuncout 
                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__rlist;
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__Vfuncout;
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                            = (0x1fU 
                                               & (([&]() {
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__spimm 
                                                            = 
                                                            (3U 
                                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                >> 2U));
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__rlist 
                                                            = 
                                                            (0xfU 
                                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                >> 4U));
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__24__spimm 
                                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__spimm;
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__24__rlist 
                                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__rlist;
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__24__Vfuncout 
                                                            = 
                                                            (0x7fU 
                                                             & (([&]() {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist 
                                                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__24__rlist;
                                                                        {
                                                                            if (
                                                                                (8U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))) {
                                                                                if (
                                                                                (4U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))) {
                                                                                if (
                                                                                (2U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))) {
                                                                                if (
                                                                                (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))) {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout = 0x40U;
                                                                                goto __Vlabel7;
                                                                                } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout = 0x30U;
                                                                                goto __Vlabel7;
                                                                                }
                                                                                } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout = 0x30U;
                                                                                goto __Vlabel7;
                                                                                }
                                                                                } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout = 0x20U;
                                                                                goto __Vlabel7;
                                                                                }
                                                                            } else if (
                                                                                (4U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist))) {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout = 0x10U;
                                                                                goto __Vlabel7;
                                                                            } else {
                                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout = 0U;
                                                                                goto __Vlabel7;
                                                                            }
                                                                            __Vlabel7: ;
                                                                        }
                                                                    }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout)) 
                                                                + 
                                                                VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__24__spimm), 4U)));
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__tmp 
                                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__24__Vfuncout;
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__Vfuncout 
                                                            = 
                                                            (0x1fU 
                                                             & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__tmp) 
                                                                >> 2U));
                                                    }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__Vfuncout)) 
                                                  - (IData)(1U)));
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__sp_offset 
                                            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d;
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__rlist 
                                            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d;
                                        VL_ASSIGNSEL_II(32,12,0U, vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__instr, 
                                                        (3U 
                                                         | (([&]() {
                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist 
                                                                = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__rlist;
                                                            {
                                                                if (
                                                                    (0x10U 
                                                                     & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))) {
                                                                    if (
                                                                        (8U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout = 0U;
                                                                        goto __Vlabel8;
                                                                    } else if (
                                                                               (4U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout = 0U;
                                                                        goto __Vlabel8;
                                                                    } else if (
                                                                               (2U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout = 0U;
                                                                        goto __Vlabel8;
                                                                    } else if (
                                                                               (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout = 0U;
                                                                        goto __Vlabel8;
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout 
                                                                            = 
                                                                            (0x1fU 
                                                                             & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist)));
                                                                        goto __Vlabel8;
                                                                    }
                                                                } else if (
                                                                           (8U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout 
                                                                        = 
                                                                        (0x1fU 
                                                                         & ((IData)(0xbU) 
                                                                            + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist)));
                                                                    goto __Vlabel8;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))) {
                                                                    if (
                                                                        (2U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))) {
                                                                        if (
                                                                            (1U 
                                                                             & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))) {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist)));
                                                                            goto __Vlabel8;
                                                                        } else {
                                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout 
                                                                                = 
                                                                                (0x1fU 
                                                                                & ((IData)(3U) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist)));
                                                                            goto __Vlabel8;
                                                                        }
                                                                    } else if (
                                                                               (1U 
                                                                                & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout 
                                                                            = 
                                                                            (0x1fU 
                                                                             & ((IData)(3U) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist)));
                                                                        goto __Vlabel8;
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout = 1U;
                                                                        goto __Vlabel8;
                                                                    }
                                                                } else {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout = 0U;
                                                                    goto __Vlabel8;
                                                                }
                                                                __Vlabel8: ;
                                                            }
                                                        }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout)) 
                                                            << 7U)));
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__instr 
                                            = (0x12000U 
                                               | ((0xfffU 
                                                   & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__instr) 
                                                  | ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__sp_offset) 
                                                     << 0x16U)));
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__Vfuncout 
                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__instr;
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__Vfuncout;
                                        if ((3U >= (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                                        } else if (
                                                   (4U 
                                                    == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                            if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 4U;
                                            }
                                        } else {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d) 
                                                      - (IData)(1U)));
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                                = (0x1fU 
                                                   & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d) 
                                                      - (IData)(1U)));
                                            if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i) 
                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 3U;
                                            }
                                        }
                                    }
                                }
                            } else if ((0x100U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                            } else {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                if ((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__instr_rlist 
                                        = (0xfU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   >> 4U));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__rlist 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__instr_rlist;
                                    if ((0xfU == (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__rlist))) {
                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__rlist = 0x10U;
                                    }
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__rlist;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__Vfuncout;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__rlist 
                                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__instr 
                                        = (0x2e23U 
                                           | (0xffff8000U 
                                              & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__instr));
                                    VL_ASSIGNSEL_II(32,10,0xfU, vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__instr, 
                                                    (2U 
                                                     | (([&]() {
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist 
                                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__rlist;
                                                        {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))) {
                                                                if (
                                                                    (8U 
                                                                     & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout = 0U;
                                                                    goto __Vlabel9;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout = 0U;
                                                                    goto __Vlabel9;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout = 0U;
                                                                    goto __Vlabel9;
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout = 0U;
                                                                    goto __Vlabel9;
                                                                } else {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout 
                                                                        = 
                                                                        (0x1fU 
                                                                         & ((IData)(0xbU) 
                                                                            + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist)));
                                                                    goto __Vlabel9;
                                                                }
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))) {
                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout 
                                                                    = 
                                                                    (0x1fU 
                                                                     & ((IData)(0xbU) 
                                                                        + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist)));
                                                                goto __Vlabel9;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout 
                                                                            = 
                                                                            (0x1fU 
                                                                             & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist)));
                                                                        goto __Vlabel9;
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout 
                                                                            = 
                                                                            (0x1fU 
                                                                             & ((IData)(3U) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist)));
                                                                        goto __Vlabel9;
                                                                    }
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout 
                                                                        = 
                                                                        (0x1fU 
                                                                         & ((IData)(3U) 
                                                                            + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist)));
                                                                    goto __Vlabel9;
                                                                } else {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout = 1U;
                                                                    goto __Vlabel9;
                                                                }
                                                            } else {
                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout = 0U;
                                                                goto __Vlabel9;
                                                            }
                                                            __Vlabel9: ;
                                                        }
                                                    }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout)) 
                                                        << 5U)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__instr 
                                        = (0xfe000000U 
                                           | vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__instr);
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__instr;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__Vfuncout;
                                    if ((3U >= (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                                    } else if ((4U 
                                                == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d))) {
                                        if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i) 
                                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 2U;
                                        }
                                    } else {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = (0x1fU 
                                               & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d) 
                                                  - (IData)(1U)));
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d = 2U;
                                        if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i) 
                                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 1U;
                                        }
                                    }
                                } else if ((1U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__sp_offset 
                                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_q;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__rlist 
                                        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset_signed 
                                        = (0xfffU & 
                                           (- ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__sp_offset) 
                                               << 2U)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset_signed;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__instr 
                                        = (0x2023U 
                                           | ((0xffff8000U 
                                               & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__instr) 
                                              | (0xf80U 
                                                 & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset) 
                                                    << 7U))));
                                    VL_ASSIGNSEL_II(32,10,0xfU, vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__instr, 
                                                    (2U 
                                                     | (([&]() {
                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist 
                                                            = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__rlist;
                                                        {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))) {
                                                                if (
                                                                    (8U 
                                                                     & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout = 0U;
                                                                    goto __Vlabel10;
                                                                } else if (
                                                                           (4U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout = 0U;
                                                                    goto __Vlabel10;
                                                                } else if (
                                                                           (2U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout = 0U;
                                                                    goto __Vlabel10;
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout = 0U;
                                                                    goto __Vlabel10;
                                                                } else {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout 
                                                                        = 
                                                                        (0x1fU 
                                                                         & ((IData)(0xbU) 
                                                                            + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist)));
                                                                    goto __Vlabel10;
                                                                }
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))) {
                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout 
                                                                    = 
                                                                    (0x1fU 
                                                                     & ((IData)(0xbU) 
                                                                        + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist)));
                                                                goto __Vlabel10;
                                                            } else if (
                                                                       (4U 
                                                                        & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout 
                                                                            = 
                                                                            (0x1fU 
                                                                             & ((IData)(0xbU) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist)));
                                                                        goto __Vlabel10;
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout 
                                                                            = 
                                                                            (0x1fU 
                                                                             & ((IData)(3U) 
                                                                                + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist)));
                                                                        goto __Vlabel10;
                                                                    }
                                                                } else if (
                                                                           (1U 
                                                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist))) {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout 
                                                                        = 
                                                                        (0x1fU 
                                                                         & ((IData)(3U) 
                                                                            + (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist)));
                                                                    goto __Vlabel10;
                                                                } else {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout = 1U;
                                                                    goto __Vlabel10;
                                                                }
                                                            } else {
                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout = 0U;
                                                                goto __Vlabel10;
                                                            }
                                                            __Vlabel10: ;
                                                        }
                                                    }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout)) 
                                                        << 5U)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__instr 
                                        = ((0x1ffffffU 
                                            & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__instr) 
                                           | (0xfe000000U 
                                              & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset) 
                                                 << 0x14U)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__instr;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__Vfuncout;
                                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d 
                                            = (0x1fU 
                                               & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q) 
                                                  - (IData)(1U)));
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d 
                                            = (0x1fU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_q)));
                                        if ((4U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q))) {
                                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 2U;
                                        }
                                    }
                                } else if ((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__spimm 
                                        = (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 >> 2U));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__rlist 
                                        = (0xfU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   >> 4U));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__imm 
                                        = (0x7fU & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__imm));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__34__spimm 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__spimm;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__34__rlist 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__rlist;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__34__Vfuncout 
                                        = (0x7fU & 
                                           (([&]() {
                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist 
                                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__34__rlist;
                                                    {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))) {
                                                            if (
                                                                (4U 
                                                                 & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))) {
                                                                if (
                                                                    (2U 
                                                                     & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))) {
                                                                    if (
                                                                        (1U 
                                                                         & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))) {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout = 0x40U;
                                                                        goto __Vlabel11;
                                                                    } else {
                                                                        vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout = 0x30U;
                                                                        goto __Vlabel11;
                                                                    }
                                                                } else {
                                                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout = 0x30U;
                                                                    goto __Vlabel11;
                                                                }
                                                            } else {
                                                                vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout = 0x20U;
                                                                goto __Vlabel11;
                                                            }
                                                        } else if (
                                                                   (4U 
                                                                    & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist))) {
                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout = 0x10U;
                                                            goto __Vlabel11;
                                                        } else {
                                                            vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout = 0U;
                                                            goto __Vlabel11;
                                                        }
                                                        __Vlabel11: ;
                                                    }
                                                }(), (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout)) 
                                            + VL_SHIFTL_III(7,32,32, (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__34__spimm), 4U)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__imm 
                                        = ((0xf80U 
                                            & (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__imm)) 
                                           | (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__34__Vfuncout));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__imm_signed 
                                        = (0xfffU & 
                                           (- (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__imm)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__instr 
                                        = (0x10113U 
                                           | ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__imm_signed) 
                                              << 0x14U));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__instr;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__Vfuncout;
                                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    }
                                } else {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                }
                            }
                        } else {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                        }
                    } else if ((0x800U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                        if ((0x400U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                            if ((1U == (3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                              >> 5U)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                if ((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__rs 
                                        = (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 >> 7U));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__dst 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__rs)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__dst 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__dst;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__instr 
                                        = (0x50013U 
                                           | ((0xfff00000U 
                                               & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__instr) 
                                              | ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__dst) 
                                                 << 7U)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__instr 
                                        = (0xfffffU 
                                           & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__instr);
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__instr;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__Vfuncout;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__Vfuncout;
                                    if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i) 
                                         & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 7U;
                                    }
                                } else if ((7U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__rs 
                                        = (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 >> 2U));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__dst 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__rs)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__dst 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__dst;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__instr 
                                        = (0x58013U 
                                           | ((0xfff00000U 
                                               & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__instr) 
                                              | ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__dst) 
                                                 << 7U)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__instr 
                                        = (0xfffffU 
                                           & vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__instr);
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__instr;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__Vfuncout;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__Vfuncout;
                                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    }
                                } else {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                }
                            } else if ((3U == (3U & 
                                               (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                >> 5U)))) {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 1U;
                                if ((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__rs 
                                        = (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 >> 7U));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__src 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__rs)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__41__src 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__src;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__41__instr 
                                        = (0x513U | 
                                           ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__41__src) 
                                            << 0xfU));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__41__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__41__instr;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__41__Vfuncout;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__Vfuncout;
                                    if (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i) 
                                         & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i))) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 7U;
                                    }
                                } else if ((7U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q))) {
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__rs 
                                        = (7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 >> 2U));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__src 
                                        = (((0U < (3U 
                                                   & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__rs) 
                                                      >> 1U))) 
                                            << 4U) 
                                           | (((0U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__rs) 
                                                    >> 1U))) 
                                               << 3U) 
                                              | (IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__rs)));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__43__src 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__src;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__43__instr 
                                        = (0x593U | 
                                           ((IData)(vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__43__src) 
                                            << 0xfU));
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__43__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__43__instr;
                                    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__Vfuncout 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__43__Vfuncout;
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                        = vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__Vfuncout;
                                    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = 2U;
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                    }
                                } else {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = 0U;
                                }
                            } else {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                            }
                        } else {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                        }
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                    }
                } else if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                        = ((0U != (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            >> 2U)))
                            ? (0x33U | ((0x1f00000U 
                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            << 0x12U)) 
                                        | ((0xf8000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                               << 8U)) 
                                           | (0xf80U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))))
                            : ((0U == (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                >> 7U)))
                                ? 0x100073U : (0xe7U 
                                               | (0xf8000U 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                     << 8U)))));
                } else if ((0U != (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            >> 2U)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                        = (0x33U | ((0x1f00000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 0x12U)) 
                                    | (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)));
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                        = (0x67U | (0xf8000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                << 8U)));
                    if ((0U == (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                         >> 7U)))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                    }
                }
            } else if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                        = (0x12003U | ((0xc000000U 
                                        & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                           << 0x18U)) 
                                       | ((0x2000000U 
                                           & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                              << 0xdU)) 
                                          | ((0x1c00000U 
                                              & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 << 0x12U)) 
                                             | (0xf80U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)))));
                    if ((0U == (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                         >> 7U)))) {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                    }
                }
            } else if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                    = (0x1013U | ((0x1f00000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 << 0x12U)) 
                                  | ((0xf8000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 8U)) 
                                     | (0xf80U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))));
                if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                }
            }
        }
    } else if ((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
        if ((0x8000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
            if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                    = (0x40063U | (((- (IData)((1U 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   >> 0xcU)))) 
                                    << 0x1cU) | ((0xc000000U 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                     << 0x15U)) 
                                                 | ((0x2000000U 
                                                     & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                        << 0x17U)) 
                                                    | ((0x38000U 
                                                        & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                           << 8U)) 
                                                       | ((0x1000U 
                                                           & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                              >> 1U)) 
                                                          | ((0xc00U 
                                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata) 
                                                             | ((0x300U 
                                                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                    << 5U)) 
                                                                | (0x80U 
                                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                      >> 5U))))))))));
            } else if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                    = (0x6fU | ((0x80000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                << 0x13U)) 
                                | ((0x40000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 0x16U)) 
                                   | ((0x30000000U 
                                       & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                          << 0x13U)) 
                                      | ((0x8000000U 
                                          & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                             << 0x15U)) 
                                         | ((0x4000000U 
                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                << 0x13U)) 
                                            | ((0x2000000U 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 0x17U)) 
                                               | ((0x1000000U 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                      << 0xdU)) 
                                                  | ((0xe00000U 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                         << 0x12U)) 
                                                     | ((0x1ff000U 
                                                         & ((- (IData)(
                                                                       (1U 
                                                                        & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                           >> 0xcU)))) 
                                                            << 0xcU)) 
                                                        | (0x80U 
                                                           & ((~ 
                                                               (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                >> 0xfU)) 
                                                              << 7U))))))))))));
            } else if ((0x800U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                if ((0x400U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                    if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                        if ((0x40U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                            if ((0x20U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                                if ((0x10U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                                    if ((8U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                                    } else if ((4U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                            = (0xfff44413U 
                                               | ((0x38000U 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                      << 8U)) 
                                                  | (0x380U 
                                                     & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)));
                                    } else {
                                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                                    }
                                } else {
                                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                        = ((8U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)
                                            ? ((4U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)
                                                ? (0x60541413U 
                                                   | ((0x38000U 
                                                       & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)))
                                                : (0x8044433U 
                                                   | ((0x38000U 
                                                       & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))))
                                            : ((4U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)
                                                ? (0x60441413U 
                                                   | ((0x38000U 
                                                       & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)))
                                                : (0xff47413U 
                                                   | ((0x38000U 
                                                       & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                          << 8U)) 
                                                      | (0x380U 
                                                         & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)))));
                                }
                            } else {
                                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                                    = (0x2840433U | 
                                       ((0x700000U 
                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            << 0x12U)) 
                                        | ((0x38000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                               << 8U)) 
                                           | (0x380U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))));
                            }
                        } else {
                            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                        }
                    } else {
                        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                            = ((0x40U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)
                                ? ((0x20U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)
                                    ? (0x847433U | 
                                       ((0x700000U 
                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            << 0x12U)) 
                                        | ((0x38000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                               << 8U)) 
                                           | (0x380U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))))
                                    : (0x846433U | 
                                       ((0x700000U 
                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            << 0x12U)) 
                                        | ((0x38000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                               << 8U)) 
                                           | (0x380U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)))))
                                : ((0x20U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)
                                    ? (0x844433U | 
                                       ((0x700000U 
                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            << 0x12U)) 
                                        | ((0x38000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                               << 8U)) 
                                           | (0x380U 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))))
                                    : (0x40840433U 
                                       | ((0x700000U 
                                           & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                              << 0x12U)) 
                                          | ((0x38000U 
                                              & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 << 8U)) 
                                             | (0x380U 
                                                & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))))));
                    }
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                        = (0x47413U | (((- (IData)(
                                                   (1U 
                                                    & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                       >> 0xcU)))) 
                                        << 0x1aU) | 
                                       ((0x2000000U 
                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            << 0xdU)) 
                                        | ((0x1f00000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                               << 0x12U)) 
                                           | ((0x38000U 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 8U)) 
                                              | (0x380U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))))));
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                    = (0x45413U | ((0x40000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 0x14U)) 
                                   | ((0x1f00000U & 
                                       (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                        << 0x12U)) 
                                      | ((0x38000U 
                                          & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                             << 8U)) 
                                         | (0x380U 
                                            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)))));
                if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                }
            }
        } else if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
            if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                    = (0x37U | (((- (IData)((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   >> 0xcU)))) 
                                 << 0x11U) | ((0x1f000U 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 0xaU)) 
                                              | (0xf80U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))));
                if ((2U == (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                     >> 7U)))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                        = (0x10113U | (((- (IData)(
                                                   (1U 
                                                    & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                       >> 0xcU)))) 
                                        << 0x1dU) | 
                                       ((0x18000000U 
                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            << 0x18U)) 
                                        | ((0x4000000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                               << 0x15U)) 
                                           | ((0x2000000U 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 0x17U)) 
                                              | (0x1000000U 
                                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                    << 0x12U)))))));
                }
                if ((0U == ((0x20U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                      >> 7U)) | (0x1fU 
                                                 & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                    >> 2U))))) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                    = (0x13U | (((- (IData)((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   >> 0xcU)))) 
                                 << 0x1aU) | ((0x2000000U 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 0xdU)) 
                                              | ((0x1f00000U 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                     << 0x12U)) 
                                                 | (0xf80U 
                                                    & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)))));
            }
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                = ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)
                    ? (0x6fU | ((0x80000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                << 0x13U)) 
                                | ((0x40000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 0x16U)) 
                                   | ((0x30000000U 
                                       & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                          << 0x13U)) 
                                      | ((0x8000000U 
                                          & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                             << 0x15U)) 
                                         | ((0x4000000U 
                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                << 0x13U)) 
                                            | ((0x2000000U 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 0x17U)) 
                                               | ((0x1000000U 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                      << 0xdU)) 
                                                  | ((0xe00000U 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                         << 0x12U)) 
                                                     | ((0x1ff000U 
                                                         & ((- (IData)(
                                                                       (1U 
                                                                        & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                           >> 0xcU)))) 
                                                            << 0xcU)) 
                                                        | (0x80U 
                                                           & ((~ 
                                                               (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                                >> 0xfU)) 
                                                              << 7U))))))))))))
                    : (0x13U | (((- (IData)((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   >> 0xcU)))) 
                                 << 0x1aU) | ((0x2000000U 
                                               & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 0xdU)) 
                                              | ((0x1f00000U 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                     << 0x12U)) 
                                                 | ((0xf8000U 
                                                     & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                        << 8U)) 
                                                    | (0xf80U 
                                                       & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)))))));
        }
    } else if ((0x8000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
        if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
            if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                    = (0x842023U | ((0x4000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 0x15U)) 
                                    | ((0x2000000U 
                                        & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                           << 0xdU)) 
                                       | ((0x700000U 
                                           & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                              << 0x12U)) 
                                          | ((0x38000U 
                                              & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 << 8U)) 
                                             | ((0xc00U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata) 
                                                | (0x200U 
                                                   & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                      << 3U))))))));
            }
        } else if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
        } else if ((0x1000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
        } else if ((0x800U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
            if ((0x400U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                if ((0x40U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                        = (0x841023U | ((0x700000U 
                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            << 0x12U)) 
                                        | ((0x38000U 
                                            & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                               << 8U)) 
                                           | (0x100U 
                                              & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 << 3U)))));
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                    = (0x840023U | ((0x700000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 0x12U)) 
                                    | ((0x38000U & 
                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                         << 8U)) | 
                                       ((0x100U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 3U)) 
                                        | (0x80U & 
                                           (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                            << 1U))))));
            }
        } else if ((0x400U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
            if ((0x40U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                if ((0x40U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                        = (0x41403U | ((0x200000U & 
                                        (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                         << 0x10U)) 
                                       | ((0x38000U 
                                           & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                              << 8U)) 
                                          | (0x380U 
                                             & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                << 5U)))));
                } else {
                    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
                }
            } else {
                vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                    = (0x45403U | ((0x200000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 << 0x10U)) 
                                   | ((0x38000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 8U)) 
                                      | (0x380U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 5U)))));
            }
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                = (0x44403U | ((0x200000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                             << 0x10U)) 
                               | ((0x100000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                << 0xeU)) 
                                  | ((0x38000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 8U)) 
                                     | (0x380U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 5U))))));
        }
    } else if ((0x4000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
        if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
        } else {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
                = (0x42403U | ((0x4000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                              << 0x15U)) 
                               | ((0x3800000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 << 0xdU)) 
                                  | ((0x400000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 0x10U)) 
                                     | ((0x38000U & 
                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                          << 8U)) | 
                                        (0x380U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                   << 5U)))))));
        }
    } else if ((0x2000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata)) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed 
            = (0x10413U | ((0x3c000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                           << 0x13U)) 
                           | ((0x3000000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                             << 0xdU)) 
                              | ((0x800000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                               << 0x12U)) 
                                 | ((0x400000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                  << 0x10U)) 
                                    | (0x380U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                                                 << 5U)))))));
        if ((0U == (0xffU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata 
                             >> 5U)))) {
            vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = 1U;
        }
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_d 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_new_id_d) 
           | ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_valid_clear)) 
              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_gets_expanded 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i)
            ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded)
            : 0U);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659e18c__0 
        = (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready) 
            & (1U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_gets_expanded))) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_valid_raw));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo 
        = ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659e18c__0) 
           & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed)) 
              | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q));
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d1f386f__0 
        = ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46fac9ec__0));
    if (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h2b0e8186__0 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46fac9ec__0;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hc11c213a__0 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf22c316__0;
    } else {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h2b0e8186__0 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf22c316__0;
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hc11c213a__0 
            = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h91d85a72__0;
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en 
        = (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h8784150c__0) 
            << 2U) | (((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46fac9ec__0) 
                         & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                        | ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                           & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f4a7__0))) 
                       << 1U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf22c316__0) 
                                  & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                                 | ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo)) 
                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767ff5__0)))));
}

VL_ATTR_COLD void Vsoc_top___024root___eval_stl(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vsoc_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[8U] = 1U;
        vlSelf->__Vm_traceActivity[7U] = 1U;
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vsoc_top___024root___eval_triggers__stl(Vsoc_top___024root* vlSelf);

VL_ATTR_COLD bool Vsoc_top___024root___eval_phase__stl(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsoc_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vsoc_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__ico(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__act(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or negedge soc_top.rst_n_int)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge soc_top.rst_n_int or posedge soc_top.u_core.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge soc_top.u_core.clk)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(negedge soc_top.u_core.clk)\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__nba(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or negedge soc_top.rst_n_int)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge soc_top.rst_n_int or posedge soc_top.u_core.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge soc_top.u_core.clk)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(negedge soc_top.u_core.clk)\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsoc_top___024root___ctor_var_reset(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__instr_addr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__dma_busy = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__mac_done = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__mac_fsm_state = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__instr_req = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__instr_rdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__cpu_gnt = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__cpu_rvalid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__cpu_rdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__mac_m_rvalid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__dma_m_req = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__dma_m_gnt = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__dma_m_rvalid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__dma_m_we = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__dma_m_addr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__dma_m_wdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__apb_paddr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__apb_pwdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__apb_bus_data = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__cpu_rdata_apb = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__apb_psel = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__apb_penable = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__apb_pwrite = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__apb_pready = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__cpu_rvalid_apb = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__s_psel = VL_RAND_RESET_I(6);
    vlSelf->soc_top__DOT__s1_prdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__d_src = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__d_dst = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__d_len = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__d_start = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__cpu_rvalid_mem = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__rst_sync = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__rst_n_int = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT____Vcellinp__u_bridge__obi_req = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__dma_start = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__double_fault_seen_o = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__core_busy_q = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__u_core__DOT__rf_wdata_wb = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__ic_tag_rdata[__Vi0] = VL_RAND_RESET_I(22);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__ic_data_rdata[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->soc_top__DOT__u_core__DOT__core_clock_gate_i__DOT__en_latch = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_c_id = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_is_compressed_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_gets_expanded_id = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_expanded_id = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err_plus2 = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_c_insn_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_id = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_d_ex[__Vi0] = VL_RAND_RESET_Q(34);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex[__Vi0] = VL_RAND_RESET_Q(34);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_we_ex = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__icache_inval = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_valid_clear = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_pc_mux_id = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause = VL_RAND_RESET_I(7);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_load_err = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_store_err = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ctrl_busy = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_wdata_id = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__result_ex = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__mult_sel_ex = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_access = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_csr_insn_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_valid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_err = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_req_int = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__en_wb = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[__Vi0] = VL_RAND_RESET_Q(34);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg[__Vi0] = VL_RAND_RESET_I(6);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pmp_req_err[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_if = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtvec_init = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_mode_entering = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_instr_ret_wb = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_jump = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_branch = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_tbranch = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_load = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_store = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_insn_id = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[__Vi0] = VL_RAND_RESET_Q(34);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg[__Vi0] = VL_RAND_RESET_I(6);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_new_id_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_new_id_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_valid_raw = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_err = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_gets_expanded = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__exc_pc = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__irq_vec = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_tag_ram_input[__Vi0] = VL_RAND_RESET_I(22);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_data_ram_input[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_q = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_d = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfdd8329f__0 = 0;
    VL_RAND_RESET_W(96, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d);
    VL_RAND_RESET_W(96, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_d = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_d = VL_RAND_RESET_I(31);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q = VL_RAND_RESET_I(31);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h92feb91f__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659e18c__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h88c42b44__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h077f4b9b__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46fac9ec__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf22c316__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h91d85a72__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d1f386f__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h2b0e8186__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hc11c213a__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h8784150c__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h18c9f4a7__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d767ff5__0 = 0;
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ebrk_insn = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mret_insn_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__dret_insn_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ecall_insn_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__wfi_insn_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set_raw_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_run = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_branch = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_jump = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multicycle_done = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_wdata_sel = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_we_raw = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_b_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator = VL_RAND_RESET_I(7);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_alu = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imd_val_q[__Vi0] = VL_RAND_RESET_Q(34);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_a_mux_sel = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_sign_ext = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__g_branch_set_flop__DOT__branch_set_raw_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_illegal = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu = VL_RAND_RESET_I(7);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_cause_q = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err_prio = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_prio = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_prio = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_prio = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__halt_if = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__retain_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__special_req = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__wfi_insn = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b = VL_RAND_RESET_Q(33);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a = VL_RAND_RESET_Q(33);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext = VL_RAND_RESET_Q(34);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_q[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_d[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_imd_val_d[__Vi0] = VL_RAND_RESET_Q(34);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1 = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2 = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3 = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed = VL_RAND_RESET_Q(33);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext = VL_RAND_RESET_Q(33);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__unused_shift_result_ext = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__g_no_alu_rvb__DOT__unused_imd_val_q[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum = VL_RAND_RESET_Q(34);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d = VL_RAND_RESET_Q(34);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d = VL_RAND_RESET_Q(34);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient = VL_RAND_RESET_Q(33);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_a = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_d = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q = VL_RAND_RESET_I(24);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_wdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_2_en_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_2_en_q = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_rvalid_2 = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_bus_err_1_d = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_bus_err_1_q = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__wb_stage_i__DOT__rf_wdata_wb_mux[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__exception_pc = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_d = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d = VL_RAND_RESET_I(6);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mie_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mscratch_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_d = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_d = VL_RAND_RESET_I(7);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_d = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtvec_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_d = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dscratch0_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dscratch1_en = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstack_en = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_d = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_we = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_we = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dbg_csr = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q = VL_RAND_RESET_I(6);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mepc_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mie_csr__DOT__rdata_q = VL_RAND_RESET_I(18);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mscratch_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mcause_csr__DOT__rdata_q = VL_RAND_RESET_I(7);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtval_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtvec_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_depc_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dscratch0_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dscratch1_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_csr__DOT__rdata_q = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_epc_csr__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_cause_csr__DOT__rdata_q = VL_RAND_RESET_I(7);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_load = VL_RAND_RESET_Q(64);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__we = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_d = VL_RAND_RESET_Q(64);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_q = VL_RAND_RESET_Q(64);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_load = VL_RAND_RESET_Q(64);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__we = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_d = VL_RAND_RESET_Q(64);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_q = VL_RAND_RESET_Q(64);
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__1__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__2__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__3__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__4__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__5__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__6__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__7__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__8__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__9__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__10__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__11__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__12__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__13__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__14__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__15__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__16__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__17__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__18__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__19__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__20__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__21__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__22__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__23__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__24__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__25__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__26__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__27__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__28__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__29__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__30__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__31__KET____DOT__rf_reg_q = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT__arb_addr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT__arb_be = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__u_mem__DOT__arb_wdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT__ram_dout = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT____Vcellinp__u_ram__sram_cen = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mem__DOT__u_rom__DOT__rom[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mem__DOT__u_ram__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->soc_top__DOT__u_bridge__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_dma_regs__DOT__abort_o = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_dma_regs__DOT__err_i = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_dma_regs__DOT__irq_ack_o = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_dma_core__DOT__done_o = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_dma_core__DOT__err_o = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_dma_core__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_dma_core__DOT__curr_src = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_dma_core__DOT__curr_dst = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_dma_core__DOT__data_buffer = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_dma_core__DOT__bytes_left = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__start = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_mac__DOT__reg_m = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__reg_k = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__reg_n = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__wgt_addr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__act_addr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__res_addr = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf[__Vi0][__Vi1] = VL_RAND_RESET_I(8);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->soc_top__DOT__u_mac__DOT__weight_in[__Vi0][__Vi1] = VL_RAND_RESET_I(8);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mac__DOT__act_buf[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mac__DOT__res_buf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->soc_top__DOT__u_mac__DOT__load_wgt = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mac__DOT__row_in[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mac__DOT__col_in[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mac__DOT__col_out[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->soc_top__DOT__u_mac__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__u_mac__DOT__next_state = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__u_mac__DOT__wgt_cnt = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_mac__DOT__res_cnt = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_mac__DOT__row_cnt = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__feed_cnt = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__u_mac__DOT__drain_cnt = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__u_mac__DOT__wgt_done_r = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_mac__DOT__res_done_r = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mac__DOT__result_hold[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->soc_top__DOT__u_mac__DOT__m_req_c = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_mac__DOT__m_addr_c = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__m_we_c = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_mac__DOT__m_wdata_c = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__sticky_done = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__pe_addr_reg = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in[__Vi0][__Vi1] = VL_RAND_RESET_I(8);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 5; ++__Vi1) {
            vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire[__Vi0][__Vi1] = VL_RAND_RESET_I(8);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg = VL_RAND_RESET_I(16);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__spimm = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__imm = VL_RAND_RESET_I(12);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__imm_signed = VL_RAND_RESET_I(12);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__3__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__4__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__4__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__4__spimm = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__5__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__sp_offset = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__6__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__7__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__instr_rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__8__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__spimm = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__9__tmp = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__10__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__10__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__10__spimm = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__11__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__sp_offset = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__12__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__13__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__spimm = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__imm = VL_RAND_RESET_I(12);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__imm_signed = VL_RAND_RESET_I(12);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__17__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__18__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__18__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__18__spimm = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__19__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__sp_offset = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__20__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__21__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__instr_rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__22__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__spimm = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_word__23__tmp = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__24__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__24__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__24__spimm = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__25__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__sp_offset = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_pop_load_reg__26__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__27__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__instr_rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_init__28__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__29__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__30__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__sp_offset = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset = VL_RAND_RESET_I(12);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__neg_offset_signed = VL_RAND_RESET_I(12);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_push_store_reg__31__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_top_reg__32__rlist = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__spimm = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__imm = VL_RAND_RESET_I(12);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__imm_signed = VL_RAND_RESET_I(12);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_addi__33__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__34__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__34__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj__34__spimm = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_stack_adj_base__35__rlist = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__rs = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__36__dst = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__dst = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__37__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__rs = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mvsa01__38__dst = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__dst = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__39__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__rs = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__40__src = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__41__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__41__src = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__41__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__rs = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mva01s__42__src = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__43__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__43__src = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_mv_reg__43__instr = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__soc_top__DOT__u_bridge__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__soc_top__DOT__u_dma_core__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__soc_top__DOT__u_dma_core__DOT__curr_src = VL_RAND_RESET_I(32);
    vlSelf->__Vdlyvdim0__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v0 = 0;
    vlSelf->__Vdlyvlsb__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v0 = 0;
    vlSelf->__Vdlyvval__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v0 = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v0 = 0;
    vlSelf->__Vdlyvdim0__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v1 = 0;
    vlSelf->__Vdlyvlsb__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v1 = 0;
    vlSelf->__Vdlyvval__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v1 = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v1 = 0;
    vlSelf->__Vdlyvdim0__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v2 = 0;
    vlSelf->__Vdlyvlsb__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v2 = 0;
    vlSelf->__Vdlyvval__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v2 = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v2 = 0;
    vlSelf->__Vdlyvdim0__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v3 = 0;
    vlSelf->__Vdlyvlsb__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v3 = 0;
    vlSelf->__Vdlyvval__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v3 = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__soc_top__DOT__u_mem__DOT__u_ram__DOT__mem__v3 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__rst_n_int__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__u_core__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
