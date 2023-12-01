#pragma once

#include "shapes.hpp"
#include <memory>

class Model
{
    static inline size_t m_width = {1000};
    static inline size_t m_height = {1000};
  public:
    using shape_ptr = shapes_impl::Shape;
    Model() = delete;
};