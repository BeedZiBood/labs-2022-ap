#include "workWithArray.h"

Shape **expandArray(Shape **shapes, size_t &capacity)
{
  Shape** newShapes = new Shape*[capacity + 10];
  for (size_t i = 0; i < capacity; i++) {
    newShapes[i] = shapes[i];
  }
  capacity += 10;
  return newShapes;
}

void deleteArray(Shape **shapes, size_t size)
{
  for (size_t i = 0; i < size; i++) {
    delete shapes[i];
  }
  delete [] shapes;
}

