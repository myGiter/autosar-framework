/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef IO_HW_AB_2015_03_05_H
  #define IO_HW_AB_2015_03_05_H

  #include <Bsw/Common/Std_Types.h>

  typedef uint8_least IoHwAb_SignalType;
  typedef uint8_least IoHwAb_LevelType;
  typedef uint8_least IoHwAb_StatusType;

  EXTERN_C Std_ReturnType IoHwAb_Set_Digital(IoHwAb_SignalType signal, IoHwAb_LevelType newValue, IoHwAb_StatusType *status);

#endif // IO_HW_AB_2015_03_05_H
