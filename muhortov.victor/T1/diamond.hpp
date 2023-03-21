#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"

class Diamond: public Shape
{
public:
  Diamond(point_t one, point_t two, point_t three);
  Rectangle findLastDiamondPosition(point_t one, point_t two, point_t three);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t newpos) override;
  void move(double delta_x, double delta_y) override;
  void scaleWithoutCheck(double k) override;
  Shape *clone() const override;
private:
  Rectangle rectangle;
};

#endif
