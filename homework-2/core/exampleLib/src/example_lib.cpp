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

void Filtering::sort_descending(vector<string>& src)
{
    std::sort(src.begin(), src.end(), [](const std::string& str1, const std::string& str2) {
        return !compare_strings(str1, str2);
    });
}

Filtering& Filtering::filter_this(uint8_t BytePattern, unsigned short ByteToTest)
{
    cout << "------" << endl;
    auto& src = (this->sequence) ? this->tmp_storage : this->input_lines;
    auto it = src.begin();
    while (it != src.end())
    {
        auto TestValue = filter_by_byte(*it, BytePattern, ByteToTest);
        if (TestValue)
        {
            // wrotking with full
            if (!this->sequence)
            {
                this->tmp_storage.push_back(*it);
            }
            else
            {
                this->tmp_storage.erase(it);
            }
        }
        it++;
    }
    this->sequence = true;
    return *this;
}

void Filtering::printout()
{
    auto& src = (this->sequence) ? this->tmp_storage : this->input_lines;
    sort_descending(src);
    for (const auto& anIp : src)
    {
        cout << anIp << endl;
    }
}

bool filter_by_byte(const std::string& str, uint8_t byte, unsigned short place)
{
    auto ConvertedStringToNumber = convert(str);
    std::uint32_t ZerosMask{0x000000FF};
    for (size_t index = 0; index < 4; index++)
    {
        unsigned short Position = place;
        Position >>= index;
        // this bit is set
        if (Position & 0x1)
        {

            ZerosMask <<= index * 8;
            uint32_t Masked = (ConvertedStringToNumber & ZerosMask) >> (index * 8); // mask off and shift right
            return (!((Masked) ^ byte)) ? true : false;
        }
        else
        {
            // just skip
            continue;
        }
    }
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
