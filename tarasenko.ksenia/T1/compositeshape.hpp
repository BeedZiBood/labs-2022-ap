#ifndef  COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include "shape.hpp"
#include "cstddef"
namespace tarasenko
{
  class CompositeShape
  {
  public:
   CompositeShape();
   CompositeShape(Shape ** shp, size_t size, size_t capacity);
   ~CompositeShape();
   size_t size() const;
   double getArea() const;
   rectangle_t getFrameRect() const;
   void move(point_t pos);
   void move(double dx, double dy);
   void scale(double k);
   void push_back(Shape * shp);
   void push_back(const Shape * shp);
   void pop_back();
   Shape * at(size_t id);
   const Shape * at(size_t id) const;
   Shape * operator[](size_t id);
   const Shape * operator[](size_t id) const;
   bool empty() const;
   CompositeShape * clone() const;
  private:
   size_t size_;
   size_t capacity_;
   Shape ** shapes;
   void deleteCompositeShape(Shape ** shapes, size_t size_) const;
  };
}
#endif
