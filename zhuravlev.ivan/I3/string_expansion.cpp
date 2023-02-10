#include "string_expansion.h"
#include <cstring>

char* stringExpansion(const char* str, size_t capacity, size_t new_capacity)
{
  char* new_str = new char[capacity + new_capacity];
  std::strcpy(new_str, str);
  return new_str;
}
