/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Mcal/Dio/Dio.h>
#include <Bsw/Servl/EcuM/EcuM.h>

EXTERN_C
void rpTask2_Init()
{
}

EXTERN_C
void rpTask2_Func()
{
  Dio_LevelType dio_val = Dio_ReadChannel(DIO_CHANNEL_A_0);
  if(dio_val == static_cast<Dio_LevelType>(STD_LOW))
  {
//    Dio_WriteChannel(DIO_CHANNEL_C_8, STD_HIGH);
    
    EcuM_SelectShutdownTarget(static_cast<EcuM_StateType>(ECUM_STATE_SLEEP), UINT8_C(0x00));
  }
}
