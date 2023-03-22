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
  point_t getCenterParallelogram(point_t f_top, point_t s_top);
  double findModule(point_t f_top, point_t s_top);
  bool isParallelogram(point_t f_top, point_t s_top, point_t t_top);
  bool isDiamond(point_t f_t, point_t s_t, point_t t_t);
  point_t scalePoint(point_t point, point_t position, double k);
  point_t getCenterDiamond(point_t f_top, point_t s_top, point_t t_top);
}
#endif
