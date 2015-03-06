/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Reg/Reg.h>
#include <Bsw/Mcal/Wdg/Wdg.h>

EXTERN_C
void Wdg_Init(const Wdg_ConfigType* WdgConfig)
{
  static_cast<void>(WdgConfig);
  util::dma<uint32,
            uint32>::reg_set(mcal::reg::wdt_mr, UINT32_C(0x3FFF2FFF));
}

EXTERN_C
void Wdg_Trigger(void)
{
  util::dma<uint32,
            uint32>::reg_set(mcal::reg::wdt_cr, UINT32_C(0xA5000001));
}
