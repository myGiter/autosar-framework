/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef ICU_CFG_2015_01_30_H
  #define ICU_CFG_2015_01_30_H

  // includes.
  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Icu/Icu_ConfigTypes.h>

  // AUTOSAR-API.
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

  // Configuration of an Icu Channel.
  typedef struct struct_IcuChannel
  {
    uint32 dummy;
//    const Icu_ChannelType         IcuChannelID;
//    const Icu_InputStateType      IcuInputState;
//    const Icu_ActivationType      IcuDefaultStartEdge;
//    const Icu_MeasurementModeType IcuMeasurementMode;
  }
  tIcuChannel;

  // Container collecting all ICU Configurations.
  typedef struct struct_Icu_ConfigType
  {
    const tIcuChannel IcuMaxChannel[1U];
  }
  Icu_ConfigType;

  EXTERN_C const Icu_ConfigType Icu_ConfigSet;

#endif // ICU_CFG_2015_01_30_H
