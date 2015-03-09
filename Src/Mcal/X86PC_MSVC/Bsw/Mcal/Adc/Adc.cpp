/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

  #include <Bsw/Mcal/Adc/Adc.h>

EXTERN_C
void Adc_Init(const Adc_ConfigType* AdcConfig)
{
  static_cast<void>(AdcConfig);
}

EXTERN_C
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)
{
  static_cast<void>(Group);
  static_cast<void>(DataBufferPtr);

  return Std_ReturnType(0U);
}

EXTERN_C
void Adc_DeInit(void)
{
}

EXTERN_C
void Adc_StartGroupConversion(Adc_GroupType Group)
{
  static_cast<void>(Group);
}

EXTERN_C
void Adc_StopGroupConversion(Adc_GroupType Group)
{
  static_cast<void>(Group);
}

EXTERN_C
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)
{
  static_cast<void>(Group);
  static_cast<void>(DataBufferPtr);
  return Std_ReturnType(0U);
}

EXTERN_C
void Adc_EnableHardwareTrigger(Adc_GroupType Group)
{
  static_cast<void>(Group);
}

EXTERN_C
void Adc_DisableHardwareTrigger(Adc_GroupType Group)
{
  static_cast<void>(Group);
}

EXTERN_C
void Adc_EnableGroupNotification(Adc_GroupType Group)
{
  static_cast<void>(Group);
}

EXTERN_C
void Adc_DisableGroupNotification(Adc_GroupType Group)
{
  static_cast<void>(Group);
}

EXTERN_C
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group)
{
  static_cast<void>(Group);
  return Adc_StatusType(0U);
}

EXTERN_C
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr)
{
  static_cast<void>(Group);
  static_cast<void>(PtrToSamplePtr);

  return Adc_StreamNumSampleType(0U);
}
