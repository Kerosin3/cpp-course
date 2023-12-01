#pragma once
#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <optional>
#include <utility>
#include <vector>

namespace shapes_impl
{
// JUST TWO DIMENSIONS
struct SimpleCoordinate
{
    std::pair<int, int> coordinates;
    //
    explicit SimpleCoordinate(int x, int y) : coordinates{x, y} {}
    explicit SimpleCoordinate(std::pair<int, int> coord) : coordinates{coord} {}
};
// INTERFACE
class Shape
{
  public:
    explicit Shape() = default;
    virtual ~Shape() = default;
    virtual std::vector<SimpleCoordinate> get_coordinates() = 0;
    virtual bool is_correct()
    {
        return true;
    }
    virtual std::optional<bool> inverse()
    {
        return true;
    }

    virtual size_t get_serial()
    {
        return m_serial;
    }
    virtual void set_serial()
    {
        m_serial += 1;
    }

  protected:
    static inline size_t m_serial{};
};
// SIMPLE POINT
class Point : public Shape
{
  public:
    Point() = default;
    ~Point() override = default;
    explicit Point(int x, int y) : m_point_coord{std::pair<int, int>{x, y}}
    {
        set_serial();
    }
    virtual std::vector<SimpleCoordinate> get_coordinates() override
    {
        std::vector<SimpleCoordinate> vec1{};
        vec1.emplace_back(m_point_coord);
        return vec1;
    }
    std::pair<int, int> get_pair()
    {
        return m_point_coord;
    }

  private:
    std::pair<int, int> m_point_coord{};
};
// SIMPLE LINE
class Line : Shape
{
  public:
    Line() = default;
    ~Line() override = default;
    explicit Line(const Point& first_coord, const Point& second_coord)
        : m_first_point(first_coord), m_second_point(second_coord)
    {}
    virtual std::vector<SimpleCoordinate> get_coordinates() override
    {
        std::vector<SimpleCoordinate> vec_out{};
        vec_out.emplace_back(m_first_point.get_pair());
        vec_out.emplace_back(m_second_point.get_pair());
        return vec_out;
    }

  private:
    Point m_first_point;
    Point m_second_point;
};

class Rectangle : Shape
{
  private:
    std::array<Line, 4> m_lines;

  public:
    Rectangle() = delete;
    explicit Rectangle(std::array<Line, 4> linez) : m_lines(linez)
    {
        std::vector<SimpleCoordinate> vec_out;
        vec_out.reserve(10);
        for (const auto &lin : m_lines){
            auto x = vec_out.push_back(m_lines.begin()->get_coordinates());
        }
    }
};
} // namespace shapes_impl