#include <iostream>
#include <cstring>
#include <stdexcept>
#include <myString.h>
#include "isRealNumber.h"

int main()
{
  size_t size = 0, capacity = 10;
  char* myString = makeMyString(size, capacity, std::cin);

  if (myString[0] == '\n')
  {
    std::cout << "Empty string";
    delete[] myString;
    return 2;
  }
  std::cout << std::boolalpha << isRealNumber(myString) << "\n";
  delete[] myString;
  return 0;
}
