/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Common/Cpu/McalCpu.h>
#include <array>

EXTERN_C void __initial_stack_pointer();

EXTERN_C void __my_startup         () __attribute__((used, noinline));
EXTERN_C void __vector_unused_irq  () __attribute__((used, noinline));
EXTERN_C void __nmi_handler        () __attribute__((used, noinline));
EXTERN_C void __hard_fault_handler () __attribute__((used, noinline));
EXTERN_C void __mem_manage_handler () __attribute__((used, noinline));
EXTERN_C void __bus_fault_handler  () __attribute__((used, noinline));
EXTERN_C void __usage_fault_handler() __attribute__((used, noinline));
EXTERN_C void __svc_handler        () __attribute__((used, noinline));
EXTERN_C void __debug_mon_handler  () __attribute__((used, noinline));
EXTERN_C void __pend_sv_handler    () __attribute__((used, noinline));
EXTERN_C void __sys_tick_handler   () __attribute__((used, noinline));
EXTERN_C void __timer4_irq_handler ();

EXTERN_C void __vector_unused_irq  () { for(;;) { mcal::cpu::nop(); } }
EXTERN_C void __nmi_handler        () { for(;;) { mcal::cpu::nop(); } }
EXTERN_C void __hard_fault_handler () { for(;;) { mcal::cpu::nop(); } }
EXTERN_C void __mem_manage_handler () { for(;;) { mcal::cpu::nop(); } }
EXTERN_C void __bus_fault_handler  () { for(;;) { mcal::cpu::nop(); } }
EXTERN_C void __usage_fault_handler() { for(;;) { mcal::cpu::nop(); } }
EXTERN_C void __svc_handler        () { for(;;) { mcal::cpu::nop(); } }
EXTERN_C void __debug_mon_handler  () { for(;;) { mcal::cpu::nop(); } }
EXTERN_C void __pend_sv_handler    () { for(;;) { mcal::cpu::nop(); } }
EXTERN_C void __sys_tick_handler   () { for(;;) { mcal::cpu::nop(); } }

namespace
{
  typedef void(*isr_type)();

  constexpr std::size_t number_of_interrupts = 80U;
}

EXTERN_C
const volatile std::array<isr_type, number_of_interrupts> __isr_vector __attribute__((section(".isr_vector")));

EXTERN_C
const volatile std::array<isr_type, number_of_interrupts> __isr_vector =
{{
  __initial_stack_pointer,             // 0x0000, initial stack pointer
  __my_startup,                        // 0x0004, reset
  __nmi_handler,                       // 0x0008, NMIException
  __hard_fault_handler,                // 0x000C, HardFaultException
  __mem_manage_handler,                // 0x0010, MemManageException
  __bus_fault_handler,                 // 0x0014, BusFaultException
  __usage_fault_handler,               // 0x0018, UsageFaultException
  nullptr,                             // 0x001C, Reserved
  nullptr,                             // 0x0020, Reserved
  nullptr,                             // 0x0024, Reserved
  nullptr,                             // 0x0028, Reserved
  __svc_handler,                       // 0x002C, SVCHandler
  __debug_mon_handler,                 // 0x0030, DebugMonitor
  nullptr,                             // 0x0034, Reserved
  __pend_sv_handler,                   // 0x0038, PendSVC,
  __sys_tick_handler,                  // 0x003C, SysTickHandler,
  __vector_unused_irq,                 // 0x0040, WWDG_IRQHandler,
  __vector_unused_irq,                 // 0x0044, PVD_IRQHandler,
  __vector_unused_irq,                 // 0x0048, TAMPER_IRQHandler,
  __vector_unused_irq,                 // 0x004C, RTC_IRQHandler,
  __vector_unused_irq,                 // 0x0050, FLASH_IRQHandler,
  __vector_unused_irq,                 // 0x0054, RCC_IRQHandler,
  __vector_unused_irq,                 // 0x0058, EXTI0_IRQHandler,
  __vector_unused_irq,                 // 0x005C, EXTI1_IRQHandler,
  __vector_unused_irq,                 // 0x0060, EXTI2_IRQHandler,
  __vector_unused_irq,                 // 0x0064, EXTI3_IRQHandler,
  __vector_unused_irq,                 // 0x0068, EXTI4_IRQHandler,
  __vector_unused_irq,                 // 0x006C, DMAChannel1_IRQHandler,
  __vector_unused_irq,                 // 0x0070, DMAChannel2_IRQHandler,
  __vector_unused_irq,                 // 0x0074, DMAChannel3_IRQHandler,
  __vector_unused_irq,                 // 0x0078, DMAChannel4_IRQHandler,
  __vector_unused_irq,                 // 0x007C, DMAChannel5_IRQHandler,
  __vector_unused_irq,                 // 0x0080, DMAChannel6_IRQHandler,
  __vector_unused_irq,                 // 0x0084, DMAChannel7_IRQHandler,
  __vector_unused_irq,                 // 0x0088, ADC_IRQHandler,
  __vector_unused_irq,                 // 0x008C, USB_HP_CAN_TX_IRQHandler,
  __vector_unused_irq,                 // 0x0090, USB_LP_CAN_RX0_IRQHandler,
  __vector_unused_irq,                 // 0x0094, CAN_RX1_IRQHandler,
  __vector_unused_irq,                 // 0x0098, CAN_SCE_IRQHandler,
  __vector_unused_irq,                 // 0x009C, EXTI9_5_IRQHandler,
  __vector_unused_irq,                 // 0x00A0, TIM1_BRK_IRQHandler,
  __vector_unused_irq,                 // 0x00A4, TIM1_UP_IRQHandler,
  __vector_unused_irq,                 // 0x00A8, TIM1_TRG_COM_IRQHandler,
  __vector_unused_irq,                 // 0x00AC, TIM1_CC_IRQHandler,
  __vector_unused_irq,                 // 0x00B0, TIM2_IRQHandler,
  __vector_unused_irq,                 // 0x00B4, TIM3_IRQHandler,
  __timer4_irq_handler,                // 0x00B8, TIM4_IRQHandler,
  __vector_unused_irq,                 // 0x00BC, I2C1_EV_IRQHandler,
  __vector_unused_irq,                 // 0x00C0, I2C1_ER_IRQHandler,
  __vector_unused_irq,                 // 0x00C4, I2C2_EV_IRQHandler,
  __vector_unused_irq,                 // 0x00C8, I2C2_ER_IRQHandler,
  __vector_unused_irq,                 // 0x00CC, SPI1_IRQHandler,
  __vector_unused_irq,                 // 0x00D0, SPI2_IRQHandler,
  __vector_unused_irq,                 // 0x00D4, USART1_IRQHandler,
  __vector_unused_irq,                 // 0x00D8, USART2_IRQHandler,
  __vector_unused_irq,                 // 0x00DC, USART3_IRQHandler,
  __vector_unused_irq,                 // 0x00E0, EXTI15_10_IRQHandler,
  __vector_unused_irq,                 // 0x00E4, RTCAlarm_IRQHandler,
  __vector_unused_irq,                 // 0x00E8, USBWakeUp_IRQHandler,
  nullptr,                             // 0x00EC, Reserved
  nullptr,                             // 0x00F0, Reserved
  nullptr,                             // 0x00F4, Reserved
  nullptr,                             // 0x00F8, Reserved
  nullptr,                             // 0x00FC, Reserved
  nullptr,                             // 0x0100, Reserved
  nullptr,                             // 0x0104, Reserved
  nullptr,                             // 0x0108 This is for boot in RAM mode for medium density devices.
  nullptr,                             // 0x010C, Unused
  nullptr,                             // 0x0110, Unused
  nullptr,                             // 0x0120, Unused
  nullptr,                             // 0x0130, Unused
  nullptr,                             // 0x0140, Unused
  nullptr,                             // 0x0150, Unused
  nullptr,                             // 0x0160, Unused
  nullptr,                             // 0x0170, Unused
  nullptr,                             // 0x0180, Unused
  nullptr,                             // 0x0190, Unused
  nullptr,                             // 0x01A0, Unused
  nullptr,                             // 0x01B0, Unused
  nullptr,                             // 0x01C0, Unused
}};
