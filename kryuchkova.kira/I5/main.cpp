#include <iostream>
#include <cstddef>
#include <utility>
#include <input_string.h>
#include "expression.h"

int main()
{
  try
  {
    std::pair< size_t, char * > cstring_pair = inputString(std::cin);
    char *cstring = cstring_pair.second;
    size_t capacity = cstring_pair.first;
    if (cstring[0] == '\0')
    {
      std::cout << "empty string";
      delete[] cstring;
      return 1;
    }
    cstring[capacity - 1] = '\0';
    std::cout << std::boolalpha << isExpression(cstring) << '\n';
    delete[] cstring;
  }
  catch (const std::exception &e)
  {
    std::cout << e.what();
    return 1;
  }
}
