#include "createStringFromInput.h"
#include <istream>
#include <cstddef>
#include <stdexcept>
#include "makeStringExtention.h"

char* createStringFromInput(std::istream& input)
{
  size_t capacity = 20;
  char* source1 = new char[capacity];
  source1[0] = '\0';
  size_t size = 0;
  input >> std::noskipws;

  do
  {
    if (size == capacity)
    {
      try
      {
        size_t new_capacity = capacity + 20;
        char* new_str = makeStringExtention(source1, capacity, size, new_capacity);
        delete[] source1;
        source1 = new_str;
        new_str = nullptr;
        capacity = new_capacity;
      }
      catch (const std::exception& e)
      {
        delete[] source1;
        throw;
      }
    }
    input >> source1[size];
  }
  while (input && source1[size++] != '\n');

  if (source1[0] == '\0' || source1[0] == '\n')
  {
    delete[] source1;
    return nullptr;
  }
  source1[size - 1] = '\0';
  return source1;
}
