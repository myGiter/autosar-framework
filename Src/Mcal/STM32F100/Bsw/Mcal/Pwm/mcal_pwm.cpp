/////////////////////////////////////////////////////// 
//  Copyright 2014 Panagiotis Bezirgiannidis
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <algorithm>
//#include <atomic>
#include <Bsw/Mcal/Pwm/mcal_pwm.h>

mcal::pwm::pwm_type::pwm_type(const Dio_ChannelType channel,
                              const Port_PinType    port,
                              const period_type     per,
                              const period_type     duty) : dio_channel      (channel),
                                                            port_id          (port),
                                                            counter          (0U),
                                                            period           (per),
                                                            duty_cycle       (duty),
                                                            shadow           (duty),
                                                            prescaler_value  (1U),
                                                            prescaler_counter(0U)
{
  // Set the port pin to output with logic level low.
  Dio_WriteChannel    (dio_channel, STD_LOW);
  Port_SetPinDirection(port_id, PORT_PIN_OUT);
}

void mcal::pwm::pwm_type::set_duty(const period_type& duty)
{
  // Set a new duty cycle in the shadow register.
//  std::atomic_store<period_type>(&shadow, (std::min)(duty, period));
  shadow = (std::min)(duty, period);
}

mcal::pwm::pwm_type::period_type mcal::pwm::pwm_type::get_duty() const
{
  // Retrieve the duty cycle.
//  return std::atomic_load(&duty_cycle);
  return duty_cycle;
}

void mcal::pwm::pwm_type::service()
{
  if(duty_cycle == 0U)
  {
    // Output low if duty cycle == 0U.
    Dio_WriteChannel(dio_channel, STD_LOW);
  }
  else if(duty_cycle == period)
  {
    // Output high if duty_cycle == period.
    Dio_WriteChannel(dio_channel, STD_HIGH);
  }
  else
  {
    // Output high if counter less than duty cycle.
    // Output low if counter exceeds duty cycle.
    ((counter <= duty_cycle) ? Dio_WriteChannel(dio_channel, STD_HIGH)
                             : Dio_WriteChannel(dio_channel, STD_LOW));
  }

  // Increment the counter in combination with the prescaler.

  if(prescaler_counter >= prescaler_value)
  {
    prescaler_counter = 0U;
    ++counter;
  }

  ++prescaler_counter;

  if(counter >= period)
  {
    // Latch duty cycle from the shadow register.
    duty_cycle = shadow;

    // Reset the counter for a new PWM period.
    counter = 0U;
  }
}
