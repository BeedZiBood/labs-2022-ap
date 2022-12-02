#include "replacesetchar.hpp"

char * replaceSetChar(char * res_str2, const char * cstring, const char ch1, const char ch2)
{
  auto j = res_str2;
  for (auto i = cstring; *i != '\0'; i++)
  {
    if (*i == ch1)
    {
      *j = ch2;
    }
    else
    {
      *j = *i;
    }
    ++j;
  }
  *j = '\0';
  return res_str2;
}
