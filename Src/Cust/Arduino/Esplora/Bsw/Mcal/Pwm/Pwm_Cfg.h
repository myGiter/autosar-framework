/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PWM_CFG_2014_11_03_H_
  #define _PWM_CFG_2014_11_03_H_

  // includes.
  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Pwm/Pwm_ConfigTypes.h>

  // AUTOSAR-API.
  #define PWM_DE_INIT_API                 STD_OFF
  #define PWM_SET_DUTY_CYCLE_API          STD_ON
  #define PWM_SET_PERIOD_AND_DUTY_API     STD_ON
  #define PWM_SET_OUTPUT_TO_IDLE_API      STD_OFF
  #define PWM_GET_OUTPUT_STATE_API        STD_OFF

  // Container collecting the PwmChannels.
  typedef struct struct_PwmChannel
  {

//    const Pwm_ChannelClassType PwmChannelClass;
    const Pwm_ChannelType      PwmChannelId;
//    const uint16               PwmDutycycleDefault;
//    const Pwm_OutputStateType  PwmIdleState;
//  PwmNotification;
//    const Pwm_PeriodType       PwmPeriodDefault;
//    const Pwm_OutputStateType  PwmPolarity;

    const Pwm_ModeType    Mode;
    const uint16          DutyDefault;


  }
  tPwmChannel;
/*
  // Container collecting the PwmSwChannels.
  typedef struct struct_PwmSwChannel
  {
    const Pwm_ChannelType  PwmChannelId;
    const uint16           DutyDefault;
    const uint16           PeriodDefault;
  }
  tPwmSwChannel;
*/


  // Number of configurated PwmChannels.
  typedef struct struct_Pwm_ConfigType
  {
    const tPwmChannel   PwmChannelConfigSet[4U];
    //const tPwmSwChannel PwmSwChannelConfigSet[1U];
  }
  Pwm_ConfigType;

  EXTERN_C const Pwm_ConfigType Pwm_ConfigSet;

#endif // _PWM_CFG_2014_11_03_H_
