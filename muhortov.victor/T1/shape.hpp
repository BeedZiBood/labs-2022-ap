#ifndef GITLAB_LABS_SHAPE_HPP
#define GITLAB_LABS_SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(point_t newpos) = 0;
  virtual void move(double delta_x, double delta_y) = 0;
  void scaleCheck(double k);
  virtual void scaleWithoutCheck(double k) = 0;
  virtual Shape *clone() const = 0;
  virtual ~Shape() = default;
};

#endif
