#include "make_triangles.h"
#include <stdexcept>
#include "base_functions.h"
dimkashelk::Triangle* dimkashelk::makeTriangles(const point_t *points, size_t size)
{
  TriangulatePoints triangulatePoints(points, size);
  size_t s = 0;
  Triangle *triangles = new Triangle[size - 2];
  while (triangulatePoints.hasNext())
  {
    try
    {
      triangles[s++] = triangulatePoints();
    }
    catch (...)
    {
      delete[] triangles;
      throw;
    }
  }
  return triangles;
}
dimkashelk::TriangulatePoints::TriangulatePoints(const point_t *points, size_t size):
  points_(new point_t[size]),
  size_(size),
  point_(1)
{
  if (size < 3)
  {
    delete[] points_;
    throw std::logic_error("Need minimum 3 points");
  }
  for (size_t i = 0; i < size; i++)
  {
    points_[i] = points[i];
  }
}
dimkashelk::TriangulatePoints::~TriangulatePoints()
{
  delete[] points_;
}
dimkashelk::Triangle dimkashelk::TriangulatePoints::operator()()
{
  if (point_ + 1 < size_)
  {
    if (getMixedProduct(points_[point_ + 1], points_[0], points_[point_], points_[0]) >= 0)
    {
      Triangle triangle = Triangle(points_[0], points_[point_], points_[point_ + 1]);
      point_++;
      return triangle;
    }
  }
  Triangle triangle = Triangle(points_[0], points_[1], points_[2]);
  points_++;
  return triangle;
}
bool dimkashelk::TriangulatePoints::hasNext() const
{
  return size_ > point_ + 1;
}
