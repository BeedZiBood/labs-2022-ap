#include <iostream>
#include <inputString.h>
#include "isFloat.h"
int main()
{
  size_t c = 0;
  char *arr = scanStr(c, std::cin);
  if (c > 0)
  {
    std::cout << std::boolalpha << isReal(arr) << "\n";
  }
  else
  {
    std::cerr << "Error";
    delete[] arr;
    return 1;
  }
  delete[] arr;
  return 0;
}
