#include <iostream>
#include <readString.h>
#include "isFloat.h"
#include "increaseCapacityMultiply2.h"
int main()
{
  size_t size = 0;
  char *cstr = nullptr;
  try
  {
    cstr = readString(std::cin, size, increaseCapacityMultiply2);
  }
  catch (...)
  {
    std::cerr << "ERROR" << "\n";
    return 2;
  }
  std::cout << std::boolalpha << isFloat(cstr) << "\n";
  delete[] cstr;
}
