#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "polygon.hpp"

namespace chemodurov
{
  class Parallelogram: public Shape
  {
   public:
    Parallelogram(const point_t & fst, const point_t & sec, const point_t & trd);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & pos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape * clone() const override;
   private:
    Polygon p;
    Parallelogram(const Polygon & pol);
  };
}

#endif
