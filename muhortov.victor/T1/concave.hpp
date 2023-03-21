#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include <array>
#include "base-types.hpp"
#include "shape.hpp"

class Concave: public Shape
{
public:
  Concave(point_t one, point_t two, point_t three, point_t four);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t newpos) override;
  void move(double delta_x, double delta_y) override;
  void scaleWithoutCheck(double k) override;
  Shape *clone() const override;
private:
  point_t positions[4];
  std::array< double, 6 > splitIntoTriangles() const;
};

#endif
