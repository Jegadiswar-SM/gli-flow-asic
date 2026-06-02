// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsoc_top__Syms.h"


void Vsoc_top___024root__trace_chg_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsoc_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_chg_0\n"); );
    // Init
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsoc_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsoc_top___024root__trace_chg_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<5>/*159:0*/ __Vtemp_3;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->soc_top__DOT__u_core__DOT__ic_tag_rdata[0]),22);
        bufp->chgIData(oldp+1,(vlSelf->soc_top__DOT__u_core__DOT__ic_tag_rdata[1]),22);
        bufp->chgQData(oldp+2,(vlSelf->soc_top__DOT__u_core__DOT__ic_data_rdata[0]),64);
        bufp->chgQData(oldp+4,(vlSelf->soc_top__DOT__u_core__DOT__ic_data_rdata[1]),64);
        bufp->chgQData(oldp+6,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[0]),34);
        bufp->chgQData(oldp+8,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[1]),34);
        bufp->chgQData(oldp+10,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[2]),34);
        bufp->chgQData(oldp+12,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_addr[3]),34);
        bufp->chgCData(oldp+14,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
                                [0U]),6);
        bufp->chgCData(oldp+15,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
                                [1U]),6);
        bufp->chgCData(oldp+16,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
                                [2U]),6);
        bufp->chgCData(oldp+17,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_pmp_cfg
                                [3U]),6);
        bufp->chgBit(oldp+18,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pmp_req_err[0]));
        bufp->chgBit(oldp+19,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pmp_req_err[1]));
        bufp->chgBit(oldp+20,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pmp_req_err[2]));
        bufp->chgIData(oldp+21,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[0]),32);
        bufp->chgIData(oldp+22,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[1]),32);
        bufp->chgIData(oldp+23,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[2]),32);
        bufp->chgIData(oldp+24,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[3]),32);
        bufp->chgIData(oldp+25,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[4]),32);
        bufp->chgIData(oldp+26,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[5]),32);
        bufp->chgIData(oldp+27,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[6]),32);
        bufp->chgIData(oldp+28,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[7]),32);
        bufp->chgIData(oldp+29,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[8]),32);
        bufp->chgIData(oldp+30,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[9]),32);
        bufp->chgIData(oldp+31,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[10]),32);
        bufp->chgIData(oldp+32,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[11]),32);
        bufp->chgIData(oldp+33,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[12]),32);
        bufp->chgIData(oldp+34,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[13]),32);
        bufp->chgIData(oldp+35,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[14]),32);
        bufp->chgIData(oldp+36,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_addr_rdata[15]),32);
        bufp->chgCData(oldp+37,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[0]),8);
        bufp->chgCData(oldp+38,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[1]),8);
        bufp->chgCData(oldp+39,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[2]),8);
        bufp->chgCData(oldp+40,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[3]),8);
        bufp->chgCData(oldp+41,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[4]),8);
        bufp->chgCData(oldp+42,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[5]),8);
        bufp->chgCData(oldp+43,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[6]),8);
        bufp->chgCData(oldp+44,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[7]),8);
        bufp->chgCData(oldp+45,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[8]),8);
        bufp->chgCData(oldp+46,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[9]),8);
        bufp->chgCData(oldp+47,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[10]),8);
        bufp->chgCData(oldp+48,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[11]),8);
        bufp->chgCData(oldp+49,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[12]),8);
        bufp->chgCData(oldp+50,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[13]),8);
        bufp->chgCData(oldp+51,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[14]),8);
        bufp->chgCData(oldp+52,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__pmp_cfg_rdata[15]),8);
        bufp->chgIData(oldp+53,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[0]),32);
        bufp->chgIData(oldp+54,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[1]),32);
        bufp->chgIData(oldp+55,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[2]),32);
        bufp->chgIData(oldp+56,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[3]),32);
        bufp->chgIData(oldp+57,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[4]),32);
        bufp->chgIData(oldp+58,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[5]),32);
        bufp->chgIData(oldp+59,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[6]),32);
        bufp->chgIData(oldp+60,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[7]),32);
        bufp->chgIData(oldp+61,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[8]),32);
        bufp->chgIData(oldp+62,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[9]),32);
        bufp->chgIData(oldp+63,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[10]),32);
        bufp->chgIData(oldp+64,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[11]),32);
        bufp->chgIData(oldp+65,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[12]),32);
        bufp->chgIData(oldp+66,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[13]),32);
        bufp->chgIData(oldp+67,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[14]),32);
        bufp->chgIData(oldp+68,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[15]),32);
        bufp->chgIData(oldp+69,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[16]),32);
        bufp->chgIData(oldp+70,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[17]),32);
        bufp->chgIData(oldp+71,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[18]),32);
        bufp->chgIData(oldp+72,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[19]),32);
        bufp->chgIData(oldp+73,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[20]),32);
        bufp->chgIData(oldp+74,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[21]),32);
        bufp->chgIData(oldp+75,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[22]),32);
        bufp->chgIData(oldp+76,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[23]),32);
        bufp->chgIData(oldp+77,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[24]),32);
        bufp->chgIData(oldp+78,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[25]),32);
        bufp->chgIData(oldp+79,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[26]),32);
        bufp->chgIData(oldp+80,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[27]),32);
        bufp->chgIData(oldp+81,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[28]),32);
        bufp->chgIData(oldp+82,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[29]),32);
        bufp->chgIData(oldp+83,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[30]),32);
        bufp->chgIData(oldp+84,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmevent[31]),32);
        bufp->chgIData(oldp+85,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_d[0]),32);
        bufp->chgIData(oldp+86,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_d[1]),32);
        bufp->chgQData(oldp+87,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[0]),34);
        bufp->chgQData(oldp+89,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[1]),34);
        bufp->chgQData(oldp+91,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[2]),34);
        bufp->chgQData(oldp+93,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_addr[3]),34);
        bufp->chgCData(oldp+95,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg
                                [0U]),6);
        bufp->chgCData(oldp+96,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg
                                [1U]),6);
        bufp->chgCData(oldp+97,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg
                                [2U]),6);
        bufp->chgCData(oldp+98,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__g_no_pmp__DOT__unused_csr_pmp_cfg
                                [3U]),6);
        bufp->chgBit(oldp+99,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_alu));
        bufp->chgIData(oldp+100,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_tag_ram_input[0]),22);
        bufp->chgIData(oldp+101,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_tag_ram_input[1]),22);
        bufp->chgQData(oldp+102,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_data_ram_input[0]),64);
        bufp->chgQData(oldp+104,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__unused_data_ram_input[1]),64);
        bufp->chgIData(oldp+106,(vlSelf->soc_top__DOT__u_mac__DOT__col_in[0]),32);
        bufp->chgIData(oldp+107,(vlSelf->soc_top__DOT__u_mac__DOT__col_in[1]),32);
        bufp->chgIData(oldp+108,(vlSelf->soc_top__DOT__u_mac__DOT__col_in[2]),32);
        bufp->chgIData(oldp+109,(vlSelf->soc_top__DOT__u_mac__DOT__col_in[3]),32);
        bufp->chgIData(oldp+110,(vlSelf->soc_top__DOT__u_mac__DOT__col_in
                                 [0U]),32);
        bufp->chgIData(oldp+111,(vlSelf->soc_top__DOT__u_mac__DOT__col_in
                                 [1U]),32);
        bufp->chgIData(oldp+112,(vlSelf->soc_top__DOT__u_mac__DOT__col_in
                                 [2U]),32);
        bufp->chgIData(oldp+113,(vlSelf->soc_top__DOT__u_mac__DOT__col_in
                                 [3U]),32);
        bufp->chgIData(oldp+114,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[0]),32);
        bufp->chgIData(oldp+115,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[1]),32);
        bufp->chgIData(oldp+116,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[2]),32);
        bufp->chgIData(oldp+117,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_in[3]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+118,(vlSelf->soc_top__DOT__mac_m_rvalid));
        bufp->chgIData(oldp+119,(vlSelf->soc_top__DOT__u_mac__DOT__m_addr_c),32);
        bufp->chgIData(oldp+120,(vlSelf->soc_top__DOT__u_mac__DOT__m_wdata_c),32);
        bufp->chgBit(oldp+121,(vlSelf->soc_top__DOT__cpu_rvalid_mem));
        bufp->chgBit(oldp+122,(vlSelf->soc_top__DOT__dma_start));
        bufp->chgBit(oldp+123,((1U & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__core_busy_q)))));
        bufp->chgCData(oldp+124,(vlSelf->soc_top__DOT__u_core__DOT__core_busy_q),4);
        bufp->chgBit(oldp+125,((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__core_busy_q))));
        bufp->chgBit(oldp+126,((1U & VL_REDXOR_32((7U 
                                                   & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__core_busy_q) 
                                                      >> 1U))))));
        bufp->chgBit(oldp+127,(vlSelf->soc_top__DOT__u_dma_regs__DOT__abort_o));
        bufp->chgBit(oldp+128,(vlSelf->soc_top__DOT__u_dma_regs__DOT__irq_ack_o));
        bufp->chgIData(oldp+129,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                                 [0U]),32);
        bufp->chgIData(oldp+130,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                                 [1U]),32);
        bufp->chgIData(oldp+131,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                                 [2U]),32);
        bufp->chgIData(oldp+132,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold
                                 [3U]),32);
        bufp->chgBit(oldp+133,(vlSelf->soc_top__DOT__u_mac__DOT__start));
        bufp->chgCData(oldp+134,(vlSelf->soc_top__DOT__u_mac__DOT__reg_m),8);
        bufp->chgCData(oldp+135,(vlSelf->soc_top__DOT__u_mac__DOT__reg_k),8);
        bufp->chgCData(oldp+136,(vlSelf->soc_top__DOT__u_mac__DOT__reg_n),8);
        bufp->chgIData(oldp+137,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_addr),32);
        bufp->chgIData(oldp+138,(vlSelf->soc_top__DOT__u_mac__DOT__act_addr),32);
        bufp->chgIData(oldp+139,(vlSelf->soc_top__DOT__u_mac__DOT__res_addr),32);
        bufp->chgCData(oldp+140,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [0U][0U]),8);
        bufp->chgCData(oldp+141,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [0U][1U]),8);
        bufp->chgCData(oldp+142,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [0U][2U]),8);
        bufp->chgCData(oldp+143,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [0U][3U]),8);
        bufp->chgCData(oldp+144,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [1U][0U]),8);
        bufp->chgCData(oldp+145,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [1U][1U]),8);
        bufp->chgCData(oldp+146,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [1U][2U]),8);
        bufp->chgCData(oldp+147,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [1U][3U]),8);
        bufp->chgCData(oldp+148,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [2U][0U]),8);
        bufp->chgCData(oldp+149,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [2U][1U]),8);
        bufp->chgCData(oldp+150,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [2U][2U]),8);
        bufp->chgCData(oldp+151,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [2U][3U]),8);
        bufp->chgCData(oldp+152,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [3U][0U]),8);
        bufp->chgCData(oldp+153,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [3U][1U]),8);
        bufp->chgCData(oldp+154,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [3U][2U]),8);
        bufp->chgCData(oldp+155,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_buf
                                 [3U][3U]),8);
        bufp->chgCData(oldp+156,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [0U][0U]),8);
        bufp->chgCData(oldp+157,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [0U][1U]),8);
        bufp->chgCData(oldp+158,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [0U][2U]),8);
        bufp->chgCData(oldp+159,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [0U][3U]),8);
        bufp->chgCData(oldp+160,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [1U][0U]),8);
        bufp->chgCData(oldp+161,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [1U][1U]),8);
        bufp->chgCData(oldp+162,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [1U][2U]),8);
        bufp->chgCData(oldp+163,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [1U][3U]),8);
        bufp->chgCData(oldp+164,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [2U][0U]),8);
        bufp->chgCData(oldp+165,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [2U][1U]),8);
        bufp->chgCData(oldp+166,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [2U][2U]),8);
        bufp->chgCData(oldp+167,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [2U][3U]),8);
        bufp->chgCData(oldp+168,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [3U][0U]),8);
        bufp->chgCData(oldp+169,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [3U][1U]),8);
        bufp->chgCData(oldp+170,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [3U][2U]),8);
        bufp->chgCData(oldp+171,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [3U][3U]),8);
        bufp->chgCData(oldp+172,(vlSelf->soc_top__DOT__u_mac__DOT__act_buf[0]),8);
        bufp->chgCData(oldp+173,(vlSelf->soc_top__DOT__u_mac__DOT__act_buf[1]),8);
        bufp->chgCData(oldp+174,(vlSelf->soc_top__DOT__u_mac__DOT__act_buf[2]),8);
        bufp->chgCData(oldp+175,(vlSelf->soc_top__DOT__u_mac__DOT__act_buf[3]),8);
        bufp->chgBit(oldp+176,(vlSelf->soc_top__DOT__u_mac__DOT__load_wgt));
        bufp->chgCData(oldp+177,(vlSelf->soc_top__DOT__u_mac__DOT__row_in[0]),8);
        bufp->chgCData(oldp+178,(vlSelf->soc_top__DOT__u_mac__DOT__row_in[1]),8);
        bufp->chgCData(oldp+179,(vlSelf->soc_top__DOT__u_mac__DOT__row_in[2]),8);
        bufp->chgCData(oldp+180,(vlSelf->soc_top__DOT__u_mac__DOT__row_in[3]),8);
        bufp->chgCData(oldp+181,(vlSelf->soc_top__DOT__u_mac__DOT__state),4);
        bufp->chgCData(oldp+182,(vlSelf->soc_top__DOT__u_mac__DOT__next_state),4);
        bufp->chgCData(oldp+183,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_cnt),2);
        bufp->chgCData(oldp+184,(vlSelf->soc_top__DOT__u_mac__DOT__res_cnt),2);
        bufp->chgCData(oldp+185,(vlSelf->soc_top__DOT__u_mac__DOT__row_cnt),8);
        bufp->chgCData(oldp+186,(vlSelf->soc_top__DOT__u_mac__DOT__feed_cnt),4);
        bufp->chgCData(oldp+187,(vlSelf->soc_top__DOT__u_mac__DOT__drain_cnt),4);
        bufp->chgBit(oldp+188,(vlSelf->soc_top__DOT__u_mac__DOT__wgt_done_r));
        bufp->chgBit(oldp+189,(vlSelf->soc_top__DOT__u_mac__DOT__res_done_r));
        bufp->chgIData(oldp+190,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold[0]),32);
        bufp->chgIData(oldp+191,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold[1]),32);
        bufp->chgIData(oldp+192,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold[2]),32);
        bufp->chgIData(oldp+193,(vlSelf->soc_top__DOT__u_mac__DOT__result_hold[3]),32);
        bufp->chgCData(oldp+194,(vlSelf->soc_top__DOT__u_mac__DOT__row_in
                                 [0U]),8);
        bufp->chgCData(oldp+195,(vlSelf->soc_top__DOT__u_mac__DOT__row_in
                                 [1U]),8);
        bufp->chgCData(oldp+196,(vlSelf->soc_top__DOT__u_mac__DOT__row_in
                                 [2U]),8);
        bufp->chgCData(oldp+197,(vlSelf->soc_top__DOT__u_mac__DOT__row_in
                                 [3U]),8);
        bufp->chgCData(oldp+198,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [0U][0U]),8);
        bufp->chgCData(oldp+199,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [0U][1U]),8);
        bufp->chgCData(oldp+200,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [0U][2U]),8);
        bufp->chgCData(oldp+201,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [0U][3U]),8);
        bufp->chgCData(oldp+202,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [1U][0U]),8);
        bufp->chgCData(oldp+203,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [1U][1U]),8);
        bufp->chgCData(oldp+204,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [1U][2U]),8);
        bufp->chgCData(oldp+205,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [1U][3U]),8);
        bufp->chgCData(oldp+206,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [2U][0U]),8);
        bufp->chgCData(oldp+207,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [2U][1U]),8);
        bufp->chgCData(oldp+208,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [2U][2U]),8);
        bufp->chgCData(oldp+209,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [2U][3U]),8);
        bufp->chgCData(oldp+210,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [3U][0U]),8);
        bufp->chgCData(oldp+211,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [3U][1U]),8);
        bufp->chgCData(oldp+212,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [3U][2U]),8);
        bufp->chgCData(oldp+213,(vlSelf->soc_top__DOT__u_mac__DOT__weight_in
                                 [3U][3U]),8);
        bufp->chgCData(oldp+214,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[0]),8);
        bufp->chgCData(oldp+215,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[1]),8);
        bufp->chgCData(oldp+216,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[2]),8);
        bufp->chgCData(oldp+217,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__row_in[3]),8);
        bufp->chgCData(oldp+218,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [0U][0U]),8);
        bufp->chgCData(oldp+219,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [0U][1U]),8);
        bufp->chgCData(oldp+220,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [0U][2U]),8);
        bufp->chgCData(oldp+221,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [0U][3U]),8);
        bufp->chgCData(oldp+222,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [1U][0U]),8);
        bufp->chgCData(oldp+223,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [1U][1U]),8);
        bufp->chgCData(oldp+224,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [1U][2U]),8);
        bufp->chgCData(oldp+225,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [1U][3U]),8);
        bufp->chgCData(oldp+226,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [2U][0U]),8);
        bufp->chgCData(oldp+227,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [2U][1U]),8);
        bufp->chgCData(oldp+228,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [2U][2U]),8);
        bufp->chgCData(oldp+229,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [2U][3U]),8);
        bufp->chgCData(oldp+230,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [3U][0U]),8);
        bufp->chgCData(oldp+231,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [3U][1U]),8);
        bufp->chgCData(oldp+232,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [3U][2U]),8);
        bufp->chgCData(oldp+233,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [3U][3U]),8);
        bufp->chgCData(oldp+234,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [0U][0U]),8);
        bufp->chgCData(oldp+235,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [0U][1U]),8);
        bufp->chgCData(oldp+236,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [0U][2U]),8);
        bufp->chgCData(oldp+237,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [0U][3U]),8);
        bufp->chgCData(oldp+238,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [0U][4U]),8);
        bufp->chgCData(oldp+239,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [1U][0U]),8);
        bufp->chgCData(oldp+240,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [1U][1U]),8);
        bufp->chgCData(oldp+241,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [1U][2U]),8);
        bufp->chgCData(oldp+242,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [1U][3U]),8);
        bufp->chgCData(oldp+243,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [1U][4U]),8);
        bufp->chgCData(oldp+244,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [2U][0U]),8);
        bufp->chgCData(oldp+245,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [2U][1U]),8);
        bufp->chgCData(oldp+246,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [2U][2U]),8);
        bufp->chgCData(oldp+247,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [2U][3U]),8);
        bufp->chgCData(oldp+248,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [2U][4U]),8);
        bufp->chgCData(oldp+249,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [3U][0U]),8);
        bufp->chgCData(oldp+250,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [3U][1U]),8);
        bufp->chgCData(oldp+251,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [3U][2U]),8);
        bufp->chgCData(oldp+252,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [3U][3U]),8);
        bufp->chgCData(oldp+253,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [3U][4U]),8);
        bufp->chgIData(oldp+254,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [0U][0U]),32);
        bufp->chgIData(oldp+255,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [0U][1U]),32);
        bufp->chgIData(oldp+256,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [0U][2U]),32);
        bufp->chgIData(oldp+257,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [0U][3U]),32);
        bufp->chgIData(oldp+258,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [1U][0U]),32);
        bufp->chgIData(oldp+259,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [1U][1U]),32);
        bufp->chgIData(oldp+260,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [1U][2U]),32);
        bufp->chgIData(oldp+261,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [1U][3U]),32);
        bufp->chgIData(oldp+262,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [2U][0U]),32);
        bufp->chgIData(oldp+263,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [2U][1U]),32);
        bufp->chgIData(oldp+264,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [2U][2U]),32);
        bufp->chgIData(oldp+265,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [2U][3U]),32);
        bufp->chgIData(oldp+266,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [3U][0U]),32);
        bufp->chgIData(oldp+267,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [3U][1U]),32);
        bufp->chgIData(oldp+268,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [3U][2U]),32);
        bufp->chgIData(oldp+269,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [3U][3U]),32);
        bufp->chgIData(oldp+270,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [4U][0U]),32);
        bufp->chgIData(oldp+271,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [4U][1U]),32);
        bufp->chgIData(oldp+272,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [4U][2U]),32);
        bufp->chgIData(oldp+273,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [4U][3U]),32);
        bufp->chgCData(oldp+274,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [0U][0U]),8);
        bufp->chgCData(oldp+275,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [0U][0U]),8);
        bufp->chgIData(oldp+276,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [0U][0U]),32);
        bufp->chgCData(oldp+277,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+278,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+279,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+280,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+281,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+282,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [0U][1U]),8);
        bufp->chgCData(oldp+283,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [0U][1U]),8);
        bufp->chgIData(oldp+284,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [0U][1U]),32);
        bufp->chgCData(oldp+285,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+286,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+287,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+288,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+289,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+290,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [0U][2U]),8);
        bufp->chgCData(oldp+291,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [0U][2U]),8);
        bufp->chgIData(oldp+292,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [0U][2U]),32);
        bufp->chgCData(oldp+293,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+294,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+295,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+296,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+297,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+298,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [0U][3U]),8);
        bufp->chgCData(oldp+299,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [0U][3U]),8);
        bufp->chgIData(oldp+300,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [0U][3U]),32);
        bufp->chgCData(oldp+301,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+302,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+303,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+304,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+305,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__0__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+306,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [1U][0U]),8);
        bufp->chgCData(oldp+307,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [1U][0U]),8);
        bufp->chgIData(oldp+308,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [1U][0U]),32);
        bufp->chgCData(oldp+309,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+310,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+311,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+312,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+313,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+314,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [1U][1U]),8);
        bufp->chgCData(oldp+315,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [1U][1U]),8);
        bufp->chgIData(oldp+316,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [1U][1U]),32);
        bufp->chgCData(oldp+317,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+318,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+319,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+320,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+321,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+322,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [1U][2U]),8);
        bufp->chgCData(oldp+323,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [1U][2U]),8);
        bufp->chgIData(oldp+324,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [1U][2U]),32);
        bufp->chgCData(oldp+325,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+326,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+327,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+328,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+329,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+330,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [1U][3U]),8);
        bufp->chgCData(oldp+331,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [1U][3U]),8);
        bufp->chgIData(oldp+332,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [1U][3U]),32);
        bufp->chgCData(oldp+333,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+334,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+335,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+336,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+337,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__1__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+338,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [2U][0U]),8);
        bufp->chgCData(oldp+339,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [2U][0U]),8);
        bufp->chgIData(oldp+340,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [2U][0U]),32);
        bufp->chgCData(oldp+341,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+342,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+343,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+344,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+345,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+346,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [2U][1U]),8);
        bufp->chgCData(oldp+347,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [2U][1U]),8);
        bufp->chgIData(oldp+348,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [2U][1U]),32);
        bufp->chgCData(oldp+349,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+350,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+351,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+352,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+353,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+354,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [2U][2U]),8);
        bufp->chgCData(oldp+355,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [2U][2U]),8);
        bufp->chgIData(oldp+356,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [2U][2U]),32);
        bufp->chgCData(oldp+357,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+358,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+359,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+360,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+361,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+362,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [2U][3U]),8);
        bufp->chgCData(oldp+363,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [2U][3U]),8);
        bufp->chgIData(oldp+364,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [2U][3U]),32);
        bufp->chgCData(oldp+365,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+366,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+367,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+368,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+369,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__2__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+370,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [3U][0U]),8);
        bufp->chgCData(oldp+371,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [3U][0U]),8);
        bufp->chgIData(oldp+372,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [3U][0U]),32);
        bufp->chgCData(oldp+373,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+374,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+375,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+376,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+377,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__0__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+378,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [3U][1U]),8);
        bufp->chgCData(oldp+379,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [3U][1U]),8);
        bufp->chgIData(oldp+380,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [3U][1U]),32);
        bufp->chgCData(oldp+381,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+382,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+383,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+384,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+385,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__1__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+386,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [3U][2U]),8);
        bufp->chgCData(oldp+387,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [3U][2U]),8);
        bufp->chgIData(oldp+388,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [3U][2U]),32);
        bufp->chgCData(oldp+389,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+390,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+391,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+392,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+393,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__2__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgCData(oldp+394,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__h_wire
                                 [3U][3U]),8);
        bufp->chgCData(oldp+395,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__weight_in
                                 [3U][3U]),8);
        bufp->chgIData(oldp+396,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__v_wire
                                 [3U][3U]),32);
        bufp->chgCData(oldp+397,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__a_out),8);
        bufp->chgIData(oldp+398,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT____Vcellout__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__acc_out),32);
        bufp->chgCData(oldp+399,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__a_reg),8);
        bufp->chgCData(oldp+400,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__w_reg),8);
        bufp->chgSData(oldp+401,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__gen_rows__BRA__3__KET____DOT__gen_cols__BRA__3__KET____DOT__inst_pe__DOT__mul_reg),16);
        bufp->chgBit(oldp+402,(vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__sticky_done));
        bufp->chgCData(oldp+403,(vlSelf->soc_top__DOT__u_mac__DOT__u_regs__DOT__pe_addr_reg),4);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+404,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[0]),32);
        bufp->chgIData(oldp+405,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[1]),32);
        bufp->chgIData(oldp+406,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[2]),32);
        bufp->chgIData(oldp+407,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[3]),32);
        bufp->chgIData(oldp+408,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[4]),32);
        bufp->chgIData(oldp+409,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[5]),32);
        bufp->chgIData(oldp+410,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[6]),32);
        bufp->chgIData(oldp+411,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[7]),32);
        bufp->chgIData(oldp+412,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[8]),32);
        bufp->chgIData(oldp+413,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[9]),32);
        bufp->chgIData(oldp+414,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[10]),32);
        bufp->chgIData(oldp+415,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[11]),32);
        bufp->chgIData(oldp+416,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[12]),32);
        bufp->chgIData(oldp+417,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[13]),32);
        bufp->chgIData(oldp+418,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[14]),32);
        bufp->chgIData(oldp+419,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[15]),32);
        bufp->chgIData(oldp+420,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[16]),32);
        bufp->chgIData(oldp+421,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[17]),32);
        bufp->chgIData(oldp+422,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[18]),32);
        bufp->chgIData(oldp+423,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[19]),32);
        bufp->chgIData(oldp+424,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[20]),32);
        bufp->chgIData(oldp+425,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[21]),32);
        bufp->chgIData(oldp+426,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[22]),32);
        bufp->chgIData(oldp+427,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[23]),32);
        bufp->chgIData(oldp+428,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[24]),32);
        bufp->chgIData(oldp+429,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[25]),32);
        bufp->chgIData(oldp+430,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[26]),32);
        bufp->chgIData(oldp+431,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[27]),32);
        bufp->chgIData(oldp+432,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[28]),32);
        bufp->chgIData(oldp+433,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[29]),32);
        bufp->chgIData(oldp+434,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[30]),32);
        bufp->chgIData(oldp+435,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__rf_reg[31]),32);
        bufp->chgIData(oldp+436,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__10__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+437,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__11__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+438,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__12__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+439,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__13__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+440,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__14__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+441,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__15__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+442,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__16__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+443,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__17__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+444,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__18__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+445,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__19__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+446,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__1__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+447,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__20__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+448,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__21__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+449,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__22__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+450,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__23__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+451,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__24__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+452,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__25__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+453,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__26__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+454,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__27__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+455,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__28__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+456,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__29__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+457,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__2__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+458,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__30__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+459,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__31__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+460,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__3__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+461,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__4__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+462,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__5__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+463,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__6__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+464,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__7__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+465,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__8__KET____DOT__rf_reg_q),32);
        bufp->chgIData(oldp+466,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__g_rf_flops__BRA__9__KET____DOT__rf_reg_q),32);
        bufp->chgBit(oldp+467,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_new_id_q));
        bufp->chgQData(oldp+468,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex[0]),34);
        bufp->chgQData(oldp+470,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex[1]),34);
        bufp->chgBit(oldp+472,((1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+473,((1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                      >> 2U))));
        bufp->chgCData(oldp+474,((7U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q) 
                                        >> 3U))),3);
        bufp->chgBit(oldp+475,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req));
        bufp->chgIData(oldp+476,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_last_q),32);
        bufp->chgBit(oldp+477,((0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))));
        bufp->chgBit(oldp+478,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_q));
        bufp->chgBit(oldp+479,((1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                      >> 5U))));
        bufp->chgIData(oldp+480,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mepc_csr__DOT__rdata_q),32);
        bufp->chgIData(oldp+481,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_depc_csr__DOT__rdata_q),32);
        bufp->chgIData(oldp+482,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtvec_csr__DOT__rdata_q),32);
        bufp->chgBit(oldp+483,((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q))));
        bufp->chgCData(oldp+484,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q),2);
        bufp->chgCData(oldp+485,((3U & ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q))
                                         ? ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                            >> 2U) : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q)))),2);
        bufp->chgBit(oldp+486,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q));
        bufp->chgCData(oldp+487,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_cause_q),3);
        bufp->chgBit(oldp+488,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                                      >> 2U))));
        bufp->chgBit(oldp+489,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                                      >> 0xfU))));
        bufp->chgBit(oldp+490,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q 
                                      >> 0xcU))));
        bufp->chgIData(oldp+491,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtval_csr__DOT__rdata_q),32);
        bufp->chgCData(oldp+492,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q),6);
        bufp->chgIData(oldp+493,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mie_csr__DOT__rdata_q),18);
        bufp->chgIData(oldp+494,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mscratch_csr__DOT__rdata_q),32);
        bufp->chgCData(oldp+495,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mcause_csr__DOT__rdata_q),7);
        bufp->chgIData(oldp+496,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dcsr_csr__DOT__rdata_q),32);
        bufp->chgIData(oldp+497,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dscratch0_csr__DOT__rdata_q),32);
        bufp->chgIData(oldp+498,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_dscratch1_csr__DOT__rdata_q),32);
        bufp->chgCData(oldp+499,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_csr__DOT__rdata_q),3);
        bufp->chgCData(oldp+500,((7U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                        >> 2U))),3);
        bufp->chgIData(oldp+501,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_epc_csr__DOT__rdata_q),32);
        bufp->chgCData(oldp+502,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstack_cause_csr__DOT__rdata_q),7);
        bufp->chgIData(oldp+503,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q),32);
        bufp->chgCData(oldp+504,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q),3);
        bufp->chgQData(oldp+505,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[0]),64);
        bufp->chgQData(oldp+507,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[1]),64);
        bufp->chgQData(oldp+509,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[2]),64);
        bufp->chgQData(oldp+511,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[3]),64);
        bufp->chgQData(oldp+513,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[4]),64);
        bufp->chgQData(oldp+515,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[5]),64);
        bufp->chgQData(oldp+517,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[6]),64);
        bufp->chgQData(oldp+519,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[7]),64);
        bufp->chgQData(oldp+521,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[8]),64);
        bufp->chgQData(oldp+523,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[9]),64);
        bufp->chgQData(oldp+525,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[10]),64);
        bufp->chgQData(oldp+527,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[11]),64);
        bufp->chgQData(oldp+529,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[12]),64);
        bufp->chgQData(oldp+531,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[13]),64);
        bufp->chgQData(oldp+533,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[14]),64);
        bufp->chgQData(oldp+535,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[15]),64);
        bufp->chgQData(oldp+537,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[16]),64);
        bufp->chgQData(oldp+539,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[17]),64);
        bufp->chgQData(oldp+541,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[18]),64);
        bufp->chgQData(oldp+543,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[19]),64);
        bufp->chgQData(oldp+545,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[20]),64);
        bufp->chgQData(oldp+547,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[21]),64);
        bufp->chgQData(oldp+549,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[22]),64);
        bufp->chgQData(oldp+551,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[23]),64);
        bufp->chgQData(oldp+553,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[24]),64);
        bufp->chgQData(oldp+555,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[25]),64);
        bufp->chgQData(oldp+557,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[26]),64);
        bufp->chgQData(oldp+559,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[27]),64);
        bufp->chgQData(oldp+561,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[28]),64);
        bufp->chgQData(oldp+563,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[29]),64);
        bufp->chgQData(oldp+565,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[30]),64);
        bufp->chgQData(oldp+567,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter[31]),64);
        bufp->chgQData(oldp+569,((1ULL + vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_q)),64);
        bufp->chgQData(oldp+571,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_q),64);
        bufp->chgCData(oldp+573,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q),8);
        bufp->chgQData(oldp+574,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_q),64);
        bufp->chgQData(oldp+576,((1ULL + vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_q)),64);
        bufp->chgQData(oldp+578,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a),33);
        bufp->chgIData(oldp+580,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_q[0]),32);
        bufp->chgIData(oldp+581,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_imd_val_q[1]),32);
        bufp->chgIData(oldp+582,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__g_no_alu_rvb__DOT__unused_imd_val_q[0]),32);
        bufp->chgIData(oldp+583,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__g_no_alu_rvb__DOT__unused_imd_val_q[1]),32);
        bufp->chgIData(oldp+584,(((IData)(1U) << (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q))),32);
        bufp->chgIData(oldp+585,((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                         [1U])),32);
        bufp->chgIData(oldp+586,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_q),32);
        bufp->chgIData(oldp+587,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_q),32);
        bufp->chgBit(oldp+588,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid));
        bufp->chgCData(oldp+589,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_q),5);
        bufp->chgBit(oldp+590,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_hold));
        bufp->chgBit(oldp+591,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q));
        bufp->chgBit(oldp+592,((0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q))));
        bufp->chgCData(oldp+593,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_q),3);
        bufp->chgCData(oldp+594,((3U & (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                                [1U] 
                                                >> 0x20U)))),2);
        bufp->chgCData(oldp+595,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_q),2);
        bufp->chgBit(oldp+596,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set));
        bufp->chgBit(oldp+597,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__g_branch_set_flop__DOT__branch_set_raw_q));
        bufp->chgBit(oldp+598,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_q));
        bufp->chgQData(oldp+599,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imd_val_q[0]),34);
        bufp->chgQData(oldp+601,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imd_val_q[1]),34);
        bufp->chgBit(oldp+603,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_q));
        bufp->chgBit(oldp+604,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_q));
        bufp->chgBit(oldp+605,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_q));
        bufp->chgBit(oldp+606,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_q));
        bufp->chgBit(oldp+607,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_q));
        bufp->chgBit(oldp+608,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_q));
        bufp->chgBit(oldp+609,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_q));
        bufp->chgBit(oldp+610,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug));
        bufp->chgBit(oldp+611,((IData)((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                         >> 5U) | (0U 
                                                   == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q))))));
        bufp->chgCData(oldp+612,((0xffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mtvec_csr__DOT__rdata_q)),8);
        bufp->chgCData(oldp+613,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_q),3);
        bufp->chgBit(oldp+614,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_req_q));
        bufp->chgBit(oldp+615,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_q));
        bufp->chgCData(oldp+616,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q),2);
        bufp->chgCData(oldp+617,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_q),2);
        bufp->chgCData(oldp+618,(((2U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                         << 1U)) | 
                                  (1U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                         >> 1U)))),2);
        bufp->chgIData(oldp+619,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q),24);
        bufp->chgCData(oldp+620,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q),2);
        bufp->chgCData(oldp+621,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_type_q),2);
        bufp->chgBit(oldp+622,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_sign_ext_q));
        bufp->chgBit(oldp+623,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_we_q));
        bufp->chgBit(oldp+624,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_q));
        bufp->chgBit(oldp+625,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_q));
        bufp->chgBit(oldp+626,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_q));
        bufp->chgBit(oldp+627,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_or_pmp_err));
        bufp->chgCData(oldp+628,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs),3);
        bufp->chgBit(oldp+629,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_2_en_q));
        bufp->chgBit(oldp+630,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_bus_err_1_q));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[2U] 
                     | vlSelf->__Vm_traceActivity[3U]))) {
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
        bufp->chgWData(oldp+631,(__Vtemp_3),160);
        bufp->chgBit(oldp+636,(((3U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                       >> 0x1cU)) > (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q))));
        bufp->chgBit(oldp+637,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dbg_csr))));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[2U] 
                     | vlSelf->__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+638,(((0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                                | (IData)(vlSelf->soc_top__DOT__instr_req))));
        bufp->chgIData(oldp+639,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex)
                                   ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_q_ex
                                             [0U]) : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d))),32);
        bufp->chgBit(oldp+640,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_valid) 
                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid))));
        bufp->chgQData(oldp+641,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                   ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_a
                                   : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1)
                                       ? (1ULL | ((QData)((IData)(
                                                                  (0x7fffffffU 
                                                                   & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a))) 
                                                  << 2U))
                                       : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2)
                                           ? (1ULL 
                                              | ((QData)((IData)(
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
        bufp->chgBit(oldp+643,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_q)) 
                                & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a) 
                                   ^ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b)))));
        bufp->chgBit(oldp+644,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q)) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__dret_insn_dec))));
        bufp->chgBit(oldp+645,(((3U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_q)) 
                                & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mret_insn_dec) 
                                   | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_mstatus_csr__DOT__rdata_q) 
                                      & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__wfi_insn_dec))))));
        bufp->chgBit(oldp+646,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec) 
                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req))));
        bufp->chgIData(oldp+647,(((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
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
                                           ? (IData)(
                                                     (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                      >> 1U))
                                           : 0x80U)))),32);
        bufp->chgBit(oldp+648,((1U & ((4U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                       ? ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
                                           ? 0x80U : 
                                          ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id))
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
        bufp->chgIData(oldp+649,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_addr_incr_req)
                                   ? ((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                               >> 3U)) 
                                      << 2U) : (IData)(
                                                       (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                        >> 1U)))),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[2U] 
                     | vlSelf->__Vm_traceActivity[7U]))) {
        bufp->chgBit(oldp+650,((1U & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q)) 
                                      & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr))));
        bufp->chgBit(oldp+651,((1U & ((~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q) 
                                          >> 2U)) & 
                                      (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr 
                                       >> 2U)))));
        bufp->chgBit(oldp+652,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_rvalid_2)) 
                                & ((((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)) 
                                     | (4U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) 
                                    & (IData)(vlSelf->soc_top__DOT__cpu_rvalid)) 
                                   | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_2_en_q)))));
        bufp->chgBit(oldp+653,((((2U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs)) 
                                 | (4U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) 
                                & (IData)(vlSelf->soc_top__DOT__cpu_rvalid))));
        bufp->chgBit(oldp+654,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_rvalid_2)) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_bus_err_1_q))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+655,((0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+656,((0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                           >> 0x14U))),5);
        bufp->chgCData(oldp+657,((0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                           >> 7U))),5);
        bufp->chgIData(oldp+658,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id),32);
        bufp->chgSData(oldp+659,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_c_id),16);
        bufp->chgBit(oldp+660,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_is_compressed_id));
        bufp->chgCData(oldp+661,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_gets_expanded_id),2);
        bufp->chgSData(oldp+662,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_expanded_id),16);
        bufp->chgBit(oldp+663,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err));
        bufp->chgBit(oldp+664,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err_plus2));
        bufp->chgBit(oldp+665,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_c_insn_id));
        bufp->chgIData(oldp+666,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                  << 1U)),32);
        bufp->chgIData(oldp+667,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_id),32);
        bufp->chgSData(oldp+668,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x14U)),12);
        bufp->chgBit(oldp+669,((1U & VL_REDXOR_16(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_expanded_id))));
        bufp->chgBit(oldp+670,((1U & VL_REDXOR_2(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_gets_expanded_id))));
        bufp->chgBit(oldp+671,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dbg_csr));
        bufp->chgBit(oldp+672,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__illegal_csr));
        bufp->chgCData(oldp+673,((7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                        >> 0x19U))),3);
        bufp->chgIData(oldp+674,((((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                               >> 0x1fU))) 
                                   << 0xcU) | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                               >> 0x14U))),32);
        bufp->chgIData(oldp+675,((((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                               >> 0x1fU))) 
                                   << 0xcU) | ((0xfe0U 
                                                & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U)) 
                                               | (0x1fU 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                     >> 7U))))),32);
        bufp->chgIData(oldp+676,((((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
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
        bufp->chgIData(oldp+677,((0xfffff000U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id)),32);
        bufp->chgIData(oldp+678,((((- (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                               >> 0x1fU))) 
                                   << 0x14U) | ((0xff000U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id) 
                                                | ((0x800U 
                                                    & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                       >> 9U)) 
                                                   | (0x7feU 
                                                      & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                         >> 0x14U)))))),32);
        bufp->chgIData(oldp+679,((0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                           >> 0xfU))),32);
        bufp->chgBit(oldp+680,(((0x340U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                            >> 0x14U)) 
                                | (0x341U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 0x14U)))));
        bufp->chgSData(oldp+681,(((0x3e0U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                             >> 0xaU)) 
                                  | (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                              >> 7U)))),10);
        bufp->chgCData(oldp+682,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                  >> 0x1bU)),5);
        bufp->chgCData(oldp+683,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_q),5);
        bufp->chgCData(oldp+684,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_q),5);
        bufp->chgIData(oldp+685,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_q),32);
        bufp->chgIData(oldp+686,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q),32);
        bufp->chgWData(oldp+687,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q),96);
        bufp->chgCData(oldp+690,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q),3);
        bufp->chgIData(oldp+691,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q),31);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgBit(oldp+692,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q));
        bufp->chgBit(oldp+693,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id));
        bufp->chgCData(oldp+694,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_pc_mux_id),2);
        bufp->chgBit(oldp+695,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ctrl_busy));
        bufp->chgBit(oldp+696,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_req_int));
        bufp->chgBit(oldp+697,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_if));
        bufp->chgBit(oldp+698,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_mode_entering));
        bufp->chgBit(oldp+699,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_csr_save));
        bufp->chgBit(oldp+700,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_run));
        bufp->chgCData(oldp+701,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs),4);
        bufp->chgBit(oldp+702,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_d));
        bufp->chgBit(oldp+703,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__enter_debug_mode_prio_d));
        bufp->chgCData(oldp+704,((3U & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                        >> 1U))),2);
        bufp->chgCData(oldp+705,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q),3);
        bufp->chgCData(oldp+706,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h88c42b44__0) 
                                   << 2U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h077f4b9b__0) 
                                              << 1U) 
                                             | (1U 
                                                & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q)))))),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgBit(oldp+707,(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c));
        bufp->chgBit(oldp+708,(vlSelf->soc_top__DOT__u_mac__DOT__m_we_c));
        bufp->chgBit(oldp+709,(vlSelf->soc_top__DOT__dma_m_req));
        bufp->chgBit(oldp+710,(vlSelf->soc_top__DOT__dma_m_rvalid));
        bufp->chgBit(oldp+711,(vlSelf->soc_top__DOT__dma_m_we));
        bufp->chgIData(oldp+712,(vlSelf->soc_top__DOT__dma_m_addr),32);
        bufp->chgIData(oldp+713,(vlSelf->soc_top__DOT__dma_m_wdata),32);
        bufp->chgIData(oldp+714,(vlSelf->soc_top__DOT__apb_paddr),32);
        bufp->chgIData(oldp+715,(vlSelf->soc_top__DOT__apb_pwdata),32);
        bufp->chgIData(oldp+716,(vlSelf->soc_top__DOT__apb_bus_data),32);
        bufp->chgIData(oldp+717,(vlSelf->soc_top__DOT__cpu_rdata_apb),32);
        bufp->chgBit(oldp+718,(vlSelf->soc_top__DOT__apb_psel));
        bufp->chgBit(oldp+719,(vlSelf->soc_top__DOT__apb_penable));
        bufp->chgBit(oldp+720,(vlSelf->soc_top__DOT__apb_pwrite));
        bufp->chgBit(oldp+721,(vlSelf->soc_top__DOT__apb_pready));
        bufp->chgBit(oldp+722,(vlSelf->soc_top__DOT__cpu_rvalid_apb));
        bufp->chgCData(oldp+723,(vlSelf->soc_top__DOT__s_psel),6);
        bufp->chgIData(oldp+724,(vlSelf->soc_top__DOT__s1_prdata),32);
        bufp->chgIData(oldp+725,(vlSelf->soc_top__DOT__d_src),32);
        bufp->chgIData(oldp+726,(vlSelf->soc_top__DOT__d_dst),32);
        bufp->chgSData(oldp+727,(vlSelf->soc_top__DOT__d_len),16);
        bufp->chgCData(oldp+728,(vlSelf->soc_top__DOT__u_bridge__DOT__state),2);
        bufp->chgBit(oldp+729,(vlSelf->soc_top__DOT__u_dma_core__DOT__done_o));
        bufp->chgBit(oldp+730,(vlSelf->soc_top__DOT__u_dma_core__DOT__err_o));
        bufp->chgCData(oldp+731,(vlSelf->soc_top__DOT__u_dma_core__DOT__state),3);
        bufp->chgIData(oldp+732,(vlSelf->soc_top__DOT__u_dma_core__DOT__curr_src),32);
        bufp->chgIData(oldp+733,(vlSelf->soc_top__DOT__u_dma_core__DOT__curr_dst),32);
        bufp->chgIData(oldp+734,(vlSelf->soc_top__DOT__u_dma_core__DOT__data_buffer),32);
        bufp->chgSData(oldp+735,(vlSelf->soc_top__DOT__u_dma_core__DOT__bytes_left),16);
        bufp->chgBit(oldp+736,((1U & (IData)(vlSelf->soc_top__DOT__s_psel))));
        bufp->chgBit(oldp+737,((1U & ((IData)(vlSelf->soc_top__DOT__s_psel) 
                                      >> 1U))));
        bufp->chgIData(oldp+738,(vlSelf->soc_top__DOT__u_mac__DOT__col_out[0]),32);
        bufp->chgIData(oldp+739,(vlSelf->soc_top__DOT__u_mac__DOT__col_out[1]),32);
        bufp->chgIData(oldp+740,(vlSelf->soc_top__DOT__u_mac__DOT__col_out[2]),32);
        bufp->chgIData(oldp+741,(vlSelf->soc_top__DOT__u_mac__DOT__col_out[3]),32);
        bufp->chgIData(oldp+742,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
                                 [0U]),32);
        bufp->chgIData(oldp+743,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
                                 [1U]),32);
        bufp->chgIData(oldp+744,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
                                 [2U]),32);
        bufp->chgIData(oldp+745,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out
                                 [3U]),32);
        bufp->chgIData(oldp+746,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[0]),32);
        bufp->chgIData(oldp+747,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[1]),32);
        bufp->chgIData(oldp+748,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[2]),32);
        bufp->chgIData(oldp+749,(vlSelf->soc_top__DOT__u_mac__DOT__u_array__DOT__col_out[3]),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[5U] 
                     | vlSelf->__Vm_traceActivity[6U]))) {
        bufp->chgBit(oldp+750,(((~ (IData)(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req)) 
                                & (IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c))));
        bufp->chgBit(oldp+751,(((0U == (IData)(vlSelf->soc_top__DOT__u_bridge__DOT__state)) 
                                & (IData)(vlSelf->soc_top__DOT____Vcellinp__u_bridge__obi_req))));
        bufp->chgBit(oldp+752,(((IData)(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req) 
                                || ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c) 
                                    || (IData)(vlSelf->soc_top__DOT__dma_m_req)))));
        bufp->chgBit(oldp+753,(((IData)(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req)
                                 ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we)
                                 : ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c)
                                     ? (IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_we_c)
                                     : ((IData)(vlSelf->soc_top__DOT__dma_m_req) 
                                        && (IData)(vlSelf->soc_top__DOT__dma_m_we))))));
        bufp->chgBit(oldp+754,((1U & (~ ((IData)(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req)
                                          ? (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we)
                                          : ((IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_req_c)
                                              ? (IData)(vlSelf->soc_top__DOT__u_mac__DOT__m_we_c)
                                              : ((IData)(vlSelf->soc_top__DOT__dma_m_req) 
                                                 && (IData)(vlSelf->soc_top__DOT__dma_m_we))))))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[6U])) {
        bufp->chgBit(oldp+755,(vlSelf->soc_top__DOT__instr_req));
        bufp->chgBit(oldp+756,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__data_req_out));
        bufp->chgBit(oldp+757,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we));
        bufp->chgCData(oldp+758,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_be),4);
        bufp->chgIData(oldp+759,(((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                           >> 3U)) 
                                  << 2U)),32);
        bufp->chgIData(oldp+760,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_wdata),32);
        bufp->chgBit(oldp+761,((0x400U == (0xfffU & (IData)(
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                             >> 0x15U))))));
        bufp->chgBit(oldp+762,((0x400U != (0xfffU & (IData)(
                                                            (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                             >> 0x15U))))));
        bufp->chgBit(oldp+763,(vlSelf->soc_top__DOT____Vcellinp__u_bridge__obi_req));
        bufp->chgIData(oldp+764,(vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_a),32);
        bufp->chgIData(oldp+765,(vlSelf->soc_top__DOT__u_core__DOT__rf_rdata_b),32);
        bufp->chgQData(oldp+766,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_d_ex[0]),34);
        bufp->chgQData(oldp+768,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_d_ex[1]),34);
        bufp->chgCData(oldp+770,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__imd_val_we_ex),2);
        bufp->chgBit(oldp+771,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__icache_inval));
        bufp->chgBit(oldp+772,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set));
        bufp->chgCData(oldp+773,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_mux_id),3);
        bufp->chgCData(oldp+774,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause),7);
        bufp->chgIData(oldp+775,((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                          >> 1U))),32);
        bufp->chgBit(oldp+776,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_result));
        bufp->chgIData(oldp+777,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_wdata_id),32);
        bufp->chgBit(oldp+778,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id));
        bufp->chgCData(oldp+779,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator),7);
        bufp->chgIData(oldp+780,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a),32);
        bufp->chgIData(oldp+781,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex),32);
        bufp->chgIData(oldp+782,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__result_ex),32);
        bufp->chgBit(oldp+783,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec))));
        bufp->chgBit(oldp+784,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec))));
        bufp->chgBit(oldp+785,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__mult_sel_ex));
        bufp->chgBit(oldp+786,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__div_sel_ex));
        bufp->chgCData(oldp+787,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_operator),2);
        bufp->chgCData(oldp+788,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode),2);
        bufp->chgBit(oldp+789,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_access));
        bufp->chgCData(oldp+790,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op),2);
        bufp->chgIData(oldp+791,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_rdata_int),32);
        bufp->chgBit(oldp+792,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_csr_insn_id));
        bufp->chgCData(oldp+793,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_type),2);
        bufp->chgBit(oldp+794,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_sign_ext));
        bufp->chgBit(oldp+795,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req));
        bufp->chgBit(oldp+796,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_valid));
        bufp->chgBit(oldp+797,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_id));
        bufp->chgBit(oldp+798,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_mret_id));
        bufp->chgBit(oldp+799,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_restore_dret_id));
        bufp->chgBit(oldp+800,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_save_cause));
        bufp->chgBit(oldp+801,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtvec_init));
        bufp->chgIData(oldp+802,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtval),32);
        bufp->chgBit(oldp+803,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_jump));
        bufp->chgBit(oldp+804,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_branch));
        bufp->chgBit(oldp+805,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_tbranch));
        bufp->chgBit(oldp+806,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_load));
        bufp->chgBit(oldp+807,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_store));
        bufp->chgBit(oldp+808,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_insn_id));
        bufp->chgIData(oldp+809,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__exception_pc),32);
        bufp->chgCData(oldp+810,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__priv_lvl_d),2);
        bufp->chgIData(oldp+811,(((0x20000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                               << 0xeU)) 
                                  | ((0x10000U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                                  << 9U)) 
                                     | ((0x8000U & 
                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                          << 4U)) | 
                                        (0x7fffU & 
                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                          >> 0x10U)))))),18);
        bufp->chgIData(oldp+812,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_d),32);
        bufp->chgIData(oldp+813,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_d),32);
        bufp->chgIData(oldp+814,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_mtvec_init)
                                   ? 1U : (1U | (0xffffff00U 
                                                 & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)))),32);
        bufp->chgIData(oldp+815,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_d),32);
        bufp->chgBit(oldp+816,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstack_en));
        bufp->chgCData(oldp+817,((0xffU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)),8);
        bufp->chgCData(oldp+818,((0xc0U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)),8);
        bufp->chgIData(oldp+819,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int),32);
        bufp->chgBit(oldp+820,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr));
        bufp->chgBit(oldp+821,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                      >> 1U))));
        bufp->chgBit(oldp+822,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                      >> 2U))));
        bufp->chgCData(oldp+823,((7U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int 
                                        >> 3U))),3);
        bufp->chgBit(oldp+824,((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)));
        bufp->chgIData(oldp+825,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_result),32);
        bufp->chgQData(oldp+826,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b),33);
        bufp->chgQData(oldp+828,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext),34);
        bufp->chgBit(oldp+830,((0U == (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                               >> 1U)))));
        bufp->chgBit(oldp+831,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel));
        bufp->chgQData(oldp+832,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_imd_val_d[0]),34);
        bufp->chgQData(oldp+834,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_imd_val_d[1]),34);
        bufp->chgCData(oldp+836,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal) 
                                   << 1U) | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal) 
                                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal)))),2);
        bufp->chgIData(oldp+837,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__operand_a_rev),32);
        bufp->chgQData(oldp+838,((0x1ffffffffULL & 
                                  (~ ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                      << 1U)))),33);
        bufp->chgBit(oldp+840,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift1));
        bufp->chgBit(oldp+841,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift2));
        bufp->chgBit(oldp+842,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_a_shift3));
        bufp->chgBit(oldp+843,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate));
        bufp->chgQData(oldp+844,((0x1ffffffffULL & 
                                  ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_sel)
                                    ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__multdiv_alu_operand_b
                                    : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__adder_op_b_negate)
                                        ? (~ ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                              << 1U))
                                        : ((QData)((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                           << 1U))))),33);
        bufp->chgBit(oldp+846,((1U & (((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                        ^ vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex) 
                                       >> 0x1fU) ? 
                                      ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                        >> 0x1fU) ^ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed))
                                       : (~ (IData)(
                                                    (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                     >> 0x20U)))))));
        bufp->chgBit(oldp+847,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__cmp_signed));
        bufp->chgBit(oldp+848,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_left));
        bufp->chgBit(oldp+849,((8U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator))));
        bufp->chgCData(oldp+850,((0x3fU & ((IData)(0x20U) 
                                           - (0x1fU 
                                              & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)))),6);
        bufp->chgIData(oldp+851,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_operand),32);
        bufp->chgQData(oldp+852,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext_signed),33);
        bufp->chgQData(oldp+854,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_ext),33);
        bufp->chgBit(oldp+856,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__unused_shift_result_ext));
        bufp->chgIData(oldp+857,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result),32);
        bufp->chgIData(oldp+858,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__shift_result_rev),32);
        bufp->chgCData(oldp+859,(((0x10U & ((~ (IData)(
                                                       (0U 
                                                        != 
                                                        (0xfU 
                                                         & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex 
                                                            >> 0x18U))))) 
                                            << 4U)) 
                                  | (0xfU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex 
                                             >> 0x18U)))),5);
        bufp->chgCData(oldp+860,((0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex 
                                           >> 0x10U))),5);
        bufp->chgBit(oldp+861,(((3U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)) 
                                | (6U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)))));
        bufp->chgBit(oldp+862,(((4U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)) 
                                | (7U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operator)))));
        bufp->chgIData(oldp+863,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                  | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)),32);
        bufp->chgIData(oldp+864,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                  & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)),32);
        bufp->chgIData(oldp+865,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_operand_a 
                                  ^ vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)),32);
        bufp->chgIData(oldp+866,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_i__DOT__bwlogic_result),32);
        bufp->chgBit(oldp+867,((1U & (((IData)(0x20U) 
                                       - (0x1fU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)) 
                                      >> 5U))));
        bufp->chgQData(oldp+868,((0x7ffffffffULL & 
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
                                   + VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum)))),35);
        bufp->chgQData(oldp+870,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum),34);
        bufp->chgBit(oldp+872,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_a));
        bufp->chgBit(oldp+873,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__sign_b));
        bufp->chgBit(oldp+874,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_valid));
        bufp->chgBit(oldp+875,((0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_signed_mode))));
        bufp->chgQData(oldp+876,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mac_res_d),34);
        bufp->chgQData(oldp+878,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_remainder_d),34);
        bufp->chgQData(oldp+880,((0x3ffffffffULL & 
                                  ((0x7ffffffffULL 
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
                                      & VL_EXTENDS_QQ(35,34, vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__accum))))),34);
        bufp->chgBit(oldp+882,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_a));
        bufp->chgBit(oldp+883,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_sign_b));
        bufp->chgBit(oldp+884,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__is_greater_equal));
        bufp->chgIData(oldp+885,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_denominator_d),32);
        bufp->chgIData(oldp+886,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_numerator_d),32);
        bufp->chgIData(oldp+887,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__op_quotient_d),32);
        bufp->chgIData(oldp+888,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_remainder),32);
        bufp->chgQData(oldp+889,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__next_quotient),33);
        bufp->chgCData(oldp+891,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_counter_d),5);
        bufp->chgBit(oldp+892,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal) 
                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal))));
        bufp->chgBit(oldp+893,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_hold));
        bufp->chgBit(oldp+894,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_by_zero_d));
        bufp->chgBit(oldp+895,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__mult_en_internal));
        bufp->chgBit(oldp+896,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__div_en_internal));
        bufp->chgCData(oldp+897,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__md_state_d),3);
        bufp->chgBit(oldp+898,((1U & (IData)((1ULL 
                                              & ((VL_MULS_QQQ(35, 
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
        bufp->chgCData(oldp+899,(((2U & ((IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                  >> 0x21U)) 
                                         << 1U)) | 
                                  (1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext)))),2);
        bufp->chgSData(oldp+900,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_a),16);
        bufp->chgSData(oldp+901,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_op_b),16);
        bufp->chgCData(oldp+902,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__gen_multdiv_fast__DOT__multdiv_i__DOT__gen_mult_fast__DOT__mult_state_d),2);
        bufp->chgBit(oldp+903,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn));
        bufp->chgBit(oldp+904,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ebrk_insn));
        bufp->chgBit(oldp+905,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mret_insn_dec));
        bufp->chgBit(oldp+906,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__dret_insn_dec));
        bufp->chgBit(oldp+907,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ecall_insn_dec));
        bufp->chgBit(oldp+908,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__wfi_insn_dec));
        bufp->chgBit(oldp+909,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_d));
        bufp->chgBit(oldp+910,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_in_dec));
        bufp->chgBit(oldp+911,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_set_raw_d));
        bufp->chgBit(oldp+912,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_in_dec));
        bufp->chgBit(oldp+913,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_dec));
        bufp->chgBit(oldp+914,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set));
        bufp->chgBit(oldp+915,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw));
        bufp->chgBit(oldp+916,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec));
        bufp->chgBit(oldp+917,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__flush_id));
        bufp->chgIData(oldp+918,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b),32);
        bufp->chgBit(oldp+919,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_wdata_sel));
        bufp->chgBit(oldp+920,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__rf_we));
        bufp->chgBit(oldp+921,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_we_raw));
        bufp->chgBit(oldp+922,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec));
        bufp->chgBit(oldp+923,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_b_dec));
        bufp->chgCData(oldp+924,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel),2);
        bufp->chgCData(oldp+925,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_a_mux_sel_dec),2);
        bufp->chgBit(oldp+926,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__alu_op_b_mux_sel_dec));
        bufp->chgBit(oldp+927,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_a_mux_sel));
        bufp->chgCData(oldp+928,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel),3);
        bufp->chgCData(oldp+929,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_b_mux_sel_dec),3);
        bufp->chgBit(oldp+930,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec));
        bufp->chgBit(oldp+931,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec));
        bufp->chgBit(oldp+932,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multdiv_en_dec));
        bufp->chgBit(oldp+933,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec));
        bufp->chgBit(oldp+934,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__nmi_mode_d));
        bufp->chgBit(oldp+935,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_d));
        bufp->chgBit(oldp+936,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_d));
        bufp->chgBit(oldp+937,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err_prio));
        bufp->chgBit(oldp+938,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_prio));
        bufp->chgBit(oldp+939,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn_prio));
        bufp->chgBit(oldp+940,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio));
        bufp->chgBit(oldp+941,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__store_err_prio));
        bufp->chgBit(oldp+942,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__load_err_prio));
        bufp->chgBit(oldp+943,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ecall_insn));
        bufp->chgBit(oldp+944,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn));
        bufp->chgBit(oldp+945,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn));
        bufp->chgBit(oldp+946,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__wfi_insn));
        bufp->chgBit(oldp+947,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn));
        bufp->chgBit(oldp+948,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__instr_fetch_err));
        bufp->chgBit(oldp+949,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_illegal));
        bufp->chgCData(oldp+950,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op),2);
        bufp->chgCData(oldp+951,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode),7);
        bufp->chgCData(oldp+952,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__opcode_alu),7);
        bufp->chgIData(oldp+953,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr),32);
        bufp->chgIData(oldp+954,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__exc_pc),32);
        bufp->chgCData(oldp+955,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__irq_vec),5);
        bufp->chgBit(oldp+956,((IData)((0U != (0x60U 
                                               & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__exc_cause))))));
        bufp->chgBit(oldp+957,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__valid_new_req));
        bufp->chgBit(oldp+958,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__discard_req_d));
        bufp->chgCData(oldp+959,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n),2);
        bufp->chgCData(oldp+960,((3U & ((IData)(vlSelf->soc_top__DOT__instr_req)
                                         ? VL_SHIFTR_III(2,2,32, (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n), 1U)
                                         : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_n)))),2);
        bufp->chgCData(oldp+961,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n),2);
        bufp->chgCData(oldp+962,((3U & ((IData)(vlSelf->soc_top__DOT__instr_req)
                                         ? VL_SHIFTR_III(2,2,32, (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n), 1U)
                                         : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__branch_discard_n)))),2);
        bufp->chgIData(oldp+963,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d),32);
        bufp->chgBit(oldp+964,(((~ (IData)(vlSelf->soc_top__DOT__instr_req)) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfdd8329f__0))));
        bufp->chgBit(oldp+965,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set) 
                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfdd8329f__0))));
        bufp->chgBit(oldp+966,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid));
        bufp->chgCData(oldp+967,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_d),3);
        bufp->chgCData(oldp+968,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h46fac9ec__0) 
                                   << 2U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_haf22c316__0) 
                                              << 1U) 
                                             | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h91d85a72__0)))),3);
        bufp->chgBit(oldp+969,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err));
        bufp->chgBit(oldp+970,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
        bufp->chgBit(oldp+971,((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr)));
        bufp->chgCData(oldp+972,((3U & (IData)((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ex_block_i__DOT__alu_adder_result_ext 
                                                >> 1U)))),2);
        bufp->chgBit(oldp+973,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__split_misaligned_access));
        bufp->chgBit(oldp+974,(vlSelf->soc_top__DOT____Vcellinp__u_mem__cpu_req));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[6U] 
                     | vlSelf->__Vm_traceActivity[7U]))) {
        bufp->chgBit(oldp+975,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id))));
        bufp->chgBit(oldp+976,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__instr_executing_spec) 
                                & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)) 
                                   & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec)))));
        bufp->chgBit(oldp+977,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__mult_en_dec) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv))));
        bufp->chgBit(oldp+978,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__div_en_dec) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv))));
        bufp->chgBit(oldp+979,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__mret_insn) 
                                | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__dret_insn) 
                                   | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__exc_req_d) 
                                      | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_err))))));
        bufp->chgCData(oldp+980,(((((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)) 
                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d1f386f__0)) 
                                   << 2U) | ((((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)) 
                                               & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h2b0e8186__0)) 
                                              << 1U) 
                                             | ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)) 
                                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hc11c213a__0))))),3);
        bufp->chgBit(oldp+981,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set) 
                                | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hd659e18c__0))));
        bufp->chgCData(oldp+982,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu) 
                                   << 1U) | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_id))),2);
        bufp->chgBit(oldp+983,(((IData)(vlSelf->soc_top__DOT__instr_req) 
                                | (0U == (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                          >> 0xcU)))));
        bufp->chgSData(oldp+984,((0x3ffU & ((IData)(vlSelf->soc_top__DOT__instr_req)
                                             ? (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__stored_addr_d 
                                                >> 2U)
                                             : (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                                >> 2U)))),10);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[7U])) {
        bufp->chgIData(oldp+985,(vlSelf->soc_top__DOT__instr_rdata),32);
        bufp->chgBit(oldp+986,(vlSelf->soc_top__DOT__cpu_gnt));
        bufp->chgBit(oldp+987,(vlSelf->soc_top__DOT__cpu_rvalid));
        bufp->chgBit(oldp+988,(vlSelf->soc_top__DOT__dma_m_gnt));
        bufp->chgBit(oldp+989,(vlSelf->soc_top__DOT__u_core__DOT__double_fault_seen_o));
        bufp->chgIData(oldp+990,(vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec),32);
        bufp->chgBit(oldp+991,((1U & vlSelf->soc_top__DOT__u_core__DOT__gen_regfile_ff__DOT__register_file_i__DOT__we_a_dec)));
        bufp->chgBit(oldp+992,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_valid_clear));
        bufp->chgBit(oldp+993,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_load_err));
        bufp->chgBit(oldp+994,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_store_err));
        bufp->chgBit(oldp+995,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__rf_we_lsu));
        bufp->chgBit(oldp+996,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en));
        bufp->chgBit(oldp+997,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready));
        bufp->chgBit(oldp+998,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid));
        bufp->chgBit(oldp+999,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_err));
        bufp->chgBit(oldp+1000,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__en_wb));
        bufp->chgBit(oldp+1001,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_instr_ret_wb));
        bufp->chgCData(oldp+1002,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_d),6);
        bufp->chgBit(oldp+1003,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mstatus_en));
        bufp->chgBit(oldp+1004,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mie_en));
        bufp->chgBit(oldp+1005,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mscratch_en));
        bufp->chgBit(oldp+1006,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mepc_en));
        bufp->chgCData(oldp+1007,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_d),7);
        bufp->chgBit(oldp+1008,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcause_en));
        bufp->chgBit(oldp+1009,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtval_en));
        bufp->chgBit(oldp+1010,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mtvec_en));
        bufp->chgIData(oldp+1011,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_d),32);
        bufp->chgBit(oldp+1012,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dcsr_en));
        bufp->chgBit(oldp+1013,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__depc_en));
        bufp->chgBit(oldp+1014,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dscratch0_en));
        bufp->chgBit(oldp+1015,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__dscratch1_en));
        bufp->chgBit(oldp+1016,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_we));
        bufp->chgIData(oldp+1017,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we),32);
        bufp->chgIData(oldp+1018,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we),32);
        bufp->chgIData(oldp+1019,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr),32);
        bufp->chgBit(oldp+1020,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                       >> 1U))));
        bufp->chgBit(oldp+1021,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                       >> 1U))));
        bufp->chgBit(oldp+1022,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr 
                                       >> 1U))));
        bufp->chgCData(oldp+1023,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_d),8);
        bufp->chgBit(oldp+1024,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__cpuctrlsts_part_we));
        bufp->chgBit(oldp+1025,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_we_int));
        bufp->chgIData(oldp+1026,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                   >> 3U)),29);
        bufp->chgIData(oldp+1027,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                   >> 3U)),29);
        bufp->chgIData(oldp+1028,((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_incr 
                                   >> 3U)),29);
        bufp->chgBit(oldp+1029,((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we)));
        bufp->chgBit(oldp+1030,((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we)));
        bufp->chgQData(oldp+1031,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_load),64);
        bufp->chgBit(oldp+1033,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__we));
        bufp->chgQData(oldp+1034,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcycle_counter_i__DOT__counter_d),64);
        bufp->chgBit(oldp+1036,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounterh_we 
                                       >> 2U))));
        bufp->chgBit(oldp+1037,((1U & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mhpmcounter_we 
                                       >> 2U))));
        bufp->chgQData(oldp+1038,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_load),64);
        bufp->chgBit(oldp+1040,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__we));
        bufp->chgQData(oldp+1041,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__minstret_counter_i__DOT__counter_d),64);
        bufp->chgBit(oldp+1043,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_multdiv));
        bufp->chgBit(oldp+1044,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_branch));
        bufp->chgBit(oldp+1045,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_jump));
        bufp->chgBit(oldp+1046,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__stall_id));
        bufp->chgBit(oldp+1047,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__multicycle_done));
        bufp->chgBit(oldp+1048,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__id_fsm_d));
        bufp->chgCData(oldp+1049,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns),4);
        bufp->chgBit(oldp+1050,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__halt_if));
        bufp->chgBit(oldp+1051,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__retain_id));
        bufp->chgBit(oldp+1052,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__special_req));
        bufp->chgBit(oldp+1053,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_new_id_d));
        bufp->chgBit(oldp+1054,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_valid_raw));
        bufp->chgBit(oldp+1055,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready) 
                                 & (1U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_gets_expanded)))));
        bufp->chgIData(oldp+1056,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata),32);
        bufp->chgBit(oldp+1057,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_err));
        bufp->chgIData(oldp+1058,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_decompressed),32);
        bufp->chgBit(oldp+1059,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__illegal_c_insn));
        bufp->chgBit(oldp+1060,((3U != (3U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__fetch_rdata))));
        bufp->chgCData(oldp+1061,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_gets_expanded),2);
        bufp->chgBit(oldp+1062,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__valid_i));
        bufp->chgBit(oldp+1063,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT____Vcellinp__compressed_decoder_i__id_in_ready_i));
        bufp->chgCData(oldp+1064,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_rlist_d),5);
        bufp->chgCData(oldp+1065,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_sp_offset_d),5);
        bufp->chgCData(oldp+1066,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__cm_state_d),3);
        bufp->chgCData(oldp+1067,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__compressed_decoder_i__DOT__gets_expanded),2);
        bufp->chgWData(oldp+1068,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_d),96);
        bufp->chgCData(oldp+1071,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h0d1f386f__0) 
                                    << 2U) | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_h2b0e8186__0) 
                                               << 1U) 
                                              | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT____VdfgTmp_hc11c213a__0)))),3);
        bufp->chgCData(oldp+1072,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__entry_en),3);
        bufp->chgBit(oldp+1073,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__pop_fifo));
        bufp->chgIData(oldp+1074,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata),32);
        bufp->chgBit(oldp+1075,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__aligned_is_compressed));
        bufp->chgBit(oldp+1076,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed));
        bufp->chgBit(oldp+1077,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two));
        bufp->chgBit(oldp+1078,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__addr_update));
        bufp->chgBit(oldp+1079,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ctrl_update));
        bufp->chgBit(oldp+1080,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_update));
        bufp->chgBit(oldp+1081,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__handle_misaligned_d));
        bufp->chgBit(oldp+1082,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__pmp_err_d));
        bufp->chgBit(oldp+1083,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__lsu_err_d));
        bufp->chgCData(oldp+1084,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns),3);
        bufp->chgBit(oldp+1085,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__fcov_mis_rvalid_2));
        bufp->chgIData(oldp+1086,(vlSelf->soc_top__DOT__u_mem__DOT__arb_addr),32);
        bufp->chgCData(oldp+1087,(vlSelf->soc_top__DOT__u_mem__DOT__arb_be),4);
        bufp->chgIData(oldp+1088,(vlSelf->soc_top__DOT__u_mem__DOT__arb_wdata),32);
        bufp->chgBit(oldp+1089,((0x100U == (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                            >> 0x14U))));
        bufp->chgBit(oldp+1090,(vlSelf->soc_top__DOT__u_mem__DOT____Vcellinp__u_ram__sram_cen));
        bufp->chgSData(oldp+1091,((0x7ffU & (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                             >> 2U))),11);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[8U])) {
        bufp->chgIData(oldp+1092,(vlSelf->soc_top__DOT__cpu_rdata),32);
        bufp->chgIData(oldp+1093,(vlSelf->soc_top__DOT__u_core__DOT__rf_wdata_wb),32);
        bufp->chgIData(oldp+1094,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__data_rdata_ext),32);
    }
    bufp->chgBit(oldp+1095,(vlSelf->clk));
    bufp->chgBit(oldp+1096,(vlSelf->rst_n));
    bufp->chgIData(oldp+1097,(vlSelf->soc_top__DOT__instr_addr),32);
    bufp->chgBit(oldp+1098,(vlSelf->soc_top__DOT__dma_busy));
    bufp->chgBit(oldp+1099,(vlSelf->soc_top__DOT__mac_done));
    bufp->chgCData(oldp+1100,(vlSelf->soc_top__DOT__mac_fsm_state),3);
    bufp->chgIData(oldp+1101,(vlSelf->soc_top__DOT__u_mem__DOT__ram_dout),32);
    bufp->chgIData(oldp+1102,(((0U == (0xffU & vlSelf->soc_top__DOT__apb_paddr))
                                ? vlSelf->soc_top__DOT__d_src
                                : ((4U == (0xffU & vlSelf->soc_top__DOT__apb_paddr))
                                    ? vlSelf->soc_top__DOT__d_dst
                                    : ((8U == (0xffU 
                                               & vlSelf->soc_top__DOT__apb_paddr))
                                        ? (IData)(vlSelf->soc_top__DOT__d_len)
                                        : ((0x10U == 
                                            (0xffU 
                                             & vlSelf->soc_top__DOT__apb_paddr))
                                            ? (((IData)(vlSelf->soc_top__DOT__u_dma_regs__DOT__err_i) 
                                                << 2U) 
                                               | (IData)(vlSelf->soc_top__DOT__dma_busy))
                                            : 0U))))),32);
    bufp->chgIData(oldp+1103,((((IData)(vlSelf->soc_top__DOT__instr_req) 
                                | (0U == (vlSelf->soc_top__DOT__u_mem__DOT__arb_addr 
                                          >> 0xcU)))
                                ? vlSelf->soc_top__DOT__instr_rdata
                                : vlSelf->soc_top__DOT__u_mem__DOT__ram_dout)),32);
    bufp->chgCData(oldp+1104,(vlSelf->soc_top__DOT__rst_sync),2);
    bufp->chgBit(oldp+1105,(vlSelf->soc_top__DOT__rst_n_int));
    bufp->chgBit(oldp+1106,(vlSelf->soc_top__DOT__u_core__DOT__clk));
    bufp->chgCData(oldp+1107,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__ctrl_busy) 
                                | (((0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q)) 
                                    | (IData)(vlSelf->soc_top__DOT__instr_req)) 
                                   | (0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))))
                                ? 5U : 0xaU)),4);
    bufp->chgBit(oldp+1108,(vlSelf->soc_top__DOT__u_core__DOT__core_clock_gate_i__DOT__en_latch));
    bufp->chgBit(oldp+1109,((1U & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ebrk_insn)) 
                                   & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__ecall_insn_dec)) 
                                      & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__decoder_i__DOT__illegal_insn)) 
                                         & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_csr_insn_id)) 
                                            & (~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err)))))))));
    bufp->chgBit(oldp+1110,((1U & ((~ ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__debug_mode_entering) 
                                       | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q))) 
                                   & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__u_cpuctrlsts_part_csr__DOT__rdata_q)))));
    bufp->chgBit(oldp+1111,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we)) 
                             & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q) 
                                & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id)) 
                                   & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec))))));
    bufp->chgBit(oldp+1112,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q) 
                              & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id)) 
                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec))) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_we))));
    bufp->chgBit(oldp+1113,((((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_insn_id)) 
                              & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err)) 
                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q))) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_a_dec))));
    bufp->chgBit(oldp+1114,((((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__illegal_insn_id)) 
                              & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_fetch_err)) 
                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q))) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__rf_ren_b_dec))));
    bufp->chgBit(oldp+1115,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_req) 
                              | (0U != (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_cs))) 
                             & (0U == (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__ls_fsm_ns)))));
    bufp->chgBit(oldp+1116,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__perf_instr_ret_wb) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_is_compressed_id))));
    bufp->chgBit(oldp+1117,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_in_ready))));
    bufp->chgCData(oldp+1118,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_we)
                                ? (5U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wdata_int)
                                : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__mcountinhibit_q))),3);
    bufp->chgBit(oldp+1119,(((3U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                     >> 0x1eU)) & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr))));
    bufp->chgCData(oldp+1120,((0x1fU & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id)
                                         ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex
                                         : (- vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__alu_operand_b_ex)))),6);
    bufp->chgBit(oldp+1121,(((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_valid_clear)) 
                             & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__g_branch_set_flop__DOT__branch_set_raw_q) 
                                | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__branch_jump_set_done_q) 
                                   | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__jump_set_raw))))));
    bufp->chgBit(oldp+1122,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q) 
                             & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__lsu_req_dec) 
                                & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__lsu_resp_valid)) 
                                   | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_first_cycle_id))))));
    bufp->chgIData(oldp+1123,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__imm_a_mux_sel)
                                ? 0U : (0x1fU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                 >> 0xfU)))),32);
    bufp->chgBit(oldp+1124,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en) 
                             & ((~ ((0x340U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                >> 0x14U)) 
                                    | (0x341U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                  >> 0x14U)))) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr)))));
    bufp->chgCData(oldp+1125,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_insn_prio) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__ebreak_into_debug))
                                ? 1U : ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__do_single_step_d)
                                         ? 4U : 0U))),3);
    bufp->chgBit(oldp+1126,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__id_stage_i__DOT__controller_i__DOT__wfi_insn) 
                             | (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en) 
                                 & ((~ ((0x340U == 
                                         (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                          >> 0x14U)) 
                                        | (0x341U == 
                                           (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                            >> 0x14U)))) 
                                    & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr))) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)))));
    bufp->chgBit(oldp+1127,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__csr_op_en) 
                              & ((~ ((0x340U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                 >> 0x14U)) 
                                     | (0x341U == (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_rdata_id 
                                                   >> 0x14U)))) 
                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__cs_registers_i__DOT__csr_wr))) 
                             & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q))));
    bufp->chgBit(oldp+1128,(((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_new_id_d) 
                             | ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__instr_valid_clear)) 
                                & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__instr_valid_id_q)))));
    bufp->chgBit(oldp+1129,(((1U & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q) 
                             && (IData)((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                          >> 1U) & 
                                         (2U == (3U 
                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q))))))));
    bufp->chgIData(oldp+1130,((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)
                                 ? vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr
                                 : (0xfffffffcU & vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fetch_addr_q)) 
                               + ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT____VdfgTmp_hfdd8329f__0) 
                                  << 2U))),32);
    bufp->chgBit(oldp+1131,((1U & (~ (IData)((3U == 
                                              (3U & 
                                               (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                                 >> 1U) 
                                                | ((2U 
                                                    & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__rdata_outstanding_q) 
                                                         >> 1U)))))))))));
    bufp->chgIData(oldp+1132,(((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                ? ((vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_q[1U] 
                                    << 0x10U) | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                                 >> 0x10U))
                                : ((vlSelf->soc_top__DOT__instr_rdata 
                                    << 0x10U) | (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                                 >> 0x10U)))),32);
    bufp->chgBit(oldp+1133,((1U & ((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q))
                                    ? (((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unaligned_is_compressed)) 
                                        & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q) 
                                           >> 1U)) 
                                       | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q))
                                    : (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err)))));
    bufp->chgBit(oldp+1134,((IData)((((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                      >> 1U) & (2U 
                                                == 
                                                (3U 
                                                 & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__err_q)))))));
    bufp->chgBit(oldp+1135,((1U & (((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                    >> 1U) | ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_q) 
                                              & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_valid))))));
    bufp->chgIData(oldp+1136,((0x7fffffffU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                              + ((2U 
                                                  & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)) 
                                                     << 1U)) 
                                                 | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two))))),31);
    bufp->chgIData(oldp+1137,((0x7fffffffU & ((IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__pc_set)
                                               ? (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__prefetch_addr 
                                                  >> 1U)
                                               : (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__instr_addr_q 
                                                  + 
                                                  ((2U 
                                                    & ((~ (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)) 
                                                       << 1U)) 
                                                   | (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__if_stage_i__DOT__gen_prefetch_buffer__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_incr_two)))))),31);
    bufp->chgIData(oldp+1138,(((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                ? ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                    ? ((vlSelf->soc_top__DOT__cpu_rdata 
                                        << 8U) | (0xffU 
                                                  & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                                     >> 0x10U)))
                                    : ((vlSelf->soc_top__DOT__cpu_rdata 
                                        << 0x10U) | 
                                       (0xffffU & (vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q 
                                                   >> 8U))))
                                : ((1U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                    ? ((vlSelf->soc_top__DOT__cpu_rdata 
                                        << 0x18U) | vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_q)
                                    : vlSelf->soc_top__DOT__cpu_rdata))),32);
    bufp->chgIData(oldp+1139,(((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
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
    bufp->chgIData(oldp+1140,(((2U & (IData)(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__load_store_unit_i__DOT__rdata_offset_q))
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
    bufp->chgIData(oldp+1141,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__wb_stage_i__DOT__rf_wdata_wb_mux[0]),32);
    bufp->chgIData(oldp+1142,(vlSelf->soc_top__DOT__u_core__DOT__u_ibex_core__DOT__wb_stage_i__DOT__rf_wdata_wb_mux[1]),32);
}

void Vsoc_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_cleanup\n"); );
    // Init
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
}
