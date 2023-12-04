#pragma once
#include <array>
#include <cstddef>
#include <exception>
#include <expected>
#include <iostream>
#include <iterator>
#include <map>
#include <optional>
#include <stdexcept>
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
// store serials for primitives
struct Identification
{
    static inline long long m_serial{0};
    static inline std::map<long long, bool> m_id_db;
    long long m_id{};

    Identification() noexcept
    {
        m_serial += 1;
    }

    bool set_id(long long id_to_set)
    {

        if (m_id_db.contains(id_to_set))
        {
            return false;
        }
        else
            m_id_db.insert({id_to_set, false});
        m_id = id_to_set;
        return true;
    }
    long long get_id() const noexcept
    {
        return m_id;
    }
    bool activate_id(long long id_to_activate)
    {

        if (m_id_db.contains(id_to_activate))
        {
            m_id_db.find(id_to_activate)->second = true;
            return true;
        }
        else
            return false;
    }
};

// INTERFACE
class Shape : public Identification
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
};
// SIMPLE POINT
class Point : public Shape
{
  public:
    Point() = default;

    ~Point() override = default;

    explicit Point(int x, int y) : m_point_coord{std::pair<int, int>{x, y}} {}

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
class Line : public Shape
{
  public:
    Line() : m_first_point(Point{0, 0}), m_second_point(Point{1, 1}) {}
    ~Line() override = default;
    explicit Line(Point& first_coord, Point& second_coord)
        : m_first_point(first_coord), m_second_point(second_coord)
    {}
    virtual std::vector<SimpleCoordinate> get_coordinates() override
    {
        std::vector<SimpleCoordinate> vec_out{};
        vec_out.emplace_back(m_first_point.get_pair());
        vec_out.emplace_back(m_second_point.get_pair());
        return vec_out;
    }

    SimpleCoordinate get_beginning()
    {
        return SimpleCoordinate{m_first_point.get_pair()};
    }
    SimpleCoordinate get_ending()
    {
        return SimpleCoordinate{m_second_point.get_pair()};
    }

  private:
    Point m_first_point;
    Point m_second_point;
};

class Rectangle : public Shape
{
  private:
    std::array<Line, 4> m_lines;

  public:
    Rectangle() = delete;
    ~Rectangle() override = default;
    Rectangle(SimpleCoordinate coordinate)
    {
        // do something simple
        m_lines = {Line{}, Line{}, Line{}, Line{}};
    }
    explicit Rectangle(std::array<Line, 4> linez) : m_lines(linez) {}

    virtual std::vector<SimpleCoordinate> get_coordinates() override
    {
        std::vector<SimpleCoordinate> vec_out;
        vec_out.reserve(8);
        for (auto& lin : m_lines)
        {
            vec_out.emplace_back(lin.get_beginning());
            vec_out.emplace_back(lin.get_ending());
        }
        return vec_out;
    }
};
} // namespace shapes_impl