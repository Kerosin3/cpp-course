#pragma once
#include "memory"
#include "model.hpp"
#include <iostream>
#include <fstream>

namespace Project{
     bool export_project(const std::shared_ptr<Model>& model,std::string filename );
}