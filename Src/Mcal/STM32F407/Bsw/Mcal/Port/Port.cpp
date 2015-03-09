/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
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
  // Power for Ports
  // Enable the peripheral clocks for porta, portb, portc, portd, porte.
  util::dma<uint32,
            uint32>::reg_or(mcal::reg::rcc_ahb1enr,
                            UINT32_C(0x1F));

  // Initialize GPIO ports A through G using the config pointer.
  for(uint8_least i = 0U; i < countof(Port_ConfigSet.PortNumberOfPortPins); ++i)
  {
    const std::uint32_t bit_position = util::division_and_modulus<Port_PinType>::result_mod(PortConfig->PortNumberOfPortPins[i].PinID);
    const std::uint32_t port_index   = util::division_and_modulus<Port_PinType>::result_div(PortConfig->PortNumberOfPortPins[i].PinID);

    const std::uint32_t address_of_value_reg     = std::uint32_t((port_index * 0x400U) + mcal::reg::gpioa_bsrr);
    const std::uint32_t address_of_direction_reg = std::uint32_t((port_index * 0x400U) + mcal::reg::gpioa_moder);

    // Configuration for Mode Dio only.
    if(PortConfig->PortNumberOfPortPins[i].Mode == PORT_PIN_MODE_DIO)
    {
      // Get the port index and bit position.
      // ucPortIndex is optimized for Bit-Shifting
      // IDs divided by 32 = Base of 400!
      // IDs modulo 32 = Pin Position!

      // If the Pin is configured as Output, first set the Level and then the Direction.
      if(PortConfig->PortNumberOfPortPins[i].PinDirection == PORT_PIN_OUT)
      {
        // Set the value of the output register.(bsrr)
        (PortConfig->PortNumberOfPortPins[i].PinLevelValue == PORT_PIN_LEVEL_HIGH) ? util::dma<uint32,
                                                                                               uint32>::reg_set(address_of_value_reg, (0x01U << bit_position))
                                                                                   : util::dma<uint32,
                                                                                               uint32>::reg_set(address_of_value_reg, (0x01U << (bit_position + 16U)));
      }
      // Set the value of the direction register.
      uint32 value_reg = UINT32_C(0x00);
      if(PortConfig->PortNumberOfPortPins[i].PinDirection == PORT_PIN_IN)
      {
        // mask reg for INPUT in moder register.
        value_reg = 0x00U << (bit_position * 2U);
      }
      else
      {
        // mask reg for OUTPUT moder register.
        value_reg = 0x01U << (bit_position * 2U);
      }
      std::uint32_t mask_reg  = 0x03U << (bit_position * 2U);
      util::dma<uint32, uint32>::reg_msk((address_of_direction_reg), value_reg, mask_reg);
    }
  }
}

EXTERN_C
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
  //calulate, which port and which pin is used
  const std::uint32_t bit_position = util::division_and_modulus<Port_PinType>::result_mod(Pin);
  const std::uint32_t port_index   = util::division_and_modulus<Port_PinType>::result_div(Pin);

  const std::uint32_t address_of_value_reg     = std::uint32_t((port_index * 0x400U) + mcal::reg::gpioa_bsrr);
  const std::uint32_t address_of_direction_reg = std::uint32_t((port_index * 0x400U) + mcal::reg::gpioa_moder);

  if(Direction == PORT_PIN_IN)
  {
    std::uint32_t input_value_reg = 0x00U << (bit_position * 2U);
    std::uint32_t input_mask_reg  = 0x03U << (bit_position * 2U);
    util::dma<uint32, uint32>::reg_msk((address_of_direction_reg), input_value_reg, input_mask_reg);
  }
  // PORT_PIN_OUT
  else
  {
    //write output high in bsrr register.
    util::dma<uint32,
              uint32>::reg_set(address_of_value_reg, (0x01U << (bit_position)));

    // set direction to output in moder register.
    std::uint32_t output_value_reg = 0x01U << (bit_position * 2U);
    std::uint32_t output_mask_reg  = 0x03U << (bit_position * 2U);
    util::dma<uint32,
              uint32>::reg_msk(address_of_direction_reg, output_value_reg, output_mask_reg);
  }
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
