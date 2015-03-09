/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _TYPE_2014_10_10_H_
  #define _TYPE_2014_10_10_H_

  #if defined(__cplusplus)
    #include <cstdint>

  // *****************************************************************************
  // types
  // *****************************************************************************

  // Standard AUTOSAR built-in types.

  // Note that fixed-width types such as uint8_t, uint16_t, etc.
  // are already defined in <stdint.h>.

    typedef std::uint8_t         uint8;
    typedef std::uint16_t        uint16;
    typedef std::uint32_t        uint32;
    typedef std::uint64_t        uint64;
    typedef std::int8_t          sint8;
    typedef std::int16_t         sint16;
    typedef std::int32_t         sint32;
    typedef std::int64_t         sint64;

    typedef std::uint_least8_t   uint8_least;
    typedef std::uint_least16_t  uint16_least;
    typedef std::uint_least32_t  uint32_least;
    typedef std::uint_least64_t  uint64_least;

    typedef std::int_least8_t    sint8_least;
    typedef std::int_least16_t   sint16_least;
    typedef std::int_least32_t   sint32_least;
    typedef std::int_least64_t   sint64_least;

    typedef std::uint_fast8_t    uint8_fast;
    typedef std::uint_fast16_t   uint16_fast;
    typedef std::uint_fast32_t   uint32_fast;
    typedef std::uint_fast64_t   uint64_fast;

    typedef std::int_fast8_t    sint8_fast;
    typedef std::int_fast16_t   sint16_fast;
    typedef std::int_fast32_t   sint32_fast;
    typedef std::int_fast64_t   sint64_fast;

  #else

    #include <stdint.h>
  // *****************************************************************************
  // types
  // *****************************************************************************

  // Standard AUTOSAR built-in types.

  // Note that fixed-width types such as uint8_t, uint16_t, etc.
  // are already defined in <stdint.h>.

    typedef uint8_t         uint8;
    typedef uint16_t        uint16;
    typedef uint32_t        uint32;
    typedef uint64_t        uint64;
    typedef  int8_t         sint8;
    typedef  int16_t        sint16;
    typedef  int32_t        sint32;
    typedef  int64_t        sint64;

    typedef uint_least8_t   uint8_least;
    typedef uint_least16_t  uint16_least;
    typedef uint_least32_t  uint32_least;
    typedef uint_least64_t  uint64_least;

    typedef  int_least8_t   sint8_least;
    typedef  int_least16_t  sint16_least;
    typedef  int_least32_t  sint32_least;
    typedef  int_least64_t  sint64_least;

    typedef uint_fast8_t   uint8_fast;
    typedef uint_fast16_t  uint16_fast;
    typedef uint_fast32_t  uint32_fast;
    typedef uint_fast64_t  uint64_fast;

    typedef  int_fast8_t   sint8_fast;
    typedef  int_fast16_t  sint16_fast;
    typedef  int_fast32_t  sint32_fast;
    typedef  int_fast64_t  sint64_fast;

  #endif

#endif // _TYPE_2014_10_10_H_
