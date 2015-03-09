/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PWM_2014_10_09_H_
  #define _PWM_2014_10_09_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Pwm/Pwm_Cfg.h>

  typedef enum enum_Pwm_OutputStateType
  {
    PWM_HIGH,
    PWM_LOW
  }
  Pwm_OutputStateType;

  typedef enum enum_Pwm_EdgeNotificationType
  {
    PWM_RISING_EDGE,
    PWM_FALLING_EDGE,
    PWM_BOTH_EDGES
  }
  Pwm_EdgeNotificationType;

  typedef enum enum_Pwm_ChannelClassType
  {
    PWM_VARIABLE_PERIOD,
    PWM_FIXED_PERIOD,
    PWM_FIXED_PERIOD_SHIFTED
  }
  Pwm_ChannelClassType;

  EXTERN_C void Pwm_Init(const Pwm_ConfigType* ConfigPtr);

  #if (PWM_DE_INIT_API == STD_ON)
    EXTERN_C void Pwm_DeInit(void);
  #endif // PWM_DE_INIT_API == STD_ON

  #if (PWM_SET_DUTY_CYCLE_API == STD_ON)
    EXTERN_C void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber,
                                   uint16          DutyCycle);
  #endif // PWM_SET_DUTY_CYCLE_API == STD_ON

  #if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
    EXTERN_C void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber,
                                       Pwm_PeriodType  Period,
                                       uint16          DutyCycle);
  #endif // PWM_SET_PERIOD_AND_DUTY_API == STD_ON

  #if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
    EXTERN_C void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber);
  #endif // PWM_SET_OUTPUT_TO_IDLE_API == STD_ON

  #if (PWM_GET_OUTPUT_STATE_API == STD_ON)
    EXTERN_C Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber);
  #endif // PWM_GET_OUTPUT_STATE_API == STD_ON


  #if (PWM_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    EXTERN_C void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber);

    EXTERN_C void Pwm_EnableNotification (Pwm_ChannelType          ChannelNumber,
                                          Pwm_EdgeNotificationType Notification);
  #endif // PWM_ENABLE_DISABLE_NOTIFICATION_API == STD_ON

#endif // _PWM_2014_10_09_H_
