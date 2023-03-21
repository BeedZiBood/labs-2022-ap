#include "realnumberchecker.h"
#include <cctype>
bool is_sign(const char number)
{
  return number == '-' || number == '+';
}
bool is_digit(const char number)
{
  return std::isdigit(number);
}
bool is_unsigned_integer(const char *number)
{
  if (!number[0])
  {
    return true;
  }
  return is_digit(number[0]) && is_unsigned_integer(number + 1);
}
bool order(const char *number)
{
  return (is_sign(number[0]) && is_unsigned_integer(number + 1)) || is_unsigned_integer(number);
}
bool mantissa_with_point(const char *number)
{
  if (number[0] == 'E')
  {
    return order(number + 1);
  }
  if (number[0] == '.')
  {
    return false;
  }
  return is_digit(number[0]) && mantissa_with_point(number + 1);
}
bool mantissa(const char *number)
{
  if (number[0] == 'E')
  {
    return order(number + 1);
  }
  if (number[0] == '.')
  {
    return mantissa_with_point(number + 1);
  }
  return is_digit(number[0]) && mantissa(number + 1);
}
bool is_real_number(const char *number)
{
  return is_sign(number[0]) && mantissa(number + 1);
}
