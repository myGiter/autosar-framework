/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef UTIL_NULL_PTR_2015_01_30_H
  #define UTIL_NULL_PTR_2015_01_30_H

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

#endif // UTIL_NULL_PTR_2015_01_30_H
