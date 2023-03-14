#include "findLongestSeries.h"

size_t findLongestSeries(const int* matrix, size_t numRows, size_t numCols)
{
  size_t maxSeriesLength = 1;
  size_t currentSeriesLength = 1;
  size_t maxSeriesRow = 0;
  for (size_t i = 0; i < numRows; i++)
  {
    for (size_t j = 0; j < numCols - 1; j++)
    {
      if (matrix[i * numCols + j] == matrix[i * numCols + j + 1])
      {
        currentSeriesLength++;
        if (currentSeriesLength > maxSeriesLength)
        {
          maxSeriesLength = currentSeriesLength;
          maxSeriesRow = i;
        }
      }
      else
      {
        currentSeriesLength = 1;
      }
    }
    currentSeriesLength = 1;
  }
  return maxSeriesRow;
}
