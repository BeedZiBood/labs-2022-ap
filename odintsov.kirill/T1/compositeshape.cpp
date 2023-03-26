#include "compositeshape.hpp"
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include "shape.hpp"
#include "base-types.hpp"

odintsov::CompositeShape::CompositeShape():
  CompositeShape(5)
{}

odintsov::CompositeShape::CompositeShape(size_t cap):
  size_(0),
  cap_(cap),
  shapes_(new Shape*[cap_])
{}

odintsov::CompositeShape::CompositeShape(const odintsov::CompositeShape& shp):
  CompositeShape(shp.cap_)
{
  for (size_t i = 0; i < shp.size(); i++) {
    Shape* clone = shp[i]->clone();
    push_back(clone);
  }
}


odintsov::CompositeShape::CompositeShape(odintsov::CompositeShape&& shp):
  size_(shp.size()),
  cap_(shp.cap_),
  shapes_(shp.shapes_)
{
  shp.shapes_ = nullptr;
  shp.size_ = 0;
}

odintsov::CompositeShape::~CompositeShape()
{
  clear();
  delete [] shapes_;
}

odintsov::CompositeShape& odintsov::CompositeShape::operator=(const odintsov::CompositeShape& shp)
{
  Shape** clonedShapes = new Shape*[shp.cap_];
  for (size_t i = 0; i < shp.size(); i++) {
    try {
      clonedShapes[i] = shp[i]->clone();
    } catch (...) {
      for (size_t j = 0; j < i; i++) {
        delete clonedShapes[j];
      }
      delete [] clonedShapes;
      throw;
    }
  }
  clear();
  delete [] shapes_;
  shapes_ = clonedShapes;
  cap_ = shp.cap_;
  size_ = shp.size_;
  return *this;
}

odintsov::CompositeShape& odintsov::CompositeShape::operator=(odintsov::CompositeShape&& shp)
{
  clear();
  delete [] shapes_;
  size_ = shp.size_;
  cap_ = shp.cap_;
  shapes_ = shp.shapes_;
  shp.size_ = 0;
  shp.shapes_ = nullptr;
  return *this;
}

double odintsov::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size(); i++) {
    area += shapes_[i]->getArea();
  }
  return area;
}

odintsov::rectangle_t odintsov::CompositeShape::getFrameRect() const
{
  if (empty()) {
    throw std::logic_error("no shapes inside CompositeShape");
  }
  FrameRectBuilder builder(shapes_[0]->getFrameRect());
  for (size_t i = 0; i < size(); i++) {
    builder << shapes_[i]->getFrameRect();
  }
  return builder.rect();
}

void odintsov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size(); i++) {
    shapes_[i]->move(dx, dy);
  }
}

void odintsov::CompositeShape::move(const point_t& pos)
{
  point_t middle = getMiddlePoint();
  move(pos.x - middle.x, pos.y - middle.y);
}

void odintsov::CompositeShape::scale(double k)
{
  assertValidScaling(k);
  point_t middle = getMiddlePoint();
  for (size_t i = 0; i < size(); i++) {
    isoScale(shapes_[i], middle, k);
  }
}

odintsov::point_t odintsov::CompositeShape::getMiddlePoint() const
{
  return getFrameRect().pos;
}

void odintsov::CompositeShape::push_back(Shape* shp)
{
  if (size() == cap_) {
    extend(cap_ + 10);
  }
  shapes_[size_++] = shp;
}

void odintsov::CompositeShape::pop_back()
{
  if (empty()) {
    throw std::logic_error("attempt to pop element from empty CompositeShape");
  }
  quiet_pop_back();
}

void odintsov::CompositeShape::quiet_pop_back()
{
  delete shapes_[--size_];
}

odintsov::Shape* odintsov::CompositeShape::at(size_t id)
{
  if (id >= size())
  {
    throw std::out_of_range("index out of range");
  }
  return shapes_[id];
}

const odintsov::Shape* odintsov::CompositeShape::at(size_t id) const
{
  if (id >= size())
  {
    throw std::out_of_range("index out of range");
  }
  return shapes_[id];
}

odintsov::Shape* odintsov::CompositeShape::operator[](size_t id)
{
  return shapes_[id];
}

const odintsov::Shape* odintsov::CompositeShape::operator[](size_t id) const
{
  return shapes_[id];
}

bool odintsov::CompositeShape::empty() const
{
  return size() == 0;
}

size_t odintsov::CompositeShape::size() const
{
  return size_;
}

void odintsov::CompositeShape::extend(size_t newCap)
{
  if (newCap < cap_) {
    throw std::logic_error("attempt to shrink Shape container");
  }
  if (newCap == cap_) {
    return;
  }
  Shape** newShapes = new Shape*[newCap];
  for (size_t i = 0; i < size(); i++) {
    newShapes[i] = shapes_[i];
  }
  delete [] shapes_;
  shapes_ = newShapes;
  cap_ = newCap;
}

void odintsov::CompositeShape::clear()
{
  while (!empty())
  {
    pop_back();
  }
}

std::ostream& odintsov::outputCompositeShape(std::ostream& out, const CompositeShape& composite)
{
  out << composite.getArea();
  for (size_t i = 0; i < composite.size(); i++) {
    rectangle_t rect = composite[i]->getFrameRect();
    outputFrameRect(out << ' ', rect);
  }
  return out;
}
