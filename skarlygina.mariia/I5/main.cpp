#include <iostream>
#include <iomanip>
#include <exception>
#include <cstring_capacity.h>
#include <extended_string.h>
#include "is_float_digit.h"

int main()
{
  char* digit_string = nullptr;
  try
  {
    std::pair< size_t, char* > result = makeNewCString(std::cin);
    digit_string = result.second;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  std::cout << std::boolalpha << isFloatDigit(digit_string) << '\n';
  delete[] digit_string;
  return 0;
}
