/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _HAL_CPU_2012_12_07_H_
  #define _HAL_CPU_2012_12_07_H_

  #include <Bsw/Common/Std_Types.h>

  INLINE void McalCpuNop(void) { __asm__ volatile ("nop"); }

  #if defined(__cplusplus)

    namespace mcal
    {
      namespace cpu
      {
        inline void nop(void) { McalCpuNop(); }
      }
    }

  #endif

#endif // _HAL_CPU_2012_12_07_H_
