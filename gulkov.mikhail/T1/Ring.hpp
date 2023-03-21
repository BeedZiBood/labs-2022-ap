#ifndef RING_HPP
#define RING_HPP

#include "Base-types.hpp"
#include "Shape.hpp"

class Ring: public Shape
{
public:
  Ring(point_t center, double r1, double r2);
  ~Ring();
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t newpos) override;
  void move(double delta_x, double delta_y) override;
  void makeScale(double k) override;
  Shape *clone() const override;
private:
  Shape *EllipseOne_;
  Shape *EllipseTwo_;
};

#endif
