/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef MCAL_REG_2015_02_16_H
  #define MCAL_REG_2015_02_16_H

  #include <Bsw/Common/Std_Types.h>

  namespace mcal
  {
    namespace reg
    {
      constexpr uint8 sfr_offset = UINT8_C(0x20);

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
      constexpr uint8 pina    = UINT8_C(0x00) + sfr_offset;
      constexpr uint8 ddra    = UINT8_C(0x01) + sfr_offset;
      constexpr uint8 porta   = UINT8_C(0x02) + sfr_offset;

      constexpr uint8 pinb    = UINT8_C(0x03) + sfr_offset;
      constexpr uint8 ddrb    = UINT8_C(0x04) + sfr_offset;
      constexpr uint8 portb   = UINT8_C(0x05) + sfr_offset;

      constexpr uint8 pinc    = UINT8_C(0x06) + sfr_offset;
      constexpr uint8 ddrc    = UINT8_C(0x07) + sfr_offset;
      constexpr uint8 portc   = UINT8_C(0x08) + sfr_offset;

      constexpr uint8 pind    = UINT8_C(0x09) + sfr_offset;
      constexpr uint8 ddrd    = UINT8_C(0x0A) + sfr_offset;
      constexpr uint8 portd   = UINT8_C(0x0B) + sfr_offset;

      constexpr uint8 pine    = UINT8_C(0x0C) + sfr_offset;
      constexpr uint8 ddre    = UINT8_C(0x0D) + sfr_offset;
      constexpr uint8 porte   = UINT8_C(0x0E) + sfr_offset;

      constexpr uint8 pinf    = UINT8_C(0x0F) + sfr_offset;
      constexpr uint8 ddrf    = UINT8_C(0x10) + sfr_offset;
      constexpr uint8 portf   = UINT8_C(0x11) + sfr_offset;

      constexpr uint8 ping    = UINT8_C(0x12) + sfr_offset;
      constexpr uint8 ddrg    = UINT8_C(0x13) + sfr_offset;
      constexpr uint8 portg   = UINT8_C(0x14) + sfr_offset;

      constexpr uint16 pinh    = UINT16_C(0x100);
      constexpr uint16 ddrh    = UINT16_C(0x101);
      constexpr uint16 porth   = UINT16_C(0x102);

      constexpr uint16 pinj    = UINT16_C(0x103);
      constexpr uint16 ddrj    = UINT16_C(0x104);
      constexpr uint16 portj   = UINT16_C(0x105);

      constexpr uint16 pink    = UINT16_C(0x106);
      constexpr uint16 ddrk    = UINT16_C(0x107);
      constexpr uint16 portk   = UINT16_C(0x108);

      constexpr uint16 pinl    = UINT16_C(0x109);
      constexpr uint16 ddrl    = UINT16_C(0x10A);
      constexpr uint16 portl   = UINT16_C(0x10B);

      // Timer registers
      constexpr uint8 tifr0   = UINT8_C(0x15) + sfr_offset;
      constexpr uint8 tifr1   = UINT8_C(0x16) + sfr_offset;
      constexpr uint8 tifr2   = UINT8_C(0x17) + sfr_offset;
      constexpr uint8 tifr3   = UINT8_C(0x18) + sfr_offset;
      constexpr uint8 tifr4   = UINT8_C(0x19) + sfr_offset;
      constexpr uint8 tifr5   = UINT8_C(0x1A) + sfr_offset;

      constexpr uint8 tccr0a  = UINT8_C(0x24) + sfr_offset;
      constexpr uint8 tccr0b  = UINT8_C(0x25) + sfr_offset;
      constexpr uint8 tcnt0   = UINT8_C(0x26) + sfr_offset;
      constexpr uint8 ocr0a   = UINT8_C(0x27) + sfr_offset;
      constexpr uint8 ocr0b   = UINT8_C(0x28) + sfr_offset;
      constexpr uint8 timsk0  = UINT8_C(0x6E);
      constexpr uint8 timsk1  = UINT8_C(0x6F);
      constexpr uint8 timsk2  = UINT8_C(0x70);
      constexpr uint8 timsk3  = UINT8_C(0x71);
      constexpr uint8 timsk4  = UINT8_C(0x72);
      constexpr uint8 timsk5  = UINT8_C(0x73);
      constexpr uint8 adcl    = UINT8_C(0x78);
      constexpr uint8 adch    = UINT8_C(0x79);
      constexpr uint8 adcsra  = UINT8_C(0x7A);
      constexpr uint8 adcsrb  = UINT8_C(0x7B);
      constexpr uint8 admux   = UINT8_C(0x7C);
      constexpr uint8 didr2   = UINT8_C(0x7D);
      constexpr uint8 didr0   = UINT8_C(0x7E);
      constexpr uint8 didr1   = UINT8_C(0x7F);
      constexpr uint8 tccr1a  = UINT8_C(0x80);
      constexpr uint8 tccr1b  = UINT8_C(0x81);
      constexpr uint8 tccr1c  = UINT8_C(0x82);
      constexpr uint8 tcnt1l  = UINT8_C(0x84);
      constexpr uint8 tcnt1h  = UINT8_C(0x85);
      constexpr uint8 icr1l   = UINT8_C(0x86);
      constexpr uint8 icr1h   = UINT8_C(0x87);
      constexpr uint8 ocr1al  = UINT8_C(0x88);
      constexpr uint8 ocr1ah  = UINT8_C(0x89);
      constexpr uint8 ocr1bl  = UINT8_C(0x8A);
      constexpr uint8 ocr1bh  = UINT8_C(0x8B);
      constexpr uint8 ocr1cl  = UINT8_C(0x8C);
      constexpr uint8 ocr1ch  = UINT8_C(0x8D);
      constexpr uint8 tccr3a  = UINT8_C(0x90);
      constexpr uint8 tccr3b  = UINT8_C(0x91);
      constexpr uint8 tccr3c  = UINT8_C(0x92);
      constexpr uint8 tcnt3l  = UINT8_C(0x94);
      constexpr uint8 tcnt3h  = UINT8_C(0x95);
      constexpr uint8 icr3l   = UINT8_C(0x96);
      constexpr uint8 icr3h   = UINT8_C(0x97);
      constexpr uint8 ocr3al  = UINT8_C(0x98);
      constexpr uint8 ocr3ah  = UINT8_C(0x99);
      constexpr uint8 ocr3bl  = UINT8_C(0x9A);
      constexpr uint8 ocr3bh  = UINT8_C(0x9B);
      constexpr uint8 ocr3cl  = UINT8_C(0x9C);
      constexpr uint8 ocr3ch  = UINT8_C(0x9D);

      constexpr uint8 twbr    = UINT8_C(0xB8);
      constexpr uint8 twsr    = UINT8_C(0xB9);
      constexpr uint8 twar    = UINT8_C(0xBA);
      constexpr uint8 twdr    = UINT8_C(0xBB);
      constexpr uint8 twcr    = UINT8_C(0xBC);
      constexpr uint8 twamr   = UINT8_C(0xBD);

      constexpr uint8 tccr4a  = UINT8_C(0xA0);
      constexpr uint8 tccr4b  = UINT8_C(0xA1);
      constexpr uint8 tccr4c  = UINT8_C(0xA2);
      constexpr uint8 tcnt4l  = UINT8_C(0xA4);
      constexpr uint8 tcnt4h  = UINT8_C(0xA5);
      constexpr uint8 icr4l   = UINT8_C(0xA6);
      constexpr uint8 icr4h   = UINT8_C(0xA7);
      constexpr uint8 ocr4al  = UINT8_C(0xA8);
      constexpr uint8 ocr4ah  = UINT8_C(0xA9);
      constexpr uint8 ocr4bl  = UINT8_C(0xAA);
      constexpr uint8 ocr4bh  = UINT8_C(0xAB);
      constexpr uint8 ocr4cl  = UINT8_C(0xAC);
      constexpr uint8 ocr4ch  = UINT8_C(0xAD);
      constexpr uint8 tccr2a  = UINT8_C(0xB0);
      constexpr uint8 tccr2b  = UINT8_C(0xB1);
      constexpr uint8 tcnt2   = UINT8_C(0xB2);
      constexpr uint8 ocr2a   = UINT8_C(0xB3);
      constexpr uint8 ocr2b   = UINT8_C(0xB4);
      constexpr uint8 assr    = UINT8_C(0xB6);
      constexpr uint8 ucsr0a  = UINT8_C(0xC0);
      constexpr uint8 ucsr0b  = UINT8_C(0xC1);
      constexpr uint8 ucsr0c  = UINT8_C(0xC2);
      constexpr uint8 ubrr0l  = UINT8_C(0xC4);
      constexpr uint8 ubrr0h  = UINT8_C(0xC5);
      constexpr uint8 udr0    = UINT8_C(0xC6);
      constexpr uint8 tccr4d  = UINT8_C(0xC3);
      constexpr uint8 tccr4e  = UINT8_C(0xC4);
      constexpr uint8 ucsr1a  = UINT8_C(0xC8);
      constexpr uint8 ucsr1b  = UINT8_C(0xC9);
      constexpr uint8 ucsr1c  = UINT8_C(0xCA);
      constexpr uint8 ubrr1l  = UINT8_C(0xCC);
      constexpr uint8 ubrr1h  = UINT8_C(0xCD);
      constexpr uint8 udr1    = UINT8_C(0xCE);
      constexpr uint8 ucsr2a  = UINT8_C(0xD0);
      constexpr uint8 ucsr2b  = UINT8_C(0xD1);
      constexpr uint8 ucsr2c  = UINT8_C(0xD2);
      constexpr uint8 ubrr2l  = UINT8_C(0xD4);
      constexpr uint8 ubbr2h  = UINT8_C(0xD5);
      constexpr uint8 udr2    = UINT8_C(0xD6);

      // Watchdog registers.
      constexpr uint8 wdtcsr  = UINT8_C(0x60);

      // SPI(TM) registers.
      // SPI Control Register.
      constexpr uint8 spcr    = UINT8_C(0x2C) + sfr_offset;
      // SPI Status Register.
      constexpr uint8 spsr    = UINT8_C(0x2D) + sfr_offset;
      constexpr uint8 spdr    = UINT8_C(0x2E) + sfr_offset;

      // power management.
      constexpr uint8 prr0    = UINT8_C(0x64);
      constexpr uint8 prr1    = UINT8_C(0x65);

      // external interrupt.
      constexpr uint8 eicra   = UINT8_C(0x69);
      constexpr uint8 eicrb   = UINT8_C(0x6A);
      constexpr uint8 eimsk   = UINT8_C(0x1D) + sfr_offset;
      constexpr uint8 eifr    = UINT8_C(0x1C) + sfr_offset;
      constexpr uint8 pcicr   = UINT8_C(0x68);
      constexpr uint8 pcifr   = UINT8_C(0x1B) + sfr_offset;
      constexpr uint8 pcmsk0  = UINT8_C(0x6B);
      constexpr uint8 pcmsk1  = UINT8_C(0x6C);
      constexpr uint8 pcmsk2  = UINT8_C(0x6D);

      // eeprom registers.
      constexpr uint8 eearh   = UINT8_C(0x22) + sfr_offset;
      constexpr uint8 eearl   = UINT8_C(0x21) + sfr_offset;
      constexpr uint8 eedr    = UINT8_C(0x20) + sfr_offset;
      constexpr uint8 eecr    = UINT8_C(0x1F) + sfr_offset;

      // oscillator calibration register.
      constexpr uint8 osccal  = UINT8_C(0x66);
      constexpr uint8 clkpr   = UINT8_C(0x61);

      // other Registers.
      constexpr uint8 gpior0  = UINT8_C(0x1E) + sfr_offset;
      constexpr uint8 gtccr   = UINT8_C(0x23) + sfr_offset;
      constexpr uint8 gpior1  = UINT8_C(0x2A) + sfr_offset;
      constexpr uint8 gpior2  = UINT8_C(0x2B) + sfr_offset;
      constexpr uint8 acsr    = UINT8_C(0x30) + sfr_offset;
      constexpr uint8 ocdr    = UINT8_C(0x31) + sfr_offset;
      constexpr uint8 smcr    = UINT8_C(0x33) + sfr_offset;
      constexpr uint8 mcusr   = UINT8_C(0x34) + sfr_offset;
      constexpr uint8 mcucr   = UINT8_C(0x35) + sfr_offset;
      constexpr uint8 spmcsr  = UINT8_C(0x37) + sfr_offset;
      constexpr uint8 rampz   = UINT8_C(0x3B) + sfr_offset;
      constexpr uint8 eind    = UINT8_C(0x3C) + sfr_offset;
      constexpr uint8 spl     = UINT8_C(0x3D) + sfr_offset;
      constexpr uint8 sph     = UINT8_C(0x3E) + sfr_offset;
      constexpr uint8 sreg    = UINT8_C(0x3F) + sfr_offset;
      constexpr uint8 xmcra   = UINT8_C(0x74);
      constexpr uint8 xmcrb   = UINT8_C(0x75);

      constexpr uint16 tccr5a  = UINT16_C(0x120);
      constexpr uint16 tccr5b  = UINT16_C(0x121);
      constexpr uint16 tccr5c  = UINT16_C(0x122);
      constexpr uint16 tcnt5l  = UINT16_C(0x124);
      constexpr uint16 tcnt5h  = UINT16_C(0x125);
      constexpr uint16 icr5l   = UINT16_C(0x126);
      constexpr uint16 icr5h   = UINT16_C(0x127);
      constexpr uint16 ocr5al  = UINT16_C(0x128);
      constexpr uint16 ocr5ah  = UINT16_C(0x129);
      constexpr uint16 ocr5bl  = UINT16_C(0x12A);
      constexpr uint16 ocr5bh  = UINT16_C(0x12B);
      constexpr uint16 ocr5cl  = UINT16_C(0x12C);
      constexpr uint16 ocr5ch  = UINT16_C(0x12D);
      constexpr uint16 ucsr3a  = UINT16_C(0x130);
      constexpr uint16 ucsr3b  = UINT16_C(0x131);
      constexpr uint16 ucsr3c  = UINT16_C(0x132);
      constexpr uint16 ubrr3l  = UINT16_C(0x134);
      constexpr uint16 ubrr3h  = UINT16_C(0x135);
      constexpr uint16 udr3    = UINT16_C(0x136);
    }
  }
#endif // MCAL_REG_2015_02_16_H
