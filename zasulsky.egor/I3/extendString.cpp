#include "extendString.hpp"
#include <stdexcept>
#include <cstring>
#include <limits>

char* zasulsky::extendString(const char* src, size_t cap, size_t capDiff)
{
  if (cap > std::numeric_limits< size_t >::max() - capDiff) {
    throw std::overflow_error("String too large");
  }
  char* newstr = new char[cap + capDiff];
  std::strcpy(newstr, src);
  return newstr;
}
