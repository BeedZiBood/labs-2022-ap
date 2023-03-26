#include "isRealNumber.h"
#include <iostream>

bool isSign(char data)
{
  return (data == '+') || (data == '-');
}
bool isDigit(char data)
{
  return std::isdigit(data);
}
bool isE(char data)
{
  return data == 'E';
}
bool isDot(char data)
{
  return (data == '.');
}
bool isEnd(const char* data)
{
  return (isDigit(*data) && (isEnd(data + 1) || *(data + 1) == '\0'));
}
bool ifE(const char* data)
{
  return (isE(*data) && ((isSign(*(data + 1)) && isEnd(data + 2)) || isEnd(data + 1)));
}
bool continueWithDigitAfterDot(const char* data)
{
  return (isDigit(*data) || ifE(data + 1));
}
bool ifDot(const char* data)
{
  return (isDot(*data) && continueWithDigitAfterDot(data + 1));
}
bool continueWithDigit(const char* data)
{
  return ((isDigit(*data) && continueWithDigit(data + 1))|| ifDot(data));
}

bool isFloat(const char* data)
{
  return ((isSign(*data) && continueWithDigit(data + 1)) || continueWithDigit(data));
}
