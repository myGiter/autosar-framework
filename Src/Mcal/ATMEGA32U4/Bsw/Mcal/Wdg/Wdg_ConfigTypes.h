/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef WDG_CONFIG_TYPES_2014_10_14_H
  #define WDG_CONFIG_TYPES_2014_10_14_H

  #define WDG_PRESCALER_16_ms  (0x00)
  #define WDG_PRESCALER_32_ms  (0x01)
  #define WDG_PRESCALER_64_ms  (0x02)
  #define WDG_PRESCALER_125_ms (0x03)
  #define WDG_PRESCALER_250_ms (0x04)
  #define WDG_PRESCALER_500_ms (0x05)
  #define WDG_PRESCALER_1_s    (0x06)
  #define WDG_PRESCALER_2_s    (0x07)
  #define WDG_PRESCALER_4_s    (0x20)
  #define WDG_PRESCALER_8_s    (0x21)

  #define WDG_CFG_NONE            (0x00)
  #define WDG_CFG_INTERRUPT       (0x40)
  #define WDG_CFG_RESET           (0x08)
  #define WDG_CFG_INTERRUPT_RESET (0x48)

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

#endif // WDG_CONFIG_TYPES_2014_10_14_H
