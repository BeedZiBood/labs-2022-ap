#include "isRealNumber.h"
#include <cctype>

bool contWithDot(const char *);
bool contWithDigitInFloat(const char *);
bool contWithE(const char *);
bool contWithSignInPower(const char *);
bool contWithDigitInPower(const char *);
bool finishedWithDigit(const char *);

bool isDigit(char c)
{
  return std::isdigit(c);
}
bool isSign(char c)
{
  return (c == '+' || c == '-');
}
bool isDot(char c)
{
  return c == '.';
}
bool isE(char c)
{
  return c == 'E';
}
bool isEndOfCString(char c)
{
  return c == '\0';
}

bool contWithDigit(const char * data)
{
  return isDigit(*data) && (contWithDigit(data + 1) || contWithDot(data + 1));
}
bool contWithDot(const char * data)
{
  return isDot(*data) && contWithDigitInFloat(data + 1);
}
bool contWithDigitInFloat(const char * data)
{
  return isDigit(*data) && (contWithDigitInFloat(data + 1) || contWithE(data + 1));
}
bool contWithE(const char * data)
{
  return isE(*data) && (contWithSignInPower(data + 1) || contWithDigitInPower(data + 1) || finishedWithDigit(data + 1));
}
bool contWithSignInPower(const char * data)
{
  return isSign(*data) && (contWithDigitInPower(data + 1) || finishedWithDigit(data + 1));
}
bool contWithDigitInPower(const char * data)
{
  return isDigit(*data) && (contWithDigitInPower(data + 1) || finishedWithDigit(data + 1));
}
bool finishedWithDigit(const char * data)
{
  return isDigit(*data) && isEndOfCString(*(data + 1));
}

bool chemodurov::isRealNumber(const char * data)
{
  bool first_opt = isSign(*data) && (contWithDigit(data + 1) || contWithDot(data + 1));
  bool second_opt = isDigit(*data) && (contWithDigit(data + 1) || contWithDot(data + 1));
  bool third_opt = isDot(*data) && contWithDigitInFloat(data + 1);
  return first_opt || second_opt || third_opt;
}
