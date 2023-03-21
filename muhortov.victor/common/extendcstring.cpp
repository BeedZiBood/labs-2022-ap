#include "extendcstring.hpp"
#include <cstring>

char *extendCString(const char *c_string, size_t &capacity)
{
  char *newstr = new char[capacity + 10];
  std::strcpy(newstr, c_string);
  capacity += 10;

  return newstr;
}
