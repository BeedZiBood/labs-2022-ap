#include "rectangle.h"
#include <stdexcept>

dmitriev::Rectangle::Rectangle(point_t leftBott, point_t rightTop):
  m_rect(makeNewRect(leftBott, rightTop))
{
  if (m_rect.height <= 0.0 || m_rect.width <= 0.0)
  {
    throw std::invalid_argument("invalid arguments");
  }
}

double dmitriev::Rectangle::getArea() const
{
  return m_rect.height * m_rect.width;
}

dmitriev::rectangle_t dmitriev::Rectangle::getFrameRect() const
{
  return m_rect;
}

void dmitriev::Rectangle::move(double dx, double dy)
{
  m_rect.center = sumVec(m_rect.center, {dx, dy});
}

void dmitriev::Rectangle::move(point_t newPos)
{
  m_rect.center = newPos;
}

void dmitriev::Rectangle::unsafeScale(double k)
{
  m_rect.height *= k;
  m_rect.width *= k;
}

dmitriev::Shape* dmitriev::Rectangle::clone() const
{
  point_t leftBott{m_rect.center.x - m_rect.width / 2, m_rect.center.y - m_rect.height / 2};
  point_t rightTop{m_rect.center.x + m_rect.width / 2, m_rect.center.y + m_rect.height / 2};
  return new Rectangle{leftBott, rightTop};
}
