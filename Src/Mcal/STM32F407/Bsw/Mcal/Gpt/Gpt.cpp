/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
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
    typedef std::uint64_t value_type;

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

    typedef std::uint32_t timer_address_type;
    typedef std::uint16_t timer_register_type;

    // Do the first read of the timer counter.
    const timer_register_type timer_cnt_1 = util::dma<timer_address_type,
                                                      timer_register_type>::reg_get(mcal::reg::tim4_cnt);

    // Read the system tick once.
    const mcal::gpt::value_type sys_tick_1 = system_tick;

    // Do the second read of the timer counter.
    const timer_register_type timer_cnt_2 = util::dma<timer_address_type,
                                                      timer_register_type>::reg_get(mcal::reg::tim4_cnt);

    // Perform the consistency check and return the system tick in microseconds.
    return ((timer_cnt_2 >= timer_cnt_1) ? static_cast<mcal::gpt::value_type>(sys_tick_1  | timer_cnt_1)
                                         : static_cast<mcal::gpt::value_type>(system_tick | timer_cnt_2));
  }

  // Define a memory-mapped structure for manipulating
  // the timer4 interrupt priority. This memory-mapped
  // structure has been taken from the STM32 peripheral library,
  // with slight modifications by Chris.
  typedef struct struct_nvic_type
  {
    volatile std::uint32_t iser[8U];        // Offset: 0x000  Interrupt Set Enable Register.
             std::uint32_t reserved0[24U];
    volatile std::uint32_t icer[8U];        // Offset: 0x080  Interrupt Clear Enable Register.
             std::uint32_t reserved1[24U];
    volatile std::uint32_t ispr[8U];        // Offset: 0x100  Interrupt Set Pending Register.
             std::uint32_t reserved2[24U];
    volatile std::uint32_t icpr[8U];        // Offset: 0x180  Interrupt Clear Pending Register.
             std::uint32_t reserved3[24U];
    volatile std::uint32_t iabr[8U];        // Offset: 0x200  Interrupt Active bit Register.
             std::uint32_t reserved4[56U];
    volatile std::uint8_t  ip[240U];        // Offset: 0x300  Interrupt Priority Register (8Bit wide).
             std::uint32_t reserved5[644U];
    volatile std::uint32_t stir;            // Offset: 0xE00  Software Trigger Interrupt Register.
  }
  nvic_type;
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

EXTERN_C void __timer4_irq_handler() __attribute__((interrupt));

void PwmTimerHook();

void __timer4_irq_handler()
{
  // Clear the interrupt request bit.
  util::dma<uint32,
            uint16>::reg_set(mcal::reg::tim4_sr,
                             UINT16_C(0x0000));

  // Increment the software system tick.
  system_tick += UINT32_C(0x10000);

  // Service Software-PWM.
  PwmTimerHook();
}

mcal::gpt::value_type mcal::gpt::get_time_elapsed()
{
  return (gpt_is_initialized() ? consistent_microsecond_tick()
                               : mcal::gpt::value_type(0U));
}

void mcal::gpt::init(const config_type*)
{
  // Set up an interrupt on timer4 for a system tick based
  // on the free-running 16-bit timer4 with a frequency of 1MHz.

  // Power management: Enable the power for timer4.
  util::dma<uint32,
            uint32>::reg_or(mcal::reg::rcc_apb1enr,
                            UINT32_C(0x00000004));

  // Compute the timer4 interrupt priority.
  const std::uint32_t aircr_value = util::dma<uint32,
                                              uint32>::reg_get(mcal::reg::aircr);

  // This following code sequence has been inspired by
  // parts of the STM32 peripheral library.
  const std::uint32_t tmp_prio((0x700UL - (aircr_value & 0x700UL)) >> 0x08);
  const std::uint32_t tmp_pre (0x04UL - tmp_prio);
  const std::uint32_t tmp_sub (0x0FUL >> tmp_prio);

  constexpr std::uint32_t timer4_nvic_irq_preemption_prio(0x0FUL);
  constexpr std::uint32_t timer4_nvic_irq_sub_prio       (0x0FUL);

  constexpr std::size_t timer4_irq_n = 30UL;

  // Place the memory-mapped NVIC configuration structure.
  // This sequence has been inspired by the STM32 peripheral library.
  constexpr nvic_type* nvic_ptr = reinterpret_cast<nvic_type*>(0xE000E100UL);

  // Set the timer4 interrupt priority.
  nvic_ptr->ip  [timer4_irq_n] =
    std::uint32_t(std::uint32_t(  static_cast<std::uint32_t>(timer4_nvic_irq_preemption_prio << tmp_pre)
                                | static_cast<std::uint32_t>(timer4_nvic_irq_sub_prio & tmp_sub)
                               ) << 0x04U);

  nvic_ptr->iser[timer4_irq_n >> 0x05U] =
    std::uint32_t(std::uint32_t(1UL) << (timer4_irq_n & 0x1FU));

  // Clear the interrupt request bit.
  util::dma<uint32,
            uint16>::reg_set(mcal::reg::tim4_sr,
                             UINT16_C(0x0000));

  // Enable the update interrupt.
  util::dma<uint32,
            uint16>::reg_set(mcal::reg::tim4_dier,
                             UINT16_C(0x0001));

  // Set the timer prescaler to 24 resulting in a 1MHz frequency.
  util::dma<uint32,
            uint16>::reg_set(mcal::reg::tim4_psc,
                             UINT16_C(84 - 1));

  // Set the auto-reload register for the entire 16-bit period of the timer.
  util::dma<uint32,
            uint16>::reg_set(mcal::reg::tim4_arr,
                             UINT16_C(0xFFFF));

  // Set the counter direction to counting-up and enable the counter.
  util::dma<uint32,
            uint16>::reg_set(mcal::reg::tim4_cr1,
                             UINT16_C(0x0001));

  // Re-initialize the counter and generate an update of the registers.
  util::dma<uint32,
            uint16>::reg_set(mcal::reg::tim4_egr,
                             UINT16_C(0x0001));

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
