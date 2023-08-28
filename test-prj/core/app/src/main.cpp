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

template <typename T> class Example
{
    T my_arg = {};
};

int main(int /*unused*/, char** /*unused*/)
{
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
    return EXIT_SUCCESS;
}
