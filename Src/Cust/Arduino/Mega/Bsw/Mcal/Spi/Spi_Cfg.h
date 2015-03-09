/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _SPI_CFG_2014_10_09_H_
  #define _SPI_CFG_2014_10_09_H_

  // includes.
  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Spi/Spi_ConfigTypes.h>

  // AUTOSAR_API.
  #define SPI_CANCEL_API                        STD_OFF
  #define SPI_CHANNEL_BUFFERS_ALLOWED           2      // 0..2
  #define SPI_DEV_ERROR_DETECT                  STD_OFF
  #define SPI_HW_STATUS_API                     STD_OFF
  #define SPI_INTERRUPTIBLE_SEQ_ALLOWED         STD_OFF
  #define SPI_LEVEL_DELIVERED                   0      //0..2
  #define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT  STD_OFF

  // Number of configurated Sequences.
  EXTERN_C
  typedef struct struct_Spi_SequenceConfigType
  {
    uint32 dummy;
  }
  Spi_SequenceConfigType;

  // Number of configurated Jobs.
  EXTERN_C
  typedef struct struct_Spi_ChannelConfigType
  {
    uint32 dummy;
//    const Spi_ChannelType SpiChannelId;
//    const Spi_BufferType SpiChannelType;
//    const uint32 SpiDataWidth;
//    const uint32 SpiDefaultData;
//    const Spi_NumberOfDataType SpiEbMaxLength;
//    const Spi_NumberOfDataType SpiIbNBuffers;
//    Spi_TransferStartType SpiTransferStart;
  }
  Spi_ChannelConfigType;

  // Number of configurated Jobs.
  EXTERN_C
  typedef struct struct_Spi_JobConfigType
  {
    uint32 dummy;
//    Spi_JobType SpiJobId;
//    uint32 SpiHwUnit;
//    void(*SpiJobEndNotification)();
//    uint8 SpiJobPriority;
  }
  Spi_JobConfigType;

  EXTERN_C
  typedef struct struct_Spi_ConfigType
  {
    Spi_SequenceConfigType SpiSequenceConfig[1U];
    Spi_JobConfigType SpiJobConfig[1U];
    Spi_ChannelConfigType SpiChannelConfig[1U];
//    Spi_ExternalDeviceType SpiExternalDevice;
  }
  Spi_ConfigType;

  EXTERN_C const Spi_ConfigType Spi_ConfigData;

#endif // _SPI_CFG_2014_10_09_H_
