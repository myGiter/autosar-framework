/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef DIO_CFG_2015_03_05_H
  #define DIO_CFG_2015_03_05_H

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Dio/Dio_ConfigTypes.h>

  #define DIO_READ_PORT_API               STD_OFF
  #define DIO_READ_CHANNEL_API            STD_ON
  #define DIO_READ_CHANNEL_GROUP_API      STD_OFF
  #define DIO_WRITE_PORT_API              STD_OFF
  #define DIO_WRITE_CHANNEL_API           STD_ON
  #define DIO_WRITE_CHANNEL_GROUP_API     STD_OFF
  #define DIO_MASKED_WRITE_PORT_API       STD_OFF

  typedef struct struct_Dio_ChannelGroupType
  {
    uint32       mask;
    uint8        offset;
    Dio_PortType port;
  }
  Dio_ChannelGroupType;

  EXTERN_C const Dio_ChannelType Dio_ChannelCfgId_01;

#endif // DIO_CFG_2015_03_05_H
