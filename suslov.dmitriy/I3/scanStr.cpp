#include "scanStr.h"
#include <cstring>
#include <iostream>
char *expandString(const char *oldString, size_t oldSize, size_t delta)
{
  char *newStr = new char[oldSize + delta];
  std::strcpy(newStr, oldString);
  newStr[oldSize + delta - 1] = '\0';
  return newStr;
}
char *scanStr(size_t &length, std::istream &in)
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  cstring[capacity - 1] = '\0';
  length = 0;
  in >> std::noskipws;
  do
  {
    if (length + 1 == capacity)
    {
      char *newCstring = nullptr;
      try
      {
        newCstring = expandString(cstring, capacity, 20);
      }
      catch (const std::bad_alloc &)
      {
        delete[] cstring;
        throw;
      }
      capacity += 20;
      delete[] cstring;
      cstring = newCstring;
    }
    in >> cstring[length];
  }
  while (std::cin && cstring[length++] != '\n');
  if (length > 0)
  {
    cstring[length - 1] = '\0';
  }
  return cstring;
}
