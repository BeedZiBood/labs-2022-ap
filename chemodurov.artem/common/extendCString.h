#ifndef EXTENDCSTRING_H
#define EXTENDCSTRING_H
#include <cstddef>

namespace chemodurov
{
  char * extendCString(const char * c_string, size_t capacity, size_t new_capacity);
}

#endif
