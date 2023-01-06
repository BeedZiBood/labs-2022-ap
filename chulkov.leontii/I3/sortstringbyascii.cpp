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
bool compare(const char* i, const char* q)
{
  bool match = false;
  for (const char* j = i + 1; *j; j++)
  {
    if ((std::toupper(*i)) == std::toupper(*j))
    {
      match = true;
      break;
    }
  }
  for (const char* z = q; *z; z++)
  {
    if ((std::toupper(*i)) == std::toupper(*z))
    {
      match = true;
      break;
    }
  }
  return match;
}
char* sortStringByAscii(char* finalstr, const char* cstring, const char* newstr)
{
  size_t elstr = 0;
  const char* q = newstr;
  for (const char* i = cstring; *i; i++)
  {
    if (std::isalpha(*i))
    {
      bool matching = compare(i, q);
      if (!matching)
      {
        finalstr[elstr++] = std::toupper(*i);
      }
    }
  }
  for (const char* i = newstr; *i; i++)
  {
    if (std::isalpha(*i))
    {
      bool matching = compare(i, q);
      if (matching)
      {
        finalstr[elstr++] = std::toupper(*i);
      }
    }
  }
  sort(elstr, finalstr);
  finalstr[elstr] = '\0';
  return finalstr;
}
