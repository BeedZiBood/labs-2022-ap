#include "IsReal.h"
#include <cctype>

bool isSign(const char chr)
{
  return chr == '+' || chr == '-';
}

bool isUInt(const char** str)
{
  return (std::isdigit(**str) && std::isdigit(*++*str) && isUInt(str)) || std::isdigit(*(*str - 1));
}

bool isMantissa(const char** str)
{
  return **str == '.' && isUInt(&++*str);
}

bool isOrder(const char* str)
{
  return *str == 'E' && ((isSign(*++str) && isUInt(&++str)) || isUInt(&str));
}

bool isReal(const char* str)
{
  return (isSign(str[0]) && isMantissa(&++str) && isOrder(str)) || (isMantissa(&str) && isOrder(str));
}
