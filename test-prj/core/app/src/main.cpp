#include "lib1.hpp"
#include <algorithm>
#include <array>
#include <boost/range/irange.hpp>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <exampleZ/example_lib.hpp>
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <iostream>
#include <iterator>
#include <memory>
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

static size_t ArrSize = 10;

int main(int /*unused*/, char** /*unused*/)
{
    fmt::print("Hello, world!\n");
    auto sharedp = std::make_shared<int>(42);
    auto* arr1 = new Some_class[ArrSize];
    for (auto i : boost::irange(0, 10))
    {
        arr1[i].attach(sharedp);
        arr1[i].printout_shared();
    };
    delete[] arr1;
    return 0;
}