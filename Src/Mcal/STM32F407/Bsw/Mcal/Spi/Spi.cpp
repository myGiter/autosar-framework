/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Mcal/Spi/Spi.h>
#include <Bsw/Mcal/Reg/Reg.h>

EXTERN_C
void Spi_Init(const Spi_ConfigType* ConfigPtr)
{
  static_cast<void>(ConfigPtr);
/*
  // AF5 -- AFRH 31:0 -- Pin 8..15 
  mcal::reg::dynamic_access<std::uint32_t, std::uint32_t>::reg_set(mcal::reg::spi1_cr1, 0x08U);
*/
}

EXTERN_C
Std_ReturnType Spi_DeInit(void)
{
  static_cast<void>(0U);
  return Std_ReturnType(0U);
}

EXTERN_C
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataType* DataBufferPtr)
{
  static_cast<void>(Channel);
  static_cast<void>(DataBufferPtr);
  return Std_ReturnType(0U);
}

EXTERN_C
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence)
{
  static_cast<void>(Sequence);
  return Std_ReturnType(0U);
}

EXTERN_C
Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataType* DataBufferPtr)
{
  static_cast<void>(Channel);
  static_cast<void>(DataBufferPtr);
  return Std_ReturnType(0U);
}

EXTERN_C
Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel, const Spi_DataType* SrcDataBufferPtr, Spi_DataType* DesDataBufferPtr, Spi_NumberOfDataType Length)
{
  static_cast<void>(Channel);
  static_cast<void>(SrcDataBufferPtr);
  static_cast<void>(DesDataBufferPtr);
  static_cast<void>(Length);
  return Std_ReturnType(0U);
}

EXTERN_C
Spi_StatusType Spi_GetStatus(void)
{
  static_cast<void>(0U);
  return Spi_StatusType(0U);
}

EXTERN_C
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job)
{
  static_cast<void>(Job);
  return Spi_JobResultType(0U);
}

EXTERN_C
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequnece)
{
  static_cast<void>(Sequnece);
  return Spi_SeqResultType(0U);
}

EXTERN_C
void Spi_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
  static_cast<void>(versioninfo);
}

EXTERN_C
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence)
{
  static_cast<void>(Sequence);
  return Std_ReturnType(0U);
}

EXTERN_C
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit)
{
  static_cast<void>(HWUnit);
  return Spi_StatusType(0U);
}

EXTERN_C
void Spi_Cancel(Spi_SequenceType Sequence)
{
  static_cast<void>(Sequence);
}

EXTERN_C
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode)
{
  static_cast<void>(Mode);
  return Std_ReturnType(0U);
}
