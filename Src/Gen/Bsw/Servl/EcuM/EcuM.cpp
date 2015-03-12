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
  EcuM_StateType EcuM_MyShutdownState;
}

void EcuM_SetStateViaHiddenFunction(const EcuM_StateType EcuM_State)
{
  EcuM_MyState = EcuM_State;
}

void EcuM_SetShutdownStateViaHiddenFunction(const EcuM_StateType EcuM_State)
{
  EcuM_MyShutdownState = EcuM_State;
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
void EcuM_OnPrepShutdown(void)
{
  EcuM_SetStateViaHiddenFunction(static_cast<EcuM_StateType>(ECUM_STATE_PREP_SHUTDOWN));
}

EXTERN_C
void EcuM_OnGoSleep(void)
{
  EcuM_SetStateViaHiddenFunction(static_cast<EcuM_StateType>(ECUM_STATE_GO_SLEEP));
}

EXTERN_C
void EcuM_OnGoOffOne(void)
{
  EcuM_SetStateViaHiddenFunction(static_cast<EcuM_StateType>(ECUM_STATE_GO_OFF_ONE));
}

EXTERN_C
void EcuM_OnGoOffTwo(void)
{
  EcuM_SetStateViaHiddenFunction(static_cast<EcuM_StateType>(ECUM_STATE_GO_OFF_TWO));
}

EXTERN_C
void EcuM_SleepActivity(void)
{
  // poll wakeup source.

}

EXTERN_C
void EcuM_ShutdownHook(void)
{
  EcuM_Shutdown();
}

EXTERN_C
void EcuM_Shutdown(void)
{
  EcuM_OnGoOffTwo();
  EcuM_StateType get_shutdown_state;
  Std_ReturnType myReturnState = EcuM_GetShutdownTarget(&get_shutdown_state, nullptr);
  static_cast<void>(myReturnState);

  // RESET:
  if(get_shutdown_state == ECUM_STATE_RESET)
  {
    // reset the ECU using:
    #if (MCU_PERFORM_RESET_API == STD_ON)
      Mcu_PerformReset();
    #endif // MCU_PERFORM_RESET_API == STD_ON or Callout
  }
  // OFF:
  EcuM_AL_SwitchOff();
}

EXTERN_C
void EcuM_AL_SwitchOff(void)
{
  // or WDG will Reset.
  for(;;)
  {
    mcal::cpu::nop();
  }
}

EXTERN_C
Std_ReturnType EcuM_SelectShutdownTarget(EcuM_StateType target, uint8 mode)
{
  static_cast<void>(mode);
  EcuM_OnPrepShutdown();
  Std_ReturnType ReturnState = E_OK;

  switch(target)
  {
    case ECUM_STATE_SLEEP:
      EcuM_SetShutdownStateViaHiddenFunction(static_cast<EcuM_StateType>(ECUM_STATE_SLEEP));
    break;

    case ECUM_STATE_RESET:
      EcuM_SetShutdownStateViaHiddenFunction(static_cast<EcuM_StateType>(ECUM_STATE_RESET));
    break;

    case ECUM_STATE_OFF:
      EcuM_SetShutdownStateViaHiddenFunction(static_cast<EcuM_StateType>(ECUM_STATE_OFF));
    break;

    default:
      ReturnState = E_NOT_OK;
    break;
  }

  return ReturnState;
}

EXTERN_C
Std_ReturnType EcuM_GetShutdownTarget(EcuM_StateType* shutdownTarget, uint8* sleepMode)
{
  static_cast<void>(sleepMode);

  if(shutdownTarget != nullptr)
  {
    *shutdownTarget = EcuM_MyShutdownState;

    return E_OK;
  }
  else
  {
    return E_NOT_OK;
  }
}

EXTERN_C
void EcuM_MainFunction(void)
{
  EcuM_StateType getting_shutdown_state;
  Std_ReturnType returnState = EcuM_GetShutdownTarget(&getting_shutdown_state, nullptr);
  static_cast<void>(returnState);

  switch(EcuM_MyState)
  {
    case ECUM_STATE_STARTUP:
      
      break;

    case ECUM_STATE_SHUTDOWN:
      ShutdownOS();
      break;

    case ECUM_STATE_APP_RUN:
      
      break;

    case ECUM_STATE_RUN:
         
      break;

    case ECUM_STATE_GO_OFF_ONE:
         
      break;

    case ECUM_STATE_GO_OFF_TWO:
         
      break;

    case ECUM_STATE_PREP_SHUTDOWN:
      if(getting_shutdown_state == ECUM_STATE_SLEEP)
      {
        EcuM_OnGoSleep();
      }
      if(getting_shutdown_state == (ECUM_STATE_RESET | ECUM_STATE_OFF))
      {
        EcuM_OnGoOffOne();
      }
      break;

    case ECUM_STATE_GO_SLEEP:
//      EcuM_GenerateRamHash();
      Mcu_SetMode(static_cast<Mcu_ModeType>(1));
      EcuM_SetStateViaHiddenFunction(static_cast<EcuM_StateType>(ECUM_STATE_WAKEUP));
      break;

    case ECUM_STATE_WAKEUP:
      EcuM_SetStateViaHiddenFunction(static_cast<EcuM_StateType>(ECUM_STATE_RUN));
      break;

    default:
      EcuM_MyState = ECUM_STATE_RUN;
      break;
  }
}
