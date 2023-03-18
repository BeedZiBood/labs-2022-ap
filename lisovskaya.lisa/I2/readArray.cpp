#include "readArray.h"
#include <iostream>
std::istream & readArray(std::istream & in, size_t & line, int *array3)
{
  for (size_t i = 0; i < line; ++i)
  {
    in >> array3[i];
    if (!in)
    {
      return in;
    }
  }
  return in;
}
