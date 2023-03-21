#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace tarasenko
{
  class Rectangle: public Shape
  {
  public:
   Rectangle(point_t point_ld, point_t point_ru);
   Rectangle(rectangle_t rect);
   double getArea() const override;
   rectangle_t getFrameRect() const override;
   void move(point_t pos) override;
   void move(double dx, double dy) override;
   void scale(double k) override;
   Shape * clone() const override;
  private:
   rectangle_t rect_;
  };
}
#endif
