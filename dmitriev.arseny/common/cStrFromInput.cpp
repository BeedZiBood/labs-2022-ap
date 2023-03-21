#include <stdexcept>
#include "string.h"
#include "cStrFromInput.h"

char* createCStrFromInput(std::istream& inp)
{
  size_t capacity = 11;
  size_t size = 0;
  char* cStr = nullptr;
  cStr = new char[capacity];
  char chInp = '\0';

  inp >> std::noskipws;

  for (inp >> chInp; (inp && chInp) && (chInp != '\n'); inp >> chInp)
  {
    if (size + 1 == capacity)
    {
      capacity = capacity + 10;
      char* dupStr = nullptr;
      try
      {
        dupStr = new char[capacity];
      }
      catch (const std::bad_alloc& e)
      {
        delete[] cStr;
        throw;
      }
      cStr[size] = '\0';
      dupStr = strcpy(dupStr, cStr);
      delete[] cStr;
      cStr = dupStr;
    }
    cStr[size++] = chInp;
  }

  if (size == 0)
  {
    delete[] cStr;
    throw std::logic_error("Empty string");
  }

  cStr[size] = '\0';

  return cStr;
}
