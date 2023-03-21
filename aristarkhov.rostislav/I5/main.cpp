#include <iostream>
#include <createCString.h>
#include "isReal.h"

int main()
{
  char* cstring = nullptr;
  try
  {
    cstring = createCString(std::cin);
    if (cstring[0] == '\0')
    {
      delete[] cstring;
      throw std::logic_error("Empty input");
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << isReal(cstring) << '\n';
  delete[] cstring;

  return 0;
}
