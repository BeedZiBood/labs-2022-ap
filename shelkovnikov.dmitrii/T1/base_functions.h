#ifndef SPBSPU_LABS_2022_AAP_904_A_BASE_FUNCTIONS_H
#define SPBSPU_LABS_2022_AAP_904_A_BASE_FUNCTIONS_H
#include <cstddef>
#include "base_types.h"
#include "shape.h"
namespace dimkashelk
{
  constexpr double PI = 3.1415926;
  point_t getLeftDownPoint(rectangle_t rect);
  point_t getRightUpPoint(rectangle_t rect);
  bool isRectangularTriangle(const point_t *points);
  point_t getCenterOfWeight(const point_t *points, size_t size);
  rectangle_t makeRectangle(point_t left, point_t right);
  point_t getLeftDownPoint(point_t point1, point_t point2);
  point_t getRightUpPoint(point_t point1, point_t point2);
  rectangle_t getFrameRect(rectangle_t rect1, rectangle_t rect2);
  double getMixedProduct(point_t p1_end, point_t p1_start, point_t p2_end, point_t p2_start);
  size_t getCountTriangles(point_t point_1, point_t point_2, point_t point_3);
}
#endif
