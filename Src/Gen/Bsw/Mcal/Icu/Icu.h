/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _ICU_2014_10_09_H_
  #define _ICU_2014_10_09_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Icu/Icu_Cfg.h>

  EXTERN_C void Icu_Init(const Icu_ConfigType* IcuConfig);

  #if (ICU_DE_INIT_API == STD_ON)
    EXTERN_C void Icu_DeInit(void);
  #endif // ICU_DE_INIT_API == STD_ON

  #if (ICU_SET_MODE_API == STD_ON)
    EXTERN_C void Icu_SetMode(Icu_ModeType Mode);
  #endif // ICU_SET_MODE_API == STD_ON

  #if (ICU_DISABLE_WAKEUP_API == STD_ON)
    EXTERN_C void Icu_DisableWakeup(Icu_ChannelType Channel);
  #endif // ICU_DISABLE_WAKEUP_API == STD_ON

  #if (ICU_ENABLE_WAKEUP_API == STD_ON)
    EXTERN_C void Icu_EnableWakeup(Icu_ChannelType Channel);
  #endif // ICU_ENABLE_WAKEUP_API == STD_ON

  EXTERN_C void Icu_SetActivationCondition (Icu_ChannelType    Channel,
                                            Icu_ActivationType Activation);

  EXTERN_C void Icu_DisableNotification    (Icu_ChannelType    Channel);

  EXTERN_C void Icu_EnableNotification     (Icu_ChannelType    Channel);

  #if (ICU_GET_INPUT_STATE_API == STD_ON)
    EXTERN_C Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel);
  #endif // ICU_GET_INPUT_STATE_API == STD_ON

  #if (ICU_TIMESTAMP_API == STD_ON)
    EXTERN_C void          Icu_StartTimestamp    (Icu_ChannelType Channel,
                                                  Icu_ValueType*  BufferPtr,
                                                  uint16          BufferSize,
                                                  uint16          NotifyInterval);

    EXTERN_C void          Icu_StopTimestamp     (Icu_ChannelType Channel);

    EXTERN_C Icu_IndexType Icu_GetTimestampIndex (Icu_ChannelType Channel);
  #endif // ICU_TIMESTAMP_API == STD_ON

  #if (ICU_EDGE_COUNT_API == STD_ON)
    EXTERN_C void Icu_ResetEdgeCount(Icu_ChannelType Channel);

    EXTERN_C void Icu_EnableEdgeCount(Icu_ChannelType Channel);

    EXTERN_C void Icu_DisableEdgeCount(Icu_ChannelType Channel);

    EXTERN_C Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel);
  #endif // ICU_EDGE_COUNT_API == STD_ON

  #if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
    EXTERN_C void Icu_StartSignalMeasurement (Icu_ChannelType Channel);

    EXTERN_C void Icu_StopSignalMeasurement  (Icu_ChannelType Channel);
  #endif // ICU_SIGNAL_MEASUREMENT_API == STD_ON

  #if (ICU_GET_TIME_ELAPSED_API == STD_ON)
    EXTERN_C Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel);
  #endif // ICU_GET_TIME_ELAPSED_API == STD_ON

  #if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
    EXTERN_C void Icu_GetDutyCycleValues(Icu_ChannelType    Channel,
                                         Icu_DutyCycleType* DutyCycleValues);
  #endif // ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON

#endif // _ICU_2014_10_09_H_
