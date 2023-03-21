#include "newCapacityCstring.h"
#include <iostream>
#include <cstddef>
char* makeNewCapacityCString(char* cstring, size_t& capacity, size_t size)
{
  char* newstring = new char[capacity + 20];
  for (auto i = cstring, j = newstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  capacity += 20;
  return newstring;
}
