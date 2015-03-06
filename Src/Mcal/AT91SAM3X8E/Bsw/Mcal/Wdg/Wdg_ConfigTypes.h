/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef WDG_CONFIG_TYPES_2015_01_30_H
  #define WDG_CONFIG_TYPES_2015_01_30_H

  typedef bool WDG_DISABLE_ALLOWED;

  EXTERN_C
  typedef enum enum_WdgIf_StatusType
  {
    WDGIF_UNINIT,
    WDGIF_IDLE,
    WDGIF_BUSY
  }
  WdgIf_StatusType;

  EXTERN_C
  typedef enum enum_WdgIf_ModeType
  {
    WDGIF_OFF_MODE,
    WDGIF_SLOW_MODE,
    WDGIF_FAST_MODE
  }
  WdgIf_ModeType;

#endif // WDG_CONFIG_TYPES_2015_01_30_H
