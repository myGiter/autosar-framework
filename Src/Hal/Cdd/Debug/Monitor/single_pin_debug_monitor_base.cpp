/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include "single_pin_debug_monitor_base.h"

single_pin_debug_monitor_base::~single_pin_debug_monitor_base() { }

single_pin_debug_monitor_base::single_pin_debug_monitor_base() : driver_buffer(),
                                                                 driver_buffer_length(0U),
                                                                 driver_is_in_send_mode(false),
                                                                 driver_current_byte_value(0U),
                                                                 driver_received_nothing_counter(0U),
                                                                 driver_transmit_state(recieve_start_bit)
{
  driver_flush_buffer();
}

void single_pin_debug_monitor_base::driver_send_buffer()
{
  driver_is_in_send_mode    = true;
  driver_transmit_state     = send_start_bit;
  driver_current_byte_value = uint8_fast(0U);
}

void single_pin_debug_monitor_base::driver_flush_buffer()
{
  driver_buffer_length  = uint8_fast(0U);
  driver_transmit_state = recieve_start_bit;
  std::fill(driver_buffer.begin(), driver_buffer.end(), driver_buffer_type::value_type(0U));
}
