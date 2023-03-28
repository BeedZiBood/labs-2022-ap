#include "fillthearraywithrandomnumbers.h"
#include <cstdlib>
#include <ctime>
int* fillTheArrayWithRandomNumbers(int* array_dynamic, size_t count_elements)
{
  std::srand(static_cast< unsigned int >(std::time(nullptr)));
  for (size_t i = 0; i < count_elements; i++)
  {
    array_dynamic[i] = std::rand() % 100;
  }
  return array_dynamic;
}
