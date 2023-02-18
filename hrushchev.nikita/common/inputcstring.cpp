#include "inputcstring.hpp"
#include <stdexcept>
#include <istream>

char* inputCString(std::istream& in)
{
  size_t capacity = 10;
  char* c_string = new char[capacity];
  size_t size = 0;

  in >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* new_str = new char[capacity + 20];
        for (auto i = c_string, j = new_str; i != c_string + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] c_string;
        c_string = new_str;
        capacity += 20;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] c_string;
        throw e;
      }
    }
    in >> c_string[size];
  }
  while (in && c_string[size++] != '\n');

  if (size <= 1)
  {
    delete[] c_string;
    throw std::invalid_argument("Empty input\n");
  }

  c_string[size - 1] = '\0';
  return c_string;
}

