#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
namespace tsareva
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t l_d, point_t r_up);
    double getArea() const override;
    rectangle_t getFrameRectangle() const override;
    void move(point_t position) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    rectangle_t rectangle_;
  };
}
#endif
