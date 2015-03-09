/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _NULL_PTR_2014_10_13_H_
  #define _NULL_PTR_2014_10_13_H_
  #if defined(__cplusplus)
//    #include <Bsw/Util/NullPtr/UtilNullPtr.h>
    #define NULL_PTR static_cast<void*>(0U)
  #else
    #define nullptr ((void*) 0U)
    #define NULL_PTR ((void*) 0U)
  #endif

#endif // _NULL_PTR_2014_10_13_H_
