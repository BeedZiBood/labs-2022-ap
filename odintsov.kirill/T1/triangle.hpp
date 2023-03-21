#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "base-types.hpp"

namespace odintsov {
  bool isTriangle(const point_t& p1, const point_t& p2, const point_t& p3);
  double getTriangleArea(const point_t& p1, const point_t& p2, const point_t& p3);
  bool isPointStrictlyInsideTriangle(const point_t& p, const point_t& p1, const point_t& p2, const point_t& p3);
}

#endif
