/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Pwm/Pwm_Cfg.h>

EXTERN_C
const Pwm_ConfigType Pwm_ConfigSet =
{
  {
    {
      // PwmChannelID.
      PWM_CHANNEL_B_5,
      // Pwm_MODE.
      PWM_MODE_FAST_NONINVERTED,
      // Default Value for DutyCycle.
      UINT16_C(0x8000)
    },
    {
      // PwmChannelID.
      PWM_CHANNEL_B_6,
      // Pwm_MODE.
      PWM_MODE_FAST_NONINVERTED,
      // Default Value for DutyCycle.
      UINT16_C(0x8000)
    },
    {
      // PwmChannelID.
      PWM_CHANNEL_C_6,
      // Pwm_MODE.
      PWM_MODE_FAST_NONINVERTED,
      // Default Value for DutyCycle.
      UINT16_C(0x8000)
    }
  }
};


/*
          mcal::pwm::pwm_type pwm_on_port_d5(mcal::reg::portd,
                                   UINT8_C(5),
                                   UINT8_C(0x80),
                                   UINT8_C(0x40),
                                   2U);
*/
