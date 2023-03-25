#include "myExtString.h"
#include <cstring>

char* extendMyString(const char* myString, size_t &capacity)
{
  char* newstr = new char[capacity + 10];
  std::strcpy(newstr, myString);
  capacity += 10;

  return newstr;
}
