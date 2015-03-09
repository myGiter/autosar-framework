/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Wdg/Wdg_Cfg.h>

EXTERN_C
const Wdg_ConfigType Wdg_ModeConfiguration =
{
  WDG_PRESCALER_500_ms | WDG_CFG_RESET
  //WDG_PRESCALER_2_s | WDG_CFG_RESET
  //WDG_CFG_NONE
};
