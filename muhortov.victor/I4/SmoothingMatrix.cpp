#include "SmoothingMatrix.hpp"

double smoothingMatrix(const int *arr, size_t cols, size_t rows, double *smooth_arr)
{
  double avg = 0;
  size_t count_near_elements = 0;
  for (size_t i = 1; i <= cols; i++)
  {
    for (size_t j = 1; j <= rows; j++)
    {
      if (j - 1 >= 1 && i - 1 >= 1)
      {
        avg += arr[cols * (i - 2) + j - 2];
        count_near_elements++;
      }
      if (j - 1 >= 1)
      {
        avg += arr[cols * (i - 1) + j - 2];
        count_near_elements++;
      }
      if (j - 1 >= 1 && i + 1 <= cols)
      {
        avg += arr[cols * i + j - 2];
        count_near_elements++;
      }
      if (i - 1 >= 1)
      {
        avg += arr[cols * (i - 2) + j - 1];
        count_near_elements++;
      }
      if (i + 1 <= cols)
      {
        avg += arr[cols * i + j - 1];
        count_near_elements++;
      }
      if (j + 1 <= rows && i - 1 >= 1)
      {
        avg += arr[cols * (i - 2) + j];
        count_near_elements++;
      }
      if (j + 1 <= rows)
      {
        avg += arr[cols * (i - 1) + j];
        count_near_elements++;
      }
      if (j + 1 <= rows && i + 1 <= cols)
      {
        avg += arr[cols * i + j];
        count_near_elements++;
      }

      if (count_near_elements != 0)
      {
        smooth_arr[cols * (i-1) + j - 1] = avg / count_near_elements;
      }

      avg = 0;
      count_near_elements = 0;
    }
  }
  return *smooth_arr;
}
