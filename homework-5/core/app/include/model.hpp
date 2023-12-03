#pragma once

#include "shapes.hpp"
#include <memory>
#include <utility>

using namespace shapes_impl;
class Model
{
    using vec_shape_p = std::vector<std::shared_ptr<Shape>>;
    using shape_ptr = shapes_impl::Shape;

  public:
    Model() = delete;
    virtual ~Model() = default;

    Model(const Rectangle& basic_model_area) : m_bonds_constrains(std::move(basic_model_area)) {}
    // проверить вписывается ли фигура
    bool check_if_in_bounds(const std::shared_ptr<Shape>& Shape) const noexcept
    {
        return true;
    }
    // удаление примитива
    bool remove_shape(long long id_to_remove) noexcept
    {
        // что то делаем
        return true;
    }
    // добавление примитива
    bool add_shape(const std::shared_ptr<Shape>& shape_to_add)
    {
        shape_to_add->set_id(shapes_impl::Shape::m_serial - 1); // fix this
        shape_to_add->activate_id(shape_to_add->get_id());
        m_shapes_storage.push_back(shape_to_add); // push to storage
        return true;
    }
    // очистка всего поля
    void clear() noexcept;
    // обновить всё
    void refresh() noexcept;
    // получить ид по объекта по точке
    int get_shape_at_point(const Point& some_point) noexcept;
    // получить размерность текущего документа
    std::pair<int, int> get_model_dim() const noexcept;

  private:
    vec_shape_p m_shapes_storage;
    Rectangle m_bonds_constrains;
};