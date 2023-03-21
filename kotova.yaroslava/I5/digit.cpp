#include "digit.hpp"
#include <cctype>

bool isDigit(char c)
{
  return std::isdigit(c);
}

bool isSign(char c)
{
  return (c == '+' || c == '-');
}

bool isDot(char c)
{
  return (c == '.');
}

bool isEnd(char c)
{
  return (c == '\0');
}

bool isE(char c)
{
  return (c == 'E');
}

bool continueWithDigit(const char* data)
{
  return isDigit(*data) && (continueWithDigit(data + 1) || isEnd(*(data + 1)));
}

bool isOrder(const char* data)
{
  return isE(*data) && ((isSign(*(data + 1)) && continueWithDigit(data + 2)) || continueWithDigit(data + 1));
}

bool isInteger(const char* data)
{
  return isDigit(*data) && (isInteger(data + 1) || isOrder(data + 1));
}

bool afterDot(const char* data)
{
  return isDot(*data) && isInteger(data + 1);
}

bool isMantissa(const char* data)
{
  return isDigit(*data) && (isMantissa(data + 1) || afterDot(data + 1));
}

bool isFloat(const char* data)
{
  return isMantissa(data) || (isSign(*data) && isMantissa(data + 1));
}
