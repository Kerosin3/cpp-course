#ifndef EXAMPLE_LIB
#define EXAMPLE_LIB
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#endif

#ifdef _VERSIONING
#include "version.h"
#endif

[[maybe_unused]] int get_build_n();
