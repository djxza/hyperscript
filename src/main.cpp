#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(const int ac, const char* argv[]) {
    _main(static_cast<u32>(ac), std::vector<std::string>(argv, argv + ac));
}
