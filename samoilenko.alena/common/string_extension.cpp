#include "string_extension.h"
#include <cstddef>

char* expandString(const char* source, size_t extcapacity, size_t size, size_t capacity)
{
  char* newstr = new char[capacity + extcapacity];
  auto j = newstr;
  for (auto i = source; i != source + size; i++)
  {
    *j++ = *i;
  }
  return newstr;
}
