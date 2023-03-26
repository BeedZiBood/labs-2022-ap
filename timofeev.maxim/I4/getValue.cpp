#include "getValue.h"
int getValue(const int* arr, size_t cols, size_t r, size_t c)
{
  return arr[r * cols + c];
}
