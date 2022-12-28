#include "make-polygon-from-string.hpp"
#include "polygon.hpp"

void extendArray(chemodurov::point_t * arr, size_t & cap, size_t arr_size)
{
  chemodurov::point_t * new_arr = new chemodurov::point_t[cap + 5];
  cap += 5;
  for (size_t i = 0; i < arr_size; ++i)
  {
    new_arr[i] = arr[i];
  }
  delete [] arr;
  arr = new_arr;
  new_arr = nullptr;
}

chemodurov::point_t readPointFromString(const std::string & data, std::string::size_type * size)
{
  std::string::size_type size1 = *size;
  std::string::size_type size2;
  double x = std::stod(data.substr(size1), &size2);
  size2 += size1;
  double y = std::stod(data.substr(size2), &size1);
  size1 += size2;
  *size = size1;
  chemodurov::point_t temp{x, y};
  return temp;
}

chemodurov::point_t * chemodurov::getArrayOfPoints(const std::string & data, size_t & arr_size)
{
  size_t capacity = 5;
  chemodurov::point_t * arr = new chemodurov::point_t[capacity];
  arr_size = 0;
  std::string::size_type size = 7;
  do
  {
    try
    {
      if (arr_size == capacity)
      {
        extendArray(arr, capacity, arr_size);
      }
      arr[arr_size++] = readPointFromString(data, &size);
    }
    catch (...)
    {
      delete [] arr;
      throw;
    }
  }
  while (size < data.size());
  return arr;
}

chemodurov::Shape * chemodurov::makePolygonFromPoints(chemodurov::point_t * arr, size_t arr_size)
{
  chemodurov::Shape * temp = new chemodurov::Polygon(arr, arr_size);
  return temp;
}
