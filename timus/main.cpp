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
    std::istream& cinstream{std::cin};
    std::string InputLine;
    std::vector<int64_t> number;
    number.reserve(65535);
    while (std::cin >> InputLine)
    {
        try
        {
            auto num = (std::stoll(InputLine, nullptr, 0));
            number.push_back(num);
        }
        catch (...)
        {
            std::cout << "Error converting number" << std::endl;
            return EXIT_FAILURE;
        }
    }
    std::reverse(number.begin(), number.end());
    for (const auto& n : number)
    {
        printf("%.4Lf\n", sqrtl(n));
    }
    return EXIT_SUCCESS;
}

// 1785
/*
const std::string decide(uint16_t input_num);
auto main() -> int
{
  int64_t A {};
  std::cin >> A;
  try {
    cout << decide(A) << endl;
  } catch (const out_of_range& err) {
    cout << err.what() << endl;
    return EXIT_FAILURE;
  } catch (...) {
    cout << "some error occured" << endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

const std::string decide(uint16_t input_num)
{
  static const char* const eng_str[] = {"few",
                                        "several",
                                        "pack",
                                        "lots",
                                        "horde",
                                        "throng",
                                        "swarm",
                                        "zounds",
                                        "legion"};
  if (input_num > 2000 || input_num == 0) {
    throw std::out_of_range("cant be more than 2000, less than 1");
  }
  if (input_num <= 4) {
    return eng_str[0];
  } else if (input_num <= 9) {
    return eng_str[1];
  } else if (input_num <= 19) {
    return eng_str[2];
  } else if (input_num <= 49) {
    return eng_str[3];
  } else if (input_num <= 99) {
    return eng_str[4];
  } else if (input_num <= 249) {
    return eng_str[5];
  } else if (input_num <= 499) {
    return eng_str[6];
  } else if (input_num <= 999) {
    return eng_str[7];
  } else
    return eng_str[8];
}
*/

/*
auto main() -> int
{
  uint16_t code1 {};
  uint16_t code2 {};
  std::cin >> code1;
  std::cin >> code2;
  uint16_t trief_code = 0;
  do {
    if ((trief_code % 2) == 0) {
      if (trief_code == code1) {
        cout << "yes" << endl;
        return 0;
      }
    } else if (trief_code == code2) {
      cout << "yes" << endl;
      return 0;
    }
    trief_code += 1;
  } while (trief_code < 9999);
  cout << "no" << endl;
}
*/
