#include "shifted_array.h"

int* makeShiftedArray(int* array, size_t size)
{
  if (array && size)
  {
    int flag = array[size - 1];
    for (size_t i = size - 1; i >= 1; i--)
    {
      array[i] = array[i - 1];
    }
    array[0] = flag;
  }
  return array;
}
