#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H
#include "shape.h"

class Complexquad: public Shape {
public:
  explicit Complexquad(point_t p0, point_t p1, point_t p2, point_t p3);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double dx, double dy) override;
  void scale(double k) override;
  Shape* clone() override;
private:
  point_t pointArr_[4];
  point_t center_;
};

#endif
