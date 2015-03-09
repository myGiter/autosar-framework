/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Mcal/Port/Port_Cfg.h>
#include <Bsw/Mcal/Reg/Reg.h>

EXTERN_C
const Port_ConfigType Port_ConfigSet =
{
  {
    {
      // Port_PinType(ID).
      PORT_PIN_C_8,
      // Set Port_PinMode.
      PORT_PIN_MODE_DIO,
      // Is Port_PinModeChangeable?
//      STD_OFF,
      // Set Port_PinDirectionType.
      PORT_PIN_OUT,
      // Is Port_PinDirectionChangeable?
//      STD_OFF,
      // Set Port_PinLevelValue.
      PORT_PIN_LEVEL_LOW
    },
    {
      // Port_PinType(ID).
      PORT_PIN_C_9,
      // Set Port_PinMode.
      PORT_PIN_MODE_DIO,
      // Is Port_PinModeChangeable?
//      STD_OFF,
      // Set Port_PinDirectionType.
      PORT_PIN_OUT,
      // Is Port_PinDirectionChangeable?
//      STD_OFF,
      // Set Port_PinLevelValue.
      PORT_PIN_LEVEL_HIGH
    }
  }
};
