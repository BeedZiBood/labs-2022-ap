#include "extendCString.h"
#include <stdexcept>

char * chemodurov::extendCString(const char * c_str, size_t cap, size_t new_cap)
{
  if (new_cap < cap)
  {
    throw std::invalid_argument("New capacity smaller than previous");
  }
  char * new_str = new char[new_cap];
  {
    auto j = new_str;
    for (auto i = c_str; i != c_str + cap; ++i)
    {
      *j = *i;
      ++j;
    }
  }
  return new_str;
}
