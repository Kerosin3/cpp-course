#include "classifier.hpp"

Classifier::Classifier(coeff_t &&coef) : m_coef{std::move(coef)} {
  assert(!m_coef.empty() && "an empty coeff vector was supplied, aborting");
}

Classifier::data_t Classifier::predictProb(const coeff_t &f_data) const {
  static auto sigma_func = [](Classifier::data_t var) { return 1 / (1 + std::exp(-var)); };
  if (f_data.size() + 1 != m_coef.size()) {
    throw std::runtime_error("feature data vector wrong size!");
  }
  return sigma_func(std::inner_product(
      f_data.begin(), f_data.end(), std::next(m_coef.begin()), m_coef.front()));
}
