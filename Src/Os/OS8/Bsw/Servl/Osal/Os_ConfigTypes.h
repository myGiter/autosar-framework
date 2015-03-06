/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef OS_CONFIGTYPES_2014_06_17_H
  #define OS_CONFIGTYPES_2014_06_17_H

  // Declare and define the idle task.
  EXTERN_C void rpSysIdle_Func(void);
  #define OS_TASK_IDLE() rpSysIdle_Func()

#endif // OS_CONFIGTYPES_2014_06_17_H
