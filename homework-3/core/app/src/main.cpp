#include "allocator.hpp"
#include "custom_vector.hpp"
#include <cstddef>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <vector>
#ifdef _VERSIONING
#include "version.h"
#endif

#ifndef __cplusplus
error C++ is required elif __cplusplus < 202002L error C++ 20 is required
#endif

    int
    factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

using namespace std;
int main(int argc, char* argv[])
{
    // standart
    std::map<int, int> stl_map{};
    for (int index = 0; index < 10; index++)
    {
        stl_map.insert({index, factorial(index)});
    }
    // map with custom alloc
    std::map<int, int, std::less<>, Xallocator<std::pair<const int, int>, 10>> map_ca;
    for (int index = 0; index < 10; index++)
    {
        map_ca.insert({index, factorial(index)});
    }
    cout << "CUSTOM MAP" << endl;
    for (auto& it : map_ca)
    {
        std::cout << it.first << ' ' << it.second << endl;
    }
    cout << endl;
    // custom container
    Xvector<int, Xallocator<int, 10>> custom_vector;
    for (int index = 0; index < 10; index++)
    {
        custom_vector.push_back(index);
    }
    cout << "CUSTOM VECTOR" << endl;
    for (size_t index = 0; const auto& elem : custom_vector)
    {
        cout << index << ' ' << elem << endl;
        index++;
    }
    return EXIT_SUCCESS;
}
