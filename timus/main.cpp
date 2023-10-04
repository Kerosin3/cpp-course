#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto main() -> int {}

int timus1001()
{
  std::istream& cinstream {std::cin};
  std::string InputLine;
  std::vector<int64_t> number;
  number.reserve(65535);
  while (std::cin >> InputLine) {
    try {
      auto num = (std::stoll(InputLine, nullptr, 0));
      number.push_back(num);
    } catch (...) {
      std::cout << "Error converting number" << std::endl;
      return EXIT_FAILURE;
    }
  }
  std::reverse(number.begin(), number.end());
  for (const auto& n : number) {
    printf("%.4Lf\n", sqrtl(n));
  }
  return EXIT_SUCCESS;
}
