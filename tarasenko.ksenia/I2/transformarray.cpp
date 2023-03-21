#include "transformarray.hpp"

int* partitionNegative(int* arr, size_t size) {
  size_t n = size / 2;
  if (size != 0) {
    int temp;
    for (size_t i = 0; i < size; i++) {
      if (arr[i] >= 0) {
        temp = arr[i];
        for (size_t j = i; j < size - 1; j++) {
          arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
        --size;
        --i;
      }
    }
  }
  return arr + n;
}
