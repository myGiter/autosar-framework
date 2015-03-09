/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _EXTERN_C_2014_10_11_H_
  #define _EXTERN_C_2014_10_11_H_

  #if defined(EXTERN_C)
    #undef EXTERN_C
  #endif

  #if defined(__cplusplus)
    #define EXTERN_C extern "C"
  #else
    #define EXTERN_C extern
  #endif

#endif // _EXTERN_C_2014_10_11_H_
