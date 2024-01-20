#include "lib1.hpp"
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <format>
#include <iostream>
#include <sstream>
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
    constexpr int size_of_matrix = 10;
    int j = 0;
    std::stringstream stream_out;
    // assign matrix with 20 values
    for (int i = 0; i < size_of_matrix; i++)
    {
        for ( ;j < size_of_matrix; j++)
        {
            // if direct or reverse diagonal -> assign and print
            if ((j == i) || (j == (size_of_matrix - 1) - i))
            {
                my_matrix[i][j] = j;
                // write assigned values
                stream_out << std::format(" [{}][{}]=>{}\n", i, j, my_matrix[i][j]);
                // skip printing riest and last row and column
                if (!(i == 0 || i == (size_of_matrix - 1) || j == 0 || j == (size_of_matrix - 1)))
                    std::cout << " " << my_matrix[i][j];
            }
            else
            {
                // skip printing riest and last row and column
                    if (!(i == 0 || i == (size_of_matrix - 1) || j == 0 || j == (size_of_matrix - 1)))
                        std::cout << " 0";
            }
        }
        j = 0;
        std::cout << std::endl;
    }
    std::cout << stream_out.str() << std::endl;
    std::cout << " size of matrix (non-default values): " << my_matrix.get_size() << std::endl;
    return EXIT_SUCCESS;
}