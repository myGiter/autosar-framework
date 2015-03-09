/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PWM_CONFIG_TYPES_2014_04_07_H_
  #define _PWM_CONFIG_TYPES_2014_04_07_H_

  #include <Bsw/Mcal/Port/Port.h>

  typedef uint16_least Pwm_PeriodType;
  typedef uint8        Pwm_ChannelType;

  EXTERN_C
  typedef enum enum_Pwm_ModeType
  {
    PWM_MODE_FAST_INVERTED,
    PWM_MODE_FAST_NONINVERTED,
    PWM_MODE_PHASECORRECT_INVERTED,
    PWM_MODE_PHASECORRECT_NONINVERTED
  }
  Pwm_ModeType;

  #define PWM_CLOCK_PRESCALE_1               ((Pwm_PeriodType) 0xC2U)
  #define PWM_CLOCK_PRESCALE_8               ((Pwm_PeriodType) 0x18U)
  #define PWM_CLOCK_PRESCALE_64              ((Pwm_PeriodType) 0x03U)
  #define PWM_CLOCK_PRESCALE_256             ((Pwm_PeriodType) 0x01U)
  #define PWM_CLOCK_PRESCALE_1024            ((Pwm_PeriodType) 0x00U)

  #define PWM_CHANNEL_B_5  PORT_PIN_B_5
  #define PWM_CHANNEL_B_6  PORT_PIN_B_6
  #define PWM_CHANNEL_B_7  PORT_PIN_B_7

  #define PWM_CHANNEL_C_6  PORT_PIN_C_6
  #define PWM_CHANNEL_C_7  PORT_PIN_C_7

  #define PWM_CHANNEL_D_0  PORT_PIN_D_0
//  #define PWM_CHANNEL_D_6  PORT_PIN_D_6
//  #define PWM_CHANNEL_D_7  PORT_PIN_D_7

  # define PWM_SW_CHANNEL_D_5 0

#endif // _PWM_CONFIG_TYPES_2014_04_07_H_
