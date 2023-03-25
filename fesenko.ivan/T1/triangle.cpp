#include "triangle.h"
#include <cmath>
#include <algorithm>
#include "base-types.h"

bool isTriangle(const point_t &p1, const point_t &p2, const point_t &p3)
{
  const double e = 0.001;
  return std::abs((p1.x - p2.x) / (p1.y - p2.y) - (p1.x - p3.x) / (p1.y - p3.y)) > e;
}

double getTriangleArea(const point_t &p1, const point_t &p2, const point_t &p3)
{
  return 0.5 * std::abs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
}

bool isPointInsideTriangle(const point_t &p1, const point_t &p2, const point_t &p3, const point_t &p0)
{
  double product1 = (p1.x - p0.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p1.y - p0.y);
  double product2 = (p2.x - p0.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p0.y);
  double product3 = (p3.x - p0.x) * (p1.y - p3.y) - (p1.x - p3.x) * (p3.y - p0.y);
  return (product1 > 0 && product2 > 0 && product3 > 0) || (product1 < 0 && product2 < 0 && product3 < 0);
}
