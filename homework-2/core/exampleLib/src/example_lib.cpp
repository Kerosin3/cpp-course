#include "exampleLib/example_lib.hpp"
using namespace std;

bool compare_strings(const std::string& str1, const std::string& str2)
{

    std::istringstream Stream1(str1);
    std::istringstream Stream2(str2);

    std::string String1{};
    std::string String2{};
    constexpr char Delimiter = '.';
    std::array<bool, 4> cmp_state{false};
    for (unsigned short index = 0; auto& _i : cmp_state)
    {
        std::getline(Stream1, String1, Delimiter);
        std::getline(Stream2, String2, Delimiter);
        auto String1Number = std::stoi(String1);
        auto String2Number = std::stoi(String2);
        if (String1Number > String2Number)
        {
            cmp_state[index] = false;
        }
        else if (String2Number > String1Number)
        {
            cmp_state[index] = true;
            return true;
        }
        else // equal
        {
            cmp_state[index] = false;
        }
        String1.clear();
        String2.clear();
        index++;
    };
    return false;
}
