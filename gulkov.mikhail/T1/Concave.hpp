#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include <array>
#include "Base-types.hpp"
#include "Shape.hpp"

class Concave: public Shape
{
public:
  Concave(point_t one, point_t two, point_t three, point_t four);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t position) override;
  void move(double dx, double dy) override;
  void makeScale(double k) override;
  Shape *clone() const override;
private:
  point_t dots_[4];
  std::array< double, 6 > calcWithTriangles() const;
};

#endif
