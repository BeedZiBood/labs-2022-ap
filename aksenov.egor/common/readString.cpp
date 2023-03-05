#include "readString.h"
#include <stdexcept>
#include <iostream>
#include <limits>
#include "extendString.h"
char *readString(std::istream &inputStr, size_t &in_size, const size_t increaseCapacity)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  inputStr >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      if (capacity == max_size)
      {
        delete[] cstring;
        throw std::runtime_error("Size more than max");
      }
      if (max_size - increaseCapacity <= capacity)
      {
        capacity = max_size;
      }
      else
      {
        capacity += increaseCapacity;
      }
      try
      {
        char *newStr = extendString(cstring, size, capacity);
        delete[] cstring;
        cstring = newStr;
      }
      catch (...)
      {
        delete[] cstring;
        throw;
      }
    }
    inputStr >> cstring[size];
  }
  while (inputStr && cstring[size++] != '\n');
  if (!inputStr && !size)
  {
    delete[] cstring;
    throw std::runtime_error("Input error");
  }
  cstring[size - 1] = '\0';
  in_size = size;
  return cstring;
}
