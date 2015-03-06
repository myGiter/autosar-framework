/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Port/Port_Cfg.h>
#include <Bsw/Mcal/Reg/Reg.h>

EXTERN_C
const Port_ConfigType Port_ConfigSet =
{
  {
    {
      // Port_PinType(ID).
      ARDUINO_LED_USER,
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
      ARDUINO_RGB_R,
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
      ARDUINO_RGB_G,
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
      ARDUINO_RGB_B,
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
      ARDUINO_PORT_RX_LED,
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
      ARDUINO_MUX_SIGNAL,
      // Set Port_PinMode.
      PORT_PIN_MODE_DIO,
      // Is Port_PinModeChangeable?
//      STD_OFF,
      // Set Port_PinDirectionType.
      PORT_PIN_IN,
      // Is Port_PinDirectionChangeable?
//      STD_OFF,
      // Set Port_PinLevelValue.
      PORT_PIN_LEVEL_LOW
    },
    {
      // Port_PinType(ID).
      ARDUINO_MUX_A,
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
      ARDUINO_MUX_B,
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
      ARDUINO_MUX_C,
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
      ARDUINO_MUX_D,
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
    }
  }
};
