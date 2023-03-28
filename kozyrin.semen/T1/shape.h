#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.h"

namespace kozyrin {
  class Shape {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
    virtual Shape* clone() = 0;
    virtual ~Shape() = default;
  };

  void isoScale(Shape* shp, point_t point, double k);
}

#endif
