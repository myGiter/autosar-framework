/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef GPT_CFG_2015_01_30_H
  #define GPT_CFG_2015_01_30_H

  // includes.
  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Gpt/Gpt_ConfigTypes.h>

  // AUTOSAR-API.
  #define GPT_DEINIT_API                      STD_OFF
  #define GPT_TIME_ELAPSED_API                STD_ON
  #define GPT_TIME_REMAINING_API              STD_OFF
  #define GPT_ENABLE_DISABLE_NOTIFICATION_API STD_OFF
  #define GPT_WAKEUP_FUNCTIONALITY_API        STD_OFF

  typedef struct struct_GptChannelConfigSet
  {
    uint32 dummy;
  }
  tGptChannelConfigSet;

  typedef struct struct_Gpt_ConfigType
  {
    const tGptChannelConfigSet GptChannelConfiguration;
  }
  Gpt_ConfigType;

  EXTERN_C const Gpt_ConfigType GptDriverConfiguration;

#endif // GPT_CFG_2015_01_30_H
