/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _REGULATION_PIR_HPP_
  #define _REGULATION_PIR_HPP_

  #include <limits>

  namespace util
  {
    template<typename my_small_type,
             typename my_large_type,
             const unsigned param_p0,
             const unsigned param_p1,
             const my_large_type range_lo,
             const my_large_type range_hi,
             const unsigned scale_factor = 8>
    class regulation_pir_order1
    {
    public:
      typedef my_small_type small_type;
      typedef my_large_type large_type;

      static const large_type my_range_lo = range_lo * scale_factor;
      static const large_type my_range_hi = range_hi * scale_factor;

      regulation_pir_order1(const large_type init) : result(init * scale_factor),
                                                     signal(init * scale_factor) { }

      large_type func(large_type input, large_type target)
      {
        input  *= scale_factor;
        target *= scale_factor;

        const bool delta_is_positive = (target > input);

        const large_type delta_large = (delta_is_positive ? large_type(target - input) : large_type(input - target));

        const small_type delta = ((delta_large > large_type((std::numeric_limits<small_type>::max)()))
                                   ? (std::numeric_limits<small_type>::max)()
                                   : small_type(delta_large));

        if(delta != small_type(0U))
        {
          if(delta_is_positive)
          {
            result = static_cast<large_type>(signal + static_cast<large_type>(param_p0 * static_cast<large_type>(delta)));

            if(result > my_range_hi)
            {
              result = static_cast<large_type>(my_range_hi);
              signal = static_cast<large_type>(my_range_hi);
            }
            else
            {
              signal = static_cast<large_type>(result - static_cast<large_type>(param_p1 * static_cast<large_type>(delta)));
            }
          }
          else
          {
            result = static_cast<large_type>(signal - static_cast<large_type>(param_p0 * static_cast<large_type>(delta)));

            if((result > signal) || (result < static_cast<large_type>(my_range_lo)))
            {
              result = static_cast<large_type>(my_range_lo);
              signal = static_cast<large_type>(my_range_lo);
            }
            else
            {
              signal = static_cast<large_type>(result + static_cast<large_type>(param_p1 * static_cast<large_type>(delta)));
            }
          }
        }
        else
        {
          result = signal;
        }

        return get_result();
      }

      large_type get_result() const { return (result + (scale_factor  - 1)) / scale_factor; }

    private:
      large_type result;
      large_type signal;
    };
  }

#endif // _REGULATION_PIR_HPP_
