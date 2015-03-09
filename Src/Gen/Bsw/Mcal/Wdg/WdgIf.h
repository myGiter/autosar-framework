/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _WDGIF_2014_04_30_H_
  #define _WDGIF_2014_04_30_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Wdg/WdgIf_Cfg.h>

  EXTERN_C Std_ReturnType WdgIf_SetMode(uint8 DeviceIndex, WdgIf_ModeType WdgMode);
  EXTERN_C void WdgIf_Trigger(uint8 DeviceIndex);

#endif // _WDGIF_2014_04_30_H_
