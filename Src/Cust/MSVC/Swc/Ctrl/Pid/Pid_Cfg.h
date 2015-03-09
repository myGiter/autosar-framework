/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PID_CFG_2014_01_15_H_
  #define _PID_CFG_2014_01_15_H_

  #include <Bsw/Common/Std_Types.h>

  typedef uint8     Pid_ValueType;

  typedef struct struct_Pid_ConfigType
  {
    uint8 dummy;
  }
  Pid_ConfigType;

  EXTERN_C const Pid_ConfigType Pid_CfgMyConfig;

#endif // _PID_CFG_2014_01_15_H_
