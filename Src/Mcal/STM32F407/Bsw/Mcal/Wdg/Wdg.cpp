/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Reg/Reg.h>
#include <Bsw/Mcal/Wdg/Wdg.h>
#include "mcal_wdg.h"

EXTERN_C
void Wdg_Init(const Wdg_ConfigType* WdgConfig)
{
  static_cast<void>(WdgConfig);
  mcal::wdg::init(nullptr);
}

EXTERN_C
void Wdg_Trigger(void)
{
  mcal::wdg::trigger();
}
