#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle: public Shape
{
public:
  Triangle(point_t m_a, point_t m_b, point_t m_c);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t newPos) override;
  void unsafeScale(double k) override;
  Shape* clone() const override;
private:
  point_t m_a;
  point_t m_b;
  point_t m_c;

};

#endif
