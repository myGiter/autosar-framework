/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <cstdint>
#include <iostream>
#include <Bsw/Mcal/Dio/Dio.h>

EXTERN_C
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
  static_cast<void>(PortId);
  static_cast<void>(Level);
}

EXTERN_C
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
  static_cast<void>(PortId);

  return Dio_PortLevelType(0U);
}

EXTERN_C
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
  static_cast<void>(ChannelId);
  static_cast<void>(Level);

  const uint32 signal_value = ((Level == STD_HIGH) ? static_cast<uint32>(1U) : static_cast<uint32>(0U));

  // Use the Boolean value.
  std::cout << "Dio signal value is: "
            << signal_value
            << std::endl;
}

EXTERN_C
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
  static_cast<void>(ChannelId);

  return Dio_LevelType(0);
}

EXTERN_C
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
  static_cast<void>(ChannelGroupIdPtr);

  return Dio_PortLevelType(0);
}

EXTERN_C
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
  static_cast<void>(ChannelGroupIdPtr);

  static_cast<void>(Level);
}

EXTERN_C
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
{
  static_cast<void>(PortId);

  static_cast<void>(Level);

  static_cast<void>(Mask);
}
