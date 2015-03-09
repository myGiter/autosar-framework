/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _WDG_CONFIG_TYPES_2014_12_10_H_
  #define _WDG_CONFIG_TYPES_2014_12_10_H_

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

#endif // _WDG_CONFIG_TYPES_2014_12_10_H_
