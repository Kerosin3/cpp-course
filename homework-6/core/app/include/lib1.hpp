#pragma once
#include <concepts>
#include <format>
#include <map>
#include <numeric>

template <typename T, T def_val>
class RowProxy;

template <typename T, T def_val>

/// main maxtrix class
class AMatrix
{
    using Element = std::pair<T, T>;

  public:
    AMatrix() = default;
    virtual ~AMatrix() = default;
    // return Proxy Row when acessing row
    auto operator[](int index) -> RowProxy<T, def_val>
    {
        return RowProxy(this, index);
    }
    int get_size()
    {
        return m_matrix.size();
    }
    // add non-default element or erase when assigning default value
    void add_element(Element elem, T value)
    {
        if (value != def_val)
        {
            this->m_matrix[elem] = value;
        }
        // erase if we assigning the default value
        else if (this->m_matrix.contains(elem))
        {
            this->m_matrix.erase(elem);
        }
    }
    // get element or default value
    auto get_element(Element elem) -> T
    {
        return (!this->m_matrix.contains(elem)) ? def_val : this->m_matrix[elem];
    }

  private:
    std::map<Element, T> m_matrix;
};

template <typename T, T def_val>
// Proxy class
class RowProxy
{

    using Element = std::pair<T, T>;

  public:
    RowProxy() = delete;
    virtual ~RowProxy() = default;
    // construct default proxy obj when acessing row
    RowProxy(AMatrix<T, def_val>* mtrx, int val) : m_matrix(mtrx)
    {
        this->m_data_row_column = std::make_pair(val, 0);
    }
    // assign data by row and column
    RowProxy& operator=(T value)
    {
        this->m_matrix->add_element(m_data_row_column, value);
        return *this;
    }

    // set column
    RowProxy& operator[](int column)
    {
        this->m_data_row_column.second = column;
        return *this;
    }
    operator T()
    {
        return this->m_matrix->get_element(m_data_row_column);
    }

  private:
    Element m_data_row_column;
    AMatrix<T, def_val>* m_matrix;
};

template <typename U, U d_val>
struct std::formatter<RowProxy<U, d_val>> : std::formatter<std::string>
{
    auto format(RowProxy<U, d_val> some_field, format_context& ctx) const
    {
        return formatter<string>::format(std::format("{}", some_field.operator U()), ctx);
    }
};
