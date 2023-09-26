#include "lib1.hpp"
#include <algorithm>
#include <array>
#include <bitset>
#include <boost/range/irange.hpp>
#include <cassert>
#include <csignal>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exampleLib/example_lib.hpp>
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <istream>
#include <iterator>
#include <memory>
#include <new>
#include <optional>
#include <spdlog/spdlog.h>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

#ifdef _VERSIONING
#include "version.h"
#endif

#ifndef __cplusplus
#error C++ is required
#elif __cplusplus < 202002L
#error C++20 is required
#endif

using namespace std;

void read(std::istream& fp)
{
    while (!fp.eof())
    {
        std::string line;
        std::getline(fp, line);
        std::cout << line << std::endl;
        ;
    }
}

int main(int argc, char* argv[])
{
    // read(std::cin);
    return EXIT_SUCCESS;
}
