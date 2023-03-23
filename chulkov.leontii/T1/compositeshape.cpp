#include "compositeshape.h"
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "basetype.h"

chulkov::CompositeShape::CompositeShape():
  first_(nullptr),
  last_(nullptr),
  size_(0)
{}

chulkov::CompositeShape::CompositeShape(CompositeShape&& anotherCompShp):
  first_(anotherCompShp.first_),
  last_(anotherCompShp.last_),
  size_(anotherCompShp.size_)
{
  anotherCompShp.first_ = nullptr;
  anotherCompShp.last_ = nullptr;
  anotherCompShp.size_ = 0;
}

chulkov::CompositeShape::CompositeShape(const CompositeShape& anotherCompShp):
  CompositeShape()
{
  ShapeNode* node = anotherCompShp.first_;
  while (node != nullptr)
  {
    pushBack(node->shape->clone());
    node = node->next;
  }
}

chulkov::CompositeShape::~CompositeShape()
{
  ShapeNode* current = first_;
  while (current != nullptr)
  {
    ShapeNode* next = current->next;
    delete current->shape;
    delete current;
    current = next;
  }
}

chulkov::CompositeShape& chulkov::CompositeShape::operator=(CompositeShape&& anotherCompShp)
{
  if (this != &anotherCompShp)
  {
    clear();
    first_ = anotherCompShp.first_;
    last_ = anotherCompShp.last_;
    size_ = anotherCompShp.size_;
    anotherCompShp.first_ = nullptr;
    anotherCompShp.last_ = nullptr;
    anotherCompShp.size_ = 0;
  }
  return *this;
}

chulkov::CompositeShape& chulkov::CompositeShape::operator=(const CompositeShape& anotherCompShp)
{
  if (this != &anotherCompShp)
  {
    clear();
    CompositeShape t(anotherCompShp);
    std::swap(first_, t.first_);
    std::swap(last_, t.last_);
    std::swap(size_, t.size_);
  }
  return *this;
}

double chulkov::CompositeShape::getArea() const
{
  double area = 0;
  for (ShapeNode* i = first_; i != nullptr; i = i->next)
  {
    area += i->shape->getArea();
  }
  return area;
}

chulkov::rectangle_t chulkov::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::logic_error("Empty compositeShape");
  }
  ShapeNode* node = first_;
  rectangle_t rec = node->shape->getFrameRect();
  double minX = rec.pos_.x - rec.width_ / 2;
  double minY = rec.pos_.y - rec.height_ / 2;
  double maxX = rec.pos_.x + rec.width_ / 2;
  double maxY = rec.pos_.y + rec.height_ / 2;
  for (ShapeNode* i = first_; i != nullptr; i = i->next)
  {
    rec = i->shape->getFrameRect();
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

void chulkov::CompositeShape::move(point_t pos)
{
  point_t center = getFrameRect().pos_;
  move(pos.x - center.x, pos.y - center.y);
}

void chulkov::CompositeShape::move(double dx, double dy)
{
  for (ShapeNode* i = first_; i != nullptr; i = i->next)
  {
    i->shape->move(dx, dy);
  }
}

void chulkov::CompositeShape::scale(double k)
{
  if (k == 1.0)
  {
    return;
  }
  if (k < 0.0)
  {
    throw std::invalid_argument("K is less than 0");
  }
  for (ShapeNode* i = first_; i != nullptr; i = i->next)
  {
    i->shape->scale(k);
  }
}

void chulkov::CompositeShape::isotropScale(point_t pos, double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("K is less than 0");
  }
  for (ShapeNode* i = first_; i != nullptr; i = i->next)
  {
    point_t pos1 = i->shape->getFrameRect().pos_;
    i->shape->move(pos);
    point_t pos2 = i->shape->getFrameRect().pos_;
    i->shape->scale(k);
    double dx = (pos1.x - pos2.x) * k;
    double dy = (pos1.y - pos2.y) * k;
    i->shape->move(dx, dy);
  }
}

void chulkov::CompositeShape::pushBack(Shape* shape)
{
  try
  {
    ShapeNode* node = new ShapeNode{nullptr, last_, shape};
    if (empty())
    {
      first_ = node;
    }
    else
    {
      last_->next = node;
    }
    last_ = node;
    ++size_;
  }
  catch (...)
  {
    clear();
    throw;
  }
}

void chulkov::CompositeShape::popBack()
{
  if (empty())
  {
    throw std::logic_error("Shape hasn't elements");
  }
  try
  {
    if (size_ == 1)
    {
      delete first_;
      first_ = nullptr;
      last_ = nullptr;
    }
    else
    {
      ShapeNode* node = last_;
      last_ = node->prev;
      last_->next = nullptr;
      delete node;
    }
    --size_;
  }
  catch (...)
  {
    clear();
    throw;
  }
}

void chulkov::CompositeShape::clear()
{
  while (last_)
  {
    popBack();
  }
}

bool chulkov::CompositeShape::empty() const
{
  return size_ == 0;
}

size_t chulkov::CompositeShape::size() const
{
  return size_;
}

void chulkov::CompositeShape::print() const
{
  for (ShapeNode* i = first_; i != nullptr; i = i->next)
  {
    double minX = i->shape->getFrameRect().pos_.x;
    minX -= i->shape->getFrameRect().width_ / 2;
    double minY = i->shape->getFrameRect().pos_.y;
    minY -= i->shape->getFrameRect().height_ / 2;
    double maxX = i->shape->getFrameRect().pos_.x;
    maxX += i->shape->getFrameRect().width_ / 2;
    double maxY = i->shape->getFrameRect().pos_.y;
    maxY += i->shape->getFrameRect().height_ / 2;
    std::cout << " " << minX;
    std::cout << " " << minY;
    std::cout << " " << maxX;
    std::cout << " " << maxY;
  }
}
