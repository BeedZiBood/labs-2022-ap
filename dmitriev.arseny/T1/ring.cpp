#include "ring.h"
#include <stdexcept>

dmitriev::Ring::Ring(point_t center, double externalRadius, double internalRadius):
  m_center(center),
  m_internalRadius(internalRadius),
  m_externalRadius(externalRadius)
{
  if (m_externalRadius < m_internalRadius)
  {
    throw std::invalid_argument("invalid arguments");
  }
  if (m_internalRadius <= 0.0)
  {
    throw std::invalid_argument("invalid arguments");
  }
}

double dmitriev::Ring::getArea() const
{
  double pi = 3.141592653589793;
  return pi * m_externalRadius * m_externalRadius - pi * m_internalRadius * m_internalRadius;
}

dmitriev::rectangle_t dmitriev::Ring::getFrameRect() const
{
  point_t leftBott{m_center.x - m_externalRadius, m_center.y - m_externalRadius};
  point_t rightTop{m_center.x + m_externalRadius, m_center.y + m_externalRadius};
  return makeNewRect(leftBott, rightTop);
}

void dmitriev::Ring::move(double dx, double dy)
{
  m_center = sumVec(m_center, {dx, dy});
}

void dmitriev::Ring::move(point_t newPos)
{
  move(newPos.x - m_center.x, newPos.y - m_center.y);
}

void dmitriev::Ring::unsafeScale(double k)
{
  m_externalRadius *= k;
  m_internalRadius *= k;
}

dmitriev::Shape* dmitriev::Ring::clone() const
{
  return new Ring{m_center, m_externalRadius, m_internalRadius};
}
