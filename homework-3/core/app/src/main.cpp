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
#error C++ is required
#elif __cplusplus < 202002L
#error C++20 is required
#endif
// https://howardhinnant.github.io/allocator_boilerplate.html
using namespace std;
// http://users.cis.fiu.edu/~weiss/Deltoid/vcstl/templates
template <typename T>
class A
{
  public:
    T value;
    A();
    ~A();
};

template <typename X>
A<X>::A()
{
    cout << "construct" << endl;
}
template <typename X>
A<X>::~A()
{
    cout << "deconstruct" << endl;
}
// template <typename T>
// using alias = typename A<T>::value;

template <typename A>
class Z
{
  public:
    template <typename B>
    struct Inner
    {
        B a;
    };
    template <typename W>
    W func1()
    {}
};

template <typename T, typename T1>
using alias = typename Z<T>::template Inner<T1>;

template <typename T, typename T1>
using alias2 = typename Z<T>::template func1<T1>;

int main(int argc, char* argv[])
{
    // std::map<int, int, std::less<>, Xallocator<std::pair<const int, int>, 1>> amap;
    // amap.insert({1, 5});
    // A<int> Aa;
    // A<float> Af;
    alias<int, float> adsad;
    cout << typeid(adsad).name() << endl;

    return EXIT_SUCCESS;
}
