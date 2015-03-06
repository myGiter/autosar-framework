/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Cpu/McalCpu.h>
#include <Bsw/Mcal/Mcu/Mcu.h>
#include <Bsw/Mcal/Reg/Reg.h>

EXTERN_C
void Mcu_Init(const Mcu_ConfigType* McuConfig)
{
  static_cast<void>(McuConfig);

  // Initialize the MCU clock.
  Mcu_InitClock(static_cast<Mcu_ClockType>(0));

  // Set and switch to Pll.
  Mcu_DistributePllClock();

  // Disable the pull-up on all ports, regardles of the other register settings.
  util::dma<uint8,
            uint8>::bit_set(mcal::reg::mcucr, UINT8_C(4));
}

EXTERN_C
Std_ReturnType Mcu_InitClock(Mcu_ClockType McuClock)
{
  static_cast<void>(McuClock);

  // Activate external Clock.
  util::dma<uint8,
            uint8>::bit_set(mcal::reg::clksel0, UINT8_C(2));

  // Wait for external clock.
  boolean dummyExt = FALSE;
  while(dummyExt != TRUE)
  {
    dummyExt = util::dma<uint8,
                         uint8>::bit_get(mcal::reg::clksta, UINT8_C(0));
  }

  // Select external Clock.
  util::dma<uint8,
            uint8>::bit_set(mcal::reg::clksel0, UINT8_C(0));

  return E_OK;
}

EXTERN_C
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
  boolean dummyPll = util::dma<uint8,
                               uint8>::bit_get(mcal::reg::pllcsr, UINT8_C(0));

  return static_cast<Mcu_PllStatusType>((dummyPll == TRUE) ? MCU_PLL_LOCKED : MCU_PLL_UNLOCKED);
}

EXTERN_C
Std_ReturnType Mcu_DistributePllClock(void)
{
  // Set Pll divide to for 16 Mhz.
  util::dma<uint8,
            uint8>::bit_set(mcal::reg::pllcsr, UINT8_C(4));

  // Set Pll prescaler.
  util::dma<uint8,
            uint8>::reg_set(mcal::reg::pllfrq, UINT8_C(0x7A));

  // Enable Pll.
  util::dma<uint8,
            uint8>::bit_set(mcal::reg::pllcsr, UINT8_C(1));

  // Disable RC Clock.
  util::dma<uint8,
            uint8>::bit_set(mcal::reg::clksel0, UINT8_C(3));

  // Wait for Pll Lock.
  while(Mcu_GetPllStatus() != MCU_PLL_LOCKED)
  {
    mcal::cpu::nop();
  }

  return E_OK;
}

EXTERN_C
Mcu_ResetType Mcu_GetResetReason(void)
{
  Mcu_ResetType reason;

  uint8 reg_reset = util::dma<uint8,
                              uint8>::reg_get(mcal::reg::mcusr);

  switch(reg_reset)
  {
    case UINT8_C(0x01):
      reason = MCU_POWER_ON_RESET;
      break;

    case UINT8_C(0x08):
      reason = MCU_WATCHDOG_RESET;
      break;

    default:
      reason = MCU_RESET_UNDEFINED;
      break;
  }

  return reason;
}
