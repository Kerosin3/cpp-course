#pragma once
#include <map>
#include <concepts>
#include <numeric>

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

    int get_size_c() const
    {
        auto fx = [](size_t accum, std::pair<U, Field<U, d_val>> another) {
            return accum + 1;
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
    int size() const
    {
        auto fx = [](size_t accum, std::pair<U, Cell<U, d_val>> another) {
            return accum + another.second.get_size_c();
        };
        return std::accumulate(m_data_matrix.cbegin(), m_data_matrix.cend(), 0, fx);
    }

  private:
    // store map to cells
    std::map<U, Cell<U, d_val>> m_data_matrix;
};
