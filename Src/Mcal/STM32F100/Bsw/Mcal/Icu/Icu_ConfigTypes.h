/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef ICU_CONFIG_TYPES_2015_01_30_H
  #define ICU_CONFIG_TYPES_2015_01_30_H

  #include <Bsw/Mcal/Port/Port.h>

  typedef uint32 Icu_ChannelType;
  typedef uint32 Icu_ValueType;
  typedef uint32 Icu_IndexType;
  typedef uint32 Icu_EdgeNumberType;

  #define ICU_CHANNEL_D_0  PORT_PIN_D_0
  #define ICU_CHANNEL_D_1  PORT_PIN_D_1
  #define ICU_CHANNEL_D_2  PORT_PIN_D_2
  #define ICU_CHANNEL_D_3  PORT_PIN_D_3

  EXTERN_C
  typedef enum enum_Icu_ModeType
  {
    ICU_MODE_NORMAL,
    ICU_MODE_SLEEP
  }
  Icu_ModeType;

  EXTERN_C
  typedef enum enum_Icu_InputStateType
  {
    ICU_ACTIVE,
    ICU_IDLE
  }
  Icu_InputStateType;

  EXTERN_C
  typedef enum enum_Icu_ActivationType
  {
    ICU_RISING_EDGE,
    ICU_FALLING_EDGE,
    ICU_BOTH_EDGES
  }
  Icu_ActivationType;

  EXTERN_C
  typedef enum enum_Icu_MeasurementModeType
  {
    ICU_MODE_SIGNAL_EDGE_DETECT,
    ICU_MODE_SIGNAL_MEASUREMENT,
    ICU_MODE_TIMESTAMP,
    ICU_MODE_EDGE_COUNTER
  }
  Icu_MeasurementModeType;

  EXTERN_C
  typedef enum enum_Icu_SignalMeasurementPropertyType
  {
    ICU_LOW_TIME,
    ICU_HIGH_TIME,
    ICU_PERIOD_TIME,
    ICU_DUTY_CYCLE
  }
  Icu_SignalMeasurementPropertyType;

  EXTERN_C
  typedef enum enum_Icu_TimestampBufferType
  {
    ICU_LINEAR_BUFFER,
    ICU_CIRCULAR_BUFFER
  }
  Icu_TimestampBufferType;

  typedef struct struct_Icu_DutyCycleType
  {
    Icu_ValueType ActiveTime;
    Icu_ValueType PeriodTime;
  }
  Icu_DutyCycleType;

#endif // ICU_CONFIG_TYPES_2015_01_30_H
