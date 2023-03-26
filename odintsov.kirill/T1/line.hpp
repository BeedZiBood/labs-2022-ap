#ifndef LINE_HPP
#define LINE_HPP

#include "base-types.hpp"

namespace odintsov {
  double getLineSegLength(const point_t& p1, const point_t& p2);
  point_t getLineIntersectionPoint(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4);
  point_t getLineSegIntersectionPoint(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4);
  bool isPointOnLineSeg(const point_t& p, const point_t& p1, const point_t& p2);
}

#endif
