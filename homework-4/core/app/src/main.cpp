#include "lib1.hpp"
#include <exampleLib/example_lib.hpp>
#include <iostream>

#ifdef _VERSIONING
#include "version.h"
#endif

#ifndef __cplusplus
#error C++ is required
#elif __cplusplus < 202002L
#error C++20 is required
#endif

using namespace std;

int main(int argc, char* argv[])
{
    Filtering filter1(std::cin);
    filter1.read_input();
    filter1.printout();
    filter1.reset_sequence();

    filter1.filter_this(1, BytePlace::first);
    filter1.printout();
    filter1.reset_sequence();

    filter1.filter_this(70, BytePlace::second);
    filter1.filter_this(46, BytePlace::first);
    filter1.printout();
    filter1.reset_sequence();

    filter1.filter_this(46, BytePlace::any);
    filter1.printout();
    filter1.reset_sequence();
    return EXIT_SUCCESS;
}
