#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace chemodurov
{
  class Polygon: public Shape
  {
   public:
    Polygon(point_t * vertices, size_t number_of_vertices);
    Polygon(const Polygon & p);
    ~Polygon();
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t & position);
    void move(double dx, double dy);
    void scale(double k);
    Shape * clone() const;
   private:
    point_t * vertices_;
    size_t number_of_vertices_;
    point_t center_;
    Polygon(point_t * vertices, size_t number_of_vertices, point_t center);
  };
}

#endif
