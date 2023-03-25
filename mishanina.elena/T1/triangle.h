#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>
#include <stdexcept>
#include <cmath>
#include "shape.h"

class Triangle: public Shape
{
public:
  Triangle(const point_t& A, const point_t& B, const point_t& C);
  std::string getName() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void scale(double k) override;
  void move(double dx, double dy) override;
  Shape* clone() const override;

private:
  point_t A_, B_, C_;
};

#endif
