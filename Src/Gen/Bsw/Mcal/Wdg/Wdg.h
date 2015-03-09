/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _WDG_2014_10_09_H_
  #define _WDG_2014_10_09_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Wdg/Wdg_Cfg.h>

  EXTERN_C void Wdg_Init(const Wdg_ConfigType* ConfigPtr);
  EXTERN_C void Wdg_Trigger(void);
  EXTERN_C Std_ReturnType Wdg_SetMode(WdgIf_ModeType Mode);

#endif // _WDG_2014_10_09_H_
