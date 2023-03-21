#include "compositeshape.hpp"
#include <stdexcept>
#include <cmath>
#include "iscale.hpp"
#include "base-types.hpp"

CompositeShape::CompositeShape():
  capacity_(1),
  shapes(new Shape * [capacity_]),
  size_(0)
{}

CompositeShape::CompositeShape(const CompositeShape &compositeShape):
  capacity_(compositeShape.capacity_),
  shapes(new Shape *[compositeShape.capacity_]),
  size_(compositeShape.size_)
{
  for (size_t i = 0; i < size_; i++)
  {
    try
    {
      shapes[i] = compositeShape.shapes[i]->clone();
    }
    catch (...)
    {
      destruct(shapes, i);
      throw;
    }
  }
}

void CompositeShape::push_back(const Shape *shape)
{
  Shape *clone = shape->clone();
  try
  {

    push_back(clone);
  }
  catch (...)
  {
    delete clone;
    throw;
  }
}

void CompositeShape::push_back(Shape *shape)
{
  if (capacity_ == size_)
  {
    Shape **extendShapes = new Shape *[capacity_ + 2];
    capacity_ += 2;
    for (size_t i = 0; i < size_; i++)
    {
      extendShapes[i] = shapes[i];
    }
    delete [] shapes;
    shapes = extendShapes;
  }
  shapes[size_++] = shape;
}

void CompositeShape::pop_back()
{
  delete shapes[--size_];
}

Shape *CompositeShape::at(size_t i)
{
  if (i > size_)
  {
    throw std::invalid_argument("Invalid argument");
  }
  return shapes[i];
}

const Shape *CompositeShape::at(size_t i) const
{
  if (i > size_)
  {
    throw std::invalid_argument("Invalid argument");
  }
  return shapes[i];
}

Shape *CompositeShape::operator[](size_t i)
{
  return shapes[i];
}

const Shape *CompositeShape::operator[](size_t i) const
{
  return shapes[i];
}

bool CompositeShape::empty() const
{
  return size_ == 0;
}

size_t CompositeShape::size() const
{
  return size_;
}

CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes[i];
  }
  delete [] shapes;
}

void CompositeShape::scale(scale_t scale)
{
  if (scale.scale > 0)
  {
    scaleWithoutChecking(scale);
  }
  else
  {
    throw std::invalid_argument("Invalid scale size");
  }
}

void CompositeShape::scaleCheck(scale_t scale)
{
  iScaleCheck(shapes[size_], scale);
}

void CompositeShape::scaleWithoutChecking(scale_t scale)
{
  for (size_t i = 0; i < size_; i++)
  {
    iScaleWithoutChecking(shapes[i], scale);
  }
}

void CompositeShape::move(point_t position)
{
  move(position.x - getFrameRect().pos.x, position.y - getFrameRect().pos.y);
}

void CompositeShape::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(delta_x, delta_y);
  }
}

double CompositeShape::getArea() const
{
  double sum = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    sum = sum + shapes[i]->getArea();
  }
  return sum;
}

rectangle_t CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::invalid_argument("No shapes");
  }
  double a = 0.0;
  double b = 0.0;
  double c = 0.0;
  double d = 0.0;
  for (size_t i = 1; i < size_; i++)
  {
    rectangle_t temp = shapes[i]->getFrameRect();
    a = std::fmax(temp.pos.x + temp.width / 2.0, temp.pos.x + temp.width / 2.0);
    b = std::fmax(temp.pos.y + temp.height / 2.0, temp.pos.y + temp.height / 2.0);
    c = std::fmin(temp.pos.x - temp.width / 2.0, temp.pos.x - temp.width / 2.0);
    d = std::fmin(temp.pos.y - temp.height / 2.0, temp.pos.y - temp.height / 2.0);
  }
  return {{(a + c) / 2.0, (b + d) / 2.0}, c - a, d - b};
}

CompositeShape *CompositeShape::clone() const
{
  Shape **cloneShapes = new Shape * [capacity_];
  for (size_t i = 0; i < size_; i++)
  {
    try
    {
      cloneShapes[i] = shapes[i]->clone();
    }
    catch (...)
    {
      destruct(cloneShapes, size_);
      throw;
    }
  }
  return new CompositeShape(cloneShapes, capacity_, size_);
}

CompositeShape::CompositeShape(Shape ** shapes, size_t capacity, size_t size):
  capacity_(capacity),
  shapes(shapes),
  size_(size)
{}

void CompositeShape::destruct(Shape **shape, size_t size) const
{
  for (size_t i = 0; i < size; i++)
  {
    delete shape[i];
  }
  delete [] shape;
}

CompositeShape &CompositeShape::operator=(const CompositeShape &compositeShape)
{
  Shape **cloneShapes = new Shape *[compositeShape.capacity_];
  for (size_t i = 0; i < compositeShape.size_; i++)
  {
    try
    {
      cloneShapes[i] = compositeShape[i]->clone();
    }
    catch (...)
    {
      destruct(cloneShapes, i);
      throw;
    }
  }
  destruct(shapes, size_);
  shapes = cloneShapes;
  size_ = compositeShape.size_;
  capacity_ = compositeShape.capacity_;
  return *this;
}

CompositeShape &CompositeShape::operator=(CompositeShape &compositeShape) noexcept
{
  destruct(shapes, size_);
  size_ = compositeShape.size_;
  capacity_ = compositeShape.capacity_;
  shapes = compositeShape.shapes;
  compositeShape.shapes = nullptr;
  compositeShape.size_ = 0;
  return * this;
}
