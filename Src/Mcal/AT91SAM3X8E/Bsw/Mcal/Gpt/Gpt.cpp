/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <cstddef>
#include <chrono>
#include <Bsw/Mcal/Gpt/Gpt.h>
#include <Bsw/Mcal/Reg/Reg.h>

namespace mcal
{
  namespace gpt
  {
    typedef void          config_type;
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

  mcal::gpt::value_type consistent_microsecond_tick()
  {
    // Return the system tick using a multiple read to ensure
    // data consistency of the system tick.

    typedef uint32 timer_address_type;
    typedef uint32 timer_register_type;

    // Do the first read of the timer counter.
    const timer_register_type timer_cnt_1 = util::dma<timer_address_type,
                                                      timer_register_type>::reg_get(mcal::reg::tc_cv0_c0);

    // Read the system tick once.
    const mcal::gpt::value_type sys_tick_1 = system_tick;

    // Do the second read of the timer counter.
    const timer_register_type timer_cnt_2 = util::dma<timer_address_type,
                                                      timer_register_type>::reg_get(mcal::reg::tc_cv0_c0);

    // Perform the consistency check and return the system tick in microseconds.
    return ((timer_cnt_2 >= timer_cnt_1) ? static_cast<mcal::gpt::value_type>(sys_tick_1  | (((timer_cnt_1 * 2) / 21)))
                                         : static_cast<mcal::gpt::value_type>(system_tick | (((timer_cnt_2 * 2) / 21))));
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

EXTERN_C void __timer0_irq_handler() __attribute__((interrupt));

void __timer0_irq_handler()
{
  // Increment the software system tick.
  system_tick += UINT32_C(0xF83E0F8);
}

mcal::gpt::value_type mcal::gpt::get_time_elapsed()
{
  return (gpt_is_initialized() ? consistent_microsecond_tick()
                               : mcal::gpt::value_type(0U));
}

void mcal::gpt::init(const config_type*)
{
  // Set up an interrupt on timer0 for a system tick based
  // on the free-running 32-bit timer0 with a frequency of 2,625MHz.

  // Set the timer prescaler to 84 resulting in a 10,5MHz frequency.
  util::dma<uint32,
            uint32>::reg_set(mcal::reg::tc_cmr0_c0, UINT32_C(0x01));

  // Start Timer.
  util::dma<uint32,
            uint32>::reg_set(mcal::reg::tc_ier0_c0, UINT32_C(0x01));

  // Enable the update interrupt.
  util::dma<uint32,
            uint32>::reg_set(mcal::reg::tc_ier0_c0, UINT32_C(0x01));

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
