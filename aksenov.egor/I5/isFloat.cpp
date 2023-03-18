#include "isFloat.h"
#include <cctype>
bool continueWithDigit(const char *expr);
bool continueWithSign(const char *expr);
bool continueWithPoint(const char *expr);
bool continueWithE(const char *expr);
bool continueFirstDigitPart(const char *expr);
bool continueSecondDigitPart(const char *expr);
bool isDigit(const char symbol)
{
  return std::isdigit(symbol);
}
bool isSign(const char symbol)
{
  return (symbol == '+' || symbol == '-');
}
bool isPoint(const char symbol)
{
  return (symbol == '.');
}
bool isEnd(const char symbol)
{
  return (symbol == '\0');
}
bool isE(const char symbol)
{
  return (symbol == 'E');
}

bool continueWithDigit(const char *expr)
{
 return isDigit(*expr) && (continueWithDigit(expr + 1) || continueWithE(expr + 1) || continueWithPoint(expr + 1));
}
bool continueWithSign(const char *expr)
{
  return isSign(*expr) && continueSecondDigitPart(expr + 1);
}
bool continueWithPoint(const char *expr)
{
  return isPoint(*expr) && continueFirstDigitPart(expr + 1);
}
bool continueWithE(const char *expr)
{
  return isE(*expr) && continueWithSign(expr + 1);
}
bool continueFirstDigitPart(const char *expr)
{
  return isDigit(*expr) && (continueFirstDigitPart(expr + 1) || continueWithE(expr + 1));
}
bool continueSecondDigitPart(const char *expr)
{
  return isDigit(*expr) && (continueSecondDigitPart(expr + 1) || isEnd(*(expr + 1)));
}
bool isFloat(const char *expr)
{
  bool firstOption = isSign(*expr) && continueWithDigit(expr + 1);
  bool secondOption = firstOption || continueWithDigit(expr + 1);
  return secondOption;
}
