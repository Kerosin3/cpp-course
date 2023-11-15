#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T, size_t B_size>
class Buffer
{

  public:
    using size_type = decltype(B_size);
    using value_type = T;
    using reference = T&;
    using pointer = T*;

  private:
    pointer head_data;

  public:
    Buffer()
    {
        head_data = (pointer)malloc(sizeof(value_type) * B_size);

        if (!head_data)
            throw std::bad_alloc();
    }
    virtual ~Buffer()
    {
        delete head_data;
    };
    reference operator[](size_type index) const
    {
        if (index >= B_size || index < 0)
            throw std::out_of_range("buffer index is out of range");

        return (head_data[index]);
    }
};

template <typename T, size_t SIZE>
class Xallocator
{
  public:
    using value_type = T;
    using const_reference = const T&;
    using const_pointer = const T*;
    using reference = T&;
    using pointer = value_type*;
    using self = Xallocator<T, SIZE>;
    using size_type = decltype(SIZE);

    template <typename A>
    struct rebind
    {
        using other = Xallocator<A, SIZE>;
    };
    Xallocator() : m_allocator_buffer(Buffer<value_type, SIZE>()), m_offset(size_type()) {}

    ~Xallocator() = default;
    Xallocator(const self&) = delete;
    Xallocator(self&) = delete;
    Xallocator(self&&) = delete;
    Xallocator operator=(self) = delete;

    pointer allocate(size_t count)
    {
        if (count > SIZE)
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
    Buffer<value_type, SIZE> m_allocator_buffer;
    size_type m_offset{};
};