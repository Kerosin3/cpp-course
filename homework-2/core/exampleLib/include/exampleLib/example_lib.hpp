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

enum class BytePlace : unsigned
{
    forth = 0x1,
    third = 0x2,
    second = 0x4,
    first = 0x8,
    any = 0xf
};

class Filtering
{
    std::istream& cinstream;
    std::vector<std::string> input_lines;
    std::vector<std::string> tmp_storage;
    bool sequence{false};

  public:
    Filtering() = delete;
    Filtering(std::istream& istream) : cinstream(istream){};
    void read_input();
    inline static void sort_descending(std::vector<std::string>&);
    void printout();
    void filter_this(uint8_t, BytePlace);
    //     std::array<uint8_t, 4> get_ipv4_int(const string&);
    inline void reset_sequence()
    {
        this->tmp_storage.clear();
        this->sequence = false;
    }
};

std::array<uint8_t, 4> get_ipv4_int(const std::string&);
// comparing strings with ipv4
bool compare_strings(const std::string& str1, const std::string& str2);

// true if specified byte position matches specified byte value
bool filter_by_byte(const std::string& str, uint8_t byte, BytePlace place);

// convert ipv4 string with . delimiter to hex representation
uint32_t convert(const std::string& ipv4Str);
