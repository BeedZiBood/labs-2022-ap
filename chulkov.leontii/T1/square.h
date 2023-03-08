#ifndef SQUARE_H
#define SQUARE_H
#include "basetype.h"
#include "shape.h"

class Square: public Shape {
public:
  Square(const point_t& center, double side);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& newCenter) override;
  void move(double dx, double dy) override;
  void scale(double k) override;

private:
  point_t center_;
  double side_;
};
#endif
