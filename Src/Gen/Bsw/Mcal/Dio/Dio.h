/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _DIO_2014_10_09_H_
  #define _DIO_2014_10_09_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Dio/Dio_Cfg.h>

  EXTERN_C Dio_PortLevelType Dio_ReadPort         (Dio_PortType PortId);

  EXTERN_C Dio_LevelType     Dio_ReadChannel      (Dio_ChannelType ChannelId);

  EXTERN_C Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr);

  EXTERN_C void              Dio_WritePort        (Dio_PortType PortId, Dio_PortLevelType Level);

  EXTERN_C void              Dio_WriteChannel     (Dio_ChannelType ChannelId, Dio_LevelType Level);

  EXTERN_C void              Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

  EXTERN_C void              Dio_MaskedWritePort  (Dio_PortType      PortId,
                                                   Dio_PortLevelType Level,
                                                   Dio_PortLevelType Mask);

#endif // _DIO_2014_10_09_H_
