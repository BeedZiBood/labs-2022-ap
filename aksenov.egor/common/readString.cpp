#include "readString.h"
#include <stdexcept>
#include <iostream>
#include <limits>
#include "extendString.h"
char *readString(std::istream &inputStr, size_t &in_size, size_t (*p)(size_t))
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  inputStr >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        capacity = p(capacity);
        char *newStr = extendString(cstring, size, capacity);
        delete[] cstring;
        cstring = newStr;
      }
      catch (...)
      {
        delete[] cstring;
        throw;
      }
    }
    inputStr >> cstring[size];
  }
  while (inputStr && cstring[size++] != '\n');
  if (!inputStr && !size)
  {
    delete[] cstring;
    throw std::runtime_error("Input error");
  }
  cstring[size - 1] = '\0';
  in_size = size;
  return cstring;
}
