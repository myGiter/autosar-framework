/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <iomanip>
#include <iostream>
#include <Bsw/Common/Std_Types.h>
#include <Bsw/Mcal/Pwm/Pwm.h>

class pwm_type
{
public:
  pwm_type(const uint8_least period) : period_value      (period),
                                       duty_cycle_value  (0U),
                                       duty_cycle_counter(0U),
                                       duty_shadow_value (0U) { }

  void set_duty(const uint8_least duty_cycle)
  {
     duty_cycle_value = duty_cycle;
  }

  uint8_least get_duty() const
  {
    return duty_cycle_value;
  }

  uint8_least get_period() const
  {
    return period_value;
  }

  void service()
  {
    if(duty_cycle_counter >= duty_cycle_value)
    {
      // TBD: Set the port low.
    }
    else
    {
      // TBD: Set the port high.
    }

    ++duty_cycle_counter;

    if(duty_cycle_counter >= period_value)
    {
      duty_cycle_value = duty_shadow_value;
    }
  }

private:
  const uint8_least period_value;
  uint8_least duty_cycle_value;
  uint8_least duty_cycle_counter;
  uint8_least duty_shadow_value;
};

namespace
{
  pwm_type my_pwm_channels[3U] =
  {
    pwm_type(100U),
    pwm_type(100U),
    pwm_type(100U)
  };
}

EXTERN_C
void Pwm_Init(const Pwm_ConfigType* ConfigPtr)
{
  static_cast<void>(ConfigPtr);
}

EXTERN_C
void Pwm_DeInit(void)
{
  static_cast<void>(0U);
}

EXTERN_C
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
  static_cast<void>(ChannelNumber);
  static_cast<void>(DutyCycle);
/*
  if(ChannelNumber < countof(my_pwm_channels))
  {
    const uint8_least new_duty = (static_cast<uint32>(DutyCycle) * my_pwm_channels[ChannelNumber].get_period()) / 0x8000U;

    my_pwm_channels[ChannelNumber].set_duty(new_duty);
  }
*/
}

EXTERN_C
void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle)
{
  static_cast<void>(ChannelNumber);
  static_cast<void>(Period);
  static_cast<void>(DutyCycle);
}

EXTERN_C
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber)
{
  static_cast<void>(ChannelNumber);
}

EXTERN_C
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber)
{
  static_cast<void>(ChannelNumber);
  return Pwm_OutputStateType(0U);
}

EXTERN_C
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber)
{
  static_cast<void>(ChannelNumber);
}

EXTERN_C
void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification)
{
  static_cast<void>(ChannelNumber);
  static_cast<void>(Notification);
}
