#include "lib1.hpp"
#include <algorithm>
#include <array>
#include <boost/range/irange.hpp>
#include <cassert>
#include <csignal>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exampleZ/example_lib.hpp>
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <new>
#include <optional>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

#ifdef _VERSIONING
#include "version.h"
#endif

#ifndef __cplusplus
#error C++ is required
#elif __cplusplus < 202002L
#error C++20 is required
#endif

using namespace std;

struct Some_class
{
    static std::string d_name;
    std::shared_ptr<int> comon;
    void get_name()
    {
        cout << fmt::format("name is {}", d_name);
    };
    void printout_shared() const
    {
        cout << "your data is " << *this->comon << endl;
    };
    void attach(std::shared_ptr<int>& shrd)
    {
        this->comon = shrd;
    };
};
std::string Some_class::d_name = "default name\n";

template <typename T> T My_Func(T x, T y)
{
    return (x > y) ? x : y;
}

auto ret_some()
{
    auto rtn{"this is a string"s};
    return rtn;
}

template <typename T> T add_something(T arg1, T arg2)
{
    return (arg1 > arg2) ? arg1 : arg2;
}

class MyStruct
{
    int number = 0;
    inline static size_t serial;
    MyStruct() = delete;

  public:
    inline explicit MyStruct(int arg) : number{arg} {}
    void set_number(int arg)
    {
        this->number = arg;
    }
    void print_number() const
    {
        cout << "your number is " << this->number << endl;
    }
    static void print_serial()
    {
        cout << "your serial is " << MyStruct::serial << endl;
    }
    [[nodiscard]] int get_value() const
    {
        return this->number;
    }
    MyStruct& operator+=(int rhs)
    {
        this->number += rhs;
        return *this;
    }
    MyStruct& operator+=(const MyStruct& rhs)
    {
        cout << "overloading!" << endl;
        this->number += rhs.number;
        return *this;
    }
    MyStruct operator+(int arg) const
    {
        return MyStruct{this->get_value() + arg};
    }
};

MyStruct operator+(const MyStruct& lsg, const MyStruct& rhs)
{
    return MyStruct{rhs.get_value() + lsg.get_value()};
}
class Iface1
{
  public:
    [[nodiscard]] virtual int add_something(int arg1, int agr2) = 0;
    virtual ~Iface1() = default;
};

template <typename T> struct Example : public Iface1
{
    T my_arg = {};
    [[nodiscard]] int add_something(int arg1, int arg2) override
    {
        return arg1 + arg2;
    }

    Example() = default;
};

template <typename T> class Grid
{
  public:
    explicit Grid(size_t width = d_widht, size_t height = d_height);
    void printout()
    {
        fmt::println("data 1 {}, data 2 {}", m_width, m_height);
    }
    virtual ~Grid() = default;

  private:
    static const size_t d_widht{10};
    static const size_t d_height{10};
    size_t m_width{0}, m_height{0};
};

template <typename T> Grid<T>::Grid(size_t width, size_t height) : m_width{width}, m_height{height}
{
    cout << "default constructor" << endl;
}

template class Grid<int>;
using IntGrid = Grid<int>;

template class Grid<double>;
using DouGrid = Grid<double>;

int main(int /*unused*/, char** /*unused*/)
{
    std::cout << __cplusplus << std::endl;
    printf("verion is %d\n", APP_MAJOR_VERSION);
    printf("verion is %d\n", APP_MINOR_VERSION);
    printf("verion is %d\n", APP_PATCH_VERSION);
    cout << My_Func(5, 10) << endl;
    cout << My_Func(1.2, 5.6) << endl;

    auto m1 = MyStruct{0};
    auto M2 = MyStruct{50};
    m1.print_number();
    m1 += 5;
    m1.print_number();
    m1 += M2;
    m1.print_number();
    auto t1 = m1 + 5;
    cout << "dasda" << endl;
    t1.print_number();

    Example<int> myExample;
    auto x = myExample.add_something(10, 20);

    IntGrid MYGrid{};
    MYGrid.printout();

    return EXIT_SUCCESS;
}
