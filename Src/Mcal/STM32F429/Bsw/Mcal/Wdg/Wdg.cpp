/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
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
  util::dma<std::uint32_t, std::uint32_t>::reg_set(mcal::reg::iwdg_kr,  0x00005555UL);

  // Set the prescaler to 1/4 (with a register value of 0).
  util::dma<std::uint32_t, std::uint32_t>::reg_set(mcal::reg::iwdg_pr,  0x00000000UL);

  // Register Reload set to 500 for a watchdog period of approximately 50ms.
  util::dma<std::uint32_t, std::uint32_t>::reg_set(mcal::reg::iwdg_rlr, 500UL);

  // Start the watchdog and lock the access protection.
  util::dma<std::uint32_t, std::uint32_t>::reg_set(mcal::reg::iwdg_kr,  0x0000CCCCUL);

  // Read the status register.
  volatile const std::uint32_t dummy_read = util::dma<std::uint32_t, std::uint32_t>::reg_get(mcal::reg::iwdg_sr);
  static_cast<void>(dummy_read);

}

EXTERN_C
void Wdg_Trigger(void)
{
  // Reload the watchdog counter with value in iwdg_rlr
  util::dma<std::uint32_t, std::uint32_t>::reg_set(mcal::reg::iwdg_kr,  0x0000AAAAUL);
}
