#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

class Ellipse: public Shape {
public:
  Ellipse(point_t pos, double r1, double r2);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double dx, double dy) override;
  void scale(double k) override;
  Shape* clone() override;
private:
  double r1_, r2_;
  rectangle_t rect_;
};

#endif
