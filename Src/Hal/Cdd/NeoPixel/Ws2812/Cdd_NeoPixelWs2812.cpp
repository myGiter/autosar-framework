/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include "Cdd_NeoPixelWs2812.h"
#include <Bsw/Hal/IoHwAb/IoHwAb.h>

Std_ReturnType Cdd_MuxNXP74H_Set_Multiplex(uint8 MuxData)
{
  return E_OK;
}

IoHwAb_LevelType Cdd_MuxNXP74H_Get_SignalValue(uint8 MuxData)
{
  // Set the Multiplexer.
  Std_ReturnType dummy = Cdd_MuxNXP74H_Set_Multiplex(MuxData);

  return IoHwAb_LevelType(0);
}
