#include "compositeShape.h"
#include <stdexcept>

CompositeShape::CompositeShape() :
  size(0),
  capacity(10),
  arr(new Shape* [capacity])
{}


CompositeShape::CompositeShape(CompositeShape&& otherShape) :
  size(otherShape.size),
  capacity(otherShape.capacity),
  arr(otherShape.arr)
{
  otherShape.arr = nullptr;
  otherShape.size = 0;
  otherShape.capacity = 0;
}

CompositeShape::CompositeShape(const CompositeShape& otherShape) :
  size(otherShape.size),
  capacity(otherShape.capacity),
  arr(new Shape* [capacity])
{
  for (unsigned i = 0; i < size; i++)
  {
    try
    {
      arr[i] = otherShape.arr[i]->clone();
    }
    catch (const std::exception& e)
    {
      clear();
      throw e;
    }
  }
}

CompositeShape::~CompositeShape()
{
  clear();
}

void CompositeShape::clear()
{
  for (unsigned i = 0; i < size; i++)
  {
    delete[] arr[i];
  }
  delete[] arr;
}

CompositeShape& CompositeShape::operator=(const CompositeShape&& otherShape)
{
  clear();

  size = otherShape.size;
  capacity = otherShape.capacity;
  arr = new Shape * [capacity];

  for (unsigned i = 0; i < size; i++)
  {
    arr[i] = otherShape.arr[i]->clone();
  }
  return *this;
}

double CompositeShape::getArea()
{
  double s = 0;
  for (unsigned i = 0; i < size; i++)
  {
    s = s + arr[i]->getArea();
  }
  return s;
}

rectangle_t CompositeShape::getFrameRect()
{
  double xMin = arr[0]->getFrameRect().pos.x - arr[0]->getFrameRect().width / 2;
  double yMin = arr[0]->getFrameRect().pos.y - arr[0]->getFrameRect().height / 2;
  double xMax = arr[0]->getFrameRect().pos.x + arr[0]->getFrameRect().width / 2;
  double yMax = arr[0]->getFrameRect().pos.y + arr[0]->getFrameRect().height / 2;

  for (unsigned i = 1; i < size; i++)
  {
    xMin = std::min(xMin, arr[i]->getFrameRect().pos.x - arr[i]->getFrameRect().width / 2);
    yMin = std::min(yMin, arr[i]->getFrameRect().pos.y - arr[i]->getFrameRect().height / 2);
    xMax = std::min(xMax, arr[i]->getFrameRect().pos.x + arr[i]->getFrameRect().width / 2);
    yMax = std::min(yMax, arr[i]->getFrameRect().pos.y + arr[i]->getFrameRect().height / 2);
  }

  point_t leftBott{ xMin, yMin };
  point_t rightTop{ xMax, yMax };

  rectangle_t newRect = makeNewRect(leftBott, rightTop);

  return newRect;
}

void CompositeShape::move(double x, double y)
{
  for (unsigned i = 0; i < size; i++)
  {
    arr[i]->move(x, y);
  }
}

void CompositeShape::move(point_t pos)
{
  for (unsigned i = 0; i < size; i++)
  {
    arr[i]->move(pos);
  }
}

void CompositeShape::scale(double k)
{
  for (unsigned i = 0; i < size; i++)
  {
    arr[i]->scale(k);
  }
}

void CompositeShape::push_back(Shape* shp)
{
  if (size == capacity)
  {
    capacity = capacity + 10;
    try
    {
      Shape** newArr = new Shape * [capacity];

      for (unsigned i = 0; i < size; i++)
      {
        newArr[i] = arr[i]->clone();
      }
      clear();
      arr = newArr;
    }
    catch (const std::exception& e)
    {
      clear();
      throw e;
    }
  }
  arr[size++] = shp;
}

void CompositeShape::push_back(Shape* const shp) const
{
  Shape* newShp = shp->clone();
  push_back(newShp);
}

void CompositeShape::pop_back()
{
  try
  {
    Shape** newArr = new Shape * [--capacity];

    for (unsigned i = 0; i < size - 1; i++)
    {
      newArr[i] = arr[i]->clone();
    }
    clear();
    arr = newArr;
    size--;
  }
  catch (const std::exception& e)
  {
    clear();
    throw e;
  }
}

Shape* CompositeShape::at(const unsigned id)
{
  if (id > size)
  {
    throw std::overflow_error("invalid argument");
  }
  return arr[id];
}

const Shape* CompositeShape::at(unsigned id) const
{
  if (id > size)
  {
    throw std::overflow_error("invalid argument");
  }
  return arr[id];
}

Shape* CompositeShape::operator[](unsigned id)
{
  return arr[id];
}

const Shape* CompositeShape::operator[](unsigned id) const
{
  return arr[id]->clone();
}

bool CompositeShape::empty()
{
  return size == 0;
}

unsigned CompositeShape::sizeArr()
{
  return size;
}
