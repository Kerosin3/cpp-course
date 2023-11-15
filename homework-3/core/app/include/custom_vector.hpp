#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

template <typename T, typename Allocator = std::allocator<T>>
class Xvector
{
    using pointer = const T*;
    //https://stackoverflow.com/questions/45549030/can-typedef-typename-be-replaced-by-using-keyword-in-c-11
    using xalloc = typename std::allocator_traits<Allocator>::template rebind_alloc<T>;
    using xalloc_traits = typename std::allocator_traits<Allocator>::template rebind_traits<T>;

    size_t m_vsize{};
    pointer m_data_pointer{nullptr};
    xalloc m_xallocator;

  public:
    Xvector() : m_xallocator(){};
    ~Xvector() = default;
};