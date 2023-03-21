#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>
#include <stdexcept>
#include "shape.h"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t& ld_point, const point_t& ru_point);
  std::string getName() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void scale(double k) override;
  void move(double dx, double dy) override;
  Shape* clone() const override;

private:
  point_t ld_point_, ru_point_;
};

#endif
