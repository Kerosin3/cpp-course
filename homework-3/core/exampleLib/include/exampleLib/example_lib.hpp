#ifndef EXAMPLE_LIB
#define EXAMPLE_LIB

#include <iostream>
#include <type_traits>
#endif

extern "C"
{
#include "mallocz/mallocz.h"
}

#ifdef _VERSIONING
#include "version.h"
#endif

using namespace std;

inline uint8_t** func1(int jmax, int imax)
{
    return malloc2D(jmax, imax);
}
