#include "createCString.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include "increaseString.h"

char* createCString(std::istream& inp, size_t size, size_t capacity)
{
  char* cstring = nullptr;
  try
  {
    cstring = new char[capacity];
  }
  catch (...)
  {
    delete[] cstring;
    throw;
  }
  inp >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* oldStr = cstring;
        cstring = increaseString(cstring, capacity, size, 20);
        delete[] oldStr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cstring;
        throw;
      }
    }
    inp >> cstring[size];
  }
  while (inp && cstring[size++] != '\n');
  if (size <= 1)
  {
    delete[] cstring;
    throw std::logic_error("empty input");
  }
  else
  {
    cstring[size - 1] = '\0';
  }
  return cstring;
}
