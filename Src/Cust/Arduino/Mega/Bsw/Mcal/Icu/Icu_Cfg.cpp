/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Icu/Icu_Cfg.h>

EXTERN_C
const Icu_ConfigType Icu_ConfigSet =
{
  {
    {
      // IcuChannelID.
      ICU_CHANNEL_D_0,
      // Is this Icu activated?
      ICU_IDLE,
      // Select Activation condition.
      ICU_FALLING_EDGE,
      // Select Mode of Measurement.
      ICU_MODE_EDGE_COUNTER
    },
    {
      // IcuChannelID.
      ICU_CHANNEL_D_1,
      // Is this Icu activated?
      ICU_IDLE,
      // Select Activation condition.
      ICU_BOTH_EDGES,
      // Select Mode of Measurement.
      ICU_MODE_EDGE_COUNTER
    },
    {
      // IcuChannelID.
      ICU_CHANNEL_D_2,
      // Is this Icu activated?
      ICU_IDLE,
      // Select Activation condition.
      ICU_FALLING_EDGE,
      // Select Mode of Measurement.
      ICU_MODE_EDGE_COUNTER
    },
    {
      // IcuChannelID.
      ICU_CHANNEL_D_3,
      // Is this Icu activated?
      ICU_IDLE,
      // Select Activation condition.
      ICU_FALLING_EDGE,
      // Select Mode of Measurement.
      ICU_MODE_EDGE_COUNTER
    }
  }
};

EXTERN_C
const Icu_DutyCycleType Icu_DutyCycleData =
{
  0U,
  0U
};
