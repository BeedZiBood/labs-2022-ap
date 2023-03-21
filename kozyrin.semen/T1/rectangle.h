#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

namespace kozyrin {
  class Rectangle: public Shape {
  public:
    Rectangle(point_t p1, point_t p2);
    explicit Rectangle(rectangle_t rect);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape* clone() override;
  private:
    rectangle_t rect_;
  };
}

#endif
