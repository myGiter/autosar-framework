/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef OS_2014_02_21_H
  #define OS_2014_02_21_H

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Servl/Osal/Os_Cfg.h>
  //#include <Bsw/EcuM/EcuM.h>


  // This Operating System has interface similar to that of OSEK.

  EXTERN_C void StartOS     (void);
  EXTERN_C void StartupHook (void);
  EXTERN_C void ShutdownOS  (void);
  EXTERN_C void ShutdownHook(void);

  typedef uint16_least   EventMaskType;
  typedef EventMaskType* EventMaskRefType;

  EXTERN_C StatusType SetEvent  (TaskIdType TaskIndex, EventMaskType TaskEvent);
  EXTERN_C StatusType ClearEvent(EventMaskType TaskEvent);
  EXTERN_C StatusType GetEvent  (TaskIdType TaskIndex, EventMaskRefType TaskEventReference);

  EXTERN_C void DisableAllInterrupts(void);
  EXTERN_C void EnableAllInterrupts (void);

#endif // OS_2014_02_21_H
