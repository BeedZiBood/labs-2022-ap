#include "expression.h"

bool isDigit(const char c)
{
  return std::isdigit(c);
}

bool isIdentificator(const char c)
{
  return c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e';
}

bool isEnd(const char data)
{
  return data == '\0';
}

bool isSign(const char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isUnsigned(const char* data)
{
  return isDigit(*data) || (isDigit(*data) && isUnsigned(++data));
}

bool isMultiplier(const char* data)
{
  return isUnsigned(data) || isIdentificator(*data);
}

bool isTerm(const char* data)
{
  return isMultiplier(data) || (isMultiplier(data) && isSign(*data) && isTerm(++data));
}

bool isExpression(const char* data)
{
  return isEnd(*data) || (isTerm(data) && isSign(*(++data)) && isExpression(++data)) || isDigit(*data);
}
