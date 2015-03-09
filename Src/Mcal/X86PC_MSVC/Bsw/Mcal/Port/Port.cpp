/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Port/Port.h>

EXTERN_C
void Port_Init(const Port_ConfigType* PortConfig)
{
  static_cast<void>(PortConfig);
}

EXTERN_C
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
  static_cast<void>(Pin);
  static_cast<void>(Direction);
}

EXTERN_C
void Port_RefreshPortDirection(void)
{

}

EXTERN_C
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
  static_cast<void>(Pin);
  static_cast<void>(Mode);
}
