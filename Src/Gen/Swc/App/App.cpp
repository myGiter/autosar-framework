/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Util/Time/Time.hpp>
#include <Rte/Rte_myApp.h>

EXTERN_C void do_app();

namespace
{
  typedef util::timer<uint32> timer_type;
  timer_type app_timer;
}

// Runnables

EXTERN_C void rpTask1_Init()
{
  ::do_app();
}

EXTERN_C void rpTask1_Func()
{
  if(app_timer.timeout())
  {
    app_timer.start_interval(timer_type::seconds(1U));

    ::do_app();
  }
}
