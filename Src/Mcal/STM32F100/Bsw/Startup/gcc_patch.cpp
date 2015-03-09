/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>

EXTERN_C
{
  void __cxa_pure_virtual() { }

  typedef void(*void_function_type)();

  int atexit(const void_function_type) { return 0; }

  int __errno;
}

void operator delete(void*) { }

namespace std
{
  void __throw_length_error(const char*) { }
  void __throw_out_of_range(const char*) { }
  void __throw_logic_error (const char*) { }
}
