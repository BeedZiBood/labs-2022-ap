#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

namespace chulkov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t width, point_t height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(const double dx, const double dy) override;
    void unsafeScale(double k) override;
    Shape* clone() const;

  private:
    rectangle_t rect_;
  };
}

#endif
