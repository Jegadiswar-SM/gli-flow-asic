// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"
#include "Vsoc_top___024root.h"

VL_INLINE_OPT void Vsoc_top___024root___nba_comb__TOP__2(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___nba_comb__TOP__2\n"); );
    // Body
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
    vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__wb_stage_i__DOT__rf_wdata_wb_mux[1U] 
        = vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext;
    vlSelf->soc_top__DOT__u_core__DOT__rf_wdata_wb 
        = (((- (IData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id))) 
            & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_wdata_id) 
           | ((- (IData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu))) 
              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext));
}

void Vsoc_top___024root___nba_sequent__TOP__0(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_sequent__TOP__1(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_sequent__TOP__2(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_sequent__TOP__3(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_sequent__TOP__4(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_sequent__TOP__5(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_sequent__TOP__6(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_sequent__TOP__7(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_comb__TOP__0(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_sequent__TOP__8(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_sequent__TOP__9(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___nba_comb__TOP__1(Vsoc_top___024root* vlSelf);

void Vsoc_top___024root___eval_nba(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__5(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__6(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__7(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if ((0xcULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0xeULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_comb__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    if ((0x2eULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_comb__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[8U] = 1U;
    }
}

void Vsoc_top___024root___eval_triggers__act(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___eval_act(Vsoc_top___024root* vlSelf);

bool Vsoc_top___024root___eval_phase__act(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<6> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsoc_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsoc_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsoc_top___024root___eval_phase__nba(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsoc_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__ico(Vsoc_top___024root* vlSelf);
#endif  // VL_DEBUG
bool Vsoc_top___024root___eval_phase__ico(Vsoc_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__nba(Vsoc_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__act(Vsoc_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsoc_top___024root___eval(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vsoc_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../rtl/soc_top.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsoc_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsoc_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/soc_top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsoc_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/soc_top.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsoc_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsoc_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsoc_top___024root___eval_debug_assertions(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG
