#pragma once
#include "model.hpp"
#include "shapes.hpp"
#include "view.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <string_view>

class Controller_UI
{
    friend struct Project;

  public:
    Controller_UI() = delete;
    // создать контроллер
    explicit Controller_UI(std::shared_ptr<View>& view)
    {
        set_view(view);
        //    this->create_project("/tmp/default_project.prj");
    }
    // установим view
    void set_view(std::shared_ptr<View>& view)
    {
        m_view = view;
    }

    // добавить фигуру
    bool add_shape(const std::shared_ptr<Shape>& shape_to_add)
    {
        m_view->add_shape(shape_to_add);
        return true;
    }
    // удалить фигуру
    bool remove_shape(long long id)
    {
        m_view->remove_shape(id);
    }
    // прорисовать кадр
    void ui_draw_frame()
    {
        m_view->draw_frame();
    }
    // включить логгинг
    void ui_enable_logging()
    {
        m_view->enable_logging();
    }
    // проверим что всё ок
    bool ui_test_setup()
    {
        return m_view->test_if_setup_valid();
    }

  private:
    std::shared_ptr<View> m_view;
};

struct Project
{
    Project() = default;
    ~Project() = default;
    // создать проект
    void create_project(const Controller_UI& controller, std::string_view path) {}
    // сохранить проект
    bool export_project(const Controller_UI& controller, std::string_view filename)
    {
        std::cout << "dumped project to file: " << filename << std::endl;
        return true;
    }
    // импорт проекта
    void import_project(const Controller_UI& controller, std::string_view project_to_import) {}
}; // namespace Project
