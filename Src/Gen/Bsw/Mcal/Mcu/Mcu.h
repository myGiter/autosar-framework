/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _MCU_2014_10_09_H_
  #define _MCU_2014_10_09_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Mcu/Mcu_Cfg.h>

  typedef enum enum_Mcu_PllStatusType
  {
    MCU_PLL_LOCKED,
    MCU_PLL_UNLOCKED,
    MCU_PLL_STATUS_UNDEFINED
  }
  Mcu_PllStatusType;

  typedef enum enum_Mcu_ResetType
  {
    MCU_POWER_ON_RESET,
    MCU_WATCHDOG_RESET,
    MCU_SW_RESET,
    MCU_RESET_UNDEFINED
  }
  Mcu_ResetType;

  typedef enum 
  {
    MCU_RAMSTATE_INVALID,
    MCU_RAMSTATE_VALID
  } Mcu_RamStateType;

  // DET errors that the MCU can produce.
  typedef enum enum_Mcu_DetErrorType
  {
    MCU_E_PARAM_CONFIG     = 0x0A,
    MCU_E_PARAM_CLOCK      = 0x0B,
    MCU_E_PARAM_MODE       = 0x0C,
    MCU_E_PARAM_RAMSECTION = 0x0D,
    MCU_E_PLL_NOT_LOCKED   = 0x0E,
    MCU_E_UNINIT           = 0x0F
  }
  Mcu_DetErrorType;

  EXTERN_C void Mcu_Init( const Mcu_ConfigType *ConfigPtr);

  EXTERN_C Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection);

  EXTERN_C Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting);

  EXTERN_C Std_ReturnType Mcu_DistributePllClock(void);

  EXTERN_C Mcu_PllStatusType Mcu_GetPllStatus(void);

  EXTERN_C Mcu_ResetType Mcu_GetResetReason(void);

  EXTERN_C Mcu_RawResetType Mcu_GetResetRawValue(void);

  #if (MCU_PERFORM_RESET_API == STD_ON)
    EXTERN_C void Mcu_PerformReset(void);
  #endif // MCU_PERFORM_RESET_API == STD_ON

  EXTERN_C void Mcu_SetMode(Mcu_ModeType McuMode);

#endif // _MCU_2014_10_09_H_
