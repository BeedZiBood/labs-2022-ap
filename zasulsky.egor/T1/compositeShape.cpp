#include "compositeShape.hpp"
#include <stdexcept>
#include <algorithm>
#include <ostream>
#include "base-types.hpp"

zasulsky::CompositeShape::CompositeShape(size_t cap) :
  cap_(cap),
  size_(0),
  shape_(new Shape* [cap])
{}
zasulsky::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shape_[i];
  }
  delete[] shape_;
}
zasulsky::Shape* zasulsky::CompositeShape::operator[](size_t id)
{
  return shape_[id];
}
const zasulsky::Shape* zasulsky::CompositeShape::operator[](size_t id) const
{
  return shape_[id];
}

double zasulsky::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area += shape_[i]->getArea();
  }
  return area;
}
zasulsky::rectangle_t zasulsky::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::runtime_error("CompositeShape is empty");
  }
  rectangle_t rect = shape_[0]->getFrameRect();
  double minX = rect.pos.x - rect.width * 0.5;
  double maxX = rect.pos.x + rect.width * 0.5;
  double minY = rect.pos.y - rect.height * 0.5;
  double maxY = rect.pos.y + rect.height * 0.5;
  for (size_t i = 1; i < size_; i++)
  {
    rect = shape_[i]->getFrameRect();
    minX = std::min(minX, rect.pos.x - rect.width * 0.5);
    maxX = std::max(maxX, rect.pos.x + rect.width * 0.5);
    minY = std::min(minY, rect.pos.y - rect.height * 0.5);
    maxY = std::max(maxY, rect.pos.y + rect.height * 0.5);
  }
  point_t p1{ minX, minY };
  point_t p2{ maxX, maxY };
  return getFrameRectFromCorners(p1, p2);
}
void zasulsky::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shape_[i]->move(dx, dy);
  }
}
zasulsky::point_t zasulsky::CompositeShape::getCenter()
{
  return getFrameRect().pos;
}
void zasulsky::CompositeShape::move(const point_t& position)
{
  point_t center = getCenter();
  move(position.x - center.x, position.y - center.y);
}
void zasulsky::CompositeShape::scale(double k)
{
  point_t center = getCenter();
  for (size_t i = 0; i < size_; ++i)
  {
    isoScale(shape_[i], center, k);
  }
}
void zasulsky::CompositeShape::extend(size_t capDiff)
{
  Shape** newshape = new Shape * [cap_ + capDiff];
  for (size_t i = 0; i < size_; ++i)
  {
    newshape[i] = shape_[i];
  }
  delete[] shape_;
  shape_ = newshape;
  cap_ += capDiff;
}
void zasulsky::CompositeShape::push_back(Shape* shp)
{
  if (size_ == cap_)
  {
    extend(5);
  }
  shape_[size_++] = shp;
}
void zasulsky::CompositeShape::pop_back()
{
  if (empty())
  {
    throw std::runtime_error("CompositeShape is empty");
  }
  delete shape_[size_--];
}
zasulsky::Shape* zasulsky::CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::invalid_argument("id should be smaller than size");
  }
  return shape_[id];
}
const zasulsky::Shape* zasulsky::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::invalid_argument("id should be smaller than size");
  }
  return shape_[id];
}
bool zasulsky::CompositeShape::empty() const
{
  return size_ == 0;
}
size_t zasulsky::CompositeShape::size() const
{
  return size_;
}
void zasulsky::isoScale(CompositeShape& shp, const point_t& center, double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k must not be less than zero");
  }
  point_t A1 = shp.getFrameRect().pos;
  shp.move(center);
  point_t A2 = shp.getFrameRect().pos;
  shp.scale(k);
  isoScalePoint(A1, center, k);
  isoScalePoint(A2, center, k);
  shp.move(A1.x - A2.x, A1.y - A2.y);
}
std::ostream& zasulsky::outputComposite(std::ostream& out, const CompositeShape& composite)
{
  out << composite.getArea();
  for (size_t i = 0; i < composite.size(); ++i)
  {
    zasulsky::rectangle_t rect = composite[i]->getFrameRect();
    out << ' ' << rect.pos.x - rect.width * 0.5;
    out << ' ' << rect.pos.y - rect.height * 0.5;
    out << ' ' << rect.pos.x + rect.width * 0.5;
    out << ' ' << rect.pos.y + rect.height * 0.5;
  }
  return out;
}
