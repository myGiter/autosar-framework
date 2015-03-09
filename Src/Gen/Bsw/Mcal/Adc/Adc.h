/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _ADC_2014_10_09_H_
  #define _ADC_2014_10_09_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Adc/Adc_Cfg.h>

  typedef uint8 Adc_ResolutionType;
  typedef uint8 Adc_GroupPriorityType;
  typedef uint8 Adc_HwUnitType;

  EXTERN_C
  typedef enum enum_Adc_StatusType
  {
    ADC_IDLE,
    ADC_BUSY,
    ADC_COMPLETED,
    ADC_STREAM_COMPLETED
  }
  Adc_StatusType;

  EXTERN_C
  typedef enum enum_Adc_TriggerSourceType
  {
    ADC_TRIGG_SRC_SW,
    ADC_TRIGG_SRC_HW
  }
  Adc_TriggerSourceType;

  EXTERN_C
  typedef enum enum_Adc_GroupConvModeType
  {
    ADC_CONV_MODE_ONESHOT,
    ADC_CONV_MODE_CONTINUOUS
  }
  Adc_GroupConvModeType;

  EXTERN_C
  typedef enum enum_Adc_StreamBufferModeType
  {
    ADC_STREAM_BUFFER_LINEAR,
    ADC_STREAM_BUFFER_CIRCULAR
  }
  Adc_StreamBufferModeType;

  EXTERN_C
  typedef enum enum_Adc_GroupAccessModeType
  {
    ADC_ACCESS_MODE_SINGLE,
    ADC_ACCESS_MODE_STREAMING
  }
  Adc_GroupAccessModeType;

  EXTERN_C
  typedef enum enum_Adc_HwTriggerSignalType
  {
    ADC_HW_TRIG_RISING_EDGE,
    ADC_HW_TRIG_FALLING_EDGE,
    ADC_HW_TRIG_BOTH_EDGES
  }
  Adc_HwTriggerSignalType;

  EXTERN_C
  typedef enum enum_Adc_PriorityImplementationType
  {
    ADC_PRIORITY_NONE,
    ADC_PRIORITY_HW,
    ADC_PRIORITY_HW_SW
  }
  Adc_PriorityImplementationType;

  EXTERN_C
  typedef enum enum_Adc_GroupReplacementType
  {
    ADC_GROUP_REPL_ABORT_RESTART,
    ADC_GROUP_REPL_SUSPEND_RESUME
  }
  Adc_GroupReplacementType;


  EXTERN_C void Adc_Init(const Adc_ConfigType* AdcConfig);

  EXTERN_C Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group,
                                                Adc_ValueGroupType* DataBufferPtr);

  #if (ADC_DEINIT_API == STD_ON)
    EXTERN_C void Adc_DeInit(void);
  #endif // ADC_DEINIT_API == STD_ON

  #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    EXTERN_C void Adc_StartGroupConversion(Adc_GroupType Group);

    EXTERN_C void Adc_StopGroupConversion(Adc_GroupType Group);
  #endif // ADC_ENABLE_START_STOP_GROUP_API == STD_ON

  #if (ADC_READ_GROUP_API == STD_ON)
    EXTERN_C Std_ReturnType Adc_ReadGroup(Adc_GroupType Group,
                                          Adc_ValueGroupType* DataBufferPtr);
  #endif // ADC_READ_GROUP_API == STD_ON

  #if (ADC_GET_GROUP_STATUS_API == STD_ON)
    EXTERN_C Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group);
  #endif // ADC_GET_GROUP_STATUS_API == STD_ON

  #if (ADC_GET_STREAM_LAST_POINTER_API == STD_ON)
    EXTERN_C Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group,
                                                              Adc_ValueGroupType** PtrToSamplePtr);
  #endif // ADC_GET_STREAM_LAST_POINTER_API == STD_ON

  #if (ADC_HARDWARE_TRIGGER_API == STD_ON)
    EXTERN_C void Adc_EnableHardwareTrigger(Adc_GroupType Group);

    EXTERN_C void Adc_DisableHardwareTrigger(Adc_GroupType Group);
  #endif // ADC_HARDWARE_TRIGGER_API == STD_ON

  EXTERN_C void Adc_EnableGroupNotification(Adc_GroupType Group);
  EXTERN_C void Adc_DisableGroupNotification(Adc_GroupType Group);

#endif // _ADC_2014_10_09_H_
