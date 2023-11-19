#pragma once

#include "buffer.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T, size_t MAX_ALLOCATOR_SIZE>
class Xallocator
{
  public:
    using value_type = T;
    using const_reference = const T&;
    using const_pointer = const T*;
    using reference = T&;
    using pointer = value_type*;
    using self = Xallocator<T, MAX_ALLOCATOR_SIZE>;
    using size_type = decltype(MAX_ALLOCATOR_SIZE);

    template <typename A>
    struct rebind
    {
        using other = Xallocator<A, MAX_ALLOCATOR_SIZE>;
    };
    Xallocator() : m_allocator_buffer(Buffer<value_type, MAX_ALLOCATOR_SIZE>()), m_offset(size_type()) {}

    virtual ~Xallocator() = default;
    Xallocator(const self&) = delete;
    Xallocator(self&) = delete;
    Xallocator(self&&) = delete;
    Xallocator operator=(self) = delete;

    pointer allocate(size_t count)
    {
        if (count > MAX_ALLOCATOR_SIZE)
            throw std::bad_alloc();
        size_type old_offset = m_offset;
        ++m_offset;
        return &m_allocator_buffer[old_offset];
    }

    void deallocate(pointer, size_type)
    {
        // simple//
    }

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args)
    {
        // place object
        ::new (p) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U* p)
    {
        p->~U();
    }

  private:
    Buffer<value_type, MAX_ALLOCATOR_SIZE> m_allocator_buffer;
    size_type m_offset{};
};