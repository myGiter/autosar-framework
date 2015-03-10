/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef ECUM_2014_10_09_H
  #define ECUM_2014_10_09_H

  //=============================================================================
  // includes
  //=============================================================================

  #include <Bsw/Common/Cpu/McalCpu.h>
  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Servl/EcuM/EcuM_Cfg.h>
  #include <Bsw/Mcal/Mcal.h>

  //=============================================================================
  // type definitions
  //=============================================================================

  typedef uint8  EcuM_StateType;
  typedef uint8  EcuM_UserType;
  typedef uint32 EcuM_WakeupSourceType;
  typedef uint8  EcuM_WakeupStatusType;
  typedef uint8  EcuM_WakeupReactionType;
  typedef uint8  EcuM_BootTargetType;
  typedef uint8  EcuM_AppModeType;

  //=============================================================================
  // EcuM States
  //=============================================================================

  #define ECUM_STATE_RUN               ((EcuM_StateType) 0x30U)
  #define ECUM_STATE_RESET             ((EcuM_StateType) 0x90U)
  #define ECUM_STATE_SHUTDOWN          ((EcuM_StateType) 0x40U)
  #define ECUM_STATE_OFF               ((EcuM_StateType) 0x80U)
  #define ECUM_STATE_STARTUP           ((EcuM_StateType) 0x10U)
  #define ECUM_STATE_APP_RUN           ((EcuM_StateType) 0x32U)

  #define ECUM_STATE_SLEEP             ((EcuM_StateType) 0x50U)
  #define ECUM_STATE_WAKEUP            ((EcuM_StateType) 0x20U)
//  #define ECUM_SUBSTATE_MASK           ((EcuM_StateType) 0x0FU)
//  #define ECUM_STATE_WAKEUP_WAKESLEEP  ((EcuM_StateType) 0x25U)
//  #define ECUM_STATE_WAKEUP_ONE        ((EcuM_StateType) 0x21U)

  #define ECUM_STATE_PREP_SHUTDOWN     ((EcuM_StateType) 0x44U)
  #define ECUM_STATE_STARTUP_TWO       ((EcuM_StateType) 0x12U)
//  #define ECUM_STATE_WAKEUP_TTII       ((EcuM_StateType) 0x26U)
//  #define ECUM_STATE_WAKEUP_VALIDATION ((EcuM_StateType) 0x22U)
  #define ECUM_STATE_GO_SLEEP          ((EcuM_StateType) 0x49U)
  #define ECUM_STATE_STARTUP_ONE       ((EcuM_StateType) 0x11U)
//  #define ECUM_STATE_WAKEUP_TWO        ((EcuM_StateType) 0x24U)
//  #define ECUM_STATE_WAKEUP_REACTION   ((EcuM_StateType) 0x23U)
//  #define ECUM_STATE_APP_POST_RUN      ((EcuM_StateType) 0x33U)
  #define ECUM_STATE_GO_OFF_TWO        ((EcuM_StateType) 0x4EU)
  #define ECUM_STATE_GO_OFF_ONE        ((EcuM_StateType) 0x4DU)

  //=============================================================================
  // EcuM_WakeupSourceType
  //=============================================================================
  #define ECUM_WKSOURCE_POWER          ((EcuM_WakeupSourceType) 0x01U)
  #define ECUM_WKSOURCE_RESET          ((EcuM_WakeupSourceType) 0x02U)
  #define ECUM_WKSOURCE_INTERNAL_RESET ((EcuM_WakeupSourceType) 0x04U)
  #define ECUM_WKSOURCE_INTERNAL_WDG   ((EcuM_WakeupSourceType) 0x08U)
  #define ECUM_WKSOURCE_EXTERNAL_WDG   ((EcuM_WakeupSourceType) 0x10U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x20U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x40U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x80U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x100U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x200U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x400U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x800U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x1000U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x2000U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x4000U)
//  #define ECUM_WKSOURCE_     ((EcuM_WakeupSourceType) 0x8000U)
 // ..

  //=============================================================================
  // EcuM_WakeupStatusType
  //=============================================================================
//  #define ECUM_WKSTATUS_NONE           ((EcuM_WakeupStatusType) 0x01U)
//  #define ECUM_WKSTATUS_PENDING        ((EcuM_WakeupStatusType) 0x02U)
//  #define ECUM_WKSTATUS_VALIDATED      ((EcuM_WakeupStatusType) 0x04U)
//  #define ECUM_WKSTATUS_EXPIRED        ((EcuM_WakeupStatusType) 0x08U)

  //=============================================================================
  // EcuM_WakeupReactionType
  //=============================================================================
//  #define ECUM_WKACT_RUN               ((EcuM_WakeupReactionType) 0x01U)
//  #define ECUM_WKACT_TTII              ((EcuM_WakeupReactionType) 0x04U)
//  #define ECUM_WKACT_SHUTDOWN          ((EcuM_WakeupReactionType) 0x08U)

  //=============================================================================
  // EcuM_BootTargetType
  //=============================================================================
  #define ECUM_BOOT_TARGET_APP         ((EcuM_BootTargetType) 0x00U)
  #define ECUM_BOOT_TARGET_BOOTLOADER  ((EcuM_BootTargetType) 0x01U)

  //=============================================================================
  // EcuM_AppModeType
  //=============================================================================
//  #define ECUM_OSDEFAULTAPPMODE         ((EcuM_AppModeType) 0x01U)

  //=============================================================================
  // function prototypes
  //=============================================================================

  EXTERN_C void           EcuM_Init      (void);
  EXTERN_C void           EcuM_StartupTwo(void);
  EXTERN_C void           EcuM_Shutdown  (void);
  EXTERN_C Std_ReturnType EcuM_GetState  (EcuM_StateType* state);

  EXTERN_C Std_ReturnType EcuM_RequestRUN(EcuM_UserType user);
  EXTERN_C Std_ReturnType EcuM_ReleaseRUN(EcuM_UserType user);

  EXTERN_C void EcuM_AL_DriverInitZero   (void);
  EXTERN_C void EcuM_AL_DriverInitOne    (void);
  EXTERN_C void EcuM_AL_DriverInitTwo    (void);
  EXTERN_C void EcuM_AL_DriverInitThree  (void);

  EXTERN_C void EcuM_MainFunction        (void);

  EXTERN_C void EcuM_AL_DriverRestart    (void);

  EXTERN_C void EcuM_SleepActivity       (void);
  EXTERN_C void EcuM_CheckWakeup         (EcuM_WakeupSourceType wakeupSource);

  EXTERN_C void EcuM_OnPrepShutdown(void);
  EXTERN_C void EcuM_OnGoSleep(void);
  EXTERN_C void EcuM_OnGoOffOne(void);
  EXTERN_C void EcuM_OnGoOffTwo(void);
  EXTERN_C Std_ReturnType EcuM_SelectShutdownTarget(EcuM_StateType target, uint8 mode);
  EXTERN_C Std_ReturnType EcuM_GetShutdownTarget(EcuM_StateType* shutdownTarget, uint8* sleepMode);
  EXTERN_C Std_ReturnType EcuM_GetLastShutdownTarget(EcuM_StateType* shutdownTarget, uint8* sleepMode);

  EXTERN_C void EcuM_ErrorHook           (Std_ReturnType reason);

  EXTERN_C void EcuM_StartupHook_App     (void);
  EXTERN_C void EcuM_ShutdownHook_App    (void);

  EXTERN_C void EcuM_ShutdownHook        (void);

  EXTERN_C void EcuM_AL_SwitchOff        (void);

  EXTERN_C Std_ReturnType EcuM_SelectBootTarget(EcuM_BootTargetType target);

#endif // ECUM_2014_10_09_H
