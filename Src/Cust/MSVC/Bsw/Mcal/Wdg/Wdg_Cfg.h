/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _WDG_CFG_2012_12_10_H_
  #define _WDG_CFG_2012_12_10_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Wdg/Wdg_ConfigTypes.h>

  typedef struct struct_Wdg_ConfigType
  {
    uint32 dummy;
  }
  Wdg_ConfigType;

//  EXTERN_C const Wdg_ConfigType Wdg_CfgMyConfig;
  EXTERN_C const Wdg_ConfigType Wdg_ModeConfiguration;

#endif // _WDG_CFG_2012_12_10_H_
