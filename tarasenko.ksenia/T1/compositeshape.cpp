#include "compositeshape.hpp"
#include <stdexcept>
#include "base-func.hpp"
#include "isoscale.hpp"

tarasenko::CompositeShape::CompositeShape():
  size_(0),
  capacity_(5),
  shapes(new Shape * [capacity_])
{}

tarasenko::CompositeShape::CompositeShape(Shape ** shp, size_t size, size_t capacity):
  size_(size),
  capacity_(capacity),
  shapes(shp)
{}

size_t tarasenko::CompositeShape::size() const
{
  return size_;
}

double tarasenko::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area += shapes[i]->getArea();
  }
  return area;
}

tarasenko::rectangle_t tarasenko::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::invalid_argument("CompositeShape is empty");
  }
  rectangle_t frame_rect = shapes[0]->getFrameRect();
  double min_x = frame_rect.pos_.x_ - 0.5 * frame_rect.width_;
  double min_y = frame_rect.pos_.y_ - 0.5 * frame_rect.height_;
  double max_x = frame_rect.pos_.x_ + 0.5 * frame_rect.width_;
  double max_y = frame_rect.pos_.y_ + 0.5 * frame_rect.height_;
  for (size_t i = 1; i < size_; i++)
  {
    frame_rect = shapes[i]->getFrameRect();
    min_x = std::min(min_x, frame_rect.pos_.x_ - 0.5 * frame_rect.width_);
    min_y = std::min(min_y, frame_rect.pos_.y_ - 0.5 * frame_rect.height_);
    max_x = std::max(max_x, frame_rect.pos_.x_ + 0.5 * frame_rect.width_);
    max_y = std::max(max_y, frame_rect.pos_.y_ + 0.5 * frame_rect.height_);
  }
  return makeRectangle(point_t{min_x, min_y},point_t{max_x, max_y});
}

void tarasenko::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(dx, dy);
  }
}

void tarasenko::CompositeShape::move(point_t pos)
{
  point_t center = getFrameRect().pos_;
  move(pos.x_ - center.x_, pos.y_ - center.y_);
}

void tarasenko::CompositeShape::scale(double k)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->scale(k);
  }
}

void tarasenko::CompositeShape::push_back(Shape * shp)
{
  if (size_ == capacity_)
  {
    Shape ** new_shapes = new Shape * [capacity_ + 5];
    capacity_ += 5;
    for (size_t i = 0; i < size_; i++)
    {
      new_shapes[i] = shapes[i];
    }
    delete[] shapes;
    shapes = new_shapes;
  }
  shapes[size_] = shp;
  size_++;
}

void tarasenko::CompositeShape::push_back(const Shape * shp)
{
  Shape * cloned_shp = nullptr;
  try
  {
    cloned_shp = shp->clone();
    push_back(cloned_shp);
  }
  catch (...)
  {
    delete cloned_shp;
    throw;
  }
}

void tarasenko::CompositeShape::pop_back()
{
  delete shapes[size_ - 1];
  size_--;
}

tarasenko::Shape * tarasenko::CompositeShape::at(size_t id)
{
  return shapes[id];
}

const tarasenko::Shape * tarasenko::CompositeShape::at(size_t id) const
{
  return shapes[id];
}

tarasenko::Shape * tarasenko::CompositeShape::operator[](size_t id)
{
  return shapes[id];
}

const tarasenko::Shape * tarasenko::CompositeShape::operator[](size_t id) const
{
  return shapes[id];
}

bool tarasenko::CompositeShape::empty() const
{
  return (size_ == 0);
}

tarasenko::CompositeShape * tarasenko::CompositeShape::clone() const
{
  Shape ** clone_shps = new Shape * [capacity_];
  for (size_t i = 0; i < size_; i++)
  {
    try
    {
      clone_shps[i] = shapes[i]->clone();
    }
    catch (...)
    {
      deleteCompositeShape(clone_shps, size_);
      throw;
    }
  }
  return new CompositeShape(clone_shps, size_, capacity_);
}

void tarasenko::CompositeShape::deleteCompositeShape(Shape ** shps, size_t size) const
{
  for (size_t i = 0; i < size; i++)
  {
    delete shps[i];
  }
  delete [] shps;
}

tarasenko::CompositeShape::~CompositeShape()
{
  deleteCompositeShape(shapes, size_);
}
