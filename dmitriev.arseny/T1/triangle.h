#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle: public Shape
{
public:
  Triangle(point_t a, point_t b, point_t c);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t newPos) override;
  void unsafeScale(double k) override;
  Shape* clone() const override;
private:
  point_t a;
  point_t b;
  point_t c;

};

#endif
