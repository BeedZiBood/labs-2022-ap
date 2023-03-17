#include <iostream>
#include <string_from_input.h>
#include "IsItExpression.h"

int main()
{
  char* inp = nullptr;
  try
  {
    inp = makeStringFromInput(std::cin);
    if (inp[0] == '\0')
    {
      throw std::logic_error("String is empty");
    }
  }
  catch(const std::exception &ex)
  {
    std::cerr << ex.what() << '\n';
    delete[] inp;
    return 1;
  }
  std::cout << std::boolalpha << outResult(inp) << '\n';
  delete inp;
  return 0;
}