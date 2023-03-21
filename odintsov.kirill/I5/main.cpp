#include <iostream>
#include <stdexcept>
#include "CStringWrapper.hpp"
#include "isRealNumber.hpp"

int main()
{
  std::cin >> std::noskipws;
  try {
    odintsov::CStringWrapper string(10);
    char c = '\0';
    do {
      std::cin >> c;
      if (c == '\n' || c == '\0') {
        break;
      }
      string.append(c);
    } while (std::cin);
    if (string.arrSize == 1) {
      std::cout << "Error: Empty string\n";
      return 1;
    }
    std::cout << std::boolalpha << odintsov::isRealNumber(string.str) << '\n';
  } catch (const std::exception& err) {
    std::cout << "Error: " << err.what() << '\n';
    return 1;
  }
}
