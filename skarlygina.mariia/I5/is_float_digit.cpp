#include "is_float_digit.h"
#include <cctype>

bool isSign(char c)
{
  return (c == '+' || c == '-');
}

bool isDigit(char c)
{
  return std::isdigit(c);
}

bool isE(char c)
{
  return (c == 'E');
}

bool isDot(char c)
{
  return (c == '.');
}

bool isEnd(char c)
{
  return (c == '\0');
}

bool continueAfterSign(const char* data)
{
  return isDigit(*data) && (continueAfterSign(data + 1) || isEnd(*(data + 1)));
}

bool continueWithSign(const char* data)
{
  return isSign(*data) && continueAfterSign(data + 1);
}

bool continueWithE(const char* data)
{
  return isE(*data) && continueWithSign(data + 1);
}

bool continueWithDigitAfterDot(const char* data)
{
  return isDigit(*data) && (continueWithDigitAfterDot(data + 1) || continueWithE(data + 1));
}

bool continueWithDot(const char* data)
{
  return isDot(*data) && continueWithDigitAfterDot(data + 1);
}

bool continueWithDigit(const char* data)
{
  return isDigit(*data) && (continueWithDigit(data + 1) || continueWithDot(data + 1));
}

bool isFloatDigit(const char* data)
{
  return (isSign(*data) && continueWithDigit(data + 1));
}
