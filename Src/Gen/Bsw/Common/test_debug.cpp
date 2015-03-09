/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/test_debug.h>

EXTERN_C
void test_debug(void)
{
/////////////////////////////////////////////////////
// TEST BEGIN
/////////////////////////////////////////////////////
// ENERGY:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_or(mcal::reg::rcc_ahb1enr,
                    UINT32_C(0x08));
// DIRECTION OUTPUT:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_msk(mcal::reg::gpiod_moder,
                    UINT32_C(0x55000000), UINT32_C(0xFF000000));

for(;;)
{
// OUTPUT VALUE HIGH:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::gpiod_bsrr,
                    UINT32_C(0xF000));

// OUTPUT VALUE LOW:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::gpiod_bsrr,
                    UINT32_C(0xF0000000));
}
/////////////////////////////////////////////////////
// TEST END
/////////////////////////////////////////////////////
}