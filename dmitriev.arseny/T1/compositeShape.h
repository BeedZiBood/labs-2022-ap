#ifndef COMPOCITESHAPE_H
#define COMPOCITESHAPE_H

#include "shape.h"

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

  void isoScale(point_t pos, double k);

  void push_back(Shape* newShape);
  void push_back(const Shape* newShape);
  void pop_back();
  Shape* at(unsigned id);
  const Shape* at(unsigned id) const;

  Shape* operator[](unsigned id);
  const Shape* operator[](unsigned id) const;
  CompositeShape& operator=(CompositeShape& otherCS);
  CompositeShape& operator=(const CompositeShape& otherCS);

  bool empty();
  unsigned sizeArr() const;

private:
  unsigned size;
  unsigned capacity;
  Shape** arr;

  void clear(Shape** arr, unsigned size);
};

#endif
