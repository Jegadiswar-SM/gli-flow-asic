// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSOC_TOP__SYMS_H_
#define VERILATED_VSOC_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsoc_top.h"

// INCLUDE MODULE CLASSES
#include "Vsoc_top___024root.h"
#include "Vsoc_top_ibex_pkg.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using Vsoc_top__Vcb_simutil_get_scramble_key_t = void (*) (Vsoc_top__Syms* __restrict vlSymsp, VlWide<4>/*127:0*/ &val, IData/*31:0*/ &simutil_get_scramble_key__Vfuncrtn);
using Vsoc_top__Vcb_simutil_get_scramble_nonce_t = void (*) (Vsoc_top__Syms* __restrict vlSymsp, VlWide<10>/*319:0*/ &nonce, IData/*31:0*/ &simutil_get_scramble_nonce__Vfuncrtn);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vsoc_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsoc_top* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsoc_top___024root             TOP;
    Vsoc_top_ibex_pkg              TOP__ibex_pkg;

    // SCOPE NAMES
    VerilatedScope __Vscope_soc_top;
    VerilatedScope __Vscope_soc_top__u_core__u_ibex_core__if_stage_i;

    // CONSTRUCTORS
    Vsoc_top__Syms(VerilatedContext* contextp, const char* namep, Vsoc_top* modelp);
    ~Vsoc_top__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
