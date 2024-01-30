#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "platform.hpp"

#define RESET_COLOR "\033[0m"

// Regular colors
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Bold colors
#define BOLD_BLACK "\033[1;30m"
#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN "\033[1;36m"
#define BOLD_WHITE "\033[1;37m"

// Underline colors
#define UNDERLINE_BLACK "\033[4;30m"
#define UNDERLINE_RED "\033[4;31m"
#define UNDERLINE_GREEN "\033[4;32m"
#define UNDERLINE_YELLOW "\033[4;33m"
#define UNDERLINE_BLUE "\033[4;34m"
#define UNDERLINE_MAGENTA "\033[4;35m"
#define UNDERLINE_CYAN "\033[4;36m"
#define UNDERLINE_WHITE "\033[4;37m"

// Background colors
#define BACKGROUND_BLACK "\033[40m"
#define BACKGROUND_RED "\033[41m"
#define BACKGROUND_GREEN "\033[42m"
#define BACKGROUND_YELLOW "\033[43m"
#define BACKGROUND_BLUE "\033[44m"
#define BACKGROUND_MAGENTA "\033[45m"
#define BACKGROUND_CYAN "\033[46m"
#define BACKGROUND_WHITE "\033[47m"

#define GLUE(a, b) a ## b
#define OUT_NAME "hsc.exe"
#define OUT_NAME_LPCWSTR  GLUE(L, OUT_NAME)

constexpr void init_ret_buf();

constexpr void fmt_to_x(
    const char* const clr,
    const std::string& x,
    const std::string& str
);

constexpr void fmt_to_error(
    const std::string& str
);

template<typename T>
constexpr void _print(
    const T& __x
);

template<typename ... A>
constexpr void print(
    const A& ... local_argv
);

void basic_assert(
    const bool condition,
    const std::string& msg
);

constexpr void init(void);

#if defined(IN_USE_VC) && !defined(NO_POPUP)
# if !defined(_WIN32) && !defined(_WIN64)
#  define ASSERT(condition, msg) basic_assert(condition, msg)
# endif // !_WIN32 && !_WIN64

#include <Windows.h>

void visual_assert(
    const bool condition,
    const std::string& msg
);

# define ASSERT(condition, msg) visual_assert(condition, msg)

#else
# if !defined(ASSERT)
#  define ASSERT(condition, msg) basic_assert(condition, msg)
# endif // !ASSERT
#endif // IN_USE_VC

void exec(
    const std::string& cmd
);