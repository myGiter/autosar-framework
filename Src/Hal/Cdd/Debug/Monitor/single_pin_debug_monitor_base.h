/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _SINGLE_PIN_DEBUG_MONITOR_BASE_2014_10_13_H_
  #define _SINGLE_PIN_DEBUG_MONITOR_BASE_2014_10_13_H_

  #include <algorithm>
  #include <array>
  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Util/NonCopyable/NonCopyable.h>
  #include <Bsw/Util/TwoPartDataManipulation/two_part_data_manipulation.h>
  #include <Bsw/Util/Debug/Monitor/DebugMonitor.h>

  // Here, we are implementing a single-pin debug monitor.
  // It uses a UART emulated in software on a digitial I/O port
  // using a baud rate of 250 bits-per-second. A driver task
  // in the derived class implements the UART physical layer.

  // A skinny protocol called "BWD" is built on top of the
  // UART in order to support read/write of byte, word
  // and dword sized variables and data chunks. A protocol
  // task in the base class implements the BWD protocol.

  // Description of the BWD protocol:
  // 'b' means read a byte.
  // 'w' means read a word.
  // 'd' means read a dword.
  // 'B' means write a byte.
  // 'W' means write a word.
  // 'D' means write a dword.

  class single_pin_debug_monitor_base : private util::noncopyable
  {
  public:
      template<typename addr_type, const addr_type addr_offset>
      void protocol_task();

      virtual ~single_pin_debug_monitor_base();

      protected:
      // Set up the driver buffer.
      static const uint8_fast driver_buffer_size = uint8_fast(8U);
      typedef std::array<uint8, driver_buffer_size> driver_buffer_type;

      typedef enum enum_driver_transmit_state_type
      {
        recieve_start_bit,
        recieve_start_bit_validation,
        recieve_data_bits,
        recieve_stop_bit,
        recieve_pause_for_next_byte,
        send_start_bit,
        send_data_bits,
        send_stop_bit,
        send_pause_for_next_byte
      }
      driver_transmit_state_type;

      driver_buffer_type         driver_buffer;
      uint8_fast                 driver_buffer_length;
      boolean                    driver_is_in_send_mode;
      uint8_fast                 driver_current_byte_value;
      uint8_fast                 driver_received_nothing_counter;
      driver_transmit_state_type driver_transmit_state;

      single_pin_debug_monitor_base();

      void driver_send_buffer();
      void driver_flush_buffer();
  };

  template<typename addr_type, const addr_type addr_offset>
  void single_pin_debug_monitor_base::protocol_task()
  {
    // This protocol task embodies the "BWD" protocol.

    if(driver_is_in_send_mode)
    {
      return;
    }

    // Note: These variables are shielded from aggressive optimization
    // with the volatile qualifier. This is because direct memory access
    // might *seem* to simply do nothing for a highly optimizing compiler.
    // The volatile qualification reduces the risk of the memory access
    // code being wrongly optimized away (partly or entirely).

    volatile uint8_fast data_elements;
    volatile uint8_fast service_id;

    // Obtain the service ID for a read or write command,
    // and set the number of data elements in the command.

    switch(driver_buffer[0U])
    {
      case 0x62:  // 'b'
        service_id    = uint8_fast(1U);
        data_elements = uint8_fast(1U);
        break;

      case 0x77:  // 'w'
        service_id    = uint8_fast(1U);
        data_elements = uint8_fast(2U);
        break;

      case 0x64:  // 'd'
        service_id    = uint8_fast(1U);
        data_elements = uint8_fast(4U);
        break;

      case 0x42:  // 'B'
        service_id    = uint8_fast(2U);
        data_elements = uint8_fast(1U);
        break;

      case 0x57:  // 'W'
        service_id    = uint8_fast(2U);
        data_elements = uint8_fast(2U);
        break;

      case 0x44:  // 'D'
        service_id    = uint8_fast(2U);
        data_elements = uint8_fast(4U);
        break;

      default:    // undefined
        service_id    = uint8_fast(0U);
        data_elements = uint8_fast(0U);
        break;
    }

    // Create the total address using the address offset combined
    // with the address obtained from the communication buffer.
    // The total address is of type addr_type, which may have a
    // width that exceeds 16 bits based on the memory characteristics
    // of the target system.

    const uint16_least address_from_buffer =
      uint16_least(util::make_long(driver_buffer[1U], driver_buffer[2U]));

    const addr_type address = addr_type(addr_offset + address_from_buffer);

    // Evaluate the service ID and issue the read or write command.
    if(service_id == uint8_fast(1U))
    {
      if(driver_buffer_length == uint8_fast(3U))
      {
        std::fill(driver_buffer.begin(), driver_buffer.begin() + 4U, uint8(0U));

        switch(data_elements)
        {
          case 1U:
          default:
            // Read a byte with the command 'b'.
            driver_buffer[0U] = *reinterpret_cast<volatile uint8*>(address);
            break;

          case 2U:
            {
              // Read a word with the command 'w'.
              const uint16 value = *reinterpret_cast<volatile uint16*>(address);

              driver_buffer[1U] = util::hi_part<uint8, uint16>(value);
              driver_buffer[0U] = util::lo_part<uint8, uint16>(value);
            }
            break;

          case 4U:
            {
              // Read a dword with the command 'd'.
              const uint32 value = *reinterpret_cast<volatile uint32*>(address);

              const uint16 value_lo = util::lo_part<uint16, uint32>(value);
              const uint16 value_hi = util::hi_part<uint16, uint32>(value);

              driver_buffer[3U] = util::hi_part<uint8, uint16>(value_hi);
              driver_buffer[2U] = util::lo_part<uint8, uint16>(value_hi);
              driver_buffer[1U] = util::hi_part<uint8, uint16>(value_lo);
              driver_buffer[0U] = util::lo_part<uint8, uint16>(value_lo);
            }
            break;
        }

        driver_buffer_length = data_elements;

        driver_send_buffer();
      }
    }
    else if(service_id == uint8_fast(2U))
    {
      if(driver_buffer_length == uint8_fast(data_elements + uint8_fast(3U)))
      {
        switch(data_elements)
        {
          case 1U:
          default:
            // Write a byte with the command 'B'.
            *reinterpret_cast<uint8*>(address) = driver_buffer[3U];
            break;

          case 2U:
            {
              // Write a word with the command 'W'.
              const uint16 value =
                util::make_long(static_cast<uint8>(driver_buffer[3U]),
                                static_cast<uint8>(driver_buffer[4U]));

              *reinterpret_cast<volatile uint16*>(address) = value;
            }
            break;

          case 4U:
            {
              // Write a dword with the command 'D'.
              const uint16 value_lo =
                util::make_long(static_cast<uint8>(driver_buffer[3U]),
                                static_cast<uint8>(driver_buffer[4U]));

              const uint16 value_hi =
                util::make_long(static_cast<uint8>(driver_buffer[5U]),
                                static_cast<uint8>(driver_buffer[6U]));

              *reinterpret_cast<volatile uint32*>(address) = util::make_long(value_lo, value_hi);
            }
            break;
        }

        driver_flush_buffer();
      }
    }
  }

#endif // _SINGLE_PIN_DEBUG_MONITOR_BASE_2014_10_13_H_
