// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsoc_top.h for the primary calling header

#ifndef VERILATED_VSOC_TOP_IBEX_PKG_H_
#define VERILATED_VSOC_TOP_IBEX_PKG_H_  // guard

#include "verilated.h"


class Vsoc_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsoc_top_ibex_pkg final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vsoc_top__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr VlUnpacked<QData/*33:0*/, 16> __PVT__PmpAddrRst = {{
        0x0000000000000000ULL, 0x0000000000000000ULL,
        0x0000000000000000ULL, 0x0000000000000000ULL,
        0x0000000000000000ULL, 0x0000000000000000ULL,
        0x0000000000000000ULL, 0x0000000000000000ULL,
        0x0000000000000000ULL, 0x0000000000000000ULL,
        0x0000000000000000ULL, 0x0000000000000000ULL,
        0x0000000000000000ULL, 0x0000000000000000ULL,
        0x0000000000000000ULL, 0x0000000000000000ULL
    }};

    // CONSTRUCTORS
    Vsoc_top_ibex_pkg(Vsoc_top__Syms* symsp, const char* v__name);
    ~Vsoc_top_ibex_pkg();
    VL_UNCOPYABLE(Vsoc_top_ibex_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
