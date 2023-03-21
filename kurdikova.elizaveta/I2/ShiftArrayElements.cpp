#include "ShiftArrayElements.h"

void shiftArrayElements(int* arr, size_t size, size_t shift)
{
  int curr = arr[0];
  int next = 0;
  size_t num = 0;
  size_t circle = 0;
  for (size_t i = 0; i < size; ++i) {
    next = arr[(num + shift) % size];
    arr[(num + shift) % size] = curr;

    curr = next;
    next = 0;
    num = (num + shift) % size;

    if (num % size == circle) {
      num++;
      curr = arr[num];
      circle++;
    }
  }
}
