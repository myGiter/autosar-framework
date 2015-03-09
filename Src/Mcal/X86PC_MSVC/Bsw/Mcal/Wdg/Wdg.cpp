/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Wdg/Wdg.h>

EXTERN_C
void Wdg_Init(const Wdg_ConfigType* ConfigPtr)
{
  static_cast<void>(ConfigPtr);
}

EXTERN_C
void Wdg_Trigger(void)
{
  static_cast<void>(0U);
}
