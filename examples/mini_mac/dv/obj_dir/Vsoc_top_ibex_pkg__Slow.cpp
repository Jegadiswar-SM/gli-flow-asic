// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"
#include "Vsoc_top__Syms.h"
#include "Vsoc_top_ibex_pkg.h"

// Parameter definitions for Vsoc_top_ibex_pkg
constexpr VlUnpacked<QData/*33:0*/, 16> Vsoc_top_ibex_pkg::__PVT__PmpAddrRst;


void Vsoc_top_ibex_pkg___ctor_var_reset(Vsoc_top_ibex_pkg* vlSelf);

Vsoc_top_ibex_pkg::Vsoc_top_ibex_pkg(Vsoc_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsoc_top_ibex_pkg___ctor_var_reset(this);
}

void Vsoc_top_ibex_pkg::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsoc_top_ibex_pkg::~Vsoc_top_ibex_pkg() {
}
