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
  // Initialize GPIO ports A through G using the config pointer.
  for(uint8_least i = 0U; i < countof(Port_ConfigSet.PortNumberOfPortPins); ++i)
  {
    const uint32 bit_position = util::division_and_modulus<Port_PinType>::result_mod(PortConfig->PortNumberOfPortPins[i].PinID);
    const uint32 port_index   = util::division_and_modulus<Port_PinType>::result_div(PortConfig->PortNumberOfPortPins[i].PinID);

    const uint32 address_of_value_reg     = uint32((port_index * 0x400U) + mcal::reg::gpioa_bsrr);
    const uint32 address_of_direction_reg = uint32((port_index * 0x400U) + mcal::reg::gpioa_crl);

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

      // check if we have to write to the high or the low config register.
      if(bit_position > 7U)
      {
        // for high register 0 to 7.
        uint32 bit_position_calc = bit_position - 8U;

      // Set the value of the direction register.
      if(PortConfig->PortNumberOfPortPins[i].PinDirection == PORT_PIN_IN)
      {
          // mask reg for INPUT in high register.
          uint32 input_value_reg = 0x08U << (bit_position_calc * 4U);
          uint32 input_mask_reg  = 0x0FU << (bit_position_calc * 4U);
          util::dma<uint32, uint32>::reg_msk((address_of_direction_reg + 4U), input_value_reg, input_mask_reg);
        }
        else
        {
          // mask reg for OUTPUT in high register.
          uint32 output_value_reg = 0x01U << (bit_position_calc * 4U);
          uint32 output_mask_reg  = 0x0FU << (bit_position_calc * 4U);
          util::dma<uint32, uint32>::reg_msk((address_of_direction_reg + 4U), output_value_reg, output_mask_reg);
        }
      }
      else
      {
        if(PortConfig->PortNumberOfPortPins[i].PinDirection == PORT_PIN_IN)
        {
          // mask reg for INPUT in low register.
          uint32 input_value_reg = 0x08U << (bit_position * 4U);
          uint32 input_mask_reg  = 0x0FU << (bit_position * 4U);
          util::dma<uint32, uint32>::reg_msk(address_of_direction_reg, input_value_reg, input_mask_reg);
      }
      else
      {
          // mask reg for OUTPUT in low register.
          uint32 output_value_reg = 0x01U << (bit_position * 4U);
          uint32 output_mask_reg  = 0x0FU << (bit_position * 4U);
          util::dma<uint32, uint32>::reg_msk(address_of_direction_reg, output_value_reg, output_mask_reg);
        }
      }
    }
  }
}

EXTERN_C
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
  //calulate, which port and which pin is used
  const uint32 bit_position = util::division_and_modulus<Port_PinType>::result_mod(Pin);
  const uint32 port_index   = util::division_and_modulus<Port_PinType>::result_div(Pin);

  const uint32 address_of_value_reg     = uint32((port_index * 0x400U) + mcal::reg::gpioa_bsrr);
  const uint32 address_of_direction_reg = uint32((port_index * 0x400U) + mcal::reg::gpioa_crl);

  //check if we have to write to the high or the low config register.
  if(bit_position > 7U)
  {
    // high register Bit 0 to 7.
    uint32 bit_position_calc = bit_position - 8U;

    if(Direction == PORT_PIN_IN)
    {
      uint32 input_value_reg = 0x08U << (bit_position_calc * 4U);
      uint32 input_mask_reg  = 0x0FU << (bit_position_calc * 4U);
      util::dma<uint32, uint32>::reg_msk((address_of_direction_reg + 4U), input_value_reg, input_mask_reg);
    }
    // PORT_PIN_OUT
    else
    {
      //write output low in bsrr
      util::dma<uint32,
                uint32>::reg_set(address_of_value_reg, (0x01U << (bit_position + 16U)));

      // set direction to output
      uint32 output_value_reg = 0x01U << (bit_position_calc * 4U);
      uint32 output_mask_reg  = 0x0FU << (bit_position_calc * 4U);
      util::dma<uint32,
                uint32>::reg_msk(address_of_direction_reg + 4U, output_value_reg, output_mask_reg);
    }
  }
  else
  {
    // low register Bit 0 to 7.
  if(Direction == PORT_PIN_IN)
  {
      uint32 input_value_reg = 0x08U << (bit_position * 4U);
      uint32 input_mask_reg  = 0x0FU << (bit_position * 4U);
      util::dma<uint32, uint32>::reg_msk(address_of_direction_reg, input_value_reg, input_mask_reg);
  }
  // PORT_PIN_OUT
  else
  {
      //write output low in bsrr
      util::dma<uint32,
                uint32>::reg_set(address_of_value_reg, (0x01U << (bit_position + 16U)));

      // set direction to output
      uint32 output_value_reg = 0x01U << (bit_position * 4U);
      uint32 output_mask_reg  = 0x0FU << (bit_position * 4U);
      util::dma<uint32, uint32>::reg_msk(address_of_direction_reg, output_value_reg, output_mask_reg);
    }
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
