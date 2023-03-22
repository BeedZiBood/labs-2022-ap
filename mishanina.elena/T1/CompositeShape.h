#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include <string>
#include <cstddef>
#include <stdexcept>
#include "shape.h"

class CompositeShape
{
public:
  CompositeShape();
  CompositeShape(const CompositeShape& compositeShape);
  CompositeShape(CompositeShape&& compositeShape) noexcept;
  ~CompositeShape();
  CompositeShape& operator=(const CompositeShape& compositeShape);
  CompositeShape& operator=(CompositeShape&& compositeShape) noexcept;
  Shape* operator[](std::size_t index);
  const Shape* operator[](std::size_t index) const;
  double getArea() const;
  void move(const point_t& point);
  void move(double dx, double dy);
  void scale(double k);
  CompositeShape* clone() const;
  void push_back(Shape* shape);
  void pop_back();
  Shape* at(std::size_t index);
  const Shape* at(std::size_t index) const;
  bool empty() const;
  std::size_t size() const;
  rectangle_t getFrameRect() const;
  void getName() const;
private:
  std::size_t size_;
  std::size_t capacity_;
  Shape** shapes_;
  CompositeShape(Shape** shapes, std::size_t capacity, std::size_t size);
  void remove(Shape** shapes, std::size_t size) const;
};

#endif
