#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace chemodurov
{
  class CompositeShape
  {
   public:
    CompositeShape();
    CompositeShape(const chemodurov::CompositeShape & rhs);
    CompositeShape(chemodurov::CompositeShape && rhs);
    CompositeShape(size_t capacity);
    CompositeShape(chemodurov::Shape ** shape, size_t size, size_t capacity);
    ~CompositeShape();
    chemodurov::CompositeShape & operator=(const chemodurov::CompositeShape & rhs);
    chemodurov::CompositeShape & operator=(chemodurov::CompositeShape && rhs);
    chemodurov::Shape * operator[](size_t id);
    const chemodurov::Shape * operator[](size_t id) const;
    chemodurov::Shape * at(size_t id);
    const chemodurov::Shape * at(size_t id) const;
    void push_back(const chemodurov::Shape * shp);
    void push_back(chemodurov::Shape * shp);
    void pop_back();
    bool empty() const noexcept;
    size_t size() const noexcept;
    double getArea() const;
    chemodurov::rectangle_t getFrameRect() const;
    void move(const chemodurov::point_t & position);
    void move(double dx, double dy);
    void scale(double k);
    void scale(const chemodurov::point_t & position, double k);
   private:
    chemodurov::Shape ** shape_;
    size_t size_;
    size_t capacity_;
  };
}

#endif
