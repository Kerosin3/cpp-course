#include "lib1.hpp"
#include <exampleLib/example_lib.hpp>
#include <iostream>
#include <list>
#include <type_traits>

#ifdef _VERSIONING
#include "version.h"
#endif

#ifndef __cplusplus
#error C++ is required
#elif __cplusplus < 202002L
#error C++20 is required
#endif

using namespace std;
namespace sorting
{

template <typename T> typename std::enable_if_t<std::is_integral_v<T>, void> print_ip(T number)
{
    unsigned short mask = 0xFF;
    for (auto index = sizeof(T) - 1; index > 0; index--)
    {
        auto shifted = number >> index * 8;
        cout << (shifted & mask) << '.';
    }

    cout << (number & mask) << endl;
}
template <typename T> typename std::enable_if_t<std::is_same_v<T, std::string>, void> print_ip(T number)
{
    cout << number << endl;
}
// if not string -> list

template <typename T>
decltype(begin(declval<T>()), end(declval<T>()), enable_if_t<!is_same_v<string, T>, void>()) print_ip(
    const T& cont_list)
{
    string separator{};
    for (const auto part : cont_list)
    {
        cout << separator << part;
        separator = ".";
    }

    cout << endl;
}

} // namespace sorting
/*
template <typename U> void print_ip(U generic_ip)
{
    sorting::print_ip(generic_ip);
}
*/
int main(int argc, char* argv[])
{
    sorting::print_ip(int8_t{-1});
    sorting::print_ip(int16_t{-1});
    sorting::print_ip(long{8875824491850138409});
    sorting::print_ip("dasdasdada"s);
    std::list<short> v1{1, 23, 4, 543};
    sorting::print_ip("dasdasdada"s);
    sorting::print_ip(v1);
    return EXIT_SUCCESS;
}
