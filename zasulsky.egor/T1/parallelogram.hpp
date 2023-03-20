#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace zasulsky
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3);

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(const point_t& position);
    void unsafeScale(double k);
    Shape* clone() const;
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    point_t getCenter() const;
  };
}
#endif
