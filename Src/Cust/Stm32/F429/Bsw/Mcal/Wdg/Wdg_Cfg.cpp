/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Wdg/Wdg_Cfg.h>

EXTERN_C
const Wdg_ConfigType Wdg_ModeConfiguration =
{
  // Set the Wdg_Prescaler.
  //WDG_PRESCALER_500_us,
  //WDG_PRESCALER_1_ms,
  //WDG_PRESCALER_2_ms,
//  WDG_PRESCALER_4_ms,
  //WDG_PRESCALER_8_ms,
  //WDG_PRESCALER_16_ms,
  //WDG_PRESCALER_32_ms,

  // Set the Wdg_ReloadValue, by default 0x0FFF.
//  UINT16_C(0x0FFF)
  0U
};
