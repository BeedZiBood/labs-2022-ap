#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
class Rectangle: public Shape
{
public:
  Rectangle(point_t left_down, point_t right_up);
  double getArea() const;
  rectangle_t gerFrameRectangle() const;
  void move(point_t position);
  void move(double dx, double dy);
  void scale(double k);
private:
  point_t left_down_;
  point_t right_up_;
};
#endif
