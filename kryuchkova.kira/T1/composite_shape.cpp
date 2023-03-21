#include "composite_shape.h"
#include <limits>
#include <stdexcept>
#include "base_types.h"
#include "shape.h"

kryuchkova::CompositeShape::CompositeShape():
  size_(0),
  capacity_(1),
  shapes_(new Shape*[capacity_])
{}

kryuchkova::CompositeShape::CompositeShape(const CompositeShape &compositeShape):
  size_(compositeShape.size_),
  capacity_(compositeShape.capacity_),
  shapes_(new Shape*[capacity_])
{
  for (size_t i = 0; i < size_; i++)
  {
    try
    {
      shapes_[i] = compositeShape.shapes_[i]->clone();
    }
    catch (...)
    {
      free(shapes_, i);
      throw;
    }
  }
}

kryuchkova::CompositeShape::CompositeShape(CompositeShape &&compositeShape):
  size_(compositeShape.size_),
  capacity_(compositeShape.capacity_),
  shapes_(compositeShape.shapes_)
{
  compositeShape.shapes_ = nullptr;
  compositeShape.size_ = 0;
}

kryuchkova::CompositeShape &kryuchkova::CompositeShape::operator=(const CompositeShape &compositeShape)
{
  if (std::addressof(compositeShape) != this)
  {
    Shape **shapes = new Shape *[compositeShape.capacity_];
    for (size_t i = 0; i < size_; i++)
    {
      try
      {
        shapes[i] = compositeShape.shapes_[i]->clone();
      }
      catch (...)
      {
        free(shapes, i);
        throw;
      }
    }
    free(shapes, size_);
    shapes_ = shapes;
    size_ = compositeShape.size_;
    capacity_ = compositeShape.capacity_;
  }
  return *this;
}

kryuchkova::CompositeShape &kryuchkova::CompositeShape::operator=(CompositeShape &&compositeShape)
{
  if (std::addressof(compositeShape) != this)
  {
    free(shapes_, size_);
    size_ = compositeShape.size_;
    capacity_ = compositeShape.capacity_;
    shapes_ = compositeShape.shapes_;
    compositeShape.shapes_ = nullptr;
    compositeShape.size_ = 0;
  }
  return *this;
}

kryuchkova::Shape *kryuchkova::CompositeShape::operator[](const size_t index)
{
  return shapes_[index];
}

const kryuchkova::Shape *kryuchkova::CompositeShape::operator[](const size_t index) const
{
  return shapes_[index];
}

kryuchkova::CompositeShape::~CompositeShape()
{
  free(shapes_, size_);
}

double kryuchkova::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; i++)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}

kryuchkova::rectangle_t kryuchkova::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::invalid_argument("CompositeShape is empty");
  }
  double minx = std::numeric_limits< double >::max();
  double miny = std::numeric_limits< double >::max();
  double maxx = std::numeric_limits< double >::min();
  double maxy = std::numeric_limits< double >::min();
  for (size_t i = 0; i < size_; i++)
  {
    rectangle_t rectangle = shapes_[i]->getFrameRect();
    minx = std::min(rectangle.pos.x - rectangle.width / 2, minx);
    miny = std::min(rectangle.pos.y - rectangle.height / 2, miny);
    maxx = std::max(rectangle.pos.x + rectangle.width / 2, maxx);
    maxy = std::max(rectangle.pos.y + rectangle.height / 2, maxy);
  }
  return rectangle_t{maxx - minx, maxy - miny, point_t{(maxx + minx) / 2, (maxy + miny) / 2}};
}

void kryuchkova::CompositeShape::move(const point_t point)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(point);
  }
}

void kryuchkova::CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void kryuchkova::CompositeShape::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("scaling koef must be positive");
  }
  unsafeScale(k);
}

void kryuchkova::CompositeShape::unsafeScale(const double k)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->unsafeScale(k);
  }
}

void kryuchkova::CompositeShape::isoScale(const point_t point, const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("scaling koef must be positive");
  }
  if (empty())
  {
    throw std::invalid_argument("CompositeShape is empty, nothing to scale");
  }
  unsafeIsoScale(point, k);
}

void kryuchkova::CompositeShape::unsafeIsoScale(const point_t point, const double k)
{
  for (size_t i = 0; i < size_; i++)
  {
    kryuchkova::unsafeIsoScale(shapes_[i], point, k);
  }
}

void kryuchkova::CompositeShape::push_back(Shape *sh)
{
  if (size_ == capacity_)
  {
    Shape **new_shapes = new Shape*[capacity_ + 2];
    capacity_ += 2;
    for (size_t i = 0; i < size_; i++)
    {
      new_shapes[i] = shapes_[i];
    }
    delete[] shapes_;
    shapes_ = new_shapes;
  }
  shapes_[size_] = sh;
  size_++;
}

void kryuchkova::CompositeShape::push_back(const Shape *sh)
{
  Shape *clone = sh->clone();
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

void kryuchkova::CompositeShape::pop_back()
{
  delete shapes_[size_ - 1];
  size_--;
}

kryuchkova::Shape* kryuchkova::CompositeShape::at(const size_t index)
{
  if (index > size_)
  {
    throw std::out_of_range("out of range");
  }
  return shapes_[index];
}

const kryuchkova::Shape* kryuchkova::CompositeShape::at(const size_t index) const
{
  if (index > size_)
  {
    throw std::out_of_range("out of range");
  }
  return shapes_[index];
}

bool kryuchkova::CompositeShape::empty() const
{
  return size_ == 0;
}

size_t kryuchkova::CompositeShape::size() const
{
  return size_;
}

void kryuchkova::CompositeShape::free(Shape **shapes, const size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
