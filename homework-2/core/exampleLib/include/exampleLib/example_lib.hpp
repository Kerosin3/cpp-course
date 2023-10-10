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
#include <stdexcept>
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
    std::vector<uint32_t> input_lines;
    std::vector<uint32_t> tmp_storage;
    bool sequence{false};

  public:
    Filtering() = delete;
    Filtering(std::istream& istream) : cinstream(istream){};
    void read_input();
    inline static void sort_descending(std::vector<uint32_t>&);
    void printout();
    void filter_this(uint8_t, BytePlace);
    uint32_t get_ipv4_int(const std::string&);
    std::string get_ip_char_repr(uint32_t);
    inline void reset_sequence()
    {
        this->tmp_storage.clear();
        this->sequence = false;
    }
    static constexpr size_t string_size = 17;
};

// comparing strings with ipv4
bool compare_strings(uint32_t, uint32_t);

// true if specified byte position matches specified byte value
bool filter_by_byte(uint32_t, uint8_t byte, BytePlace place);

// convert ipv4 string with . delimiter to hex representation
uint32_t convert(const std::string& ipv4Str);
