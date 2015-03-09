/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _PIN_POSITION_2014_10_13_H_
  #define _PIN_POSITION_2014_10_13_H_

  #include <limits>

  namespace util
  {
    template<typename unsigned_integral_type,
                const unsigned_integral_type unsigned_integral_width = std::numeric_limits<unsigned_integral_type>::digits>
    struct division_and_modulus
    {
      static_assert(std::numeric_limits<unsigned_integral_type>::is_signed == false,
                    "The integral type must be unsigned.");

      static unsigned_integral_type result_div(const unsigned_integral_type value_to_div)
      {
        return value_to_div / unsigned_integral_width;
      }

      static unsigned_integral_type result_mod(const unsigned_integral_type value_to_mod)
      {
        return value_to_mod % unsigned_integral_width;
      }
    };
  }

#endif // _PIN_POSITION_2014_10_13_H_
