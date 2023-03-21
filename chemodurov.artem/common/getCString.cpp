#include "getCString.h"
#include <iostream>
#include <extendCString.h>

char * chemodurov::getCString(std::istream & in)
{
  size_t capacity = 20;
  char * c_string = new char[capacity];
  c_string[0] = '\0';
  size_t size = 0;

  in >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        size_t new_capacity = capacity + 20;
        char * new_string = chemodurov::extendCString(c_string, capacity, new_capacity);
        delete [] c_string;
        c_string = new_string;
        new_string = nullptr;
        capacity = new_capacity;
      }
      catch (const std::exception & e)
      {
        delete [] c_string;
        throw;
      }
    }
    in >> c_string[size];
  }
  while (in && c_string[size] != '\0' && c_string[size++] != '\n');

  if (c_string[0] == '\n' || c_string[0] == '\0')
  {
    delete [] c_string;
    throw std::logic_error("Empty string");
  }
  c_string[size - 1] = '\0';
  return c_string;
}
