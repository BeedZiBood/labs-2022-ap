#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Base-types.hpp"
#include "Shape.hpp"

class Ellipse: public Shape
{
public:
  Ellipse(point_t one, double first, double second);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t position) override;
  void move(double dx, double dy) override;
  void makeScale(double k) override;
  Shape *clone() const override;
private:
  rectangle_t rect_;
  double r1_;
  double r2_;
};

#endif
