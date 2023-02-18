#include "change_register.h"
#include <cctype>

char * changeRegister(char * res, const char * str)
{
  const char * i = str;
  char * j = res;
  while (*i)
  {
    *j++ = std::tolower(*i++);
  }
  *j = '\0';
  return res;
}
