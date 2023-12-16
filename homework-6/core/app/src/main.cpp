#include "lib1.hpp"
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <format>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <vector>
#ifdef _VERSIONING
#include "version.h"
#endif

#ifndef __cplusplus
error C++ is required elif __cplusplus < 202002L error C++ 20 is required
#endif

    int
    main(int argc, char* argv[])
{
    AMatrix<int, 0> my_matrix{};
    size_t size_of_matrix = 10;
    size_t j = 0;
    for (size_t i = 0; i < size_of_matrix; i++)
    {
        for (j; j < size_of_matrix; j++)
        {
            if (j == i)
            {
                my_matrix[i][j] = j;
                std::cout << " " << my_matrix[i][j];
            }
            else if (j == (size_of_matrix - 1) - i)
            {
                my_matrix[i][j] = j;
                std::cout << " " << my_matrix[i][j];
            }
            else
                std::cout << " 0";
        }
        j = 0;
        std::cout << std::endl;
    }
    std::cout << "size " << my_matrix.size() << std::endl;
    return EXIT_SUCCESS;
}
void printout(AMatrix<int, 0>& m_matrix) {}