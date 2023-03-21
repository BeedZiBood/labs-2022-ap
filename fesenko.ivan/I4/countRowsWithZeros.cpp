#include "countRowsWithZeros.h"

size_t countRowsWithZeros(const int *array, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      if (array[i * cols + j] == 0) {
        count++;
        break;
      }
    }
  }
  return count;
}
