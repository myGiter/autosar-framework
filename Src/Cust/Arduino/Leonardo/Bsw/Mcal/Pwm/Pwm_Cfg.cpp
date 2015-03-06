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
      PWM_CHANNEL_D_0,
      // Pwm_MODE.
      PWM_MODE_FAST_NONINVERTED
    }
  }
};
