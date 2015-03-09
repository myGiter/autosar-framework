/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef OS_CFG_2015_03_05_H
  #define OS_CFG_2015_03_05_H

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Servl/EcuM/EcuM.h>
  #include <Bsw/Servl/Osal/Os_ConfigTypes.h>

  // Declare all of the tasks and their initialization functions.
  EXTERN_C void rpEcuM_Main_Init(void);
  EXTERN_C void rpEcuM_Main_Func(void);

  EXTERN_C void rpTask1_Init(void);
  EXTERN_C void rpTask1_Func(void);

  EXTERN_C void rpTask2_Init(void);
  EXTERN_C void rpTask2_Func(void);

  EXTERN_C void rpDebugMonitor_Init(void);
  EXTERN_C void rpDebugMonitor_Func(void);

  EXTERN_C void rpBenchmarkFpu_Init(void);
  EXTERN_C void rpBenchmarkFpu_Func(void);

  // Configure the operating system tasks.
  #define OS_TASK_COUNT 3U

  #define OS_TASK_LIST                                                             \
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

  typedef enum enumTaskIdType
  {
    rpMaxID
  }
  TaskIdType;

#endif // OS_CFG_2015_03_05_H
