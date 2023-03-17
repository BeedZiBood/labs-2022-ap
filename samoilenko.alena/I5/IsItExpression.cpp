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

bool isMult(const char* inp, size_t firstVal, size_t secondVal)
{
  if (isIdentificator(*(inp + firstVal)) && (firstVal == secondVal))
  {
    return 1;
  }
  else
  {
    if (isBracket(*(inp + firstVal)) && (isBracket(*(inp + secondVal))))
    {
      return examExpress(inp, firstVal + 1, secondVal - 1);
    }
    else
    {
      return isUnsignedInteger(inp, firstVal, secondVal);
    }
  }
  return 0;
}

bool isTerm(const char* inp, size_t firstVal, size_t secondVal)
{
  size_t t = firstVal;
  while (!isAster(*(inp + t)) && (t != secondVal))
  {
    t++;
  }
  if (t == secondVal)
  {
    if (isMult(inp, firstVal, t))
    {
      return 1;
    }
  }
  if (isMult(inp, firstVal, t - 1))
  {
    firstVal = t + 1;
    return isTerm(inp, firstVal, secondVal);
  }
  else
  {
    return 0;
  }
  return 0;
}

bool examExpress(const char* inp, size_t firstVal, size_t secondVal)
{
  size_t t = firstVal;
  while (!isSign(*(inp + t)) && (t != secondVal))
  {
    t++;
  }
  if (t == secondVal)
  {
    if (isTerm(inp, firstVal, t))
    {
      return 1;
    }
  }
  if (isTerm(inp, firstVal, t - 1))
  {
    firstVal = t + 1;
    return examExpress(inp, firstVal, secondVal);
  }
  else
  {
    return 0;
  }
  return 0;
}

bool outResult(const char* inp)
{
  return examExpress(inp, 0, strlen(inp) - 1);
}
