/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Pwm/mcal_pwm.h>

mcal::pwm::pwm_type::pwm_type(const std::uint8_t addr,
                              const std::uint8_t bpos,
                              const period_type per,
                              const period_type duty) : address          (addr),
                                                           bit_position     (bpos),
                                                           counter          (0U),
                                                           period           (per),
                                                           duty_cycle       (duty),
                                                           shadow           (duty),
                                                           prescaler_value  (1U),
                                                           prescaler_counter(0U)
{
  // Set the port pin to output with logic level low.
  util::dma<std::uint8_t,
            std::uint8_t>::bit_clr(address, bit_position);

  util::dma<std::uint8_t,
            std::uint8_t>::bit_set(address - 1U, bit_position);

  static_cast<void>(prescaler_value);
}

  void mcal::pwm::pwm_type::set_duty(const period_type duty)
  {
    // Set a new duty cycle in the shadow register.
    std::atomic_store(&shadow, (std::min)(duty, period));
  }

  mcal::pwm::pwm_type::period_type mcal::pwm::pwm_type::get_duty() const
  {
    // Retrieve the duty cycle.
    return std::atomic_load(&duty_cycle);
  }

  void mcal::pwm::pwm_type::service()
  {
    if(duty_cycle == 0U)
    {
      // Output low if  duty cycle == 0U.
      util::dma<std::uint8_t,
                std::uint8_t>::bit_clr(address, bit_position);
    }
    else if(duty_cycle == period)
    {
      // Output high if duty_cycle == period.
      util::dma<std::uint8_t,
                std::uint8_t>::bit_set(address, bit_position);
    }
    else
    {
      // Output high if counter less than duty cycle.
      // Output low if counter exceeds duty cycle.
      ((counter <= duty_cycle) ? util::dma<std::uint8_t, std::uint8_t>::bit_set(address, bit_position)
                               : util::dma<std::uint8_t, std::uint8_t>::bit_clr(address, bit_position));
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

  mcal::pwm::pwm_type::period_type mcal::pwm::pwm_type::get_period() const { return period; }
