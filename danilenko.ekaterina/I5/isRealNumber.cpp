#include "isRealNumber.h"
#include <iomanip>

bool isUnsignInteger(const char* data);
bool isEnd(char s)
{
  return s == '\0';
}

bool isSign(char s)
{
  return s == '+' || s == '-';
}

bool isDot(char s)
{
  return s == '.';
}

bool isE(char s)
{
  return s == 'E' || s == 'e';
}

bool isDigit(char s)
{
  return std::isdigit(s);
}

bool isOrder(const char* data)
{
  return (isE(*data) && isSign(*(data + 1)) && isUnsignInteger(data + 2)) || (isE(*data) && isUnsignInteger(data + 1));
}

bool isUnsignInteger(const char* data)
{
  return (isDigit(*data) && (isUnsignInteger(data + 1) || isOrder(data + 1) || isEnd(*(data + 1)))) || (isDigit(*data) && isEnd(*(data + 1)));
}

bool isMantissa(const char* data)
{
  return (isDot(*data) && isUnsignInteger(data + 1)) || isUnsignInteger(data);
}

bool isRealNumber(const char* data)
{
  return isMantissa(data) || (isSign(*data) && isMantissa(data + 1));
}
