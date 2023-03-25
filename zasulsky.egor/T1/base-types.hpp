#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace zasulsky
{
  struct point_t
  {
    double x, y;
  };
  struct rectangle_t
  {
    double width, height;
    point_t pos;
  };
  void isoScalePoint(point_t& p, const point_t& center, double k);
  void unsafeIsoScalePoint(point_t& p, const point_t& center, double k);
  void movePoint(point_t& p, double dx, double dy);
  rectangle_t getFrameRectFromCorners(const point_t& bl, const point_t& tr);
  point_t getMidPoint(const point_t& p1, const point_t& p2);
}
#endif
