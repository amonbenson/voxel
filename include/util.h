#pragma once


#ifdef _MSC_VER
    # include <intrin.h>
    # include <nmmintrin.h>
#endif


#if defined(__GNUC__)
    #define __util_popcount __builtin_popcount
    #define __util_popcountl __builtin_popcountl
    #define __util_popcountll __builtin_popcountll

    #define __util_clz __builtin_clz
    #define __util_clzl __builtin_clzl
    #define __util_clzll __builtin_clzll
#elif defined(_MSC_VER)
    #define __util_popcount _mm_popcnt_u32
    #define __util_popcountl _mm_popcnt_u64
    #define __util_popcountll _mm_popcnt_u64

    #define __util_clz __lzcnt
    #define __util_clzl __lzcnt64
    #define __util_clzll __lzcnt64
#else
    #error Unsupported compiler
#endif


#define util_popcount(x) (_Generic((x), \
    unsigned int: __util_popcount, \
    unsigned long: __util_popcountl, \
    unsigned long long: __util_popcountll)(x))

#define util_clz(x) (_Generic((x), \
    unsigned int: __util_clz, \
    unsigned long: __util_clzl, \
    unsigned long long: __util_clzll)(x))


#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define is_pwrtwo(n) (!((n) & ((n) - 1)) && (n) != 0)

#define next_pwrtwo(x) ((x) == 1 ? 1 : (__typeof__(x)) 1 << (sizeof(x) * 8 - util_clz((x) - 1)))
