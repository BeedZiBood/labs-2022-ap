#include "hasDoubledChars.h"

bool hasDoubledChars(const char* c_string)
{
  if (!*c_string) {
    return false;
  }
  size_t i = 1;
  while (c_string[i]) {
    if (c_string[i] == c_string[i - 1]) {
      return true;
    }
    ++i;
  }
  return false;
}
