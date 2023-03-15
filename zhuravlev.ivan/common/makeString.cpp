#include "makeString.h"
#include <iostream>
#include <stdexcept>
#include "string_expansion.h"

char* makeCstring(size_t& capacity, size_t& size, std::istream& input)
{
  char* cstring = new char[capacity];
  cstring[0] = '\0';
  size_t new_capacity = 0;
  input >> std::noskipws;
  do
  {
    if (size + 1 == capacity)
    {
      try
      {
        cstring[size] = '\0';
        new_capacity += 20;
        char* new_str = nullptr;
        char* prev_cstring = cstring;
        new_str = stringExpansion(cstring, capacity, new_capacity);
        delete[] prev_cstring;
        cstring = new_str;
        capacity += new_capacity;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] cstring;
        throw;
      }
    }
    input >> cstring[size];
  }
  while (input && cstring[size++] != '\n');
  if (cstring[0] == '\n' || size == 0)
  {
    delete[] cstring;
    throw std::invalid_argument("Empty string");
  }
    cstring[size - 1] = '\0';
  return cstring;
}
