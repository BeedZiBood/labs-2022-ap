#include "rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(point_t leftBott, point_t rightTop):
  m_rect(makeNewRect(leftBott, rightTop))
{
  if (m_rect.height <= 0.0 || m_rect.width <= 0.0)
  {
    throw std::invalid_argument("invalid arguments");
  }
}

double Rectangle::getArea() const
{
  return m_rect.height * m_rect.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return m_rect;
}

void Rectangle::move(double dx, double dy)
{
  m_rect.m_center.x = m_rect.m_center.x + dx;
  m_rect.m_center.y = m_rect.m_center.y + dy;
}

void Rectangle::move(point_t newPos)
{
  double dx = newPos.x - m_rect.m_center.x;
  double dy = newPos.y - m_rect.m_center.y;
  move(dx, dy);
}

void Rectangle::unsafeScale(double k)
{
  m_rect.height = m_rect.height * k;
  m_rect.width = m_rect.width * k;
}

Shape* Rectangle::clone() const
{
  point_t leftBott{m_rect.m_center.x - m_rect.width / 2, m_rect.m_center.y - m_rect.height / 2};
  point_t rightTop{m_rect.m_center.x + m_rect.width / 2, m_rect.m_center.y + m_rect.height / 2};
  return new Rectangle{leftBott, rightTop};
}
