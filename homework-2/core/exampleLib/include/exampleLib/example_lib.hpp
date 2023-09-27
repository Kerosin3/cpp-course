#ifndef EXAMPLE_LIB
#define EXAMPLE_LIB
#include <algorithm>
#include <array>
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <vector>
#endif

#ifdef _VERSIONING
#include "version.h"
#endif

using namespace std;
// specity which byte from ip to test
enum BytePlace : unsigned short
{
    first = 0x1,
    second = 0x2,
    third = 0x4,
    forth = 0x8,
};

class Filtering
{
    std::ifstream& cinstream;
    std::vector<std::string> input_lines;

  public:
    Filtering() = delete;
    Filtering(std::ifstream& cin_stream) : cinstream(cin_stream){};
    void read_input();
    void sort_descending();
    void printout();
    void printout(uint8_t, unsigned short);
};

// returns true is str1 <= str2 using atoi()
bool compare_strings(const std::string& str1, const std::string& str2);

// true if specified byte position matches specified byte value
bool filter_by_byte(const std::string& str, uint8_t byte, unsigned short place);

// convert ipv4 string with . delimiter to hex representation
inline uint32_t convert(const std::string& ipv4Str)
{
    std::istringstream iss(ipv4Str);

    uint32_t ipv4 = 0;

    for (uint32_t i = 0; i < 4; ++i)
    {
        uint32_t part;
        iss >> part;
        ipv4 |= part << (8 * (3 - i));
        if (i != 3)
        {
            char delimiter;
            iss >> delimiter;
        }
    }
    return ipv4;
}
