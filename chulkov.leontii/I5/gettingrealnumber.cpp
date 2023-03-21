#include "gettingrealnumber.h"
#include <cctype>

bool contDot(const char*);
bool contDigitFloat(const char*);
bool contE(const char*);
bool contSign(const char*);
bool contAfterSign(const char*);
bool contFinish(const char*);

bool isSign(char cstr)
{
  return cstr == '+' || cstr == '-';
}
bool isDigit(char cstr)
{
  return std::isdigit(cstr);
}
bool isE(char cstr)
{
  return cstr == 'E';
}
bool isDot(char cstr)
{
  return cstr == '.';
}
bool isEnd(char cstr)
{
  return cstr == '\0';
}

bool contDigit(const char* cstr)
{
  return isDigit(*cstr) && (contDigit(cstr + 1) || contDot(cstr + 1));
}
bool contDot(const char* cstr)
{
  return isDot(*cstr) && contDigitFloat(cstr + 1);
}
bool contDigitFloat(const char* cstr)
{
  return isDigit(*cstr) && (contDigitFloat(cstr + 1) || contE(cstr + 1));
}
bool contE(const char* cstr)
{
  return isE(*cstr) && (contSign(cstr + 1) || contAfterSign(cstr + 1) || contFinish(cstr + 1));
}
bool contSign(const char* cstr)
{
  return isSign(*cstr) && (contAfterSign(cstr + 1) || contFinish(cstr + 1));
}
bool contAfterSign(const char* cstr)
{
  return isDigit(*cstr) && (contAfterSign(cstr + 1) || contFinish(cstr + 1));
}
bool contFinish(const char* cstr)
{
  return isDigit(*cstr) && isEnd(*(cstr + 1));
}

bool getRealNumber(const char* cstr)
{
  bool first = isDigit(*cstr) && (contDigit(cstr + 1) || contDot(cstr + 1));
  bool second = isSign(*cstr) && (contDigit(cstr + 1) || contDot(cstr + 1));
  bool thrid = isDot(*cstr) && contDigitFloat(cstr + 1);
  return first || second || thrid;
}
