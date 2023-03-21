#include "isexpression.hpp"
#include <iostream>

bool isIdentificator(const char x)
{
  return x == 'a' || x == 'b' || x == 'c' || x == 'd' || x == 'e';
}

bool isDigit(const char x)
{
  return std::isdigit(x);
}

bool isEnd(const char x)
{
  return (x == '\0');
}

bool isSign(const char x)
{
  return x == '+' || x == '-';
}

bool isUnsigned(const char *x)
{
  return isDigit(*x) || (isDigit(*x) && isUnsigned(++x));
}

bool isMultiplier(const char *x)
{
  return isUnsigned(x) || isIdentificator(*x);
}

bool isTerm(const char *x)
{
  return isMultiplier(x) || (isMultiplier(x) && isSign(*x) && isTerm(++x));
}

bool isExpression(const char *x)
{
  return isTerm(x) || (isTerm(x) && (isSign(*x) || isSign(*x)) && isExpression(++x));
}

bool checkExpression(const char *x)
{
  return isExpression(x) && isEnd(*x);
}
