#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

namespace chulkov
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t& pos, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(const double dx, const double dy) override;
    void unsafeScale(double k) override;
    Shape* clone() const;

  private:
    point_t pos_;
    double radius_;
  };
}
#endif
