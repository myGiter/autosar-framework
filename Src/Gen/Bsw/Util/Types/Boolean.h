/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _BOOLEAN_2014_10_11_H_
  #define _BOOLEAN_2014_10_11_H_

  #include <stdbool.h>

  // *****************************************************************************
  // types
  // *****************************************************************************

  // Standard AUTOSAR Boolean type.
  #if !defined(_MSC_VER)
  typedef bool boolean;
  #endif

  // Note that bool, true and false are already defined in <stdbool.h>

  #ifdef TRUE
  #undef TRUE
  #endif

  #ifdef FALSE
  #undef FALSE
  #endif

  #define TRUE true
  #define FALSE false

#endif // _BOOLEAN_2014_10_11_H_
