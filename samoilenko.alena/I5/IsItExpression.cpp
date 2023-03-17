#include "IsItExpression.h"
#include <iostream>
#include <cstring>

bool isLetter(char c)
{
  return c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E';
}

bool isDigit(char c)
{
  return std::isdigit(c);
}

bool isIdentificator(char c)
{
  return (isLetter(c) == 0) ? 0 : 1;
}

bool isEnd(char c)
{
  return (c == '\0');
}

bool isSign (char c)
{
  return c == '+' || c == '-';
}

bool isBracket(char c)
{
  return c == '(' || c == ')';
}

bool isUnsignedInteger(char* inp)
{
  return isDigit(*inp) || (isDigit(*inp) && isUnsignedInteger(inp + 1));
}

bool isMult(char* inp)
{
  return isUnsignedInteger(inp) || isIdentificator(*inp) || (isBracket(*inp) && examExpression(inp + 1));
}

bool isTerm(char* inp)
{
  return isMult(inp) || (isMult(inp) && isTerm(inp + 1));
}

bool examExpression(char* inp)
{
  return isEnd(*inp) || (isTerm(inp) && isSign(*(inp + 1)) && examExpression(inp + 1)) || isDigit(*inp);
}
