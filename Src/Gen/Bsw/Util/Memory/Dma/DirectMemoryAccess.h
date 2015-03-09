/////////////////////////////////////////////////////// 
//  Copyright 2014 Stephan Hage.
//  Copyright 2014 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef _DIRECT_MEMORY_ACCESS_TEMPLATE_2014_10_09_H_
  #define _DIRECT_MEMORY_ACCESS_TEMPLATE_2014_10_09_H_

  namespace util
  {
    template<typename register_address_type,
             typename register_value_type>
    struct dma
    {
      static void     reg_set(register_address_type address, const register_value_type value) { *reinterpret_cast<volatile register_value_type*>(address)  = value; }
      static void     reg_and(register_address_type address, const register_value_type value) { *reinterpret_cast<volatile register_value_type*>(address) &= value; }
      static void     reg_or (register_address_type address, const register_value_type value) { *reinterpret_cast<volatile register_value_type*>(address) |= value; }
      static register_value_type reg_get(register_address_type address) { return *reinterpret_cast<volatile register_value_type*>(address); }
      static void reg_msk(const register_address_type address, const register_value_type value, const register_value_type mask_value)
      {
        *reinterpret_cast<volatile register_value_type*>(address) = register_value_type(register_value_type(reg_get(address) & register_value_type(~mask_value)) | register_value_type(value & mask_value));
      }

      static void     bit_set(register_address_type address, const register_value_type value) { *reinterpret_cast<volatile register_value_type*>(address) |= static_cast<register_value_type>(1uL << value); }
      static void     bit_clr(register_address_type address, const register_value_type value) { *reinterpret_cast<volatile register_value_type*>(address) &= static_cast<register_value_type>(~static_cast<register_value_type>(1uL << value)); }
      static void     bit_not(register_address_type address, const register_value_type value) { *reinterpret_cast<volatile register_value_type*>(address) ^= static_cast<register_value_type>(1uL << value); }
      static bool     bit_get(register_address_type address, const register_value_type value) { return (static_cast<register_value_type>(reg_get(address) & static_cast<register_value_type>(1uL << value)) != static_cast<register_value_type>(0u)); }
    };
  }

  // *****************************************************************************
  // macros
  // *****************************************************************************
  #define UTIL_COUNTOF(x) (sizeof(x) / sizeof((x)[0U]))
  #define countof(x)      UTIL_COUNTOF(x)

  #define UTIL_MAX_OF_TYPE(T) ((T) (((uint32_t) 0xFFFFFFFFUL) >> (32U - (8U * sizeof(T)))))

  #define UTIL_LOBYTE(w) ((uint8_t) (w))
  #define UTIL_HIBYTE(w) ((uint8_t) ((uint16_t)(w) >> 8U))

  #define LOBYTE(w)       UTIL_LOBYTE(w)
  #define HIBYTE(w)       UTIL_HIBYTE(w)

  #define UTIL_LOWORD(d) ((uint16_t) (d))
  #define UTIL_HIWORD(d) ((uint16_t) ((uint32_t) (d) >> 16U))

  #define UTIL_BYTE_MASK_BITS(bpos, count)   ((uint8_t)  (((uint8_t)  (0xFFU        >> ( 8U - (count)))) << (bpos)))
  #define UTIL_WORD_MASK_BITS(bpos, count)   ((uint16_t) (((uint16_t) (0xFFFFU      >> (16U - (count)))) << (bpos)))
  #define UTIL_DWORD_MASK_BITS(bpos, count)  ((uint32_t) (((uint32_t) (0xFFFFFFFFUL >> (32U - (count)))) << (bpos)))

  #define UTIL_BYTE_MASK_BIT(n)  (1UL << (n))
  #define UTIL_WORD_MASK_BIT(n)  (1UL << (n))
  #define UTIL_DWORD_MASK_BIT(n) (1UL << (n))

  #define UTIL_BYTE_CLEAR_BITS(value, bpos, count)  value &= (uint8_t)  ~UTIL_BYTE_MASK_BITS(bpos, count)
  #define UTIL_WORD_CLEAR_BITS(value, bpos, count)  value &= (uint16_t) ~UTIL_WORD_MASK_BITS(bpos, count)
  #define UTIL_DWORD_CLEAR_BITS(value, bpos, count) value &= (uint32_t) ~UTIL_DWORD_MASK_BITS(bpos, count)

  #define UTIL_BYTE_SET_BITS(value, bpos, count)  value |= (uint8_t)  UTIL_BYTE_MASK_BITS(bpos, count)
  #define UTIL_WORD_SET_BITS(value, bpos, count)  value |= (uint16_t) UTIL_WORD_MASK_BITS(bpos, count)
  #define UTIL_DWORD_SET_BITS(value, bpos, count) value |= (uint32_t) UTIL_DWORD_MASK_BITS(bpos, count)

  #define UTIL_MAKEWORD(lo,hi) ((uint16_t)(((uint8_t)(lo)) | (((uint16_t)((uint8_t)(hi))) << 8U)))
  #define MAKEWORD(lo,hi)       UTIL_MAKEWORD(lo,hi)
  #define UTIL_MAKELONG(lo,hi) ((uint32)(((uint16)(lo)) | (((uint32)((uint32)(hi)))<< 16u)))
  
  #define UTIL_SWAPWORD(w) (UTIL_MAKEWORD(UTIL_HIBYTE(w),UTIL_LOBYTE(w)))
  #define UTIL_SWAPLONG(l) (UTIL_MAKELONG(UTIL_SWAPWORD(UTIL_HIWORD(l)),UTIL_SWAPWORD(UTIL_LOWORD(l))))

  #define UTIL_MIN(a, b) ((a) < (b) ? (a) : (b))
  #define UTIL_MAX(a, b) ((a) > (b) ? (a) : (b))

  #define UTIL_MODIFY_BITS  (reg, mask, val) (((reg) & ~(mask)) | ((val) & (mask)))
  #define UTIL_CLEAR_BITS   (reg, mask)      ((reg) & ~(mask))
  #define UTIL_SET_BITS     (reg, mask)      ((reg) | (mask))
  #define UTIL_BYTE_TEST_BIT(reg, bpos)      ((bool) ((((uint8) (reg)) & UTIL_BYTE_MASK_BIT(bpos)) != (uint8) 0U))

  #define UTIL_DWORD_TEST_BIT(reg, bpos)      ((bool) ((((uint32) (reg)) & UTIL_BYTE_MASK_BIT(bpos)) != (uint32) 0U))

  #define UTIL_MEMCOPY(Dest, Source, Length)  \
  {                                           \
    uint8_t* pucDest = (Dest);                \
    const uint8_t* pucSource = (Source);      \
    uint8_t ucLength = (Length);              \
                                              \
    while(ucLength > (uint8_t) 0U)            \
    {                                         \
      *pucDest++ = *pucSource++;              \
      ucLength--;                             \
    }                                         \
  }

#endif // _DIRECT_MEMORY_ACCESS_TEMPLATE_2014_10_09_H_
