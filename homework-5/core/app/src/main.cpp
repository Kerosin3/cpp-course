#include "controller.hpp"
#include "model.hpp"
#include "shapes.hpp"
#include "view.hpp"
#include <cstddef>
#include <iostream>
#include <list>
#include <map>
#include <memory>
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

    // https://www.bogotobogo.com/DesignPatterns/mvc_model_view_controller_pattern.php
    using namespace std;
int main(int argc, char* argv[])
{
    cout << "program starts" << endl;
    // просто прямоугольник 100 на 100
    auto ModelRectangle = shapes_impl::Rectangle{SimpleCoordinate{100, 100}};
    // создадим модель с такими границами
    auto BaseModelSp = std::make_shared<Model>(Model{ModelRectangle});
    // прикрепим вью к модели
    auto View1 = std::make_shared<View>(View{BaseModelSp});
    // создадим контроллер
    auto UserController = Controller_UI{View1};
    // создадим проект
    auto ProjectTest = Project();
    // присоединим к модели
    UserController.set_view(View1);
    // включим логгинг
    UserController.ui_enable_logging();
    //----------------------------------------------
    // создадим примитив
    auto Rectangle1 = std::make_shared<Rectangle>(shapes_impl::Rectangle{SimpleCoordinate{10, 10}});
    // добавим примитив
    UserController.add_shape(Rectangle1);
    // создадим точку
    auto Point1 = std::make_shared<Point>(shapes_impl::Point{1, 2});
    // добавим точку
    UserController.add_shape(Point1);
    // создадим линию
    const std::shared_ptr<Line> linexyz = std::make_shared<shapes_impl::Line>(shapes_impl::Line());
    // добавим линию
    UserController.add_shape(linexyz);
    // проверим что всё установленное ок
    UserController.ui_test_setup();
    // нарисуем
    UserController.ui_draw_frame();
    // сохраним проект
    ProjectTest.export_project(UserController, "project_name.prj");

    return EXIT_SUCCESS;
}
