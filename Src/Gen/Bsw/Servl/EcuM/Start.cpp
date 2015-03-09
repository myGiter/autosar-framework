/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Servl/EcuM/EcuM.h>

EXTERN_C int main()
{
  EcuM_Init();

  // A potential return from the operating system will be handled
  // in EcuM by the subroutine EcuM_Shutdown().
}
