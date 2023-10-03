#include "lib1.hpp"
#include <exampleLib/example_lib.hpp>
#include <iostream>
#include <list>

#ifdef _VERSIONING
#include "version.h"
#endif

#ifndef __cplusplus
#error C++ is required
#elif __cplusplus < 202002L
#error C++20 is required
#endif

using namespace std;
/*
namespace xxx
{
template <typename T> struct type_is
{
    using type = T;
};
// base
template <bool cond, typename T> struct enable_if : type_is<T>
{
};

template <typename T> struct enable_if<false, T>;
} // namespace xxx

// invalid for vector
namespace xxx
{
template <typename T> auto generic_sort(T& container, int) -> decltype(container.sort())
{
    container.sort();
}
template <typename T> void generic_sort(T& container, long)
{
    std::sort(container.begin(), container.end());
}
} // namespace xxx
template <typename T> auto generic_sort(T& container)
{
    xxx::generic_sort(container, 42);
}
*/
namespace sorting
{

template <typename T> typename std::enable_if_t<std::is_same_v<T, int8_t>, void> print_ip(T generic_ip)
{
    cout << "uint8" << endl;
}

template <typename T> typename std::enable_if_t<std::is_same_v<T, int16_t>, void> print_ip(T generic_ip)
{
    cout << "uint16" << endl;
}
template <typename T> typename std::enable_if_t<std::is_same_v<T, int32_t>, void> print_ip(T generic_ip)
{
    cout << "uint32" << endl;
}
template <typename T> typename std::enable_if_t<std::is_same_v<T, std::vector<int>>, void> print_ip(T generic_ip)
{
    cout << "vector" << endl;
    for (auto const i : generic_ip)
    {
        cout << i << endl;
    }
}
template <typename T> typename std::enable_if_t<std::is_same_v<T, std::list<short>>, void> print_ip(T generic_ip)
{
    cout << "list" << endl;
    for (auto const i : generic_ip)
    {
        cout << i << endl;
    }
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
    sorting::print_ip(int16_t{55});
    sorting::print_ip(int32_t{555});
    std::vector v1{1, 2, 34, 4};
    std::list<short> v2{123, 323, 434, 323};
    sorting::print_ip(v1);
    sorting::print_ip(v2);
    return EXIT_SUCCESS;
}
