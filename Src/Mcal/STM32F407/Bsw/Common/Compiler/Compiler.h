/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _COMPILER_2014_12_09_H_
  #define _COMPILER_2014_12_09_H_

  #include "Compiler_Cfg.h"

  #define COMPILER_AR_MAJOR_VERSION       (0u)
  #define COMPILER_AR_MINOR_VERSION       (0u)
  #define COMPILER_AR_PATCH_VERSION       (0u)

  // Component Version Information 
  #define COMPILER_SW_MAJOR_VERSION       (0u)
  #define COMPILER_SW_MINOR_VERSION       (1u)
  #define COMPILER_SW_PATCH_VERSION       (0u) 

  // AUTOMATIC used for the declaration of local pointers 
  #define AUTOMATIC

  // TYPEDEF shall be used within type definitions, where no memory qualifier can be specified.
  #define TYPEDEF

  //_STATIC_ define for abstraction of compiler keyword static
  #define STATIC     static

  //NULL_PTR define with a void pointer to zero definition
  #ifndef NULL_PTR
    #define NULL_PTR  ((void *)0)
  #endif

  //_INLINE_ define for abstraction of the keyword inline

  #ifndef NULL_PTR
    #define INLINE static inline
  #endif
  // FUNC macro for the declaration and definition of functions, that ensures correct syntax of function declarations
  //  rettype     return type of the function
  //  memclass    classification of the function itself

  #define FUNC(rettype, memclass) rettype

  // P2VAR macro for the declaration and definition of pointers in RAM, pointing to variables
  //  ptrtype     type of the referenced variable memclass
  //  memclass    classification of the pointer’s variable itself
  //  ptrclass    defines the classification of the pointer’s distance

  #define P2VAR(ptrtype, memclass, ptrclass) ptrtype*

  // P2CONST macro for the declaration and definition of pointers in RAM pointing to constants
  //  ptrtype     type of the referenced data
  //  memclass    classification of the pointer's variable itself
  //  ptrclass    defines the classification of the pointer's distance

  #define P2CONST(ptrtype, memclass, ptrclass) const ptrtype*

  // CONSTP2VAR macro for the declaration and definition of constant pointers accessing variables
  //  ptrtype     type of the referenced data
  //  memclass    classification of the pointer's variable itself
  //  ptrclass    defines the classification of the pointer's distance

  #define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype *const

  // CONSTP2CONST macro for the declaration and definition of constant pointers accessing constants
  //  ptrtype     type of the referenced data
  //  memclass    classification of the pointer's variable itself
  //  ptrclass    defines the classification of the pointer's distance

  #define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype *const

  // P2FUNC macro for the type definition of pointers to functions
  //  rettype     return type of the function
  //  ptrclass    defines the classification of the pointer's distance
  //  fctname     function name respectivly name of the defined type

  #define P2FUNC(rettype, ptrclass, fctname) rettype (* fctname)

  // CONST macro for the declaration and definition of constants
  //  type        type of the constant
  //  memclass    classification of the constant itself

  #if defined(CONST)
    #undef CONST
  #endif

  #define CONST(type, memclass) const type

  // VAR macro for the declaration and definition of variables
  //  vartype        type of the variable
  //  memclass    classification of the variable itself

  #define VAR(vartype, memclass) vartype


#endif // _COMPILER_2014_12_09_H_
