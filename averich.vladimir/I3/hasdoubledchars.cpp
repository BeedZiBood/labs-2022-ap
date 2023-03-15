#include "hasdoubledchars.h"

#include <cstddef>

bool hasDoubledChars(const char* c_string)
{
  const char terminator = '\0';
  
  if (c_string[0] == terminator)// in case of empty string
  {
    return false;
  }
  size_t i = 1;
  while (c_string[i] != terminator)
  {
    if (c_string[i] == c_string[i - 1])// compare current with previous
    { 
      return true;
    }
    ++i;
  }
  
  return false;
}
