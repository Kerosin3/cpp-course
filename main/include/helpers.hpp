#pragma once
#include "classifier.hpp"
#include <cstddef>

using cdata_t = Classifier::data_t;

static bool readCoeficients(std::istream &istream,
                            std::vector<cdata_t> &coefs) {
  std::string str_line;
  if (!std::getline(istream, str_line)) {
    return false;
  }

  std::istringstream linestream{str_line};
  cdata_t value {};

  while (linestream >> value) {
    coefs.emplace_back(value);
  }

  return !istream.eof();
}
static bool readFeatures(std::istream &istream, std::vector<cdata_t> &feat_vec,
                         ssize_t &targetClass) {
  std::string str_line;
  if (!std::getline(istream, str_line)) {
    return false;
  }

  std::istringstream linestream(str_line);
  std::string str_data;
  size_t index = 0;

  while (std::getline(linestream, str_data, ',')) {
    try {
      if (index == 0) {
        targetClass = std::stoi(str_data);
      } else {
        feat_vec.push_back(std::stoi(str_data));
      }
    } catch (const std::invalid_argument &e) {
      std::cerr << "invalid number format in input : " << str_data << std::endl;
      return false;
    } catch (const std::out_of_range &e) {
      std::cerr << "number out of range: " << str_data << std::endl;
      return false;
    }
    ++index;
  }

  return !istream.eof();
}
