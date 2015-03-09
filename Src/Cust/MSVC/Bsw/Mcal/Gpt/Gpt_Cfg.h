/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef GPT_CFG_2015_03_05_H
  #define GPT_CFG_2015_03_05_H

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Gpt/Gpt_ConfigTypes.h>

  #define GPT_DE_INIT_API                 STD_OFF
  #define GPT_TIME_ELAPSED_API            STD_ON
  #define GPT_GET_TIME_REMAINING_API      STD_OFF
  #define GPT_START_STOP_TIMER_API        STD_ON
  #define GPT_SET_MODE_API                STD_OFF
  #define GPT_WAKEUP_API                  STD_OFF
  #define GPT_ECUM_WAKEUPSOURCE_API       STD_OFF

  typedef uint32 Gpt_ConfigType;
  typedef uint32 Gpt_ConfigType;

  EXTERN_C const Gpt_ConfigType GptDriverConfiguration;

#endif // GPT_CFG_2015_03_05_H

