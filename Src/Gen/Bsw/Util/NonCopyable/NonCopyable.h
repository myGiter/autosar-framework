/////////////////////////////////////////////////////// 
//  Copyright 2013-2014 Stephan Hage.
//  Copyright 2007-2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _NONCOPYABLE_2014_10_13_H_
  #define _NONCOPYABLE_2014_10_13_H_

  // Taken (with slight modification) from boost::noncopyable.

  namespace util
  {
    namespace my_noncopyable_namespace
    {
      class noncopyable
      {
      protected:

      #if defined(__GNUC__)
        constexpr noncopyable() = default;
        ~noncopyable() = default;
      #else
        noncopyable() {}
        ~noncopyable() {}
      #endif

      private:

      #if defined(__GNUC__)
        // Emphasize: The following members are private.
        noncopyable(const noncopyable&) = delete;
        noncopyable& operator=(const noncopyable&) = delete;
      #else
        // Emphasize: The following members are private.
        noncopyable(const noncopyable&);
        noncopyable& operator=(const noncopyable&);
      #endif
      };
    }

    typedef my_noncopyable_namespace::noncopyable noncopyable;
  }

#endif // _NONCOPYABLE_2014_10_13_H_
