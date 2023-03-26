#include "isexpression.h"
#include <cctype>

bool isOpenBrace(char x)
{
  return x == '(';
}

bool isCloseBrace(char x)
{
  return x == ')';
}

bool isIdentificator(char x)
{
  return x == 'a' || x == 'b' || x == 'c' || x == 'd' || x == 'e';
}

bool isDigit(char x)
{
  return std::isdigit(x);
}

bool isEnd(char x)
{
  return (x == '\0');
}

bool isSign(char x)
{
  return x == '+' || x == '-' || x == '*';
}
bool isMultiplier(const char * array)
{
  return (isSign(*array) || isEnd(*array)) || ((isDigit(*array) || isIdentificator(*array)) && isMultiplier(++array));
}

bool isTerm(const char * array)
{
  return (isSign(*array) || isEnd(*array)) || (isMultiplier(array) && isTerm(++array));
}

bool isExpression(const char * array)
{
  return isEnd(*array) || (isTerm(array) && isExpression(++array));
}
