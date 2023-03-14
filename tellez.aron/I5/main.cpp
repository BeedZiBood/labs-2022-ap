#include <iostream>
#include <newCapacityCstring.h>
#include "isexpression.h"
int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  cstring[0] = '\0';
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char *newCString = makeNewCapacityCString(cstring, capacity, size);
        delete[] cstring;
        cstring = newCString;
        newCString = nullptr;
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << "\n";
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    std::cout << "Error while reading the string \n";
    delete[] cstring;
    return 2;
  }
  cstring[size - 1] = '\0';
  char* new_cstring = cstring;
  std::cout << std::boolalpha << isExpression(new_cstring) << "\n";
  delete[] cstring;
  return 0;
}
