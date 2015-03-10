/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef MCAL_PWR_2015_03_10_H
  #define MCAL_PWR_2015_03_10_H

  #include <Bsw/Common/Std_Types.h>

  INLINE void McalPwrSleepNow(void)    { __asm__ volatile ("wfi"); }
  INLINE void McalPwrSleepOnExit(void) { __asm__ volatile ("wfe"); }

  #if defined(__cplusplus)

    namespace mcal
    {
      namespace pwr
      {
        inline void sleep_now()     { ::McalPwrSleepNow();    }
        inline void sleep_on_exit() { ::McalPwrSleepOnExit(); }
      }
    }

  #endif

#endif // MCAL_PWR_2015_03_10_H
