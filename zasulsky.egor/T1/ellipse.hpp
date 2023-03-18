#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace zasulsky
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(const point_t& center, double radiusVerical, double radiusHorizontal);

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(const point_t& position);
    void unsafeScale(double k);
  private:
    point_t center_;
    double radiusVertical_;
    double radiusHorizontal_;
  };
}
#endif
