/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _UTIL_NULL_PTR_2014_12_09_H_
  #define _UTIL_NULL_PTR_2014_12_09_H_

  #if defined(__cplusplus)
    #if defined(__GNUC__)

    #elif defined(_MSC_VER) && (_MSC_VER < 1600)
      #include <Bsw/Util/NullPtr/NullPtrWorkaround.h>
    #endif
    #define NULL_PTR static_cast<void*>(0U)
  #else
    #define nullptr ((void*) 0U)
    #define NULL_PTR ((void*) 0U)
  #endif

#endif // _UTIL_NULL_PTR_2014_12_09_H_
