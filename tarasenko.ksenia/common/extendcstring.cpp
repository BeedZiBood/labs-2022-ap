#include "extendcstring.hpp"
#include <cmath>
#include <stdexcept>

char * extendCString(char * cstring, size_t & capacity, size_t size)
{
  size_t new_capacity = static_cast< size_t >(std::ceil(capacity * std::sqrt(2)));
  if (new_capacity < size)
  {
    throw std::invalid_argument("error");
  }
  char * newstr = new char[new_capacity];
  for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  delete [] cstring;
  cstring = newstr;
  capacity = new_capacity;
  return cstring;
}
