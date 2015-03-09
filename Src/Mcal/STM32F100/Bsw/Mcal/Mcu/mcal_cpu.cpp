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
  // Power management: Enable power for I/O porta and portc.
  util::dma<uint32, uint32>::reg_or(mcal::reg::rcc_apb2enr, 0x00000014UL);

  // Disable all interrupts and clear pending bits.
  util::dma<uint32, uint32>::reg_set(mcal::reg::rcc_cir, 0x009F0000UL);

  // Reset the cfgr2 register.
  util::dma<uint32, uint32>::reg_set(mcal::reg::rcc_cfgr2, 0x00000000UL);

  // Relocate the vector table to internal flash.
  util::dma<uint32, uint32>::reg_set(mcal::reg::scb_vtor, 0x08000000UL);
}
