/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Reg/Reg.h>
#include "mcal_wdg.h"

void mcal::wdg::init(const config_type*)
{
  // Write access to the IWDG_PR and IWDG_RLR registers is protected
  // Register access  unlock protection
  util::dma<uint32, uint32>::reg_set(mcal::reg::iwdg_kr, UINT32_C(0x00005555));

  // Set the prescaler to 1/4 (with a register value of 0).
  util::dma<uint32, uint32>::reg_set(mcal::reg::iwdg_pr, UINT32_C(0x00000000));

  // Register Reload set to 500 for a watchdog period of approximately 50ms.
  util::dma<uint32, uint32>::reg_set(mcal::reg::iwdg_rlr, UINT32_C(500));

  // Start the watchdog and lock the access protection.
  util::dma<uint32, uint32>::reg_set(mcal::reg::iwdg_kr, UINT32_C(0x0000CCCC));

  // Read the status register.
  volatile const uint32 dummy_read = util::dma<uint32, uint32>::reg_get(mcal::reg::iwdg_sr);
  static_cast<void>(dummy_read);
}

void mcal::wdg::trigger()
{
  // Reload the watchdog counter with value in iwdg_rlr
  util::dma<uint32, uint32>::reg_set(mcal::reg::iwdg_kr, UINT32_C(0x0000AAAA));
}
