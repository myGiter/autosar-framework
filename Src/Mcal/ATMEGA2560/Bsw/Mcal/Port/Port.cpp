/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Port/Port.h>
#include <Bsw/Mcal/Reg/Reg.h>

EXTERN_C
void Port_Init(const Port_ConfigType* PortConfig)
{
  // Initialize GPIO ports B through F using the config pointer.
  for(uint8_least i = 0U; i < countof(Port_ConfigSet.PortNumberOfPortPins); ++i)
  {
    // Configuration for Mode Dio only.
    if(PortConfig->PortNumberOfPortPins[i].Mode == PORT_PIN_MODE_DIO)
    {
      // Get the port index and bit position.
      // ucPortIndex is optimized for Bit-Shifting
      // IDs divided by 8 = Base of 3!
      // IDs modulo 8 = Pin Position!

      const uint8 bit_position = util::division_and_modulus<Port_PinType>::result_mod(PortConfig->PortNumberOfPortPins[i].PinID);
      const uint8 port_index   = util::division_and_modulus<Port_PinType>::result_div(PortConfig->PortNumberOfPortPins[i].PinID);

      const uint16 address_of_value_reg     = uint16(port_index + mcal::reg::porta);
      const uint16 address_of_direction_reg = uint16(port_index + mcal::reg::ddra);

      // By Default Tri-State, first set the Direction and then the Level.
      if(PortConfig->PortNumberOfPortPins[i].PinDirection == PORT_PIN_OUT)
      {
        // Set the value of the direction register.
        (PortConfig->PortNumberOfPortPins[i].PinDirection == PORT_PIN_OUT) ? util::dma<uint16,
                                                                                       uint8>::bit_set(address_of_direction_reg, bit_position)
                                                                           : util::dma<uint16,
                                                                                       uint8>::bit_clr(address_of_direction_reg, bit_position);

        // Set the value of the output register.
        (PortConfig->PortNumberOfPortPins[i].PinLevelValue == PORT_PIN_LEVEL_HIGH) ? util::dma<uint16,
                                                                                               uint8>::bit_set(address_of_value_reg, bit_position)
                                                                                   : util::dma<uint16,
                                                                                               uint8>::bit_clr(address_of_value_reg, bit_position);
      }
      else
      {
        util::dma<uint16, uint8>::bit_set(address_of_value_reg, bit_position);
      }
    }
  }
}

EXTERN_C
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
  const uint8 bit_position = util::division_and_modulus<Port_PinType>::result_mod(Pin);
  const uint8 port_index   = util::division_and_modulus<Port_PinType>::result_div(Pin);

  const uint16 address_of_value_reg     = uint16(port_index * mcal::reg::porta);
  const uint16 address_of_direction_reg = uint16(port_index * mcal::reg::ddra);

  util::dma<uint16, uint8>::bit_clr(address_of_value_reg,     bit_position);
  util::dma<uint16, uint8>::bit_clr(address_of_direction_reg, bit_position);

  (Direction == PORT_PIN_IN) ? util::dma<uint16,
                                         uint8>::bit_set(address_of_value_reg,     bit_position)
                             : util::dma<uint16,
                                         uint8>::bit_set(address_of_direction_reg, bit_position);
}

EXTERN_C
void Port_RefreshPortDirection(void)
{
}

EXTERN_C
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
  static_cast<void>(Pin);
  static_cast<void>(Mode);
}
