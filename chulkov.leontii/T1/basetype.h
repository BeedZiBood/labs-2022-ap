#ifndef BASETYPE_H
#define BASETYPE_H

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  point_t pos_;
  double width_;
  double height_;
};

point_t movePoint(point_t p, point_t dp);

#endif
