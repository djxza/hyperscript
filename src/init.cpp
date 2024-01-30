#define ASSERT(condition, msg) private_assert(condition, msg)

#include "init.hpp"

#define COMP_SUCCESS "compilation successful"
#define COMP_ERROR   "compilation failed because of a comptime error"
#define COMP_LOGICAL "compilation failed because of a logical error"

#define _Abort(__exit)  ret_buf = GLUE(COMP_, __exit); \
                        std::exit(EXIT_FAILURE)

std::string ret_buf = COMP_SUCCESS;

static void private_assert(
    const bool condition,
    const std::string& msg
) {
    if(!condition) {
        fmt_to_error(msg);
        _Abort(ERROR);
    }
}

constexpr static void _show_retbuf() {
    std::cerr << ret_buf << std::endl;
}

constexpr void init_ret_buf() {
    ASSERT(std::atexit(_show_retbuf) == 0, "failed to initialize return buffer");
}

void _main(
    const u32 ac,
    const std::vector<std::string>& args
) {
    init_ret_buf();
    ASSERT(ac != 1, "no input files");
}