#include "triangle.h"
#include <stdexcept>
#include <cmath>

Triangle::Triangle(point_t a, point_t b, point_t c):
  m_a(a),
  m_b(b),
  m_c(c)
{
  double aSide = makeLine(m_a, m_b);
  double bSide = makeLine(m_b, m_c);
  double cSide = makeLine(m_c, m_a);

  if (aSide + bSide == cSide)
  {
    throw std::invalid_argument("invalid argumet");
  }
  else if (bSide + cSide == aSide)
  {
    throw std::invalid_argument("invalid argumet");
  }
  else if (cSide + aSide == bSide)
  {
    throw std::invalid_argument("invalid argumet");
  }
}

double Triangle::getArea() const
{
  double aSide = makeLine(m_a, m_b);
  double bSide = makeLine(m_b, m_c);
  double cSide = makeLine(m_c, m_a);
  double p = (aSide + bSide + cSide) / 2;
  return std::sqrt(p * (p - aSide) * (p - bSide) * (p - cSide));
}

rectangle_t Triangle::getFrameRect() const
{
  point_t leftBott{std::min(m_a.x, std::min(m_b.x, m_c.x)), std::min(m_a.y, std::min(m_b.y, m_c.y))};
  point_t rightTop{std::max(m_a.x, std::max(m_b.x, m_c.x)), std::max(m_a.y, std::max(m_b.y, m_c.y))};
  return makeNewRect(leftBott, rightTop);
}

void Triangle::move(double dx, double dy)
{
  m_a = sumVec(m_a, {dx, dy});
  m_b = sumVec(m_b, {dx, dy});
  m_c = sumVec(m_c, {dx, dy});
}

void Triangle::move(point_t newPos)
{
  point_t m_center{(m_a.x + m_b.x + m_c.x) / 3, (m_a.y + m_b.y + m_c.y) / 3};
  move(newPos.x - m_center.x, newPos.y - m_center.y);
}

void Triangle::unsafeScale(double k)
{
  point_t m_center{(m_a.x + m_b.x + m_c.x) / 3, (m_a.y + m_b.y + m_c.y) / 3};
  m_a = multVec(m_center, m_a, k);
  m_b = multVec(m_center, m_b, k);
  m_c = multVec(m_center, m_c, k);
}

Shape* Triangle::clone() const
{
  return new Triangle{m_a, m_b, m_c};
}
