#include "rowvalidation.h"
#include <cctype>

bool isSign(char data)
{
  return (data == '+' || data == '-');
}
bool isDigit(char data)
{
  return std::isdigit(data);
}
bool isEnd(char data)
{
  return (data == '\0');
}
bool isDot(char data)
{
  return (data == '.');
}
bool isE(char data)
{
  return (data == 'E');
}
bool continueWithDigit(const char * data)
{
  return isDigit(*data) && (continueWithDigit(data + 1) || isEnd(*(data + 1)));
}
bool isOrder(const char * data)
{
  return isE(*data) && isSign(*(data + 1)) && continueWithDigit(data + 2);
}
bool continueWithSign(const char * data)
{
  return isE(*data) && isSign(*(data + 1)) && continueWithDigit(data + 2);
}
bool continueWithE(const char * data)
{
  return isDigit(*data) && (continueWithE(data + 1) || continueWithSign(data + 1));
}
bool continueWithDot(const char * data)
{
  return isDot(*data) && continueWithE(data + 1);
}
bool continueWithD(const char * data)
{
  return isDigit(*data) && (continueWithD(data + 1) || continueWithDot(data + 1));
}
bool isFloat(const char * data)
{
  return (continueWithDot(data) && isOrder(data + 1)) || (isSign(*data) && continueWithD(data + 1));
}
