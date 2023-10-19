#ifndef EXAMPLE_LIB
#define EXAMPLE_LIB

#include <iostream>
#include <type_traits>
#endif

#ifdef _VERSIONING
#include "version.h"
#endif

using namespace std;

namespace storing
{

/**
 * struct store_element - this class stores current and next element
 *
 * @tparam U datatype
 */
template <typename U> struct store_element
{
    store_element(U* data, store_element<U>* next_element) : m_data(data), m_next_element(next_element) {}
    U* m_data;
    store_element<U*> m_next_element;
};
} // namespace storing
