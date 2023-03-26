#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include "rectangle.h"

namespace kryuchkova
{
  class Square: public Shape
  {
  public:
    Square(const point_t &lb_point, const double length);
    std::string getName() const;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void unsafeScale(double k) override;
    Shape * clone() const;
  private:
    Rectangle square_;
    Square(const Rectangle &rectangle);
  };
}

#endif
