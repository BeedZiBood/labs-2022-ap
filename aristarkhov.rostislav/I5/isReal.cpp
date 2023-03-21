#include "isReal.h"
#include <cctype>

bool isSign(char value)
{
  return (value == '+' || value == '-');
}
bool isDigit(char value)
{
  return (std::isdigit(value));
}
bool isE(char value)
{
  return (value == 'E');
}
bool isPoint(char value)
{
  return (value == '.');
}
bool isEnd(char value)
{
  return (value == '\0');
}

bool continueEnding(const char* str)
{
  return isDigit(*str) && (continueEnding(str + 1) || isEnd(*(str + 1)));
}

bool continueWithSign(const char* str)
{
  return isSign(*str) && continueEnding(str + 1);
}

bool continueWithOrder(const char* str)
{
  return isE(*str) && continueWithSign(str + 1);
}

bool continueWithDigitAfterPoint(const char* str)
{
  return isDigit(*str) && (continueWithDigitAfterPoint(str + 1) || continueWithOrder(str + 1));
}

bool continueWithPoint(const char* str)
{
  return isPoint(*str) && continueWithDigitAfterPoint(str + 1);
}
bool continueWithMantissa(const char* str)
{
  return isDigit(*str) && (continueWithMantissa(str + 1) || continueWithPoint(str + 1));
}

bool isReal(const char* str)
{
  return isSign(*str) && continueWithMantissa(str + 1);
}
