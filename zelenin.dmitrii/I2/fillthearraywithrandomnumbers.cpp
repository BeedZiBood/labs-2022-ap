#include "fillthearraywithrandomnumbers.h"

int* fillTheArrayWithRandomNumbers(int* array_dynamic, size_t count_elements)
{
  srand(static_cast<unsigned int>(time(NULL)));
  for (size_t i = 0; i < count_elements; i++)
  {
    array_dynamic[i] = rand() % 100;
  }
  return array_dynamic;

}
