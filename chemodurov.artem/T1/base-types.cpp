#include "base-types.hpp"

chemodurov::point_t chemodurov::operator+(const point_t & left, const point_t & right)
{
  point_t temp{left.x + right.x, left.y + right.y};
  return temp;
}
chemodurov::point_t chemodurov::operator*(const point_t & left, double k)
{
  point_t temp{left.x * k, left.y * k};
  return temp;
}
chemodurov::point_t chemodurov::operator-(const point_t & left, const point_t & right)
{
  point_t temp{left.x - right.x, left.y - right.y};
  return temp;
}
bool chemodurov::operator==(const point_t & left, const point_t & right)
{
  return (left.x == right.x && left.y == right.y);
}
