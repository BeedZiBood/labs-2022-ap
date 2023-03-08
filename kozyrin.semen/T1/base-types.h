#ifndef BASE_TYPES_H
#define BASE_TYPES_H

struct point_t {
  double x, y;
};

struct rectangle_t {
  double width, height;
  point_t pos;
};

void addVector(point_t& point, double dx, double dy);

#endif
