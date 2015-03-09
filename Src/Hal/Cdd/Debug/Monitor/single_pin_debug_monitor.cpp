/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include "single_pin_debug_monitor.h"

single_pin_debug_monitor::single_pin_debug_monitor(const Dio_ChannelType dio_channel,
                                                   const Port_PinType port_pin)
  : my_dio_channel             (dio_channel),
    my_port_pin                (port_pin),
    driver_wait                (),
    driver_current_bit_position(0U)
{
  Port_SetPinDirection(my_port_pin, PORT_PIN_IN);
}

single_pin_debug_monitor::~single_pin_debug_monitor() { }

void single_pin_debug_monitor::driver_task()
{
  if(driver_is_in_send_mode)
  {
    driver_port_send();
  }
  else
  {
    const bool port_pin_is_idle_high = (port_pin_receive() == true);

    if(port_pin_is_idle_high)
    {
      // Increment a counter if nothing has been received.
      ++driver_received_nothing_counter;

      if(driver_received_nothing_counter >= receive_reset_limit)
      {
        // Clear the buffer if nothing has been received for quite a while.
        driver_flush_buffer();
        driver_received_nothing_counter = uint8_fast(0U);
      }
    }
    else
    {
      driver_received_nothing_counter = uint8_fast(0U);
    }

    driver_port_receive();
  }
}

void single_pin_debug_monitor::driver_init_port(const bool set_direction_to_output)
{
  Port_SetPinDirection(my_port_pin, set_direction_to_output ? PORT_PIN_OUT : PORT_PIN_IN);
}

void single_pin_debug_monitor::port_pin_send(const bool set_value_to_high)
{
  Dio_WriteChannel(my_dio_channel, set_value_to_high ? STD_HIGH : STD_LOW);
}

bool single_pin_debug_monitor::port_pin_receive()
{
  const Dio_LevelType the_dio_level = Dio_ReadChannel(my_dio_channel);

  return (the_dio_level == STD_HIGH);
}

void single_pin_debug_monitor::driver_port_send()
{
  // Send the buffer contents over the port pin.
  // Use the UART physical layer protocol.
  if(driver_current_byte_value < driver_buffer_length)
  {
    switch(driver_transmit_state)
    {
      case send_start_bit:
        driver_wait.start_relative(timer_type::microseconds(bit_time_microseconds()));

        if(driver_current_byte_value == uint8_fast(0U))
        {
          driver_init_port(true);
        }

        port_pin_send(false);
        driver_transmit_state = send_data_bits;
        driver_current_bit_position = 0U;

      case send_data_bits:
        if(driver_wait.timeout())
        {
          driver_wait.start_relative(timer_type::microseconds(bit_time_microseconds()));

          // Send a single data bit.
          const bool bit_is_high = (uint8_fast(uint8_fast(single_pin_debug_monitor_base::driver_buffer[driver_current_byte_value]) & uint8_fast(1U << driver_current_bit_position)) != uint8_fast(0U));

          port_pin_send(bit_is_high);

          ++driver_current_bit_position;

          if(driver_current_bit_position >= driver_buffer.size())
          {
            driver_transmit_state = send_stop_bit;
          }
        }
        break;

      case send_stop_bit:
        if(driver_wait.timeout())
        {
          driver_wait.start_relative(timer_type::microseconds(bit_time_microseconds()));
          port_pin_send(true);
          driver_transmit_state = send_pause_for_next_byte;
        }
        break;

      case send_pause_for_next_byte:
        if(driver_wait.timeout())
        {
          ++driver_current_byte_value;

          driver_transmit_state = send_start_bit;

          if(driver_current_byte_value >= driver_buffer_length)
          {
            driver_is_in_send_mode = false;
            driver_flush_buffer();
            driver_init_port(driver_is_in_send_mode);
          }
        }
        break;

      case recieve_start_bit:
      case recieve_start_bit_validation:
      case recieve_data_bits:
      case recieve_stop_bit:
      case recieve_pause_for_next_byte:
      default:
        break;
    }
  }
}

void single_pin_debug_monitor::driver_port_receive()
{
  // Read incoming data bytes on the port pin and store them in the buffer.
  // Use the UART physical layer protocol.
  if(driver_buffer_length < driver_buffer.size())
  {
    switch(driver_transmit_state)
    {
      case recieve_start_bit:
        if((!port_pin_receive()))
        {
          driver_transmit_state = recieve_start_bit_validation;
        }
        break;

      case recieve_start_bit_validation:
        if((!port_pin_receive()))
        {
          driver_wait.start_relative(timer_type::microseconds(bit_time_microseconds()));
          driver_current_bit_position = uint8_fast(0U);
          driver_current_byte_value   = uint8_fast(0U);
          driver_transmit_state       = recieve_data_bits;
        }
        else
        {
          // If the start bit can not be validated, then flush
          // the buffer and thereby revert to the receive state.
          driver_flush_buffer();
        }
        break;

      case recieve_data_bits:
        if(driver_wait.timeout())
        {
          driver_wait.start_relative(timer_type::microseconds(bit_time_microseconds()));

          // Append the bit value to the current byte value.
          if(port_pin_receive())
          {
            driver_current_byte_value |= uint8_fast(uint8_fast(1U) << driver_current_bit_position);
          }

          ++driver_current_bit_position;

          if(driver_current_bit_position >= uint8_fast(8U))
          {
            driver_transmit_state = recieve_stop_bit;
          }
        }
        break;

      case recieve_stop_bit:
        if(driver_wait.timeout())
        {
          if(port_pin_receive())
          {
            driver_buffer[driver_buffer_length] = uint8_fast(driver_current_byte_value);

            ++driver_buffer_length;
          }

          driver_transmit_state = recieve_pause_for_next_byte;
        }
        break;

      case recieve_pause_for_next_byte:
        driver_transmit_state = recieve_start_bit;
        break;

      case send_start_bit:
      case send_data_bits:
      case send_stop_bit:
      case send_pause_for_next_byte:
      default:
        break;
    }
  }
}
