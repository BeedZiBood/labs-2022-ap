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

rectangle_t makeNewRect(point_t leftBott, point_t rightTop);
point_t shiftPoint(point_t source, double x, double y);
point_t multVec(point_t begin, point_t end, double k);

#endif
