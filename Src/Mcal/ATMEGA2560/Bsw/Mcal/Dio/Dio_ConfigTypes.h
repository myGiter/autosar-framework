/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _DIO_CONFIG_TYPES_2014_04_07_H_
  #define _DIO_CONFIG_TYPES_2014_04_07_H_

  #include <Bsw/Mcal/Port/Port.h>

  typedef uint8 Dio_PortType;
  typedef uint8 Dio_PortLevelType;
  typedef uint8 Dio_ChannelType;
  typedef uint8 Dio_LevelType;

  #define DIO_CHANNEL_B_0  PORT_PIN_B_0
  #define DIO_CHANNEL_B_1  PORT_PIN_B_1
  #define DIO_CHANNEL_B_2  PORT_PIN_B_2
  #define DIO_CHANNEL_B_3  PORT_PIN_B_3
  #define DIO_CHANNEL_B_4  PORT_PIN_B_4
  #define DIO_CHANNEL_B_5  PORT_PIN_B_5
  #define DIO_CHANNEL_B_6  PORT_PIN_B_6
  #define DIO_CHANNEL_B_7  PORT_PIN_B_7

  #define DIO_CHANNEL_C_6  PORT_PIN_C_6
  #define DIO_CHANNEL_C_7  PORT_PIN_C_7

  #define DIO_CHANNEL_D_0  PORT_PIN_D_0
  #define DIO_CHANNEL_D_1  PORT_PIN_D_1
  #define DIO_CHANNEL_D_2  PORT_PIN_D_2
  #define DIO_CHANNEL_D_3  PORT_PIN_D_3
  #define DIO_CHANNEL_D_4  PORT_PIN_D_4
  #define DIO_CHANNEL_D_5  PORT_PIN_D_5
  #define DIO_CHANNEL_D_6  PORT_PIN_D_6
  #define DIO_CHANNEL_D_7  PORT_PIN_D_7

  #define DIO_CHANNEL_E_2  PORT_PIN_E_2
  #define DIO_CHANNEL_E_6  PORT_PIN_E_6

  #define DIO_CHANNEL_F_0  PORT_PIN_F_0
  #define DIO_CHANNEL_F_1  PORT_PIN_F_1
  #define DIO_CHANNEL_F_4  PORT_PIN_F_4
  #define DIO_CHANNEL_F_5  PORT_PIN_F_5
  #define DIO_CHANNEL_F_6  PORT_PIN_F_6
  #define DIO_CHANNEL_F_7  PORT_PIN_F_7

// Arduino Kompatibilität:
  #define ARDUINO_DIO_D_0       DIO_CHANNEL_D_2
  #define ARDUINO_DIO_D_1       DIO_CHANNEL_D_3
  #define ARDUINO_DIO_D_2       DIO_CHANNEL_D_1
  #define ARDUINO_DIO_D_3       DIO_CHANNEL_D_0
  #define ARDUINO_DIO_D_4       DIO_CHANNEL_D_4
  #define ARDUINO_DIO_D_5       DIO_CHANNEL_C_6
  #define ARDUINO_DIO_D_6       DIO_CHANNEL_D_7
  #define ARDUINO_DIO_D_7       DIO_CHANNEL_E_6
  #define ARDUINO_DIO_D_8       DIO_CHANNEL_B_4
  #define ARDUINO_DIO_D_9       DIO_CHANNEL_B_5
  #define ARDUINO_DIO_D_10      DIO_CHANNEL_B_6
  #define ARDUINO_DIO_D_11      DIO_CHANNEL_B_7
  #define ARDUINO_DIO_D_12      DIO_CHANNEL_D_6
  #define ARDUINO_DIO_D_13      DIO_CHANNEL_C_7

  #define ARDUINO_DIO_USER_LED  DIO_CHANNEL_B_7
  #define ARDUINO_DIO_TX_LED    DIO_CHANNEL_D_5
  #define ARDUINO_DIO_RX_LED    DIO_CHANNEL_B_0

  #define ARDUINO_DIO_A_0       DIO_CHANNEL_F_7
  #define ARDUINO_DIO_A_1       DIO_CHANNEL_F_6
  #define ARDUINO_DIO_A_2       DIO_CHANNEL_F_5
  #define ARDUINO_DIO_A_3       DIO_CHANNEL_F_4
  #define ARDUINO_DIO_A_4       DIO_CHANNEL_F_1
  #define ARDUINO_DIO_A_5       DIO_CHANNEL_F_0

#endif // _DIO_CONFIG_TYPES_2014_04_07_H_
