/* Linker script for STM32F10x Cortex-M3 ARM MCU */

INPUT(libc.a libm.a libgcc.a)

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)

ENTRY(__my_startup)

/* The beginning and end of the program ROM area */
/* Set up a ROM area with a size of 32K - 4 */
_rom_begin = 0x08000000;
_rom_end   = 0x08007FFC;

/* The beginning and end (i.e., the top) of the stack */
/* Set up a stack with a size of 4K */
_stack_begin = 0x20001C00;
_stack_end   = 0x20002000;

__initial_stack_pointer = _stack_end;


MEMORY
{
  ROM(rx)   : ORIGIN = 0x08000000, LENGTH = 32K - 4
  RAM(rwx)  : ORIGIN = 0x20000000, LENGTH = 0x2000
}

SECTIONS
{
  . = 0x08000000;
  . = ALIGN(4);

  /* ISR vectors */
  .isr_vector :
  {
    *(.isr_vector)
    . = ALIGN(0x10);
    KEEP(*(.isr_vector))
  } > ROM = 0xAAAA

  /* Program code (text), read-only data and static ctors */
  .text :
  {
    _ctors_begin = .;
    *(.init_array)
    . = ALIGN(4);
    KEEP (*(SORT(.init_array)))
    _ctors_end = .;
    *(.text)
    . = ALIGN(4);
    *(.text*)
    . = ALIGN(4);
    *(.rodata)
    . = ALIGN(4);
    *(.rodata*)
    . = ALIGN(4);
  } > ROM

  .text :
  {
    . = ALIGN(0x10);
  } > ROM = 0xAAAA

  . = 0x20000000;
  . = ALIGN(4);

  /* The ROM-to-RAM initialized data section */
  .data :
  {
    _data_begin = .;
    *(.data)
    . = ALIGN(4);
    KEEP (*(.data))
    *(.data*)
    . = ALIGN(4);
    KEEP (*(.data*))
    _data_end = .;
  } > RAM AT > ROM

  /* The uninitialized (zero-cleared) data section */
  .bss :
  {
    _bss_begin = .;
    *(.bss)
    . = ALIGN(4);
    KEEP (*(.bss))
    *(.bss*)
    . = ALIGN(4);
    KEEP (*(.bss*))
    _bss_end = .;
  } > RAM

  _rom_data_begin = LOADADDR(.data);
}
