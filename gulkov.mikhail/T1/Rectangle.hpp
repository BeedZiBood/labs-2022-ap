#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Base-types.hpp"
#include "Shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(point_t one, point_t two);
  explicit Rectangle(rectangle_t rectangle);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t position) override;
  void move(double dx, double dy) override;
  void makeScale(double k) override;
  Shape *clone() const override;
private:
  rectangle_t rect_;
};

#endif
