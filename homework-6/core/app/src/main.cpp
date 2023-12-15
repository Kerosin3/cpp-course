#include <concepts>
#include <cstddef>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
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
        cout << "assigned" << endl;
        return *this;
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
    Field<U, d_val>& operator[](int index)
    {
        return m_cell_map[index];
    }

    size_t get_size_c() const
    {
        auto fx = [&](size_t previous, const std::pair<U, Field<U, d_val>> another) {
            return previous + 1;
        };
        return std::accumulate(m_cell_map.cbegin(), m_cell_map.cend(), 0, fx);
    }

  private:
    // store map to cells
    std::map<U, Field<U, d_val>> m_cell_map;
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
    Cell<U, d_val>& operator[](int index)
    {
        return m_data_matrix[index];
    }
    size_t size() const
    {
        auto fx = [&](size_t previous, const std::pair<U, Cell<U, d_val>> another) {
            return previous + another.second.get_size_c();
        };
        return std::accumulate(m_data_matrix.cbegin(), m_data_matrix.cend(), 0, fx);
    }

  private:
    // store map to cells
    std::map<U, Cell<U, d_val>> m_data_matrix;
};

int main(int argc, char* argv[])
{
    cout << "program starts" << endl;
    AMatrix<int, -1> my_matrix{};
    my_matrix[10][1] = 10;
    my_matrix[10][2] = 11;
    my_matrix[10][3] = 12;
    my_matrix[1][3] = 13;
    cout << "value is " << my_matrix[10][3] << endl;
    // my_matrix[1][2] = 11;
    cout << my_matrix.size() << endl;
    return EXIT_SUCCESS;
}
