#include <iostream>
#include <MakeCString.hpp>
#include "IsExpression.hpp"

int main()
{
  size_t cstring_size = 0;
  size_t cstring_capacity = 10;
  char *cstring = nullptr;
  try
  {
    cstring = new char[cstring_capacity];
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << "Error:\n" << e.what();
    return 1;
  }
  cstring[cstring_size] = '\n';
  try
  {
    cstring = makeCString(cstring, cstring_size, cstring_capacity, std::cin);
    if (cstring[0] == '\n')
    {
      std::cout << "Error, empty string";
      delete[] cstring;
      return 2;
    }
    cstring[cstring_size - 1] = '\0';
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << "Error:\n";
    std::cout << e.what();
    delete[] cstring;
    return 1;
  }
  std::cout << std::boolalpha << isExpression(cstring) << "\n";
  delete[] cstring;
}
