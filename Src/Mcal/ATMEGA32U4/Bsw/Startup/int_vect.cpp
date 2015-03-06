/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Common/Cpu/McalCpu.h>

EXTERN_C void __my_startup       () __attribute__((section(".startup"), used, noinline));
EXTERN_C void __vector_unused_irq    () __attribute__((signal, used, externally_visible));
EXTERN_C void __vector_timer0_ovf_irq() __attribute__((signal, used, externally_visible));
EXTERN_C void __vector_wdt_timout_irq() __attribute__((signal, used, externally_visible));
//EXTERN_C void __vector_ext0_irq()       __attribute__((signal, used, externally_visible));
EXTERN_C void __vector_ext1_irq()       __attribute__((signal, used, externally_visible));
//EXTERN_C void __vector_ext2_irq()       __attribute__((signal, used, externally_visible));
//EXTERN_C void __vector_ext3_irq()       __attribute__((signal, used, externally_visible));

EXTERN_C void __vector_unused_irq() { for(;;) { mcal::cpu::nop(); } }

typedef struct struct_isr_type
{
  typedef void(*function_type)();

  uint8  jmp[2]; // JMP instruction (0x940C): 0x0C = low byte, 0x94 = high byte.
  function_type func;   // The interrupt service routine.
}
isr_type;

EXTERN_C
const volatile isr_type isr_vector[43U] __attribute__ ((section(".isr_vector")));

EXTERN_C
const volatile isr_type isr_vector[43U] =
{
                                            // Vector No.  Program Address  Source Interrupt Definition
  {{0x0C, 0x94}, __my_startup },            //  0 reset
  {{0x0C, 0x94}, __vector_unused_irq},      //  1 External Interrupt Request 0
  {{0x0C, 0x94}, __vector_ext1_irq},        //  2 External Interrupt Request 1
  {{0x0C, 0x94}, __vector_unused_irq},      //  3 External Interrupt Request 2
  {{0x0C, 0x94}, __vector_unused_irq},      //  4 External Interrupt Request 3
  {{0x0C, 0x94}, __vector_unused_irq},      //  5 Reserved
  {{0x0C, 0x94}, __vector_unused_irq},      //  6 Reserved
  {{0x0C, 0x94}, __vector_unused_irq},      //  7 External Interrupt Request 6
  {{0x0C, 0x94}, __vector_unused_irq},      //  8 Reserved
  {{0x0C, 0x94}, __vector_unused_irq},      //  9 Pin Change Interrupt Request 0
  {{0x0C, 0x94}, __vector_unused_irq},      // 10 USB General Interrupt request
  {{0x0C, 0x94}, __vector_unused_irq},      // 11 USB Endpoint Interrupt request
  {{0x0C, 0x94}, __vector_wdt_timout_irq},  // 12 Watchdog Time-Out Interrupt
  {{0x0C, 0x94}, __vector_unused_irq},      // 13 Reserved
  {{0x0C, 0x94}, __vector_unused_irq},      // 14 Reserved
  {{0x0C, 0x94}, __vector_unused_irq},      // 15 Reserved
  {{0x0C, 0x94}, __vector_unused_irq},      // 16 Timer/Counter1 Capture Event
  {{0x0C, 0x94}, __vector_unused_irq},      // 17 Timer/Counter1 Compare Match A
  {{0x0C, 0x94}, __vector_unused_irq},      // 18 Timer/Counter1 Compare Match B
  {{0x0C, 0x94}, __vector_unused_irq},      // 19 Timer/Counter1 Compare Match C
  {{0x0C, 0x94}, __vector_unused_irq},      // 20 Timer/Counter1 Overflow
  {{0x0C, 0x94}, __vector_unused_irq},      // 21 Timer/Counter0 Compare Match A
  {{0x0C, 0x94}, __vector_unused_irq},      // 22 Timer/Counter0 Compare Match B
  {{0x0C, 0x94}, __vector_timer0_ovf_irq},  // 23 Timer/Counter0 Overflow
  {{0x0C, 0x94}, __vector_unused_irq},      // 24 SPI Serial Transfer Complete
  {{0x0C, 0x94}, __vector_unused_irq},      // 25 USART1 Rx Complete
  {{0x0C, 0x94}, __vector_unused_irq},      // 26 USART1 Data Register Empty
  {{0x0C, 0x94}, __vector_unused_irq},      // 27 USART1 Tx Complete
  {{0x0C, 0x94}, __vector_unused_irq},      // 28 Analog Comparator
  {{0x0C, 0x94}, __vector_unused_irq},      // 29 ADC Conversion Complete
  {{0x0C, 0x94}, __vector_unused_irq},      // 30 EEPROM Ready
  {{0x0C, 0x94}, __vector_unused_irq},      // 31 Timer/Counter3 Capture Event
  {{0x0C, 0x94}, __vector_unused_irq},      // 32 Timer/Counter3 Compare Match A
  {{0x0C, 0x94}, __vector_unused_irq},      // 33 Timer/Counter3 Compare Match B
  {{0x0C, 0x94}, __vector_unused_irq},      // 34 Timer/Counter3 Compare Match C
  {{0x0C, 0x94}, __vector_unused_irq},      // 35 Timer/Counter3 Overflow
  {{0x0C, 0x94}, __vector_unused_irq},      // 36 2-wire Serial Interface
  {{0x0C, 0x94}, __vector_unused_irq},      // 37 Store Program Memory Ready
  {{0x0C, 0x94}, __vector_unused_irq},      // 38 Timer/Counter4 Compare Match A
  {{0x0C, 0x94}, __vector_unused_irq},      // 39 Timer/Counter4 Compare Match B
  {{0x0C, 0x94}, __vector_unused_irq},      // 40 Timer/Counter4 Compare Match D
  {{0x0C, 0x94}, __vector_unused_irq},      // 41 Timer/Counter4 Overflow
  {{0x0C, 0x94}, __vector_unused_irq},      // 42 Timer/Counter4 Fault Protection Interrupt
};
