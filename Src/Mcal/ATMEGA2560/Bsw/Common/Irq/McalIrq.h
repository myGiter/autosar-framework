/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef MCAL_IRQ_2015_02_16_H
  #define MCAL_IRQ_2015_02_16_H

  #include <Bsw/Common/Std_Types.h>

  INLINE void McalIrqEnableAll () { __asm__ volatile ("sei"); }
  INLINE void McalIrqDisableAll() { __asm__ volatile ("cli"); }

  EXTERN_C void McalIrqInit(void);

  #if defined(__cplusplus)

    namespace mcal
    {
      namespace irq
      {
        inline void enable_all (void) { McalIrqEnableAll(); }
        inline void disable_all(void) { McalIrqDisableAll(); }
      }
    }

  #endif

#endif // MCAL_IRQ_2015_02_16_H
