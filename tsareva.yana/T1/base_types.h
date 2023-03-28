#ifndef BASE_TYPES_H
#define BASE_TYPES_H
namespace tsareva
{
  struct point_t
  {
    double x;
    double y;
  };
  struct rectangle_t
  {
    double height;
    double width;
    point_t pos;
  };
  point_t movePoint(point_t point, point_t d_point);
  double findModule(point_t f_top, point_t s_top);
  bool isTriangle(point_t f_top, point_t s_top, point_t t_top);
  point_t scalePoint(point_t point, point_t position, double k);
  point_t getLeftDown(rectangle_t rectangle);
  point_t getRightUp(rectangle_t rectangle);
}
#endif
