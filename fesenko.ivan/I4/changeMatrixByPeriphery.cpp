#include "changeMatrixByPeriphery.h"

void changeMatrixByPeriphery(int *array, size_t rows, size_t cols)
{
  for (size_t i = 0; i < (rows + 1) / 2; i++) {
    for (size_t j = i; cols >= i && j < cols - i; j++) {
      array[i * cols + j] = i + 1;
      array[(rows - i - 1) * cols + j] = i + 1;
    }
  }
  for (size_t j = 0; j < (cols + 1) / 2; j++) {
    for (size_t i = j + 1; rows >= j + 1 && i < rows - j - 1; i++) {
      array[i * cols + j] = j + 1;
      array[(i + 1) * cols - j - 1] = j + 1;
    }
  }
}
