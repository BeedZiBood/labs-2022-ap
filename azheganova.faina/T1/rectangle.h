#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "shape.h"

Shape* inputRectangle(std::istream &input);

class Rectangle : virtual public Shape
{
  public:
    explicit Rectangle(rectangle_t rectangle);
    Rectangle(point_t point1, point_t point2);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t position);
    void move(double dx, double dy);
    void scale(double k) noexcept;
    Shape * clone() const override;
  private:
    rectangle_t rectangle1;
};

#endif
