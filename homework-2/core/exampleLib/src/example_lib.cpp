#include "exampleLib/example_lib.hpp"
using namespace std;

void Filtering::read_input()
{
    std::string InputLine;
    while (std::getline(this->cinstream, InputLine))
    {
        auto DelimPosition = InputLine.find('\t');
        this->input_lines.emplace_back(InputLine.substr(0, DelimPosition));
    }
}

void Filtering::sort_descending()
{
    std::sort(this->input_lines.begin(), this->input_lines.end(), [](const std::string& str1, const std::string& str2) {
        return !compare_strings(str1, str2);
    });
}

void Filtering::printout(uint8_t BytePattern, unsigned ByteToTest)
{
    cout << " TESTNG" << endl;
    for (const auto& anIp : this->input_lines)
    {
        if (filter_by_byte(anIp, BytePattern, BytePlace::first))
        {

            cout << anIp << endl;
        }
    }
}

void Filtering::printout()
{
    for (const auto& anIp : this->input_lines)
    {
        cout << anIp << endl;
    }
}

bool filter_by_byte(const std::string& str, uint8_t byte, unsigned place)
{
    auto ConvertedStringToNumber = convert(str);
    std::uint32_t ZerosMask{0x000000FF};
    uint8_t ShiftValue = place >> 1;
    if (place == BytePlace::forth)
    {
        ShiftValue = 3;
    }
    ZerosMask <<= ShiftValue * 8;                                                // shift mask
    uint32_t Masked = (ConvertedStringToNumber & ZerosMask) >> (ShiftValue * 8); // mask off and shift right
    return (!((Masked) ^ byte)) ? true : false;
}

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
        if (String1Number < String2Number)
        {
            return true;
        }
        else if (String2Number < String1Number)
        {
            return false;
        }
        else // equal
        {
            String1.clear();
            String2.clear();
            index++;
            continue;
        }
    };
    return false;
}
