#pragma once
#include "model.hpp"
#include "shapes.hpp"
#include <memory>

class SomeLogger
{
}

class View
{
  public:
    explicit View(const std::shared_ptr<Model>);
    virtual ~View() = default;

    void connect_new_model(const std::shared_ptr<Model>& model)
    {
        m_the_model = model;
    }

    void add_shape(const std::shared_ptr<Shape>& shape)
    {
        auto if_valid = m_the_model->check_if_in_bounds(shape); // is ok...
        if (!if_valid)
        {
            // do something
        }
        m_the_model->add_shape(shape);
    }
    void remove_shape(const std::shared_ptr<Shape> shape)
    {
        m_the_model->remove_shape(shape->get_id());
    }
    bool draw_frame()
    {
        m_the_model->refresh();
    }
    void enable_logging()
    {
        // m_logger.enable();
    }

  private:
    std::shared_ptr<Model> m_the_model;
    SomeLogger m_logger; // logging backend
};