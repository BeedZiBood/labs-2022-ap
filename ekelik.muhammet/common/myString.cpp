#include "myString.h"
#include <myExtString.h>

char* makeMyString(size_t &size, size_t &capacity, std::istream &input)
{
  char* myString = new char[capacity];
  myString[0] = '\n';

  input >> std::noskipws;
  do
  {
    if (size + 1 == capacity)
    {
      myString[size] = '\0';
      char* newstr = extendMyString(myString, capacity);
      delete[] myString;
      myString = newstr;
    }
    input >> myString[size];
  }
  while (input && myString[size++] != '\n');

  if (myString[0] != '\n')
  {
    myString[size - 1] = '\0';
  }

  return myString;
}
