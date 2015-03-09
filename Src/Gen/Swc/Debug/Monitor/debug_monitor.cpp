/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Mcal/Mcal.h>
#include <Hal/Cdd/Debug/Monitor/single_pin_debug_monitor.h>

namespace
{
  typedef single_pin_debug_monitor debug_monitor_type;

  debug_monitor_type debug_monitor(RDM_DIO_CHANNEL, RDM_PORT_PIN);

  uint8_least protocol_prescaler;
}

EXTERN_C
void rpDebugMonitor_Init()
{

}

EXTERN_C
void rpDebugMonitor_Func()
{
  debug_monitor.driver_task();

  const bool run_the_protocol_task = (static_cast<uint8_fast>(protocol_prescaler % 8U) == static_cast<uint8_fast>(0U));

  if(run_the_protocol_task)
  {
    debug_monitor.protocol_task<rdm_address_type, rdm_address_offset>();
  }

  ++protocol_prescaler;
}
