#include "input_string.h"
#include <stdexcept>
#include <golden_ratio.h>
#include <extend_string.h>

char * inputString(std::istream & in)
{
  size_t capacity = 10;
  char * str_1 = new char[capacity];
  size_t size_1 = 0;
  in >> std::noskipws;
  do
  {
    if (size_1 == capacity)
    {
      try
      {
        size_t new_capacity = goldenRatio(capacity);
        char * new_str = extendString(str_1, capacity, new_capacity);
        delete [] str_1;
        str_1 = new_str;
        capacity = new_capacity;
      }
      catch (...)
      {
        delete [] str_1;
        throw;
      }
    }
    in >> str_1[size_1];
  }
  while (in && str_1[size_1++] != '\n');
  if (!in && !size_1)
  {
    delete[] str_1;
    throw std::runtime_error("error");
  }
  str_1[size_1 - 1] = '\0';
  return str_1;
}
