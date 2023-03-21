#include "make-polygon-from-string.hpp"
#include "polygon.hpp"

namespace chemodurov
{
  point_t * extendArray(const point_t * arr, size_t cap, size_t arr_size)
  {
    cap += 5;
    point_t * new_arr = new point_t[cap];
    for (size_t i = 0; i < arr_size; ++i)
    {
      new_arr[i] = arr[i];
    }
    return new_arr;
  }
  point_t readPointFromString(const std::string & data, std::string::size_type & size)
  {
    std::string::size_type size1 = size;
    std::string::size_type size2 = 0;
    double x = std::stod(data.substr(size1), std::addressof(size2));
    size2 += size1;
    double y = std::stod(data.substr(size2), std::addressof(size1));
    size1 += size2;
    size = size1;
    point_t temp{x, y};
    return temp;
  }
}
chemodurov::point_t * chemodurov::getArrayOfPoints(const std::string & data, size_t pos, size_t & arr_size)
{
  size_t capacity = 5;
  size_t arr_temp_size = arr_size;
  point_t * arr = new point_t[capacity];
  do
  {
    point_t * new_arr = nullptr;
    try
    {
      if (arr_temp_size == capacity)
      {
        new_arr = extendArray(arr, capacity, arr_temp_size);
        capacity += 5;
        delete [] arr;
        arr = new_arr;
        new_arr = nullptr;
      }
      arr[arr_temp_size++] = readPointFromString(data, pos);
    }
    catch (...)
    {
      delete [] arr;
      delete [] new_arr;
      throw;
    }
  }
  while (pos < data.size());
  arr_size = arr_temp_size;
  return arr;
}
