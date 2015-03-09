/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _MCU_CFG_2014_10_14_H_
  #define _MCU_CFG_2014_10_14_H_

  // includes.
  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Mcu/Mcu_ConfigTypes.h>

  // AUTOSAR-API.
  #define MCU_PERFORM_RESET_API           STD_OFF

  typedef struct struct_McuClockSettingConfig
  {
    uint32 dummy;
  }
  tMcuClockSettingConfig;

  typedef struct struct_McuModeSettingConf
  {
    uint32 dummy;
  }
  tMcuModeSettingConf;

  typedef struct struct_Mcu_ConfigType
  {
    const tMcuClockSettingConfig McuClockSettingConfiguration;
    const tMcuModeSettingConf    McuModeSettingConfiguration;
  }
  Mcu_ConfigType;

  EXTERN_C const Mcu_ConfigType Mcu_ModulConfiguration;

#endif // _MCU_CFG_2014_10_14_H_
