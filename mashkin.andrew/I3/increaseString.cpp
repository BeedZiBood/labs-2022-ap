#include "increaseString.h"
#include <cstddef>

char* increaseString(const char* string1, size_t capacity, size_t size, size_t increaseCapacity)
{
  char* newStr = new char[capacity + increaseCapacity];
  char* j = newStr;
  for (const char* i = string1; i != string1 + size; ++i, ++j)
  {
    *j = *i;
  }
  return newStr;
}
