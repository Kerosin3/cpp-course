#include "exampleLib/example_lib.hpp"
#include <cstddef>
#include <iostream>
#include <list>
#include <map>
#include <new>
#include <stdexcept>
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

template <typename T, size_t B_size>
class Buffer
{

  public:
    using size_type = decltype(B_size);
    using value_type = T;
    using reference = const T&;
    using pointer = const T*;

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
        cout << "deleting" << endl;
        delete head_data;
    };
    reference operator[](size_type index) const
    {
        if (index >= B_size || index < 0)
            throw std::out_of_range("buffer index is out of range");
        return *(head_data + index);
    }
};

template <typename T, size_t SIZE>
class Xallocator
{
  public:
    using value_type = T;
    using c_reference = const T&;
    using c_pointer = const T*;
    using reference = T&;
    using pointer = T*;
    using self = Xallocator<T, SIZE>;
    using size_type = decltype(SIZE);

    template <typename A>
    struct rebind
    {
        using other = Xallocator<A, SIZE>;
    };
    ~Xallocator() = default;
    Xallocator(const self& other) = delete;
    Xallocator(self&& other) = delete;
    Xallocator operator=(self) = delete;
    Xallocator() : m_allocator_buffer(Buffer<value_type, SIZE>()), m_offset(size_type()) {}
    void allocate(size_t count){
      if (count >= SIZE)
        throw std::bad_alloc();
      size_type old_offset = m_offset;
      ++m_offset;
      return &m_allocator_buffer[m_offset];
    }
  private:
    Buffer<value_type, SIZE> m_allocator_buffer;
    size_type m_offset{
};

int main(int argc, char* argv[])
{
  i
    return EXIT_SUCCESS;
}
