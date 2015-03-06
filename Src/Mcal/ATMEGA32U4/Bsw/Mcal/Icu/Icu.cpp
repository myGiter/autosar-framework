/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Icu/Icu.h>
#include <Bsw/Mcal/Reg/Reg.h>

EXTERN_C
void Icu_Init(const Icu_ConfigType* IcuConfig)
{
  for(uint8_least i = 0U; i < countof(Icu_ConfigSet.IcuMaxChannel); ++i)
  {
    // Configuration for active ICU only.
    if(IcuConfig->IcuMaxChannel[i].IcuInputState == ICU_ACTIVE)
    {
      // Set Activation Condition.
      Icu_SetActivationCondition(IcuConfig->IcuMaxChannel[i].IcuChannelID, IcuConfig->IcuMaxChannel[i].IcuDefaultStartEdge);
    }
  }
}

EXTERN_C
void Icu_DeInit(void)
{
}

EXTERN_C
void 
Icu_SetMode(Icu_ModeType Mode)
{
  static_cast<void>(Mode);
}

EXTERN_C
void Icu_DisableWakeup(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_EnableWakeup(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
  // Get the bit position.
  // IDs modulo 8 = Pin Position!

  const uint8 bit_position = util::division_and_modulus<Port_PinType>::result_mod(Channel);
  uint8 bit_position_0 = bit_position  * 2U;
  uint8 bit_position_1 = (bit_position * 2U) +1U;

  // encode activation type
  switch(Activation)
  {
    case ICU_RISING_EDGE:
      util::dma<uint8, uint8>::bit_set(mcal::reg::eicra, bit_position_0);
      util::dma<uint8, uint8>::bit_set(mcal::reg::eicra, bit_position_1);
      break;

    case ICU_FALLING_EDGE:
      util::dma<uint8, uint8>::bit_clr(mcal::reg::eicra, bit_position_0);
      util::dma<uint8, uint8>::bit_set(mcal::reg::eicra, bit_position_1);
      break;

    case ICU_BOTH_EDGES:
      util::dma<uint8, uint8>::bit_set(mcal::reg::eicra, bit_position_0);
      util::dma<uint8, uint8>::bit_clr(mcal::reg::eicra, bit_position_1);
      break;
  }
}

EXTERN_C
void Icu_DisableNotification(Icu_ChannelType Channel)
{
  const uint8 bit_position = util::division_and_modulus<Port_PinType>::result_mod(Channel);
  util::dma<uint8, uint8>::bit_clr(mcal::reg::eimsk, bit_position);
}

EXTERN_C
void Icu_EnableNotification(Icu_ChannelType Channel)
{
  const uint8 bit_position = util::division_and_modulus<Port_PinType>::result_mod(Channel);
  util::dma<uint8, uint8>::bit_set(mcal::reg::eimsk, bit_position);
}

EXTERN_C
Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
  return Icu_InputStateType(0U);
}

EXTERN_C
void Icu_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType* BufferPtr, uint16 BufferSize, uint16 NotifyInterval)
{
  static_cast<void>(Channel);
  static_cast<void>(BufferPtr);
  static_cast<void>(BufferSize);
  static_cast<void>(NotifyInterval);
}

EXTERN_C
void Icu_StopTimestamp(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);

  return Icu_IndexType(0U);
}

EXTERN_C
void Icu_ResetEdgeCount(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_EnableEdgeCount(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_DisableEdgeCount(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
  return Icu_EdgeNumberType(0U);
}
EXTERN_C
void Icu_StartSignalMeasurement(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
void Icu_StopSignalMeasurement(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
}

EXTERN_C
Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel)
{
  static_cast<void>(Channel);
  return Icu_ValueType(0U);
}

EXTERN_C
void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues)
{
  static_cast<void>(Channel);
  static_cast<void>(DutyCycleValues);
}

EXTERN_C void __vector_ext0_irq(void) __attribute__((signal, used, externally_visible));
void __vector_ext0_irq(void)
{

}


EXTERN_C void __vector_ext1_irq(void) __attribute__((signal, used, externally_visible));
void __vector_ext1_irq(void)
{

}

EXTERN_C void __vector_ext2_irq(void) __attribute__((signal, used, externally_visible));
void __vector_ext2_irq(void)
{

}

EXTERN_C void __vector_ext3_irq(void) __attribute__((signal, used, externally_visible));
void __vector_ext3_irq(void)
{

}
