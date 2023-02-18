#include "compositeshape.h"
#include <limits>
#include <stdexcept>
#include "base_functions.h"
#include "isotropic_scaling.h"
dimkashelk::CompositeShape::CompositeShape():
  size_(0),
  capacity_(10),
  shapes_(new Shape*[capacity_])
{}
dimkashelk::CompositeShape::CompositeShape(const CompositeShape &compositeShape):
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
dimkashelk::CompositeShape::CompositeShape(CompositeShape &&compositeShape):
  size_(compositeShape.size_),
  capacity_(compositeShape.capacity_),
  shapes_(compositeShape.shapes_)
{
  compositeShape.shapes_ = nullptr;
  compositeShape.size_ = 0;
}
dimkashelk::CompositeShape &dimkashelk::CompositeShape::operator=(const CompositeShape &other)
{
  if (std::addressof(other) != this)
  {
    Shape **shapes = new Shape *[other.capacity_];
    for (size_t i = 0; i < size_; i++)
    {
      try
      {
        shapes[i] = other.shapes_[i]->clone();
      }
      catch (...)
      {
        free(shapes, i);
        throw;
      }
    }
    free(shapes_, size_);
    shapes_ = shapes;
    size_ = other.size_;
    capacity_ = other.capacity_;
  }
  return *this;
}
dimkashelk::CompositeShape &dimkashelk::CompositeShape::operator=(CompositeShape &&tmp)
{
  if (std::addressof(tmp) != this)
  {
    free(shapes_, size_);
    size_ = tmp.size_;
    capacity_ = tmp.capacity_;
    shapes_ = tmp.shapes_;
    tmp.shapes_ = nullptr;
    tmp.size_ = 0;
  }
  return *this;
}
dimkashelk::Shape *dimkashelk::CompositeShape::operator[](size_t id)
{
  return shapes_[id];
}
const dimkashelk::Shape *dimkashelk::CompositeShape::operator[](size_t id) const
{
  return shapes_[id];
}
dimkashelk::CompositeShape::~CompositeShape()
{
  free(shapes_, size_);
}
double dimkashelk::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}
dimkashelk::rectangle_t dimkashelk::CompositeShape::getFrameRect() const
{
  namespace dks = dimkashelk;
  if (empty())
  {
    throw std::logic_error("CompositeShape empty");
  }
  rectangle_t rectangle = dks::getFrameRect(shapes_[0]->getFrameRect(), shapes_[0]->getFrameRect());
  for (size_t i = 1; i < size_; i++)
  {
    rectangle = dks::getFrameRect(shapes_[i]->getFrameRect(), shapes_[i]->getFrameRect());
  }
  return rectangle;
}
void dimkashelk::CompositeShape::move(point_t point)
{
  point_t center = getFrameRect().pos;
  move(point.x - center.x, point.y - center.y);
}
void dimkashelk::CompositeShape::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(delta_x, delta_y);
  }
}
void dimkashelk::CompositeShape::scale(double k)
{
  if (empty())
  {
    throw std::logic_error("CompositeShape empty");
  }
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  unsafeScale(k);
}
void dimkashelk::CompositeShape::unsafeScale(double k)
{
  namespace dks = dimkashelk;
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    dks::unsafeIsotropicScaling(shapes_[i], center, k);
  }
}
void dimkashelk::CompositeShape::push_back(Shape *shp)
{
  constexpr size_t max_size_t = std::numeric_limits< size_t >::max();
  if (size_ == capacity_)
  {
    if (max_size_t == capacity_)
    {
      throw std::overflow_error("Stack overflow");
    }
    Shape **new_shapes = new Shape*[capacity_ + 10];
    capacity_ += 10;
    for (size_t i = 0; i < size_; i++)
    {
      new_shapes[i] = shapes_[i];
    }
    delete[] shapes_;
    shapes_ = new_shapes;
  }
  shapes_[size_] = shp;
  size_++;
}
void dimkashelk::CompositeShape::push_back(const Shape *shp)
{
  Shape *cloneShape = shp->clone();
  try
  {
    push_back(cloneShape);
  }
  catch (...)
  {
    delete cloneShape;
    throw;
  }
}
void dimkashelk::CompositeShape::pop_back()
{
  delete shapes_[size_ - 1];
  size_--;
}
dimkashelk::Shape* dimkashelk::CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::out_of_range("Check number");
  }
  return shapes_[id];
}
const dimkashelk::Shape* dimkashelk::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::out_of_range("Check number");
  }
  return shapes_[id];
}
bool dimkashelk::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t dimkashelk::CompositeShape::size() const noexcept
{
  return size_;
}
void dimkashelk::CompositeShape::isotropicScaling(point_t point, double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  unsafeIsotropicScaling(point, k);
}
void dimkashelk::CompositeShape::unsafeIsotropicScaling(point_t point, double k)
{
  point_t point_1 = getFrameRect().pos;
  move(point);
  point_t point_2 = getFrameRect().pos;
  unsafeScale(k);
  move(-k * (point_2.x - point_1.x), -k * (point_2.y - point_1.y));
}
void dimkashelk::CompositeShape::free(Shape **shapes, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
