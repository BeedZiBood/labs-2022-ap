#include "IsItExpression.h"

bool isLetter(const char c)
{
  return c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E';
}

bool isDigit(const char c)
{
  return std::isdigit(c);
}

bool isIdentificator(const char c)
{
  return (isLetter(c) == 0) ? 0 : 1;
}

bool isEnd(const char c)
{
  return (c == '\0');
}

bool isSign(const char c)
{
  return c == '+' || c == '-' || c == '*';
}

bool isBracket(const char c)
{
  return c == '(' || c == ')';
}

bool isUnsignedInteger(const char* inp)
{
  return isDigit(*inp) || (isDigit(*inp) && isUnsignedInteger(inp + 1));
}

bool isMult(const char* inp)
{
  return isUnsignedInteger(inp) || isIdentificator(*inp) || (isBracket(*inp) && examExpression(inp + 1));
}

bool isTerm(const char* inp)
{
  return isMult(inp) || (isMult(inp) && isTerm(inp + 1));
}

bool examExpression(const char* inp)
{
  return isEnd(*inp) || (isTerm(inp) && isSign(*(inp + 1)) && examExpression(inp + 1)) || isDigit(*inp);
}
