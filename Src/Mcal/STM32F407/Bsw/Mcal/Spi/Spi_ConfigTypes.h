/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _SPI_CONFIG_TYPES_2014_12_10_H_
  #define _SPI_CONFIG_TYPES_2014_12_10_H_

  typedef uint32 Spi_DataType;

  // AUTOSAR fix size.
  typedef uint16 Spi_NumberOfDataType;
  typedef uint8  Spi_ChannelType;
  typedef uint16 Spi_JobType;
  typedef uint8  Spi_SequenceType;
  typedef uint8  Spi_HWUnitType;

  EXTERN_C
    typedef enum enum_Spi_StatusType
  {
    SPI_UNINIT,
    SPI_IDLE,
    SPI_BUSY
  }
  Spi_StatusType;

  EXTERN_C
    typedef enum enum_Spi_JobResultType
  {
    SPI_JOB_OK,
    SPI_JOB_PENDING,
    SPI_JOB_FAILED
  }
  Spi_JobResultType;

  EXTERN_C
    typedef enum enum_Spi_SeqResultType
  {
    SPI_SEQ_OK,
    SPI_SEQ_PENDING,
    SPI_SEQ_FAILED,
    SPI_SEQ_CANCELLED
  }
  Spi_SeqResultType;

  EXTERN_C
    typedef enum enum_Spi_AsyncModeType
  {
    SPI_POLLING_MODE,
    SPI_INTERRUPT_MODE
  }
  Spi_AsyncModeType;

#endif // _SPI_CONFIG_TYPES_2014_12_10_H_
