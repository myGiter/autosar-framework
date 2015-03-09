/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _NULL_PTR_WORKAROUND_2014_10_13_H_
  #define _NULL_PTR_WORKAROUND_2014_10_13_H_

  // Provide a nullptr workaround for C++ compilers not yet supporting it.

  namespace std
  {
    class nullptr_t
    {
    public:
      template<typename T>
      operator T*() const { return static_cast<T*>(0U); }

      template<typename C, typename T>
      operator T C::*() const { return static_cast<T C::*>(0U); }

    private:
      void operator&() const;
    };

    template<typename T> inline bool operator==(const T* p, const nullptr_t&) { return (static_cast<const T*>(0U) == p); }
    template<typename T> inline bool operator!=(const T* p, const nullptr_t&) { return (static_cast<const T*>(0U) != p); }

    template<typename T> inline bool operator==(T* p, const nullptr_t&) { return (static_cast<T*>(0U) == p); }
    template<typename T> inline bool operator!=(T* p, const nullptr_t&) { return (static_cast<T*>(0U) != p); }

    template<typename T> inline bool operator==(const nullptr_t&, const T* p) { return (static_cast<const T*>(0U) == p); }
    template<typename T> inline bool operator!=(const nullptr_t&, const T* p) { return (static_cast<const T*>(0U) != p); }

    template<typename T> inline bool operator==(const nullptr_t&, T* p) { return (static_cast<T*>(0U) == p); }
    template<typename T> inline bool operator!=(const nullptr_t&, T* p) { return (static_cast<T*>(0U) != p); }
  }

  const std::nullptr_t nullptr = { };

#endif // _NULL_PTR_WORKAROUND_2014_10_13_H_
