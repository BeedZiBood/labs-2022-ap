#include "makecsting.h"
#include <stdexcept>
#include <istream>
#include <cstring>

char* makeCSting(std::istream& in)
{
  size_t cap = 10;
  char* cstring = new char[cap];
  size_t size = 0;
  in >> std::noskipws;
  do
  {
    if (size == cap - 1)
    {
      try
      {
        cstring[cap - 1] = '\0';
        char *newstr = new char[cap + 20];
        std::strcpy(newstr, cstring);
        delete[] cstring;
        cstring = newstr;
        cap += 20;
      }
      catch (...)
      {
        delete[] cstring;
      }
    }
    in >> cstring[size];
  }
  while (in && cstring[size++] != '\n');
  if (size == 0)
  {
    delete[] cstring;
    throw std::runtime_error("Empty string");
  }
  else
  {
    cstring[size - 1] = '\0';
    return cstring;
  }
}
