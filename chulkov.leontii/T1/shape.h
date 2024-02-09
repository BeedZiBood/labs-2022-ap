#ifndef SHAPE_HP
#define SHAPE_HP
#include <iomanip>
#include "basetype.h"

namespace chulkov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& pos) = 0;
    virtual void move(const double dx, const double dy) = 0;
    virtual void unsafeScale(double k) = 0;
    virtual Shape* clone() const = 0;
    void scale(double k);
  };
}

#endif