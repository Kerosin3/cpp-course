#include "exampleLib/example_lib.hpp"
using namespace std;

[[maybe_unused]] int get_build_n()
{
    return EXAMPLELIB_PATCH_VERSION;
};
