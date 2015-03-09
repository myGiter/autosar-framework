/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PORT_CONFIG_TYPES_2014_05_21_H_
  #define _PORT_CONFIG_TYPES_2014_05_21_H_

  // All available Ports:
  // IDs divided by 32 = Base of 0x400!
  // IDs modulo 32 = Pin Position!


  // Typedefs.
  typedef uint32 Port_PinType;
  typedef uint32 Port_PinModeType;

  EXTERN_C
  typedef enum enum_Port_PinDirectionType
  {
    PORT_PIN_IN,
    PORT_PIN_OUT
  }
  Port_PinDirectionType;

  typedef bool Port_PinDirectionChangeable;
  typedef bool Port_PinModeChangeable;

  EXTERN_C
  typedef enum enum_Port_PinMode
  {
    PORT_PIN_MODE_ADC,
    PORT_PIN_MODE_CAN,
    PORT_PIN_MODE_DIO,
    PORT_PIN_MODE_DIO_GPT,
    PORT_PIN_MODE_DIO_WDG,
    PORT_PIN_MODE_FLEXRAY,
    PORT_PIN_MODE_ICU,
    PORT_PIN_MODE_LIN,
    PORT_PIN_MODE_MEM,
    PORT_PIN_MODE_PWM,
    PORT_PIN_MODE_SPI
  }
  Port_PinMode;

  EXTERN_C
  typedef enum enum_Port_PinLevelValue
  {
    PORT_PIN_LEVEL_HIGH,
    PORT_PIN_LEVEL_LOW
  }
  Port_PinLevelValue;

#endif // _PORT_CONFIG_TYPES_2014_05_21_H_
