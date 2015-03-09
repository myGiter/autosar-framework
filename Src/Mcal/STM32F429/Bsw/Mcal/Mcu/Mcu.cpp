/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Cpu/McalCpu.h>
#include <Bsw/Mcal/Mcu/Mcu.h>
#include <Bsw/Mcal/Reg/Reg.h>

namespace
{
  Mcu_PllStatusType Mcu_MyPllStatus = MCU_PLL_STATUS_UNDEFINED;
}

EXTERN_C
void Mcu_Init(const Mcu_ConfigType* McuConfig)
{
  static_cast<void>(McuConfig);

  // Initialize the fpu: Enable cp10 and cp11.
  // Note: The address of scb_cpacr is 0xE000ED88.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_or(mcal::reg::scb_cpacr,
                    UINT32_C(0x00F00000));

  // Reset the rcc clock configuration to the default reset state
  // Set the hsion bit.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_or(mcal::reg::rcc_cr,
                    UINT32_C(0x00000001));

  // Reset the rcc_cfgr register.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::rcc_cfgr,
                    UINT32_C(0));

  // Clear the hseon, the csson, and the pllon bits.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_and(mcal::reg::rcc_cr,
                    UINT32_C(0xFEF6FFFF));

  // Reset the pllcfgr register.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::rcc_pllcfgr,
                    UINT32_C(0x24003010));

  // Reset the hsebyp bit.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_and(mcal::reg::rcc_cr,
                    UINT32_C(0xFFFBFFFF));

  // Disable all interrupts.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::rcc_cir,
                    UINT32_C(0));

  // Configure the flash memory.
  // Set the wait states.
  // Activate the flash prefetch.
  // Activate the instruction cache.
  // Activate the data cache.
  constexpr std::uint32_t wait_states = UINT32_C(5);

  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::flash_acr,
                    wait_states | UINT32_C(0x00000700));

  // Enable the power interface clock.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_or(mcal::reg::rcc_apb1enr,
                    UINT32_C(0x10000000));

  // Select the regulator voltage scaling output to "scale 3 mode".
  util::dma<std::uint32_t,
            std::uint32_t>::reg_or(mcal::reg::pwr_cr,
                    UINT32_C(0x0000C000));

  Mcu_InitClock(static_cast<Mcu_ClockType>(0));

//  Std_ReturnType myStatus = Mcu_DistributePllClock();
//  static_cast<void>(myStatus);


/////////////////////////////////////////////////////
// TEST BEGIN
/////////////////////////////////////////////////////
// ENERGY:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_or(mcal::reg::rcc_ahb1enr,
                    UINT32_C(0x40));
// DIRECTION OUTPUT:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_msk(mcal::reg::gpiog_moder,
                    UINT32_C(0x10000000), UINT32_C(0x30000000));

for(;;)
{
// OUTPUT VALUE HIGH:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::gpiog_bsrr,
                    UINT32_C(0x4000));

// OUTPUT VALUE LOW:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::gpiog_bsrr,
                    UINT32_C(0x40000000));
}
/////////////////////////////////////////////////////
// TEST END
/////////////////////////////////////////////////////

  Mcu_PllStatusType myDummyPll = Mcu_GetPllStatus();

  if(myDummyPll == MCU_PLL_UNLOCKED)
  {
    // Select the pll as the system clock source.
    util::dma<std::uint32_t,
              std::uint32_t>::reg_msk(mcal::reg::rcc_cfgr,
                                      UINT32_C(0x02),
                                      UINT32_C(0x03));

    std::uint32_t rcc_cfgr_sws_value = UINT32_C(0);

    // Wait until the pll is latched as the system clock source.
    while(rcc_cfgr_sws_value != UINT32_C(0x00000008))
    {
      rcc_cfgr_sws_value = (util::dma<std::uint32_t,
                                     std::uint32_t>::reg_get(mcal::reg::rcc_cfgr) & UINT32_C(0x0C));
    }

    // Now we have:
    //   * The hse is ready.
    //   * The pll is locked.
    //   * The pll is the clock source.

    Mcu_MyPllStatus = MCU_PLL_LOCKED;
  }
}

EXTERN_C
Std_ReturnType Mcu_InitClock(Mcu_ClockType McuClock)
{
  static_cast<void>(McuClock);

  // Configure the system clock for 168MHz using the PLL.

  // Enable the HSE.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_or(mcal::reg::rcc_cr,
                    UINT32_C(0x00010000));

  // Wait until the hse is ready.
  while(util::dma<std::uint32_t,
                  std::uint32_t>::bit_get(mcal::reg::rcc_cr,
                          UINT32_C(17)) == false)
  {
    mcal::cpu::nop();
  }

  // Set the pll parameters.

  // pll_vco    =  (hse_value / pll_m) * pll_n
  // sysclk     = ((hse_value / pll_m) * pll_n) / pll_p
  // usb, sdio, rng clock
  //            = ((hse_value / pll_m) * pll_n) / pll_q

  constexpr std::uint32_t pll_m = UINT32_C(8);
  constexpr std::uint32_t pll_n = UINT32_C(336);
  constexpr std::uint32_t pll_p = UINT32_C(2);
  constexpr std::uint32_t pll_q = UINT32_C(7);

  constexpr std::uint32_t rcc_pllcfgr_value =
    static_cast<std::uint32_t>(  pll_m
                                | static_cast<std::uint32_t>(pll_n << 6)
                                | static_cast<std::uint32_t>(static_cast<std::uint32_t>((pll_p >> 1) - 1) << 16)
                                | UINT32_C(0x00400000)
                                | static_cast<std::uint32_t>(pll_q << 24));

  // Configure the main pll.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::rcc_pllcfgr,
                    rcc_pllcfgr_value);

  // Set hclk  = sysclk / 1.
  // Set pclk2 =   hclk / 2.
  // Set pclk1 =   hclk / 4.
  util::dma<std::uint32_t,
            std::uint32_t>::reg_or(mcal::reg::rcc_cfgr,
                    UINT32_C(0x00009400));

  // Enable the pll via setting the pllon bit of the rcc_cr register.
  util::dma<std::uint32_t, std::uint32_t>::reg_or(mcal::reg::rcc_cr, UINT32_C(0x01000000));

  // Wait until the pll is locked.
  while(util::dma<std::uint32_t,
                  std::uint32_t>::bit_get(mcal::reg::rcc_cr,
                          UINT32_C(25)) == false)
  {
    mcal::cpu::nop();
  }

  Mcu_MyPllStatus = MCU_PLL_UNLOCKED;

  return E_OK;
}

EXTERN_C
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
  return Mcu_PllStatusType(Mcu_MyPllStatus);
}

EXTERN_C
Std_ReturnType Mcu_DistributePllClock(void)
{
  Mcu_PllStatusType myDummyPll = Mcu_GetPllStatus();

  if(myDummyPll == MCU_PLL_UNLOCKED)
  {
    // Select the pll as the system clock source.
    util::dma<std::uint32_t,
              std::uint32_t>::reg_msk(mcal::reg::rcc_cfgr,
                                      UINT32_C(0x02),
                                      UINT32_C(0x03));

    std::uint32_t rcc_cfgr_sws_value = UINT32_C(0);

    // Wait until the pll is latched as the system clock source.
    while(rcc_cfgr_sws_value != UINT32_C(0x00000008))
    {
      rcc_cfgr_sws_value = (util::dma<std::uint32_t,
                                     std::uint32_t>::reg_get(mcal::reg::rcc_cfgr) & UINT32_C(0x0C));
    }

    // Now we have:
    //   * The hse is ready.
    //   * The pll is locked.
    //   * The pll is the clock source.

    Mcu_MyPllStatus = MCU_PLL_LOCKED;
  }
  else
  {
  
/////////////////////////////////////////////////////
// TEST BEGIN
/////////////////////////////////////////////////////
// ENERGY:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_or(mcal::reg::rcc_ahb1enr,
                    UINT32_C(0x40));
// DIRECTION OUTPUT:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_msk(mcal::reg::gpiog_moder,
                    UINT32_C(0x10000000), UINT32_C(0x30000000));

for(;;)
{
// OUTPUT VALUE HIGH:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::gpiog_bsrr,
                    UINT32_C(0x4000));

// OUTPUT VALUE LOW:
  util::dma<std::uint32_t,
            std::uint32_t>::reg_set(mcal::reg::gpiog_bsrr,
                    UINT32_C(0x40000000));
}
/////////////////////////////////////////////////////
// TEST END
/////////////////////////////////////////////////////
  }
  return E_OK;
}
