#include "isFloat.h"
#include <cctype>

bool isSign(char x)
{
  return x == '+' || x == '-';
}

bool isDigit(char x)
{
  return std::isdigit(x);
}

bool isNonZero(char x)
{
  return isDigit(x) && x != '0';
}

bool isEnd(char x)
{
  return x == '\0';
}

bool isDot(char x)
{
  return x == '.';
}

bool isE(char x)
{
  return x == 'E';
}

bool continueWithInteger(const char *x)
{
  return isDigit(*x) && (continueWithInteger(x + 1) || isEnd(*(x + 1)));
}

bool isOrder(const char *x)
{
  return isE(*x) && isSign(*(x + 1)) && continueWithInteger(x + 2);
}

bool continueInFloatBeforeOrder(const char *x)
{
  return isDigit(*x) && (continueInFloatBeforeOrder(x + 1) || (isOrder(x + 1) && isNonZero(*x)));
}

bool continueWithIntegerInMantissa(const char *x)
{
  return isDigit(*x) && (continueWithIntegerInMantissa(x + 1) || (isDot(*(x + 1)) && continueInFloatBeforeOrder(x + 2)));
}

bool isMantissa(const char *x)
{
  return (isDot(*x) && continueInFloatBeforeOrder(x + 1)) || (continueWithIntegerInMantissa(x)) || continueInFloatBeforeOrder(x);
}

bool isFloat(const char *x)
{
  return (isSign(*x) && isMantissa(x + 1)) || isMantissa(x);
}
