/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _GPT_2014_10_09_H_
  #define _GPT_2014_10_09_H_

  #include <Bsw/Mcal/Gpt/Gpt_Cfg.h>

  typedef uint64 Gpt_ValueType;

  EXTERN_C
  typedef enum enum_Gpt_ModeType
  {
    GPT_MODE_NORMAL,
    GPT_MODE_SLEEP
  }
  Gpt_ModeType;

  EXTERN_C void Gpt_Init(const Gpt_ConfigType* Gpt_Config);

  #if (GPT_DEINIT_API == STD_ON)
    EXTERN_C void Gpt_DeInit(void);
  #endif // GPT_DEINIT_API == STD_ON

  #if (GPT_TIME_ELAPSED_API == STD_ON)
    EXTERN_C Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
  #endif // GPT_TIME_ELAPSED_API == STD_ON

  #if (GPT_TIME_REMAINING_API == STD_ON)
    EXTERN_C Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
  #endif // GPT_TIME_REMAINING_API == STD_ON

  EXTERN_C void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

  EXTERN_C void Gpt_StopTimer(Gpt_ChannelType Channel);

  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    EXTERN_C void Gpt_EnableNotification(Gpt_ChannelType Channel);

    EXTERN_C void Gpt_DisableNotification(Gpt_ChannelType Channel);
  #endif // GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON

  #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    EXTERN_C void Gpt_SetMode(Gpt_ModeType Mode);

    EXTERN_C void Gpt_DisableWakeup(Gpt_ChannelType Channel);

    EXTERN_C void Gpt_EnableWakeup(Gpt_ChannelType Channel);

    EXTERN_C void Gpt_Cbk_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
  #endif // GPT_WAKEUP_FUNCTIONALITY_API == STD_ON

#endif // _GPT_2014_10_09_H_
