/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _INLINE_2014_10_11_H_
  #define _INLINE_2014_10_11_H_

  #if defined(_MSC_VER)        // Microsoft-compiler

    #if defined(__cplusplus)
      #define INLINE inline
    #else
      #define INLINE _inline
    #endif

  #elif defined(__GNUC__)      // GNU-compiler

    #if defined(__cplusplus)
      #define INLINE inline
    #else
      #define INLINE static inline
    #endif

  #endif

#endif // _INLINE_2014_10_11_H_
