/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
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
  return Dio_PortLevelType(0);
}

EXTERN_C
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
  // Get the port index and bit position.
  // ucPortIndex is optimized for Bit-Shifting
  // IDs divided by 32 = Base of 400!
  // IDs modulo 32 = Pin Position!

  const uint32 bit_position = util::division_and_modulus<Dio_ChannelType>::result_mod(ChannelId);
  const uint32 port_index   = util::division_and_modulus<Dio_ChannelType>::result_div(ChannelId);

  const uint32 address_of_value_reg = uint32((port_index * 0x0400U) + mcal::reg::gpioa_bsrr);

  (Level == STD_HIGH) ? util::dma<uint32,
                                  uint32>::reg_set(address_of_value_reg, (UINT32_C(0x01) << bit_position))
                      : util::dma<uint32,
                                  uint32>::reg_set(address_of_value_reg, (UINT32_C(0x01) << (bit_position + UINT16_C(16))));
}

EXTERN_C
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
  // Get the port index and bit position.
  // ucPortIndex is optimized for Bit-Shifting
  // IDs divided by 32 = Base of 400!
  // IDs modulo 32 = Pin Position!

  const uint32 bit_position = util::division_and_modulus<Dio_ChannelType>::result_mod(ChannelId);
  const uint32 port_index   = util::division_and_modulus<Dio_ChannelType>::result_div(ChannelId);

  const uint32 address_of_value_reg = uint32((port_index * 0x0400U) + mcal::reg::gpioa_idr);

  const uint32 input_reg_values = util::dma<uint32,
                                            uint32>::reg_get(address_of_value_reg);

  bool  DioValue = UTIL_DWORD_TEST_BIT(input_reg_values, bit_position);

  return ((DioValue == TRUE)   ? static_cast<Dio_LevelType>(STD_HIGH)
                               : static_cast<Dio_LevelType>(STD_LOW));
}
