#ifndef EXAMPLE_LIB
#define EXAMPLE_LIB
#include "another.hpp"
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#endif

#ifdef _VERSIONING
#include "version.h"
#endif

using my_int = int32_t;
int run_me();
int makeXsum(std::initializer_list<int> values);
namespace NSX1
{
struct Some_Classs1
{
    int age{0};
    double freq{0.0};

    void print_age() const;
    void print_freq() const;
};
}; // namespace NSX1
struct Point
{
    double x{0.0};
    double y{0.0};
};
// template

#ifdef __cplusplus
extern "C"
{
#endif
    void DumpHex(const void* data, size_t size);
#ifdef __cplusplus
}
#endif
