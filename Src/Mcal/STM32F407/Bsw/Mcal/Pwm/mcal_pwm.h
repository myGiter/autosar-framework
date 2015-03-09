///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2013.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef _MCAL_PWM_2010_09_14_H_
  #define _MCAL_PWM_2010_09_14_H_

  #include <cstdint>
  #include <Bsw/Mcal/Dio/Dio.h>
  #include <Bsw/Mcal/Port/Port.h>
  #include <Bsw/Util/Memory/Dma/DirectMemoryAccess.h>
  #include <Bsw/Util/NonCopyable/NonCopyable.h>

  namespace mcal
  {
    namespace pwm
    {
      // A software PWM class for a pin at the port address given
      // by address and on the bit-position given by bit_position.

      class pwm_type : private util::noncopyable
      {
      public:
        typedef std::uint_fast32_t period_type;

        pwm_type(const Dio_ChannelType channel,
                 const Port_PinType    port,
                 const period_type     per  = 0x80U,
                 const period_type     duty = 0U);

        void set_duty(const period_type& duty);

        period_type get_duty() const;

        void service();

        period_type get_period() const;

      private:
        const Dio_ChannelType dio_channel;
        const Port_PinType    port_id;
        period_type           counter;
        period_type           period;
        period_type           duty_cycle;
        period_type           shadow;
        period_type           prescaler_value;
        period_type           prescaler_counter;
      };
    }
  }

#endif // _MCAL_PWM_2010_09_14_H_
