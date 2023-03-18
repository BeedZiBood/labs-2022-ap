#include "compositeShape.h"
#include <stdexcept>
#include <algorithm>

CompositeShape::CompositeShape():
  size(0),
  capacity(10),
  arr(new Shape* [capacity])
{
}

void clear(Shape** arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete arr[i];
  }
  delete[]arr;
}

CompositeShape::CompositeShape(const CompositeShape& otherCS):
  size(otherCS.size),
  capacity(otherCS.capacity),
  arr(new Shape* [capacity])
{
  for (size_t i = 0; i < size; i++)
  {
    try
    {
      arr[i] = otherCS.arr[i]->clone();
    }
    catch(const std::bad_alloc& e)
    {
      clear(arr, i);
      throw;
    }
  }
}

CompositeShape::CompositeShape(CompositeShape&& othrerCS):
  size(othrerCS.size),
  capacity(othrerCS.capacity),
  arr(othrerCS.arr)
{
  othrerCS.size = 0;
  othrerCS.capacity = 0;
  othrerCS.arr = nullptr;
}

CompositeShape::~CompositeShape()
{
  clear(arr, size);
}

double CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    area = area + arr[i]->getArea();
  }
  return area;
}

rectangle_t CompositeShape::getFrameRect() const
{
  if (size == 0)
  {
    throw std::logic_error("no elements in arr");
  }
  double minX = arr[0]->getFrameRect().center.x - arr[0]->getFrameRect().width / 2;
  double minY = arr[0]->getFrameRect().center.y - arr[0]->getFrameRect().height / 2;
  double maxX = arr[0]->getFrameRect().center.x + arr[0]->getFrameRect().width / 2;
  double maxY = arr[0]->getFrameRect().center.y + arr[0]->getFrameRect().height / 2;

  for (size_t i = 1; i < size; i++)
  {
    minX = std::min(minX, arr[i]->getFrameRect().center.x - arr[i]->getFrameRect().width / 2);
    minY = std::min(minY, arr[i]->getFrameRect().center.y - arr[i]->getFrameRect().height / 2);
    maxX = std::max(maxX, arr[i]->getFrameRect().center.x + arr[i]->getFrameRect().width / 2);
    maxY = std::max(maxY, arr[i]->getFrameRect().center.y + arr[i]->getFrameRect().height / 2);
  }
  return makeNewRect(point_t{ minX, minY }, point_t{ maxX, maxY });
}

void CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size; i++)
  {
    arr[i]->move(dx, dy);
  }
}

void CompositeShape::move(point_t newPos)
{
  for (size_t i = 0; i < size; i++)
  {
    arr[i]->move(newPos);
  }
}

void CompositeShape::scale(double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("invalid argument");
  }
  unsafeScale(k);
}

void CompositeShape::unsafeScale(double k)
{
  for (size_t i = 0; i < size; i++)
  {
    arr[i]->unsafeScale(k);
  }
}

void CompositeShape::isoScale(point_t pos, double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("invalid argument");
  }
  if (size == 0)
  {
    throw std::logic_error("invalid scaling");
  }
  unsafeIsoScale(pos, k);
}

void CompositeShape::unsafeIsoScale(point_t pos, double k)
{
  for (size_t i = 0; i < size; i++)
  {
    point_t p1{arr[i]->getFrameRect().center.x, arr[i]->getFrameRect().center.y};
    arr[i]->move(pos);
    point_t p2{arr[i]->getFrameRect().center.x, arr[i]->getFrameRect().center.y};

    double dx = k * (p1.x - p2.x);
    double dy = k * (p1.y - p2.y);
    arr[i]->unsafeScale(k);
    arr[i]->move(dx, dy);
  }
}

void CompositeShape::pushBack(Shape* newShape)
{
  if (size == capacity)
  {
    capacity = capacity + 10;
    Shape** newArr = new Shape* [capacity];
    for (size_t i = 0; i < size; i++)
    {
      newArr[i] = arr[i];
    }
    delete[]arr;
    arr = newArr;
  }
  arr[size++] = newShape;
}

void CompositeShape::pushBack(const Shape* newShape)
{
  Shape* newShapeClone = nullptr;
  try
  {
    newShapeClone = newShape->clone();
  }
  catch (const std::bad_alloc& e)
  {
    clear(arr, size);
    throw;
  }

  pushBack(newShapeClone);
}

void CompositeShape::popBack()
{
  delete arr[--size];
}

Shape* CompositeShape::at(size_t id)
{
  if (id >= size)
  {
    throw std::out_of_range("out of range");
  }
  return arr[id];
}

const Shape* CompositeShape::at(size_t id) const
{
  if (id >= size)
  {
    throw std::out_of_range("out of range");
  }
  return arr[id];
}

Shape* CompositeShape::operator[](size_t id)
{
  return arr[id];
}

const Shape* CompositeShape::operator[](size_t id) const
{
  return arr[id];
}

CompositeShape& CompositeShape::operator=(CompositeShape&& otherCS)
{
  clear(arr, size);
  size = otherCS.size;
  capacity = otherCS.capacity;
  arr = otherCS.arr;
  otherCS.size = 0;
  otherCS.capacity = 0;
  otherCS.arr = nullptr;

  return *this;
}

CompositeShape& CompositeShape::operator=(const CompositeShape& otherCS)
{
  Shape** newArr = new Shape* [capacity];

  for (size_t i = 0; i < otherCS.size; i++)
  {
    try
    {
      newArr[i] = otherCS.arr[i]->clone();
    }
    catch (const std::bad_alloc& e)
    {
      clear(newArr, i);
      throw;
    }
  }

  clear(arr, size);
  size = otherCS.size;
  capacity = otherCS.capacity;
  arr = newArr;

  return *this;
}

bool CompositeShape::empty() const
{
  return (size == 0);
}

size_t CompositeShape::sizeArr() const
{
  return size;
}

void CompositeShape::printInfo(std::ostream& out, char separator) const
{
  out << getArea();

  for (size_t i = 0; i < sizeArr(); i++)
  {
    out << separator << arr[i]->getFrameRect().center.x - arr[i]->getFrameRect().width / 2;
    out << separator << arr[i]->getFrameRect().center.y - arr[i]->getFrameRect().height / 2;
    out << separator << arr[i]->getFrameRect().center.x + arr[i]->getFrameRect().width / 2;
    out << separator << arr[i]->getFrameRect().center.y + arr[i]->getFrameRect().height / 2;
  }
}
