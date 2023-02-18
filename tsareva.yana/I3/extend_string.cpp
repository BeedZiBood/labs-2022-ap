#include "extend_string.h"
#include <stdexcept>

char * extendString(char * str_1, size_t capacity, size_t new_capacity)
{
  if (new_capacity < capacity )
  {
    throw std::invalid_argument("bruh");
  }
  char * new_str = new char[new_capacity];
  auto * i = str_1;
  auto * j = new_str;
  while (i != str_1 + capacity)
  {
    *(j++) = *(i++);
  }
  return new_str;
}

