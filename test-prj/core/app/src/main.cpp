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
#include <utility>
#include <vector>

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

struct Struct1
{
    int valx = 0;
    static inline size_t index = {1};
    Struct1() = delete;
    explicit(true) Struct1(int arg1) : valx{arg1} {}
    Struct1(const Struct1& src) = delete;
    Struct1& operator=(const Struct1& rhs) = delete;

    void set_val(int arg)
    {
        this->valx = arg;
    }
    void print_val() const
    {
        cout << "your value is " << this->valx << endl;
    }
    static void get_index()
    {
        cout << "index is " << index << endl;
    }
};

inline int func1x(int a = 10, int b = 10)
{
    return (a > b) ? a : b;
}

class Example1
{
    int my_int = 0;

  public:
    enum class Color
    {
        Red,
        Gree,
        White,
        Yellow
    };

  public:
    Example1 operator+(const Example1& exmpl) const
    {
        return Example1{this->my_int, exmpl.my_int};
    }
    void print_data() const
    {
        cout << "your data is " << this->my_int << endl;
    }

  private:
    explicit Example1(int a, int b)
    {
        this->my_int = a + b;
    }

  public:
    explicit Example1(Color clr)
    {
        if (clr == Color::Red)
        {
            this->my_int = 42;
        }
        else
        {
            this->my_int = 1;
        }
    }
    explicit Example1(int arg = 1)
    {
        this->my_int = arg;
    }
};

int main(int /*unused*/, char** /*unused*/)
{
    cout << My_Func(5, 10) << endl;
    cout << My_Func(1.2, 5.6) << endl;

    auto s = Struct1{24};
    s.set_val(550);
    s.print_val();

    func1x();

    auto x1 = Example1{Example1::Color::Red};
    auto x2 = Example1{100};
    x1.print_data();
    x2.print_data();
    auto x3 = x1 + x2;
    x3.print_data();
    return EXIT_SUCCESS;
}
