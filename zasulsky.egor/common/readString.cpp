#include "readString.hpp"
#include <iostream>
#include <cstddef>
#include <tuple>
#include "extendString.hpp"

std::tuple< char*, size_t, size_t > zasulsky::readString(std::istream& in)
{
  size_t capacity = 10;
  size_t size = 0;
  char* cstring = new char[capacity];

  in >> std::noskipws;
  do {
    if (size == capacity - 1) {
      try {
        cstring[size] = '\0';
        char* newstr = extendString(cstring, capacity, 20);
        delete [] cstring;
        cstring = newstr;
        capacity += 20;
      } catch (...) {
        delete [] cstring;
        throw;
      }
    }
    in >> cstring[size++];
  } while (in && cstring[size - 1] != '\n');
  cstring[size - 1] = '\0';
  return std::make_tuple(cstring, size, capacity);
}
