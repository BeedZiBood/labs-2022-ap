#include "sortstringbyascii.h"
#include <cctype>
#include <stdexcept>

void sort(size_t elstr, char* finalstr)
{
  for (size_t i = 0; i < elstr; i++)
  {
    for (size_t j = i + 1; j < elstr; j++)
    {
      if (finalstr[i] > finalstr[j])
      {
        std::swap(finalstr[i], finalstr[j]);
      }
    }
  }
}
bool compare(const char i, const char* q)
{
  for (const char* z = q; *z; z++)
  {
    if ((std::toupper(i)) == std::toupper(*z))
    {
      return true;
    }
  }
  return false;
}
char* checkString(char* alpstr, const char* cstring, const char* q, size_t& elstr)
{
  for (const char *i = cstring; *i; i++)
  {
    if (std::isalpha(*i))
    {
      bool matching = compare(*i, q);
      if (matching)
      {
        alpstr[elstr++] = std::toupper(*i);
      }
    }
  }
  return alpstr;
}
char* sortStringByAscii(char* alpstr, const char* cstring, const char* newstr)
{
  size_t elstr = 0;
  checkString(alpstr, cstring, newstr, elstr);
  sort(elstr, alpstr);
  alpstr[elstr] = '\0';
  sort(elstr, alpstr);
  return alpstr;
}
