/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include "Cdd_MuxNXP74HC4067.h"
#include <Bsw/Mcal/Dio/Dio.h>
#include <Bsw/Hal/IoHwAb/IoHwAb.h>

Std_ReturnType Cdd_MuxNXP74H_Set_Multiplex(uint8 MuxData)
{
  Dio_WriteChannel(DIO_CHANNEL_MUX_A, ((MuxData && UINT8_C(0x01)) ? STD_HIGH : STD_LOW));

  Dio_WriteChannel(DIO_CHANNEL_MUX_B, ((MuxData && UINT8_C(0x02)) ? STD_HIGH : STD_LOW));

  Dio_WriteChannel(DIO_CHANNEL_MUX_C, ((MuxData && UINT8_C(0x04)) ? STD_HIGH : STD_LOW));

  Dio_WriteChannel(DIO_CHANNEL_MUX_D, ((MuxData && UINT8_C(0x08)) ? STD_HIGH : STD_LOW));

  return E_OK;
}

IoHwAb_LevelType Cdd_MuxNXP74H_Get_SignalValue(uint8 MuxData)
{
  // Set the Multiplexer.
  Std_ReturnType dummy = Cdd_MuxNXP74H_Set_Multiplex(MuxData);


  Dio_WriteChannel(DIO_CHANNEL_MUX_D, ((MuxData && UINT8_C(0x08)) ? STD_HIGH : STD_LOW));

  return IoHwAb_LevelType(0);
}
