/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PORT_CONFIG_TYPES_2014_04_07_H_
  #define _PORT_CONFIG_TYPES_2014_04_07_H_

  // All available Ports:
  // IDs divided by 8 = Base of 3!
  // IDs modulo 8 = Pin Position!
  #define PORT_PIN_B_0   0
  #define PORT_PIN_B_1   1
  #define PORT_PIN_B_2   2
  #define PORT_PIN_B_3   3
  #define PORT_PIN_B_4   4
  #define PORT_PIN_B_5   5
  #define PORT_PIN_B_6   6
  #define PORT_PIN_B_7   7

  #define PORT_PIN_C_6  30
  #define PORT_PIN_C_7  31

  #define PORT_PIN_D_0  48
  #define PORT_PIN_D_1  49
  #define PORT_PIN_D_2  50
  #define PORT_PIN_D_3  51
  #define PORT_PIN_D_4  52
  #define PORT_PIN_D_5  53
  #define PORT_PIN_D_6  54
  #define PORT_PIN_D_7  55

  #define PORT_PIN_E_2  74
  #define PORT_PIN_E_6  78

  #define PORT_PIN_F_0  96
  #define PORT_PIN_F_1  97
  #define PORT_PIN_F_4 100
  #define PORT_PIN_F_5 101
  #define PORT_PIN_F_6 102
  #define PORT_PIN_F_7 103

  // Typedefs.
  typedef uint8 Port_PinType;
  typedef uint8 Port_PinModeType;


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

#endif // _PORT_CONFIG_TYPES_2014_04_07_H_
