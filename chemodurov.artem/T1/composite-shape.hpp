#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace chemodurov
{
  class CompositeShape
  {
   public:
    CompositeShape(const CompositeShape & rhs);
    CompositeShape(CompositeShape && rhs);
    CompositeShape(size_t capacity);
    ~CompositeShape();
    CompositeShape & operator=(const CompositeShape & rhs);
    CompositeShape & operator=(CompositeShape && rhs);
    Shape * operator[](size_t id);
    const Shape * operator[](size_t id) const;
    Shape * at(size_t id);
    const Shape * at(size_t id) const;
    void push_back(const Shape * shp);
    void push_back(Shape * shp);
    void pop_back();
    bool empty() const noexcept;
    size_t size() const noexcept;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t & position);
    void move(double dx, double dy);
    void scale(double k);
    void scale(const point_t & position, double k);
   private:
    Shape ** shape_;
    size_t size_;
    size_t capacity_;
  };
}

#endif
