#include "lib1.hpp"
#include <algorithm>
#include <array>
#include <boost/range/irange.hpp>
#include <cassert>
#include <csignal>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exampleZ/example_lib.hpp>
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <iostream>
#include <iterator>
#include <memory>
#include <new>
#include <optional>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <string>
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

int main(int /*unused*/, char** /*unused*/)
{
    cout << My_Func(5, 10) << endl;
    cout << My_Func(1.2, 5.6) << endl;
    return EXIT_SUCCESS;
}
