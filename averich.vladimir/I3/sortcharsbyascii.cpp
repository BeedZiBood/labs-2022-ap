#include "sortcharsbyascii.hpp"
#include <iostream>
#include <cstddef>
int sortCharsByAscii(char* destination, size_t sizeOfDestination)
{
  for (size_t i = 0; i < sizeOfDestination; i++)
  {
    for (size_t j = i + 1; j < sizeOfDestination; j++)
    {
      if (destination[i] > destination[j])
      {
        std::swap(destination[i], destination[j]);
      }
    }
  }
  return 0;
}
