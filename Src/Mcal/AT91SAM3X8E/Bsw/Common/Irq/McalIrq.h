/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef MCAL_IRQ_2015_01_30_H
  #define MCAL_IRQ_2015_01_30_H

  INLINE void McalIrqDisableAll() { __asm__ volatile ("cpsid i"); }
  INLINE void McalIrqEnableAll () { __asm__ volatile ("cpsie i"); }

  EXTERN_C void McalIrqInit(void);

  #if defined(__cplusplus)

    namespace mcal
    {
      namespace irq
      {
        inline void disable_all(void) { ::McalIrqDisableAll(); }
        inline void enable_all (void) { ::McalIrqEnableAll(); }
      }
    }

  #endif

#endif // MCAL_IRQ_2015_01_30_H
