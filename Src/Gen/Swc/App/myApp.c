/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Hal/IoHwAb/IoHwAb.h>
#include <Rte/Rte_myApp.h>
#include <Swc/App/myApp_Cfg.h>

void do_app()
{
  // Read the Signal value from the RTE.
  uint8 this_signal;
  uint8 next_signal;

  Rte_Read_PortName01_DataElement01((Rte_CDS_myApp*) NULL_PTR, &this_signal);
  {
    // Evaluate the new data for the I/O channel level.
    const IoHwAb_LevelType new_channel_level = ((this_signal == (uint8) 1U) ? (IoHwAb_LevelType) STD_HIGH
                                                                            : (IoHwAb_LevelType) STD_LOW);

    IoHwAb_StatusType dummy_status;

    uint8_least led_index;

    // Write the new data to the I/O channel level.
    for(led_index = 0U; led_index < (uint8_least) NUMBER_OF_LED_SIGNALS; ++led_index)
    {
      (void) IoHwAb_Set_Digital(led_index, new_channel_level, &dummy_status);
    }
  }

  // Set the next Signal value in the RTE.
  next_signal = ((this_signal == (uint8) 1U) ? (uint8) 0U : (uint8) 1U);
  Rte_Write_PortName01_DataElement01((Rte_CDS_myApp*) NULL_PTR, &next_signal);
}
