#include <iostream>
#include <cstddef>
#include <FormingCstring.h>
#include "digit.hpp"

int main()
{
  size_t size = 0;
  char* cstring = nullptr;
  try
  {
    cstring = formingCstring(size, std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << '\n';
  delete[] cstring;
}
