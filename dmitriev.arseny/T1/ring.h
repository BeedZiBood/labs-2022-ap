#ifndef RING
#define RING

#include "shape.h"

class Ring : public Shape
{
public:

  Ring(point_t center, double externalRadius, double internalRadius);

  double getArea() override;
  rectangle_t getFrameRect() override;
  void move(double x, double y) override;
  void move(point_t pos) override;
  void scale(double k) override;
  Shape* clone() const override;

private:
  point_t center;
  double externalRadius;
  double internalRadius;
};

#endif
