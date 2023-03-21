#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

namespace kryuchkova
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t &pos, const double radius);
    std::string getName() const;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void unsafeScale(double k) override;
    Shape *clone() const;
  private:
    point_t pos_;
    double radius_;
  };
}

#endif
