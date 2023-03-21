#include "IsRealNumber.hpp"
#include <cctype>

bool findDot(const char *);
bool afterDot(const char *);
bool findE(const char *);
bool findSign(const char *);
bool afterSign(const char *);
bool finish(const char *);

bool isSign(char x)
{
  return x == '+' || x == '-';
}

bool isDigit(char x)
{
  return std::isdigit(x);
}

bool isE(char x)
{
  return x == 'E';
}

bool isDot(char x)
{
  return x == '.';
}

bool isEnd(char x)
{
  return x == '\0';
}

bool start(const char *x)
{
  return isDigit(*x) && (start(x + 1) || findDot(x + 1));
}
bool findDot(const char *x)
{
  return isDot(*x) && afterDot(x + 1);
}
bool afterDot(const char *x)
{
  return isDigit(*x) && (afterDot(x + 1) || findE(x + 1));
}
bool findE(const char *x)
{
  return isE(*x) && (findSign(x + 1) || afterSign(x + 1) || finish(x + 1));
}
bool findSign(const char *x)
{
  return isSign(*x) && (afterSign(x + 1) || finish(x + 1));
}
bool afterSign(const char *x)
{
  return isDigit(*x) && (afterSign(x + 1) || finish(x + 1));
}
bool finish(const char *x)
{
  return isDigit(*x) && isEnd(*(x + 1));
}

bool isRealNum(const char *x)
{
  bool first_variant = isSign(*x) && (start(x + 1) || findDot(x + 1));
  bool second_variant = isDigit(*x) && (start(x + 1) || findDot(x + 1));
  bool third_variant = isDot(*x) && afterDot(x + 1);

  return first_variant || second_variant || third_variant;
}
