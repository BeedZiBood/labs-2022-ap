#include "polygon.hpp"
#include <stdexcept>
#include <cmath>
#include "is-repeating-points-in-array.hpp"

namespace chemodurov
{
  double calcPolygonArea(const point_t * verts, size_t num_of_verts)
  {
    double area = 0.0;
    for (size_t i = 1; i < num_of_verts - 1; ++i)
    {
      area += verts[i].x * (verts[i + 1].y - verts[i - 1].y);
    }
    area += verts[0].x * (verts[1].y - verts[num_of_verts - 1].y);
    area += verts[num_of_verts - 1].x * (verts[0].y - verts[num_of_verts - 2].y);
    area = std::abs(0.5 * area);
    return area;
  }
  point_t findPolygonCenter(const point_t * verts, size_t num_of_verts)
  {
    double area = calcPolygonArea(verts, num_of_verts);
    double x_of_center = 0.0;
    double y_of_center = 0.0;
    for (size_t i = 0; i < num_of_verts - 1; ++i)
    {
      x_of_center += (verts[i].x + verts[i + 1].x) * (verts[i].x * verts[i + 1].y - verts[i + 1].x * verts[i].y);
      y_of_center += (verts[i].y + verts[i + 1].y) * (verts[i].x * verts[i + 1].y - verts[i + 1].x * verts[i].y);
    }
    {
      size_t j = num_of_verts - 1;
      x_of_center += (verts[j].x + verts[0].x) * (verts[j].x * verts[0].y - verts[0].x * verts[j].y);
      y_of_center += (verts[j].y + verts[0].y) * (verts[j].x * verts[0].y - verts[0].x * verts[j].y);
    }
    x_of_center /= (6 * area);
    y_of_center /= (6 * area);
    point_t temp{x_of_center, y_of_center};
    return temp;
  }
}

chemodurov::Polygon::Polygon(point_t * verts, size_t num_of_verts):
 vertices_(verts),
 number_of_vertices_(num_of_verts),
 center_(findPolygonCenter(verts, num_of_verts))
{
  if (num_of_verts < 3 || isRepeatingPointsInArray(verts, num_of_verts))
  {
    throw std::invalid_argument("Not correct vertices of polygon");
  }
}
chemodurov::Polygon::~Polygon()
{
  delete [] vertices_;
}
double chemodurov::Polygon::getArea() const
{
  return calcPolygonArea(vertices_, number_of_vertices_);
}
chemodurov::rectangle_t chemodurov::Polygon::getFrameRect() const
{
  double max_x = vertices_[0].x;
  double min_x = max_x;
  double max_y = vertices_[0].y;
  double min_y = max_y;
  for (size_t i = 0; i < number_of_vertices_; ++i)
  {
    if (vertices_[i].x > max_x)
    {
      max_x = vertices_[i].x;
    }
    if (vertices_[i].x < min_x)
    {
      min_x = vertices_[i].x;
    }
    if (vertices_[i].y > max_y)
    {
      max_y = vertices_[i].y;
    }
    if (vertices_[i].y < min_y)
    {
      min_y = vertices_[i].y;
    }
  }
  point_t center{(max_x + min_x) / 2, (max_y + min_y) / 2};
  rectangle_t temp{center, max_x - min_x, max_y - min_y};
  return temp;
}
void chemodurov::Polygon::move(const point_t & pos)
{
  const point_t delta = pos - center_;
  center_ = center_ + delta;
  for (size_t i = 0; i < number_of_vertices_; ++i)
  {
    vertices_[i] = vertices_[i] + delta;
  }
}
void chemodurov::Polygon::move(double dx, double dy)
{
  const point_t delta{dx, dy};
  center_ = center_ + delta;
  for (size_t i = 0; i < number_of_vertices_; ++i)
  {
    vertices_[i] = vertices_[i] + delta;
  }
}
void chemodurov::Polygon::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Not correct coefficient of scale");
  }
  for (size_t i = 0; i < number_of_vertices_; ++i)
  {
    vertices_[i] = (vertices_[i] - center_) * k + center_;
  }
}
chemodurov::Shape * chemodurov::Polygon::clone() const
{
  point_t * temp = new point_t[number_of_vertices_];
  for (size_t i = 0; i < number_of_vertices_; ++i)
  {
    temp[i] = vertices_[i];
  }
  Shape * cloned = nullptr;
  try
  {
    cloned = new Polygon(temp, number_of_vertices_);
  }
  catch (...)
  {
    delete [] temp;
    throw;
  }
  return cloned;
}
chemodurov::Polygon::Polygon(const chemodurov::Polygon & p):
 Polygon(new point_t[p.number_of_vertices_], p.number_of_vertices_, p.center_)
{
  for (size_t i = 0; i < number_of_vertices_; ++i)
  {
    vertices_[i] = p.vertices_[i];
  }
}
chemodurov::Polygon::Polygon(chemodurov::point_t * vertices, size_t number_of_vertices, chemodurov::point_t center):
 vertices_(vertices),
 number_of_vertices_(number_of_vertices),
 center_(center)
{}
