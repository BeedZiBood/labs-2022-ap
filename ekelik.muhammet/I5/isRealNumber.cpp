#include "isRealNumber.h"
#include <cstddef>
#include <cctype>

bool isSign(char sym)
{
  return (sym == '-' || sym == '+');
}
bool isDigit(char sym)
{
  return std::isdigit(sym);
}
bool isDot(char sym)
{
  return (sym == '.');
}
bool isEChar(char sym)
{
  return (sym == 'e' || sym == 'E');
}
bool isEnd(char sym)
{
  return (sym == '\0');
}

bool isUnsignedInteger(const char* data, size_t& shift)
{
  while (!isEnd(*(data + shift)) && isDigit(*(data + shift)))
  {
    shift++;
    if (isDot(*(data + shift)) || isEChar(*(data + shift)) || isEnd(*(data + shift)))
    {
      return true;
    }
  }
  return false;
}
bool isInOrder(const char* data, size_t& shift)
{
  if (!isEChar(*data))
  {
    return false;
  }
  ++data;
  ++shift;
  if (!isSign(*data))
  {
    return false;
  }
  ++data;
  ++shift;
  size_t a = 0;
  if (!isUnsignedInteger(data, a))
  {
    return false;
  }
  shift += a;
  return true;
}
bool isMantissa(const char* data, size_t& shift)
{
  bool firstNumber = isUnsignedInteger(data, shift);
  if (firstNumber)
  {
    if (isDot(*(data + shift)))
    {
      shift += 1;
      bool secondNumber = isUnsignedInteger(data, shift);
      return secondNumber;
    }
    else if (isEChar(*(data + shift)))
    {
      return true;
    }
  }
  return false;
}
bool isRealNumber(const char* data)
{
  size_t shift = 0;
  const char* currVal = data;
  if (isSign(*currVal))
  {
    currVal++;
  }
  return isMantissa(currVal, shift) && isInOrder(currVal + shift, shift) && isEnd(*(currVal + shift));
}
