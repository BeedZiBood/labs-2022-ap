#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include "rectangle.h"

class Square: public Shape
{
  public:
    Square(const point_t& pos, double side);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape* clone() const;

  private:
    Rectangle rect_;
};
#endif
