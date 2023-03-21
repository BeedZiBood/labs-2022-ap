#include "replacesetchar.hpp"

char * replaceSetChar(char * res_str2, const char * cstring, const char ch1, const char ch2)
{
  auto j = res_str2;
  for (auto i = cstring; *i != '\0'; i++)
  {
    *j = (*i == ch1) ? ch2 : *i;
    ++j;
  }
  *j = '\0';
  return res_str2;
}
