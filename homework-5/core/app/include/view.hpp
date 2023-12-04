#pragma once
#include "model.hpp"
#include "shapes.hpp"
#include <memory>
#include <utility>

// some logger
class SomeLogger
{
};

class View
{
  public:
    explicit View(std::shared_ptr<Model> model) : m_the_model(std::move(model)) {}
    View() = delete;
    virtual ~View() = default;

    void connect_new_model(const std::shared_ptr<Model>& model)
    {
        m_the_model = model;
    }
    bool test_if_setup_valid()
    {
        return m_the_model->test_frame_ok();
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
    void remove_shape(long long id)
    {
        m_the_model->remove_shape(id);
    }
    bool draw_frame()
    {
        m_the_model->refresh();
        return true;
    }
    void enable_logging()
    {
        // m_logger.enable();
    }

  private:
    std::shared_ptr<Model> m_the_model;
    SomeLogger m_logger; // logging backend
};