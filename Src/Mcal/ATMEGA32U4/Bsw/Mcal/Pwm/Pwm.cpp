/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Pwm/mcal_pwm.h>
#include <Bsw/Mcal/Pwm/Pwm.h>
#include <Bsw/Mcal/Reg/Reg.h>

/*
          mcal::pwm::pwm_type pwm_on_port_d5(mcal::reg::portd,
                                   UINT8_C(5),
                                   UINT8_C(0x80),
                                   UINT8_C(0x40));

void PwmTimerHook()
{
  pwm_on_port_d5.service();
}
*/

EXTERN_C
void Pwm_Init(const Pwm_ConfigType* ConfigPtr)
{
  static_cast<void>(ConfigPtr);

  for(uint8_least i = 0U; i < countof(Pwm_ConfigSet.PwmChannelConfigSet); ++i)
  {
    // Configuration for Pwm Mode.
    switch(ConfigPtr->PwmChannelConfigSet[i].Mode)
    {

      case PWM_MODE_FAST_INVERTED:
//        if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_C_7)
        {
         /*
          Missing UINT8_C Value x
          util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(x));
          util::dma<uint8, uint8>::reg_set(mcal::reg::timsk0, UINT8_C(x));
          */
        }
//        else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_B_7)
        {
         /*
          Missing UINT8_C Value x
          util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(x));
          util::dma<uint8, uint8>::reg_set(mcal::reg::timsk0, UINT8_C(x));
          */
        }
//        else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_D_0)
        {
         /*
          Missing UINT8_C Value x
          util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(x));
          util::dma<uint8, uint8>::reg_set(mcal::reg::timsk0, UINT8_C(x));
          */
        }
//        else
        {
          //Code for other Channels
        }
        break;

      case PWM_MODE_FAST_NONINVERTED:
//        if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_B_5)
        {
          util::dma<uint8, uint8>::reg_msk(mcal::reg::tccr1a, UINT8_C(0xC1), UINT8_C(0xC1));
          util::dma<uint8, uint8>::reg_msk(mcal::reg::tccr1b, UINT8_C(0x08), UINT8_C(0x08));
        }
//        else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_B_6)
        {
          util::dma<uint8, uint8>::reg_msk(mcal::reg::tccr1a, UINT8_C(0x31), UINT8_C(0x31));
          util::dma<uint8, uint8>::reg_msk(mcal::reg::tccr1b, UINT8_C(0x08), UINT8_C(0x08));
        }
//        else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_B_7)
        {
          //util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(0xC3));
        }
//        else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_C_6)
        {
          util::dma<uint8, uint8>::reg_msk(mcal::reg::tccr3a, UINT8_C(0xC1), UINT8_C(0xC1));
          util::dma<uint8, uint8>::reg_msk(mcal::reg::tccr3b, UINT8_C(0x08), UINT8_C(0x08));
        }
//        else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_C_7)
        {
          //util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(0xC3));
        }
//        else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_D_0)
        {
          //util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(0xC3));
        }
//        else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_SW_CHANNEL_D_5)
        {

        }
//        else
        {
          //Code for other Channels
        }
        break;

      case PWM_MODE_PHASECORRECT_INVERTED:
//          if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_C_7)
        {
           /*
            Missing UINT8_C Value x
            util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(x));
            util::dma<uint8, uint8>::reg_set(mcal::reg::timsk0, UINT8_C(x));
            */
        }
//          else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_B_7)
        {
           /*
            Missing UINT8_C Value x
            util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(x));
            util::dma<uint8, uint8>::reg_set(mcal::reg::timsk0, UINT8_C(x));
            */
        }
//          else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_D_0)
        {
           /*
            Missing UINT8_C Value x
            util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(x));
            util::dma<uint8, uint8>::reg_set(mcal::reg::timsk0, UINT8_C(x));
            */
        }
//        else
        {
            //Code for other Channels
        }
        break;

      case PWM_MODE_PHASECORRECT_NONINVERTED:
//          if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_C_7)
        {
           /*
            Missing UINT8_C Value x
            util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(x));
            util::dma<uint8, uint8>::reg_set(mcal::reg::timsk0, UINT8_C(x));
            */
        }
//          else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_B_7)
        {
           /*
            Missing UINT8_C Value x
            util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(x));
            util::dma<uint8, uint8>::reg_set(mcal::reg::timsk0, UINT8_C(x));
            */
        }
//          else if(ConfigPtr->PwmChannelConfigSet[i].PwmChannelId == PWM_CHANNEL_D_0)
        {
           /*
            Missing UINT8_C Value x
            util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0a, UINT8_C(x));
            util::dma<uint8, uint8>::reg_set(mcal::reg::timsk0, UINT8_C(x));
            */
        }
//        else
        {
            //Code for other Channels
        }
        break;

      default:
          //Code for unused Channels

        break;
    }
  }
}

EXTERN_C
void Pwm_DeInit(void)
{
  static_cast<void>(0);
}

EXTERN_C
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
  std::uint8_t duty_cycle_reg_value;

  // Calculate the scaled duty cycle.
  duty_cycle_reg_value = static_cast<std::uint8_t>(DutyCycle / UINT8_C(0x80));

  switch(ChannelNumber)
  {
    case PWM_CHANNEL_B_5:
      util::dma<uint8,
                uint8>::reg_set(mcal::reg::ocr1al, duty_cycle_reg_value);
      break;

    case PWM_CHANNEL_B_6:
      util::dma<uint8,
                uint8>::reg_set(mcal::reg::ocr1bl, duty_cycle_reg_value);
      break;

    case PWM_CHANNEL_B_7:
      util::dma<uint8,
                uint8>::reg_set(mcal::reg::ocr0a, duty_cycle_reg_value);
      break;

    case PWM_CHANNEL_C_6:
      util::dma<uint8,
                uint8>::reg_set(mcal::reg::ocr3al, duty_cycle_reg_value);
      break;
/*
    case PWM_CHANNEL_C_7:
      util::dma<uint8,
                uint8>::reg_set(mcal::reg::ocr4a, LOBYTE(DutyCycle));
      break;

    case PWM_CHANNEL_D_0:
      util::dma<uint8,
                uint8>::reg_set(mcal::reg::ocr0b, LOBYTE(DutyCycle));
      break;
      
    case PWM_SW_CHANNEL:
      // code;
      break;
*/
/*
    case PWM_CHANNEL_D_6:
      // code;
      break;

    case PWM_CHANNEL_D_7:
      // code;
      break;

    default:
     // return error;
      break;
*/
  }
}
EXTERN_C
void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle)
{
  // first set duty cycle via autosar function.
  Pwm_SetDutyCycle(ChannelNumber, DutyCycle);

  if(Period > static_cast<Pwm_PeriodType>(16384))
  {
    // TBD: Switch to a software PWM here. Requires lots of code.
  }
  else
  {
    std::uint8_t prescaler_register_value;

    if(Period <= static_cast<Pwm_PeriodType>(16))
    {
      prescaler_register_value = UINT8_C(0x01);
    }
    else if(Period <= static_cast<Pwm_PeriodType>(128))
    {
      prescaler_register_value = UINT8_C(0x02);
    }
    else if(Period <= static_cast<Pwm_PeriodType>(1024))
    {
      prescaler_register_value = UINT8_C(0x03);
    }
    else if(Period <= static_cast<Pwm_PeriodType>(4096))
    {
      prescaler_register_value = UINT8_C(0x04);
    }
    else
    {
      prescaler_register_value = UINT8_C(0x05);
    }

//    util::dma<uint8, uint8>::reg_set(mcal::reg::tccr0b, prescaler_register_value);
    util::dma<uint8, uint8>::reg_msk(mcal::reg::tccr1b, prescaler_register_value, UINT8_C(0x07));
    util::dma<uint8, uint8>::reg_msk(mcal::reg::tccr3b, prescaler_register_value, UINT8_C(0x07));
  }
}

EXTERN_C
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber)
{
  static_cast<void>(ChannelNumber);
}

EXTERN_C
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber)
{
  static_cast<void>(ChannelNumber);
  return Pwm_OutputStateType(0);
}
