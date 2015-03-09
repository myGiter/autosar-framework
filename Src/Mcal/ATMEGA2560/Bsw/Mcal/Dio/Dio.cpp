/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Dio/Dio.h>
#include <Bsw/Mcal/Reg/Reg.h>

EXTERN_C
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
  static_cast<void>(PortId);
  static_cast<void>(Level);
}

EXTERN_C
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
  static_cast<void>(PortId);
  return Dio_PortLevelType(0U);
}

EXTERN_C
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
  // Get the port index and bit position.
  // ucPortIndex is optimized for Bit-Shifting
  // IDs divided by 8 = Base of 3!
  // IDs modulo 8 = Pin Position!

  const uint8 bit_position = util::division_and_modulus<Dio_ChannelType>::result_mod(ChannelId);
  const uint8 port_index   = util::division_and_modulus<Dio_ChannelType>::result_div(ChannelId);

  const uint16 address_of_value_reg = uint16(port_index + mcal::reg::porta);

  (Level == STD_HIGH) ? util::dma<uint16,
                                  uint8>::bit_set(address_of_value_reg, bit_position)
                      : util::dma<uint16,
                                  uint8>::bit_clr(address_of_value_reg, bit_position);
}

EXTERN_C
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
  // Get the port index and bit position.
  // ucPortIndex is optimized for Bit-Shifting
  // IDs divided by 8 = Base of 3!
  // IDs modulo 8 = Pin Position!

  const uint8 bit_position = util::division_and_modulus<Dio_ChannelType>::result_mod(ChannelId);
  const uint8 port_index   = util::division_and_modulus<Dio_ChannelType>::result_div(ChannelId);

  const uint16 address_of_value_reg = uint16(port_index + mcal::reg::pina);

  bool  DioValue = util::dma<uint16,
                             uint8>::bit_get(address_of_value_reg, bit_position);

  return ((DioValue == TRUE)   ? static_cast<Dio_LevelType>(STD_HIGH)
                               : static_cast<Dio_LevelType>(STD_LOW));
}
