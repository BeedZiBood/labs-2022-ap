#include "compositeshape.h"
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include "basetype.h"

void remove(Shape** shp, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shp[i];
    shp[i] = nullptr;
  }
  delete[] shp;
  shp = nullptr;
}

CompositeShape::CompositeShape():
  size_(0),
  shp_(nullptr)
{}

CompositeShape::CompositeShape(CompositeShape&& anotherCompShp):
  size_(anotherCompShp.size_),
  shp_(anotherCompShp.shp_)
{
  anotherCompShp.size_ = 0.0;
  anotherCompShp.shp_ = nullptr;
}

CompositeShape::CompositeShape(const CompositeShape& anotherCompShp):
  size_(anotherCompShp.size()),
  shp_(new Shape*[size_])
{
  for (size_t i = 0; i < size_; ++i)
  {
    shp_[i] = anotherCompShp.shp_[i]->clone();
  }
}

CompositeShape::~CompositeShape()
{
  remove(shp_, size_);
}

CompositeShape& CompositeShape::operator=(CompositeShape&& anotherCompShp)
{
  remove(shp_, size_);
  size_ = anotherCompShp.size_;
  shp_ = anotherCompShp.shp_;
  anotherCompShp.size_ = 0.0;
  anotherCompShp.shp_ = nullptr;
  return *this;
}

CompositeShape& CompositeShape::operator=(const CompositeShape& anotherCompShp)
{
  remove(shp_, size_);
  size_ = anotherCompShp.size_;
  shp_ = new Shape*[size_];
  for (size_t i = 0; i < size_; ++i)
  {
    shp_[i] = anotherCompShp.shp_[i]->clone();
  }
  return *this;
}

double CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += shp_[i]->getArea();
  }
  return area;
}

rectangle_t CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::logic_error("Empty compositeShape");
  }
  rectangle_t rec = shp_[0]->getFrameRect();
  double minX = rec.pos_.x - rec.width_ / 2;
  double minY = rec.pos_.y - rec.height_ / 2;
  double maxX = rec.pos_.x + rec.width_ / 2;
  double maxY = rec.pos_.y + rec.height_ / 2;
  for (size_t i = 1; i < size_; ++i)
  {
    rec = shp_[i]->getFrameRect();
    minX = std::min(minX, rec.pos_.x - rec.width_ / 2);
    minY = std::min(minY, rec.pos_.y - rec.height_ / 2);
    maxX = std::max(maxX, rec.pos_.x + rec.width_ / 2);
    maxY = std::max(maxY, rec.pos_.y + rec.height_ / 2);
  }
  rec.width_ = maxX - minX;
  rec.height_ = maxY - minY;
  rec.pos_ = {minX + rec.width_ / 2, minY + rec.height_ / 2};
  return rec;
}

void CompositeShape::move(point_t pos)
{
  point_t center = getFrameRect().pos_;
  move(pos.x - center.x, pos.y - center.y);
}

void CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shp_[i]->move(dx, dy);
  }
}

void CompositeShape::scale(double k)
{
  if (k == 1.0)
  {
    return;
  }
  if (k < 0.0)
  {
    throw std::invalid_argument("K is less than 0");
  }
  for (size_t i = 0; i < size_; ++i)
  {
    shp_[i]->scale(k);
  }
}

void CompositeShape::isotropScale(point_t pos, double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("K is less than 0");
  }
  for (size_t i = 0; i < size_; ++i)
  {
    point_t pos1 = shp_[i]->getFrameRect().pos_;
    shp_[i]->move(pos);
    point_t pos2 = shp_[i]->getFrameRect().pos_;
    shp_[i]->scale(k);
    double dx = (pos1.x - pos2.x) * k;
    double dy = (pos1.y - pos2.y) * k;
    shp_[i]->move(dx, dy);
  }
}

void CompositeShape::pushBack(Shape* shp)
{
  try
  {
    if (empty())
    {
      shp_ = new Shape*[++size_];
      shp_[size_ - 1] = shp;
    }
    else
    {
      Shape** newShape = new Shape*[size_ + 1];
      for (size_t i = 0; i < size_; ++i)
      {
        newShape[i] = shp_[i];
      }
      delete[] shp_;
      shp_ = newShape;
      shp_[size_] = shp;
      ++size_;
    }
  }
  catch (...)
  {
    remove(shp_, size_);
    throw;
  }
}

void CompositeShape::popBack()
{
  if (empty())
  {
    throw std::logic_error("Shape hasn't elements");
  }
  if (size_ == 1)
  {
    delete shp_;
    shp_ = nullptr;
  }
  try
  {
    Shape** newShape = new Shape*[--size_];
    for (size_t i = 0; i < size_; ++i)
    {
      newShape[i] = shp_[i];
    }
    remove(shp_, size_);
    shp_ = newShape;
  }
  catch (...)
  {
    remove(shp_, size_);
    throw;
  }
}

Shape* CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::logic_error("Going beyond the bounds of the array");
  }
  return shp_[id];
}

Shape* CompositeShape::operator[](size_t id) const
{
  return shp_[id];
}

bool CompositeShape::empty() const
{
  return size_ == 0;
}

size_t CompositeShape::size() const
{
  return size_;
}
