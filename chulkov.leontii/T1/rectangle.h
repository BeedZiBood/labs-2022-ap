#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle: public Shape
{
  public:
    Rectangle(const double width, const double height, const point_t& pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(const double dx, const double dy) override;
    void scale(double k) override;

  private:
    point_t pos_;
    double width_;
    double height_;
};
#endif
