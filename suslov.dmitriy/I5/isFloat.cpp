#include "isFloat.h"

bool sign(char arr[], int &counter)
{
  if (arr[counter] == '+' || arr[counter] == '-')
  {
    counter++;
    return true;
  }
  return false;
}
bool digit(char arr[], int &iterator)
{
  if (arr[iterator] >= '0' and arr[iterator] <= '9')
  {
    iterator++;
    return true;
  }
  return false;
}
bool number(char arr[], int &iterator)
{
  if (digit(arr, iterator))
  {
    number(arr, iterator);
    return true;
  }
  return false;
}
bool exponent(char arr[], int &iterator)
{
  if (arr[iterator] == 'E')
  {
    iterator++;
    sign(arr, iterator);
    return number(arr, iterator);
  }
  return false;
}
bool mantissa(char arr[], int &iterator)
{
  if (arr[iterator] == '.')
  {
    iterator++;
    return number(arr, iterator);
  }
  return false;
}
bool real(char arr[], int &iterator)
{
  sign(arr, iterator);
  if (mantissa(arr, iterator))
  {
    return exponent(arr, iterator);
  }
  return false;
}
