/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef MCAL_WDG_2015_02_18_H
  #define MCAL_WDG_2015_02_18_H

  #include <Bsw/Common/Std_Types.h>

  INLINE void McalWdgReset () { __asm__ volatile ("wdr"); }

  #if defined(__cplusplus)

    namespace mcal
    {
      namespace wdg
      {
        inline void wdg_reset (void) { McalWdgReset(); }
      }
    }

  #endif

#endif // MCAL_WDG_2015_02_18_H
