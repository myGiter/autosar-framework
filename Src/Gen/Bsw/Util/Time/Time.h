/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _TIME_2014_10_13_H_
  #define _TIME_2014_10_13_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Gpt/Gpt.h>

  #define USEC(x) ((Gpt_ValueType) (       1U  * (x)))
  #define MSEC(x) ((Gpt_ValueType) (    1000UL * (x)))
  #define SEC(x)  ((Gpt_ValueType) ( 1000000UL * (x)))
  #define MIN(x)  ((Gpt_ValueType) (60000000UL * (x)))

  #if defined(__cplusplus)
  #include <Bsw/Util/Time/UtilTime.hpp>
  #endif

  // *****************************************************************************
  // types 
  // *****************************************************************************
  typedef uint8  MTIMER;
  typedef uint16 STIMER;
  typedef uint32  TIMER;

  // *****************************************************************************
  // macros 
  // *****************************************************************************
  #define TimerMiniStart(T)         (  (MTIMER) ((MTIMER) Gpt_GetTimeElapsed(0U) + (MTIMER) (T)))
  #define TimerMiniTimeout(T)       (((MTIMER) (((MTIMER) ((MTIMER) Gpt_GetTimeElapsed(0U) - (MTIMER) (T)) & (MTIMER) 0x80U))        == (MTIMER) 0U) ? TRUE : FALSE)
  #define TimerMiniGetTimeSince(T)  (  (MTIMER) ((MTIMER) Gpt_GetTimeElapsed(0U) - (MTIMER) (T)))

  #define TimerShortStart(T)        (  (STIMER) ((STIMER) Gpt_GetTimeElapsed(0U) + (STIMER) (T)))
  #define TimerShortTimeout(T)      (((STIMER) (((STIMER) ((STIMER) Gpt_GetTimeElapsed(0U) - (STIMER) (T)) & (STIMER) 0x8000U))      == (STIMER) 0U) ? TRUE : FALSE)
  #define TimerShortGetTimeSince(T) (  (STIMER) ((STIMER) Gpt_GetTimeElapsed(0U) - (STIMER) (T)))

  #define TimerStart(T)             (  ( TIMER) (( TIMER) Gpt_GetTimeElapsed(0U) + ( TIMER) (T)))
  #define TimerTimeout(T)           ((( TIMER) ((( TIMER) (( TIMER) Gpt_GetTimeElapsed(0U) - ( TIMER) (T)) & ( TIMER) 0x80000000UL)) == ( TIMER) 0U) ? TRUE : FALSE)
  #define TimerGetTimeSince(T)      (  ( TIMER) (( TIMER) Gpt_GetTimeElapsed(0U) - ( TIMER) (T)))

#endif // _TIME_2014_10_13_H_
