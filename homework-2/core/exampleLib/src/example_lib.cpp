#include "exampleLib/example_lib.hpp"
using namespace std;

/**
 * @brief Initializes reading from supplied stream source
 *
 */
void Filtering::read_input()
{
    std::string InputLine;
    while (std::getline(this->cinstream, InputLine))
    {
        auto DelimPosition = InputLine.find('\t');
        auto a_str = InputLine.substr(0, DelimPosition);
        this->input_lines.emplace_back(a_str);
    }
}

std::array<uint8_t, 4> get_ipv4_int(const std::string& str_in)
{
    auto delimiter = '.';
    size_t initial_position{};
    std::array<uint8_t, 4> out_data{};
    for (unsigned short index = 0; auto& a_byte : out_data)
    {
        size_t position = str_in.find(delimiter, initial_position);
        auto numeric_string = std::stoi(str_in.substr(initial_position, position - initial_position));
        a_byte = numeric_string;
        initial_position = position + 1;
        index++;
    }
    return out_data;
}
/**
 * @brief sorting
 *
 * @param[input] src vector of strings
 */
void Filtering::sort_descending(vector<string>& src)
{
    std::sort(src.begin(), src.end(), [](const std::string& str1, const std::string& str2) {
        return !compare_strings(str1, str2);
    });
}

/**
 * @brief Used to filter in series and single
 *
 * @param[in] BytePattern single byte that is being searched for
 * @param[in] ByteToTest specify which byte position to search in an IP, 1.2.3.4. 1<- first! 2<- second!
 */
void Filtering::filter_this(uint8_t BytePattern, BytePlace ByteToTest)
{
    auto& src = (this->sequence) ? this->tmp_storage : this->input_lines;
    auto IteratorString = src.begin();
    while (IteratorString != src.end())
    {
        auto TestValue = filter_by_byte(*IteratorString, BytePattern, ByteToTest);
        if (this->sequence)
        {
            if (!TestValue)
            {
                this->tmp_storage.erase(IteratorString);
                continue; // ok...
            }
        }
        else
        {
            if (TestValue)
            {
                this->tmp_storage.push_back(*IteratorString);
            }
        }
        IteratorString++;
    }
    this->sequence = true;
}
/**
 * @brief printout to stdout
 *
 */
void Filtering::printout()
{
    auto& src = (this->sequence) ? this->tmp_storage : this->input_lines;
    sort_descending(src);
    for (const auto& anIp : src)
    {
        cout << std::nounitbuf << anIp << '\n';
    }
}

/**
 * @brief searches supplied byte on specified place. ANY - search in any byte
 *
 * @param[[TODO:direction]] str source ipv4 string
 * @param[[TODO:direction]] byte byte to search
 * @param[[TODO:direction]] place byte position in an IP
 * @return true if matches
 */
bool filter_by_byte(const std::string& str, uint8_t byte, BytePlace place)
{
    // convert string to number
    auto ConvertedStringToNumber = convert(str);
    // mask to shift
    for (size_t index = 0; index < 4; index++)
    {
        unsigned int Position = static_cast<unsigned>(place);
        // iterate over bitmask enum
        Position >>= index;
        // decide if this bit should be tested
        if (Position & 0x1)
        {
            // bitmask
            std::uint32_t ZerosMask{0x000000FF};
            // adjust bitmask
            ZerosMask <<= index * 8;
            // mask off
            uint32_t Masked = (ConvertedStringToNumber & ZerosMask) >> (index * 8); // mask off and shift right
            auto Match = (!((Masked) ^ byte));
            if (place != BytePlace::any)
            {
                return Match;
            }
            else
            {
                if (Match)
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return false; // default
}

/**
 * @brief compares two strings with format X.Y.Z.Q, bytesizez accordingly to ipv4
 *
 * @param[input] str1 first string
 * @param[input] str2 second string
 * @return true if string2 > string1
 */
bool compare_strings(const std::string& str1, const std::string& str2)
{

    std::istringstream Stream1(str1);
    std::istringstream Stream2(str2);

    std::string String1{};
    std::string String2{};
    constexpr char Delimiter = '.';
    std::array<bool, 4> CmpState{false};
    for ([[maybe_unused]] auto& var : CmpState)
    {
        // get lines
        std::getline(Stream1, String1, Delimiter);
        std::getline(Stream2, String2, Delimiter);
        // convert strings to numbers
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
            continue;
        }
    };
    return false;
}
/**
 * @brief converting string containing ipv4 IP to uint32
 *
 * @param[input] ipv4Str string with an IP
 * @return parsed number
 */
uint32_t convert(const std::string& ipv4Str)
{
    std::istringstream iss(ipv4Str);
    uint32_t Ipv4ToNumeric = 0;
    for (uint32_t i = 0; i < 4; ++i)
    {
        uint32_t part;
        iss >> part;
        Ipv4ToNumeric |= part << (8 * (3 - i));
        if (i != 3)
        {
            char delimiter;
            iss >> delimiter;
        }
    }
    return Ipv4ToNumeric;
}
