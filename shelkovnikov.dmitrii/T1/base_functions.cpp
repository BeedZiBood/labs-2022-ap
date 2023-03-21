#include "base_functions.h"
#include <cmath>
#include <stdexcept>
dimkashelk::point_t dimkashelk::getLeftDownPoint(rectangle_t rect)
{
  return point_t{rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2};
}
dimkashelk::point_t dimkashelk::getRightUpPoint(rectangle_t rect)
{
  return point_t{rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2};
}
bool dimkashelk::isRectangularTriangle(const point_t *points)
{
  double square[3]{0.0, 0.0, 0.0};
  for (size_t i = 0; i < 3; i++)
  {
    square[i] = std::pow(points[i].x - points[(i + 1) % 3].x, 2) + std::pow(points[i].y - points[(i + 1) % 3].y, 2);
  }
  bool result = false;
  for (size_t i = 0; i < 3; i++)
  {
    result = result || square[i]  == square[(i + 1) % 3] + square[(i + 2) % 3];
  }
  return result;
}
dimkashelk::point_t dimkashelk::getCenterOfWeight(const point_t *points, size_t size)
{
  double x_sum = 0.0;
  double y_sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    x_sum += points[i].x;
    y_sum += points[i].y;
  }
  return point_t{x_sum / size, y_sum / size};
}
dimkashelk::rectangle_t dimkashelk::makeRectangle(point_t left, point_t right)
{
  if (right.x <= left.x || right.y <= left.y)
  {
    throw std::logic_error("It isn't rectangle");
  }
  rectangle_t rect{point_t{(left.x + right.x) / 2, (left.y + right.y) / 2},right.x - left.x,right.y - left.y};
  return rect;
}
dimkashelk::point_t dimkashelk::getLeftDownPoint(point_t point1, point_t point2)
{
  return point_t{std::min(point1.x, point2.x), std::min(point1.y, point2.y)};
}
dimkashelk::point_t dimkashelk::getRightUpPoint(point_t point1, point_t point2)
{
  return point_t{std::max(point1.x, point2.x), std::max(point1.y, point2.y)};
}
dimkashelk::rectangle_t dimkashelk::getFrameRect(rectangle_t rect1, rectangle_t rect2)
{
  point_t left_down = getLeftDownPoint(getLeftDownPoint(rect1), getLeftDownPoint(rect2));
  point_t right_up = getRightUpPoint(getRightUpPoint(rect1), getRightUpPoint(rect2));
  return makeRectangle(left_down, right_up);
}
double dimkashelk::getMixedProduct(point_t p1_end, point_t p1_start, point_t p2_end, point_t p2_start)
{
  //         |i  j  k|
  // a * b = |x1 y1 0| = 0 * i + 0 * j + (x1 * y2 - x2 * y1) * k;
  //         |x2 y2 0|
  double a_x = p1_end.x - p1_start.x;
  double a_y = p1_end.y - p1_start.y;
  double b_x = p2_end.x - p2_start.x;
  double b_y = p2_end.y - p2_start.y;
  double third_coord = a_x * b_y - a_y * b_x;
  //             |x1 y1 0|
  // a * b * c = |x2 y2 0| = x1 * y2 * z3 - x2 * y1 * z3
  //             |0  0 z3|
  return a_x * b_y * third_coord - b_x * a_y * third_coord;
}
size_t dimkashelk::getCountTriangles(point_t point_1, point_t point_2, point_t point_3)
{
  double side_1 = std::sqrt(std::pow(point_2.x - point_1.x, 2) + std::pow(point_2.y - point_1.y, 2));
  double side_2 = std::sqrt(std::pow(point_3.x - point_1.x, 2) + std::pow(point_3.y - point_1.y, 2));
  double hypotenuse = std::max(side_1, side_2);
  double cathet = std::min(side_1, side_2);
  double angle_degrees = std::round((std::acos(cathet / hypotenuse) * 180.0 / PI) * 1000) / 1000;
  size_t size = static_cast< size_t >(360 / angle_degrees);
  if (size * angle_degrees != 360)
  {
    throw std::logic_error("Cannot build regular figure");
  }
  return size;
}
