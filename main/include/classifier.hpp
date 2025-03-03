#pragma once

#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

class Classifier {
public:
  using data_t = float;
  using coeff_t = std::vector<data_t>;

  explicit Classifier(coeff_t &&coef);
  [[nodiscard]] data_t predictProb(const coeff_t &) const;

private:
  coeff_t m_coef;
};
