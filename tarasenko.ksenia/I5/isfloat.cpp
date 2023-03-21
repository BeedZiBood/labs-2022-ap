#include "isfloat.hpp"

bool isSign(char n)
{
  return (n == '+' || n == '-');
}
bool isDigit(char n)
{
  return (n >= '0' && n <= '9');
}
bool isNonZero(char n)
{
  return (n > '0' && n <= '9');
}
bool isEnd(char n)
{
  return (n == '\0');
}
bool isDot(char n)
{
  return (n == '.');
}
bool isE(char n)
{
  return (n == 'E');
}
bool nextDigit(const char * n)
{
  return isDigit(*n) && (nextDigit(n + 1) || isEnd(*(n + 1)));
}
bool continueWithSign(const char * n)
{
  return isNonZero(*n) && (nextDigit(n + 1) || isEnd(*(n + 1)));
}
bool continueInExponent(const char * n)
{
  return (isSign(*n) && continueWithSign(n + 1)) || (isNonZero(*n) && (nextDigit(n + 1) || isEnd(*(n + 1))));
}
bool continueWithE(const char * n)
{
  return isE(*n) && continueInExponent(n + 1);
}
bool continueWithDigit(const char * n)
{
  return isDigit(*n) && (continueWithDigit(n + 1) || continueWithE(n + 1));
}
bool continueWithDot(const char * n)
{
  return isDigit(*n) && (continueWithDigit(n + 1) || continueWithE(n + 1));
}
bool isFloat(const char * n)
{
  return ((isDot(*n) && continueWithDot(n + 1)) || (isSign(*n) && isDot(*(n + 1)) && continueWithDot(n + 2)));
}

