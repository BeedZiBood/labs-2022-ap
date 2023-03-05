#include "count_rows_with_same_elements.h"
#include <cstddef>

int countOfRowsWithSameElements(int* arr, size_t nRows, size_t nColomns)
{
  size_t cnt = 0;
  size_t cnt_elem = 0;
  for (size_t i = 0; i < nColomns; ++i)
  {
    for (size_t j = 0; j < nRows - 1; ++j)
    {
      for (size_t k = 1; k < nRows; ++k)
      {
        if (arr[i * nColomns + j] == arr[i * nRows + k])
        {
          cnt_elem++;
        }
      }
      if (cnt_elem != 0)
      {
        cnt++;
      }
      cnt_elem = 0;
    }
  }
  return cnt;
}

