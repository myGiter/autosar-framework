/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef MCAL_IRQ_2015_03_05_H
  #define MCAL_IRQ_2015_03_05_H
  #include <Bsw/Common/Std_Types.h>

  // *****************************************************************************
  // inline functions
  // *****************************************************************************

  INLINE void McalIrqDisableAll(void) { }
  INLINE void McalIrqEnableAll(void)  { }

  EXTERN_C void McalIrqInit(void);

  #if defined(__cplusplus)

    namespace mcal
    {
      namespace irq
      {
        inline void disable_all(void) { }
        inline void enable_all (void) { }
      }
    }

  #endif

#endif // MCAL_IRQ_2015_03_05_H
