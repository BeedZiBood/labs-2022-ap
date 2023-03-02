#include "createCString.h"
#include <stdexcept>

char* createCString(std::istream& inp)
{
  size_t capacity = 10;
  size_t size = 0;

  char* new_source = nullptr;
  new_source = new char[capacity];
  char charInput = '\0';
  inp >> std::noskipws;

  for (inp >> charInput; (inp && charInput) && (charInput != '\n'); inp >> charInput)
  {
    if (capacity == size + 1)
    {
      capacity = capacity + 10;
      char* dupStr = nullptr;
      try
      {
        dupStr = new char[capacity + 10];
      }
      catch (const std::bad_alloc& e)
      {
        delete[] new_source;
        throw e;
      }
      new_source[size] = '\0';
      for (size_t i = 0; i < size; i++)
      {
        dupStr[i] = new_source[i];
      }
      delete[] new_source;
      new_source = dupStr;
    }
    new_source[size++] = charInput;
  }
  if (size < 1)
  {
    delete[] new_source;
    throw std::logic_error("Empty input");
  }
  new_source[size] = '\0';
  return new_source;
}
