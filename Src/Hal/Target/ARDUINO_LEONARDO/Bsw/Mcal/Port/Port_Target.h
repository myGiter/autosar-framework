/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PORT_TARGET_2014_11_03_H_
  #define _PORT_TARGET_2014_11_03_H_

// Arduino Kompatibilität:
  #define ARDUINO_PORT_D_0       PORT_PIN_D_2
  #define ARDUINO_PORT_D_1       PORT_PIN_D_3
  #define ARDUINO_PORT_D_2       PORT_PIN_D_1
  #define ARDUINO_PORT_D_3       PORT_PIN_D_0
  #define ARDUINO_PORT_D_4       PORT_PIN_D_4
  #define ARDUINO_PORT_D_5       PORT_PIN_C_6
  #define ARDUINO_PORT_D_6       PORT_PIN_D_7
  #define ARDUINO_PORT_D_7       PORT_PIN_E_6
  #define ARDUINO_PORT_D_8       PORT_PIN_B_4
  #define ARDUINO_PORT_D_9       PORT_PIN_B_5
  #define ARDUINO_PORT_D_10      PORT_PIN_B_6
  #define ARDUINO_PORT_D_11      PORT_PIN_B_7
  #define ARDUINO_PORT_D_12      PORT_PIN_D_6
  #define ARDUINO_PORT_D_13      PORT_PIN_C_7

  #define ARDUINO_PORT_USER_LED  PORT_PIN_C_7
  #define ARDUINO_PORT_TX_LED    PORT_PIN_D_5
  #define ARDUINO_PORT_RX_LED    PORT_PIN_B_0

  #define ARDUINO_PORT_A_0       PORT_PIN_F_7
  #define ARDUINO_PORT_A_1       PORT_PIN_F_6
  #define ARDUINO_PORT_A_2       PORT_PIN_F_5
  #define ARDUINO_PORT_A_3       PORT_PIN_F_4
  #define ARDUINO_PORT_A_4       PORT_PIN_F_1
  #define ARDUINO_PORT_A_5       PORT_PIN_F_0

  #define LCD_DB_4               ARDUINO_PORT_D_4
  #define LCD_DB_5               ARDUINO_PORT_D_5
  #define LCD_DB_6               ARDUINO_PORT_D_6
  #define LCD_DB_7               ARDUINO_PORT_D_7
  #define LCD_RS                 ARDUINO_PORT_D_8
  #define LCD_ENABLE             ARDUINO_PORT_D_9
  #define LCD_BACKLIGHT          ARDUINO_PORT_D_10

  #endif // _PORT_TARGET_2014_11_03_H_
