#include "isFloat.h"
#include <iostream>
bool isSign(const char *arr);
bool isDigit(const char *arr);
bool isNumber(const char *arr);
bool isExponent(const char *arr);
bool isMantissa(const char *arr);
bool isSign(const char *arr)
{
  return (*arr == '+' || *arr == '-');
}
bool isDigit(const char *arr)
{
  return std::isdigit(*arr) || !*arr;
}
bool isNumber(const char *arr)
{
  if (!(*arr))
  {
    return (!(*arr));
  }
  if (*arr == 'E')
  {
    return isExponent(arr);
  }
  return isDigit(arr) && isNumber(arr + 1);
}
bool isExponent(const char *arr)
{
  return (*arr == 'E') && (isSign(arr + 1) && isNumber(arr + 2));
}
bool isMantissa(const char *arr)
{
  return (*arr == '.') && isNumber(arr + 1);
}
bool isReal(const char *arr)
{
  return isSign(arr) && isMantissa(arr + 1);
}
