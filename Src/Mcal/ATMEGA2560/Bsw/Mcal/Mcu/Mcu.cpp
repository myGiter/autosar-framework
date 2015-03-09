/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
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
}

EXTERN_C
Std_ReturnType Mcu_InitClock(Mcu_ClockType McuClock)
{
  static_cast<void>(McuClock);

  // Only Programmable via Fuses:
  // The device is shipped with internal RC oscillator at 8.0MHz
  // and with the fuse CKDIV8 programmed,
  // resulting in 1.0MHz system clock

  // The Arduino Board is shipped with an External oscillator with 16.0MHz,
  // and without the fuse CKDIV8 programmed,
  // resulting in 16.0MHz system clock

  return E_OK;
}

EXTERN_C
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
  return static_cast<Mcu_PllStatusType>(MCU_PLL_LOCKED);
}

EXTERN_C
Std_ReturnType Mcu_DistributePllClock(void)
{
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
