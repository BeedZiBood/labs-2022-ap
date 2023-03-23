#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include <cstddef>
#include "basetype.h"
#include "shape.h"

namespace chulkov
{
  class CompositeShape {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& anotherCompShp);
    CompositeShape& operator=(const CompositeShape& anotherCompShp);
    CompositeShape(CompositeShape&& anotherCompShp);
    CompositeShape& operator=(CompositeShape&& anotherCompShp);
    ~CompositeShape();

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double dx, double dy);
    void scale(double k);
    void isotropScale(point_t pos, double k);

    void pushBack(Shape* shp);
    void popBack();
    void clear();
    bool empty() const;
    size_t size() const;
    void print() const;

  private:
    struct ShapeNode
    {
      ShapeNode* next;
      ShapeNode* prev;
      Shape* shape;
    };
    ShapeNode* first_;
    ShapeNode* last_;
    size_t size_;
  };
}

#endif