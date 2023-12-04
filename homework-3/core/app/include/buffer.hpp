#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T, size_t BUFFER_MAX_SIZE>
class Buffer
{

  public:
    using size_type = decltype(BUFFER_MAX_SIZE);
    using value_type = T;
    using reference = T&;
    using pointer = T*;

  private:
    pointer m_buf_base_pointer;

  public:
    Buffer()
    {
        m_buf_base_pointer = static_cast<pointer>(::operator new(sizeof(value_type) * BUFFER_MAX_SIZE));

        if (!m_buf_base_pointer)
            throw std::bad_alloc();
    }
    virtual ~Buffer()
    {
        delete m_buf_base_pointer;
    };
    reference operator[](size_type index) const
    {
        if (index >= BUFFER_MAX_SIZE || index < 0)
            throw std::out_of_range("buffer index is out of range");

        return (m_buf_base_pointer[index]);
    }
};