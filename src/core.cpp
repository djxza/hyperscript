#include "core.hpp"

constexpr void fmt_to_x(
    const char* const clr,
    const std::string& x,
    const std::string& str
) {
    std::cout       <<
        OUT_NAME    <<
        ": "        <<
        clr         <<
        x           <<
        ": "        <<
        RESET_COLOR <<
        str         <<
        std::endl;
}

constexpr void fmt_to_error(
    const std::string& str
) {
    fmt_to_x(
        RED,
        "error",
        str
    );
}


template <typename T>
constexpr void _print(
    const T& __x
) {
    std::cout << __x << std::endl;
}

template<typename ... A>
constexpr void print(
    const A& ... local_argv
) {
    _print(local_argv...);
}

void basic_assert(
    const bool condition,
    const std::string& msg
) {
    if(!condition) {
        fmt_to_error(msg);
        std::exit(EXIT_FAILURE);
    }
}

#if defined(IN_USE_VC) && !defined(NO_POPUP)
# if defined(_WIN32) || defined(_WIN64)

void visual_assert(
    const bool condition,
    const std::string& msg
) {
    if(!condition) {
        const auto __usr = MessageBox(nullptr, msg, OUT_NAME_LPCWSTR, MB_OK);
        if(__usr == IDOK) {
            std::exit(EXIT_FAILURE);
        }
    }
}

#endif
# endif // IN_USE_VC  && !NO_POPUP

void exec(
    const std::string &cmd
){
    ASSERT(
        std::system(cmd.c_str()),
        "Failed to execute command " + cmd
    );
}