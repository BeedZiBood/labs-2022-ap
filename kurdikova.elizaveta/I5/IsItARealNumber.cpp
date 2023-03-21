#include "IsItARealNumber.h"
#include <cstddef>
#include <cctype>

bool isSign(char c)
{
  return c == '-' || c == '+';
}

bool isDigit(char c)
{
  return std::isdigit(c);
}

bool isDot(char c)
{
  return c == '.';
}

bool isEChar(char c)
{
  return c == 'E';
}

bool isEnd(char c)
{
  return c == '\0';
}

bool isUnsignedInteger(const char* data, size_t& shift)
{
  if (!isEnd(*(data + shift)) && isDigit(*(data + shift)))
  {
    shift++;
    if (isDot(*(data + shift)) || isEChar(*(data + shift)) || isEnd(*(data + shift)))
    {
      return true;
    }
    return isUnsignedInteger(data, shift);
  }
  return false;
}

bool isInOrder(const char* data, size_t& shift)
{
  size_t a = 0;
  bool result =  isEChar(*data) && isSign(*(data + 1)) && isUnsignedInteger(data + 2, a);
  shift += a + 2;
  return result;
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
