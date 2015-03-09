/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PORT_2014_10_09_H_
  #define _PORT_2014_10_09_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Port/Port_Cfg.h>

  EXTERN_C void Port_Init(const Port_ConfigType* PortConfig);

  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
    EXTERN_C void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
  #endif // PORT_SET_PIN_DIRECTION_API == STD_ON

  EXTERN_C void Port_RefreshPortDirection(void);

  #if (PORT_SET_PIN_MODE_API == STD_ON)
    EXTERN_C void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
  #endif // PORT_SET_PIN_MODE_API == STD_ON

#endif // _PORT_2014_10_09_H_
