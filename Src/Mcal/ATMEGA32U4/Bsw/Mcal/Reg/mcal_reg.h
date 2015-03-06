/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _MCAL_REG_2014_10_10_H_
  #define _MCAL_REG_2014_10_10_H_

  #include <cstdint>

  namespace mcal
  {
    namespace reg
    {
      constexpr std::uint8_t sfr_offset = 0x20U;

      // Bit-position values.
      constexpr std::uint8_t bval0   = 1U;
      constexpr std::uint8_t bval1   = 1U << 1U;
      constexpr std::uint8_t bval2   = 1U << 2U;
      constexpr std::uint8_t bval3   = 1U << 3U;
      constexpr std::uint8_t bval4   = 1U << 4U;
      constexpr std::uint8_t bval5   = 1U << 5U;
      constexpr std::uint8_t bval6   = 1U << 6U;
      constexpr std::uint8_t bval7   = 1U << 7U;

      // Port registers
      constexpr std::uint8_t pinb    = 0x03U + sfr_offset;
      constexpr std::uint8_t ddrb    = 0x04U + sfr_offset;
      constexpr std::uint8_t portb   = 0x05U + sfr_offset;

      constexpr std::uint8_t pinc    = 0x06U + sfr_offset;
      constexpr std::uint8_t ddrc    = 0x07U + sfr_offset;
      constexpr std::uint8_t portc   = 0x08U + sfr_offset;

      constexpr std::uint8_t pind    = 0x09U + sfr_offset;
      constexpr std::uint8_t ddrd    = 0x0AU + sfr_offset;
      constexpr std::uint8_t portd   = 0x0BU + sfr_offset;

      constexpr std::uint8_t pine    = 0x0CU + sfr_offset;
      constexpr std::uint8_t ddre    = 0x0DU + sfr_offset;
      constexpr std::uint8_t porte   = 0x0EU + sfr_offset;

      constexpr std::uint8_t pinf    = 0x0FU + sfr_offset;
      constexpr std::uint8_t ddrf    = 0x10U + sfr_offset;
      constexpr std::uint8_t portf   = 0x11U + sfr_offset;

      // Timer registers
      constexpr std::uint8_t tifr0   = 0x15U + sfr_offset;
      constexpr std::uint8_t tifr1   = 0x16U + sfr_offset;
      constexpr std::uint8_t tifr3   = 0x18U + sfr_offset;
      constexpr std::uint8_t tifr4   = 0x19U + sfr_offset;
      constexpr std::uint8_t tccr0a  = 0x24U + sfr_offset;
      constexpr std::uint8_t tccr0b  = 0x25U + sfr_offset;
      constexpr std::uint8_t tcnt0   = 0x26U + sfr_offset;
      constexpr std::uint8_t ocr0a   = 0x27U + sfr_offset;
      constexpr std::uint8_t ocr0b   = 0x28U + sfr_offset;
      constexpr std::uint8_t timsk0  = 0x6EU;
      constexpr std::uint8_t timsk1  = 0x6FU;
      constexpr std::uint8_t timsk3  = 0x71U;
      constexpr std::uint8_t timsk4  = 0x72U;
      constexpr std::uint8_t adcl    = 0x78U;
      constexpr std::uint8_t adch    = 0x79U;
      constexpr std::uint8_t adcsra  = 0x7AU;
      constexpr std::uint8_t adcsrb  = 0x7BU;
      constexpr std::uint8_t admux   = 0x7CU;
      constexpr std::uint8_t didr2   = 0x7DU;
      constexpr std::uint8_t didr0   = 0x7EU;
      constexpr std::uint8_t didr1   = 0x7FU;
      constexpr std::uint8_t tccr1a  = 0x80U;
      constexpr std::uint8_t tccr1b  = 0x81U;
      constexpr std::uint8_t tccr1c  = 0x82U;
      constexpr std::uint8_t tcnt1l  = 0x84U;
      constexpr std::uint8_t tcnt1h  = 0x85U;
      constexpr std::uint8_t icr1l   = 0x86U;
      constexpr std::uint8_t icr1h   = 0x87U;
      constexpr std::uint8_t ocr1al  = 0x88U;
      constexpr std::uint8_t ocr1ah  = 0x89U;
      constexpr std::uint8_t ocr1bl  = 0x8AU;
      constexpr std::uint8_t ocr1bh  = 0x8BU;
      constexpr std::uint8_t ocr1cl  = 0x8CU;
      constexpr std::uint8_t ocr1ch  = 0x8DU;
      constexpr std::uint8_t tccr3a  = 0x90U;
      constexpr std::uint8_t tccr3b  = 0x91U;
      constexpr std::uint8_t tccr3c  = 0x92U;
      constexpr std::uint8_t tcnt3l  = 0x94U;
      constexpr std::uint8_t tcnt3h  = 0x95U;
      constexpr std::uint8_t icr3l   = 0x96U;
      constexpr std::uint8_t icr3h   = 0x97U;
      constexpr std::uint8_t ocr3al  = 0x98U;
      constexpr std::uint8_t ocr3ah  = 0x99U;
      constexpr std::uint8_t ocr3bl  = 0x9AU;
      constexpr std::uint8_t ocr3bh  = 0x9BU;
      constexpr std::uint8_t ocr3cl  = 0x9CU;
      constexpr std::uint8_t ocr3ch  = 0x9DU;
      constexpr std::uint8_t twbr    = 0xB8U;
      constexpr std::uint8_t twsr    = 0xB9U;
      constexpr std::uint8_t twar    = 0xBAU;
      constexpr std::uint8_t twdr    = 0xBBU;
      constexpr std::uint8_t twcr    = 0xBCU;
      constexpr std::uint8_t twamr   = 0xBDU;
      constexpr std::uint8_t tcnt4   = 0xBEU;
      constexpr std::uint8_t tc4h    = 0xBFU;
      constexpr std::uint8_t tccr4a  = 0xC0U;
      constexpr std::uint8_t tccr4b  = 0xC1U;
      constexpr std::uint8_t tccr4c  = 0xC2U;
      constexpr std::uint8_t tccr4d  = 0xC3U;
      constexpr std::uint8_t tccr4e  = 0xC4U;
      constexpr std::uint8_t ucsr1a  = 0xC8U;
      constexpr std::uint8_t ucsr1b  = 0xC9U;
      constexpr std::uint8_t ucsr1c  = 0xCAU;
      constexpr std::uint8_t ubrr1l  = 0xCCU;
      constexpr std::uint8_t ubrr1h  = 0xCDU;
      constexpr std::uint8_t udr1    = 0xCEU;
      constexpr std::uint8_t ocr4a   = 0xCFU;
      constexpr std::uint8_t ocr4b   = 0xD0U;
      constexpr std::uint8_t ocr4c   = 0xD1U;
      constexpr std::uint8_t ocr4d   = 0xD2U;

      constexpr std::uint8_t dt4     = 0xD4U;

      // Watchdog registers.
      constexpr std::uint8_t wdtcsr  = 0x60U;

      // SPI(TM) registers.
      // SPI Control Register.
      constexpr std::uint8_t spcr    = 0x2CU + sfr_offset;
      // SPI Status Register.
      constexpr std::uint8_t spsr    = 0x2DU + sfr_offset;
      constexpr std::uint8_t spdr    = 0x2EU + sfr_offset;

      // power management.
      constexpr std::uint8_t smcr    = 0x33U + sfr_offset;
      constexpr std::uint8_t prr0    = 0x64U;
      constexpr std::uint8_t prr1    = 0x65U;

      // external interrupt.
      constexpr std::uint8_t eicra   = 0x69U;
      constexpr std::uint8_t eicrb   = 0x6AU;
      constexpr std::uint8_t eimsk   = 0x1DU + sfr_offset;
      constexpr std::uint8_t eifr    = 0x1CU + sfr_offset;
      constexpr std::uint8_t pcicr   = 0x68U;
      constexpr std::uint8_t pcifr   = 0x1BU + sfr_offset;
      constexpr std::uint8_t pcmsk0  = 0x6BU;

      // eeprom registers.
      constexpr std::uint8_t eearh   = 0x22U + sfr_offset;
      constexpr std::uint8_t eearl   = 0x21U + sfr_offset;
      constexpr std::uint8_t eedr    = 0x20U + sfr_offset;
      constexpr std::uint8_t eecr    = 0x1FU + sfr_offset;

      // oscillator calibration register.
      constexpr std::uint8_t osccal  = 0x66U;
      constexpr std::uint8_t rcctrl  = 0x67U;
      constexpr std::uint8_t clksel0 = 0xC5U;
      constexpr std::uint8_t clksel1 = 0xC6U;
      constexpr std::uint8_t clksta  = 0xC7U;
      constexpr std::uint8_t clkpr   = 0x61U;
      constexpr std::uint8_t pllcsr  = 0x29U + sfr_offset;
      constexpr std::uint8_t pllfrq  = 0x32U + sfr_offset;

      // other Registers.
      constexpr std::uint8_t gpior0  = 0x1EU + sfr_offset;
      constexpr std::uint8_t gtccr   = 0x23U + sfr_offset;
      constexpr std::uint8_t gpior1  = 0x2AU + sfr_offset;
      constexpr std::uint8_t gpior2  = 0x2BU + sfr_offset;
      constexpr std::uint8_t mcusr   = 0x34U + sfr_offset;
      constexpr std::uint8_t mcucr   = 0x35U + sfr_offset;

    }
  }
#endif // _MCAL_REG_2014_10_10_H_
