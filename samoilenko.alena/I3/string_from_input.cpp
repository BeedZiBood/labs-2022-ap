#include "string_from_input.h"
#include "string_extension.h"

char* makeStringFromInput(std::istream& input)
{
  size_t capacity = 30;
  char* source = new char[capacity];
  source[0] = '\0';
  size_t size = 0;
  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        size_t newcapacity = 20;
        char* newstr = expandString(source, newcapacity, size, capacity);
        capacity += newcapacity;
        delete[] source;
        source = newstr;
        newstr = nullptr;
      }
      catch (const std::bad_alloc &ex)
      {
        delete[] source;
        throw;
      }
    }
    input >> source[size];
  }
  while (input && source[size] != '\0' && source[size++] != '\n');

  if (source[0] == '\n' || source[0] == '\0')
  {
    delete[] source;
    throw std::logic_error("Empty string");
  }
  source[size - 1] = '\0';
  return source;
}
