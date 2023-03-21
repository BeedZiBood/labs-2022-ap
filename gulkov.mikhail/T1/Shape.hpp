#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Base-types.hpp"

class Shape
{
public:
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(point_t position) = 0;
  virtual void move(double dx, double dy) = 0;
  void makeSafeScale(double k);
  virtual void makeScale(double k) = 0;
  virtual Shape *clone() const = 0;
  virtual ~Shape() = default;
};

#endif
