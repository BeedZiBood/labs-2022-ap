#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include <cstddef>
#include "basetype.h"
#include "shape.h"

class CompositeShape
{
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& anotherCompShp);
    CompositeShape(CompositeShape&& anotherCompShp);
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& anotherCompShp);
    CompositeShape& operator=(CompositeShape&& anotherCompShp);

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t position);
    void move(double dx, double dy);
    void scale(double k);
    void isotropScale(point_t pos, double k);

    void pushBack(Shape* shp);
    void popBack();
    Shape* at(size_t id) const;
    Shape* operator[](size_t id) const;
    bool empty() const;
    size_t size() const;

  private:
    size_t size_;
    Shape** shp_;
};
#endif