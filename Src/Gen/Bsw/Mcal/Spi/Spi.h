/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _SPI_2014_10_09_H_
  #define _SPI_2014_10_09_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Spi/Spi_Cfg.h>

  EXTERN_C void              Spi_Init              (const Spi_ConfigType* ConfigPtr);

  EXTERN_C Std_ReturnType    Spi_DeInit            (void);

  EXTERN_C Std_ReturnType    Spi_ReadIB            (Spi_ChannelType       Channel,
                                                   Spi_DataType*         DataBufferPtr);

  EXTERN_C Std_ReturnType    Spi_WriteIB           (Spi_ChannelType       Channel,
                                                   const Spi_DataType*   DataBufferPtr);

  EXTERN_C Std_ReturnType    Spi_AsyncTransmit     (Spi_SequenceType      Sequence);

  EXTERN_C Std_ReturnType    Spi_SetupEB           (Spi_ChannelType       Channel,
                                                    const Spi_DataType*   SrcDataBufferPtr,
                                                    Spi_DataType*         DesDataBufferPtr,
                                                    Spi_NumberOfDataType  Length);

  EXTERN_C Spi_StatusType    Spi_GetStatus         (void);

  EXTERN_C Spi_JobResultType Spi_GetJobResult      (Spi_JobType           Job);

  EXTERN_C Spi_SeqResultType Spi_GetSequenceResult (Spi_SequenceType      Sequnece);

  EXTERN_C Std_ReturnType    Spi_SyncTransmit      (Spi_SequenceType      Sequence);

  EXTERN_C Spi_StatusType    Spi_GetHWUnitStatus   (Spi_HWUnitType        HWUnit);

  #if (SPI_CANCEL_API == STD_ON)
    EXTERN_C void              Spi_Cancel            (Spi_SequenceType      Sequence);
  #endif // SPI_CANCEL_API == STD_ON

  EXTERN_C Std_ReturnType    Spi_SetAsyncMode      (Spi_AsyncModeType     Mode);

  EXTERN_C void Spi_MainFunction_Handling(void);

  EXTERN_C void Spi_MainFunction_Driving(void);

  EXTERN_C void (*Spi_JobEndNotification)(void);
  EXTERN_C void (*Spi_SeqEndNotification)(void);

#endif // _SPI_2014_10_09_H_
