#ifndef COMPOCITESHAPE_H
#define COMPOCITESHAPE_H

#include <cstddef>
#include <ostream>
#include "shape.h"

namespace dmitriev
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& otherCS);
    CompositeShape(CompositeShape&& othrerCS);
    ~CompositeShape();

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(point_t newPos);
    void scale(double k);
    void unsafeScale(double k);

    void isoScale(point_t pos, double k);
    void unsafeIsoScale(point_t pos, double k);

    void pushBack(Shape* newShape);
    void pushBack(const Shape* newShape);
    void popBack();
    Shape* at(size_t id);
    const Shape* at(size_t id) const;

    Shape* operator[](size_t id);
    const Shape* operator[](size_t id) const;
    CompositeShape& operator=(CompositeShape&& otherCS);
    CompositeShape& operator=(const CompositeShape& otherCS);

    bool empty() const;
    size_t sizeArr() const;
    void printInfo(std::ostream& out, char separator) const;

  private:
    size_t m_size;
    size_t m_capacity;
    Shape** m_arr;
  };
}

#endif