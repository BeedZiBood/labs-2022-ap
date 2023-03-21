#include "ReadString.h"
#include <cstddef>

char* readString(std::istream& in)
{
  size_t size = 0;
  size_t capacity = 10;
  char* cstring = new char[capacity];
  in >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        capacity *= 2;
        char* newstr = new char[capacity];
        for (auto i = cstring, j = newstr; i != (cstring + size); ++i, ++j)
        {
          *j = *i;
        }
        delete[] cstring;
        cstring = newstr;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] cstring;
        throw;
      }
    }
    in >> cstring[size];
  }
  while (in && cstring[size++] != '\n');
  if (size <= 1)
  {
    delete[] cstring;
    throw std::invalid_argument("Nothing was entered!\n");
  }
  cstring[size - 1] = '\0';
  return cstring;
}
