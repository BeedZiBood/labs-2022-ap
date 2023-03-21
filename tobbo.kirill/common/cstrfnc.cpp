#include "cstrfnc.h"
#include <cmath>
#include <cstring>
#include <stdexcept>

std::pair< char*, size_t > getCString(std::istream& stream)
{
  size_t size = 0;
  size_t capacity = 10;
  char* str = new char[capacity + 1];
  str[0] = '\0';
  stream >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      capacity = static_cast< size_t >(capacity * std::sqrt(2));
      char* newstr = new char[capacity + 1];
      str[size] = '\0';
      std::strcpy(newstr, str);
      delete[] str;
      str = newstr;
    }
    stream >> str[size++];
  }
  while (std::cin && str[size - 1] != '\n');
  str[size - 1] = '\0';
  return std::make_pair(str, size);
}
