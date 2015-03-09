/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Reg/Reg.h>
#include "mcal_cpu.h"

void mcal::cpu::init(const mcal::cpu::config_type*)
{
  // Reset the rcc clock configuration to the default reset state
  // Set the hsion bit.
  util::dma<uint32,
            uint32>::reg_or(mcal::reg::rcc_cr,
                    UINT32_C(0x00000001));

 // Reset the rcc_cfgr register.
  util::dma<uint32,
            uint32>::reg_set(mcal::reg::rcc_cfgr,
                             UINT32_C(0));

  // Clear the hseon, the csson, and the pllon bits.
  util::dma<uint32,
            uint32>::reg_and(mcal::reg::rcc_cr,
                             UINT32_C(0xFEF6FFFF));

 // Reset the pllcfgr register.
  util::dma<uint32,
            uint32>::reg_set(mcal::reg::rcc_pllcfgr,
                             UINT32_C(0x24003010));

  // Reset the hsebyp bit.
  util::dma<uint32,
            uint32>::reg_and(mcal::reg::rcc_cr,
                             UINT32_C(0xFFFBFFFF));

  // Disable all interrupts.
  util::dma<uint32,
            uint32>::reg_set(mcal::reg::rcc_cir,
                             UINT32_C(0));

  // Configure the flash memory.
  // Set 5 wait states.
  // Activate the flash prefetch.
  // Activate the instruction cache.
  // Activate the data cache.
  util::dma<uint32,
            uint32>::reg_set(mcal::reg::flash_acr,
                             UINT32_C(5) | UINT32_C(0x00000700));

 // Enable the power interface clock.
  util::dma<uint32,
            uint32>::reg_or(mcal::reg::rcc_apb1enr,
                            UINT32_C(0x10000000));

  // Select the regulator voltage scaling output to scale 1 mode.
  util::dma<uint32,
            uint32>::reg_or(mcal::reg::pwr_cr,
                            UINT32_C(0x00004000));

  // Relocate the vector table to internal flash.
  util::dma<uint32, uint32>::reg_set(mcal::reg::scb_vtor, UINT32_C(0x08000000));
}
