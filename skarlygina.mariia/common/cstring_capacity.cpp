#include "cstring_capacity.h"
#include <exception>
#include <iostream>
#include <cstring>
#include <memory>
char* makeNewCString(std::istream& input)
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  char* newstring = nullptr;
  size_t size = 0;
  cstring[0] = '\0';

  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        newstring = new char[capacity + 20];
        newstring = std::strcpy(newstring, cstring);
        delete[] cstring;
        cstring = newstring;
        newstring = nullptr;
        capacity += 20;
      }
      catch (const std::exception& e)
      {
        delete[] cstring;
        delete[] newstring;
        throw;
      }
    }
    input >> cstring[size];
  }
  while (input && cstring[size++] != '\n');

  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    delete[] cstring;
    throw std::invalid_argument("Error while reading the string");
  }
  cstring[size - 1] = '\0';
  return cstring;
}
