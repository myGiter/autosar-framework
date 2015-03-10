/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Reg/Reg.h>
#include <Bsw/Mcal/Wdg/Wdg.h>

EXTERN_C
void Wdg_Init(const Wdg_ConfigType* WdgConfig)
{
  static_cast<void>(WdgConfig);
  // Write access to the IWDG_PR and IWDG_RLR registers is protected
  // Register access  unlock protection
  util::dma<uint32, uint32>::reg_set(mcal::reg::iwdg_kr, UINT32_C(0x00005555));

  // Set the prescaler to 1/4 (with a register value of 0).
  util::dma<uint32, uint32>::reg_set(mcal::reg::iwdg_pr, UINT32_C(0x00000000));

  // Register Reload set to 500 for a watchdog period of approximately 50ms.
  util::dma<uint32, uint32>::reg_set(mcal::reg::iwdg_rlr, UINT32_C(0x28A));

  // Start the watchdog and lock the access protection.
  util::dma<uint32, uint32>::reg_set(mcal::reg::iwdg_kr, UINT32_C(0x0000CCCC));

  // Read the status register.
  volatile const uint32 dummy_read = util::dma<uint32, uint32>::reg_get(mcal::reg::iwdg_sr);
  static_cast<void>(dummy_read);
}

EXTERN_C
void Wdg_Trigger(void)
{
  // Reload the watchdog counter with value in iwdg_rlr
  util::dma<uint32, uint32>::reg_set(mcal::reg::iwdg_kr, UINT32_C(0x0000AAAA));
}
