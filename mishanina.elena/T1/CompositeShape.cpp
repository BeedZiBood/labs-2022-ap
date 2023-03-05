#include "CompositeShape.h"
#include <memory>

CompositeShape::CompositeShape():
  size_(0),
  capacity_(1),
  shapes_(new Shape* [capacity_])
{
}

CompositeShape::~CompositeShape()
{
  remove(shapes_, size_);
}

Shape* CompositeShape::operator[](std::size_t index)
{
  return shapes_[index];
}

const Shape* CompositeShape::operator[](std::size_t index) const
{
  return shapes_[index];
}

void CompositeShape::getName() const
{
  for (std::size_t i = 0; i < size_; i++)
  {
    shapes_[i]->getName();
  }
}

double CompositeShape::getArea() const
{
  double area = 0;
  for (std::size_t i = 0; i < size_; i++)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}

void CompositeShape::push_back(Shape* shape)
{
  if (capacity_ == size_)
  {
    Shape** new_arr = new Shape * [capacity_ + 2];
    capacity_ += 2;
    for (std::size_t i = 0; i < size_; i++)
    {
      new_arr[i] = shapes_[i];
    }
    delete[] shapes_;
    shapes_ = new_arr;
  }
  shapes_[size_] = shape;
  size_++;
}

void CompositeShape::pop_back()
{
  delete shapes_[size_ - 1];
  size_--;
}

Shape* CompositeShape::at(const std::size_t index)
{
  if (index > size_)
  {
    throw std::out_of_range("out of range");
  }
  return shapes_[index];
}

const Shape* CompositeShape::at(const std::size_t index) const
{
  if (index > size_)
  {
    throw std::out_of_range("out of range");
  }
  return shapes_[index];
}

bool CompositeShape::empty() const
{
  return size_ == 0;
}

std::size_t CompositeShape::size() const
{
  return size_;
}

void CompositeShape::remove(Shape** shapes, std::size_t size) const
{
  for (std::size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

void CompositeShape::move(double dx, double dy)
{
  for (std::size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void CompositeShape::move(const point_t& point)
{
  for (std::size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(point);
  }
}

void CompositeShape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid k size");
  }
  for (std::size_t i = 0; i < size_; i++)
  {
    shapes_[i]->scale(k);
  }
}

rectangle_t CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::invalid_argument("CompositeShape is empty");
  }
  rectangle_t Rect = shapes_[0]->getFrameRect();

  double LowerLeft_x = Rect.pos.x - Rect.width / 2;
  double LowerLeft_y = Rect.pos.y - Rect.height / 2;
  double UpperRight_x = Rect.pos.x + Rect.width / 2;
  double UpperRight_y = Rect.pos.y + Rect.height / 2;

  point_t lower_left = { LowerLeft_x, LowerLeft_y };
  point_t upper_right = { UpperRight_x, UpperRight_y };

  for (std::size_t i = 1; i < size_; i++)
  {
    Rect = shapes_[i]->getFrameRect();
    LowerLeft_x = Rect.pos.x - Rect.width / 2;
    LowerLeft_y = Rect.pos.y - Rect.height / 2;
    UpperRight_x = Rect.pos.x + Rect.width / 2;
    UpperRight_y = Rect.pos.y + Rect.height / 2;

    if (LowerLeft_x < lower_left.x)
    {
      lower_left.x = LowerLeft_x;
    }

    if (LowerLeft_y > lower_left.y)
    {
      lower_left.y = LowerLeft_y;
    }

    if (UpperRight_x > upper_right.x)
    {
      upper_right.x = UpperRight_x;
    }

    if (UpperRight_y < upper_right.y)
    {
      upper_right.y = UpperRight_y;
    }
  }
  point_t center = { (lower_left.x + upper_right.x) / 2, (lower_left.y + upper_right.y) / 2 };
  return { upper_right.x - lower_left.x, upper_right.y - lower_left.y, center };
}

CompositeShape* CompositeShape::clone() const
{
  Shape** cloneShapes = new Shape * [capacity_];
  for (std::size_t i = 0; i < size_; i++)
  {
    try
    {
      cloneShapes[i] = shapes_[i]->clone();
    }
    catch (...)
    {
      remove(cloneShapes, size_);
      throw;
    }
  }
  return new CompositeShape(cloneShapes, capacity_, size_);
}

CompositeShape::CompositeShape(Shape** shapes, std::size_t capacity, std::size_t size) :
  size_(size),
  capacity_(capacity),
  shapes_(shapes)
{
}

CompositeShape::CompositeShape(const CompositeShape& compositeShape) :
  size_(compositeShape.size_),
  capacity_(compositeShape.capacity_),
  shapes_(new Shape* [capacity_])
{
  for (std::size_t i = 0; i < size_; i++)
  {
    try
    {
      shapes_[i] = compositeShape.shapes_[i]->clone();
    }
    catch (...)
    {
      remove(shapes_, i);
      throw;
    }
  }
}

CompositeShape::CompositeShape(CompositeShape&& compositeShape) noexcept:
  size_(compositeShape.size_),
  capacity_(compositeShape.capacity_),
  shapes_(compositeShape.shapes_)
{
  compositeShape.shapes_ = nullptr;
  compositeShape.size_ = 0;
}

CompositeShape& CompositeShape::operator=(const CompositeShape& compositeShape)
{
  if (std::addressof(compositeShape) != this)
  {
    Shape** shapes = new Shape * [compositeShape.capacity_];
    for (std::size_t i = 0; i < size_; i++)
    {
      try
      {
        shapes[i] = compositeShape.shapes_[i]->clone();
      }
      catch (...)
      {
        remove(shapes, i);
        throw;
      }
    }
    remove(shapes, size_);
    shapes_ = shapes;
    size_ = compositeShape.size_;
    capacity_ = compositeShape.capacity_;
  }
  return *this;
}

CompositeShape& CompositeShape::operator=(CompositeShape&& compositeShape) noexcept
{
  if (std::addressof(compositeShape) != this)
  {
    remove(shapes_, size_);
    size_ = compositeShape.size_;
    capacity_ = compositeShape.capacity_;
    shapes_ = compositeShape.shapes_;
    compositeShape.shapes_ = nullptr;
    compositeShape.size_ = 0;
  }
  return *this;
}
