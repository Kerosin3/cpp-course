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
        const auto a_str = InputLine.substr(0, DelimPosition);
        this->input_lines.push_back(get_ipv4_int(a_str));
    }
}
/**
 * @brief converts ip as uint32 to string. THROW when sprintf writes wrong
 *
 * @param[input] ip_as_uint32 ipv4 as uint32
 */
std::string Filtering::get_ip_char_repr(uint32_t ip_as_uint32)
{
    char out_buf[Filtering::string_size] = {0};
    uint8_t first = (ip_as_uint32 >> 24) & 0xFF;
    uint8_t second = (ip_as_uint32 >> 16) & 0xFF;
    uint8_t third = (ip_as_uint32 >> 8) & 0xFF;
    uint8_t forth = (ip_as_uint32)&0xFF;
    auto ret = snprintf(out_buf, Filtering::string_size, "%u.%u.%u.%u", first, second, third, forth);
    if (!ret)
    {
        throw std::length_error("sprintf wrong lenght has been written");
    }
    return out_buf;
}
/**
 * @brief converting valid ipv4 address to uint32
 *
 * @param[input] str_in string
 * @return uint32
 */
uint32_t Filtering::get_ipv4_int(const std::string& str_in)
{
    auto delimiter = '.';
    size_t initial_position{};
    uint32_t out_data = 0x0;
    uint32_t mask = 0xFF000000;
    for (short index = 3; index >= 0; --index)
    {
        size_t position = str_in.find(delimiter, initial_position);
        uint32_t numeric_string = std::stoi(str_in.substr(initial_position, position - initial_position));
        initial_position = position + 1;
        numeric_string <<= (index * 8);
        out_data |= numeric_string & mask;
        mask >>= 8;
    }
    return out_data;
}
/**
 * @brief sorting
 *
 * @param[input] src vector of strings
 */
void Filtering::sort_descending(vector<uint32_t>& src)
{
    std::sort(src.begin(), src.end(), [](uint32_t str1, uint32_t str2) {
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
    //     auto& src = this->input_lines;
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
        cout << std::nounitbuf << Filtering::get_ip_char_repr(anIp) << '\n';
    }
}

/*
void Filtering::printout()
{
    auto& src = (this->sequence) ? this->tmp_storage : this->input_lines;
    sort_descending(src);
    for (const auto& anIp : src)
    {
        cout << std::nounitbuf << anIp << '\n';
    }
}
*/
/**
 * @brief searches supplied byte on specified place. ANY - search in any byte
 *
 * @param[[TODO:direction]] str source ipv4 string
 * @param[[TODO:direction]] byte byte to search
 * @param[[TODO:direction]] place byte position in an IP
 * @return true if matches
 */
bool filter_by_byte(uint32_t input_inv4_as_uint32, uint8_t byte, BytePlace place)
{
    // convert string to number
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
            uint32_t Masked = (input_inv4_as_uint32 & ZerosMask) >> (index * 8); // mask off and shift right
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
bool compare_strings(uint32_t String1Number, uint32_t String2Number)
{

    uint32_t mask = 0xFF000000;
    for (short index = 3; index >= 0; index--)
    {
        auto shift = 8 * index;
        auto num1 = ((String1Number & mask) >> shift);
        auto num2 = ((String2Number & mask) >> shift);
        if (num1 < num2)
        {
            return true;
        }
        else if (num2 < num1)
        {
            return false;
        }
        // equal
        mask >>= 8;
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
