#include "IsItExpression.h"
#include <iostream>

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

bool isAster(char c)
{
  return c == '*';
}

bool isSign (char c)
{
  return c == '+' || c == '-';
}

bool isBracket(char c)
{
  return c == '(' || c == ')';
}

