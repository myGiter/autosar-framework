/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _TYPE_VERSION_2014_10_12_H_
  #define _TYPE_VERSION_2014_10_12_H_
  
#include <Bsw/Common/Std_Types.h>
  typedef struct struct_Std_VersionInfoType
  {
    uint16 vendorId;
    uint16 moduleId;
    uint8  instanceId;
    uint8  sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;
  }
  Std_VersionInfoType;

#endif // _TYPE_VERSION_2014_10_12_H_
