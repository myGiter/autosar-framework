/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _MCU_CONFIG_TYPES_2014_12_10_H_
  #define _MCU_CONFIG_TYPES_2014_12_10_H_

  //Specifies the id for a clock setting which is configured in the configuration structure
  typedef uint32  Mcu_ClockType;

  //This type contains the raw register value of the reset reason register
  typedef uint32 Mcu_RawResetType;

  //This type specifies the id for a MCU mode which is configured in the configuration structure
  typedef  uint32 Mcu_ModeType;

  //This type specifies the id for a RAM section which is configured in the configuration structure
  typedef uint32 Mcu_RamSectionType;

#endif // _MCU_CONFIG_TYPES_2014_12_10_H_
