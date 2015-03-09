/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <windows.h>
#include <Bsw/Mcal/Gpt/Gpt.h>

namespace
{
  Gpt_ValueType consistent_microsecond_tick()
  {
    // Sleep in order to reduce the load on a Win32 simulated target.
    static std::uint_least16_t prescale;
    ++prescale;

    ::Sleep((std::uint_least16_t(prescale % 4096U) == std::uint_least16_t(0U)) ? 3U : 0U);

    static bool is_initialized;

    static LARGE_INTEGER start_time;
    static LARGE_INTEGER frequency;

    if(is_initialized == false)
    {
      is_initialized = true;

      ::QueryPerformanceFrequency(&frequency);
      ::QueryPerformanceCounter(&start_time);
    }

    LARGE_INTEGER tick;
    ::QueryPerformanceCounter(&tick);

    const std::uint64_t elapsed = static_cast<std::uint64_t>(tick.QuadPart - start_time.QuadPart);

    return Gpt_ValueType((double(elapsed) / double(frequency.QuadPart)) * 1000000.0);
  }
}

EXTERN_C
void Gpt_Init(const Gpt_ConfigType* GptConfig)
{
  static_cast<void>(GptConfig);
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
  return consistent_microsecond_tick();
}

EXTERN_C
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
  static_cast<void>(Channel);
  return Gpt_ValueType(0U);
}

EXTERN_C
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Gpt_SetMode(Gpt_ModeType Mode)
{
  static_cast<void>(Mode);
}

EXTERN_C
void Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Gpt_EnableWakeup(Gpt_ChannelType Channel)
{
  static_cast<void>(Channel);
}

/*
EXTERN_C
void Gpt_Cbk_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
  static_cast<void>(WakeupSource);
}
*/
