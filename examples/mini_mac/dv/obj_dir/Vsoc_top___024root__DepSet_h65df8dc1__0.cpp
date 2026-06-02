// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"
#include "Vsoc_top__Syms.h"
#include "Vsoc_top___024root.h"

void Vsoc_top___024root____Vdpiexp_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__simutil_get_scramble_key_TOP(Vsoc_top__Syms* __restrict vlSymsp, VlWide<4>/*127:0*/ &val, IData/*31:0*/ &simutil_get_scramble_key__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root____Vdpiexp_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__simutil_get_scramble_key_TOP\n"); );
    // Init
    // Body
    simutil_get_scramble_key__Vfuncrtn = 0U;
}

void Vsoc_top___024root____Vdpiexp_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__simutil_get_scramble_nonce_TOP(Vsoc_top__Syms* __restrict vlSymsp, VlWide<10>/*319:0*/ &nonce, IData/*31:0*/ &simutil_get_scramble_nonce__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root____Vdpiexp_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__simutil_get_scramble_nonce_TOP\n"); );
    // Init
    // Body
    simutil_get_scramble_nonce__Vfuncrtn = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__ico(Vsoc_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsoc_top___024root___eval_triggers__ico(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsoc_top___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__act(Vsoc_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsoc_top___024root___eval_triggers__act(Vsoc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((~ (IData)(vlSelf->rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__rst_n__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((~ (IData)(vlSelf->soc_top__DOT__rst_n_int)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__rst_n_int__0))));
    vlSelf->__VactTriggered.set(2U, (((~ (IData)(vlSelf->soc_top__DOT__rst_n_int)) 
                                      & (IData)(vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__rst_n_int__0)) 
                                     | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__clk) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__u_core__DOT__clk__0)))));
    vlSelf->__VactTriggered.set(3U, ((IData)(vlSelf->soc_top__DOT__u_core__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__u_core__DOT__clk__0))));
    vlSelf->__VactTriggered.set(4U, ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__u_core__DOT__clk__0)));
    vlSelf->__VactTriggered.set(5U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
    vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__rst_n_int__0 
        = vlSelf->soc_top__DOT__rst_n_int;
    vlSelf->__Vtrigprevexpr___TOP__soc_top__DOT__u_core__DOT__clk__0 
        = vlSelf->soc_top__DOT__u_core__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsoc_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
