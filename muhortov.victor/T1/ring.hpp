#ifndef RING_HPP
#define RING_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Ring: public Shape
{
public:
  Ring(point_t one, double first, double second);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t newpos) override;
  void move(double delta_x, double delta_y) override;
  void scaleWithoutCheck(double k) override;
  Shape *clone() const override;
private:
  rectangle_t rectangle;
  double r1, r2;
};

#endif
