#include "CreateCString.h"
#include "StringExtension.h"


char *createCString(std::istream &input)
{
  size_t capacity = 10;
  char *source1 = new char[capacity];
  size_t size = 0;

  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char *newstr = stringExtension(source1,capacity, size);
        delete[] source1;
        source1 = newstr;
      }
      catch(const std::exception &e)
      {
        delete[] source1;
        throw;
      }
    }
    input >> source1[size];
  }
  while (input && source1[size++] != '\n');
  if (size == 0)
  {
    source1[0] = '\0';
    return source1;
  }
  source1[size - 1] = '\0';
  return source1;
}
