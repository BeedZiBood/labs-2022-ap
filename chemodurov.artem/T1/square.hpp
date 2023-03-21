#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "polygon.hpp"

namespace chemodurov
{
  class Square: public Shape
  {
   public:
    Square(const point_t & left_down, double length);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & position) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape * clone() const override;
   private:
    Polygon p;
    Square(const Polygon & p);
  };
}

#endif
