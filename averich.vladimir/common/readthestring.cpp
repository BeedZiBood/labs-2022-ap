#include "readthestring.hpp"
#include <stdexcept>
#include <iostream>
#include <limits>
#include <cstddef>
#include "extendthestring.hpp"
char* readTheString(std::istream& inputString, size_t& inputSize, const size_t increaseCapacity)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  inputString >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      if (capacity == maxSize)
      {
        delete[] cstring;
        throw std::runtime_error("Error: overflow");
      }
      if (maxSize - increaseCapacity <= capacity)
      {
        capacity = maxSize;
      }
      else
      {
        capacity += increaseCapacity;
      }
      char* newString = extendTheString(cstring, size, capacity);
      delete[] cstring;
      cstring = newString;
    }
    inputString >> cstring[size];
  }
  while (inputString && cstring[size++] != '\n');
  if (!inputString && !size)
  {
    delete[] cstring;
    throw std::runtime_error("Error: invalid input");
  }
  cstring[size - 1] = '\0';
  inputSize = size;
  return cstring;
}
