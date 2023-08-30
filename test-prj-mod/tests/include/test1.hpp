#ifndef TEST1
#define TEST1
#include "fmt/core.h"
#include "iostream"
#include "vector"
#include <string>
#endif

struct TestMe
{
    int some_int = 0;
    TestMe() = default;
    ~TestMe() = default;
    int get_some() const;
    void set_some(int arg);
};

enum class ShapeType
{
    circle,
    square,
    def,
    rectangle,
};

class Shape
{
  public:
    ShapeType st;
    int width;
    int height;
    void set_h(int arg1);
    void set_w(int arg1);
    int get_h() const;
    int get_w() const;
    virtual ShapeType return_my_shape();
};

class Rectangle : public Shape
{
    int area;

  public:
    Rectangle() ;
    void set_area();
    void printarea() const;
    int get_area() const;
    ShapeType return_my_shape() override;
};