#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

#include "classifier.hpp"
#include "helpers.hpp"

static const constexpr size_t RESERVE_SIZE = 1000;

int main(int argc, char *argv[]) {

  if (argc != 3) {
    std::cerr
        << "Usage (logistic regression): fashion_mnist <csv> <coef_file>\n";
    return EXIT_FAILURE;
  }
  if (!std::filesystem::exists(argv[1]) || !std::filesystem::exists(argv[2])) {
    std::cerr << "supplied files are not exist!\n";
    return EXIT_FAILURE;
  }

  // init files
  std::ifstream coeffFile(argv[2]);
  std::ifstream dataFile(argv[1]);

  // initialize logreg coeff
  std::vector<Classifier> vclassifier{};
  vclassifier.reserve(RESERVE_SIZE);
  for (Classifier::coeff_t coef; readCoeficients(coeffFile, coef);) {
    vclassifier.emplace_back(std::move(coef));
  }

  // process data
  Classifier::coeff_t features;
  features.reserve(RESERVE_SIZE);
  ssize_t targetCls{};
  std::size_t total{}, answersCount{};
  while (readFeatures(dataFile, features, targetCls)) {
    float maxRes = -1;
    ssize_t maxResultCls = 0;
    for (size_t i = 0; i < vclassifier.size(); i++) {
      try {
        if (auto result = vclassifier[i].predictProb(features);
            result > maxRes) {
          maxRes = result;
          maxResultCls = i;
        }
      } catch (...) {
        std::cerr << "error predict probability for this data\n";
      }
    }

    if (maxResultCls == targetCls) {
      answersCount++;
    }
    features.clear();
    ++total;
  }

  if (auto accuracy = static_cast<float>(answersCount) / total; total) {
    std::cout << "Model accuracy: " << accuracy << "\n";
  } else {
    std::cout << "wrong computation\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
