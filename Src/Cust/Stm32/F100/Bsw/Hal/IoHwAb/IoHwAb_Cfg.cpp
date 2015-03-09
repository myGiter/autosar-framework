/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Hal/IoHwAb/IoHwAb.h>
#include <Bsw/Mcal/Dio/Dio.h>

Std_ReturnType IoHwAb_Set_Digital(IoHwAb_SignalType signal, IoHwAb_LevelType newValue, IoHwAb_StatusType* status)
{
  static_cast<void>(status);

  Std_ReturnType io_result;

  switch(signal)
  {
    case 0:
      Dio_WriteChannel(DIO_CHANNEL_OPERATION, newValue);
      io_result = E_OK;
      break;

    default:
      io_result = E_NOT_OK;
      break;
  }

  return io_result;
}
