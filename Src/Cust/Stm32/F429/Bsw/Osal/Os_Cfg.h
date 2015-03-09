/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _OS_CFG_2014_10_14_H_
  #define _OS_CFG_2014_10_14_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/EcuM/EcuM.h>
  #include <Bsw/Osal/Os_ConfigTypes.h>

  // Declare all of the tasks and their initialization functions.
  EXTERN_C void rpDebugMonitor_Init(void);
  EXTERN_C void rpDebugMonitor_Func(void);

  EXTERN_C void rpEcuM_Main_Init(void);
  EXTERN_C void rpEcuM_Main_Func(void);

  EXTERN_C void rpTask1_Init(void);
  EXTERN_C void rpTask1_Func(void);

  EXTERN_C void rpTask2_Init(void);
  EXTERN_C void rpTask2_Func(void);

  // Configure the operating system tasks.
  #define OS_TASK_COUNT 3U

/*
    task_control_block(rpDebugMonitor_Init,                                      \
                       rpDebugMonitor_Func,                                      \
                       task_control_block::timer_type::microseconds(   250UL),   \
                       task_control_block::timer_type::microseconds(     0UL)),  \
*/

  #define OS_TASK_LIST                                                           \
  {{                                                                             \
   task_control_block(rpEcuM_Main_Init,                                         \
                       rpEcuM_Main_Func,                                         \
                       task_control_block::timer_type::microseconds(  2000UL),   \
                       task_control_block::timer_type::microseconds(   417UL)),  \
    task_control_block(rpTask1_Init,                                             \
                       rpTask1_Func,                                             \
                       task_control_block::timer_type::microseconds(  2000UL),   \
                       task_control_block::timer_type::microseconds(   513UL)),  \
    task_control_block(rpTask2_Init,                                             \
                       rpTask2_Func,                                             \
                       task_control_block::timer_type::microseconds(  3000UL),   \
                       task_control_block::timer_type::microseconds(   739UL)),  \
  }}

  // Configure the operating system events.
  typedef enum enumTaskIdType
  {
    rpEcuM_Main_ID,
    rpTask1_ID,
    rpTask2_ID,
    rpMaxID
  }
  TaskIdType;

#endif // _OS_CFG_2014_10_14_H_
