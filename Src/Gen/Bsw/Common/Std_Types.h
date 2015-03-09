/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _STD_TYPES_2014_10_09_H_
  #define _STD_TYPES_2014_10_09_H_

  #include <Bsw/Common/Platform_Types.h>
  
  typedef uint8 Std_ReturnType;

  // See AUTOSAR "Specification of Standard Types", Section 8.2.1
  #ifndef STATUSTYPEDEFINED
    #define STATUSTYPEDEFINED
    typedef uint8 StatusType;
    #define E_OK ((StatusType) 0x00U)
  #endif

  #define E_NOT_OK ((StatusType) 0x01U)

  #define STD_HIGH    0x01U
  #define STD_LOW     0x00U

  #define STD_ACTIVE  0x01U
  #define STD_IDLE    0x00U

  #define STD_ON      0x01U
  #define STD_OFF     0x00U

#endif // _STD_TYPES_2014_10_09_H_
