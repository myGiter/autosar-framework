/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef DIO_CFG_2015_02_18_H
  #define DIO_CFG_2015_02_18_H

  // includes.
  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Dio/Dio_ConfigTypes.h>

  // AUTOSAR-API.
  #define DIO_DEV_ERROR_DETECT           STD_OFF

  typedef struct struct_Dio_ChannelGroupType
  {
    uint8        offset;
    Dio_PortType port;
    uint8        mask;
  }
  Dio_ChannelGroupType;

  // Specific.
  #define DIO_CHANNEL_OPERATION   DIO_CHANNEL_B_7
  #define RDM_DIO_CHANNEL         DIO_CHANNEL_B_2

#endif // DIO_CFG_2015_02_18_H
