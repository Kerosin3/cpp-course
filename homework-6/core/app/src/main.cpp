#include <concepts>
#include <cstddef>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <vector>
#ifdef _VERSIONING
#include "version.h"
#endif

#ifndef __cplusplus
error C++ is required elif __cplusplus < 202002L error C++ 20 is required
#endif
    using namespace std;

// template <typename U>
// concept NonPointer = not is_pointer_v<U>;

template <typename U, U d_val>
requires std::integral<U>
class Field
{
  public:
    Field() = default;
    virtual ~Field() = default;

    Field& operator=(U rhs)
    {
        m_value = rhs;
        return *this; // ?
    }
    operator U() const
    {
        return m_value;
    }

  private:
    U m_value;
};

template <typename U, U d_val>
requires std::integral<U>
class Cell
{
  public:
    Cell() = default;
    virtual ~Cell() = default;

  private:
    // store map to cells
    static std::map<U, Field<U, d_val>> m_cell_map;
};

template <typename U, U d_val>
requires std::integral<U>
class AMatrix
{
  public:
    AMatrix() = default;
    virtual ~AMatrix() = default;
    size_t get_size() const
    {
        return 0;
    }

  private:
    // store map to cells
    static std::map<U, Cell<U, d_val>> m_data_matrix;
};

int main(int argc, char* argv[])
{
    cout << "program starts" << endl;
    return EXIT_SUCCESS;
}
