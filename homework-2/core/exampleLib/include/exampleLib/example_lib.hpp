#ifndef EXAMPLE_LIB
#define EXAMPLE_LIB
#include <algorithm>
#include <array>
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

class Filtering
{
    std::ifstream& cinstream;
    std::vector<std::string> input_lines;

  public:
    Filtering() = delete;
    Filtering(std::ifstream& cin_stream) : cinstream(cin_stream){};
    void somefunc();
    void printout();
};
// returns true is str1 <= str2 with atoi()
bool compare_strings(const std::string& str1, const std::string& str2);
