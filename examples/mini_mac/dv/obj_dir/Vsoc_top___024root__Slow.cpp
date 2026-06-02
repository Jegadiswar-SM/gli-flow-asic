// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"
#include "Vsoc_top__Syms.h"
#include "Vsoc_top___024root.h"

// Parameter definitions for Vsoc_top___024root
constexpr VlUnpacked<QData/*33:0*/, 16> Vsoc_top___024root::soc_top__DOT__u_core__DOT__PMPRstAddr;
constexpr VlUnpacked<QData/*33:0*/, 16> Vsoc_top___024root::soc_top__DOT__u_core__DOT__u_ibex_core__DOT__PMPRstAddr;
constexpr VlUnpacked<QData/*33:0*/, 16> Vsoc_top___024root::soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__PMPRstAddr;


void Vsoc_top___024root___ctor_var_reset(Vsoc_top___024root* vlSelf);

Vsoc_top___024root::Vsoc_top___024root(Vsoc_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsoc_top___024root___ctor_var_reset(this);
}

void Vsoc_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsoc_top___024root::~Vsoc_top___024root() {
}
