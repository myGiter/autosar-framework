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
  #define PORT_PIN_D_3   99
  #define PORT_PIN_D_4  100
  #define PORT_PIN_D_5  101
  #define PORT_PIN_D_6  102
  #define PORT_PIN_D_7  103
  #define PORT_PIN_D_8  104
  #define PORT_PIN_D_9  105
  #define PORT_PIN_D_10 106
  #define PORT_PIN_D_11 107
  #define PORT_PIN_D_12 108
  #define PORT_PIN_D_13 109
  #define PORT_PIN_D_14 110
  #define PORT_PIN_D_15 111

  #define PORT_PIN_E_0  128
  #define PORT_PIN_E_1  129
  #define PORT_PIN_E_2  130
  #define PORT_PIN_E_3  131
  #define PORT_PIN_E_4  132
  #define PORT_PIN_E_5  133
  #define PORT_PIN_E_6  134
  #define PORT_PIN_E_7  135
  #define PORT_PIN_E_8  136
  #define PORT_PIN_E_9  137
  #define PORT_PIN_E_10 138
  #define PORT_PIN_E_11 139
  #define PORT_PIN_E_12 140
  #define PORT_PIN_E_13 141
  #define PORT_PIN_E_14 142
  #define PORT_PIN_E_15 143

  #define PORT_PIN_F_0  160
  #define PORT_PIN_F_1  161
  #define PORT_PIN_F_2  162
  #define PORT_PIN_F_3  163
  #define PORT_PIN_F_4  164
  #define PORT_PIN_F_5  165
  #define PORT_PIN_F_6  166
  #define PORT_PIN_F_7  167
  #define PORT_PIN_F_8  168
  #define PORT_PIN_F_9  169
  #define PORT_PIN_F_10 170
  #define PORT_PIN_F_11 171
  #define PORT_PIN_F_12 172
  #define PORT_PIN_F_13 173
  #define PORT_PIN_F_14 174
  #define PORT_PIN_F_15 175

  #define PORT_PIN_G_0  192
  #define PORT_PIN_G_1  193
  #define PORT_PIN_G_2  194
  #define PORT_PIN_G_3  195
  #define PORT_PIN_G_4  196
  #define PORT_PIN_G_5  197
  #define PORT_PIN_G_6  198
  #define PORT_PIN_G_7  199
  #define PORT_PIN_G_8  200
  #define PORT_PIN_G_9  201
  #define PORT_PIN_G_10 202
  #define PORT_PIN_G_11 203
  #define PORT_PIN_G_12 204
  #define PORT_PIN_G_13 205
  #define PORT_PIN_G_14 206
  #define PORT_PIN_G_15 207

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

#endif // _PORT_CONFIG_TYPES_2014_04_07_H_
