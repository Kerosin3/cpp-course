#include "lib1.hpp"
#include <algorithm>
#include <array>
#include <boost/range/irange.hpp>
#include <cassert>
#include <csignal>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exampleZ/example_lib.hpp>
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <new>
#include <optional>
#include <spdlog/spdlog.h>
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
int main(int /*unused*/, char** /*unused*/)
{
    // printf("verion is %d\n", APP_MAJOR_VERSION);
    // printf("verion is %d\n", APP_MINOR_VERSION);
    // printf("verion is %d\n", APP_PATCH_VERSION);
    cout << "####################################" << endl;
    cout << "build " << get_build_n() << endl;
    cout << "Hello, World!" << endl;
    return EXIT_SUCCESS;
}
