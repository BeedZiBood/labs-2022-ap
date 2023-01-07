#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Base-types.hpp"

class Shape
{
public:
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(point_t newpos) = 0;
  virtual void move(double delta_x, double delta_y) = 0;
  void makeSafeScale(double k);
  virtual void makeScale(double k) = 0;
  virtual Shape *clone() const = 0;
  virtual ~Shape() = default;
};

#endif
