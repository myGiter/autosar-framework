/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Servl/EcuM/EcuM.h>
#include <Bsw/Servl/Osal/Os.h>
#include <Bsw/Mcal/Mcal.h>

namespace
{
  EcuM_StateType EcuM_MyState;
}

void EcuM_SetStateViaHiddenFunction(const EcuM_StateType EcuM_State)
{
  EcuM_MyState = EcuM_State;
}

EXTERN_C
void EcuM_Init(void)
{
  EcuM_MyState = ECUM_STATE_STARTUP_ONE;

  EcuM_AL_DriverInitZero();

// EcuM struct.

  EcuM_AL_DriverInitOne();

// Get Reset Reason.

  StartOS();
}

EXTERN_C
void EcuM_StartupTwo(void)
{
  EcuM_MyState = ECUM_STATE_STARTUP_TWO;

// BSW Scheduler.

  EcuM_AL_DriverInitTwo   ();

// StartRte();

  EcuM_AL_DriverInitThree ();
}

EXTERN_C
void EcuM_AL_DriverInitZero(void)
{
  // Initialize the DET.
}

EXTERN_C
void EcuM_AL_DriverInitOne(void)
{
  // Initialize the microcontroller unit.
  Mcu_Init(&Mcu_ModulConfiguration);

  // Initialize port.
  Port_Init(&Port_ConfigSet);

  // DIO.

  // DEM.

  // Initialize the genereal purpose timer.
  Gpt_Init(&GptDriverConfiguration);

  Gpt_StartTimer(static_cast<Gpt_ChannelType>(0U), static_cast<Gpt_ValueType>(0U));

  // Initialize the watchdog.
  Wdg_Init(&Wdg_ModeConfiguration);

  // WdM.

  // SchM.

  // BswM.

  // Initialize the analod to digital converter.
  Adc_Init(&Adc_CfgMyConfig);

  // Initialize the input capture unit.
  Icu_Init(&Icu_ConfigSet);

  // Initialize the PWM Unit.
  Pwm_Init(&Pwm_ConfigSet);
}

//-----------------------------------------------------------------------------
/// \brief  BSW modules, which need OS support
///
/// \descr  EcuM_AL_DriverInitTwo is provided, where initialization of those
///         basic software modules should take place, which need OS support and
///         need no access to NvRam data or manage the NvRam data on their own.
/// \param  - 
///
/// \return void 
//-----------------------------------------------------------------------------
EXTERN_C
void EcuM_AL_DriverInitTwo(void)
{
  // Initialize the SPI Unit.
  Spi_Init(&Spi_ConfigData);
}


EXTERN_C
Std_ReturnType EcuM_GetState(EcuM_StateType* EcuM_StatePtr)
{
  if(EcuM_StatePtr != nullptr)
  {
    *EcuM_StatePtr = EcuM_MyState;

    return E_OK;
  }
  else
  {
    return E_NOT_OK;
  }
}

EXTERN_C
void EcuM_SleepActivity(void)
{
  // poll wakeup source.

}

EXTERN_C
void EcuM_ShutdownHook(void)
{

}

EXTERN_C
void EcuM_Shutdown(void)
{
// SLEEP?
// OFF?
// RESET?

  EcuM_AL_SwitchOff(); // Endless loop.
}

EXTERN_C
void EcuM_AL_SwitchOff(void)
{
  // Endless Loop
  for(;;)
  {
  }

  // Or limit the endless loop and after a sufficient long time
  // reset the ECU using:
  // Mcu_PerformReset();
}


EXTERN_C
void EcuM_MainFunction(void)
{
  switch(EcuM_MyState)
  {
    case ECUM_STATE_STARTUP:
      
      break;

    case ECUM_STATE_RESET:
      
      break;

    case ECUM_STATE_SHUTDOWN:
      
      break;

    case ECUM_STATE_APP_RUN:
      
      break;

    case ECUM_STATE_RUN:
         
      break;

    case ECUM_STATE_OFF:
      
      break;

    default:
      EcuM_MyState = ECUM_STATE_RUN;
      break;
  }
}
