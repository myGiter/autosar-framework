/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PWM_CFG_2013_03_26_H_
  #define _PWM_CFG_2013_03_26_H_

  #include <Bsw/Common/Std_Types.h>
  
  #define PWM_DE_INIT_API                 STD_OFF
  #define PWM_SET_DUTY_CYCLE_API          STD_OFF
  #define PWM_SET_PERIOD_AND_DUTY_API     STD_OFF
  #define PWM_SET_OUTPUT_TO_IDLE_API      STD_OFF
  #define PWM_GET_OUTPUT_STATE_API        STD_OFF

  typedef uint16_least Pwm_PeriodType;
  typedef uint32       Pwm_ChannelType;

  typedef struct struct_Pwm_ConfigType
  {
    uint32 dummy;
  }
  Pwm_ConfigType;

  EXTERN_C const Pwm_ConfigType Pwm_ConfigSet;

#endif // _PWM_CFG_2013_03_26_H_
