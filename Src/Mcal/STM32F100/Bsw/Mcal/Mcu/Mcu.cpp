/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Cpu/McalCpu.h>
#include <Bsw/Common/Pwr/McalPwr.h>
#include <Bsw/Mcal/Mcu/Mcu.h>
#include <Bsw/Mcal/Wdg/Wdg.h>
#include "mcal_cpu.h"
#include "mcal_osc.h"

EXTERN_C
void Mcu_Init(const Mcu_ConfigType* McuConfig)
{
  static_cast<void>(McuConfig);

  mcal::cpu::init(nullptr);
  mcal::osc::init(nullptr);

  // Initialize the MCU clock.
  Mcu_InitClock(static_cast<Mcu_ClockType>(0));

  // Wait for PLL lock.
  while(MCU_PLL_LOCKED != Mcu_GetPllStatus())
  {
    mcal::cpu::nop();
  }
}

EXTERN_C
Std_ReturnType Mcu_InitClock(Mcu_ClockType McuClock)
{
  static_cast<void>(McuClock);

  return E_OK;
}

EXTERN_C
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
  return MCU_PLL_LOCKED;
}

EXTERN_C
Std_ReturnType Mcu_DistributePllClock(void)
{

  return E_OK;
}

EXTERN_C
void Mcu_SetMode(Mcu_ModeType McuMode)
{
  if(McuMode == static_cast<Mcu_ModeType>(1))
  {
    Wdg_Trigger();
//    McalPwrSleepOnExit();
  }
}
