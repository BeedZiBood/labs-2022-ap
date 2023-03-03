#include "inputStr.h"
#include <limits>
#include <stdexcept>
#include "increaseLineSize.h"
char *inputStr(std::istream &str, size_t &in_size)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  size_t capasity = 10;
  size_t size = 0;
  char *timestr = nullptr;
  char *cstring = new char[capasity];
  str >> std::noskipws;
  do
  {
    if (size == capasity)
    {
      if (capasity == max_size)
      {
        delete [] cstring;
        throw std::runtime_error("Size of string more than max_size");
      }
      try
      {
        timestr = increaseSize(cstring, capasity, size);
        delete [] cstring;
        cstring = timestr;
        capasity += 20;
      }
      catch (...)
      {
        delete [] cstring;
        throw std::runtime_error("Memory error");
      }
    }
    str >> cstring[size];
  }
  while (str && cstring[size++] != '\n');
  if (!str && !size)
  {
    delete [] cstring;
    throw std::runtime_error("Input error");
  }
  in_size = size;
  cstring[size - 1] = '\0';
  if (cstring[0] == '\0')
  {
    delete [] cstring;
    throw std::runtime_error("Input error");
  }
  return cstring;
}
