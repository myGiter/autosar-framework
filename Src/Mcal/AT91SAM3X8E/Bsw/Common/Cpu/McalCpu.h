/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef MCAL_CPU_2015_01_30_H
  #define MCAL_CPU_2015_01_30_H

  #include <Bsw/Common/Std_Types.h>

  void McalCpuInit(void);

  INLINE void McalCpuNop(void) { __asm__ volatile ("nop"); }

  #if defined(__cplusplus)

    namespace mcal
    {
      namespace cpu
      {
        inline void nop() { ::McalCpuNop(); }
      }
    }

  #endif

#endif // MCAL_CPU_2015_01_30_H
