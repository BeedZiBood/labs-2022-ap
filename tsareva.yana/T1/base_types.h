#ifndef BASE_TYPES_H
#define BASE_TYPES_H
struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  double height;
  double width;
  point_t position;
};

point_t movePoint(point_t point, point_t d_point);
#endif
