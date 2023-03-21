#include <stdexcept>
#include <istream>
#include <cstddef>
#include "inputstring.h"

char * inputString(std::istream & input)
{
  size_t capacity = 10;
  char * cstring = new char[capacity];
  size_t size = 0;
  cstring[0] = '\0';
  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char * newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete [] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete [] cstring;
        throw;
      }
    }
    input >> cstring[size];
  }
  while (input && cstring[size++] != '\0');
  if (cstring[0] == '\0')
  {
    delete [] cstring;
    throw std::logic_error("Empty string");
  }
  cstring[size] = '\0';
  return cstring;
}
