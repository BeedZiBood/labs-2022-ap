#include "isthesamechars.hpp"
#include <cstddef>
bool isTheSameChars(const char source[], size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    if (source[i] == source[i + 1])
    {
      return true;
    }
  }
  return false;
}
