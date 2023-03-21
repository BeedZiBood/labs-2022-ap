#include "isExpression.h"

bool isLetter(const char val)
{
  return (val >= 'A') and (val <= 'E');
}

bool isDigit(const char val)
{
  return (val >= '0') and (val <= '9');
}

bool isOpenBrace(const char val)
{
  return (val == '(');
}

bool isCloseBrace(const char val)
{
  return (val == ')');
}

bool isMuSi(const char val)
{
  return (val == '*');
}

bool isSubtrOrAddSi(const char val)
{
  return (val == '+') || (val == '-');
}

bool isEnd(const char val)
{
  return (val == '\0');
}

bool isIdentifier(const char val)
{
  return isLetter(val);
}

bool isUnsignedInteger(const char* c)
{
  return isDigit(*c) || (isDigit(*c) && isUnsignedInteger(c + 1));
}

bool isMultiplier(const char* c)
{
  return isUnsignedInteger(c) || isIdentifier(*c) || (isOpenBrace(*c) && isMathExpr(c + 1) && isCloseBrace(*c));
}

bool isTerm(const char* c)
{
  return isMultiplier(c) || (isMultiplier(c) && isMuSi(*c) && isTerm(c + 1));
}

bool isMathExpr(const char* c)
{
  return isEnd(*c) || isTerm(c) || (isTerm(c) && isSubtrOrAddSi(*c) && isMathExpr(c + 1));
}
