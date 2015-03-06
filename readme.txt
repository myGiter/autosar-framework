Master-Thesis

Reutlingen-University

Automotive Lighting Reutlingen GmbH

Framework für wiederverwendbare Autosar Basis-Software-Module.

by Stephan Hage.

Betreuer: Prof. Dr. rer. pol. Jens Weiland
Mitberichter: Dr. Christopher Kormanyos


Summary
------------------------------------

The assignment of this thesis is to create a manually written,
scalable, portable, and reusable software framework based on 
the Autosar-architecture. This Autosar-Frameworkis intended to
be used for small and large microcontrollers alike. 
The Autosar-Framework can be extended and modified at clearly
defined layers within its architecture, providing
for adaption to other projects and scalability. Small
microcontrollers do not commonly use Autosar due to the large
memory and run-time resources needed for it.

The Autosar-Framework is very lightweight and can be used in
electronic control unit projects with small microcontrollers.
This allows cost-sensitive projects with small microcontrollers
to profit from the standardization provided by Autosar.

For proof of concept, a benchmark has been written that uses
the Autosar-Framework and runs on several target systems with
microcontrollers ranging from small to large. For comparison,
the Arc Core tool chain supporting full Autosar has been used
to configure the same benchmark code for a large microcontroller.
The Software-Component in the benchmark toggles one to four
LEDs (depending on the target system) at 1/ 2 Hz.
This benchmark provides a simple „Hello World“ running within
the Autosar-Framework.

The source-code of Autosar-Framework is provided under the
free boost software license.

Supported Targets in this Master-Thesis
----------------------------------------------

The following targets are supported:
  * Win32 in both Release and Debug modes
  * ATMEL(R) AVR(R) Atmega328P
  * ATMEL(R) AVR(R) Atmega32U4
  * ATMEL(R) At91sam3X8E ARM(R) Cortex(TM)-M3
  * Raspberry Pi(R) BCM2835 ARM(R)11
  * Renesas(R) RX63N
  * ST microelectronics(R) STM32F030 ARM(R) Cortex(TM)-M0
  * ST microelectronics(R) STM32F100 ARM(R) Cortex(TM)-M3
  * ST microelectronics(R) STM32F303 ARM(R) Cortex(TM)-M4
  * ST microelectronics(R) STM32F334 ARM(R) Cortex(TM)-M4
  * ST microelectronics(R) STM32F407 ARM(R) Cortex(TM)-M4F
  * ST microelectronics(R) STM32F429 ARM(R) Cortex(TM)-M4F
  * ST microelectronics(R) STM32L152 ARM(R) Cortex(TM)-M4F
  * Texas Instruments(R) Sitara AM3358BZCZ ARM(R) Cortex(TM)-A8