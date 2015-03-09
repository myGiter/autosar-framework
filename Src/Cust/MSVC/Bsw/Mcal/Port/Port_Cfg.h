/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PORT_CFG_2013_02_21_H_
  #define _PORT_CFG_2013_02_21_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Port/Port_ConfigTypes.h>

  #define PORT_SET_PIN_DIRECTION_API      STD_OFF
  #define PORT_REFRESH_DIRECTION_API      STD_OFF
  #define PORT_SET_PIN_MODE_API           STD_OFF

  typedef struct struct_Port_ConfigType
  {
    uint32 dummy;
  }
  Port_ConfigType;

  EXTERN_C const Port_ConfigType Port_ConfigSet;

#endif // _PORT_CFG_2013_02_21_H_
