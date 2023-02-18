#ifndef BASETYPES_HPP
#define BASETYPES_HPP
namespace tarasenko
{
  struct point_t
  {
    double x_, y_;
  };
  point_t operator+(const point_t & point_1, const point_t & point_2);

  struct rectangle_t
  {
    double width_, height_;
    point_t pos_;
  };
}
#endif
