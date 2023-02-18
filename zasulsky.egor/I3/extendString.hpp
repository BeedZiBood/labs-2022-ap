#ifndef EXTENDSTRING_HPP
#define EXTENDSTRING_HPP

#include <cstddef>

namespace zasulsky {
  char* extendString(const char* src, size_t cap, size_t capDiff);
}

#endif
