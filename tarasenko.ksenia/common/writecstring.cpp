#include "writecstring.hpp"
#include <stdexcept>
#include <extendcstring.hpp>

char * writeCString(std::istream & input)
{
  size_t capacity = 10;
  char * cstring = new char[capacity];
  cstring[0] = '\0';
  size_t size = 0;
  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        cstring = extendCString(cstring, capacity, size);
      }
      catch (const std::exception & e)
      {
        delete [] cstring;
        throw;
      }
    }
    input >> cstring[size];
  }
  while (input && cstring[size++] != '\n');
  if (input && !size)
  {
    delete [] cstring;
    throw std::runtime_error("Error");
  }
  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    delete [] cstring;
    throw std::invalid_argument("Empty string");
  }
  cstring[size - 1] = '\0';
  return cstring;
}
