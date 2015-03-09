/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PORT_CONFIG_TYPES_2014_12_10_H_
  #define _PORT_CONFIG_TYPES_2014_12_10_H_

  // All available Ports:
  // IDs divided by 32 = Base of 0x400!
  // IDs modulo 32 = Pin Position!
  #define PORT_PIN_A_0    0
  #define PORT_PIN_A_1    1
  #define PORT_PIN_A_2    2
  #define PORT_PIN_A_3    3
  #define PORT_PIN_A_4    4
  #define PORT_PIN_A_5    5
  #define PORT_PIN_A_6    6
  #define PORT_PIN_A_7    7
  #define PORT_PIN_A_8    8
  #define PORT_PIN_A_9    9
  #define PORT_PIN_A_10  10
  #define PORT_PIN_A_11  11
  #define PORT_PIN_A_12  12
  #define PORT_PIN_A_13  13
  #define PORT_PIN_A_14  14
  #define PORT_PIN_A_15  15

  #define PORT_PIN_B_0   32
  #define PORT_PIN_B_1   33
  #define PORT_PIN_B_2   34
  #define PORT_PIN_B_3   35
  #define PORT_PIN_B_4   36
  #define PORT_PIN_B_5   37
  #define PORT_PIN_B_6   38
  #define PORT_PIN_B_7   39
  #define PORT_PIN_B_8   40
  #define PORT_PIN_B_9   41
  #define PORT_PIN_B_10  42
  #define PORT_PIN_B_11  43
  #define PORT_PIN_B_12  44
  #define PORT_PIN_B_13  45
  #define PORT_PIN_B_14  46
  #define PORT_PIN_B_15  47

  #define PORT_PIN_C_0   64
  #define PORT_PIN_C_1   65
  #define PORT_PIN_C_2   66
  #define PORT_PIN_C_3   67
  #define PORT_PIN_C_4   68
  #define PORT_PIN_C_5   69
  #define PORT_PIN_C_6   70
  #define PORT_PIN_C_7   71
  #define PORT_PIN_C_8   72
  #define PORT_PIN_C_9   73
  #define PORT_PIN_C_10  74
  #define PORT_PIN_C_11  75
  #define PORT_PIN_C_12  76
  #define PORT_PIN_C_13  77
  #define PORT_PIN_C_14  78
  #define PORT_PIN_C_15  79

  #define PORT_PIN_D_0   96
  #define PORT_PIN_D_1   97
  #define PORT_PIN_D_2   98

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

#endif // _PORT_CONFIG_TYPES_2014_12_10_H_
