#include "Base-types.hpp"
#include <cmath>

double calcVectorLength(const point_t &p1, const point_t &p2)
{
  double line_x = p1.x - p2.x;
  double line_y = p1.y - p2.y;
  return std::sqrt(line_x * line_x + line_y * line_y);
}

bool checkTriangles(point_t dots[])
{
  bool triangle1 = validateTriangle(dots[0], dots[1], dots[3]);
  bool triangle2 = validateTriangle(dots[1], dots[2], dots[3]);
  bool triangle3 = 0.0;

  if (!triangle1 && !triangle2)
  {
    triangle3 = validateTriangle(dots[2], dots[0], dots[3]);
    if (!triangle3)
    {
      return false;
    }
  }
  return true;
}

bool validateTriangle(point_t a, point_t b, point_t c)
{
  return std::abs((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)) == 0;
}

bool validateConcave(point_t dots[])
{
  return dots[0].y == dots[3].y || checkTriangles(dots);
}

point_t addVector(point_t dot, double dx, double dy)
{
  dot.x += dx;
  dot.y += dy;
  return dot;
}

point_t scaleDelta(point_t pos, scale_t scale)
{
  return {(pos.x - scale.pos.x) * scale.scale, (pos.y - scale.pos.y) * scale.scale};
}

point_t getVectorDiff(point_t position, point_t delta)
{
  return {position.x - delta.x, position.y - delta.y};
}
