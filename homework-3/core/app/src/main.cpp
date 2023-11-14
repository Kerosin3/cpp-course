#include "exampleLib/example_lib.hpp"
#include <cstddef>
#include <iostream>
#include <list>
#include <map>
#include <new>
#include <ratio>
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

template <typename T, size_t B_size> class Buffer {

public:
  using size_type = decltype(B_size);
  using value_type = T;
  using reference = T &;
  using pointer = T *;

private:
  pointer head_data;

public:
  Buffer() {
    head_data = (pointer)malloc(sizeof(value_type) * B_size);

    if (!head_data)
      throw std::bad_alloc();
  }
  virtual ~Buffer() {
    cout << "deleting" << endl;
    delete head_data;
  };
  reference operator[](size_type index) const {
    cout << "index is " << index << endl;
    if (index >= B_size || index < 0)       throw std::out_of_range("buffer index is out of range");
    return *(head_data + index);
  }
};

template <typename T, size_t SIZE> class Xallocator {
public:
  using value_type = T;
  using const_reference = const T &;
  using const_pointer = const T *;
  using reference = T &;
  using pointer = value_type *;
  using self = Xallocator<T, SIZE>;
  using size_type = decltype(SIZE);

  template <typename A> struct rebind { using other = Xallocator<A, SIZE>; };
  ~Xallocator() = default;
  Xallocator(const self &other) = delete;
  Xallocator(self &&other) = delete;
  Xallocator operator=(self) = delete;
  Xallocator()
      : m_allocator_buffer(Buffer<value_type, SIZE>()), m_offset(size_type()) {}

  pointer allocate(size_t count) {
    if (count > SIZE)
      throw std::bad_alloc();
    size_type old_offset = m_offset;
    cout << "offset is " << m_offset << endl;
    ++m_offset;
    return &m_allocator_buffer[old_offset];
  }
  void deallocate(pointer, size_type) {}

  template <typename U, typename... Args> void construct(U *p, Args &&...args) {
    ::new (p) U(std::forward<Args>(args)...);
  }

  template <typename U> void destroy(U *p) { p->~U(); }

private:
  Buffer<value_type, SIZE> m_allocator_buffer;
  size_type m_offset{};
};
int main(int argc, char *argv[]) {
  std::map<int, int, std::less<>, Xallocator<std::pair<const int, int>, 1>>
      amap;
  amap.insert({1, 5});
  return EXIT_SUCCESS;
}
