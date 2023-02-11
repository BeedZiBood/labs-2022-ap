#include "compositeShape.h"
#include <iostream>

CompociteShape::CompociteShape() :
  size(0),
  capacity(10),
  arr(new Shape* [capacity])
{
}

CompociteShape::CompociteShape(const CompociteShape& otherCS) :
  size(otherCS.size),
  capacity(otherCS.capacity),
  arr(new Shape* [capacity])
{
  for (unsigned i = 0; i < size; i++)
  {
    arr[i] = otherCS.arr[i]->clone();
  }
}

CompociteShape::CompociteShape(CompociteShape&& othreCS) :
  size(otherCS.size),
  capacity(otherCS.capacity),
  arr(othreCS.arr)
{
  othreCS.size = 0;
  othreCS.capacity = 0;
  othreCS.arr = nullptr;
}

CompociteShape::~CompociteShape()
{
  clear(arr, size);
}

double CompociteShape::getArea() const
{
  double area = 0;
  for (unsigned i = 0; i < size; i++)
  {
    area = area + arr[i]->getArea();
  }
  return area;
}

rectangle_t CompociteShape::getFrameRect() const
{
  double minX = arr[0]->getFrameRect().center.x - arr[0]->getFrameRect().width / 2;
  double minY = arr[0]->getFrameRect().center.y - arr[0]->getFrameRect().height / 2;
  double maxX = arr[0]->getFrameRect().center.x + arr[0]->getFrameRect().width / 2;
  double maxY = arr[0]->getFrameRect().center.y + arr[0]->getFrameRect().height / 2;

  for (unsigned i = 1; i < size; i++)
  {
    minX = std::min(minX, arr[i]->getFrameRect().center.x - arr[i]->getFrameRect().width / 2);
    minY = std::min(minY, arr[i]->getFrameRect().center.y - arr[i]->getFrameRect().height / 2);
    maxX = std::max(maxX, arr[i]->getFrameRect().center.x + arr[i]->getFrameRect().width / 2);
    maxY = std::max(maxY, arr[i]->getFrameRect().center.y + arr[i]->getFrameRect().height / 2);
  }

  return makeNewRect(point_t{ minX, minY }, point_t{ maxX, maxY });
}

void CompociteShape::move(double dx, double dy)
{
  for (unsigned i = 0; i < size; i++)
  {
    arr[i]->move(dx, dy);
  }
}

void CompociteShape::move(point_t newPos)
{
  for (unsigned i = 0; i < size; i++)
  {
    arr[i]->move(newPos);
  }
}

void CompociteShape::scale(double k)
{
  for (unsigned i = 0; i < size; i++)
  {
    arr[i]->scale(k);
  }
}

void CompociteShape::isoScale(point_t pos, double k)
{
  for (unsigned i = 0; i < size; i++)
  {
    point_t p1{ arr[i]->getFrameRect().center.x, arr[i]->getFrameRect().center.y };
    arr[i]->move(pos);
    point_t p2{ arr[i]->getFrameRect().center.x, arr[i]->getFrameRect().center.y };

    double dx = k * (p1.x - p2.x);
    double dy = k * (p1.y - p2.y);
    arr[i]->scale(k);
    arr[i]->move(dx, dy);
  }
}

void CompociteShape::push_back(Shape* newShape)
{
  if (size == capacity)
  {
    capacity = capacity + 10;
    Shape** newArr = new Shape * [capacity];
    for (unsigned i = 0; i < size; i++)
    {
      newArr[i] = arr[i]->clone();
    }
    clear(arr, size);
    arr = newArr;
  }
  arr[size++] = newShape;
}

Shape* CompociteShape::operator[](unsigned id)
{
  return arr[id];
}

const Shape* CompociteShape::operator[](unsigned id) const
{
  return arr[id]->clone();
}

unsigned CompociteShape::sizeArr() const
{
  return size;
}

void CompociteShape::clear(Shape** arr, unsigned size)
{
  for (unsigned i = 0; i < size; i++)
  {
    delete[]arr[i];
  }
  delete[]arr;
}
