#include "CompositeShape.hpp"
#include "IsoScale.hpp"
#include <cmath>
#include <stdexcept>
#include <limits>

CompositeShape::CompositeShape(size_t capacity):
  shapes(new Shape *[capacity]),
  capacity_(capacity),
  size_(0)
{}

CompositeShape::CompositeShape(const CompositeShape &compositeShape):
  shapes(new Shape *[compositeShape.capacity_]),
  capacity_(compositeShape.capacity_),
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
      destruct(shapes, size_);
      throw;
    }
  }
}

void CompositeShape::push_back(const Shape *shape)
{
  Shape *cloned = nullptr;
  try
  {
    cloned = shape->clone();
  }
  catch (...)
  {
    delete shape;
    throw;
  }
  push_back(cloned);
}

void CompositeShape::push_back(Shape *shape)
{
  if (capacity_ == size_)
  {
    Shape **extendShapes = new Shape *[capacity_ + 10];
    capacity_ += 10;
    for (size_t i = 0; i < size_; i++)
    {
      extendShapes[i] = shapes[i];
    }
    delete[] shapes;
    shapes = extendShapes;
  }
  shapes[size_++] = shape;
}

void CompositeShape::pop_back()
{
  delete shapes[--size_];
}

const Shape *CompositeShape::at(size_t i) const
{
  return i > size_ ? throw std::invalid_argument("invalid size") : shapes[i];
}

Shape *CompositeShape::at(size_t i)
{
  return i > size_ ? throw std::invalid_argument("invalid size") : shapes[i];
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
  delete[] shapes;
}

void CompositeShape::scale(scale_t scale)
{
  for (size_t i = 0; i < size_; i++)
  {
    doSafeIsoScale(shapes[i], scale);
  }
}

void CompositeShape::move(point_t position)
{
  point_t offset = getVectorDiff(position, getFrameRect().pos);
  move(offset.x, offset.y);
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
  if (size_ == 0)
  {
    throw std::invalid_argument("No shapes");
  }
  double a = std::numeric_limits< double >::min();;
  double b = std::numeric_limits< double >::min();;
  double c = std::numeric_limits< double >::max();;
  double d = std::numeric_limits< double >::max();;
  for (size_t i = 0; i < size_; i++)
  {
    rectangle_t temp = shapes[i]->getFrameRect();
    a = std::abs(std::fmax(temp.pos.x + temp.width / 2.0, a));
    b = std::abs(std::fmax(temp.pos.y + temp.height / 2.0, b));
    c = std::abs(std::fmin(temp.pos.x - temp.width / 2.0, c));
    d = std::abs(std::fmin(temp.pos.y - temp.height / 2.0, d));
  }
  return {{(a + c) / 2.0, (b + d) / 2.0}, c - a, d - b};
}

CompositeShape *CompositeShape::clone() const
{
  Shape **cloneShapes = new Shape *[capacity_];
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

CompositeShape::CompositeShape(Shape **shapes, size_t capacity, size_t size):
  shapes(shapes),
  capacity_(capacity),
  size_(size)
{}


void CompositeShape::destruct(Shape **shape, size_t size) const
{
  for (size_t i = 0; i < size; i++)
  {
    delete shape[i];
  }
  delete[] shape;
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
      destruct(cloneShapes, compositeShape.size_);
      destruct(shapes, size_);
      throw;
    }
  }
  destruct(shapes, size_);
  shapes = cloneShapes;
  size_ = compositeShape.size_;
  capacity_ = compositeShape.capacity_;
  return *this;
}

CompositeShape &CompositeShape::operator=(CompositeShape &&compositeShape) noexcept
{
  destruct(shapes, size_);
  size_ = compositeShape.size_;
  capacity_ = compositeShape.capacity_;
  shapes = compositeShape.shapes;
  compositeShape.shapes = nullptr;
  compositeShape.size_ = 0;
  return *this;
}
