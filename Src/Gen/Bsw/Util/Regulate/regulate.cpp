#include <Windows.h>
#include <iostream>


#include <cstdint>
#include "RegulationPir.hpp"

typedef util::regulation_pir_order1 <std::uint16_t,
                                     std::uint32_t,
                                      3U,
                                      2U,
                                     10U,
                                   2000U,
                                     32U> filter_type;

filter_type::large_type system_value = 1000U;
filter_type::large_type target_value;
filter_type filter(system_value);

int main()
{
  for(;;)
  {
    system_value = 970U;

    for(unsigned i = 0U; i < 20U; ++i)
    {
      target_value = filter.func(system_value, 1000U);

      ++system_value;

      std::cout << unsigned(target_value) << std::endl;

      ::Sleep(50U);
    }

    system_value = 1030U;

    for(unsigned i = 0U; i < 20U; ++i)
    {
      target_value = filter.func(system_value, 1000);

      --system_value;

      std::cout << unsigned(target_value) << std::endl;

      ::Sleep(50U);
    }
  }
}
