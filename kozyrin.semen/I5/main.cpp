#include <iostream>
#include <InputString.h>
#include "IsReal.h"

int main()
{
  size_t size = 0;
  char* str = nullptr;
  try {
    str = inputString(std::cin, size);
  }
  catch (const std::bad_alloc & err) {
    std::cerr << "Problem with input stream";
    return 1;
  }
  if (size == 1) {
    std::cerr << "Empty string";
    delete[] str;
    return 2;
  }
  std::cout << std::boolalpha << isReal(str) << '\n';
  delete[] str;
}
