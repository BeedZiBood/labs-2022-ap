#ifndef BASETYPES_H
#define BASETYPES_H

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  point_t pos;
  double width;
  double height;
};

point_t countPointBetwen(point_t p1, point_t p2);
point_t addVector(point_t p, double dx, double dy);
point_t countShift(point_t oldCenter, point_t newCenter);
point_t multiplShift(point_t center, point_t point, double k);

#endif
