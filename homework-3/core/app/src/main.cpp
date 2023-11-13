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
// https://howardhinnant.github.io/allocator_boilerplate.html
using namespace std;

template <typename T> class Xallocator
{
  public:
    using value_type = T;

    Xallocator() noexcept {} // not required, unless used
    template <typename U> Xallocator(Xallocator<U> const&) noexcept {}

    value_type* // Use pointer if pointer is not a value_type*
    allocate(std::size_t n)
    {
        cout << "allocation" << endl;
        return static_cast<value_type*>(::operator new(n * sizeof(value_type)));
    }

    void deallocate(value_type* p, std::size_t) noexcept // Use pointer if pointer is not a value_type*
    {
        cout << "deallocation" << endl;
        ::operator delete(p);
    }

};

template <typename T, typename U> bool operator==(Xallocator<T> const&, Xallocator<U> const&) noexcept
{
    return true;
}

template <typename T, typename U> bool operator!=(Xallocator<T> const& x, Xallocator<U> const& y) noexcept
{
    return !(x == y);
}

int main(int argc, char* argv[])
{
    std::vector<int,Xallocator<int>> xvec;
    xvec.push_back(5);
    xvec.push_back(5);
    return EXIT_SUCCESS;
}
