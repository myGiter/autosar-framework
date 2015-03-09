/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _MCAL_IRQ_2014_10_14_H_
  #define _MCAL_IRQ_2014_10_14_H_

  #include <Bsw/Common/Std_Types.h>

  INLINE void McalIrqEnableAll () { __asm__ volatile ("cpsid i"); }
  INLINE void McalIrqDisableAll() { __asm__ volatile ("cpsie i"); }

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

#endif // _MCAL_IRQ_2014_10_14_H_
