/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef PORT_CONFIG_TYPES_2015_02_18_H
  #define PORT_CONFIG_TYPES_2015_02_18_H

  // All available Ports:
  // IDs divided by 8 = Base of 3!
  // IDs modulo 8 = Pin Position!
  #define PORT_PIN_A_0    0
  #define PORT_PIN_A_1    1
  #define PORT_PIN_A_2    2
  #define PORT_PIN_A_3    3
  #define PORT_PIN_A_4    4
  #define PORT_PIN_A_5    5
  #define PORT_PIN_A_6    6
  #define PORT_PIN_A_7    7

  #define PORT_PIN_B_0   24
  #define PORT_PIN_B_1   25
  #define PORT_PIN_B_2   26
  #define PORT_PIN_B_3   27
  #define PORT_PIN_B_4   28
  #define PORT_PIN_B_5   29
  #define PORT_PIN_B_6   30
  #define PORT_PIN_B_7   31

  #define PORT_PIN_C_0   48
  #define PORT_PIN_C_1   49
  #define PORT_PIN_C_2   50
  #define PORT_PIN_C_3   51
  #define PORT_PIN_C_4   52
  #define PORT_PIN_C_5   53
  #define PORT_PIN_C_6   54
  #define PORT_PIN_C_7   55

  #define PORT_PIN_D_0   72
  #define PORT_PIN_D_1   73
  #define PORT_PIN_D_2   74
  #define PORT_PIN_D_3   75
  #define PORT_PIN_D_4   76
  #define PORT_PIN_D_5   77
  #define PORT_PIN_D_6   78
  #define PORT_PIN_D_7   79

  #define PORT_PIN_E_0   96
  #define PORT_PIN_E_1   97
  #define PORT_PIN_E_2   98
  #define PORT_PIN_E_3   99
  #define PORT_PIN_E_4  100
  #define PORT_PIN_E_5  101
  #define PORT_PIN_E_6  102
  #define PORT_PIN_E_7  103

  #define PORT_PIN_F_0  120
  #define PORT_PIN_F_1  121
  #define PORT_PIN_F_2  122
  #define PORT_PIN_F_3  123
  #define PORT_PIN_F_4  124
  #define PORT_PIN_F_5  125
  #define PORT_PIN_F_6  126
  #define PORT_PIN_F_7  127

  #define PORT_PIN_G_0  144
  #define PORT_PIN_G_1  145
  #define PORT_PIN_G_2  146
  #define PORT_PIN_G_3  147
  #define PORT_PIN_G_4  148
  #define PORT_PIN_G_5  149

  #define PORT_PIN_H_0  800
  #define PORT_PIN_H_1  801
  #define PORT_PIN_H_2  802
  #define PORT_PIN_H_3  803
  #define PORT_PIN_H_4  804
  #define PORT_PIN_H_5  805
  #define PORT_PIN_H_6  806
  #define PORT_PIN_H_7  807

  #define PORT_PIN_J_0  824
  #define PORT_PIN_J_1  825
  #define PORT_PIN_J_2  826
  #define PORT_PIN_J_3  827
  #define PORT_PIN_J_4  828
  #define PORT_PIN_J_5  829
  #define PORT_PIN_J_6  830
  #define PORT_PIN_J_7  831

  #define PORT_PIN_K_0  848
  #define PORT_PIN_K_1  849
  #define PORT_PIN_K_2  850
  #define PORT_PIN_K_3  851
  #define PORT_PIN_K_4  852
  #define PORT_PIN_K_5  853
  #define PORT_PIN_K_6  854
  #define PORT_PIN_K_7  855

  #define PORT_PIN_L_0  872
  #define PORT_PIN_L_1  873
  #define PORT_PIN_L_2  874
  #define PORT_PIN_L_3  875
  #define PORT_PIN_L_4  876
  #define PORT_PIN_L_5  877
  #define PORT_PIN_L_6  878
  #define PORT_PIN_L_7  879

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

#endif // PORT_CONFIG_TYPES_2015_02_18_H
