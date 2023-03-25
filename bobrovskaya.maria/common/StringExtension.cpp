#include "StringExtension.h"

char *stringExtension(const char *source1, size_t &capacity, size_t size)
{
  char *newstr = new char[capacity + 20];
  auto j = newstr;
  for (auto i = source1; i != source1 + size; i++, j++)
  {
    *j = *i;
  }
  capacity += 20;
  return newstr;
}
