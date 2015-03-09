/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Cpu/McalCpu.h>
#include <Bsw/Mcal/Reg/Reg.h>
#include "mcal_osc.h"

namespace
{
  bool set_the_system_clock_to_24mhz()
  {
    // Configure the system clock for 24MHz using the PLL.

    // Enable the HSE.
    util::dma<uint32, uint32>::reg_set(mcal::reg::rcc_cr, 0x00010083UL);

    constexpr uint32 max_counter = 500000UL;

    volatile uint32 startup_counter;

    // Wait until the HSE is ready or exit if timeout occurs.
    for(startup_counter = 0UL; startup_counter < max_counter; ++startup_counter)
    {
      const uint32 tmp = util::dma<uint32, uint32>::reg_get(mcal::reg::rcc_cr);

      if(static_cast<uint32>(tmp & static_cast<uint32>(0x00020000UL)) != static_cast<uint32>(0UL))
    {
        break;
      }
    }

    // Verify that the HSE is ready.
    const bool hse_is_ready = (startup_counter < max_counter);

    if(!hse_is_ready)
    {
      // The HSE is not ready.
      return false;
    }

    // The PLL configuration is: = (HSE / 2) * 6 = 24 MHz.
    util::dma<uint32, uint32>::reg_set(mcal::reg::rcc_cfgr, 0x00130000UL);

    // Enable the PLL.
    util::dma<uint32, uint32>::reg_set(mcal::reg::rcc_cr, 0x01010083UL);

    // Wait until the PLL is locked.
    for(startup_counter = 0UL; startup_counter < max_counter; ++startup_counter)
    {
      const uint32 tmp = util::dma<uint32, uint32>::reg_get(mcal::reg::rcc_cr);

      if(static_cast<uint32>(tmp & static_cast<uint32>(0x00020000UL)) != static_cast<uint32>(0UL))
      {
        break;
      }
    }

    // Verify that the PLL is locked.
    const bool pll_is_locked = (startup_counter < max_counter);

    if(!pll_is_locked)
    {
      // The PLL is not locked.
      return false;
    }

    // Select the PLL as the system clock source.
    util::dma<uint32, uint32>::reg_set(mcal::reg::rcc_cfgr, 0x00130002UL);

    // Wait until the PLL latched as the system clock source.
    for(startup_counter = 0UL; startup_counter < max_counter; ++startup_counter)
    {
      const uint32 tmp = util::dma<uint32, uint32>::reg_get(mcal::reg::rcc_cfgr);

      if(static_cast<uint32>(tmp & static_cast<uint32>(0x0CUL)) == static_cast<uint32>(0x08UL))
      {
        break;
      }
    }

    // Verify that the PLL is the clock source.
    const bool pll_is_the_clock_source = (startup_counter < max_counter);

    // Now we have:
    //   * The HSE is ready.
    //   * The PLL is locked.
    //   * The PLL is the clock source.

    return pll_is_the_clock_source;
  }
}

void mcal::osc::init(const config_type*)
{
  const bool clock_result = ::set_the_system_clock_to_24mhz();

  static_cast<void>(clock_result);
}
