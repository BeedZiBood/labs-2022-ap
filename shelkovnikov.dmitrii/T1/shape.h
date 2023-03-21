#ifndef SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#include <stdexcept>
#include "base_types.h"
namespace dimkashelk
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double delta_x, double delta_y) = 0;
    virtual void scale(double k);
    virtual void unsafeScale(double k) noexcept = 0;
    virtual Shape* clone() const = 0;
    virtual ~Shape() = default;
  };
}
#endif
