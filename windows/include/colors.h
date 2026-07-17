#include <string_view>

namespace Colors {
    constexpr std::string_view red       = "\x1B[31m";
    constexpr std::string_view green     = "\x1B[32m";
    constexpr std::string_view yellow    = "\x1B[33m";
    constexpr std::string_view blue      = "\x1B[34m";
    constexpr std::string_view magenta   = "\x1B[35m";
    constexpr std::string_view cyan      = "\x1B[36m";
    constexpr std::string_view gray      = "\x1B[37m";
    constexpr std::string_view brown     = "\x1B[33m"; // нет 130, берём близкий

    constexpr std::string_view lred      = "\x1B[91m";
    constexpr std::string_view lgreen    = "\x1B[92m";
    constexpr std::string_view lyellow   = "\x1B[93m";
    constexpr std::string_view lblue     = "\x1B[94m";
    constexpr std::string_view lmagenta  = "\x1B[95m";
    constexpr std::string_view lcyan     = "\x1B[96m";
    constexpr std::string_view lwhite    = "\x1B[97m";
    constexpr std::string_view lbrown    = "\x1B[93m"; // нет 130, берём близкий

    constexpr std::string_view bold      = "\x1B[1m";
    constexpr std::string_view underline = "\x1B[4m";

    constexpr std::string_view reset     = "\x1B[0m";
}

