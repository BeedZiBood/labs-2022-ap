#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "polygon.hpp"

namespace chemodurov
{
  class Rectangle: public Shape
  {
   public:
    Rectangle(const point_t & left_down, const point_t & right_up);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & position) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape * clone() const override;
   private:
    Polygon p;
    Rectangle(const Polygon & p);
  };
}

#endif
