#include <iostream>
#include <inputString.h>
#include "expression.h"

int main()
{
  size_t capacity = 10;
  char* cstring = nullptr;
  try
  {
    cstring = inputString(capacity, std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    delete[] cstring;
    return 1;
  }
  std::cout << std::boolalpha << isExpression(cstring) << '\n';
  delete[] cstring;
  return 0;
}
