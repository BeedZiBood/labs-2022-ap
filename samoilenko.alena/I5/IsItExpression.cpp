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

bool isUnsignedInteger(const char* inp, size_t firstVal, size_t secondVal)
{
  if ((*(inp + firstVal) != '\0') && (isDigit(*(inp + firstVal))))
  {
    firstVal++;
    return ((*(inp + firstVal) == '\0') || (firstVal == secondVal + 1)) ? 1 : isUnsignedInteger(inp, firstVal, secondVal);
  }
  return 0;
}

