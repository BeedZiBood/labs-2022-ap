#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
  Rectangle(point_t leftBott, point_t rightTop);

  double getArea() override;
  rectangle_t getFrameRect() override;
  void move(double x, double y) override;
  void move(point_t pos) override;
  void scale(double k) override;
  Shape* clone() const override;

private:
  rectangle_t rect;

};

#endif
