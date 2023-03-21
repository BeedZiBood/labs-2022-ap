#include "MakeCString.hpp"

char *makeCString(char *cstring, size_t &size, size_t &capacity, std::istream &input)
{
  input >> std::noskipws;

  do
  {
    if (size == capacity)
    {
      char *newstr = new char[capacity + 20];
      for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
      {
        *j = *i;
      }
      delete[] cstring;
      cstring = newstr;
      capacity += 20;
    }

    input >> cstring[size];

  }
  while (input && cstring[size++] != '\n');

  return cstring;
}
