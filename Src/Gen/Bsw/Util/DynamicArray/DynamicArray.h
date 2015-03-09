/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _DYNAMIC_ARRAY_2014_10_13_H_
  #define _DYNAMIC_ARRAY_2014_10_13_H_

  #include <cstddef>
  #include <iterator>
  #include <algorithm>

  namespace util
  {
    template<typename T, const std::size_t MAX = 32u>
    class dynamic_array
    {
    public:
      typedef std::size_t                           size_type;
      typedef std::ptrdiff_t                        difference_type;
      typedef T                                     value_type;
      typedef T*                                    pointer;
      typedef const T*                              const_pointer;
      typedef T&                                    reference;
      typedef const T&                              const_reference;
      typedef pointer                               iterator;
      typedef const_pointer                         const_iterator;
      typedef std::reverse_iterator<iterator>       reverse_iterator;
      typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

      dynamic_array() : len(0u) { }

      dynamic_array(size_type s,
                    const T& t = T()) : len((std::min)(size_type(MAX), s))
      {
        for(size_type i = 0u; i < len; i++)
        {
          elems[i] = t;
        }
      }

      template<typename InputIterator>
      dynamic_array(InputIterator first, InputIterator last) : len((std::min)(size_type(MAX), size_type(last - first)))
      {
        for(size_type i = 0u; i < len; ++i)
        {
          elems[i] = *(first + i);
        }
      }

      size_type size(void) const { return len; }

      reference       operator[](const size_type i)       { return elems[i]; }
      const_reference operator[](const size_type i) const { return elems[i]; }

      iterator begin(void) { return elems; }
      iterator end  (void) { return elems + len; }

      const_iterator begin(void) const { return elems; }
      const_iterator end  (void) const { return elems + len; }

      void push_back(const T& t)
      {
        if(len < MAX)
        {
          elems[len] = t;
          ++len;
        }
      }

    private:
      size_type len;
      T elems[MAX];
    };
  }

#endif // _DYNAMIC_ARRAY_2014_10_13_H_
