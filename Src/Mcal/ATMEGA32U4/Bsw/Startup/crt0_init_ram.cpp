/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <avr/pgmspace.h>
#include <cstddef>
#include <algorithm>
#include <Bsw/Common/Std_Types.h>
#include <Bsw/Util/TwoPartDataManipulation/two_part_data_manipulation.h>

namespace mcal
{
  namespace cpu
  {
    uint8 read_program_memory(volatile uint8* pointer_to_program_memory)
    {
      return pgm_read_byte(reinterpret_cast<uint16>(pointer_to_program_memory));
    }
  }
}

EXTERN_C
{
  extern std::uintptr_t _rom_data_begin;  // Start address for the initialization values of the rom-to-ram section.
  extern std::uintptr_t _data_begin;      // Start address for the .data section.
  extern std::uintptr_t _data_end;        // End address for the .data section.
  extern std::uintptr_t _bss_begin;       // Start address for the .bss section.
  extern std::uintptr_t _bss_end;         // End address for the .bss section.
}

namespace crt
{
  void init_ram() __attribute__((section(".startup")));
}

void crt::init_ram()
{
  typedef uint16 memory_aligned_type;

  // Copy the data segment initializers from ROM to RAM.
  // Note that all data segments are aligned by 2.
  const std::size_t size = std::size_t(  static_cast<const memory_aligned_type*>(static_cast<const void*>(&_data_end))
                                       - static_cast<const memory_aligned_type*>(static_cast<const void*>(&_data_begin)));


  volatile uint8* rom_source = static_cast<volatile uint8*>(static_cast<volatile void*>(&_rom_data_begin));

  std::for_each(static_cast<memory_aligned_type*>(static_cast<void*>(&_data_begin)),
                static_cast<memory_aligned_type*>(static_cast<void*>(&_data_begin)) + size,
                [&rom_source](memory_aligned_type& ram_destination)
                {
                  // Note that particular care needs to be taken to read program
                  // memory with the function mcal::cpu::read_program_memory().

                  ram_destination = util::make_long(mcal::cpu::read_program_memory(rom_source),
                                                    mcal::cpu::read_program_memory(rom_source + 1U));

                  rom_source += 2U;
                });

  // Clear the bss segment.
  // Note that the bss segment is aligned by 2.
  std::fill(static_cast<memory_aligned_type*>(static_cast<void*>(&_bss_begin)),
            static_cast<memory_aligned_type*>(static_cast<void*>(&_bss_end)),
            static_cast<memory_aligned_type>(0U));
}
