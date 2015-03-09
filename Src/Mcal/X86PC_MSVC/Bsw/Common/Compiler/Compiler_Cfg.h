/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef COMPILER_CFG_H
 #define COMPILER_CFG_H

  #define PWM_PUBLIC_CODE                /* API functions                         */
  #define PWM_PUBLIC_CONST               /* API constants                         */
  #define PWM_PRIVATE_CODE               /* Internal functions                    */
  #define PWM_PRIVATE_DATA               /* Module internal data                  */
  #define PWM_PRIVATE_CONST              /* Internal ROM Data                     */
  #define PWM_APPL_CODE                  /* callbacks of the Application          */
  #define PWM_APPL_CONST                 /* Applications ROM Data                 */
  #define PWM_APPL_DATA                  /* Applications RAM Data                 */
  #define PWM_FAST_DATA                  /* Near RAM Data                         */
  #define PWM_CONFIG_CONST               /* Desc. Tables -> Config-dependent      */
  #define PWM_CONFIG_DATA                /* Config. dependent (reg. size) data    */
  #define PWM_INIT_DATA                  /* Data which is initialized during      */
  #define PWM_NOINIT_DATA                /* Data which is not initialized during  */
  #define PWM_CONST                      /* Data Constants                        */

#endif // COMPILER_CFG_H
