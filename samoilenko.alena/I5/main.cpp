#include "IsItExpression.h"
#include <iostream>
#include <string_from_input.h>

int main()
{
  char *cstr = nullptr;
  try
  {
    cstr = makeStringFromInput(std::cin);
    if (cstr[0] == '\0')
    {
      throw std::logic_error("String is empty");
    }
  }
  catch (const std::exception &ex)
  {
    std::cerr << ex.what() << '\n';
    delete[] cstr;
    return 1;
  }
  std::cout << std::boolalpha << examExpression(cstr) << '\n';
  delete[] cstr;
  return 0;
}
