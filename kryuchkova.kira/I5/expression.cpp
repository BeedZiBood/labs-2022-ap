#include "expression.h"
#include <cctype>

bool isOpenBrace(const char data)
{
  return data == '(';
}
bool isCloseBrace (const char data)
{
  return data == ')';
}
bool isDigit(const char data)
{
  return std::isdigit(data);
}
bool isIdentificator(const char data)
{
  return data == 'a' || data == 'b' || data == 'c' || data == 'd' || data == 'e' || data == 'f' || data == 'x' || data == 'y' || data == 'z';
}
bool isEnd(const char data)
{
  return (data == '\0');
}
bool isSign(const char data)
{
  return data == '+' || data == '-' || data == '/' || data == '*';
}

bool isUnsigned(const char *data)
{
  return isDigit(*data) || (isDigit(*data) && isUnsigned(++data));
}
bool isFactor(const char *data)
{
  return isUnsigned(data) || isIdentificator(*data) || (isOpenBrace(*data) && isExpression(++data) && isCloseBrace(*data));
}
bool isTerm(const char *data)
{
  return isFactor(data) || (isOpenBrace(*data) && isFactor(data) && isSign(*data) && isFactor(data) && isCloseBrace(*data));
}
bool isExpression(const char *data)
{
  return isEnd(*data) || (isTerm(data) && isSign(*(++data)) && isExpression(++data)) || isDigit(*data);
}
