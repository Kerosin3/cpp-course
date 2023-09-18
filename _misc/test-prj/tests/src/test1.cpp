#include "test1.hpp"
#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>

int TestMe::get_some() const
{
    fmt::println("test result");
    return this->some_int;
}

void TestMe::set_some(int arg)
{
    this->some_int = arg;
}
//--------------------------------------------------
void Shape::set_h(int arg1)
{
    this->height = arg1;
}
void Shape::set_w(int arg1)
{
    this->width = arg1;
}

int Shape::get_h() const
{
    fmt::println("height is {}", this->height);
    return this->height;
}
int Shape::get_w() const
{
    fmt::println("height is {}", this->width);
    return this->width;
}

ShapeType Shape::return_my_shape()
{
    fmt::println("default class function");
    return this->st;
}

//--------------------------------------------------
void Rectangle::set_area()
{
    this->area = this->get_h() * this->get_w();
}
void Rectangle::printarea() const
{
    fmt::println("are is {}", this->area);
}
int Rectangle::get_area() const
{
    return this->area;
}

ShapeType Rectangle::return_my_shape()
{
    fmt::println("Rectangle class function");
    return this->st;
}

Rectangle::Rectangle()
{
    fmt::println("default rectange constructor was called");
    this->st = ShapeType::rectangle;
    this->area = 0;
    this->height = 0;
    this->width = 0;
}
