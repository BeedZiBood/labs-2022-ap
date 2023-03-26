#include "createPoints.h"

double *createCoordinates(std::istream& in, std::size_t size)
{
  double *coordinates = new double[size];
  for (std::size_t i = 0; i < size; ++i)
  {
    in >> coordinates[i];
    if (!in)
    {
      delete[] coordinates;
      throw std::invalid_argument("error input");
    }
  }
  return coordinates;
}

point_t *fillPoints(double *coordinates, std::size_t size)
{
  point_t *points = new point_t[size];
  for (std::size_t i = 0, j = 0; i < size; i++, j+=2)
  {
    points[i].x = coordinates[j];
    points[i].y = coordinates[j + 1];
  }
  return points;
}
