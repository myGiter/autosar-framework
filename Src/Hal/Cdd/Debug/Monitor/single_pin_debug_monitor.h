/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _SINGLE_PIN_DEBUG_MONITOR_2014_10_13_H_
  #define _SINGLE_PIN_DEBUG_MONITOR_2014_10_13_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Dio/Dio.h>
  #include <Bsw/Mcal/Port/Port.h>
  #include <Bsw/Util/Time/Time.hpp>
  #include "single_pin_debug_monitor_base.h"

  class single_pin_debug_monitor : public single_pin_debug_monitor_base
  {
  public:
    single_pin_debug_monitor(const Dio_ChannelType dio_channel,
                             const Port_PinType port_pin);

    virtual ~single_pin_debug_monitor();
    void driver_task();

  private:
    // Set up the port driver timing.

    // The 1000 baud corresponds to a bit-time of approximately 1ms
    // per bit. The polling period is 0.250ms (i.e., 250us), such that
    // the driver polls up to four times per bit.

    // * The single-bit timeout is set to 5% less than four poll times.
    // * The receiver automatically resets if it is idle for 12 bit times or more.
    static uint16_fast bit_time_microseconds() { return (475U * 4U) / 2U; }
    static const uint8_fast  receive_reset_limit   =   12U * 4U;

    typedef util::timer<uint16_fast> timer_type;

    Dio_ChannelType   my_dio_channel;
    Port_PinType      my_port_pin;

    timer_type        driver_wait;
    uint8_fast        driver_current_bit_position;

    void driver_init_port(const bool set_direction_to_output);
    void port_pin_send(const bool set_value_to_high);
    bool port_pin_receive();

    void driver_port_send();
    void driver_port_receive();
  };

#endif // _SINGLE_PIN_DEBUG_MONITOR_2014_10_13_H_
