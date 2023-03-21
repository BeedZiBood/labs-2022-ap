#include "extended_string.h"
#include <cstring>

char* makeExtendedString(char* cstring, size_t& capacity)
{
  char* newstring = new char[capacity + 20];
  cstring[capacity - 1] = '\0';
  std::strcpy(newstring, cstring);
  capacity += 20;
  return newstring;
}
