/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <chrono>
#include <Bsw/Mcal/Gpt/Gpt.h>
#include <Bsw/Mcal/Reg/Reg.h>

namespace mcal
{
  namespace gpt
  {
    typedef void   config_type;
    typedef uint64 value_type;

    void init(const config_type*);

    // Elapsed time in microseconds.
    value_type get_time_elapsed();
  }
}

namespace
{
  // The one (and only one) system tick.
  volatile mcal::gpt::value_type system_tick;

  bool& gpt_is_initialized()
  {
    static bool is_init;

    return is_init;
  }
/*
  uint16 consistent_16bit_timer_tick()
  {
    // Perform a consistent Read the 16-bit timer register.

    // Do the first read of the timer counter low.
    uint8 low_1 = util::dma<uint8,
                            uint8>::reg_get(mcal::reg::tcnt3l);

    // Do the first read of the timer counter high.
    uint8 high_1 = util::dma<uint8,
                             uint8>::reg_get(mcal::reg::tcnt3h);

    // Do the second read of the timer counter low.
    uint8 low_2 = util::dma<uint8,
                            uint8>::reg_get(mcal::reg::tcnt3l);

    uint16 timer_tick;

    if(low_2 >= low_1)
    {
      timer_tick = MAKEWORD(low_1, high_1);
    }
    else
    {
      const uint8 high_2 = util::dma<uint8,
                                     uint8>::reg_get(mcal::reg::tcnt3h);

      timer_tick = MAKEWORD(low_2, high_2);
    }

    return timer_tick / 2;
  }
*/
  mcal::gpt::value_type consistent_microsecond_tick()
  {
    // Return the system tick using a multiple read to ensure
    // data consistency of the system tick.

    //typedef std::uint32_t timer_address_type;
    typedef uint8 timer_register_type;

    // Do the first read of the timer counter.
    const timer_register_type timer_cnt_1 = mcal::reg::tcnt0;

    // Read the system tick once.
    const mcal::gpt::value_type sys_tick_1 = system_tick;

    // Do the second read of the timer counter.
    const timer_register_type timer_cnt_2 = mcal::reg::tcnt0;

    // Perform the consistency check and return the system tick in microseconds.
    return ((timer_cnt_2 >= timer_cnt_1) ? static_cast<mcal::gpt::value_type>(sys_tick_1  | std::uint8_t(std::uint16_t(std::uint16_t(timer_cnt_1) + 1U) >> 1U))
                                         : static_cast<mcal::gpt::value_type>(system_tick | std::uint8_t(std::uint16_t(std::uint16_t(timer_cnt_2) + 1U) >> 1U)));
  }
}

EXTERN_C
void Gpt_Init(const Gpt_ConfigType* GptConfig)
{
  static_cast<void>(GptConfig);
  mcal::gpt::init(nullptr);
}

EXTERN_C
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType StartTime)
{
  static_cast<void>(Channel);
  static_cast<void>(StartTime);
}

EXTERN_C
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
  static_cast<void>(Channel);
  return static_cast<Gpt_ValueType>(mcal::gpt::get_time_elapsed());
}

EXTERN_C void __vector_timer0_ovf_irq(void) __attribute__((signal, used, externally_visible));

void PwmTimerHook();

void __vector_timer0_ovf_irq(void)
{
  // Increment the software system tick.
  system_tick += static_cast<std::uint8_t>(0x80U);

//  PwmTimerHook();
}

mcal::gpt::value_type mcal::gpt::get_time_elapsed()
{
  return (gpt_is_initialized() ? consistent_microsecond_tick()
                               : mcal::gpt::value_type(0));
}

void mcal::gpt::init(const config_type*)
{
  // Clear the timer0 overflow flag.
  util::dma<uint8,
            uint8>::reg_set(mcal::reg::tifr0, UINT8_C(0x00));

  // Enable the timer0 overflow interrupt.
  util::dma<uint8,
            uint8>::reg_set(mcal::reg::timsk0, UINT8_C(0x01));

  // Set the timer0 clock source to f_osc/8 = 2MHz and begin counting.
  util::dma<uint8,
            uint8>::reg_set(mcal::reg::tccr0b, UINT8_C(0x02));

  // Set the is-initialized indication flag.
  gpt_is_initialized() = true;
}

// Implement std::chrono::high_resolution_clock::now()
// for the standard library high-resolution clock.
namespace std
{
  namespace chrono
  {
    high_resolution_clock::time_point high_resolution_clock::now()
    {
      // The source of the high-resolution clock is microseconds.
      typedef std::chrono::time_point<high_resolution_clock, microseconds> microseconds_type;

      // Obtain a time-point from the consistent tick in units of microseconds.
      const microseconds_type my_now(std::chrono::microseconds(::consistent_microsecond_tick()));

      // Return the corresponding duration in microseconds.
      return std::chrono::high_resolution_clock::time_point(my_now);
    }
  }
}
