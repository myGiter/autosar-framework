/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include "Rte_Type.h"

#define IN_RTE_C

#include "Rte_myApp.h"

/******************************************
 * Component: myAppl
 ******************************************/

static Rte_CDS_myApp my_app_instance = { TRUE };

/*
 * Send/Write buffer
 */

Std_ReturnType Rte_Write_PortName01_DataElement01(Rte_CDS_myApp* InstancePtr, const uint8* DataPtrIn)
{
  (void) InstancePtr;

  my_app_instance.my_signal_value = *DataPtrIn;

  return RTE_E_OK;
}

Std_ReturnType Rte_Read_PortName01_DataElement01 (Rte_CDS_myApp* InstancePtr, uint8* DataPtrOut)
{
  (void) InstancePtr;

  *DataPtrOut = my_app_instance.my_signal_value;

  return RTE_E_OK;
}
