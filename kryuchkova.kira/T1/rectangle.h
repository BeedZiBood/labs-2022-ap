#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

namespace kryuchkova
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t &lb_point, const point_t &ru_point);
    std::string getName() const;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void unsafeScale(double k) override;
    Shape *clone() const override;
  private:
    point_t lb_point_;
    point_t ru_point_;
  };

  point_t getCentre(point_t point1, point_t point2);
}

#endif
