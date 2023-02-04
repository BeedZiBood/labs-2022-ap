#ifndef TROANGLE
#define TRIANGLE

#include "shape.h"

class Triangle : public Shape
{
public:
  Triangle(point_t a, point_t b, point_t c);

  double getArea() override;
  rectangle_t getFrameRect() override;
  void move(double x, double y) override;
  void move(point_t pos) override;
  void scale(double k) override;
  Shape* clone() const override;

private:
  point_t a;
  point_t b;
  point_t c;

  point_t center;

  double aSide;
  double bSide;
  double cSide;
};

#endif
