/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Mcal/Pwm/Pwm.h>

#include <Hal/Cdd/Multiplex/NXP_74HC4067/Cdd_MuxNXP74HC4067.h>
#include <Bsw/Mcal/Dio/Dio.h>

// Runnables
uint16 duty_rgb_g = UINT16_C(0x4000);
uint16 duty_rgb_b = UINT16_C(0x4000);
uint16 duty_rgb_r = UINT16_C(0x4000);

bool upcounting_rgb_g = true;
bool upcounting_rgb_b = true;
bool upcounting_rgb_r = true;

EXTERN_C
void rpTask2_Init()
{
  Pwm_SetPeriodAndDuty(ARDUINO_RGB_G, UINT16_C(500), UINT16_C(0x4000));
  Pwm_SetPeriodAndDuty(ARDUINO_RGB_B, UINT16_C(500), UINT16_C(0x4000));
  Pwm_SetPeriodAndDuty(ARDUINO_RGB_R, UINT16_C(500), UINT16_C(0x4000));
}

EXTERN_C
void rpTask2_Func()
{
//  Cdd_MuxNXP74H_Set_Multiplex(ARDUINO_MUX_SWITCH_1);

//  Cdd_MuxNXP74H_Set_Multiplex(ARDUINO_MUX_SWITCH_2);

  Cdd_MuxNXP74H_Set_Multiplex(ARDUINO_MUX_SWITCH_3);

//  Cdd_MuxNXP74H_Set_Multiplex(ARDUINO_MUX_SWITCH_4);
  Dio_WriteChannel(ARDUINO_PORT_RX_LED, (Dio_ReadChannel(ARDUINO_MUX_SIGNAL) == STD_HIGH) ? STD_HIGH : STD_LOW);

  (upcounting_rgb_g ? duty_rgb_g += 4U : duty_rgb_g -= 4U);

  Pwm_SetDutyCycle(ARDUINO_RGB_G, duty_rgb_g);

  if((duty_rgb_g >= UINT16_C(0x7FF0)) || (duty_rgb_g <= UINT16_C(0x0010)))
  {
    upcounting_rgb_g = !upcounting_rgb_g;
  }

  (upcounting_rgb_b ? duty_rgb_b += 8U : duty_rgb_b -= 8U);

  Pwm_SetDutyCycle(ARDUINO_RGB_B, duty_rgb_b);

  if((duty_rgb_b >= UINT16_C(0x7FF0)) || (duty_rgb_b <= UINT16_C(0x0010)))
  {
    upcounting_rgb_b = !upcounting_rgb_b;
  }

  (upcounting_rgb_r ? duty_rgb_r += 16U : duty_rgb_r -= 16U);

  Pwm_SetDutyCycle(ARDUINO_RGB_R, duty_rgb_r);

  if((duty_rgb_r >= UINT16_C(0x7FF0)) || (duty_rgb_r <= UINT16_C(0x0010)))
  {
    upcounting_rgb_r = !upcounting_rgb_r;
  }
}
