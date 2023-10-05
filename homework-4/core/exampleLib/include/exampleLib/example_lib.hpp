#ifndef EXAMPLE_LIB
#define EXAMPLE_LIB

#include <iostream>
#include <type_traits>
#endif

#ifdef _VERSIONING
#include "version.h"
#endif

using namespace std;
namespace sorting
{

/**
 * @brief printing integral type
 *
 * @tparam T some integer type
 * @param[input] number a number
 */
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
/**
 * @brief printing for string type
 *
 * @tparam T some string
 * @param[input] number some number is string representation
 */
template <typename T> typename std::enable_if_t<std::is_same_v<T, std::string>, void> print_ip(T number)
{
    cout << number << endl;
}

/**
 * @brief printing list
 *
 * @tparam T list type
 * @param[input] cont_list list containing integer type
 */
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
