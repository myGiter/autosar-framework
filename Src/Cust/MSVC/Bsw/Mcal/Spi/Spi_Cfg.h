/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _SPI_CFG_2013_03_26_H_
  #define _SPI_CFG_2013_03_26_H_

  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Spi/Spi_ConfigTypes.h>

  #define SPI_CANCEL_API                  STD_OFF

  typedef uint32 Spi_DataType;

  EXTERN_C
  typedef struct struct_Spi_ConfigType
  {
    uint32 dummy;
  }
  Spi_ConfigType;

  EXTERN_C const Spi_ConfigType Spi_ConfigData;

#endif // _SPI_CFG_2013_03_26_H_
