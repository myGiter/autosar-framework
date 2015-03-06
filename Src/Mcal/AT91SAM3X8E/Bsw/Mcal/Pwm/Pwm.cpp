/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <array>
#include <Bsw/Mcal/Pwm/mcal_pwm.h>
#include <Bsw/Mcal/Pwm/Pwm.h>
#include <Bsw/Mcal/Reg/Reg.h>

/*
namespace
{
  mcal::pwm::pwm_type pwm0(0U, 0x80U);
  mcal::pwm::pwm_type pwm1(1U, 0x80U);
  mcal::pwm::pwm_type pwm2(2U, 0x80U);

  std::array<mcal::pwm::pwm_type*, 3U> my_pwm_channels =
  {{
    &pwm0,
    &pwm1,
    &pwm2,
  }};
}
*/
/*
void PwmTimerHook()
{
  my_pwm_channels[0U]->service();
  my_pwm_channels[1U]->service();
  my_pwm_channels[2U]->service();
}
*/
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
  if(ChannelNumber < my_pwm_channels.size())
  {
    const uint32_least new_duty = (static_cast<uint32>(DutyCycle) * my_pwm_channels[ChannelNumber]->get_period()) / 0x8000U;

    my_pwm_channels[ChannelNumber]->set_duty(new_duty);
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
