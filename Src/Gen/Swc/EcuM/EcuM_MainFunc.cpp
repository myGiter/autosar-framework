/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Servl/EcuM/EcuM.h>

EXTERN_C void rpEcuM_Main_Init()
{
  EcuM_StartupTwo();

  EcuM_MainFunction();
}

EXTERN_C void rpEcuM_Main_Func()
{
  EcuM_MainFunction();
}
