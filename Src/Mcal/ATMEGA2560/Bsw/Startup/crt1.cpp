/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Util/TwoPartDataManipulation/two_part_data_manipulation.h>

namespace mcal
{
  namespace cpu
  {
    uint8 read_program_memory(volatile uint8* pointer_to_program_memory);
  }
}

EXTERN_C
{
  struct ctor_type
  {
    typedef void(*function_type)();
  };

  extern ctor_type::function_type _ctors_end[];
  extern ctor_type::function_type _ctors_begin[];
}

namespace crt
{
  void init_ctors() __attribute__((section(".startup")));
}

void crt::init_ctors()
{
  typedef uint16 function_aligned_type;

  for(volatile uint8* rom_source  = static_cast<volatile uint8*>(static_cast<volatile void*>(_ctors_end));
                      rom_source != static_cast<volatile uint8*>(static_cast<volatile void*>(_ctors_begin));
                      rom_source -= sizeof(function_aligned_type))
  {
    // Note that particular care needs to be taken to read program
    // memory with the function mcal::cpu::read_program_memory().

    // Read the high byte and the low byte of the ctor function address.
    const uint8 addr_hi = mcal::cpu::read_program_memory(rom_source - 1U);
    const uint8 addr_lo = mcal::cpu::read_program_memory(rom_source - 2U);

    // Create the address of the ctor function.
    const ctor_type::function_type ctor_function_address
      = reinterpret_cast<const ctor_type::function_type>(util::make_long(addr_lo, addr_hi));

    // Call the ctor function.
    ctor_function_address();
  }
}
