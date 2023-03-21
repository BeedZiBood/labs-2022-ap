#include "elements.h"

size_t potapova::findNegativeAfterMax(const long long int* array, size_t size)
{
  int max_element = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (max_element < array[i])
    {
      max_element = array[i];
    }
  }
  size_t count_negative = 0;
  for (size_t i = 0; i < size - 1; i++)
  {
    if (array[i] == max_element && array[i + 1] < 0)
    {
      count_negative++;
    }
  }
  return count_negative;
}
bool potapova::findRepeatingPositiveNumbers(const long long int* array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 1; j < size; j++)
    {
      if (array[i] > 0 && array[j] > 0 && array[i] < array[j] && array[i] == array[j])
      {
        return true;
      }
    }
  }
  return false;
}
