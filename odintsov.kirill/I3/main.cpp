#include <iostream>
#include <stdexcept>
#include "cstr.hpp"

int main()
{
  constexpr size_t cap = 10;
  odintsov::CStringWrapper cstr(cap);
  std::cin >> std::noskipws;
  try {
    char c = '\0';
    do {
      std::cin >> c;
      if (c == '\n' || c == '\0') {
        break;
      }
      cstr.append(c);
    } while (std::cin);
    if (cstr.size <= 1) {
      std::cout << "Error: Empty string" << '\n';
      return 1;
    }
    {
      odintsov::CStringWrapper cstrNoLatin(cstr.size);
      std::cout << odintsov::removeLatin(cstrNoLatin.str, cstr.str) << '\n';
    }
    {
      odintsov::CStringWrapper cstrNoVowels(cstr.size);
      std::cout << odintsov::removeVowels(cstrNoVowels.str, cstr.str) << '\n';
    }
  } catch (const std::invalid_argument& err) {
    std::cout << "Error: " << err.what() << '\n';
    return 1;
  }
}
