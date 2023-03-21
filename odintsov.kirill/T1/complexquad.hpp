#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include "shape.hpp"

namespace odintsov {
  class ComplexQuad: public Shape {
    public:
      ComplexQuad(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4);

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double dx, double dy);
      void move(const point_t& pos);
      void scale(double k);
      ComplexQuad* clone() const;
    private:
      point_t p1_, p2_, p3_, p4_;

      point_t getMiddlePoint() const;
      point_t getIntersectionPoint() const;
  };
}

#endif
