#include "input_string.h"
#include <iostream>
#include <utility>
#include <cstddef>
#include <stdexcept>
#include <cstring>

std::pair< size_t, char * > inputString(std::istream &in)
{
  size_t size = 0;
  size_t capacity = 10;
  char *cstring = new char[capacity];
  cstring[0] = '\0';
  in >> std::noskipws;

  do
  {
    if (size == capacity)
    {
      try
      {
        char *newstr = new char[capacity + 20];
        cstring[size - 1] = '\0';
        const char *newstr_1 = cstring;
        std::strcpy(newstr, newstr_1);
        delete[] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cstring;
        throw;
      }
    }
    in >> cstring[size];
  }
  while (in && cstring[size++] != '\n');
  capacity = size;
  return std::make_pair(capacity, cstring);
}
