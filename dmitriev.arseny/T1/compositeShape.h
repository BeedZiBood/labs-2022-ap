#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H

#include "shape.h"

class CompositeShape
{
public:
  CompositeShape();
  CompositeShape(CompositeShape&& otherShape);
  CompositeShape(const CompositeShape& otherShape);

  ~CompositeShape();

  CompositeShape& operator=(const CompositeShape&& otherShape);

  double getArea();
  rectangle_t getFrameRect();
  void move(double x, double y);
  void move(point_t pos);
  void scale(double k);

  void isoScale(point_t posLeftBoard, double k);

  void push_back(Shape* shp);
  void push_back(Shape* const shp) const;
  void pop_back();
  Shape* at(unsigned id);
  const Shape* at(unsigned id) const;
  Shape* operator[](unsigned id);
  const Shape* operator[](unsigned id) const;
  bool empty();
  unsigned sizeArr();

private:
  unsigned size;
  unsigned capacity;
  Shape** arr;

  void clear();
};

#endif
