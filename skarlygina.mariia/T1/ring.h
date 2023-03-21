#ifndef RING_H
#define RING_H
#include "shape.h"
#include "ellipse.h"
class Ring: public Shape
{
public:
  Ring(point_t center, double radius_small, double radius_big);
  double getArea() const override;
  rectangle_t getFrameRectangle() const override;
  void move(point_t position) override;
  void move(double dx, double dy) override;
  void scale(double k) override;
private:
  Ellipse smallEllipse_;
  Ellipse bigEllipse_;
};
#endif
