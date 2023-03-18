#include "compositeShape.h"
#include <stdexcept>
#include <algorithm>

CompositeShape::CompositeShape():
  m_size(0),
  m_capacity(10),
  m_arr(new Shape* [m_capacity])
{
}

void clear(Shape** arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete arr[i];
  }
  delete[] arr;
}

CompositeShape::CompositeShape(const CompositeShape& otherCS):
  m_size(otherCS.m_size),
  m_capacity(otherCS.m_capacity),
  m_arr(new Shape* [m_capacity])
{
  for (size_t i = 0; i < m_size; i++)
  {
    try
    {
      m_arr[i] = otherCS.m_arr[i]->clone();
    }
    catch(const std::exception& e)
    {
      clear(m_arr, i);
      throw e;
    }
  }
}

CompositeShape::CompositeShape(CompositeShape&& othrerCS):
  m_size(othrerCS.m_size),
  m_capacity(othrerCS.m_capacity),
  m_arr(othrerCS.m_arr)
{
  othrerCS.m_size = 0;
  othrerCS.m_arr = nullptr;
}

CompositeShape::~CompositeShape()
{
  clear(m_arr, m_size);
}

double CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < m_size; i++)
  {
    area = area + m_arr[i]->getArea();
  }
  return area;
}

rectangle_t CompositeShape::getFrameRect() const
{
  if (m_size == 0)
  {
    throw std::logic_error("no elements in arr");
  }
  double minX = m_arr[0]->getFrameRect().center.x - m_arr[0]->getFrameRect().width / 2;
  double minY = m_arr[0]->getFrameRect().center.y - m_arr[0]->getFrameRect().height / 2;
  double maxX = m_arr[0]->getFrameRect().center.x + m_arr[0]->getFrameRect().width / 2;
  double maxY = m_arr[0]->getFrameRect().center.y + m_arr[0]->getFrameRect().height / 2;

  for (size_t i = 1; i < m_size; i++)
  {
    minX = std::min(minX, m_arr[i]->getFrameRect().center.x - m_arr[i]->getFrameRect().width / 2);
    minY = std::min(minY, m_arr[i]->getFrameRect().center.y - m_arr[i]->getFrameRect().height / 2);
    maxX = std::max(maxX, m_arr[i]->getFrameRect().center.x + m_arr[i]->getFrameRect().width / 2);
    maxY = std::max(maxY, m_arr[i]->getFrameRect().center.y + m_arr[i]->getFrameRect().height / 2);
  }
  return makeNewRect(point_t{ minX, minY }, point_t{ maxX, maxY });
}

void CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < m_size; i++)
  {
    m_arr[i]->move(dx, dy);
  }
}

void CompositeShape::move(point_t newPos)
{
  for (size_t i = 0; i < m_size; i++)
  {
    m_arr[i]->move(newPos);
  }
}

void CompositeShape::scale(double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("invalid argument");
  }
  unsafeScale(k);
}

void CompositeShape::unsafeScale(double k)
{
  for (size_t i = 0; i < m_size; i++)
  {
    m_arr[i]->unsafeScale(k);
  }
}

void CompositeShape::isoScale(point_t pos, double k)
{
  if (k < 0.0)
  {
    throw std::invalid_argument("invalid argument");
  }
  if (m_size == 0)
  {
    throw std::logic_error("invalid scaling");
  }
  unsafeIsoScale(pos, k);
}

void CompositeShape::unsafeIsoScale(point_t pos, double k)
{
  for (size_t i = 0; i < m_size; i++)
  {
    point_t p1{m_arr[i]->getFrameRect().center.x, m_arr[i]->getFrameRect().center.y};
    m_arr[i]->move(pos);
    point_t p2{m_arr[i]->getFrameRect().center.x, m_arr[i]->getFrameRect().center.y};

    double dx = k * (p1.x - p2.x);
    double dy = k * (p1.y - p2.y);
    m_arr[i]->unsafeScale(k);
    m_arr[i]->move(dx, dy);
  }
}

void CompositeShape::pushBack(Shape* newShape)
{
  if (m_size == m_capacity)
  {
    m_capacity = m_capacity + 10;
    Shape** newArr = new Shape* [m_capacity];
    for (size_t i = 0; i < m_size; i++)
    {
      newArr[i] = m_arr[i];
    }
    delete[]m_arr;
    m_arr = newArr;
  }
  m_arr[m_size++] = newShape;
}

void CompositeShape::pushBack(const Shape* newShape)
{
  Shape* newShapeClone = nullptr;
  try
  {
    newShapeClone = newShape->clone();
  }
  catch (const std::exception& e)
  {
    clear(m_arr, m_size);
    throw e;
  }

  pushBack(newShapeClone);
}

void CompositeShape::popBack()
{
  delete m_arr[--m_size];
}

Shape* CompositeShape::at(size_t id)
{
  if (id >= m_size)
  {
    throw std::out_of_range("out of range");
  }
  return m_arr[id];
}

const Shape* CompositeShape::at(size_t id) const
{
  if (id >= m_size)
  {
    throw std::out_of_range("out of range");
  }
  return m_arr[id];
}

Shape* CompositeShape::operator[](size_t id)
{
  return m_arr[id];
}

const Shape* CompositeShape::operator[](size_t id) const
{
  return m_arr[id];
}

CompositeShape& CompositeShape::operator=(CompositeShape&& otherCS)
{
  clear(m_arr, m_size);
  m_size = otherCS.m_size;
  m_capacity = otherCS.m_capacity;
  m_arr = otherCS.m_arr;
  otherCS.m_size = 0;
  otherCS.m_arr = nullptr;

  return *this;
}

CompositeShape& CompositeShape::operator=(const CompositeShape& otherCS)
{
  Shape** newArr = new Shape* [m_capacity];

  for (size_t i = 0; i < otherCS.m_size; i++)
  {
    try
    {
      newArr[i] = otherCS.m_arr[i]->clone();
    }
    catch (const std::exception& e)
    {
      clear(newArr, i);
      throw e;
    }
  }

  clear(m_arr, m_size);
  m_size = otherCS.m_size;
  m_capacity = otherCS.m_capacity;
  m_arr = newArr;

  return *this;
}

bool CompositeShape::empty() const
{
  return (m_size == 0);
}

size_t CompositeShape::sizeArr() const
{
  return m_size;
}

void CompositeShape::printInfo(std::ostream& out, char separator) const
{
  out << getArea();

  for (size_t i = 0; i < sizeArr(); i++)
  {
    out << separator << m_arr[i]->getFrameRect().center.x - m_arr[i]->getFrameRect().width / 2;
    out << separator << m_arr[i]->getFrameRect().center.y - m_arr[i]->getFrameRect().height / 2;
    out << separator << m_arr[i]->getFrameRect().center.x + m_arr[i]->getFrameRect().width / 2;
    out << separator << m_arr[i]->getFrameRect().center.y + m_arr[i]->getFrameRect().height / 2;
  }
}
