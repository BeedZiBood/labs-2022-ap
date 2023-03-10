#include "base-types.h"

void addVector(point_t& point, vector_t vector)
{
  point.x += vector.x;
  point.y += vector.y;
}

vector_t getVector(point_t p1, point_t p2)
{
  return {p2.x - p1.x, p2.y - p1.y};
}

vector_t vector_t::operator*(double k)
{
   return {x * k, y * k};
}