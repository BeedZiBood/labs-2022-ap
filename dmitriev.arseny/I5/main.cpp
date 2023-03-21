#include <iostream>
#include <cstddef>
#include <cStrFromInput.h>
#include "isExpression.h"

int main()
{
  char* cStr = nullptr;
  try
  {
    cStr = createCStrFromInput(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  std::cout << std::boolalpha << isMathExpr(cStr) << '\n';

  delete[] cStr;

  return 0;
}
