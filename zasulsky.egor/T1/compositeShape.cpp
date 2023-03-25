#include "compositeShape.hpp"
#include <stdexcept>
#include <algorithm>
#include <ostream>
#include "base-types.hpp"

zasulsky::CompositeShape::CompositeShape(size_t cap):
  cap_(cap),
  size_(0),
  shape_(new Shape* [cap])
{}
zasulsky::CompositeShape::CompositeShape(const zasulsky::CompositeShape& cshp):
  CompositeShape(cshp.cap_)
{
  for (size_t i = 0; i < cshp.size(); i++)
  {
    push_back(cshp[i]->clone());
  }
}
zasulsky::CompositeShape::CompositeShape(CompositeShape&& cshp):
  cap_(cshp.cap_),
  size_(cshp.size_),
  shape_(cshp.shape_)
{
  cshp.shape_ = nullptr;
  cshp.cap_ = 0;
  cshp.size_ = 0;
}
zasulsky::CompositeShape& zasulsky::CompositeShape::operator=(const zasulsky::CompositeShape& cshp)
{
  zasulsky::Shape** newShape = new zasulsky::Shape* [cshp.cap_];
  for (size_t i = 0; i < cshp.size(); i++)
  {
    try
    {
      newShape[i] = cshp[i]->clone();
    }
    catch (...)
    {
      for (size_t j = 0; j < i; j++)
      {
        delete newShape[i];
      }
      delete[] newShape;
    }
  }
  purge();
  shape_ = newShape;
  cap_ = cshp.cap_;
  size_ = cshp.size_;
  return *this;
}
zasulsky::CompositeShape& zasulsky::CompositeShape::operator=(CompositeShape&& cshp)
{
  purge();
  shape_ = cshp.shape_;
  cap_ = cshp.cap_;
  size_ = cshp.size_;
  cshp.shape_ = nullptr;
  cshp.cap_ = 0;
  cshp.size_ = 0;
  return *this;
}
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
void zasulsky::CompositeShape::purge()
{
  while (!empty())
  {
    pop_back();
  }
  delete[] shape_;
}
template< class F >
F zasulsky::CompositeShape::traverse(F f) const
{
  for (size_t i = 0; i < size_; ++i)
  {
    f(*(*this)[i]);
  }
  return f;
}
template< class F >
F zasulsky::CompositeShape::traverse(F f)
{
  for (size_t i = 0; i < size_; ++i)
  {
    f(*(*this)[i]);
  }
  return f;
}
zasulsky::CompositeArea::CompositeArea():
  area(0.0)
{}
void zasulsky::CompositeArea::operator()(const Shape& shp)
{
  area += shp.getArea();
}
zasulsky::CompositeCorners::CompositeCorners():
  p1{0.0, 0.0},
  p2{0.0, 0.0},
  isFirstCall_(true)
{}

void zasulsky::CompositeCorners::operator()(const Shape& shp)
{
  rectangle_t fr = shp.getFrameRect();
  double minX = fr.pos.x - fr.width * 0.5;
  double maxX = fr.pos.x + fr.width * 0.5;
  double minY = fr.pos.y - fr.height * 0.5;
  double maxY = fr.pos.y + fr.height * 0.5;
  if (isFirstCall_)
  {
    isFirstCall_ = false;
    p1.x = minX;
    p1.y = minY;
    p2.x = maxX;
    p2.y = maxY;
  }
  else
  {
    p1.x = std::min(minX, p1.x);
    p1.y = std::min(minY, p1.y);
    p2.x = std::max(maxX, p2.x);
    p2.y = std::max(maxY, p2.y);
  }
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
  CompositeCorners f;
  f = traverse(f);
  return getMidPoint(f.p1, f.p2);
}
void zasulsky::CompositeShape::move(const point_t& position)
{
  point_t center = getCenter();
  move(position.x - center.x, position.y - center.y);
}
void zasulsky::CompositeShape::unsafeScale(double k)
{
  point_t center = getCenter();
  for (size_t i = 0; i < size_; ++i)
  {
    unsafeIsoScale(shape_[i], center, k);
  }
}
void zasulsky::CompositeShape::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k must not be less than zero");
  }
  unsafeScale(k);
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
  point_t A1{0.0, 0.0};
  {
    CompositeCorners f;
    f = shp.traverse(f);
    A1 = getMidPoint(f.p1, f.p2);
  }
  shp.move(center);
  point_t A2{ 0.0, 0.0 };
  {
    CompositeCorners f;
    f = shp.traverse(f);
    A2 = getMidPoint(f.p1, f.p2);
  }
  shp.unsafeScale(k);
  unsafeIsoScalePoint(A1, center, k);
  unsafeIsoScalePoint(A2, center, k);
  shp.move(A1.x - A2.x, A1.y - A2.y);
}
std::ostream& zasulsky::outputComposite(std::ostream& out, const CompositeShape& composite)
{
  {
    CompositeArea f;
    out << composite.traverse(f).area;
  }
  composite.traverse([](const Shape& shp)
    {
      zasulsky::rectangle_t fr = shp.getFrameRect();
      out << ' ' << fr.pos.x - fr.width * 0.5;
      out << ' ' << fr.pos.y - fr.height * 0.5;
      out << ' ' << fr.pos.x + fr.width * 0.5;
      out << ' ' << fr.pos.y + fr.height * 0.5;
    }
  );
  return out;
}
