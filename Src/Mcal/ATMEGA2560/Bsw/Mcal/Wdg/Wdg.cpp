/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Wdg/Wdg.h>
#include <Bsw/Mcal/Reg/Reg.h>
#include <Bsw/Common/Wdg/McalWdg.h>
#include <Bsw/Common/Irq/McalIrq.h>


EXTERN_C
void Wdg_Init(const Wdg_ConfigType* WdgConfig)
{
  const uint8 wdg_settings = WdgConfig->Wdg_Setting;

  mcal::irq::disable_all();
  mcal::wdg::wdg_reset();

  util::dma<uint8,
            uint8>::reg_msk(mcal::reg::mcusr, UINT8_C(0x00), UINT8_C(0x08));

  // Get Access to WDG Configuration:
  // Writing 1 to WDCE.
  util::dma<uint8,
            uint8>::reg_set(mcal::reg::wdtcsr, UINT8_C(0x10));

  util::dma<uint8,
            uint8>::reg_set(mcal::reg::wdtcsr, wdg_settings);
  mcal::irq::enable_all();
}

EXTERN_C
void Wdg_Trigger(void)
{
  mcal::wdg::wdg_reset();
}

EXTERN_C void __vector_wdt_timout_irq(void) __attribute__((signal, used, externally_visible));

void __vector_wdt_timout_irq(void)
{
  // Routine before System Reset.

}
