#include <iostream>
#include <cstddef>
#include <inputStr.h>
#include "isExpression.h"
int main()
{
  char *str = nullptr;
  size_t size = 0;
  try
  {
    str = inputStr(std::cin, size);
  }
  catch (...)
  {
    std::cerr << "Error" << "\n";
    return 2;
  }
  std::cout << std::boolalpha << isExpression(str) << "\n";
  delete [] str;
  return 0;
}
