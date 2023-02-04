#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.h"

class Shape
{
public:
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual void move(double x, double y) = 0;
  virtual void move(point_t pos) = 0;
  virtual void scale(double k) = 0;
  virtual Shape* clone() const = 0;

};

#endif
