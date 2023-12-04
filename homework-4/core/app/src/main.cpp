#include "exampleLib/example_lib.hpp"
#include <iostream>
#include <list>
#include <type_traits>
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
// namespace sorting
int main(int argc, char* argv[])
{
    sorting::print_ip(int8_t{-1});                           // 255
    sorting::print_ip(int16_t{0});                           // 0.0
    sorting::print_ip(int32_t{2130706433});                  // 127.0.0.1
    sorting::print_ip(int64_t{8875824491850138409});         // 123.45.67.89.101.112.131.41
    sorting::print_ip(std::string{"Hello, World !"});        // Hello, World!
    sorting::print_ip(std::vector<int>{100, 200, 300, 400}); // 100.200.300.400
    sorting::print_ip(std::list<short>{400, 300, 200, 100}); // 400.300.200.100
    return EXIT_SUCCESS;
}
