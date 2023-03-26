#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace odintsov {
  class Rectangle: public Shape {
    public:
      explicit Rectangle(const rectangle_t& rect);
      Rectangle(const point_t& p1, const point_t& p2);

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double dx, double dy);
      void move(const point_t& pos);
      void scale(double k);
      Rectangle* clone() const;
    private:
      rectangle_t rect_;
  };
}

#endif
