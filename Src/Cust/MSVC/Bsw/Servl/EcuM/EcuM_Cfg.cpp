/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <Bsw/Servl/EcuM/EcuM_Cfg.h>

//-----------------------------------------------------------------------------
/// \brief  BSW modules, which need OS support ans NvRam access
///
/// \descr  EcuM_AL_DriverInitThree is provided, where initialization of those
///         basic software modules should take place, which need OS support and
///         need NvRam data to be completely restored
/// \param  - 
///
/// \return void 
//-----------------------------------------------------------------------------
EXTERN_C
void EcuM_AL_DriverInitThree(void)
{

}

EXTERN_C
void EcuM_StartupHook_App(void)
{

}

EXTERN_C
void EcuM_ShutdownHook_App(void)
{

}
