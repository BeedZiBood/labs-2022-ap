#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.h"

namespace dmitriev
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void move(point_t pos) = 0;
    void scale(double k);
    virtual void unsafeScale(double k) = 0;
    virtual Shape* clone() const = 0;
    virtual ~Shape() = default;

  };
}

#endif
