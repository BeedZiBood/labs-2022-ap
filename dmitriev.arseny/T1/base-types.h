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

#endif
