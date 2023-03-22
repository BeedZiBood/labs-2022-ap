#include "is_float.h"
#include <cctype>

bool continueSign(const char * data);
bool continueWithE(const char * data);
bool continueWithDot(const char * data);
bool continueWithDigit(const char * data);
bool continueDigitalSecondPart(const char * data);
bool continueDigitalFirstPart(const char * data);

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
  return (c == '.');
}
bool isE(char c)
{
  return (c == 'E');
}
bool isEndString(char c)
{
  return (c == '\0');
}

bool continueSign(const char * data)
{
  return isSign(*data) && continueDigitalSecondPart(data + 1);
}
bool continueWithE(const char * data)
{
  return isE(*data) && continueSign(data + 1);
}
bool continueDigitalSecondPart(const char * data)
{
  return isDigit(*data) && (continueDigitalSecondPart(data + 1 ) || isEndString(*(data + 1)) );
}
bool continueDigitalFirstPart(const char * data)
{
  return isDigit(*data) && (continueDigitalFirstPart(data + 1) || continueWithE(data + 1));
}
bool continueWithDigit(const char * data)
{
  return isDigit(*data) && (continueWithDigit(data + 1) || continueWithDot(data + 1) || continueWithE(data + 1));
}
bool continueWithDot(const char * data)
{
  return isDot(*data) && continueDigitalFirstPart(data + 1);
}

bool isFloat(const char * data)
{
  bool first_option = isSign(*data) && continueWithDigit(data + 1);
  bool second_option = isDigit (*data) && (continueWithDigit(data + 1) || continueWithE(data + 1) || continueWithDot(data + 1));
  return first_option || second_option;
}
