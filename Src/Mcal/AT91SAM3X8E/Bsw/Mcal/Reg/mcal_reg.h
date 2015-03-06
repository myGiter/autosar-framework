/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef MCAL_REG_2015_01_30_H
  #define MCAL_REG_2015_01_30_H

  #include <Bsw/Common/Std_Types.h>

  namespace mcal
  {
    namespace reg
    {

      // Global base addresses.
      constexpr std::uint32_t pmc_base     = UINT32_C(0x400E0600);

      // System registers.
//      constexpr std::uint32_t scb_vtor  = static_cast<std::uint32_t>(0xE000ED08UL);   // 32-bit register.
//      constexpr std::uint32_t aircr     = static_cast<std::uint32_t>(0xE000ED0CUL);   // 32-bit register. SCB application interrupt / reset control.

      // Interrupt registers.
//      constexpr std::uint32_t rcc_cr    = static_cast<std::uint32_t>(0x40021000UL);   // 32-bit register.
//      constexpr std::uint32_t rcc_cfgr  = static_cast<std::uint32_t>(0x40021004UL);   // 32-bit register.
//      constexpr std::uint32_t rcc_cir   = static_cast<std::uint32_t>(0x40021008UL);   // 32-bit register.
//      constexpr std::uint32_t rcc_cfgr2 = static_cast<std::uint32_t>(0x4002102CUL);   // 32-bit register.

      // Port registers.
//      constexpr std::uint32_t gpioa_crl  = static_cast<std::uint32_t>(0x40010800UL);   // 32-bit register.
//      constexpr std::uint32_t gpioa_crh  = static_cast<std::uint32_t>(0x40010804UL);   // 32-bit register.
//      constexpr std::uint32_t gpioa_idr  = static_cast<std::uint32_t>(0x40010808UL);   // 32-bit register.
//      constexpr std::uint32_t gpioa_odr  = static_cast<std::uint32_t>(0x4001080CUL);   // 32-bit register.
//      constexpr std::uint32_t gpioa_bsrr = static_cast<std::uint32_t>(0x40010810UL);   // 32-bit register.
//      constexpr std::uint32_t gpioa_brr  = static_cast<std::uint32_t>(0x40010814UL);   // 32-bit register.

      constexpr std::uint32_t piob_per   = static_cast<std::uint32_t>(0x400E1000UL);   // 32-bit register.
      constexpr std::uint32_t piob_pdr   = static_cast<std::uint32_t>(0x400E1004UL);   // 32-bit register.
      constexpr std::uint32_t piob_psr   = static_cast<std::uint32_t>(0x400E1008UL);   // 32-bit register.
      constexpr std::uint32_t piob_oer   = static_cast<std::uint32_t>(0x400E1010UL);   // 32-bit register.
      constexpr std::uint32_t piob_odr   = static_cast<std::uint32_t>(0x400E1014UL);   // 32-bit register.
      constexpr std::uint32_t piob_osr   = static_cast<std::uint32_t>(0x400E1018UL);   // 32-bit register.
      constexpr std::uint32_t piob_ifer  = static_cast<std::uint32_t>(0x400E1020UL);   // 32-bit register.
      constexpr std::uint32_t piob_ifdr  = static_cast<std::uint32_t>(0x400E1024UL);   // 32-bit register.
      constexpr std::uint32_t piob_ifsr  = static_cast<std::uint32_t>(0x400E1028UL);   // 32-bit register.
      constexpr std::uint32_t piob_sodr  = static_cast<std::uint32_t>(0x400E1030UL);   // 32-bit register.
      constexpr std::uint32_t piob_codr  = static_cast<std::uint32_t>(0x400E1034UL);   // 32-bit register.
      constexpr std::uint32_t piob_pdsr  = static_cast<std::uint32_t>(0x400E1038UL);   // 32-bit register.
      constexpr std::uint32_t piob_ier   = static_cast<std::uint32_t>(0x400E1040UL);   // 32-bit register.
      constexpr std::uint32_t piob_idr   = static_cast<std::uint32_t>(0x400E1044UL);   // 32-bit register.
//      constexpr std::uint32_t piob_imr   = static_cast<std::uint32_t>(0x400E1048UL);   // 32-bit register.
//      constexpr std::uint32_t piob_isr   = static_cast<std::uint32_t>(0x400E1050UL);   // 32-bit register.
//      constexpr std::uint32_t piob_mder   = static_cast<std::uint32_t>(0x400E1054UL);   // 32-bit register.
//      constexpr std::uint32_t piob_mddr   = static_cast<std::uint32_t>(0x400E1058UL);   // 32-bit register.
//      constexpr std::uint32_t piob_mdsr   = static_cast<std::uint32_t>(0x400E1058UL);   // 32-bit register.
       constexpr std::uint32_t piob_pudr   = static_cast<std::uint32_t>(0x400E1060UL);   // 32-bit register.
       constexpr std::uint32_t piob_puer   = static_cast<std::uint32_t>(0x400E1064UL);   // 32-bit register.
//      constexpr std::uint32_t piob_pusr   = static_cast<std::uint32_t>(0x400E1068UL);   // 32-bit register.
//      constexpr std::uint32_t piob_absr   = static_cast<std::uint32_t>(0x400E1070UL);   // 32-bit register.
//      constexpr std::uint32_t piob_scifsr   = static_cast<std::uint32_t>(0x400E1074UL);   // 32-bit register.
//      constexpr std::uint32_t piob_difsr   = static_cast<std::uint32_t>(0x400E1078UL);   // 32-bit register.
//      constexpr std::uint32_t piob_ifdgsr   = static_cast<std::uint32_t>(0x400E1080UL);   // 32-bit register.
//      constexpr std::uint32_t piob_scdr   = static_cast<std::uint32_t>(0x400E1084UL);   // 32-bit register.
//      constexpr std::uint32_t piob_ower   = static_cast<std::uint32_t>(0x400E1088UL);   // 32-bit register.
//      constexpr std::uint32_t piob_owdr   = static_cast<std::uint32_t>(0x400E1090UL);   // 32-bit register.
//      constexpr std::uint32_t piob_owsr   = static_cast<std::uint32_t>(0x400E1094UL);   // 32-bit register.
//      constexpr std::uint32_t piob_aimer   = static_cast<std::uint32_t>(0x400E1098UL);   // 32-bit register.
//      constexpr std::uint32_t piob_aimdr   = static_cast<std::uint32_t>(0x400E10A0UL);   // 32-bit register.
//      constexpr std::uint32_t piob_aimmr   = static_cast<std::uint32_t>(0x400E10A4UL);   // 32-bit register.
//      constexpr std::uint32_t piob_esr   = static_cast<std::uint32_t>(0x400E10A8UL);   // 32-bit register.
//      constexpr std::uint32_t piob_lsr   = static_cast<std::uint32_t>(0x400E10B0UL);   // 32-bit register.
//      constexpr std::uint32_t piob_elsr   = static_cast<std::uint32_t>(0x400E10B4UL);   // 32-bit register.
//      constexpr std::uint32_t piob_fellsr   = static_cast<std::uint32_t>(0x400E10B8UL);   // 32-bit register.
//      constexpr std::uint32_t piob_rehlsr   = static_cast<std::uint32_t>(0x400E10C0UL);   // 32-bit register.
//      constexpr std::uint32_t piob_xxx   = static_cast<std::uint32_t>(0x400E10C4UL);   // 32-bit register.
//      constexpr std::uint32_t piob_xxx   = static_cast<std::uint32_t>(0x400E10C8UL);   // 32-bit register.
//      constexpr std::uint32_t piob_xxx   = static_cast<std::uint32_t>(0x400E10D0UL);   // 32-bit register.
//      constexpr std::uint32_t piob_xxx   = static_cast<std::uint32_t>(0x400E10D4UL);   // 32-bit register.
//      constexpr std::uint32_t piob_xxx   = static_cast<std::uint32_t>(0x400E10D8UL);   // 32-bit register.
//      constexpr std::uint32_t piob_xxx   = static_cast<std::uint32_t>(0x400E10E0UL);   // 32-bit register.
      constexpr std::uint32_t piob_wpmr  = static_cast<std::uint32_t>(0x400E10E4UL);   // 32-bit register.
      constexpr std::uint32_t piob_wpsr  = static_cast<std::uint32_t>(0x400E10E8UL);   // 32-bit register.

//      constexpr std::uint32_t gpioc_crl  = static_cast<std::uint32_t>(0x40011000UL);   // 32-bit register.
//      constexpr std::uint32_t gpioc_crh  = static_cast<std::uint32_t>(0x40011004UL);   // 32-bit register.
//      constexpr std::uint32_t gpioc_idr  = static_cast<std::uint32_t>(0x40011008UL);   // 32-bit register.
//      constexpr std::uint32_t gpioc_odr  = static_cast<std::uint32_t>(0x4001100CUL);   // 32-bit register.
//      constexpr std::uint32_t gpioc_bsrr = static_cast<std::uint32_t>(0x40011010UL);   // 32-bit register.
//      constexpr std::uint32_t gpioc_brr = static_cast<std::uint32_t>(0x40011014UL);   // 32-bit register.

//      constexpr std::uint32_t gpiod_crl  = static_cast<std::uint32_t>(0x40011400UL);   // 32-bit register.
//      constexpr std::uint32_t gpiod_crh  = static_cast<std::uint32_t>(0x40011404UL);   // 32-bit register.
//      constexpr std::uint32_t gpiod_idr  = static_cast<std::uint32_t>(0x40011408UL);   // 32-bit register.
//      constexpr std::uint32_t gpiod_odr  = static_cast<std::uint32_t>(0x4001140CUL);   // 32-bit register.
//      constexpr std::uint32_t gpiod_bsrr = static_cast<std::uint32_t>(0x40011410UL);   // 32-bit register.
//      constexpr std::uint32_t gpiod_brr  = static_cast<std::uint32_t>(0x40011414UL);   // 32-bit register.

      // Power Management Controller.pmc_base
      constexpr std::uint32_t pmc_scer      = pmc_base + UINT32_C(0x0000);               // 32-bit register.
      constexpr std::uint32_t pmc_scdr      = pmc_base + UINT32_C(0x0004);               // 32-bit register.
      constexpr std::uint32_t pmc_scsr      = pmc_base + UINT32_C(0x0008);               // 32-bit register.
      constexpr std::uint32_t pmc_pcer0     = pmc_base + UINT32_C(0x0010);               // 32-bit register.
      constexpr std::uint32_t pmc_pcdr0     = pmc_base + UINT32_C(0x0014);               // 32-bit register.
      constexpr std::uint32_t pmc_pcsr0     = pmc_base + UINT32_C(0x0018);               // 32-bit register.
      constexpr std::uint32_t ckgr_uckr     = pmc_base + UINT32_C(0x001C);               // 32-bit register.
      constexpr std::uint32_t ckgr_mor      = pmc_base + UINT32_C(0x0020);               // 32-bit register.
      constexpr std::uint32_t ckgr_mcfr     = pmc_base + UINT32_C(0x0024);               // 32-bit register.
      constexpr std::uint32_t ckgr_pllar    = pmc_base + UINT32_C(0x0028);               // 32-bit register.
      constexpr std::uint32_t pmc_mckr      = pmc_base + UINT32_C(0x0030);               // 32-bit register.
      constexpr std::uint32_t pmc_usb       = pmc_base + UINT32_C(0x0038);               // 32-bit register.
      constexpr std::uint32_t pmc_pck0      = pmc_base + UINT32_C(0x0040);               // 32-bit register.
      constexpr std::uint32_t pmc_pck1      = pmc_base + UINT32_C(0x0044);               // 32-bit register.
      constexpr std::uint32_t pmc_pck2      = pmc_base + UINT32_C(0x0048);               // 32-bit register.
      constexpr std::uint32_t pmc_ier       = pmc_base + UINT32_C(0x0060);               // 32-bit register.
      constexpr std::uint32_t pmc_idr       = pmc_base + UINT32_C(0x0064);               // 32-bit register.
      constexpr std::uint32_t pmc_sr        = pmc_base + UINT32_C(0x0068);               // 32-bit register.
      constexpr std::uint32_t pmc_imr       = pmc_base + UINT32_C(0x006C);               // 32-bit register.
      constexpr std::uint32_t pmc_fsmr      = pmc_base + UINT32_C(0x0070);               // 32-bit register.
      constexpr std::uint32_t pmc_fspr      = pmc_base + UINT32_C(0x0074);               // 32-bit register.
      constexpr std::uint32_t pmc_focr      = pmc_base + UINT32_C(0x0078);               // 32-bit register.
      constexpr std::uint32_t pmc_wpmr      = pmc_base + UINT32_C(0x00E4);               // 32-bit register.
      constexpr std::uint32_t pmc_wpsr      = pmc_base + UINT32_C(0x00E8);               // 32-bit register.
      constexpr std::uint32_t pmc_pcer1     = pmc_base + UINT32_C(0x0100);               // 32-bit register.
      constexpr std::uint32_t pmc_pcdr1     = pmc_base + UINT32_C(0x0104);               // 32-bit register.
      constexpr std::uint32_t pmc_pcsr1     = pmc_base + UINT32_C(0x0108);               // 32-bit register.
      constexpr std::uint32_t pmc_pcr       = pmc_base + UINT32_C(0x010C);               // 32-bit register.

      // System timer registers.
      constexpr std::uint32_t systick_ctrl  = static_cast<std::uint32_t>(0xE000E010UL);   // 32-bit register.
      constexpr std::uint32_t systick_load  = static_cast<std::uint32_t>(0xE000E014UL);   // 32-bit register.
      constexpr std::uint32_t systick_val   = static_cast<std::uint32_t>(0xE000E018UL);   // 32-bit register.
      constexpr std::uint32_t systick_calib = static_cast<std::uint32_t>(0xE000E01CUL);   // 32-bit register.

      // Timer registers.
      constexpr uint32 tc_ccr0_c0           = UINT32_C(0x40080000);                      // 32-bit register.
      constexpr uint32 tc_ccr1_c0           = UINT32_C(0x40080040);                      // 32-bit register.
      constexpr uint32 tc_ccr2_c0           = UINT32_C(0x40080080);                      // 32-bit register.
      constexpr uint32 tc_ccr0_c1           = UINT32_C(0x40084000);                      // 32-bit register.
      constexpr uint32 tc_ccr1_c1           = UINT32_C(0x40084040);                      // 32-bit register.
      constexpr uint32 tc_ccr2_c1           = UINT32_C(0x40084080);                      // 32-bit register.
      constexpr uint32 tc_ccr0_c2           = UINT32_C(0x40088000);                      // 32-bit register.
      constexpr uint32 tc_ccr1_c2           = UINT32_C(0x40088040);                      // 32-bit register.
      constexpr uint32 tc_ccr2_c2           = UINT32_C(0x40088080);                      // 32-bit register.

      constexpr uint32 tc_cv0_c0           = UINT32_C(0x40080010);                      // 32-bit register.
      constexpr uint32 tc_cv1_c0           = UINT32_C(0x40080050);                      // 32-bit register.
      constexpr uint32 tc_cv2_c0           = UINT32_C(0x40080090);                      // 32-bit register.
      constexpr uint32 tc_cv0_c1           = UINT32_C(0x40084010);                      // 32-bit register.
      constexpr uint32 tc_cv1_c1           = UINT32_C(0x40084050);                      // 32-bit register.
      constexpr uint32 tc_cv2_c1           = UINT32_C(0x40084090);                      // 32-bit register.
      constexpr uint32 tc_cv0_c2           = UINT32_C(0x40088010);                      // 32-bit register.
      constexpr uint32 tc_cv1_c2           = UINT32_C(0x40088050);                      // 32-bit register.
      constexpr uint32 tc_cv2_c2           = UINT32_C(0x40088090);                      // 32-bit register.

      constexpr uint32 tc_ier0_c0          = UINT32_C(0x40080024);                      // 32-bit register.
      constexpr uint32 tc_ier1_c0          = UINT32_C(0x40080064);                      // 32-bit register.
      constexpr uint32 tc_ier2_c0          = UINT32_C(0x400800A4);                      // 32-bit register.
      constexpr uint32 tc_ier0_c1          = UINT32_C(0x40084024);                      // 32-bit register.
      constexpr uint32 tc_ier1_c1          = UINT32_C(0x40084064);                      // 32-bit register.
      constexpr uint32 tc_ier2_c1          = UINT32_C(0x400840A4);                      // 32-bit register.
      constexpr uint32 tc_ier0_c2          = UINT32_C(0x40088024);                      // 32-bit register.
      constexpr uint32 tc_ier1_c2          = UINT32_C(0x40088064);                      // 32-bit register.
      constexpr uint32 tc_ier2_c2          = UINT32_C(0x400880A4);                      // 32-bit register.

      constexpr uint32 tc_cmr0_c0          = UINT32_C(0x40080004);                      // 32-bit register.
      constexpr uint32 tc_cmr1_c0          = UINT32_C(0x40080044);                      // 32-bit register.
      constexpr uint32 tc_cmr2_c0          = UINT32_C(0x40080084);                      // 32-bit register.
      constexpr uint32 tc_cmr0_c1          = UINT32_C(0x40084004);                      // 32-bit register.
      constexpr uint32 tc_cmr1_c1          = UINT32_C(0x40084044);                      // 32-bit register.
      constexpr uint32 tc_cmr2_c1          = UINT32_C(0x40084084);                      // 32-bit register.
      constexpr uint32 tc_cmr0_c2          = UINT32_C(0x40088004);                      // 32-bit register.
      constexpr uint32 tc_cmr1_c2          = UINT32_C(0x40088044);                      // 32-bit register.
      constexpr uint32 tc_cmr2_c2          = UINT32_C(0x40088084);                      // 32-bit register.

//      constexpr std::uint32_t tim4_cr1   = static_cast<std::uint32_t>(0x40000800UL);  // 16-bit register.
//      constexpr std::uint32_t tim4_cr2   = static_cast<std::uint32_t>(0x40000804UL);  // 16-bit register.
//      constexpr std::uint32_t tim4_smcr  = static_cast<std::uint32_t>(0x40000808UL);  // 16-bit register.
//      constexpr std::uint32_t tim4_dier  = static_cast<std::uint32_t>(0x4000080CUL);  // 16-bit register.
//      constexpr std::uint32_t tim4_sr    = static_cast<std::uint32_t>(0x40000810UL);  // 16-bit register.
//      constexpr std::uint32_t tim4_egr   = static_cast<std::uint32_t>(0x40000814UL);  // 16-bit register.
//      constexpr std::uint32_t tim4_ccmr1 = static_cast<std::uint32_t>(0x40000818UL);  // 16-bit register.
//      constexpr std::uint32_t tim4_ccmr2 = static_cast<std::uint32_t>(0x4000081CUL);  // 16-bit register.
//      constexpr std::uint32_t tim4_ccer  = static_cast<std::uint32_t>(0x40000820UL);  // 16-bit register.
//      constexpr std::uint32_t tim4_cnt   = static_cast<std::uint32_t>(0x40000824UL);  // 16-bit register.
//      constexpr std::uint32_t tim4_psc   = static_cast<std::uint32_t>(0x40000828UL);  // 16-bit register.
//      constexpr std::uint32_t tim4_arr   = static_cast<std::uint32_t>(0x4000082CUL);  // 16-bit register.
//      constexpr std::uint32_t tim4_rcr   = static_cast<std::uint32_t>(0x40000830UL);  // 16-bit register.

      // Power management registers.
//      constexpr std::uint32_t rcc_apbenr  = static_cast<std::uint32_t>(0x40021014UL); // 32-bit register.
//      constexpr std::uint32_t rcc_apb2enr = static_cast<std::uint32_t>(0x40021018UL); // 32-bit register.
//      constexpr std::uint32_t rcc_apb1enr = static_cast<std::uint32_t>(0x4002101CUL); // 32-bit register.

      // CAN control and status registers (CAN 1 only).
//      constexpr std::uint32_t can_mcr     = static_cast<std::uint32_t>(0x40006400UL); // 32-bit register.
//      constexpr std::uint32_t can_msr     = static_cast<std::uint32_t>(0x40006404UL); // 32-bit register.
//      constexpr std::uint32_t can_tsr     = static_cast<std::uint32_t>(0x40006408UL); // 32-bit register.
//      constexpr std::uint32_t can_rf0r    = static_cast<std::uint32_t>(0x4000640CUL); // 32-bit register.
//      constexpr std::uint32_t can_rf1r    = static_cast<std::uint32_t>(0x40006410UL); // 32-bit register.
//      constexpr std::uint32_t can_ier     = static_cast<std::uint32_t>(0x40006414UL); // 32-bit register.
//      constexpr std::uint32_t can_esr     = static_cast<std::uint32_t>(0x40006418UL); // 32-bit register.
//      constexpr std::uint32_t can_btr     = static_cast<std::uint32_t>(0x4000641CUL); // 32-bit register.
//      constexpr std::uint32_t can_ti0r    = static_cast<std::uint32_t>(0x40006580UL); // 32-bit register.
//      constexpr std::uint32_t can_tdt0r   = static_cast<std::uint32_t>(0x40006584UL); // 32-bit register.
//      constexpr std::uint32_t can_tdl0r   = static_cast<std::uint32_t>(0x40006588UL); // 32-bit register.
//      constexpr std::uint32_t can_tdh0r   = static_cast<std::uint32_t>(0x4000658CUL); // 32-bit register.
//      constexpr std::uint32_t can_ti1r    = static_cast<std::uint32_t>(0x40006590UL); // 32-bit register.
//      constexpr std::uint32_t can_tdt1r   = static_cast<std::uint32_t>(0x40006594UL); // 32-bit register.
//      constexpr std::uint32_t can_tdl1r   = static_cast<std::uint32_t>(0x40006598UL); // 32-bit register.
//      constexpr std::uint32_t can_tdh1r   = static_cast<std::uint32_t>(0x4000659CUL); // 32-bit register.
//      constexpr std::uint32_t can_ti2r    = static_cast<std::uint32_t>(0x400065A0UL); // 32-bit register.
//      constexpr std::uint32_t can_tdt2r   = static_cast<std::uint32_t>(0x400065A4UL); // 32-bit register.
//      constexpr std::uint32_t can_tdl2r   = static_cast<std::uint32_t>(0x400065A8UL); // 32-bit register.
//      constexpr std::uint32_t can_tdh2r   = static_cast<std::uint32_t>(0x400065ACUL); // 32-bit register.
//      constexpr std::uint32_t can_ri0r    = static_cast<std::uint32_t>(0x400065B0UL); // 32-bit register.
//      constexpr std::uint32_t can_rtd0r   = static_cast<std::uint32_t>(0x400065B4UL); // 32-bit register.
//      constexpr std::uint32_t can_rdl0r   = static_cast<std::uint32_t>(0x400065B8UL); // 32-bit register.
//      constexpr std::uint32_t can_rdh0r   = static_cast<std::uint32_t>(0x400065BCUL); // 32-bit register.
//      constexpr std::uint32_t can_ri1r    = static_cast<std::uint32_t>(0x400065C0UL); // 32-bit register.
//      constexpr std::uint32_t can_rtd1r   = static_cast<std::uint32_t>(0x400065C4UL); // 32-bit register.
//      constexpr std::uint32_t can_rdl1r   = static_cast<std::uint32_t>(0x400065C8UL); // 32-bit register.
//      constexpr std::uint32_t can_rdh1r   = static_cast<std::uint32_t>(0x400065CCUL); // 32-bit register.
//      constexpr std::uint32_t can_fmr     = static_cast<std::uint32_t>(0x40006600UL); // 32-bit register.
//      constexpr std::uint32_t can_fm1r    = static_cast<std::uint32_t>(0x40006604UL); // 32-bit register.
//      constexpr std::uint32_t can_fs1r    = static_cast<std::uint32_t>(0x4000660CUL); // 32-bit register.
//      constexpr std::uint32_t can_ffa1r   = static_cast<std::uint32_t>(0x40006614UL); // 32-bit register.
//      constexpr std::uint32_t can_fa1r    = static_cast<std::uint32_t>(0x4000661CUL); // 32-bit register.
//      constexpr std::uint32_t can_f0r1    = static_cast<std::uint32_t>(0x40006640UL); // 32-bit register.
//      constexpr std::uint32_t can_f0r2    = static_cast<std::uint32_t>(0x40006644UL); // 32-bit register.
//      constexpr std::uint32_t can_f1r1    = static_cast<std::uint32_t>(0x40006648UL); // 32-bit register.
//      constexpr std::uint32_t can_f1r2    = static_cast<std::uint32_t>(0x4000664CUL); // 32-bit register.
//      constexpr std::uint32_t can_f2r1    = static_cast<std::uint32_t>(0x40006650UL); // 32-bit register.
//      constexpr std::uint32_t can_f2r2    = static_cast<std::uint32_t>(0x40006654UL); // 32-bit register.
//      constexpr std::uint32_t can_f3r1    = static_cast<std::uint32_t>(0x40006658UL); // 32-bit register.
//      constexpr std::uint32_t can_f3r2    = static_cast<std::uint32_t>(0x4000665CUL); // 32-bit register.
//      constexpr std::uint32_t can_f4r1    = static_cast<std::uint32_t>(0x40006660UL); // 32-bit register.
//      constexpr std::uint32_t can_f4r2    = static_cast<std::uint32_t>(0x40006664UL); // 32-bit register.
//      constexpr std::uint32_t can_f5r1    = static_cast<std::uint32_t>(0x40006668UL); // 32-bit register.
//      constexpr std::uint32_t can_f5r2    = static_cast<std::uint32_t>(0x4000666CUL); // 32-bit register.
//      constexpr std::uint32_t can_f6r1    = static_cast<std::uint32_t>(0x40006670UL); // 32-bit register.
//      constexpr std::uint32_t can_f6r2    = static_cast<std::uint32_t>(0x40006674UL); // 32-bit register.
//      constexpr std::uint32_t can_f7r1    = static_cast<std::uint32_t>(0x40006678UL); // 32-bit register.
//      constexpr std::uint32_t can_f7r2    = static_cast<std::uint32_t>(0x4000667CUL); // 32-bit register.
//      constexpr std::uint32_t can_f8r1    = static_cast<std::uint32_t>(0x40006680UL); // 32-bit register.
//      constexpr std::uint32_t can_f8r2    = static_cast<std::uint32_t>(0x40006684UL); // 32-bit register.
//      constexpr std::uint32_t can_f9r1    = static_cast<std::uint32_t>(0x40006688UL); // 32-bit register.
//      constexpr std::uint32_t can_f9r2    = static_cast<std::uint32_t>(0x4000668CUL); // 32-bit register.
//      constexpr std::uint32_t can_f10r1   = static_cast<std::uint32_t>(0x40006690UL); // 32-bit register.
//      constexpr std::uint32_t can_f10r2   = static_cast<std::uint32_t>(0x40006694UL); // 32-bit register.
//      constexpr std::uint32_t can_f11r1   = static_cast<std::uint32_t>(0x40006698UL); // 32-bit register.
//      constexpr std::uint32_t can_f11r2   = static_cast<std::uint32_t>(0x4000669CUL); // 32-bit register.
//      constexpr std::uint32_t can_f12r1   = static_cast<std::uint32_t>(0x400066A0UL); // 32-bit register.
//      constexpr std::uint32_t can_f12r2   = static_cast<std::uint32_t>(0x400066A4UL); // 32-bit register.
//      constexpr std::uint32_t can_f13r1   = static_cast<std::uint32_t>(0x400066A8UL); // 32-bit register.
//      constexpr std::uint32_t can_f13r2   = static_cast<std::uint32_t>(0x400066ACUL); // 32-bit register.
//      constexpr std::uint32_t can_f14r1   = static_cast<std::uint32_t>(0x400066B0UL); // 32-bit register.
//      constexpr std::uint32_t can_f14r2   = static_cast<std::uint32_t>(0x400066B4UL); // 32-bit register.
//      constexpr std::uint32_t can_f15r1   = static_cast<std::uint32_t>(0x400066B8UL); // 32-bit register.
//      constexpr std::uint32_t can_f15r2   = static_cast<std::uint32_t>(0x400066BCUL); // 32-bit register.
//      constexpr std::uint32_t can_f16r1   = static_cast<std::uint32_t>(0x400066C0UL); // 32-bit register.
//      constexpr std::uint32_t can_f16r2   = static_cast<std::uint32_t>(0x400066C4UL); // 32-bit register.
//      constexpr std::uint32_t can_f17r1   = static_cast<std::uint32_t>(0x400066C8UL); // 32-bit register.
//      constexpr std::uint32_t can_f17r2   = static_cast<std::uint32_t>(0x400066CCUL); // 32-bit register.
//      constexpr std::uint32_t can_f18r1   = static_cast<std::uint32_t>(0x400066D0UL); // 32-bit register.
//      constexpr std::uint32_t can_f18r2   = static_cast<std::uint32_t>(0x400066D4UL); // 32-bit register.
//      constexpr std::uint32_t can_f19r1   = static_cast<std::uint32_t>(0x400066D8UL); // 32-bit register.
//      constexpr std::uint32_t can_f19r2   = static_cast<std::uint32_t>(0x400066DCUL); // 32-bit register.
//      constexpr std::uint32_t can_f20r1   = static_cast<std::uint32_t>(0x400066E0UL); // 32-bit register.
//      constexpr std::uint32_t can_f20r2   = static_cast<std::uint32_t>(0x400066E4UL); // 32-bit register.
//      constexpr std::uint32_t can_f21r1   = static_cast<std::uint32_t>(0x400066E8UL); // 32-bit register.
//      constexpr std::uint32_t can_f21r2   = static_cast<std::uint32_t>(0x400066ECUL); // 32-bit register.
//      constexpr std::uint32_t can_f22r1   = static_cast<std::uint32_t>(0x400066F0UL); // 32-bit register.
//      constexpr std::uint32_t can_f22r2   = static_cast<std::uint32_t>(0x400066F4UL); // 32-bit register.
//      constexpr std::uint32_t can_f23r1   = static_cast<std::uint32_t>(0x400066F8UL); // 32-bit register.
//      constexpr std::uint32_t can_f23r2   = static_cast<std::uint32_t>(0x400066FCUL); // 32-bit register.
//      constexpr std::uint32_t can_f24r1   = static_cast<std::uint32_t>(0x40006700UL); // 32-bit register.
//      constexpr std::uint32_t can_f24r2   = static_cast<std::uint32_t>(0x40006704UL); // 32-bit register.
//      constexpr std::uint32_t can_f25r1   = static_cast<std::uint32_t>(0x40006708UL); // 32-bit register.
//      constexpr std::uint32_t can_f25r2   = static_cast<std::uint32_t>(0x4000670CUL); // 32-bit register.
//      constexpr std::uint32_t can_f26r1   = static_cast<std::uint32_t>(0x40006710UL); // 32-bit register.
//      constexpr std::uint32_t can_f26r2   = static_cast<std::uint32_t>(0x40006714UL); // 32-bit register.
//      constexpr std::uint32_t can_f27r1   = static_cast<std::uint32_t>(0x40006718UL); // 32-bit register.
//      constexpr std::uint32_t can_f27r2   = static_cast<std::uint32_t>(0x4000671CUL); // 32-bit register.

      // Independet watchdog registers.
      constexpr uint32 wdt_cr             = UINT32_C(0x400E1A50);                     // 32-bit register.
      constexpr uint32 wdt_mr             = UINT32_C(0x400E1A54);                     // 32-bit register.
      constexpr uint32 iwdg_rlr    = static_cast<std::uint32_t>(0x40003008UL); // 32-bit register.
    }
  }
#endif // MCAL_REG_2015_01_30_H
