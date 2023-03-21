#ifndef T1_COMPOSITESHAPE_H
#define T1_COMPOSITESHAPE_H
#include <cstddef>
#include "shape.hpp"

class CompositeShape
{
public:
  explicit CompositeShape();
  CompositeShape(const CompositeShape &compositeShape);
  CompositeShape(Shape **shapes, size_t capacity, size_t size);
  CompositeShape &operator=(const CompositeShape &compositeShape);
  CompositeShape &operator=(CompositeShape &compositeShape) noexcept;
  ~CompositeShape();
  CompositeShape * clone() const;
  void push_back(Shape *shape);
  void push_back(const Shape *shape);
  void pop_back();
  Shape *at(size_t i);
  const Shape *at(size_t i) const;
  Shape *operator[](size_t i);
  const Shape *operator[](size_t i) const;
  bool empty() const;
  size_t size() const;
  rectangle_t getFrameRect() const;
  double getArea() const;
  void move(point_t position);
  void move(double delta_x, double delta_y);
  void scale(scale_t scale);
  void scaleCheck(scale_t scale);
  void scaleWithoutChecking(scale_t scale);
private:
  size_t capacity_;
  Shape **shapes;
  size_t size_;
  void destruct(Shape **shape, size_t size) const;
};

#endif
