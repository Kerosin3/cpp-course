#include "exampleLib/example_lib.hpp"
#include <iostream>
#include <list>
#include <memory>
#include <type_traits>
#include <vector>

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

    return EXIT_SUCCESS;
}
