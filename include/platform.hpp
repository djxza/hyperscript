#pragma once

#include <stdint.h>

#define PLATFORM_UNKNOWN 0
#define PLATFORM_WINDOWS 1
#define PLATFORM_MACOSX  2
#define PLATFORM_LINUXOS 3
#define PLATFORM_FREEBSD 4
#define PLATFORM_UNIX    5

#if defined(WIN32)   || \
	defined(_WIN32)  || \
	defined(__WIN32) || \
	defined(WIN64)   || \
	defined(_WIN64)  || \
	defined(__WIN64)
# define PLATFORM PLATFORM_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__)
# define PLATFORM PLATFORM_MACOSX
#elif defined(__linux__)
# define PLATFORM PLATFORM_LINUXOS
#elif defined(__FreeBSD__)
# define PLATFORM PLATFORM_FREEBSD
#elif defined(__unix__) || defined(__unix)
# define PLATFORM PLATFORM_UNIX
#else
# define PLATFORM PLATFORM_UNKNOWN
#endif

#if defined(__SIZEOF_INT128__)
# define ARCH 128
#elif defined(__x86_64__) || defined(_M_X64) || defined(aarch64) || defined(__aarch64)
# define ARCH 64
#elif defined(__i386__) || defined(_M_IX86)
# define ARCH 32
#elif defined(__i8086__) || defined(_M_I86)
# define ARCH 16
#else
# define ARCH 8
#endif

#if ARCH >= 8
using i8 = int8_t;
using u8 = uint8_t;
#endif // ARCH

#if ARCH >= 16
using i16 = int16_t;
using u16 = uint16_t;
#endif // ARCH

#if ARCH >= 32
using i32 = int32_t;
using u32 = uint32_t;
using f32 = float;

# if !defined(__FSIZE__)
#  define __FSIZE__ f32
# endif // __FSIZE__

#endif // ARCH

#if ARCH >= 64
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;

# if !defined(__FSIZE__)
#  undef  __FSIZE__
#  define __FSIZE__ f64
# endif // __FSIZE__

#endif // ARCH

#if ARCH >= 128
/*
using i128 = __int128;
using u128 = __uint128_t;
*/
#endif

using usize = std::size_t;    // the biggest possible unsigned integer
using isize = std::ptrdiff_t; // Signed counterpart of size_t
using fsize = __FSIZE__;      // floating point counterpart of size_t