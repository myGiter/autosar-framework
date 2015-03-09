/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Icu/Icu.h>
#include <Bsw/Mcal/Dio/Dio.h>

EXTERN_C
void Icu_Init(const Icu_ConfigType* IcuConfig)
{
  static_cast<void>(IcuConfig);
}

EXTERN_C
void Icu_DeInit(void)
{
}

EXTERN_C
void 
Icu_SetMode(Icu_ModeType Mode)
{
  static_cast<void>(Mode);
}

EXTERN_C
void Icu_DisableWakeup(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_EnableWakeup(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
  static_cast<void>(Channel);
  static_cast<void>(Activation);
}

EXTERN_C
void Icu_DisableNotification(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_EnableNotification(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
  return Icu_InputStateType(0U);
}

EXTERN_C
void Icu_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType* BufferPtr, uint16 BufferSize, uint16 NotifyInterval)
{
  static_cast<void>(Channel);
  static_cast<void>(BufferPtr);
  static_cast<void>(BufferSize);
  static_cast<void>(NotifyInterval);
}

EXTERN_C
void Icu_StopTimestamp(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);

  return Icu_IndexType(0U);
}

EXTERN_C
void Icu_ResetEdgeCount(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_EnableEdgeCount(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_DisableEdgeCount(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
  return Icu_EdgeNumberType(0U);
}
EXTERN_C
void Icu_StartSignalMeasurement(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_StopSignalMeasurement(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
  return Icu_ValueType(0U);
}

EXTERN_C
void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues)
{
  static_cast<void>(Channel);
  static_cast<void>(DutyCycleValues);
}
