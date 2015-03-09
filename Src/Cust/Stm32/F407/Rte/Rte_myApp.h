/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _RTE_MYAPP_2014_12_10_H_
  #define _RTE_MYAPP_2014_12_10_H_

  #include <Rte/Rte_Type.h>
  #include <Rte/Rte.h>

  #ifdef __cplusplus
  extern "C" {
  #endif /* __cplusplus */

  #ifndef IN_RTE_C
    typedef const Rte_CDS_myApp * const Rte_Instance_myApp;
  #endif

  extern const Rte_CDS_myApp Rte_Inst_myApp;

  /* Runnables */

  /* Ports */
  Std_ReturnType Rte_Write_PortName01_DataElement01(Rte_CDS_myApp* InstancePtr, const uint8* DataPtrIn);
  Std_ReturnType Rte_Read_PortName01_DataElement01 (Rte_CDS_myApp* InstancePtr,       uint8* DataPtrOut);

  #ifdef __cplusplus
    } /* extern "C" */
  #endif /* __cplusplus */

#endif // _RTE_MYAPP_2014_12_10_H_

