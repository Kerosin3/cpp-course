#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

template <typename T, typename Allocator = std::allocator<T>>
class Xvector
{
    static inline size_t ALLOCATE_PER_ALLOC = 1;
    using pointer = T*;
    // initialize allocator
    using xalloc = typename std::allocator_traits<Allocator>::template rebind_alloc<T>;
    // rebinds to type
    using xalloc_traits = typename std::allocator_traits<Allocator>::template rebind_traits<T>;

    size_t m_vsize{};
    pointer m_data_pointer{nullptr};
    xalloc m_xallocator;

  public:
    // construct allocator
    Xvector() : m_xallocator(){};
    virtual ~Xvector() = default;
    [[nodiscard]] size_t size() const noexcept
    {
        return m_vsize;
    }
    T& operator[](size_t position)
    {
        return m_data_pointer[position];
    }
    const T& operator[](size_t position) const
    {
        return m_data_pointer[position];
    }
    void push_back(const T& element)
    {
        // allocate one element via allocator
        T* ptr_allocate = xalloc_traits::allocate(m_xallocator, Xvector::ALLOCATE_PER_ALLOC);
        // place element in memory
        xalloc_traits::construct(m_xallocator, ptr_allocate, element);
        // pin first element pointer as base
        if (m_vsize == 0)
        {
            m_data_pointer = ptr_allocate;
        }
        m_vsize++;
    }
    void pop_back()
    {
        auto element_to_deallocate = m_data_pointer + m_vsize;
        // firstly destroy
        xalloc_traits::destroy(m_xallocator, element_to_deallocate);
        // then deallocate
        xalloc_traits::deallocate(m_xallocator, element_to_deallocate);
        m_vsize--;
    }
    //-----------------------------------------
    // iterators
    using xiterator = T*;
    using const_xiterator = const T*;
    xiterator begin() const noexcept
    {
        return m_data_pointer;
    }
    xiterator end() const noexcept
    {
        return m_data_pointer + m_vsize;
    }
    const_xiterator cbegin() const noexcept
    {
        return m_data_pointer;
    }
    const_xiterator cend() const noexcept
    {
        return m_data_pointer + m_vsize;
    }
};
