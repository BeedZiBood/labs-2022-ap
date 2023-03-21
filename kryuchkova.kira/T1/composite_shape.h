#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H
#include <cstddef>
#include "base_types.h"
#include "shape.h"

namespace kryuchkova
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape &compositeShape);
    CompositeShape(CompositeShape &&compositeShape);
    CompositeShape &operator=(const CompositeShape &compositeShape);
    CompositeShape &operator=(CompositeShape &&compositeShape);
    ~CompositeShape();
    Shape *operator[](size_t index);
    const Shape *operator[](size_t index) const;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t point);
    void move(double dx, double dy);
    void scale(double k);
    void unsafeScale(double k);
    void isoScale(point_t point, double k);
    void unsafeIsoScale(point_t point, double k);
    void push_back(Shape *sh);
    void push_back (Shape const *sh);
    void pop_back();
    Shape* at(size_t index);
    const Shape* at(size_t index) const;
    bool empty() const;
    size_t size() const;
  private:
    size_t size_;
    size_t capacity_;
    Shape **shapes_;
    void free(Shape **shapes, size_t size);
  };
}

#endif
