#include "composite-shape.hpp"
#include <stdexcept>
#include "iso-scale.hpp"

chemodurov::CompositeShape::CompositeShape(const CompositeShape & rhs):
 CompositeShape(rhs.capacity_)
{
  for (size_t i = 0; i < rhs.size_; ++i)
  {
    shape_[i] = rhs.shape_[i]->clone();
    size_++;
  }
}
chemodurov::CompositeShape::CompositeShape(CompositeShape && rhs):
 shape_(rhs.shape_),
 size_(rhs.size_),
 capacity_(rhs.capacity_)
{
  rhs.shape_ = nullptr;
  rhs.size_ = 0;
}
chemodurov::CompositeShape::CompositeShape(size_t capacity):
 shape_(new Shape*[capacity]),
 size_(0),
 capacity_(capacity)
{}
chemodurov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; ++i)
  {
    delete shape_[i];
  }
  delete [] shape_;
}
chemodurov::CompositeShape & chemodurov::CompositeShape::operator=(const CompositeShape & rhs)
{
  Shape ** new_data = new Shape*[rhs.capacity_];
  size_t new_size = 0;
  try
  {
    for (size_t i = 0; i < rhs.size_; ++i)
    {
      new_data[i] = rhs.shape_[i]->clone();
      new_size++;
    }
  }
  catch (...)
  {
    for (size_t i = 0; i < new_size; ++i)
    {
      delete new_data[i];
    }
    delete [] new_data;
    throw;
  }
  for (size_t i = 0; i < size_; ++i)
  {
    delete shape_[i];
  }
  delete [] shape_;
  shape_ = new_data;
  size_ = new_size;
  capacity_ = rhs.capacity_;
  return *this;
}
chemodurov::CompositeShape & chemodurov::CompositeShape::operator=(CompositeShape && rhs)
{
  for (size_t i = 0; i < size_; ++i)
  {
    delete shape_[i];
  }
  delete [] shape_;
  shape_ = rhs.shape_;
  rhs.shape_ = nullptr;
  size_ = rhs.size_;
  rhs.size_ = 0;
  capacity_ = rhs.capacity_;
  return *this;
}
double chemodurov::CompositeShape::getArea() const
{
  double summ_area = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    summ_area += shape_[i]->getArea();
  }
  return summ_area;
}
chemodurov::rectangle_t chemodurov::CompositeShape::getFrameRect() const
{
  rectangle_t temp = shape_[0]->getFrameRect();
  double max_x = temp.pos.x + 0.5 * temp.width;
  double min_x = max_x;
  double max_y = temp.pos.y + 0.5 * temp.height;
  double min_y = max_y;
  for (size_t i = 0; i < size_; ++i)
  {
    rectangle_t temp1 = shape_[i]->getFrameRect();
    if (max_x < temp1.pos.x + 0.5 * temp1.width)
    {
      max_x = temp1.pos.x + 0.5 * temp1.width;
    }
    if (min_x > temp1.pos.x - 0.5 * temp1.width)
    {
      min_x = temp1.pos.x - 0.5 * temp1.width;
    }
    if (max_y < temp1.pos.y + 0.5 * temp1.height)
    {
      max_y = temp1.pos.y + 0.5 * temp1.height;
    }
    if (min_y > temp1.pos.y - 0.5 * temp1.height)
    {
      min_y = temp1.pos.y - 0.5 * temp1.height;
    }
  }
  point_t center{(max_x + min_x) / 2, (max_y + min_y) / 2};
  rectangle_t frame{center, max_x - min_x, max_y - min_y};
  return frame;
}
void chemodurov::CompositeShape::move(const point_t & position)
{
  rectangle_t frame = CompositeShape::getFrameRect();
  double dx = position.x - frame.pos.x;
  double dy = position.y - frame.pos.y;
  move(dx, dy);
}
void chemodurov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shape_[i]->move(dx, dy);
  }
}
void chemodurov::CompositeShape::scale(double k)
{
  rectangle_t frame = CompositeShape::getFrameRect();
  scale(frame.pos, k);
}
void chemodurov::CompositeShape::scale(const point_t & position, double k)
{
  for (size_t i = 0; i < size_; ++i)
  {
    isoScale(shape_[i], position, k);
  }
}
chemodurov::Shape * chemodurov::CompositeShape::operator[](size_t id)
{
  return shape_[id];
}
const chemodurov::Shape * chemodurov::CompositeShape::operator[](size_t id) const
{
  return shape_[id];
}
chemodurov::Shape * chemodurov::CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::out_of_range("Id is out of range");
  }
  return shape_[id];
}
const chemodurov::Shape * chemodurov::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::out_of_range("Id is out of range");
  }
  return shape_[id];
}
bool chemodurov::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t chemodurov::CompositeShape::size() const noexcept
{
  return size_;
}
void chemodurov::CompositeShape::push_back(const Shape * shp)
{
  Shape * cloned = shp->clone();
  if (capacity_ == size_)
  {
    Shape ** new_shape = nullptr;
    try
    {
      new_shape = new Shape * [capacity_ + 10];
    }
    catch (...)
    {
      delete cloned;
      throw;
    }
    capacity_ += 10;
    for (size_t i = 0; i < size_; ++i)
    {
      new_shape[i] = shape_[i];
    }
    delete[] shape_;
    shape_ = new_shape;
  }
  shape_[size_++] = cloned;
}
void chemodurov::CompositeShape::push_back(Shape * shp)
{
  if (capacity_ == size_)
  {
    Shape ** new_shape = new Shape * [capacity_ + 10];
    capacity_ += 10;
    for (size_t i = 0; i < size_; ++i)
    {
      new_shape[i] = shape_[i];
    }
    delete[] shape_;
    shape_ = new_shape;
  }
  shape_[size_++] = shp;
}
void chemodurov::CompositeShape::pop_back()
{
  delete shape_[size_];
  shape_[size_--] = nullptr;
}
