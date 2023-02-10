#ifndef COMPOCITESHAPE_H
#define COMPOCITESHAPE_H

#include "shape.h"

class CompociteShape
{
public:
  CompociteShape();
  CompociteShape(const CompociteShape& otherCS);
  CompociteShape(CompociteShape&& othreCS);
  ~CompociteShape();

  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double dx, double dy);
  void move(point_t newPos);
  void scale(double k);

  void isoScale(point_t pos, double k);

  void push_back(Shape* newShape);
  Shape* operator[](unsigned id);
  const Shape* operator[](unsigned id) const;
  unsigned sizeArr() const;

private:
  unsigned size;
  unsigned capacity;
  Shape** arr;

  void clear(Shape** arr, unsigned size);
};

#endif
