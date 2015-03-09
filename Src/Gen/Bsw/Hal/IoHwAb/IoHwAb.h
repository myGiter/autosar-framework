/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef IO_HW_AB_2014_10_09_H
  #define IO_HW_AB_2014_10_09_H

  #include <Bsw/Common/Std_Types.h>

  typedef uint8 IoHwAb_DiscreteGroupType;
  typedef uint8 IoHwAb_SignalDiagnosisType;

  typedef uint16 IoHwAb_SignalType;
  typedef uint8_least IoHwAb_LevelType;
  typedef uint8_least IoHwAb_StatusType;

  typedef uint16 IoHwAb_VoltageType;
  typedef uint16 IoHwAb_CurrentType;
  typedef uint16 IoHwAb_ResistenceType;
  typedef uint16 IoHwAb_PwxPeriodType;
  typedef uint16 IoHwAb_PwxDutyCycleType;

  EXTERN_C Std_ReturnType   IoHwAb_Set_Digital    (IoHwAb_SignalType signal, IoHwAb_LevelType newValue, IoHwAb_StatusType *status);
  EXTERN_C IoHwAb_LevelType IoHwAb_Get_SignalValue(IoHwAb_SignalType signal, IoHwAb_StatusType *status);

#endif // IO_HW_AB_2014_10_09_H
