// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsoc_top__pch.h"
#include "Vsoc_top.h"
#include "Vsoc_top___024root.h"
#include "Vsoc_top_ibex_pkg.h"

void Vsoc_top___024root____Vdpiexp_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__simutil_get_scramble_key_TOP(Vsoc_top__Syms* __restrict vlSymsp, VlWide<4>/*127:0*/ &val, IData/*31:0*/ &simutil_get_scramble_key__Vfuncrtn);
void Vsoc_top___024root____Vdpiexp_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__simutil_get_scramble_nonce_TOP(Vsoc_top__Syms* __restrict vlSymsp, VlWide<10>/*319:0*/ &nonce, IData/*31:0*/ &simutil_get_scramble_nonce__Vfuncrtn);

// FUNCTIONS
Vsoc_top__Syms::~Vsoc_top__Syms()
{
}

Vsoc_top__Syms::Vsoc_top__Syms(VerilatedContext* contextp, const char* namep, Vsoc_top* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__ibex_pkg{this, Verilated::catName(namep, "ibex_pkg")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__ibex_pkg = &TOP__ibex_pkg;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__ibex_pkg.__Vconfigure(true);
    // Setup scopes
    __Vscope_soc_top.configure(this, name(), "soc_top", "soc_top", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_soc_top__u_core__u_ibex_core__if_stage_i.configure(this, name(), "soc_top.u_core.u_ibex_core.if_stage_i", "if_stage_i", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_soc_top__u_core__u_ibex_core__if_stage_i.exportInsert(__Vfinal, "simutil_get_scramble_key", (void*)(&Vsoc_top___024root____Vdpiexp_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__simutil_get_scramble_key_TOP));
        __Vscope_soc_top__u_core__u_ibex_core__if_stage_i.exportInsert(__Vfinal, "simutil_get_scramble_nonce", (void*)(&Vsoc_top___024root____Vdpiexp_soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__simutil_get_scramble_nonce_TOP));
        __Vscope_soc_top.varInsert(__Vfinal,"dma_busy", &(TOP.soc_top__DOT__dma_busy), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RD,0);
        __Vscope_soc_top.varInsert(__Vfinal,"instr_addr", &(TOP.soc_top__DOT__instr_addr), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RD,1 ,31,0);
        __Vscope_soc_top.varInsert(__Vfinal,"mac_done", &(TOP.soc_top__DOT__mac_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RD,0);
        __Vscope_soc_top.varInsert(__Vfinal,"mac_fsm_state", &(TOP.soc_top__DOT__mac_fsm_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RD,1 ,2,0);
    }
}
