/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _MCU_CFG_2013_12_16_H_
  #define _MCU_CFG_2013_12_16_H_

  #include <Bsw/Common/Std_Types.h>

  #define MCU_INIT_RAM_API                STD_OFF
  #define MCU_GET_RESET_REASON_API        STD_OFF
  #define MCU_GET_RESET_RAW_API           STD_OFF
  #define MCU_PERFORM_RESET_API           STD_OFF
  #define MCU_SET_MODE_API                STD_OFF

  //Specifies the id for a clock setting which is configured in the configuration structure
  typedef uint32 Mcu_ClockType;

  //This type contains the raw register value of the reset reason register
  typedef uint32 Mcu_RawResetType;

  //This type specifies the id for a MCU mode which is configured in the configuration structure
  typedef  uint32 Mcu_ModeType;

  //This type specifies the id for a RAM section which is configured in the configuration structure
  typedef uint32 Mcu_RamSectionType;

  typedef struct struct_Mcu_ConfigType
  {
    uint32 dummy;
  }
  Mcu_ConfigType;

  EXTERN_C const Mcu_ConfigType Mcu_ModulConfiguration;

#endif // _MCU_CFG_2013_12_16_H_
