#include <iostream>
#include <cstddef>
#include <createCString.h>
#include "isFloat.h"

int main()
{
  char* string = nullptr;
  size_t capacity = 10;
  size_t size = 0;
  try
  {
    string = createCString(std::cin, size, capacity);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    delete[] string;
    return 1;
  }
  std::cout << std::boolalpha << isFloat(string) << "\n";
  delete[] string;
  return 0;
}
