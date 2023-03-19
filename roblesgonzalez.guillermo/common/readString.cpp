#include "readString.h"
#include <stdexcept>
#include <istream>
#include <cstddef>
#include <cstring>

char *readString(std::istream &inp)
{
  size_t capacity = 10;
  size_t size = 0;
  char *cstring = nullptr;
  cstring = new char[capacity];
  char chInp = '\0';
  inp >> std::noskipws;
  for (inp >> chInp; (inp && chInp) && (chInp != '\n'); inp >> chInp)
  {
    if (size + 1 == capacity)
    {
      capacity = capacity + 10;
      char *dupStr = nullptr;
      try
      {
        dupStr = new char[capacity];
      }
      catch (const std::bad_alloc& e)
      {
        delete[] cstring;
        throw;
      }
      cstring[size] = '\0';
      dupStr = strcpy(dupStr, cstring);
      delete[] cstring;
      cstring = dupStr;
    }
    cstring[size++] = chInp;
  }
  if (size == 0)
  {
    delete[] cstring;
    throw std::logic_error("Error: Empty String!");
  }
  cstring[size] = '\0';
  return cstring;
}
