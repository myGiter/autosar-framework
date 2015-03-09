/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Mcu/Mcu.h>

EXTERN_C
void Mcu_Init(const Mcu_ConfigType* McuConfig)
{
  static_cast<void>(McuConfig);
}

EXTERN_C
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{
  static_cast<void>(RamSection);

  return Std_ReturnType(0U);
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
  return static_cast<Std_ReturnType>(0);
}

EXTERN_C
Mcu_ResetType Mcu_GetResetReason(void)
{

  return Mcu_ResetType(0U);
}

EXTERN_C
Mcu_RawResetType Mcu_GetResetRawValue(void)
{

  return Mcu_RawResetType(0U);
}

EXTERN_C
void Mcu_PerformReset(void)
{

}

EXTERN_C
void Mcu_SetMode(Mcu_ModeType McuMode)
{
  static_cast<void>(McuMode);
}
