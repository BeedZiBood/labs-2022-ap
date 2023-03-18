#include <iostream>
#include <makeString.h>
#include "isRealNumber.h"

int main()
{
  size_t size = 0;
  size_t capacity = 10;
  char* cstring = nullptr;
  try
  {
    cstring = makeCstring(capacity, size, std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << "\n";
  delete[] cstring;
  return 0;
}
