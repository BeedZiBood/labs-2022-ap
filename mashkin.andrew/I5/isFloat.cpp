#include "isFloat.h"
#include <cctype>

bool isMantissa(const char* str);
bool isSign(char symb);
bool isUnsignedInt(const char* str);
bool isDot(char symb);
bool isDigit(char symb);
bool isOrder(const char* str);
bool isEnd(char symb);
bool isE(char symb);
bool isFloat(const char* str)
{
  return isMantissa(str) || (isSign(*str) && isMantissa(str + 1));
}
bool isMantissa(const char* str)
{
  return (isDot(*str) && isUnsignedInt(str + 1)) || isUnsignedInt(str);
}
bool isSign(char symb)
{
  return symb == '+' || symb == '-';
}
bool isUnsignedInt(const char* str)
{
  return (isDigit(*str) && (isUnsignedInt(str + 1) || isOrder(str + 1) || isEnd(*(str + 1)))) || (isDigit(*str) && isEnd(*(str + 1)));
}
bool isDigit(char symb)
{
  return std::isdigit(symb);
}
bool isOrder(const char* str)
{
  return (isE(*str) && isSign(*(str + 1)) && isUnsignedInt(str + 2)) || (isE(*str) && isUnsignedInt(str + 1));
}
bool isEnd(char symb)
{
  return symb == '\0';
}
bool isE(char symb)
{
  return symb == 'E' || symb == 'e';
}
bool isDot(char symb)
{
  return symb == '.' || symb == ',';
}
