/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _DIO_CONFIG_TYPES_2014_06_03_H_
  #define _DIO_CONFIG_TYPES_2014_06_03_H_

  #include <Bsw/Mcal/Port/Port.h>

  typedef uint32 Dio_PortType;
  typedef uint32 Dio_PortLevelType;
  typedef uint32 Dio_ChannelType;
  typedef uint32 Dio_LevelType;

  #define DIO_CHANNEL_A_0   PORT_PIN_A_0
  #define DIO_CHANNEL_A_1   PORT_PIN_A_1
  #define DIO_CHANNEL_A_2   PORT_PIN_A_2
  #define DIO_CHANNEL_A_3   PORT_PIN_A_3
  #define DIO_CHANNEL_A_4   PORT_PIN_A_4
  #define DIO_CHANNEL_A_5   PORT_PIN_A_5
  #define DIO_CHANNEL_A_6   PORT_PIN_A_6
  #define DIO_CHANNEL_A_7   PORT_PIN_A_7
  #define DIO_CHANNEL_A_8   PORT_PIN_A_8
  #define DIO_CHANNEL_A_9   PORT_PIN_A_9
  #define DIO_CHANNEL_A_10  PORT_PIN_A_10
  #define DIO_CHANNEL_A_11  PORT_PIN_A_11
  #define DIO_CHANNEL_A_12  PORT_PIN_A_12
  #define DIO_CHANNEL_A_13  PORT_PIN_A_13
  #define DIO_CHANNEL_A_14  PORT_PIN_A_14
  #define DIO_CHANNEL_A_15  PORT_PIN_A_15

  #define DIO_CHANNEL_B_0   PORT_PIN_B_0
  #define DIO_CHANNEL_B_1   PORT_PIN_B_1
  #define DIO_CHANNEL_B_2   PORT_PIN_B_2
  #define DIO_CHANNEL_B_3   PORT_PIN_B_3
  #define DIO_CHANNEL_B_4   PORT_PIN_B_4
  #define DIO_CHANNEL_B_5   PORT_PIN_B_5
  #define DIO_CHANNEL_B_6   PORT_PIN_B_6
  #define DIO_CHANNEL_B_7   PORT_PIN_B_7
  #define DIO_CHANNEL_B_8   PORT_PIN_B_8
  #define DIO_CHANNEL_B_9   PORT_PIN_B_9
  #define DIO_CHANNEL_B_10  PORT_PIN_B_10
  #define DIO_CHANNEL_B_11  PORT_PIN_B_11
  #define DIO_CHANNEL_B_12  PORT_PIN_B_12
  #define DIO_CHANNEL_B_13  PORT_PIN_B_13
  #define DIO_CHANNEL_B_14  PORT_PIN_B_14
  #define DIO_CHANNEL_B_15  PORT_PIN_B_15

  #define DIO_CHANNEL_C_0   PORT_PIN_C_0
  #define DIO_CHANNEL_C_1   PORT_PIN_C_1
  #define DIO_CHANNEL_C_2   PORT_PIN_C_2
  #define DIO_CHANNEL_C_3   PORT_PIN_C_3
  #define DIO_CHANNEL_C_4   PORT_PIN_C_4
  #define DIO_CHANNEL_C_5   PORT_PIN_C_5
  #define DIO_CHANNEL_C_6   PORT_PIN_C_6
  #define DIO_CHANNEL_C_7   PORT_PIN_C_7
  #define DIO_CHANNEL_C_8   PORT_PIN_C_8
  #define DIO_CHANNEL_C_9   PORT_PIN_C_9
  #define DIO_CHANNEL_C_10  PORT_PIN_C_10
  #define DIO_CHANNEL_C_11  PORT_PIN_C_11
  #define DIO_CHANNEL_C_12  PORT_PIN_C_12
  #define DIO_CHANNEL_C_13  PORT_PIN_C_13
  #define DIO_CHANNEL_C_14  PORT_PIN_C_14
  #define DIO_CHANNEL_C_15  PORT_PIN_C_15

  #define DIO_CHANNEL_D_0   PORT_PIN_D_0
  #define DIO_CHANNEL_D_1   PORT_PIN_D_1
  #define DIO_CHANNEL_D_2   PORT_PIN_D_2
  #define DIO_CHANNEL_D_3   PORT_PIN_D_3
  #define DIO_CHANNEL_D_4   PORT_PIN_D_4
  #define DIO_CHANNEL_D_5   PORT_PIN_D_5
  #define DIO_CHANNEL_D_6   PORT_PIN_D_6
  #define DIO_CHANNEL_D_7   PORT_PIN_D_7
  #define DIO_CHANNEL_D_8   PORT_PIN_D_8
  #define DIO_CHANNEL_D_9   PORT_PIN_D_9
  #define DIO_CHANNEL_D_10  PORT_PIN_D_10
  #define DIO_CHANNEL_D_11  PORT_PIN_D_11
  #define DIO_CHANNEL_D_12  PORT_PIN_D_12
  #define DIO_CHANNEL_D_13  PORT_PIN_D_13
  #define DIO_CHANNEL_D_14  PORT_PIN_D_14
  #define DIO_CHANNEL_D_15  PORT_PIN_D_15
  
  #define DIO_CHANNEL_E_0   PORT_PIN_E_0
  #define DIO_CHANNEL_E_1   PORT_PIN_E_1
  #define DIO_CHANNEL_E_2   PORT_PIN_E_2
  #define DIO_CHANNEL_E_3   PORT_PIN_E_3
  #define DIO_CHANNEL_E_4   PORT_PIN_E_4
  #define DIO_CHANNEL_E_5   PORT_PIN_E_5
  #define DIO_CHANNEL_E_6   PORT_PIN_E_6
  #define DIO_CHANNEL_E_7   PORT_PIN_E_7
  #define DIO_CHANNEL_E_8   PORT_PIN_E_8
  #define DIO_CHANNEL_E_9   PORT_PIN_E_9
  #define DIO_CHANNEL_E_10  PORT_PIN_E_10
  #define DIO_CHANNEL_E_11  PORT_PIN_E_11
  #define DIO_CHANNEL_E_12  PORT_PIN_E_12
  #define DIO_CHANNEL_E_13  PORT_PIN_E_13
  #define DIO_CHANNEL_E_14  PORT_PIN_E_14
  #define DIO_CHANNEL_E_15  PORT_PIN_E_15
  
  #define DIO_CHANNEL_F_0   PORT_PIN_F_0
  #define DIO_CHANNEL_F_1   PORT_PIN_F_1
  #define DIO_CHANNEL_F_2   PORT_PIN_F_2
  #define DIO_CHANNEL_F_3   PORT_PIN_F_3
  #define DIO_CHANNEL_F_4   PORT_PIN_F_4
  #define DIO_CHANNEL_F_5   PORT_PIN_F_5
  #define DIO_CHANNEL_F_6   PORT_PIN_F_6
  #define DIO_CHANNEL_F_7   PORT_PIN_F_7
  #define DIO_CHANNEL_F_8   PORT_PIN_F_8
  #define DIO_CHANNEL_F_9   PORT_PIN_F_9
  #define DIO_CHANNEL_F_10  PORT_PIN_F_10
  #define DIO_CHANNEL_F_11  PORT_PIN_F_11
  #define DIO_CHANNEL_F_12  PORT_PIN_F_12
  #define DIO_CHANNEL_F_13  PORT_PIN_F_13
  #define DIO_CHANNEL_F_14  PORT_PIN_F_14
  #define DIO_CHANNEL_F_15  PORT_PIN_F_15
  
  #define DIO_CHANNEL_G_0   PORT_PIN_G_0
  #define DIO_CHANNEL_G_1   PORT_PIN_G_1
  #define DIO_CHANNEL_G_2   PORT_PIN_G_2
  #define DIO_CHANNEL_G_3   PORT_PIN_G_3
  #define DIO_CHANNEL_G_4   PORT_PIN_G_4
  #define DIO_CHANNEL_G_5   PORT_PIN_G_5
  #define DIO_CHANNEL_G_6   PORT_PIN_G_6
  #define DIO_CHANNEL_G_7   PORT_PIN_G_7
  #define DIO_CHANNEL_G_8   PORT_PIN_G_8
  #define DIO_CHANNEL_G_9   PORT_PIN_G_9
  #define DIO_CHANNEL_G_10  PORT_PIN_G_10
  #define DIO_CHANNEL_G_11  PORT_PIN_G_11
  #define DIO_CHANNEL_G_12  PORT_PIN_G_12
  #define DIO_CHANNEL_G_13  PORT_PIN_G_13
  #define DIO_CHANNEL_G_14  PORT_PIN_G_14
  #define DIO_CHANNEL_G_15  PORT_PIN_G_15

#endif // _DIO_CONFIG_TYPES_2014_06_03_H_
