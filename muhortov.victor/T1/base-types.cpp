#include "base-types.hpp"
#include <cmath>
#include <stdexcept>

double calculatePointsDistance(const point_t &p1, const point_t &p2)
{
  double line_x = p1.x - p2.x;
  double line_y = p1.y - p2.y;
  return std::sqrt(line_x * line_x + line_y * line_y);
}

point_t findDeltaScale(point_t pos, scale_t scale)
{
  return {(pos.x - scale.pos.x) * scale.scale, (pos.y - scale.pos.y) * scale.scale};
}

point_t calculateVectorSum(point_t position, double delta_x, double delta_y)
{
  position.x += delta_x;
  position.y += delta_y;
  return position;
}

point_t calculateVectorDifference(point_t position, double delta_x, double delta_y)
{
  return calculateVectorSum(position, -delta_x, -delta_y);
}

point_t multiplicationVector(point_t position, double k)
{
  position.x *= k;
  position.y *= k;
  return position;
}

point_t calculateScale(point_t position, point_t center, double k)
{
  return calculateVectorSum(multiplicationVector(calculateVectorDifference(position, center.x, center.y), k), center.x, center.y);
}

double calculateTriangleArea(const double &a, const double &b, const double &c)
{
  double p = (a + b + c) / 2;
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

bool checkingSideForPosition(const point_t &one, const point_t &two, const point_t &four)
{
  return ((one.x - four.x) * (two.y - one.y) - (two.x - one.x) * (one.y - four.y)) > 0;
}

bool checkingTriangle(const point_t &one, const point_t &two, const point_t &three)
{
  double a = calculatePointsDistance(three, one);
  double b = calculatePointsDistance(two, one);
  double c = calculatePointsDistance(three, two);
  return a + b < c || a + c < b || b + c < a;
}

bool checkingPosition(const point_t &one, const point_t &two, const point_t &three, const point_t &four)
{
  bool trOne = checkingSideForPosition(one, two, four);
  bool trTwo = checkingSideForPosition(two, three, four);
  bool trThree = checkingSideForPosition(three, one, four);;
  return !((trOne && trTwo && trThree) || (!trOne && !trTwo && !trThree));
}

bool checkingConcave(const point_t &one, const point_t &two, const point_t &three, const point_t &four)
{
  return (checkingTriangle(one, two, three) || one.x == four.x || one.y == four.y || checkingPosition(one, two, three, four));
}

point_t calcPosXY(point_t pos, point_t center)
{
  return {pos.x - (pos.x - center.x) * 2.0, pos.y - (pos.y - center.y) * 2.0};
}
