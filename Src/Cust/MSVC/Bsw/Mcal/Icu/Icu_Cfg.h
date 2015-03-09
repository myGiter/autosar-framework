/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _ICU_CFG_2013_12_12_H_
  #define _ICU_CFG_2013_12_12_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Icu/Icu_ConfigTypes.h>

  #define ICU_DE_INIT_API                 STD_OFF
  #define ICU_DISABLE_WAKEUP_API          STD_OFF
  #define ICU_ENABLE_WAKEUP_API           STD_OFF
  #define ICU_SET_MODE_API                STD_OFF
  #define ICU_GET_INPUT_STATE_API         STD_OFF
  #define ICU_TIMESTAMP_API               STD_OFF
  #define ICU_EDGE_COUNT_API              STD_OFF
  #define ICU_SIGNAL_MEASUREMENT_API      STD_OFF
  #define ICU_GET_TIME_ELAPSED_API        STD_OFF
  #define ICU_GET_DUTY_CYCLE_VALUES_API   STD_OFF

  typedef struct struct_Icu_ConfigType
  {
    uint32 dummy;
  }
  Icu_ConfigType;

  EXTERN_C const Icu_ConfigType Icu_ConfigSet;

#endif // _ICU_CFG_2013_12_12_H_
