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