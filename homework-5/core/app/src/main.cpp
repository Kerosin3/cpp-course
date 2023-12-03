#include "model.hpp"
#include "shapes.hpp"
#include <cstddef>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <vector>
#ifdef _VERSIONING
#include "version.h"
#endif

#ifndef __cplusplus
error C++ is required elif __cplusplus < 202002L error C++ 20 is required
#endif

//https://www.bogotobogo.com/DesignPatterns/mvc_model_view_controller_pattern.php
using namespace std;
int main(int argc, char* argv[])
{
    cout << "program starts" << endl;
    // просто прямоугольник 100 на 100
    auto ModelRectangle = shapes_impl::Rectangle{SimpleCoordinate{100, 100}};
    // создадим модель с такими границами
    auto BaseModel = Model{ModelRectangle};
    // создадим примитив
    // auto rectangle1 = shapes_impl::Rectangle{SimpleCoordinate{10,10}};    
    // добавим приметив в модель
    // BaseModel.add_shape(rectangle1);

    
    return EXIT_SUCCESS;
}
