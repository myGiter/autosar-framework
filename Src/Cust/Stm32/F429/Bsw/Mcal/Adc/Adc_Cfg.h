/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _ADC_CFG_2014_10_14_H_
  #define _ADC_CFG_2014_10_14_H_

  // includes.
  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Adc/Adc_ConfigTypes.h>

  // AUTOSAR-API.
  #define ADC_DEINIT_API                  STD_OFF
  #define ADC_HARDWARE_TRIGGER_API        STD_OFF
  #define ADC_ENABLE_START_STOP_GROUP_API STD_OFF
  #define ADC_GET_GROUP_STATUS_API        STD_OFF
  #define ADC_READ_GROUP_API              STD_OFF
  #define ADC_GET_STREAM_LAST_POINTER_API STD_OFF

  typedef struct struct_Adc_ConfigType
  {
    uint32 dummy;
  }
  Adc_ConfigType;

  typedef struct struct_Adc_GroupDefType
  {
    uint32 dummy;
  }
  Adc_GroupDefType;

  EXTERN_C const Adc_ConfigType Adc_CfgMyConfig;

#endif // _ADC_CFG_2014_10_14_H_
