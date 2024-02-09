#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace dmitriev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftBott, point_t rightTop);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t newPos) override;
    void unsafeScale(double k) override;
    Shape* clone() const override;

  private:
    rectangle_t m_rect;
  };
}

#endif