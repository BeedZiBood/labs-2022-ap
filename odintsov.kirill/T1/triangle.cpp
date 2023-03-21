#include "triangle.hpp"
#include <cmath>
#include <algorithm>
#include "base-types.hpp"
#include "line.hpp"
#include "nearlyEquals.hpp"

bool odintsov::isTriangle(const point_t& p1, const point_t& p2, const point_t& p3)
{
  double a = getLineSegLength(p1, p2);
  double b = getLineSegLength(p1, p3);
  double c = getLineSegLength(p2, p3);
  double maxSide = std::max(std::max(a, b), c);
  return maxSide < a + b + c - maxSide;
}

double odintsov::getTriangleArea(const point_t& p1, const point_t& p2, const point_t& p3)
{
  double a = getLineSegLength(p1, p2);
  double b = getLineSegLength(p1, p3);
  double c = getLineSegLength(p2, p3);
  double s = (a + b + c) * 0.5;
  return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

bool odintsov::isPointStrictlyInsideTriangle(const point_t& p, const point_t& p1, const point_t& p2, const point_t& p3)
{
  double area1 = getTriangleArea(p1, p2, p);
  double area2 = getTriangleArea(p1, p3, p);
  double area3 = getTriangleArea(p2, p3, p);
  constexpr double epsilon = 0.00001;
  if (isPointOnLineSeg(p, p1, p2) || isPointOnLineSeg(p, p1, p3) || isPointOnLineSeg(p, p2, p3)) {
    return false;
  }
  return nearlyEquals(getTriangleArea(p1, p2, p3), area1 + area2 + area3, epsilon);
}
